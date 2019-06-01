
--------------------------------
-- @module TiledGrid3DAction
-- @extend GridAction
-- @parent_module cc

--------------------------------
-- brief Get the non-transformed tile that belongs to a certain position of the grid.<br>
-- param position The position of the tile want to get.<br>
-- return A quadrilateral of the tile. <br>
-- js originalTile<br>
-- lua NA
-- @function [parent=#TiledGrid3DAction] getOriginalTile 
-- @param self
-- @param #vec2_table position
-- @return Quad3#Quad3 ret (return value: cc.Quad3)
        
--------------------------------
-- brief Set a new tile to a certain position of the grid.<br>
-- param position The position of the tile.<br>
-- param coords The quadrilateral of the new tile.<br>
-- lua NA
-- @function [parent=#TiledGrid3DAction] setTile 
-- @param self
-- @param #vec2_table position
-- @param #cc.Quad3 coords
-- @return TiledGrid3DAction#TiledGrid3DAction self (return value: cc.TiledGrid3DAction)
        
--------------------------------
-- brief Get the tile that belongs to a certain position of the grid.<br>
-- param position The position of the tile want to get.<br>
-- return A quadrilateral of the tile. <br>
-- js tile<br>
-- lua NA
-- @function [parent=#TiledGrid3DAction] getTile 
-- @param self
-- @param #vec2_table position
-- @return Quad3#Quad3 ret (return value: cc.Quad3)
        
--------------------------------
-- brief Create the action with size and duration.<br>
-- param duration The duration of the action. It's a value in seconds.<br>
-- param gridSize Specify the grid size of the action.<br>
-- return A pointer of TiledGrid3DAction. If creation failed, return nil.<br>
-- lua NA
-- @function [parent=#TiledGrid3DAction] create 
-- @param self
-- @param #float duration
-- @param #size_table gridSize
-- @return TiledGrid3DAction#TiledGrid3DAction ret (return value: cc.TiledGrid3DAction)
        
--------------------------------
-- 
-- @function [parent=#TiledGrid3DAction] clone 
-- @param self
-- @return TiledGrid3DAction#TiledGrid3DAction ret (return value: cc.TiledGrid3DAction)
        
--------------------------------
--  returns the grid 
-- @function [parent=#TiledGrid3DAction] getGrid 
-- @param self
-- @return GridBase#GridBase ret (return value: cc.GridBase)
        
return nil
