-- premake5.lua
workspace "App"
   configurations { "Debug", "Release" }

project "C++ProjectInitializer"
   kind "ConsoleApp"
   language "C++"
   targetdir "bin/%{cfg.buildcfg}"

   files { "include/**.hpp", "src/**.cpp" }

   -- this is where we will define where the header files are
   includedirs{
      "include"
   }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"