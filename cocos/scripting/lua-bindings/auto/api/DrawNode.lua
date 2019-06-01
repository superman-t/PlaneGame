
--------------------------------
-- @module DrawNode
-- @extend Node
-- @parent_module cc

--------------------------------
--  Get the color mixed mode.<br>
-- lua NA
-- @function [parent=#DrawNode] getBlendFunc 
-- @param self
-- @return BlendFunc#BlendFunc ret (return value: cc.BlendFunc)
        
--------------------------------
--  Draw an line from origin to destination with color. <br>
-- param origin The line origin.<br>
-- param destination The line destination.<br>
-- param color The line color.<br>
-- js NA
-- @function [parent=#DrawNode] drawLine 
-- @param self
-- @param #vec2_table origin
-- @param #vec2_table destination
-- @param #color4f_table color
-- @return DrawNode#DrawNode self (return value: cc.DrawNode)
        
--------------------------------
--  Clear the geometry in the node's buffer. 
-- @function [parent=#DrawNode] clear 
-- @param self
-- @return DrawNode#DrawNode self (return value: cc.DrawNode)
        
--------------------------------
--  Set the color mixed mode.<br>
-- code<br>
-- When this function bound into js or lua,the parameter will be changed<br>
-- In js: var setBlendFunc(var src, var dst)<br>
-- endcode<br>
-- lua NA
-- @function [parent=#DrawNode] setBlendFunc 
-- @param self
-- @param #cc.BlendFunc blendFunc
-- @return DrawNode#DrawNode self (return value: cc.DrawNode)
        
--------------------------------
-- 
-- @function [parent=#DrawNode] getLineWidth 
-- @param self
-- @return float#float ret (return value: float)
        
--------------------------------
-- @overload self, vec2_table, float, float, unsigned int, bool, color4f_table         
-- @overload self, vec2_table, float, float, unsigned int, bool, float, float, color4f_table         
-- @function [parent=#DrawNode] drawCircle
-- @param self
-- @param #vec2_table center
-- @param #float radius
-- @param #float angle
-- @param #unsigned int segments
-- @param #bool drawLineToCenter
-- @param #float scaleX
-- @param #float scaleY
-- @param #color4f_table color
-- @return DrawNode#DrawNode self (return value: cc.DrawNode)

--------------------------------
-- 
-- @function [parent=#DrawNode] setLineWidth 
-- @param self
-- @param #float lineWidth
-- @return DrawNode#DrawNode self (return value: cc.DrawNode)
        
--------------------------------
-- js NA
-- @function [parent=#DrawNode] onDraw 
-- @param self
-- @param #mat4_table transform
-- @param #unsigned int flags
-- @return DrawNode#DrawNode self (return value: cc.DrawNode)
        
--------------------------------
-- @overload self, vec2_table, float, float, unsigned int, color4f_table         
-- @overload self, vec2_table, float, float, unsigned int, float, float, color4f_table         
-- @function [parent=#DrawNode] drawSolidCircle
-- @param self
-- @param #vec2_table center
-- @param #float radius
-- @param #float angle
-- @param #unsigned int segments
-- @param #float scaleX
-- @param #float scaleY
-- @param #color4f_table color
-- @return DrawNode#DrawNode self (return value: cc.DrawNode)

--------------------------------
-- js NA
-- @function [parent=#DrawNode] onDrawGLLine 
-- @param self
-- @param #mat4_table transform
-- @param #unsigned int flags
-- @return DrawNode#DrawNode self (return value: cc.DrawNode)
        
--------------------------------
--  creates and initialize a DrawNode node.<br>
-- return Return an autorelease object.
-- @function [parent=#DrawNode] create 
-- @param self
-- @return DrawNode#DrawNode ret (return value: cc.DrawNode)
        
--------------------------------
-- 
-- @function [parent=#DrawNode] draw 
-- @param self
-- @param #cc.Renderer renderer
-- @param #mat4_table transform
-- @param #unsigned int flags
-- @return DrawNode#DrawNode self (return value: cc.DrawNode)
        
--------------------------------
-- 
-- @function [parent=#DrawNode] init 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#DrawNode] DrawNode 
-- @param self
-- @return DrawNode#DrawNode self (return value: cc.DrawNode)
        
return nil
