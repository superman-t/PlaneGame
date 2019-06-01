
--------------------------------
-- @module CardinalSplineBy
-- @extend CardinalSplineTo
-- @parent_module cc

--------------------------------
--  Creates an action with a Cardinal Spline array of points and tension.<br>
-- code<br>
-- When this function bound to js or lua,the input params are changed.<br>
-- In js: var create(var t,var table).<br>
-- In lua: local create(local t, local table).<br>
-- param duration In seconds.<br>
-- param point An PointArray.<br>
-- param tension Goodness of fit.<br>
-- endcode
-- @function [parent=#CardinalSplineBy] create 
-- @param self
-- @param #float duration
-- @param #point_table points
-- @param #float tension
-- @return CardinalSplineBy#CardinalSplineBy ret (return value: cc.CardinalSplineBy)
        
--------------------------------
-- 
-- @function [parent=#CardinalSplineBy] startWithTarget 
-- @param self
-- @param #cc.Node target
-- @return CardinalSplineBy#CardinalSplineBy self (return value: cc.CardinalSplineBy)
        
--------------------------------
-- 
-- @function [parent=#CardinalSplineBy] clone 
-- @param self
-- @return CardinalSplineBy#CardinalSplineBy ret (return value: cc.CardinalSplineBy)
        
--------------------------------
-- 
-- @function [parent=#CardinalSplineBy] updatePosition 
-- @param self
-- @param #vec2_table newPos
-- @return CardinalSplineBy#CardinalSplineBy self (return value: cc.CardinalSplineBy)
        
--------------------------------
-- 
-- @function [parent=#CardinalSplineBy] reverse 
-- @param self
-- @return CardinalSplineBy#CardinalSplineBy ret (return value: cc.CardinalSplineBy)
        
--------------------------------
-- 
-- @function [parent=#CardinalSplineBy] CardinalSplineBy 
-- @param self
-- @return CardinalSplineBy#CardinalSplineBy self (return value: cc.CardinalSplineBy)
        
return nil
