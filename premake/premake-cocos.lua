local cocos2d = {}
local cocos2d_external = require("premake-external")

cocos2d.src = {
	"cocos/cocos2d.**",
	"cocos/**",
}



cocos2d.excludes = {
	"**android**",
	"**apple**", 
	"**ios**" ,
	"**mac**" ,
	"**/android/**",
	"**/apple/**", 
	"**/ios/**" ,
	"**/mac/**" ,
	"**/iOS/**",
	"**/Mac/**",
	"**/scripting/**",
}

cocos2d.includes = {
	"cocos",
	"cocos/2d",
	"cocos/base",
	"cocos/deprecated",
	"cocos/math",
	"cocos/platform",
	"cocos/platform/win32",
	"cocos/renderer",
	"cocos/ui",
}


local function AddFiles(t) 
	local rootDir = "../"
	local fileLists = {}
	local includeList = {}
	local excludeLists = {}

	if t.src then
		for _, v in pairs(t.src) do
			table.insert(fileLists, rootDir .. v)
		end
	end

	if t.excludes then
		for _, v in pairs(t.excludes) do
			table.insert(excludeLists, rootDir .. v)
		end
	end

	table.insert( includeList, rootDir)
	for _, include in pairs( t.includes ) do
		table.insert(includeList, rootDir .. include)
	end

	files    	( fileLists )
	includedirs ( includeList )
	excludes 	( excludeLists )
end
cocos2d.AddFiles = AddFiles

-- Sets target output directories.
if not SetTargetDirectories then
	function SetTargetDirectories()
		local platformName = { "Debug", "Release"}

		local binLocation = "Bin/"
		local libLocation = "Lib/"

		os.mkdir (binLocation)
		os.mkdir (libLocation)
		for _, platform in pairs (platformName) do
			configuration { platform, "SharedLib or ConsoleApp or WindowedApp" }
			targetdir     ( binLocation )

			configuration { platform, "StaticLib" }
			targetdir     ( libLocation )

			configuration { platform, "SharedLib" }
			implibdir     ( libLocation )
		end
	end
end
cocos2d.SetTargetDirectories = SetTargetDirectories

local function CopyFiles(src, des)
	if os.get() == "windows" then
		print(src)
		src = string.gsub(src, "/", "\\")
		des = string.gsub(des, "/", "\\")
		if os.isdir(src) then
			os.execute( "xcopy /y /s /e /q /i " .. src .. " " .. des )
		else
			os.copyfile(src, des)
		end
	else
		print("other")
		src = string.gsub(src, "\\", "/")
		des = string.gsub(des, "\\", "/")
		os.execute( "cp -rf " .. src .. " " .. des)
	end
end
cocos2d.CopyFiles = CopyFiles

