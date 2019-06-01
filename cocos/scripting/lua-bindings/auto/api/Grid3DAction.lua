
--------------------------------
-- @module Grid3DAction
-- @extend GridAction
-- @parent_module cc

--------------------------------
-- brief Set a new vertex to a certain position of the grid.<br>
-- param position The position of the grid.<br>
-- param vertex The vertex will be used on the certain position of grid.<br>
-- js setVertex<br>
-- lua NA
-- @function [parent=#Grid3DAction] setVertex 
-- @param self
-- @param #vec2_table position
-- @param #vec3_table vertex
-- @return Grid3DAction#Grid3DAction self (return value: cc.Grid3DAction)
        
--------------------------------
-- brief Get the effect grid rect.<br>
-- return Return the effect grid rect.
-- @function [parent=#Grid3DAction] getGridRect 
-- @param self
-- @return rect_table#rect_table ret (return value: rect_table)
        
--------------------------------
-- brief Get the non-transformed vertex that belongs to certain position in the grid.<br>
-- param position The position of the grid.<br>
-- return Return a pointer of vertex.<br>
-- js originalVertex<br>
-- lua NA
-- @function [parent=#Grid3DAction] getOriginalVertex 
-- @param self
-- @param #vec2_table position
-- @return vec3_table#vec3_table ret (return value: vec3_table)
        
--------------------------------
-- brief Get the vertex that belongs to certain position in the grid.<br>
-- param position The position of the grid.<br>
-- return Return a pointer of vertex.<br>
-- js vertex<br>
-- lua NA
-- @function [parent=#Grid3DAction] getVertex 
-- @param self
-- @param #vec2_table position
-- @return vec3_table#vec3_table ret (return value: vec3_table)
        
--------------------------------
-- 
-- @function [parent=#Grid3DAction] clone 
-- @param self
-- @return Grid3DAction#Grid3DAction ret (return value: cc.Grid3DAction)
        
--------------------------------
-- 
-- @function [parent=#Grid3DAction] getGrid 
-- @param self
-- @return GridBase#GridBase ret (return value: cc.GridBase)
        
return nil
