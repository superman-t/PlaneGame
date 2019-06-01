set(cocos_root ${Cocos2d-X_SOURCE_DIR})

include_directories(
  ${cocos_root}/external/lua/tolua
  ${cocos_root}/external/lua/lua
  ${cocos_root}/external/lua
  ${cocos_root}/external/xxtea
  ${cocos_root}/external
  ${cocos_root}/cocos
  ${cocos_root}/cocos/editor-support
)

file(GLOB lua_cocos2d_source_files
    "${cocos_root}/external/lua/lua/*.c"
    "${cocos_root}/external/lua/tolua/*.c"
    "${cocos_root}/external/xxtea/xxtea.cpp"
    )

list(APPEND lua_cocos2d_source_files
        ${cocos_root}/external/lua/luasocket/luasocket.c
        ${cocos_root}/external/lua/luasocket/timeout.c
        ${cocos_root}/external/lua/luasocket/buffer.c
        ${cocos_root}/external/lua/luasocket/io.c
        ${cocos_root}/external/lua/luasocket/auxiliar.c
        ${cocos_root}/external/lua/luasocket/options.c
        ${cocos_root}/external/lua/luasocket/inet.c
        ${cocos_root}/external/lua/luasocket/except.c
        ${cocos_root}/external/lua/luasocket/select.c
        ${cocos_root}/external/lua/luasocket/tcp.c
        ${cocos_root}/external/lua/luasocket/udp.c
        ${cocos_root}/external/lua/luasocket/mime.c
        ${cocos_root}/external/lua/luasocket/luasocket_scripts.c
	)

if(WINDOWS)
    if(MINGW)
        add_definitions(-DLUASOCKET_INET_ATON -DLUASOCKET_INET_PTON)
    endif()
    add_definitions(-DWIN32 -D_WINDOWS)
    list(APPEND lua_cocos2d_source_files
        ${cocos_root}/external/lua/luasocket/wsocket.c
        )
elseif(UNIX)
    # because we have -std=c99
    add_definitions(-D_POSIX_C_SOURCE=200809L)
    if(LINUX)
        add_definitions(-D_BSD_SOURCE -D_DEFAULT_SOURCE)
    endif()
    if(APPLE)
        add_definitions(-D_DARWIN_C_SOURCE)
    endif()

    list(APPEND lua_cocos2d_source_files
        ${cocos_root}/external/lua/luasocket/serial.c
        ${cocos_root}/external/lua/luasocket/unix.c
        ${cocos_root}/external/lua/luasocket/usocket.c
        )
endif()

set(lua_bindings_manual_files
    manual/CCLuaBridge.cpp
    manual/CCLuaEngine.cpp
    manual/CCLuaStack.cpp
    manual/CCLuaValue.cpp
    manual/Cocos2dxLuaLoader.cpp
    manual/LuaBasicConversions.cpp
    manual/lua_module_register.cpp
    manual/tolua_fix.cpp
    manual/CCComponentLua.cpp
    manual/cocos2d/LuaOpengl.cpp
    manual/cocos2d/LuaScriptHandlerMgr.cpp
    manual/cocos2d/lua_cocos2dx_deprecated.cpp
    manual/cocos2d/lua_cocos2dx_manual.cpp
    manual/controller/lua_cocos2dx_controller_manual.cpp
    manual/ui/lua_cocos2dx_ui_manual.cpp

    )

set(lua_bindings_auto_files
    auto/lua_cocos2dx_auto.cpp
    auto/lua_cocos2dx_controller_auto.cpp
    auto/lua_cocos2dx_ui_auto.cpp
    )

if(MACOSX)
    set(lua_bindings_manual_files
        ${lua_bindings_manual_files}
        manual/platform/ios/CCLuaObjcBridge.mm
        )
endif()

if(USE_BULLET)
  include_directories(${BULLET_INCLUDE_DIRS})
endif()

set(lua_bindings_files ${lua_cocos2d_source_files} ${lua_bindings_manual_files} ${lua_bindings_auto_files})

add_library(luacocos2d ${lua_bindings_files})
target_link_libraries(luacocos2d cocos2d)
set_target_properties(luacocos2d
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)
