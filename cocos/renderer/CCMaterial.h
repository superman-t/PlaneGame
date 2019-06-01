/****************************************************************************
 Copyright (c) 2015-2017 Chukong Technologies Inc.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.

 Ideas taken from:
 - GamePlay3D: http://gameplay3d.org/
 - OGRE3D: http://www.ogre3d.org/
 - Qt3D: http://qt-project.org/
 ****************************************************************************/

#ifndef __cocos2d_libs__CCMaterial__
#define __cocos2d_libs__CCMaterial__

#include <string>

#include "renderer/CCRenderState.h"
#include "base/CCRef.h"
#include "base/CCVector.h"
#include "math/Vec2.h"
#include "math/Vec3.h"
#include "math/Vec4.h"
#include "math/Mat4.h"
#include "platform/CCPlatformMacros.h"


NS_CC_BEGIN

class GLProgramState;
class Node;
class Properties;

/// Material
class CC_DLL Material : public RenderState
{
    friend class Node;
    friend class Renderer;
    friend class Mesh;

public:
    /**
     * Creates a Material using the data from the Properties object defined at the specified URL,
     * where the URL is of the format "<file-path>.<extension>#<namespace-id>/<namespace-id>/.../<namespace-id>"
     * (and "#<namespace-id>/<namespace-id>/.../<namespace-id>" is optional).
     *
     * @param url The URL pointing to the Properties object defining the material.
     *
     * @return A new Material or NULL if there was an error.
     */
    static Material* createWithFilename(const std::string& path);

    /** Creates a Material with a GLProgramState.
     It will only contain one Technique and one Pass.
     Added in order to support legacy code.
     */
    static Material* createWithGLStateProgram(GLProgramState* programState);

    /**
     * Creates a material from the specified properties object.
     *
     * @param materialProperties The properties object defining the
     *      material (must have namespace equal to 'material').
     * @return A new Material.
     */
    static Material* createWithProperties(Properties* materialProperties);

    /// returns the material name
    std::string getName() const;
    /// sets the material name
    void setName(const std::string& name);

    /** returns a clone (deep-copy) of the material */
    virtual Material* clone() const;

protected:
    Material();
    ~Material();

    bool initWithFile(const std::string& file);
    bool initWithProperties(Properties* materialProperties);

    void setTarget(Node* target);

    bool parseProperties(Properties* properties);
    bool parseSampler(GLProgramState* glProgramState, Properties* properties);
    bool parseUniform(GLProgramState* programState, Properties* properties, const char* uniformName);
    bool parseRenderState(RenderState* renderState, Properties* properties);
    
    
    // material name
    std::string _name;

    // weak reference
    Node* _target;
};

NS_CC_END


#endif /* defined(__cocos2d_libs__CCMaterial__) */