project "freetype"
	uuid "9ab72a5a-8f19-11e8-9eb6-529269fb1459"
    kind "StaticLib"

    defines { "FT2_BUILD_LIBRARY" }

	configuration {}

	targetname "freetype"
	vpaths      { ["*"] = "../freetype/**" }

    includedirs { "../freetype/include", "../freetype/include/config", "../freetype/include/internal", "../freetype/src", "../freetype/src/truetype", "../freetype/src/sfnt", "../freetype/src/autofit", 
    "../freetype/src/smooth", "../freetype/src/raster", "../freetype/src/psaux", "../freetype/src/psnames", }

    files {   
	  "../freetype/src/autofit/autofit.c",
	  "../freetype/src/base/ftadvanc.c",
	  "../freetype/src/base/ftbbox.c",
	  "../freetype/src/base/ftbdf.c",
	  "../freetype/src/base/ftbitmap.c",
	  "../freetype/src/base/ftcalc.c",
	  "../freetype/src/base/ftcid.c",
	  "../freetype/src/base/ftdbgmem.c",
	  "../freetype/src/base/ftdebug.c",
	  "../freetype/src/base/ftfntfmt.c",
	  "../freetype/src/base/ftfstype.c",
	  "../freetype/src/base/ftgasp.c",
	  "../freetype/src/base/ftgloadr.c",
	  "../freetype/src/base/ftglyph.c",
	  "../freetype/src/base/ftgxval.c",
	  "../freetype/src/base/ftinit.c",
	  "../freetype/src/base/ftlcdfil.c",
	  "../freetype/src/base/ftmm.c",
	  "../freetype/src/base/ftobjs.c",
	  "../freetype/src/base/ftotval.c",
	  "../freetype/src/base/ftoutln.c",
	  "../freetype/src/base/ftpatent.c",
	  "../freetype/src/base/ftpfr.c",
	  "../freetype/src/base/ftrfork.c",
	  "../freetype/src/base/ftsnames.c",
	  "../freetype/src/base/ftstream.c",
	  "../freetype/src/base/ftstroke.c",
	  "../freetype/src/base/ftsynth.c",
	  "../freetype/src/base/ftsystem.c",
	  "../freetype/src/base/fttrigon.c",
	  "../freetype/src/base/fttype1.c",
	  "../freetype/src/base/ftutil.c",
	  "../freetype/src/base/ftwinfnt.c",
	  "../freetype/src/bdf/bdf.c",
	  "../freetype/src/bzip2/ftbzip2.c",
	  "../freetype/src/cache/ftcache.c",
	  "../freetype/src/cff/cff.c",
	  "../freetype/src/cid/type1cid.c",
	  "../freetype/src/gzip/ftgzip.c",
	  "../freetype/src/lzw/ftlzw.c",
	  "../freetype/src/pcf/pcf.c",
	  "../freetype/src/pfr/pfr.c",
	  "../freetype/src/psaux/psaux.c",
	  "../freetype/src/pshinter/pshinter.c",
	  "../freetype/src/psnames/psmodule.c",
	  "../freetype/src/raster/raster.c",
	  "../freetype/src/sfnt/sfnt.c",
	  "../freetype/src/smooth/smooth.c",
	  "../freetype/src/truetype/truetype.c",
	  "../freetype/src/type1/type1.c",
	  "../freetype/src/type42/type42.c",
	  "../freetype/src/winfonts/winfnt.c",
    }

	SetTargetDirectories()
 	configuration "Debug"
        flags { "Symbols" }
        targetname "freetype"
      
    configuration "Release"
        flags { "Optimize" }
        targetname "freetype"

project "libcocos2d"
	uuid "ac6b5c42-0acb-454f-a44c-0f215f1d39a5"
	kind "SharedLib"
	configurations { "Debug" }
		defines { "_DEBUG", "COCOS2D_DEBUG=1",}
	if os.get() == "windows" then
		defines { "WIN32", "_WINDOWS", "WINDOWS", "COCOS2DXWIN32_EXPORTS", "_WINDLL", }
	end

	defines {"_USRDLL", "_LIB", "LWS_DLL", "GL_GLEXT_PROTOTYPES",  "_CRT_SECURE_NO_WARNINGS",
				"_SCL_SECURE_NO_WARNINGS", "_EXPORT_DLL_", "_USRSTUDIODLL", "_USREXDLL", "_USEGUIDLL",
				"_VARIADIC_MAX=10",  "_UNICODE", "UNICODE"
			}

	links {"opengl32", "glew32", "libzlib", "libwebp", "freetype", "winmm", "ws2_32", "version"}
	libdirs { "Lib"}
	flags {  "Symbols" }
	-- linkoptions { "/NODEFAULTLIB:LIBCMT" }
	buildoptions {
		"/wd4305", 
		"/wd4251",
		"/wd4244",
		"/wd4334",
		"/wd4005",
		"/wd4820",
		"/wd4710",
		"/wd4514",
		"/wd4056",
		"/wd4996",
		"/wd4099",
	}
	
	AddFiles(cocos2d)
	AddFiles(cocos2d_external)
	includedirs { "../freetype/include", "../freetype/include/config", "../freetype/include/internal", "../freetype/src", "../freetype/src/truetype", "../freetype/src/sfnt", "../freetype/src/autofit", 
    "../freetype/src/smooth", "../freetype/src/raster", "../freetype/src/psaux", "../freetype/src/psnames", }
	SetTargetDirectories()
	if os.get() == "windows" then
		for k, name in pairs(cocos2d_external.thirdLib) do
			CopyFiles("../external/win32/libs/" .. name .. ".lib", "Lib/" .. name .. ".lib")
			if _ACTION >= "vs2015" then
				CopyFiles("../external/win32/libs/" .. name .. "-2015.lib", "Lib/" .. name .. "-2015.lib")
			end

		end
	end

	configuration {"Debug"}
		buildoptions { "/MDd", "/Zi", "/Gm" }

	configuration {"Release"}
		buildoptions { "/MD", "/Zi", "/Gm" }

