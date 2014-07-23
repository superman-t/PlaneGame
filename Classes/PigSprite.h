#ifndef __PIG_SPRITE_H__
#define __PIG_SPRITE_H__

#include "cocos2d.h"
USING_NS_CC;

class PigSprite : public cocos2d::Sprite
{
public:
    PigSprite();
	~PigSprite();
    virtual bool init();  
    CREATE_FUNC(PigSprite);

	void f_createAnimate(int count,int fps);
	void f_followPlane(float dt);

    Sprite *spritepig;
};

#endif // __HELLOWORLD_SCENE_H__
