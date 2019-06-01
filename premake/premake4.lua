solution "cocos2d"
	location "build"
	language   "C++"
	cxxdialect "C++11"
	configuration {"Debug", "Release"}

	flags { "ExtraWarnings", "FatalWarnings", "RuntimeSearchPath", "Symbols" }
	objdir ( "../Temp" )

	buildoptions { "/MP" }
	defines { "_ALLOW_RTCc_IN_STL" }

if os.get() == "windows" then
	local cocos2d = require("premake-cocos")
	local cocos2d_external = require("premake-external")
	project "PlaneGame"
		uuid "c44ce759-b702-40bb-a67c-7951810c84aa"
		kind "WindowedApp"
		
		defines { "_DEBUG", "_WINDOWS", "WINDOWS","COCOS2D_DEBUG=1", "_CRT_SECURE_NO_WARNINGS",
					"_SCL_SECURE_NO_WARNINGS"
				}
		links {"libcocos2d"}
		libdirs {"Lib"}
		flags { "WinMain", "Symbols" }
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
			"/wd4503",
		}

		cocos2d.AddFiles({includes = cocos2d.includes})
		cocos2d.AddFiles({includes = cocos2d_external.includes})
		includedirs { "../PlaneGame/Classes"  }

		files { "../PlaneGame/Classes/**", "../PlaneGame/proj.win32/main.**"}
		excludes {"../PlaneGame/Classes/BulletSprite.cpp"}
		vpaths      { ["*"] = "../PlaneGame/**" }

		cocos2d.SetTargetDirectories()

		cocos2d.CopyFiles("../external/win32/libs/glew32.dll", "Bin/glew32.dll")
		cocos2d.CopyFiles("../PlaneGame/Resources", "Bin/Resources")

		configuration {"Debug"}
			buildoptions { "/MDd", "/Zi", "/Gm"}

		configuration {"Release"}
			buildoptions { "/MD","/Zi", "/Gm" }

end