project "libluacocos2d"
	uuid "9ab72a5a-8f19-11e8-9eb6-529269fb1459"
    kind "StaticLib"

    defines { "_USRLUASTATIC" }



    includedirs { "../external/sources/lua/tolua", "../external/sources/lua/lua", "../external/sources/lua", "../external/sources/xxtea",
			"../external/sources/", "../cocos", "../cocos/scripting", }

	files {
		"../external/sources/lua/**",
		"../external/sources/xxtea/**",
		"../cocos/scripting/lua-bindings/auto/*.cpp",
		"../cocos/scripting/lua-bindings/auto/*.hpp",
		"../cocos/scripting/lua-bindings/manual/CCLuaBridge.**",
		"../cocos/scripting/lua-bindings/manual/CCLuaEngine.**",
		"../cocos/scripting/lua-bindings/manual/CCLuaStack.**",
		"../cocos/scripting/lua-bindings/manual/CCLuaValue.**",
		"../cocos/scripting/lua-bindings/manual/Cocos2dxLuaLoader.**",
		"../cocos/scripting/lua-bindings/manual/LuaBasicConversions.**",
		"../cocos/scripting/lua-bindings/manual/lua_module_register.**",
		"../cocos/scripting/lua-bindings/manual/tolua_fix.**",
		"../cocos/scripting/lua-bindings/manual/CCComponentLua.**",
		"../cocos/scripting/lua-bindings/manual/cocos2d/LuaOpengl.**",
		"../cocos/scripting/lua-bindings/manual/cocos2d/LuaScriptHandlerMgr.**",
		"../cocos/scripting/lua-bindings/manual/cocos2d/lua_cocos2dx_deprecated.**",
		"../cocos/scripting/lua-bindings/manual/cocos2d/lua_cocos2dx_manual.**",
		"../cocos/scripting/lua-bindings/manual/controller/lua_cocos2dx_controller_manual.**",
		"../cocos/scripting/lua-bindings/manual/ui/lua_cocos2dx_ui_manual.**",
	}	

	if os.get() == "macosx" then
		files { "../cocos/scripting/lua-bindings/manual/platform/ios/CCLuaObjcBridge.mm" }
	end

	if os.get() == "windows" then
		includedirs { "../external/win32/include", "../external/win32/include/gles", "../external/win32/include/glfw3" }
	end

	if os.get() == "windows" then
	    defines { "WIN32", "_WINDOWS" }
	else
		defines { "_POSIX_C_SOURCE=200809L"}
		if os.get() == "linux" then
			defines { "_BSD_SOURCE", "_DEFAULT_SOURCE"}
		else
			defines { "_DARWIN_C_SOURCE" }
		end
	end

	libdirs { "Lib"}

	links { "libcocos2d", "glew32"}
	
	SetTargetDirectories()
	configuration {"Debug"}
		buildoptions { "/MDd", "/Zi", "/Gm" }

	configuration {"Release"}
		buildoptions { "/MD", "/Zi", "/Gm" }



return cocos2d