local external = {}

local platforms = { "android", "ios", "mac", "win32"}

local postfix = {"h", "hpp", "c", "cpp", "cc"}

local thirdLibSources = { "clipper", "ConvertUTF", "edtaa3func", "poly2tri", "rapidxml", "tinydir","tinyxml2", "unzip", "xxhash"}

external.thirdLib = { "glew32", "glfw3", "libiconv", "libjpeg", "libpng", "libtiff", "libzlib", "libwebp"}


external.src = {}

for _, dir in pairs(thirdLibSources) do
		for _, fix in pairs(postfix) do
			table.insert(external.src, "external/sources/" .. dir .. "/**.".. fix)
		end
end

external.excludes = {

}

external.includes = {}

local thirdIncludes = { "gles", "glfw3", "icon", "jpeg", "png", "tiff", "webp", "zlib"}


table.insert( external.includes, "external/sources/" )

for k, v in pairs( thirdLibSources ) do
	table.insert( external.includes, "external/sources/" .. v )
end	


if os.get() == "windows" then
	table.insert( external.includes, "external/win32/include" )
	for k, v in pairs( thirdIncludes ) do
		table.insert( external.includes, "external/win32/include/" .. v )
	end
end

return external