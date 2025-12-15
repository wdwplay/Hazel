#pragma once

// 我们要定义一个宏，使得这个宏不是_declspec(dllexport)就是_declspec(dllimport)
// 具体的，当这个宏存在于Hazel项目中时为_declspec(dllexport)，当这个宏存在于调用Hazel的dll
// 的项目中时为_declspec(dllimport)
// 另外declspec只存在与windows操作系统中，我们目前支持Windows平台

#ifdef HZ_PLATFORM_WINDOWS
	#ifdef HZ_BUILD_DLL
		#define HAZEL_API _declspec(dllexport)
	#else
		#define HAZEL_API _declspec(dllimport)
	#endif // HZ_BUILD_DLL
#else
	#error Hazel only support Windows!
#endif // HZ_PLATFORM_WINDOWS
