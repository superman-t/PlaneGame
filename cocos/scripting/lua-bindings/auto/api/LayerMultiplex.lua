
--------------------------------
-- @module LayerMultiplex
-- @extend Layer
-- @parent_module cc

--------------------------------
--  initializes a MultiplexLayer with an array of layers<br>
-- since v2.1
-- @function [parent=#LayerMultiplex] initWithArray 
-- @param self
-- @param #array_table arrayOfLayers
-- @return bool#bool ret (return value: bool)
        
--------------------------------
--  release the current layer and switches to another layer indexed by n.<br>
-- The current (old) layer will be removed from it's parent with 'cleanup=true'.<br>
-- param n The layer indexed by n will display.
-- @function [parent=#LayerMultiplex] switchToAndReleaseMe 
-- @param self
-- @param #int n
-- @return LayerMultiplex#LayerMultiplex self (return value: cc.LayerMultiplex)
        
--------------------------------
--  Add a certain layer to LayerMultiplex.<br>
-- param layer A layer need to be added to the LayerMultiplex.
-- @function [parent=#LayerMultiplex] addLayer 
-- @param self
-- @param #cc.Layer layer
-- @return LayerMultiplex#LayerMultiplex self (return value: cc.LayerMultiplex)
        
--------------------------------
--  initializes a MultiplexLayer with one or more layers using a variable argument list.<br>
-- js NA<br>
-- lua NA
-- @function [parent=#LayerMultiplex] initWithLayers 
-- @param self
-- @param #cc.Layer layer
-- @param #char params
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- @overload self, int, bool         
-- @overload self, int         
-- @function [parent=#LayerMultiplex] switchTo
-- @param self
-- @param #int n
-- @param #bool cleanup
-- @return LayerMultiplex#LayerMultiplex self (return value: cc.LayerMultiplex)

--------------------------------
--  Creates a LayerMultiplex with one layer.<br>
-- Lua script can not init with undetermined number of variables<br>
-- so add these functions to be used with lua.<br>
-- js NA<br>
-- lua NA<br>
-- param layer A certain layer.<br>
-- return An autoreleased LayerMultiplex object.
-- @function [parent=#LayerMultiplex] createWithLayer 
-- @param self
-- @param #cc.Layer layer
-- @return LayerMultiplex#LayerMultiplex ret (return value: cc.LayerMultiplex)
        
--------------------------------
--  Creates and initializes a LayerMultiplex object.<br>
-- lua NA<br>
-- return An autoreleased LayerMultiplex object.
-- @function [parent=#LayerMultiplex] create 
-- @param self
-- @return LayerMultiplex#LayerMultiplex ret (return value: cc.LayerMultiplex)
        
--------------------------------
--  Creates a LayerMultiplex with an array of layers.<br>
-- since v2.1<br>
-- js NA<br>
-- param arrayOfLayers An array of layers.<br>
-- return An autoreleased LayerMultiplex object.
-- @function [parent=#LayerMultiplex] createWithArray 
-- @param self
-- @param #array_table arrayOfLayers
-- @return LayerMultiplex#LayerMultiplex ret (return value: cc.LayerMultiplex)
        
--------------------------------
-- 
-- @function [parent=#LayerMultiplex] init 
-- @param self
-- @return bool#bool ret (return value: bool)
        
--------------------------------
-- 
-- @function [parent=#LayerMultiplex] getDescription 
-- @param self
-- @return string#string ret (return value: string)
        
--------------------------------
-- js ctor
-- @function [parent=#LayerMultiplex] LayerMultiplex 
-- @param self
-- @return LayerMultiplex#LayerMultiplex self (return value: cc.LayerMultiplex)
        
return nil
