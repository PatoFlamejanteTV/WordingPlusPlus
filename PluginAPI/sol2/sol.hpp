// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_SINGLE_INCLUDE_HPP
#define SOL_SINGLE_INCLUDE_HPP

// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_VERSION_HPP
#define SOL_VERSION_HPP

#include <sol/config.hpp>

// clang-format off

#define SOL_VERSION_MAJOR 3
#define SOL_VERSION_MINOR 5
#define SOL_VERSION_PATCH 0
#define SOL_VERSION_STRING "3.5.0"
#define SOL_VERSION ((SOL_VERSION_MAJOR * 100000) + (SOL_VERSION_MINOR * 100) + (SOL_VERSION_PATCH))

#define SOL_TOKEN_TO_STRING_POST_EXPANSION_I_(_TOKEN) #_TOKEN
#define SOL_TOKEN_TO_STRING_I_(_TOKEN) SOL_TOKEN_TO_STRING_POST_EXPANSION_I_(_TOKEN)

#define SOL_CONCAT_TOKENS_POST_EXPANSION_I_(_LEFT, _RIGHT) _LEFT##_RIGHT
#define SOL_CONCAT_TOKENS_I_(_LEFT, _RIGHT) SOL_CONCAT_TOKENS_POST_EXPANSION_I_(_LEFT, _RIGHT)

#define SOL_RAW_USE(SYMBOL) SYMBOL
#define SOL_RAW_IS_ON(OP_SYMBOL) ((3 OP_SYMBOL 3) != 0)
#define SOL_RAW_IS_OFF(OP_SYMBOL) ((3 OP_SYMBOL 3) == 0)
#define SOL_RAW_IS_DEFAULT_ON(OP_SYMBOL) ((3 OP_SYMBOL 3) > 3)
#define SOL_RAW_IS_DEFAULT_OFF(OP_SYMBOL) ((3 OP_SYMBOL 3 OP_SYMBOL 3) < 0)

#define SOL_IS_ON(OP_SYMBOL) SOL_RAW_IS_ON(OP_SYMBOL ## _I_)
#define SOL_IS_OFF(OP_SYMBOL) SOL_RAW_IS_OFF(OP_SYMBOL ## _I_)
#define SOL_IS_DEFAULT_ON(OP_SYMBOL) SOL_RAW_IS_DEFAULT_ON(OP_SYMBOL ## _I_)
#define SOL_IS_DEFAULT_OFF(OP_SYMBOL) SOL_RAW_IS_DEFAULT_OFF(OP_SYMBOL ## _I_)
#define SOL_USE(SYMBOL) SOL_RAW_USE(SYMBOL ## _I_)

#define SOL_ON          |
#define SOL_OFF         ^
#define SOL_DEFAULT_ON  +
#define SOL_DEFAULT_OFF -

#if defined(SOL_BUILD_CXX_MODE)
	#if (SOL_BUILD_CXX_MODE != 0)
		#define SOL_BUILD_CXX_MODE_I_ SOL_ON
	#else
		#define SOL_BUILD_CXX_MODE_I_ SOL_OFF
	#endif
#elif defined(__cplusplus)
	#define SOL_BUILD_CXX_MODE_I_ SOL_DEFAULT_ON
#else
	#define SOL_BUILD_CXX_MODE_I_ SOL_DEFAULT_OFF
#endif

#if defined(SOL_BUILD_C_MODE)
	#if (SOL_BUILD_C_MODE != 0)
		#define SOL_BUILD_C_MODE_I_ SOL_ON
	#else
		#define SOL_BUILD_C_MODE_I_ SOL_OFF
	#endif
#elif defined(__STDC__)
	#define SOL_BUILD_C_MODE_I_ SOL_DEFAULT_ON
#else
	#define SOL_BUILD_C_MODE_I_ SOL_DEFAULT_OFF
#endif

#if SOL_IS_ON(SOL_BUILD_C_MODE)
	#include <stddef.h>
	#include <stdint.h>
	#include <limits.h>
#else
	#include <cstddef>
	#include <cstdint>
	#include <climits>
#endif

#if defined(SOL_HAS_BUILTIN)
	#define SOL_HAS_BUILTIN_I_(...) SOL_HAS_BUILTIN(__VA_ARGS__)
#elif defined(__has_builtin)
	#define SOL_HAS_BUILTIN_I_(...) __has_builtin(__VA_ARGS__)
#else
	#define SOL_HAS_BUILTIN_I_(...) 0
#endif

#if defined(SOL_COMPILER_VCXX)
	#if (SOL_COMPILER_VCXX != 0)
		#define SOL_COMPILER_VCXX_I_ SOL_ON
	#else
		#define SOL_COMPILER_VCXX_I_ SOL_OFF
	#endif
#elif defined(_MSC_VER)
	#define SOL_COMPILER_VCXX_I_ SOL_DEFAULT_ON
#else
	#define SOL_COMPILER_VCXX_I_ SOL_DEFAULT_OFF
#endif

#if defined(SOL_COMPILER_GCC)
	#if (SOL_COMPILER_GCC != 0)
		#define SOL_COMPILER_GCC_I_ SOL_ON
	#else
		#define SOL_COMPILER_GCC_I_ SOL_OFF
	#endif
#elif defined(__GNUC__)
	#define SOL_COMPILER_GCC_I_ SOL_DEFAULT_ON
#else
	#define SOL_COMPILER_GCC_I_ SOL_DEFAULT_OFF
#endif

#if defined(SOL_COMPILER_CLANG)
	#if (SOL_COMPILER_CLANG != 0)
		#define SOL_COMPILER_CLANG_I_ SOL_ON
	#else
		#define SOL_COMPILER_CLANG_I_ SOL_OFF
	#endif
#elif defined(__clang__)
	#define SOL_COMPILER_CLANG_I_ SOL_DEFAULT_ON
#else
	#define SOL_COMPILER_CLANG_I_ SOL_DEFAULT_OFF
#endif

#if defined(SOL_COMPILER_EDG)
	#if (SOL_COMPILER_EDG != 0)
		#define SOL_COMPILER_EDG_I_ SOL_ON
	#else
		#define SOL_COMPILER_EDG_I_ SOL_OFF
	#endif
#else
	#define SOL_COMPILER_EDG_I_ SOL_DEFAULT_OFF
#endif

#if defined(SOL_COMPILER_MINGW)
	#if (SOL_COMPILER_MINGW != 0)
		#define SOL_COMPILER_MINGW_I_ SOL_ON
	#else
		#define SOL_COMPILER_MINGW_I_ SOL_OFF
	#endif
#elif defined(__MINGW32__)
	#define SOL_COMPILER_MINGW_I_ SOL_DEFAULT_ON
#else
	#define SOL_COMPILER_MINGW_I_ SOL_DEFAULT_OFF
#endif

#if SIZE_MAX <= 0xFFFFULL
	#define SOL_PLATFORM_X16_I_ SOL_ON
	#define SOL_PLATFORM_X86_I_ SOL_OFF
	#define SOL_PLATFORM_X64_I_ SOL_OFF
#elif SIZE_MAX <= 0xFFFFFFFFULL
	#define SOL_PLATFORM_X16_I_ SOL_OFF
	#define SOL_PLATFORM_X86_I_ SOL_ON
	#define SOL_PLATFORM_X64_I_ SOL_OFF
#else
	#define SOL_PLATFORM_X16_I_ SOL_OFF
	#define SOL_PLATFORM_X86_I_ SOL_OFF
	#define SOL_PLATFORM_X64_I_ SOL_ON
#endif

// TODO: ARM codes? So far, not needed explicitly...
#define SOL_PLATFORM_ARM32_I_ SOL_OFF
#define SOL_PLATFORM_ARM64_I_ SOL_OFF

#if defined(SOL_PLATFORM_WINDOWS)
	#if (SOL_PLATFORM_WINDOWS != 0)
		#define SOL_PLATFORM_WINDOWS_I_ SOL_ON
	#else
		#define SOL_PLATFORM_WINDOWS_I_ SOL_OFF
	#endif
#elif defined(_WIN32)
	#define SOL_PLATFORM_WINDOWS_I_ SOL_DEFAULT_ON
#else
	#define SOL_PLATFORM_WINDOWS_I_ SOL_DEFAULT_OFF
#endif

#if defined(SOL_PLATFORM_CYGWIN)
	#if (SOL_PLATFORM_CYGWIN != 0)
		#define SOL_PLATFORM_CYGWIN_I_ SOL_ON
	#else
		#define SOL_PLATFORM_CYGWIN_I_ SOL_ON
	#endif
#elif defined(__CYGWIN__)
	#define SOL_PLATFORM_CYGWIN_I_ SOL_DEFAULT_ON
#else
	#define SOL_PLATFORM_CYGWIN_I_ SOL_DEFAULT_OFF
#endif

#if defined(SOL_PLATFORM_APPLE)
	#if (SOL_PLATFORM_APPLE != 0)
		#define SOL_PLATFORM_APPLE_I_ SOL_ON
	#else
		#define SOL_PLATFORM_APPLE_I_ SOL_OFF
	#endif
#elif defined(__APPLE__)
	#define SOL_PLATFORM_APPLE_I_ SOL_DEFAULT_ON
#else
	#define SOL_PLATFORM_APPLE_I_ SOL_DEFAULT_OFF
#endif

#if defined(SOL_PLATFORM_UNIX)
	#if (SOL_PLATFORM_UNIX != 0)
		#define SOL_PLATFORM_UNIXLIKE_I_ SOL_ON
	#else
		#define SOL_PLATFORM_UNIXLIKE_I_ SOL_OFF
	#endif
#elif defined(__unix__)
	#define SOL_PLATFORM_UNIXLIKE_I_ SOL_DEFAULT_ON
#else
	#define SOL_PLATFORM_UNIXLIKE_I_ SOL_DEFAULT_OFF
#endif

#if defined(SOL_PLATFORM_LINUX)
	#if (SOL_PLATFORM_LINUX != 0)
		#define SOL_PLATFORM_LINUXLIKE_I_ SOL_ON
	#else
		#define SOL_PLATFORM_LINUXLIKE_I_ SOL_OFF
	#endif
#elif defined(__LINUX__)
	#define SOL_PLATFORM_LINUXLIKE_I_ SOL_DEFAULT_ON
#else
	#define SOL_PLATFORM_LINUXLIKE_I_ SOL_DEFAULT_OFF
#endif

#define SOL_PLATFORM_APPLE_IPHONE_I_ SOL_OFF
#define SOL_PLATFORM_BSDLIKE_I_      SOL_OFF

#if defined(SOL_IN_DEBUG_DETECTED)
	#if (SOL_IN_DEBUG_DETECTED != 0)
		#define SOL_DEBUG_BUILD_I_ SOL_ON
	#else
		#define SOL_DEBUG_BUILD_I_ SOL_OFF
	#endif
#elif !defined(NDEBUG)
	#if SOL_IS_ON(SOL_COMPILER_VCXX) && defined(_DEBUG)
		#define SOL_DEBUG_BUILD_I_ SOL_ON
	#elif (SOL_IS_ON(SOL_COMPILER_CLANG) || SOL_IS_ON(SOL_COMPILER_GCC)) && !defined(__OPTIMIZE__)
		#define SOL_DEBUG_BUILD_I_ SOL_ON
	#else
		#define SOL_DEBUG_BUILD_I_ SOL_OFF
	#endif
#else
	#define SOL_DEBUG_BUILD_I_ SOL_DEFAULT_OFF
#endif // We are in a debug mode of some sort

#if defined(SOL_NO_EXCEPTIONS)
	#if (SOL_NO_EXCEPTIONS != 0)
		#define SOL_EXCEPTIONS_I_ SOL_OFF
	#else
		#define SOL_EXCEPTIONS_I_ SOL_ON
	#endif
#elif SOL_IS_ON(SOL_COMPILER_VCXX)
	#if !defined(_CPPUNWIND)
		#define SOL_EXCEPTIONS_I_ SOL_OFF
	#else
		#define SOL_EXCEPTIONS_I_ SOL_ON
	#endif
#elif SOL_IS_ON(SOL_COMPILER_CLANG) || SOL_IS_ON(SOL_COMPILER_GCC)
	#if !defined(__EXCEPTIONS)
		#define SOL_EXCEPTIONS_I_ SOL_OFF
	#else
		#define SOL_EXCEPTIONS_I_ SOL_ON
	#endif
#else
	#define SOL_EXCEPTIONS_I_ SOL_DEFAULT_ON
#endif


#if defined(SOL_NO_RTTI)
	#if (SOL_NO_RTTI != 0)
		#define SOL_RTTI_I_ SOL_OFF
	#else
		#define SOL_RTTI_I_ SOL_ON
	#endif
#elif SOL_IS_ON(SOL_COMPILER_VCXX)
	#if !defined(_CPPRTTI)
		#define SOL_RTTI_I_ SOL_OFF
	#else
		#define SOL_RTTI_I_ SOL_ON
	#endif
#elif SOL_IS_ON(SOL_COMPILER_CLANG) || SOL_IS_ON(SOL_COMPILER_GCC)
	#if !defined(__GXX_RTTI)
		#define SOL_RTTI_I_ SOL_OFF
	#else
		#define SOL_RTTI_I_ SOL_ON
	#endif
#else
	#define SOL_RTTI_I_ SOL_DEFAULT_ON
#endif

#if defined(SOL_NO_THREAD_LOCAL)
	#if (SOL_NO_THREAD_LOCAL != 0)
		#define SOL_USE_THREAD_LOCAL_I_ SOL_OFF
	#else
		#define SOL_USE_THREAD_LOCAL_I_ SOL_ON
	#endif
#else
	#define SOL_USE_THREAD_LOCAL_I_ SOL_DEFAULT_ON
#endif // thread_local keyword is bjorked on some platforms

#if defined(SOL_ALL_SAFETIES_ON)
	#if (SOL_ALL_SAFETIES_ON != 0)
		#define SOL_ALL_SAFETIES_ON_I_ SOL_ON
	#else
		#define SOL_ALL_SAFETIES_ON_I_ SOL_OFF
	#endif
#else
	#define SOL_ALL_SAFETIES_ON_I_ SOL_DEFAULT_OFF
#endif

#if defined(SOL_SAFE_GETTER)
	#if (SOL_SAFE_GETTER != 0)
		#define SOL_SAFE_GETTER_I_ SOL_ON
	#else
		#define SOL_SAFE_GETTER_I_ SOL_OFF
	#endif
#else
	#if SOL_IS_ON(SOL_ALL_SAFETIES_ON)
		#define SOL_SAFE_GETTER_I_ SOL_ON
	#elif SOL_IS_ON(SOL_DEBUG_BUILD)
		#define SOL_SAFE_GETTER_I_ SOL_DEFAULT_ON
	#else
		#define SOL_SAFE_GETTER_I_ SOL_DEFAULT_OFF
	#endif
#endif

#if defined(SOL_SAFE_USERTYPE)
	#if (SOL_SAFE_USERTYPE != 0)
		#define SOL_SAFE_USERTYPE_I_ SOL_ON
	#else
		#define SOL_SAFE_USERTYPE_I_ SOL_OFF
	#endif
#else
	#if SOL_IS_ON(SOL_ALL_SAFETIES_ON)
		#define SOL_SAFE_USERTYPE_I_ SOL_ON
	#elif SOL_IS_ON(SOL_DEBUG_BUILD)
		#define SOL_SAFE_USERTYPE_I_ SOL_DEFAULT_ON
	#else
		#define SOL_SAFE_USERTYPE_I_ SOL_DEFAULT_OFF
	#endif
#endif

#if defined(SOL_SAFE_REFERENCES)
	#if (SOL_SAFE_REFERENCES != 0)
		#define SOL_SAFE_REFERENCES_I_ SOL_ON
	#else
		#define SOL_SAFE_REFERENCES_I_ SOL_OFF
	#endif
#else
	#if SOL_IS_ON(SOL_ALL_SAFETIES_ON)
		#define SOL_SAFE_REFERENCES_I_ SOL_ON
	#elif SOL_IS_ON(SOL_DEBUG_BUILD)
		#define SOL_SAFE_REFERENCES_I_ SOL_DEFAULT_ON
	#else
		#define SOL_SAFE_REFERENCES_I_ SOL_DEFAULT_OFF
	#endif
#endif

#if defined(SOL_SAFE_FUNCTIONS)
	#if (SOL_SAFE_FUNCTIONS != 0)
		#define SOL_SAFE_FUNCTION_OBJECTS_I_ SOL_ON
	#else
		#define SOL_SAFE_FUNCTION_OBJECTS_I_ SOL_OFF
	#endif
#elif defined (SOL_SAFE_FUNCTION_OBJECTS)
	#if (SOL_SAFE_FUNCTION_OBJECTS != 0)
		#define SOL_SAFE_FUNCTION_OBJECTS_I_ SOL_ON
	#else
		#define SOL_SAFE_FUNCTION_OBJECTS_I_ SOL_OFF
	#endif
#else
	#if SOL_IS_ON(SOL_ALL_SAFETIES_ON)
		#define SOL_SAFE_FUNCTION_OBJECTS_I_ SOL_ON
	#elif SOL_IS_ON(SOL_DEBUG_BUILD)
		#define SOL_SAFE_FUNCTION_OBJECTS_I_ SOL_DEFAULT_ON
	#else
		#define SOL_SAFE_FUNCTION_OBJECTS_I_ SOL_DEFAULT_OFF
	#endif
#endif

#if defined(SOL_SAFE_FUNCTION_CALLS)
	#if (SOL_SAFE_FUNCTION_CALLS != 0)
		#define SOL_SAFE_FUNCTION_CALLS_I_ SOL_ON
	#else
		#define SOL_SAFE_FUNCTION_CALLS_I_ SOL_OFF
	#endif
#else
	#if SOL_IS_ON(SOL_ALL_SAFETIES_ON)
		#define SOL_SAFE_FUNCTION_CALLS_I_ SOL_ON
	#elif SOL_IS_ON(SOL_DEBUG_BUILD)
		#define SOL_SAFE_FUNCTION_CALLS_I_ SOL_DEFAULT_ON
	#else
		#define SOL_SAFE_FUNCTION_CALLS_I_ SOL_DEFAULT_OFF
	#endif
#endif

#if defined(SOL_SAFE_PROXIES)
	#if (SOL_SAFE_PROXIES != 0)
		#define SOL_SAFE_PROXIES_I_ SOL_ON
	#else
		#define SOL_SAFE_PROXIES_I_ SOL_OFF
	#endif
#else
	#if SOL_IS_ON(SOL_ALL_SAFETIES_ON)
		#define SOL_SAFE_PROXIES_I_ SOL_ON
	#elif SOL_IS_ON(SOL_DEBUG_BUILD)
		#define SOL_SAFE_PROXIES_I_ SOL_DEFAULT_ON
	#else
		#define SOL_SAFE_PROXIES_I_ SOL_DEFAULT_OFF
	#endif
#endif

#if defined(SOL_SAFE_NUMERICS)
	#if (SOL_SAFE_NUMERICS != 0)
		#define SOL_SAFE_NUMERICS_I_ SOL_ON
	#else
		#define SOL_SAFE_NUMERICS_I_ SOL_OFF
	#endif
#else
	#if SOL_IS_ON(SOL_ALL_SAFETIES_ON)
		#define SOL_SAFE_NUMERICS_I_ SOL_ON
	#elif SOL_IS_ON(SOL_DEBUG_BUILD)
		#define SOL_SAFE_NUMERICS_I_ SOL_DEFAULT_ON
	#else
		#define SOL_SAFE_NUMERICS_I_ SOL_DEFAULT_OFF
	#endif
#endif

#if defined(SOL_ALL_INTEGER_VALUES_FIT)
	#if (SOL_ALL_INTEGER_VALUES_FIT != 0)
		#define SOL_ALL_INTEGER_VALUES_FIT_I_ SOL_ON
	#else
		#define SOL_ALL_INTEGER_VALUES_FIT_I_ SOL_OFF
	#endif
#elif !SOL_IS_DEFAULT_OFF(SOL_SAFE_NUMERICS) && SOL_IS_OFF(SOL_SAFE_NUMERICS)
	// if numerics is intentionally turned off, flip this on
	#define SOL_ALL_INTEGER_VALUES_FIT_I_ SOL_DEFAULT_ON
#else
	// default to off
	#define SOL_ALL_INTEGER_VALUES_FIT_I_ SOL_DEFAULT_OFF
#endif

#if defined(SOL_SAFE_STACK_CHECK)
	#if (SOL_SAFE_STACK_CHECK != 0)
		#define SOL_SAFE_STACK_CHECK_I_ SOL_ON
	#else
		#define SOL_SAFE_STACK_CHECK_I_ SOL_OFF
	#endif
#else
	#if SOL_IS_ON(SOL_ALL_SAFETIES_ON)
		#define SOL_SAFE_STACK_CHECK_I_ SOL_ON
	#elif SOL_IS_ON(SOL_DEBUG_BUILD)
		#define SOL_SAFE_STACK_CHECK_I_ SOL_DEFAULT_ON
	#else
		#define SOL_SAFE_STACK_CHECK_I_ SOL_DEFAULT_OFF
	#endif
#endif

#if defined(SOL_NO_CHECK_NUMBER_PRECISION)
	#if (SOL_NO_CHECK_NUMBER_PRECISION != 0)
		#define SOL_NUMBER_PRECISION_CHECKS_I_ SOL_OFF
	#else
		#define SOL_NUMBER_PRECISION_CHECKS_I_ SOL_ON
	#endif
#elif defined(SOL_NO_CHECKING_NUMBER_PRECISION)
	#if (SOL_NO_CHECKING_NUMBER_PRECISION != 0)
		#define SOL_NUMBER_PRECISION_CHECKS_I_ SOL_OFF
	#else
		#define SOL_NUMBER_PRECISION_CHECKS_I_ SOL_ON
	#endif
#else
	#if SOL_IS_ON(SOL_ALL_SAFETIES_ON)
		#define SOL_NUMBER_PRECISION_CHECKS_I_ SOL_ON
	#elif SOL_IS_ON(SOL_SAFE_NUMERICS)
		#define SOL_NUMBER_PRECISION_CHECKS_I_ SOL_ON
	#elif SOL_IS_ON(SOL_DEBUG_BUILD)
		#define SOL_NUMBER_PRECISION_CHECKS_I_ SOL_DEFAULT_ON
	#else
		#define SOL_NUMBER_PRECISION_CHECKS_I_ SOL_DEFAULT_OFF
	#endif
#endif

#if defined(SOL_STRINGS_ARE_NUMBERS)
	#if (SOL_STRINGS_ARE_NUMBERS != 0)
		#define SOL_STRINGS_ARE_NUMBERS_I_ SOL_ON
	#else
		#define SOL_STRINGS_ARE_NUMBERS_I_ SOL_OFF
	#endif
#else
	#define SOL_STRINGS_ARE_NUMBERS_I_ SOL_DEFAULT_OFF
#endif

#if defined(SOL_ENABLE_INTEROP)
	#if (SOL_ENABLE_INTEROP != 0)
		#define SOL_USE_INTEROP_I_ SOL_ON
	#else
		#define SOL_USE_INTEROP_I_ SOL_OFF
	#endif
#elif defined(SOL_USE_INTEROP)
	#if (SOL_USE_INTEROP != 0)
		#define SOL_USE_INTEROP_I_ SOL_ON
	#else
		#define SOL_USE_INTEROP_I_ SOL_OFF
	#endif
#else
	#define SOL_USE_INTEROP_I_ SOL_DEFAULT_OFF
#endif

#if defined(SOL_NO_NIL)
	#if (SOL_NO_NIL != 0)
		#define SOL_NIL_I_ SOL_OFF
	#else
		#define SOL_NIL_I_ SOL_ON
	#endif
#elif defined(__MAC_OS_X_VERSION_MAX_ALLOWED) || defined(__OBJC__) || defined(nil)
	#define SOL_NIL_I_ SOL_DEFAULT_OFF
#else
	#define SOL_NIL_I_ SOL_DEFAULT_ON
#endif

#if defined(SOL_USERTYPE_TYPE_BINDING_INFO)
	#if (SOL_USERTYPE_TYPE_BINDING_INFO != 0)
		#define SOL_USERTYPE_TYPE_BINDING_INFO_I_ SOL_ON
	#else
		#define SOL_USERTYPE_TYPE_BINDING_INFO_I_ SOL_OFF
	#endif
#else
	#define SOL_USERTYPE_TYPE_BINDING_INFO_I_ SOL_DEFAULT_ON
#endif // We should generate a my_type.__type table with lots of class information for usertypes

#if defined(SOL_AUTOMAGICAL_TYPES_BY_DEFAULT)
	#if (SOL_AUTOMAGICAL_TYPES_BY_DEFAULT != 0)
		#define SOL_DEFAULT_AUTOMAGICAL_USERTYPES_I_ SOL_ON
	#else
		#define SOL_DEFAULT_AUTOMAGICAL_USERTYPES_I_ SOL_OFF
	#endif
#elif defined(SOL_DEFAULT_AUTOMAGICAL_USERTYPES)
	#if (SOL_DEFAULT_AUTOMAGICAL_USERTYPES != 0)
		#define SOL_DEFAULT_AUTOMAGICAL_USERTYPES_I_ SOL_ON
	#else
		#define SOL_DEFAULT_AUTOMAGICAL_USERTYPES_I_ SOL_OFF
	#endif
#else
	#define SOL_DEFAULT_AUTOMAGICAL_USERTYPES_I_ SOL_DEFAULT_ON
#endif // make is_automagical on/off by default

#if defined(SOL_STD_VARIANT)
	#if (SOL_STD_VARIANT != 0)
		#define SOL_STD_VARIANT_I_ SOL_ON
	#else
		#define SOL_STD_VARIANT_I_ SOL_OFF
	#endif
#else
	#if SOL_IS_ON(SOL_COMPILER_CLANG) && SOL_IS_ON(SOL_PLATFORM_APPLE)
		#if defined(__has_include)
			#if __has_include(<variant>)
				#define SOL_STD_VARIANT_I_ SOL_DEFAULT_ON
			#else
				#define SOL_STD_VARIANT_I_ SOL_DEFAULT_OFF
			#endif
		#else
			#define SOL_STD_VARIANT_I_ SOL_DEFAULT_OFF
		#endif
	#else
		#define SOL_STD_VARIANT_I_ SOL_DEFAULT_ON
	#endif
#endif // make is_automagical on/off by default

#if defined(SOL_NOEXCEPT_FUNCTION_TYPE)
	#if (SOL_NOEXCEPT_FUNCTION_TYPE != 0)
		#define SOL_USE_NOEXCEPT_FUNCTION_TYPE_I_ SOL_ON
	#else
		#define SOL_USE_NOEXCEPT_FUNCTION_TYPE_I_ SOL_OFF
	#endif
#else
	#if defined(__cpp_noexcept_function_type)
		#define SOL_USE_NOEXCEPT_FUNCTION_TYPE_I_ SOL_ON
	#elif SOL_IS_ON(SOL_COMPILER_VCXX) && (defined(_MSVC_LANG) && (_MSVC_LANG < 201403L))
		// There is a bug in the VC++ compiler??
		// on /std:c++latest under x86 conditions (VS 15.5.2),
		// compiler errors are tossed for noexcept markings being on function types
		// that are identical in every other way to their non-noexcept marked types function types...
		// VS 2019: There is absolutely a bug.
		#define SOL_USE_NOEXCEPT_FUNCTION_TYPE_I_ SOL_OFF
	#else
		#define SOL_USE_NOEXCEPT_FUNCTION_TYPE_I_ SOL_DEFAULT_ON
	#endif
#endif // noexcept is part of a function's type

#if defined(SOL_STACK_STRING_OPTIMIZATION_SIZE) && (SOL_STACK_STRING_OPTIMIZATION_SIZE > 0)
	#define SOL_OPTIMIZATION_STRING_CONVERSION_STACK_SIZE_I_ SOL_STACK_STRING_OPTIMIZATION_SIZE
#else
	#define SOL_OPTIMIZATION_STRING_CONVERSION_STACK_SIZE_I_ 1024
#endif

#if defined(SOL_ID_SIZE) && (SOL_ID_SIZE > 0)
	#define SOL_ID_SIZE_I_ SOL_ID_SIZE
#else
	#define SOL_ID_SIZE_I_ 512
#endif

#if defined(LUA_IDSIZE) && (LUA_IDSIZE > 0)
	#define SOL_FILE_ID_SIZE_I_ LUA_IDSIZE
#elif defined(SOL_ID_SIZE) && SOL_ID_SIZE > 0
	#define SOL_FILE_ID_SIZE_I_ SOL_FILE_ID_SIZE
#else
	#define SOL_FILE_ID_SIZE_I_ 2048
#endif

#if defined(SOL_PRINT_ERRORS)
	#if (SOL_PRINT_ERRORS != 0)
		#define SOL_PRINT_ERRORS_I_ SOL_ON
	#else
		#define SOL_PRINT_ERRORS_I_ SOL_OFF
	#endif
#else
	#if SOL_IS_ON(SOL_ALL_SAFETIES_ON)
		#define SOL_PRINT_ERRORS_I_ SOL_ON
	#elif SOL_IS_ON(SOL_DEBUG_BUILD)
		#define SOL_PRINT_ERRORS_I_ SOL_DEFAULT_ON
	#else
		#define SOL_PRINT_ERRORS_I_ SOL_OFF
	#endif
#endif

#if defined(SOL_DEFAULT_PASS_ON_ERROR)
	#if (SOL_DEFAULT_PASS_ON_ERROR != 0)
		#define SOL_DEFAULT_PASS_ON_ERROR_I_ SOL_ON
	#else
		#define SOL_DEFAULT_PASS_ON_ERROR_I_ SOL_OFF
	#endif
#else
	#define SOL_DEFAULT_PASS_ON_ERROR_I_ SOL_DEFAULT_OFF
#endif

#if defined(SOL_USING_CXX_LUA)
	#if (SOL_USING_CXX_LUA != 0)
		#define SOL_USING_CXX_LUA_I_ SOL_ON
	#else
		#define SOL_USING_CXX_LUA_I_ SOL_OFF
	#endif
#elif defined(SOL_USE_CXX_LUA)
	// alternative spelling
	#if (SOL_USE_CXX_LUA != 0)
		#define SOL_USING_CXX_LUA_I_ SOL_ON
	#else
		#define SOL_USING_CXX_LUA_I_ SOL_OFF
	#endif
#else
	#define SOL_USING_CXX_LUA_I_ SOL_DEFAULT_OFF
#endif

#if defined(SOL_USING_CXX_LUAJIT)
	#if (SOL_USING_CXX_LUAJIT != 0)
		#define SOL_USING_CXX_LUAJIT_I_ SOL_ON
	#else
		#define SOL_USING_CXX_LUAJIT_I_ SOL_OFF
	#endif
#elif defined(SOL_USE_CXX_LUAJIT)
	#if (SOL_USE_CXX_LUAJIT != 0)
		#define SOL_USING_CXX_LUAJIT_I_ SOL_ON
	#else
		#define SOL_USING_CXX_LUAJIT_I_ SOL_OFF
	#endif
#else
	#define SOL_USING_CXX_LUAJIT_I_ SOL_DEFAULT_OFF
#endif

#if defined(SOL_NO_LUA_HPP)
	#if (SOL_NO_LUA_HPP != 0)
		#define SOL_USE_LUA_HPP_I_ SOL_OFF
	#else
		#define SOL_USE_LUA_HPP_I_ SOL_ON
	#endif
#elif SOL_IS_ON(SOL_USING_CXX_LUA)
	#define SOL_USE_LUA_HPP_I_ SOL_OFF
#elif defined(__has_include)
	#if __has_include(<lua.hpp>)
		#define SOL_USE_LUA_HPP_I_ SOL_ON
	#else
		#define SOL_USE_LUA_HPP_I_ SOL_OFF
	#endif
#else
	#define SOL_USE_LUA_HPP_I_ SOL_DEFAULT_ON
#endif

#if defined(SOL_CONTAINERS_START)
	#define SOL_CONTAINER_START_INDEX_I_ SOL_CONTAINERS_START
#elif defined(SOL_CONTAINERS_START_INDEX)
	#define SOL_CONTAINER_START_INDEX_I_ SOL_CONTAINERS_START_INDEX
#elif defined(SOL_CONTAINER_START_INDEX)
	#define SOL_CONTAINER_START_INDEX_I_ SOL_CONTAINER_START_INDEX
#else
	#define SOL_CONTAINER_START_INDEX_I_ 1
#endif

#if defined (SOL_NO_MEMORY_ALIGNMENT)
	#if (SOL_NO_MEMORY_ALIGNMENT != 0)
		#define SOL_ALIGN_MEMORY_I_ SOL_OFF
	#else
		#define SOL_ALIGN_MEMORY_I_ SOL_ON
	#endif
#else
	#define SOL_ALIGN_MEMORY_I_ SOL_DEFAULT_ON
#endif

#if defined(SOL_USE_BOOST)
	#if (SOL_USE_BOOST != 0)
		#define SOL_USE_BOOST_I_ SOL_ON
	#else
		#define SOL_USE_BOOST_I_ SOL_OFF
	#endif
#else
		#define SOL_USE_BOOST_I_ SOL_DEFAULT_OFF
#endif

#if defined(SOL_USE_UNSAFE_BASE_LOOKUP)
	#if (SOL_USE_UNSAFE_BASE_LOOKUP != 0)
		#define SOL_USE_UNSAFE_BASE_LOOKUP_I_ SOL_ON
	#else
		#define SOL_USE_UNSAFE_BASE_LOOKUP_I_ SOL_OFF
	#endif
#else
	#define SOL_USE_UNSAFE_BASE_LOOKUP_I_ SOL_DEFAULT_OFF
#endif

#if defined(SOL_INSIDE_UNREAL)
	#if (SOL_INSIDE_UNREAL != 0)
		#define SOL_INSIDE_UNREAL_ENGINE_I_ SOL_ON
	#else
		#define SOL_INSIDE_UNREAL_ENGINE_I_ SOL_OFF
	#endif
#else
	#if defined(UE_BUILD_DEBUG) || defined(UE_BUILD_DEVELOPMENT) || defined(UE_BUILD_TEST) || defined(UE_BUILD_SHIPPING) || defined(UE_SERVER)
		#define SOL_INSIDE_UNREAL_ENGINE_I_ SOL_DEFAULT_ON
	#else
		#define SOL_INSIDE_UNREAL_ENGINE_I_ SOL_DEFAULT_OFF
	#endif
#endif

#if defined(SOL_NO_COMPAT)
	#if (SOL_NO_COMPAT != 0)
		#define SOL_USE_COMPATIBILITY_LAYER_I_ SOL_OFF
	#else
		#define SOL_USE_COMPATIBILITY_LAYER_I_ SOL_ON
	#endif
#else
	#define SOL_USE_COMPATIBILITY_LAYER_I_ SOL_DEFAULT_ON
#endif

#if defined(SOL_GET_FUNCTION_POINTER_UNSAFE)
	#if (SOL_GET_FUNCTION_POINTER_UNSAFE != 0)
		#define SOL_GET_FUNCTION_POINTER_UNSAFE_I_ SOL_ON
	#else
		#define SOL_GET_FUNCTION_POINTER_UNSAFE_I_ SOL_OFF
	#endif
#else
	#define SOL_GET_FUNCTION_POINTER_UNSAFE_I_ SOL_DEFAULT_OFF
#endif

#if defined(SOL_CONTAINER_CHECK_IS_EXHAUSTIVE)
	#if (SOL_CONTAINER_CHECK_IS_EXHAUSTIVE != 0)
		#define SOL_CONTAINER_CHECK_IS_EXHAUSTIVE_I_ SOL_ON
	#else
		#define SOL_CONTAINER_CHECK_IS_EXHAUSTIVE_I_ SOL_OFF
	#endif
#else
	#define SOL_CONTAINER_CHECK_IS_EXHAUSTIVE_I_ SOL_DEFAULT_OFF
#endif

#if defined(SOL_FUNCTION_CALL_VALUE_SEMANTICS)
	#if (SOL_FUNCTION_CALL_VALUE_SEMANTICS != 0)
		#define SOL_FUNCTION_CALL_VALUE_SEMANTICS_I_ SOL_ON
	#else
		#define SOL_FUNCTION_CALL_VALUE_SEMANTICS_I_ SOL_OFF
	#endif
#else
	#define SOL_FUNCTION_CALL_VALUE_SEMANTICS_I_ SOL_DEFAULT_OFF
#endif

#if defined(SOL_MINGW_CCTYPE_IS_POISONED)
	#if (SOL_MINGW_CCTYPE_IS_POISONED != 0)
		#define SOL_MINGW_CCTYPE_IS_POISONED_I_ SOL_ON
	#else
		#define SOL_MINGW_CCTYPE_IS_POISONED_I_ SOL_OFF
	#endif
#elif SOL_IS_ON(SOL_COMPILER_MINGW) && defined(__GNUC__) && (__GNUC__ < 6)
	// MinGW is off its rocker in some places...
	#define SOL_MINGW_CCTYPE_IS_POISONED_I_ SOL_DEFAULT_ON
#else
	#define SOL_MINGW_CCTYPE_IS_POISONED_I_ SOL_DEFAULT_OFF
#endif

#if defined(SOL_CHAR8_T)
	#if (SOL_CHAR8_T != 0)
		#define SOL_CHAR8_T_I_ SOL_ON
	#else
		#define SOL_CHAR8_T_I_ SOL_OFF
	#endif
#else
	#if defined(__cpp_char8_t)
		#define SOL_CHAR8_T_I_ SOL_DEFAULT_ON
	#else
		#define SOL_CHAR8_T_I_ SOL_DEFAULT_OFF
	#endif
#endif

#if SOL_IS_ON(SOL_USE_BOOST)
	#include <boost/version.hpp>

	#if BOOST_VERSION >= 107500 // Since Boost 1.75.0 boost::none is constexpr
		#define SOL_BOOST_NONE_CONSTEXPR_I_ constexpr
	#else
		#define SOL_BOOST_NONE_CONSTEXPR_I_ const
	#endif // BOOST_VERSION
#else
	// assume boost isn't using a garbage version
	#define SOL_BOOST_NONE_CONSTEXPR_I_ constexpr
#endif

#if defined(SOL2_CI)
	#if (SOL2_CI != 0)
		#define SOL2_CI_I_ SOL_ON
	#else
		#define SOL2_CI_I_ SOL_OFF
	#endif
#else
	#define SOL2_CI_I_ SOL_DEFAULT_OFF
#endif

#if defined(SOL_ASSERT)
	#define SOL_USER_ASSERT_I_ SOL_ON
#else
	#define SOL_USER_ASSERT_I_ SOL_DEFAULT_OFF
#endif

#if defined(SOL_ASSERT_MSG)
	#define SOL_USER_ASSERT_MSG_I_ SOL_ON
#else
	#define SOL_USER_ASSERT_MSG_I_ SOL_DEFAULT_OFF
#endif

#include <sol/prologue.hpp>
#include <sol/epilogue.hpp>

// clang-format on

#include <sol/detail/build_version.hpp>

#endif // SOL_VERSION_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_FORWARD_HPP
#define SOL_FORWARD_HPP

#include <sol/version.hpp>

#include <utility>
#include <type_traits>
#include <string_view>

#if SOL_IS_ON(SOL_USING_CXX_LUA) || SOL_IS_ON(SOL_USING_CXX_LUAJIT)
struct lua_State;
#else
extern "C" {
struct lua_State;
}
#endif // C++ Mangling for Lua vs. Not

namespace sol {

	enum class type;

	class stateless_reference;
	template <bool b>
	class basic_reference;
	using reference = basic_reference<false>;
	using main_reference = basic_reference<true>;
	class stateless_stack_reference;
	class stack_reference;

	template <typename A>
	class basic_bytecode;

	struct lua_value;

	struct proxy_base_tag;
	template <typename>
	struct proxy_base;
	template <typename, typename>
	struct table_proxy;

	template <bool, typename>
	class basic_table_core;
	template <bool b>
	using table_core = basic_table_core<b, reference>;
	template <bool b>
	using main_table_core = basic_table_core<b, main_reference>;
	template <bool b>
	using stack_table_core = basic_table_core<b, stack_reference>;
	template <typename base_type>
	using basic_table = basic_table_core<false, base_type>;
	using table = table_core<false>;
	using global_table = table_core<true>;
	using main_table = main_table_core<false>;
	using main_global_table = main_table_core<true>;
	using stack_table = stack_table_core<false>;
	using stack_global_table = stack_table_core<true>;

	template <typename>
	struct basic_lua_table;
	using lua_table = basic_lua_table<reference>;
	using stack_lua_table = basic_lua_table<stack_reference>;

	template <typename T, typename base_type>
	class basic_usertype;
	template <typename T>
	using usertype = basic_usertype<T, reference>;
	template <typename T>
	using stack_usertype = basic_usertype<T, stack_reference>;

	template <typename base_type>
	class basic_metatable;
	using metatable = basic_metatable<reference>;
	using stack_metatable = basic_metatable<stack_reference>;

	template <typename base_t>
	struct basic_environment;
	using environment = basic_environment<reference>;
	using main_environment = basic_environment<main_reference>;
	using stack_environment = basic_environment<stack_reference>;

	template <typename T, bool>
	class basic_function;
	template <typename T, bool, typename H>
	class basic_protected_function;
	using unsafe_function = basic_function<reference, false>;
	using safe_function = basic_protected_function<reference, false, reference>;
	using main_unsafe_function = basic_function<main_reference, false>;
	using main_safe_function = basic_protected_function<main_reference, false, reference>;
	using stack_unsafe_function = basic_function<stack_reference, false>;
	using stack_safe_function = basic_protected_function<stack_reference, false, reference>;
	using stack_aligned_unsafe_function = basic_function<stack_reference, true>;
	using stack_aligned_safe_function = basic_protected_function<stack_reference, true, reference>;
	using protected_function = safe_function;
	using main_protected_function = main_safe_function;
	using stack_protected_function = stack_safe_function;
	using stack_aligned_protected_function = stack_aligned_safe_function;
#if SOL_IS_ON(SOL_SAFE_FUNCTION_OBJECTS)
	using function = protected_function;
	using main_function = main_protected_function;
	using stack_function = stack_protected_function;
	using stack_aligned_function = stack_aligned_safe_function;
#else
	using function = unsafe_function;
	using main_function = main_unsafe_function;
	using stack_function = stack_unsafe_function;
	using stack_aligned_function = stack_aligned_unsafe_function;
#endif
	using stack_aligned_stack_handler_function = basic_protected_function<stack_reference, true, stack_reference>;

	struct unsafe_function_result;
	struct protected_function_result;
	using safe_function_result = protected_function_result;
#if SOL_IS_ON(SOL_SAFE_FUNCTION_OBJECTS)
	using function_result = safe_function_result;
#else
	using function_result = unsafe_function_result;
#endif

	template <typename base_t>
	class basic_object_base;
	template <typename base_t>
	class basic_object;
	template <typename base_t>
	class basic_userdata;
	template <typename base_t>
	class basic_lightuserdata;
	template <typename base_t>
	class basic_coroutine;
	template <typename base_t>
	class basic_packaged_coroutine;
	template <typename base_t>
	class basic_thread;

	using object = basic_object<reference>;
	using userdata = basic_userdata<reference>;
	using lightuserdata = basic_lightuserdata<reference>;
	using thread = basic_thread<reference>;
	using coroutine = basic_coroutine<reference>;
	using packaged_coroutine = basic_packaged_coroutine<reference>;
	using main_object = basic_object<main_reference>;
	using main_userdata = basic_userdata<main_reference>;
	using main_lightuserdata = basic_lightuserdata<main_reference>;
	using main_coroutine = basic_coroutine<main_reference>;
	using stack_object = basic_object<stack_reference>;
	using stack_userdata = basic_userdata<stack_reference>;
	using stack_lightuserdata = basic_lightuserdata<stack_reference>;
	using stack_thread = basic_thread<stack_reference>;
	using stack_coroutine = basic_coroutine<stack_reference>;

	struct stack_proxy_base;
	struct stack_proxy;
	struct variadic_args;
	struct variadic_results;
	struct stack_count;
	struct this_state;
	struct this_main_state;
	struct this_environment;

	class state_view;
	class state;

	template <typename T>
	struct as_table_t;
	template <typename T>
	struct as_container_t;
	template <typename T>
	struct nested;
	template <typename T>
	struct light;
	template <typename T>
	struct user;
	template <typename T>
	struct as_args_t;
	template <typename T>
	struct protect_t;
	template <typename F, typename... Policies>
	struct policy_wrapper;

	template <typename T>
	struct usertype_traits;
	template <typename T>
	struct unique_usertype_traits;

	template <typename... Args>
	struct types {
		typedef std::make_index_sequence<sizeof...(Args)> indices;
		static constexpr std::size_t size() {
			return sizeof...(Args);
		}
	};

	template <typename T>
	struct derive : std::false_type {
		typedef types<> type;
	};

	template <typename T>
	struct base : std::false_type {
		typedef types<> type;
	};

	template <typename T>
	struct weak_derive {
		static bool value;
	};

	template <typename T>
	bool weak_derive<T>::value = false;

	namespace stack {
		struct record;
	}

#if SOL_IS_OFF(SOL_USE_BOOST)
	template <class T>
	class optional;

	template <class T>
	class optional<T&>;
#endif

	using check_handler_type = int(lua_State*, int, type, type, const char*);

} // namespace sol

#define SOL_BASE_CLASSES(T, ...)                       \
	namespace sol {                                   \
		template <>                                  \
		struct base<T> : std::true_type {            \
			typedef ::sol::types<__VA_ARGS__> type; \
		};                                           \
	}                                                 \
	static_assert(true, "")
#define SOL_DERIVED_CLASSES(T, ...)                    \
	namespace sol {                                   \
		template <>                                  \
		struct derive<T> : std::true_type {          \
			typedef ::sol::types<__VA_ARGS__> type; \
		};                                           \
	}                                                 \
	static_assert(true, "")

#endif // SOL_FORWARD_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_FORWARD_DETAIL_HPP
#define SOL_FORWARD_DETAIL_HPP

#include <sol/version.hpp>

#include <sol/forward.hpp>
#include <sol/traits.hpp>

namespace sol {
	namespace detail {
		const bool default_safe_function_calls =
#if SOL_IS_ON(SOL_SAFE_FUNCTION_CALLS)
		     true;
#else
		     false;
#endif
	} // namespace detail


	namespace meta { namespace meta_detail {
	}} // namespace meta::meta_detail

	namespace stack { namespace stack_detail {
		using undefined_method_func = void (*)(stack_reference);

		template <typename T>
		void set_undefined_methods_on(stack_reference);

		struct undefined_metatable;
	}} // namespace stack::stack_detail
} // namespace sol

#endif // SOL_FORWARD_DETAIL_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#pragma once

#ifndef SOL_ASSERT_HPP
#define SOL_ASSERT_HPP

#include <sol/forward.hpp>

#if SOL_IS_ON(SOL2_CI)

struct pre_main {
	pre_main() {
#ifdef _MSC_VER
		_set_abort_behavior(0, _WRITE_ABORT_MSG);
#endif
	}
} inline sol2_ci_dont_lock_ci_please = {};

#endif // Prevent lockup when doing Continuous Integration


// clang-format off

#if SOL_IS_ON(SOL_USER_ASSERT)
	#define SOL_ASSERT(...) SOL_C_ASSERT(__VA_ARGS__)
#else
	#if SOL_IS_ON(SOL_DEBUG_BUILD)
		#include <exception>
		#include <iostream>
		#include <cstdlib>

			#define SOL_ASSERT(...)                                                                                               \
				do {                                                                                                               \
					if (!(__VA_ARGS__)) {                                                                                           \
						std::cerr << "Assertion `" #__VA_ARGS__ "` failed in " << __FILE__ << " line " << __LINE__ << std::endl; \
						std::terminate();                                                                                        \
					}                                                                                                             \
				} while (false)
	#else
		#define SOL_ASSERT(...)           \
			do {                           \
				if (false) {              \
					(void)(__VA_ARGS__); \
				}                         \
			} while (false)
	#endif
#endif

#if SOL_IS_ON(SOL_USER_ASSERT_MSG)
	#define SOL_ASSERT_MSG(message, ...) SOL_ASSERT_MSG(message, __VA_ARGS__)
#else
	#if SOL_IS_ON(SOL_DEBUG_BUILD)
		#include <exception>
		#include <iostream>
		#include <cstdlib>

		#define SOL_ASSERT_MSG(message, ...)                                                                                                         \
			do {                                                                                                                                  \
				if (!(__VA_ARGS__)) {                                                                                                              \
					std::cerr << "Assertion `" #__VA_ARGS__ "` failed in " << __FILE__ << " line " << __LINE__ << ": " << message << std::endl; \
					std::terminate();                                                                                                           \
				}                                                                                                                                \
			} while (false)
	#else
		#define SOL_ASSERT_MSG(message, ...)    \
			do {                             \
				if (false) {                \
					(void)(__VA_ARGS__);   \
					(void)sizeof(message); \
				}                           \
			} while (false)
	#endif
#endif

// clang-format on

#endif // SOL_ASSERT_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_BYTECODE_HPP
#define SOL_BYTECODE_HPP

#include <sol/compatibility.hpp>
#include <sol/string_view.hpp>
#include <vector>
#include <cstdint>
#include <cstddef>

namespace sol {

	template <typename Allocator = std::allocator<std::byte>>
	class basic_bytecode : private std::vector<std::byte, Allocator> {
	private:
		using base_t = std::vector<std::byte, Allocator>;

	public:
		using typename base_t::allocator_type;
		using typename base_t::const_iterator;
		using typename base_t::const_pointer;
		using typename base_t::const_reference;
		using typename base_t::const_reverse_iterator;
		using typename base_t::difference_type;
		using typename base_t::iterator;
		using typename base_t::pointer;
		using typename base_t::reference;
		using typename base_t::reverse_iterator;
		using typename base_t::size_type;
		using typename base_t::value_type;

		using base_t::base_t;
		using base_t::operator=;

		using base_t::data;
		using base_t::empty;
		using base_t::max_size;
		using base_t::size;

		using base_t::at;
		using base_t::operator[];
		using base_t::back;
		using base_t::front;

		using base_t::begin;
		using base_t::cbegin;
		using base_t::cend;
		using base_t::end;

		using base_t::crbegin;
		using base_t::crend;
		using base_t::rbegin;
		using base_t::rend;


		using base_t::get_allocator;
		using base_t::swap;

		using base_t::clear;
		using base_t::emplace;
		using base_t::emplace_back;
		using base_t::erase;
		using base_t::insert;
		using base_t::pop_back;
		using base_t::push_back;
		using base_t::reserve;
		using base_t::resize;
		using base_t::shrink_to_fit;

		string_view as_string_view() const {
			return string_view(reinterpret_cast<const char*>(this->data()), this->size());
		}
	};

	template <typename Container>
	inline int basic_insert_dump_writer(lua_State*, const void* memory, size_t memory_size, void* userdata_pointer) {
		using storage_t = Container;
		const std::byte* p_code = static_cast<const std::byte*>(memory);
		storage_t& bc = *static_cast<storage_t*>(userdata_pointer);
#if SOL_IS_OFF(SOL_EXCEPTIONS)
		bc.insert(bc.cend(), p_code, p_code + memory_size);
#else
		try {
			bc.insert(bc.cend(), p_code, p_code + memory_size);
		}
		catch (...) {
			return -1;
		}
#endif
		return 0;
	}

	using bytecode = basic_bytecode<>;

	constexpr inline auto bytecode_dump_writer = &basic_insert_dump_writer<bytecode>;

} // namespace sol

#endif // SOL_BYTECODE_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_TRAMPOLINE_HPP
#define SOL_TRAMPOLINE_HPP

#include <sol/types.hpp>
#include <sol/traits.hpp>
#include <exception>
#include <cstring>

#if SOL_IS_ON(SOL_PRINT_ERRORS)
#include <iostream>
#endif

namespace sol {
	// must push a single object to be the error object
	// NOTE: the VAST MAJORITY of all Lua libraries -- C or otherwise -- expect a string for the type of error
	// break this convention at your own risk
	using exception_handler_function = int (*)(lua_State*, optional<const std::exception&>, string_view);

	namespace detail {
		inline const char (&default_exception_handler_name())[11] {
			static const char name[11] = "sol.\xE2\x98\xA2\xE2\x98\xA2";
			return name;
		}

		// must push at least 1 object on the stack
		inline int default_exception_handler(lua_State* L, optional<const std::exception&>, string_view what) {
#if SOL_IS_ON(SOL_PRINT_ERRORS)
			std::cerr << "[sol2] An exception occurred: ";
			std::cerr.write(what.data(), static_cast<std::streamsize>(what.size()));
			std::cerr << std::endl;
#endif
			lua_pushlstring(L, what.data(), what.size());
			return 1;
		}

		inline int call_exception_handler(lua_State* L, optional<const std::exception&> maybe_ex, string_view what) {
			lua_getglobal(L, default_exception_handler_name());
			type t = static_cast<type>(lua_type(L, -1));
			if (t != type::lightuserdata) {
				lua_pop(L, 1);
				return default_exception_handler(L, std::move(maybe_ex), std::move(what));
			}
			void* vfunc = lua_touserdata(L, -1);
			lua_pop(L, 1);
			if (vfunc == nullptr) {
				return default_exception_handler(L, std::move(maybe_ex), std::move(what));
			}
			exception_handler_function exfunc = reinterpret_cast<exception_handler_function>(vfunc);
			return exfunc(L, std::move(maybe_ex), std::move(what));
		}

#if SOL_IS_OFF(SOL_EXCEPTIONS)
		template <lua_CFunction f>
		int static_trampoline(lua_State* L) noexcept {
			return f(L);
		}

#if SOL_IS_ON(SOL_USE_NOEXCEPT_FUNCTION_TYPE)
		template <lua_CFunction_noexcept f>
		int static_trampoline_noexcept(lua_State* L) noexcept {
			return f(L);
		}
#else
		template <lua_CFunction f>
		int static_trampoline_noexcept(lua_State* L) noexcept {
			return f(L);
		}
#endif

		template <typename Fx, typename... Args>
		int trampoline(lua_State* L, Fx&& f, Args&&... args) noexcept {
			return f(L, std::forward<Args>(args)...);
		}

		inline int c_trampoline(lua_State* L, lua_CFunction f) noexcept {
			return trampoline(L, f);
		}
#else

		inline int lua_cfunction_trampoline(lua_State* L, lua_CFunction f) {
#if SOL_IS_ON(SOL_PROPAGATE_EXCEPTIONS)
			return f(L);
#else
			try {
				return f(L);
			}
			catch (const char* cs) {
				call_exception_handler(L, optional<const std::exception&>(nullopt), string_view(cs));
			}
			catch (const std::string& s) {
				call_exception_handler(L, optional<const std::exception&>(nullopt), string_view(s.c_str(), s.size()));
			}
			catch (const std::exception& e) {
				call_exception_handler(L, optional<const std::exception&>(e), e.what());
			}
#if SOL_IS_ON(SOL_EXCEPTIONS_CATCH_ALL)
			// LuaJIT cannot have the catchall when the safe propagation is on
			// but LuaJIT will swallow all C++ errors
			// if we don't at least catch std::exception ones
			catch (...) {
				call_exception_handler(L, optional<const std::exception&>(nullopt), "caught (...) exception");
			}
#endif
			return lua_error(L);
#endif // Safe exceptions
		}

		template <lua_CFunction f>
		int static_trampoline(lua_State* L) {
			return lua_cfunction_trampoline(L, f);
		}

#if SOL_IS_ON(SOL_USE_NOEXCEPT_FUNCTION_TYPE)
		template <lua_CFunction_noexcept f>
		int static_trampoline_noexcept(lua_State* L) noexcept {
			return f(L);
		}
#else
		template <lua_CFunction f>
		int static_trampoline_noexcept(lua_State* L) noexcept {
			return f(L);
		}
#endif

		template <typename Fx, typename... Args>
		int trampoline(lua_State* L, Fx&& f, Args&&... args) {
			if constexpr (meta::bind_traits<meta::unqualified_t<Fx>>::is_noexcept) {
				return f(L, std::forward<Args>(args)...);
			}
			else {
#if SOL_IS_ON(SOL_PROPAGATE_EXCEPTIONS)
				return f(L, std::forward<Args>(args)...);
#else
				try {
					return f(L, std::forward<Args>(args)...);
				}
				catch (const char* cs) {
					call_exception_handler(L, optional<const std::exception&>(nullopt), string_view(cs));
				}
				catch (const std::string& s) {
					call_exception_handler(L, optional<const std::exception&>(nullopt), string_view(s.c_str(), s.size()));
				}
				catch (const std::exception& e) {
					call_exception_handler(L, optional<const std::exception&>(e), e.what());
				}
#if SOL_IS_ON(SOL_EXCEPTIONS_CATCH_ALL)
				// LuaJIT cannot have the catchall when the safe propagation is on
				// but LuaJIT will swallow all C++ errors
				// if we don't at least catch std::exception ones
				catch (...) {
					call_exception_handler(L, optional<const std::exception&>(nullopt), "caught (...) exception");
				}
#endif
				return lua_error(L);
#endif
			}
		}

		inline int c_trampoline(lua_State* L, lua_CFunction f) {
			return trampoline(L, f);
		}
#endif // Exceptions vs. No Exceptions

		template <typename F, F fx>
		inline int typed_static_trampoline(lua_State* L) {
#if 0
			// NOTE: you must evaluate the get/check_get of every
			// argument, to ensure it doesn't throw
			// (e.g., for the sol_lua_check_access extension point!)
			// This incluudes properly noexcept-ing all the above
			// trampolines / safety nets
			// This is currently not done properly because it's an enormous pain in the ass to attempt to accomplish.
			if constexpr (meta::bind_traits<F>::is_noexcept) {
				return static_trampoline_noexcept<fx>(L);
			}
			else
#endif
			{ return static_trampoline<fx>(L); }
		}
	} // namespace detail

	inline void set_default_exception_handler(lua_State* L, exception_handler_function exf = &detail::default_exception_handler) {
		static_assert(sizeof(void*) >= sizeof(exception_handler_function),
		     "void* storage is too small to transport the exception handler: please file a bug on the sol2 issue tracker to get this looked at!");
		void* storage;
		std::memcpy(&storage, &exf, sizeof(exception_handler_function));
		lua_pushlightuserdata(L, storage);
		lua_setglobal(L, detail::default_exception_handler_name());
	}
} // namespace sol

#endif // SOL_TRAMPOLINE_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_STACK_CORE_HPP
#define SOL_STACK_CORE_HPP

#include <sol/types.hpp>
#include <sol/inheritance.hpp>
#include <sol/error_handler.hpp>
#include <sol/reference.hpp>
#include <sol/stack_reference.hpp>
#include <sol/tuple.hpp>
#include <sol/traits.hpp>
#include <sol/tie.hpp>
#include <sol/stack_guard.hpp>
#include <sol/demangle.hpp>
#include <sol/forward_detail.hpp>

#include <vector>
#include <bitset>
#include <forward_list>
#include <string>
#include <limits>
#include <algorithm>
#include <sstream>
#include <optional>
#include <type_traits>

namespace sol {
	namespace detail {
		struct with_function_tag { };
		struct as_reference_tag { };
		template <typename T>
		struct as_pointer_tag { };
		template <typename T>
		struct as_value_tag { };
		template <typename T>
		struct as_unique_tag { };
		template <typename T>
		struct as_table_tag { };

		template <typename Tag>
		inline constexpr bool is_tagged_v
		     = meta::is_specialization_of_v<Tag,
		            detail::
		                 as_pointer_tag> || meta::is_specialization_of_v<Tag, as_value_tag> || meta::is_specialization_of_v<Tag, as_unique_tag> || meta::is_specialization_of_v<Tag, as_table_tag> || std::is_same_v<Tag, as_reference_tag> || std::is_same_v<Tag, with_function_tag>;

		using lua_reg_table = luaL_Reg[64];

		using unique_destructor = void (*)(void*);
		using unique_tag = detail::inheritance_unique_cast_function;

		inline void* alloc_newuserdata(lua_State* L, std::size_t bytesize) {
#if SOL_LUA_VERSION_I_ >= 504
			return lua_newuserdatauv(L, bytesize, 1);
#else
			return lua_newuserdata(L, bytesize);
#endif
		}

		constexpr std::uintptr_t align(std::size_t alignment, std::uintptr_t ptr, std::size_t& space) {
			// this handles arbitrary alignments...
			// make this into a power-of-2-only?
			// actually can't: this is a C++14-compatible framework,
			// power of 2 alignment is C++17
			std::uintptr_t offby = static_cast<std::uintptr_t>(ptr % alignment);
			std::uintptr_t padding = (alignment - offby) % alignment;
			ptr += padding;
			space -= padding;
			return ptr;
		}

		inline void* align(std::size_t alignment, void* ptr, std::size_t& space) {
			return reinterpret_cast<void*>(align(alignment, reinterpret_cast<std::uintptr_t>(ptr), space));
		}

		constexpr std::uintptr_t align_one(std::size_t alignment, std::size_t size, std::uintptr_t ptr) {
			std::size_t space = (std::numeric_limits<std::size_t>::max)();
			return align(alignment, ptr, space) + size;
		}

		template <typename... Args>
		constexpr std::size_t aligned_space_for(std::uintptr_t ptr) {
			std::uintptr_t end = ptr;
			((end = align_one(alignof(Args), sizeof(Args), end)), ...);
			return static_cast<std::size_t>(end - ptr);
		}

		template <typename... Args>
		constexpr std::size_t aligned_space_for() {
			static_assert(sizeof...(Args) > 0);

			constexpr std::size_t max_arg_alignment = (std::max)({ alignof(Args)... });
			if constexpr (max_arg_alignment <= alignof(std::max_align_t)) {
				// If all types are `good enough`, simply calculate alignment in case of the worst allocator
				std::size_t worst_required_size = 0;
				for (std::size_t ptr = 0; ptr < max_arg_alignment; ptr++) {
					worst_required_size = (std::max)(worst_required_size, aligned_space_for<Args...>(ptr));
				}
				return worst_required_size;
			}
			else {
				// For over-aligned types let's assume that every Arg in Args starts at the worst aligned address
				return (aligned_space_for<Args>(0x1) + ...);
			}
		}

		inline void* align_usertype_pointer(void* ptr) {
			using use_align = std::integral_constant<bool,
#if SOL_IS_OFF(SOL_ALIGN_MEMORY)
			     false
#else
			     (std::alignment_of<void*>::value > 1)
#endif
			     >;
			if (!use_align::value) {
				return ptr;
			}
			std::size_t space = (std::numeric_limits<std::size_t>::max)();
			return align(std::alignment_of<void*>::value, ptr, space);
		}

		template <bool pre_aligned = false, bool pre_shifted = false>
		void* align_usertype_unique_destructor(void* ptr) {
			using use_align = std::integral_constant<bool,
#if SOL_IS_OFF(SOL_ALIGN_MEMORY)
			     false
#else
			     (std::alignment_of<unique_destructor>::value > 1)
#endif
			     >;
			if (!pre_aligned) {
				ptr = align_usertype_pointer(ptr);
			}
			if (!pre_shifted) {
				ptr = static_cast<void*>(static_cast<char*>(ptr) + sizeof(void*));
			}
			if (!use_align::value) {
				return static_cast<void*>(static_cast<void**>(ptr) + 1);
			}
			std::size_t space = (std::numeric_limits<std::size_t>::max)();
			return align(std::alignment_of<unique_destructor>::value, ptr, space);
		}

		template <bool pre_aligned = false, bool pre_shifted = false>
		void* align_usertype_unique_tag(void* ptr) {
			using use_align = std::integral_constant<bool,
#if SOL_IS_OFF(SOL_ALIGN_MEMORY)
			     false
#else
			     (std::alignment_of<unique_tag>::value > 1)
#endif
			     >;
			if (!pre_aligned) {
				ptr = align_usertype_unique_destructor(ptr);
			}
			if (!pre_shifted) {
				ptr = static_cast<void*>(static_cast<char*>(ptr) + sizeof(unique_destructor));
			}
			if (!use_align::value) {
				return ptr;
			}
			std::size_t space = (std::numeric_limits<std::size_t>::max)();
			return align(std::alignment_of<unique_tag>::value, ptr, space);
		}

		template <typename T, bool pre_aligned = false, bool pre_shifted = false>
		void* align_usertype_unique(void* ptr) {
			typedef std::integral_constant<bool,
#if SOL_IS_OFF(SOL_ALIGN_MEMORY)
			     false
#else
			     (std::alignment_of_v<T> > 1)
#endif
			     >
			     use_align;
			if (!pre_aligned) {
				ptr = align_usertype_unique_tag(ptr);
			}
			if (!pre_shifted) {
				ptr = static_cast<void*>(static_cast<char*>(ptr) + sizeof(unique_tag));
			}
			if (!use_align::value) {
				return ptr;
			}
			std::size_t space = (std::numeric_limits<std::size_t>::max)();
			return align(std::alignment_of_v<T>, ptr, space);
		}

		template <typename T>
		void* align_user(void* ptr) {
			typedef std::integral_constant<bool,
#if SOL_IS_OFF(SOL_ALIGN_MEMORY)
			     false
#else
			     (std::alignment_of_v<T> > 1)
#endif
			     >
			     use_align;
			if (!use_align::value) {
				return ptr;
			}
			std::size_t space = (std::numeric_limits<std::size_t>::max)();
			return align(std::alignment_of_v<T>, ptr, space);
		}

		template <typename T>
		T** usertype_allocate_pointer(lua_State* L) {
			typedef std::integral_constant<bool,
#if SOL_IS_OFF(SOL_ALIGN_MEMORY)
			     false
#else
			     (std::alignment_of<T*>::value > 1)
#endif
			     >
			     use_align;
			if (!use_align::value) {
				T** pointerpointer = static_cast<T**>(alloc_newuserdata(L, sizeof(T*)));
				return pointerpointer;
			}
			constexpr std::size_t initial_size = aligned_space_for<T*>();

			std::size_t allocated_size = initial_size;
			void* unadjusted = alloc_newuserdata(L, initial_size);
			void* adjusted = align(std::alignment_of<T*>::value, unadjusted, allocated_size);
			if (adjusted == nullptr) {
				// trash allocator can burn in hell
				lua_pop(L, 1);
				// luaL_error(L, "if you are the one that wrote this allocator you should feel bad for doing a
				// worse job than malloc/realloc and should go read some books, yeah?");
				luaL_error(L, "cannot properly align memory for '%s'", detail::demangle<T*>().data());
			}
			return static_cast<T**>(adjusted);
		}

		inline bool attempt_alloc(lua_State* L, std::size_t ptr_align, std::size_t ptr_size, std::size_t value_align,
		     std::size_t allocated_size, void*& pointer_adjusted, void*& data_adjusted) {
			void* adjusted = alloc_newuserdata(L, allocated_size);
			pointer_adjusted = align(ptr_align, adjusted, allocated_size);
			if (pointer_adjusted == nullptr) {
				lua_pop(L, 1);
				return false;
			}
			// subtract size of what we're going to allocate there
			allocated_size -= ptr_size;
			adjusted = static_cast<void*>(static_cast<char*>(pointer_adjusted) + ptr_size);
			data_adjusted = align(value_align, adjusted, allocated_size);
			if (data_adjusted == nullptr) {
				lua_pop(L, 1);
				return false;
			}
			return true;
		}

		inline bool attempt_alloc_unique(lua_State* L, std::size_t ptr_align, std::size_t ptr_size, std::size_t real_align,
		     std::size_t allocated_size, void*& pointer_adjusted, void*& dx_adjusted, void*& id_adjusted, void*& data_adjusted) {
			void* adjusted = alloc_newuserdata(L, allocated_size);
			pointer_adjusted = align(ptr_align, adjusted, allocated_size);
			if (pointer_adjusted == nullptr) {
				lua_pop(L, 1);
				return false;
			}
			allocated_size -= ptr_size;

			adjusted = static_cast<void*>(static_cast<char*>(pointer_adjusted) + ptr_size);
			dx_adjusted = align(std::alignment_of_v<unique_destructor>, adjusted, allocated_size);
			if (dx_adjusted == nullptr) {
				lua_pop(L, 1);
				return false;
			}
			allocated_size -= sizeof(unique_destructor);

			adjusted = static_cast<void*>(static_cast<char*>(dx_adjusted) + sizeof(unique_destructor));

			id_adjusted = align(std::alignment_of_v<unique_tag>, adjusted, allocated_size);
			if (id_adjusted == nullptr) {
				lua_pop(L, 1);
				return false;
			}
			allocated_size -= sizeof(unique_tag);

			adjusted = static_cast<void*>(static_cast<char*>(id_adjusted) + sizeof(unique_tag));
			data_adjusted = align(real_align, adjusted, allocated_size);
			if (data_adjusted == nullptr) {
				lua_pop(L, 1);
				return false;
			}
			return true;
		}

		template <typename T>
		T* usertype_allocate(lua_State* L) {
			typedef std::integral_constant<bool,
#if SOL_IS_OFF(SOL_ALIGN_MEMORY)
			     false
#else
			     (std::alignment_of<T*>::value > 1 || std::alignment_of_v<T> > 1)
#endif
			     >
			     use_align;
			if (!use_align::value) {
				T** pointerpointer = static_cast<T**>(alloc_newuserdata(L, sizeof(T*) + sizeof(T)));
				T*& pointerreference = *pointerpointer;
				T* allocationtarget = reinterpret_cast<T*>(pointerpointer + 1);
				pointerreference = allocationtarget;
				return allocationtarget;
			}

			constexpr std::size_t initial_size = aligned_space_for<T*, T>();

			void* pointer_adjusted;
			void* data_adjusted;
			bool result
			     = attempt_alloc(L, std::alignment_of_v<T*>, sizeof(T*), std::alignment_of_v<T>, initial_size, pointer_adjusted, data_adjusted);
			if (!result) {
				if (pointer_adjusted == nullptr) {
					luaL_error(L, "aligned allocation of userdata block (pointer section) for '%s' failed", detail::demangle<T>().c_str());
				}
				else {
					luaL_error(L, "aligned allocation of userdata block (data section) for '%s' failed", detail::demangle<T>().c_str());
				}
				return nullptr;
			}

			T** pointerpointer = reinterpret_cast<T**>(pointer_adjusted);
			T*& pointerreference = *pointerpointer;
			T* allocationtarget = reinterpret_cast<T*>(data_adjusted);
			pointerreference = allocationtarget;
			return allocationtarget;
		}

		template <typename T, typename Real>
		Real* usertype_unique_allocate(lua_State* L, T**& pref, unique_destructor*& dx, unique_tag*& id) {
			typedef std::integral_constant<bool,
#if SOL_IS_OFF(SOL_ALIGN_MEMORY)
			     false
#else
			     (std::alignment_of<T*>::value > 1 || std::alignment_of<unique_tag>::value > 1 || std::alignment_of<unique_destructor>::value > 1
			          || std::alignment_of<Real>::value > 1)
#endif
			     >
			     use_align;
			if (!use_align::value) {
				pref = static_cast<T**>(alloc_newuserdata(L, sizeof(T*) + sizeof(detail::unique_destructor) + sizeof(unique_tag) + sizeof(Real)));
				dx = static_cast<detail::unique_destructor*>(static_cast<void*>(pref + 1));
				id = static_cast<unique_tag*>(static_cast<void*>(dx + 1));
				Real* mem = static_cast<Real*>(static_cast<void*>(id + 1));
				return mem;
			}

			constexpr std::size_t initial_size = aligned_space_for<T*, unique_destructor, unique_tag, Real>();

			void* pointer_adjusted = nullptr;
			void* dx_adjusted = nullptr;
			void* id_adjusted = nullptr;
			void* data_adjusted = nullptr;
			bool result = attempt_alloc_unique(L,
			     std::alignment_of_v<T*>,
			     sizeof(T*),
			     std::alignment_of_v<Real>,
			     initial_size,
			     pointer_adjusted,
			     dx_adjusted,
			     id_adjusted,
			     data_adjusted);
			if (!result) {
				if (pointer_adjusted == nullptr) {
					luaL_error(L, "aligned allocation of userdata block (pointer section) for '%s' failed", detail::demangle<T>().c_str());
				}
				else if (dx_adjusted == nullptr) {
					luaL_error(L, "aligned allocation of userdata block (deleter section) for '%s' failed", detail::demangle<T>().c_str());
				}
				else {
					luaL_error(L, "aligned allocation of userdata block (data section) for '%s' failed", detail::demangle<T>().c_str());
				}
				return nullptr;
			}

			pref = static_cast<T**>(pointer_adjusted);
			dx = static_cast<detail::unique_destructor*>(dx_adjusted);
			id = static_cast<unique_tag*>(id_adjusted);
			Real* mem = static_cast<Real*>(data_adjusted);
			return mem;
		}

		template <typename T>
		T* user_allocate(lua_State* L) {
			typedef std::integral_constant<bool,
#if SOL_IS_OFF(SOL_ALIGN_MEMORY)
			     false
#else
			     (std::alignment_of_v<T> > 1)
#endif
			     >
			     use_align;
			if (!use_align::value) {
				T* pointer = static_cast<T*>(alloc_newuserdata(L, sizeof(T)));
				return pointer;
			}

			constexpr std::size_t initial_size = aligned_space_for<T>();

			std::size_t allocated_size = initial_size;
			void* unadjusted = alloc_newuserdata(L, allocated_size);
			void* adjusted = align(std::alignment_of_v<T>, unadjusted, allocated_size);
			if (adjusted == nullptr) {
				lua_pop(L, 1);
				luaL_error(L, "cannot properly align memory for '%s'", detail::demangle<T>().data());
			}
			return static_cast<T*>(adjusted);
		}

		template <typename T>
		int usertype_alloc_destroy(lua_State* L) noexcept {
			void* memory = lua_touserdata(L, 1);
			memory = align_usertype_pointer(memory);
			T** pdata = static_cast<T**>(memory);
			T* data = *pdata;
			std::allocator<T> alloc {};
			std::allocator_traits<std::allocator<T>>::destroy(alloc, data);
			return 0;
		}

		template <typename T>
		int unique_destroy(lua_State* L) noexcept {
			void* memory = lua_touserdata(L, 1);
			memory = align_usertype_unique_destructor(memory);
			unique_destructor& dx = *static_cast<unique_destructor*>(memory);
			memory = align_usertype_unique_tag<true>(memory);
			(dx)(memory);
			return 0;
		}

		template <typename T>
		int user_alloc_destroy(lua_State* L) noexcept {
			void* memory = lua_touserdata(L, 1);
			void* aligned_memory = align_user<T>(memory);
			T* typed_memory = static_cast<T*>(aligned_memory);
			std::allocator<T> alloc;
			std::allocator_traits<std::allocator<T>>::destroy(alloc, typed_memory);
			return 0;
		}

		template <typename T, typename Real>
		void usertype_unique_alloc_destroy(void* memory) {
			void* aligned_memory = align_usertype_unique<Real, true>(memory);
			Real* typed_memory = static_cast<Real*>(aligned_memory);
			std::allocator<Real> alloc;
			std::allocator_traits<std::allocator<Real>>::destroy(alloc, typed_memory);
		}

		template <typename T>
		int cannot_destroy(lua_State* L) {
			return luaL_error(L,
			     "cannot call the destructor for '%s': it is either hidden (protected/private) or removed with '= "
			     "delete' and thusly this type is being destroyed without properly destroying, invoking undefined "
			     "behavior: please bind a usertype and specify a custom destructor to define the behavior properly",
			     detail::demangle<T>().data());
		}

		template <typename T>
		void reserve(T&, std::size_t) {
		}

		template <typename T, typename Al>
		void reserve(std::vector<T, Al>& vec, std::size_t hint) {
			vec.reserve(hint);
		}

		template <typename T, typename Tr, typename Al>
		void reserve(std::basic_string<T, Tr, Al>& str, std::size_t hint) {
			str.reserve(hint);
		}

		inline bool property_always_true(meta_function) {
			return true;
		}

		struct properties_enrollment_allowed {
			int& times_through;
			std::bitset<64>& properties;
			automagic_enrollments& enrollments;

			properties_enrollment_allowed(int& times_through_, std::bitset<64>& properties_, automagic_enrollments& enrollments_)
			: times_through(times_through_), properties(properties_), enrollments(enrollments_) {
			}

			bool operator()(meta_function mf) const {
				bool p = properties[static_cast<std::size_t>(mf)];
				if (times_through > 0) {
					return p;
				}
				switch (mf) {
				case meta_function::length:
					return enrollments.length_operator && !p;
				case meta_function::pairs:
					return enrollments.pairs_operator && !p;
				case meta_function::call:
					return enrollments.call_operator && !p;
				case meta_function::less_than:
					return enrollments.less_than_operator && !p;
				case meta_function::less_than_or_equal_to:
					return enrollments.less_than_or_equal_to_operator && !p;
				case meta_function::equal_to:
					return enrollments.equal_to_operator && !p;
				default:
					break;
				}
				return !p;
			}
		};

		struct indexed_insert {
			lua_reg_table& registration_table;
			int& index;

			indexed_insert(lua_reg_table& registration_table_, int& index_ref_) : registration_table(registration_table_), index(index_ref_) {
			}
			void operator()(meta_function meta_function_name_, lua_CFunction c_function_) {
				registration_table[index] = luaL_Reg { to_string(meta_function_name_).c_str(), c_function_ };
				++index;
			}
		};
	} // namespace detail

	namespace stack {

		template <typename T, bool global = false, bool raw = false, typename = void>
		struct field_getter;
		template <typename T, typename P, bool global = false, bool raw = false, typename = void>
		struct probe_field_getter;

		template <typename T, bool global = false, bool raw = false, typename = void>
		struct field_setter;

		template <typename T, typename = void>
		struct unqualified_getter;
		template <typename T, typename = void>
		struct qualified_getter;

		template <typename T, typename = void>
		struct qualified_interop_getter;
		template <typename T, typename = void>
		struct unqualified_interop_getter;

		template <typename T, typename = void>
		struct popper;

		template <typename T, typename = void>
		struct unqualified_pusher;

		template <typename T, type t, typename = void>
		struct unqualified_checker;
		template <typename T, type t, typename = void>
		struct qualified_checker;

		template <typename T, typename = void>
		struct unqualified_check_getter;
		template <typename T, typename = void>
		struct qualified_check_getter;

		struct probe {
			bool success;
			int levels;

			probe(bool s, int l) : success(s), levels(l) {
			}

			operator bool() const {
				return success;
			};
		};

		struct record {
			int last;
			int used;

			record() noexcept : last(), used() {
			}
			void use(int count) noexcept {
				last = count;
				used += count;
			}
		};

		namespace stack_detail {
			template <typename Function>
			Function* get_function_pointer(lua_State*, int, record&) noexcept;
			template <typename Function, typename Handler>
			bool check_function_pointer(lua_State* L, int index, Handler&& handler, record& tracking) noexcept;
		} // namespace stack_detail

	} // namespace stack

	namespace meta { namespace meta_detail {
		template <typename T>
		using adl_sol_lua_get_test_t = decltype(sol_lua_get(types<T>(), static_cast<lua_State*>(nullptr), -1, std::declval<stack::record&>()));

		template <typename T>
		using adl_sol_lua_interop_get_test_t
			= decltype(sol_lua_interop_get(types<T>(), static_cast<lua_State*>(nullptr), -1, static_cast<void*>(nullptr), std::declval<stack::record&>()));

		template <typename T>
		using adl_sol_lua_check_test_t = decltype(sol_lua_check(types<T>(), static_cast<lua_State*>(nullptr), -1, &no_panic, std::declval<stack::record&>()));

		template <typename T>
		using adl_sol_lua_interop_check_test_t
			= decltype(sol_lua_interop_check(types<T>(), static_cast<lua_State*>(nullptr), -1, type::none, &no_panic, std::declval<stack::record&>()));

		template <typename T>
		using adl_sol_lua_check_get_test_t
			= decltype(sol_lua_check_get(types<T>(), static_cast<lua_State*>(nullptr), -1, &no_panic, std::declval<stack::record&>()));

		template <typename... Args>
		using adl_sol_lua_push_test_t = decltype(sol_lua_push(static_cast<lua_State*>(nullptr), std::declval<Args>()...));

		template <typename T, typename... Args>
		using adl_sol_lua_push_exact_test_t = decltype(sol_lua_push(types<T>(), static_cast<lua_State*>(nullptr), std::declval<Args>()...));

		template <typename T>
		inline constexpr bool is_adl_sol_lua_get_v = meta::is_detected_v<adl_sol_lua_get_test_t, T>;

		template <typename T>
		inline constexpr bool is_adl_sol_lua_interop_get_v = meta::is_detected_v<adl_sol_lua_interop_get_test_t, T>;

		template <typename T>
		inline constexpr bool is_adl_sol_lua_check_v = meta::is_detected_v<adl_sol_lua_check_test_t, T>;

		template <typename T>
		inline constexpr bool is_adl_sol_lua_interop_check_v = meta::is_detected_v<adl_sol_lua_interop_check_test_t, T>;

		template <typename T>
		inline constexpr bool is_adl_sol_lua_check_get_v = meta::is_detected_v<adl_sol_lua_check_get_test_t, T>;

		template <typename... Args>
		inline constexpr bool is_adl_sol_lua_push_v = meta::is_detected_v<adl_sol_lua_push_test_t, Args...>;

		template <typename T, typename... Args>
		inline constexpr bool is_adl_sol_lua_push_exact_v = meta::is_detected_v<adl_sol_lua_push_exact_test_t, T, Args...>;
	}} // namespace meta::meta_detail


	namespace stack {
		namespace stack_detail {
			constexpr const char* not_enough_stack_space = "not enough space left on Lua stack";
			constexpr const char* not_enough_stack_space_floating = "not enough space left on Lua stack for a floating point number";
			constexpr const char* not_enough_stack_space_integral = "not enough space left on Lua stack for an integral number";
			constexpr const char* not_enough_stack_space_string = "not enough space left on Lua stack for a string";
			constexpr const char* not_enough_stack_space_meta_function_name = "not enough space left on Lua stack for the name of a meta_function";
			constexpr const char* not_enough_stack_space_userdata = "not enough space left on Lua stack to create a sol2 userdata";
			constexpr const char* not_enough_stack_space_generic = "not enough space left on Lua stack to push valuees";
			constexpr const char* not_enough_stack_space_environment = "not enough space left on Lua stack to retrieve environment";

			template <typename T>
			struct strip {
				typedef T type;
			};
			template <typename T>
			struct strip<std::reference_wrapper<T>> {
				typedef T& type;
			};
			template <typename T>
			struct strip<user<T>> {
				typedef T& type;
			};
			template <typename T>
			struct strip<non_null<T>> {
				typedef T type;
			};
			template <typename T>
			using strip_t = typename strip<T>::type;

			template <typename C>
			static int get_size_hint(C& c) {
				return static_cast<int>(c.size());
			}

			template <typename V, typename Al>
			static int get_size_hint(const std::forward_list<V, Al>&) {
				// forward_list makes me sad
				return static_cast<int>(32);
			}

			template <typename T>
			decltype(auto) unchecked_unqualified_get(lua_State* L, int index, record& tracking) {
				using Tu = meta::unqualified_t<T>;
				if constexpr (meta::meta_detail::is_adl_sol_lua_get_v<Tu>) {
					return sol_lua_get(types<Tu>(), L, index, tracking);
				}
				else {
					unqualified_getter<Tu> g {};
					return g.get(L, index, tracking);
				}
			}

			template <typename T>
			decltype(auto) unchecked_get(lua_State* L, int index, record& tracking) {
				if constexpr (meta::meta_detail::is_adl_sol_lua_get_v<T>) {
					return sol_lua_get(types<T>(), L, index, tracking);
				}
				else {
					qualified_getter<T> g {};
					return g.get(L, index, tracking);
				}
			}

			template <typename T>
			decltype(auto) unqualified_interop_get(lua_State* L, int index, void* unadjusted_pointer, record& tracking) {
				using Tu = meta::unqualified_t<T>;
				if constexpr (meta::meta_detail::is_adl_sol_lua_interop_get_v<Tu>) {
					return sol_lua_interop_get(types<Tu>(), L, index, unadjusted_pointer, tracking);
				}
				else {
					(void)L;
					(void)index;
					(void)unadjusted_pointer;
					(void)tracking;
					using Ti = stack_detail::strip_t<Tu>;
					return std::pair<bool, Ti*> { false, nullptr };
				}
			}

			template <typename T>
			decltype(auto) interop_get(lua_State* L, int index, void* unadjusted_pointer, record& tracking) {
				if constexpr (meta::meta_detail::is_adl_sol_lua_interop_get_v<T>) {
					return sol_lua_interop_get(types<T>(), L, index, unadjusted_pointer, tracking);
				}
				else {
					return unqualified_interop_get<T>(L, index, unadjusted_pointer, tracking);
				}
			}

			template <typename T, typename Handler>
			bool unqualified_interop_check(lua_State* L, int index, type index_type, Handler&& handler, record& tracking) {
				using Tu = meta::unqualified_t<T>;
				if constexpr (meta::meta_detail::is_adl_sol_lua_interop_check_v<Tu>) {
					return sol_lua_interop_check(types<Tu>(), L, index, index_type, std::forward<Handler>(handler), tracking);
				}
				else {
					(void)L;
					(void)index;
					(void)index_type;
					(void)handler;
					(void)tracking;
					return false;
				}
			}

			template <typename T, typename Handler>
			bool interop_check(lua_State* L, int index, type index_type, Handler&& handler, record& tracking) {
				if constexpr (meta::meta_detail::is_adl_sol_lua_interop_check_v<T>) {
					return sol_lua_interop_check(types<T>(), L, index, index_type, std::forward<Handler>(handler), tracking);
				}
				else {
					return unqualified_interop_check<T>(L, index, index_type, std::forward<Handler>(handler), tracking);
				}
			}

			using undefined_method_func = void (*)(stack_reference);

			struct undefined_metatable {
				lua_State* L;
				const char* key;
				undefined_method_func on_new_table;

				undefined_metatable(lua_State* l, const char* k, undefined_method_func umf) : L(l), key(k), on_new_table(umf) {
				}

				void operator()() const {
					if (luaL_newmetatable(L, key) == 1) {
						on_new_table(stack_reference(L, -1));
					}
					lua_setmetatable(L, -2);
				}
			};
		} // namespace stack_detail

		inline bool maybe_indexable(lua_State* L, int index = -1) {
			type t = type_of(L, index);
			return t == type::userdata || t == type::table;
		}

		inline int top(lua_State* L) {
			return lua_gettop(L);
		}

		inline bool is_main_thread(lua_State* L) {
			int ismainthread = lua_pushthread(L);
			lua_pop(L, 1);
			return ismainthread == 1;
		}

		inline void coroutine_create_guard(lua_State* L) {
			if (is_main_thread(L)) {
				return;
			}
			int stacksize = lua_gettop(L);
			if (stacksize < 1) {
				return;
			}
			if (type_of(L, 1) != type::function) {
				return;
			}
			// well now we're screwed...
			// we can clean the stack and pray it doesn't destroy anything?
			lua_pop(L, stacksize);
		}

		inline void clear(lua_State* L, int table_index) {
			lua_pushnil(L);
			while (lua_next(L, table_index) != 0) {
				// remove value
				lua_pop(L, 1);
				// duplicate key to protect form rawset
				lua_pushvalue(L, -1);
				// push new value
				lua_pushnil(L);
				// table_index%[key] = nil
				lua_rawset(L, table_index);
			}
		}

		inline void clear(reference& r) {
			auto pp = push_pop<false>(r);
			int stack_index = pp.index_of(r);
			clear(r.lua_state(), stack_index);
		}

		inline void clear(stack_reference& r) {
			clear(r.lua_state(), r.stack_index());
		}

		inline void clear(lua_State* L_, stateless_reference& r) {
			r.push(L_);
			int stack_index = absolute_index(L_, -1);
			clear(L_, stack_index);
			r.pop(L_);
		}

		inline void clear(lua_State* L_, stateless_stack_reference& r) {
			clear(L_, r.stack_index());
		}

		template <typename T, typename... Args>
		int push(lua_State* L, T&& t, Args&&... args) {
			using Tu = meta::unqualified_t<T>;
			if constexpr (meta::meta_detail::is_adl_sol_lua_push_exact_v<T, T, Args...>) {
				return sol_lua_push(types<T>(), L, std::forward<T>(t), std::forward<Args>(args)...);
			}
			else if constexpr (meta::meta_detail::is_adl_sol_lua_push_exact_v<Tu, T, Args...>) {
				return sol_lua_push(types<Tu>(), L, std::forward<T>(t), std::forward<Args>(args)...);
			}
			else if constexpr (meta::meta_detail::is_adl_sol_lua_push_v<T, Args...>) {
				return sol_lua_push(L, std::forward<T>(t), std::forward<Args>(args)...);
			}
			else {
				unqualified_pusher<Tu> p {};
				return p.push(L, std::forward<T>(t), std::forward<Args>(args)...);
			}
		}

		// overload allows to use a pusher of a specific type, but pass in any kind of args
		template <typename T, typename Arg, typename... Args, typename = std::enable_if_t<!std::is_same<T, Arg>::value>>
		int push(lua_State* L, Arg&& arg, Args&&... args) {
			using Tu = meta::unqualified_t<T>;
			if constexpr (meta::meta_detail::is_adl_sol_lua_push_exact_v<T, Arg, Args...>) {
				return sol_lua_push(types<T>(), L, std::forward<Arg>(arg), std::forward<Args>(args)...);
			}
			else if constexpr (meta::meta_detail::is_adl_sol_lua_push_exact_v<Tu, Arg, Args...>) {
				return sol_lua_push(types<Tu>(), L, std::forward<Arg>(arg), std::forward<Args>(args)...);
			}
			else if constexpr (meta::meta_detail::is_adl_sol_lua_push_v<Arg, Args...> && !detail::is_tagged_v<Tu>) {
				return sol_lua_push(L, std::forward<Arg>(arg), std::forward<Args>(args)...);
			}
			else {
				unqualified_pusher<Tu> p {};
				return p.push(L, std::forward<Arg>(arg), std::forward<Args>(args)...);
			}
		}

		template <typename T, typename... Args>
		int push_userdata(lua_State* L, T&& t, Args&&... args) {
			using U = meta::unqualified_t<T>;
			using Tr = meta::conditional_t<std::is_pointer_v<U>,
			     detail::as_pointer_tag<std::remove_pointer_t<U>>,
			     meta::conditional_t<is_unique_usertype_v<U>, detail::as_unique_tag<U>, detail::as_value_tag<U>>>;
			return stack::push<Tr>(L, std::forward<T>(t), std::forward<Args>(args)...);
		}

		template <typename T, typename Arg, typename... Args>
		int push_userdata(lua_State* L, Arg&& arg, Args&&... args) {
			using U = meta::unqualified_t<T>;
			using Tr = meta::conditional_t<std::is_pointer_v<U>,
			     detail::as_pointer_tag<std::remove_pointer_t<U>>,
			     meta::conditional_t<is_unique_usertype_v<U>, detail::as_unique_tag<U>, detail::as_value_tag<U>>>;
			return stack::push<Tr>(L, std::forward<Arg>(arg), std::forward<Args>(args)...);
		}

		namespace stack_detail {

			template <typename T, typename Arg, typename... Args>
			int push_reference(lua_State* L, Arg&& arg, Args&&... args) {
				// clang-format off
				using use_reference_tag =
				meta::all<
					meta::neg<is_value_semantic_for_function<T>>
#if SOL_IS_OFF(SOL_FUNCTION_CALL_VALUE_SEMANTICS)
					, std::is_lvalue_reference<T>,
					meta::neg<std::is_const<std::remove_reference_t<T>>>,
					meta::neg<is_lua_primitive<meta::unqualified_t<T>>>,
					meta::neg<is_unique_usertype<meta::unqualified_t<T>>>
#endif
				>;
				// clang-format on
				using Tr = meta::conditional_t<use_reference_tag::value, detail::as_reference_tag, meta::unqualified_t<T>>;
				return stack::push<Tr>(L, std::forward<Arg>(arg), std::forward<Args>(args)...);
			}

		} // namespace stack_detail

		template <typename T, typename... Args>
		int push_reference(lua_State* L, T&& t, Args&&... args) {
			return stack_detail::push_reference<T>(L, std::forward<T>(t), std::forward<Args>(args)...);
		}

		template <typename T, typename Arg, typename... Args>
		int push_reference(lua_State* L, Arg&& arg, Args&&... args) {
			return stack_detail::push_reference<T>(L, std::forward<Arg>(arg), std::forward<Args>(args)...);
		}

		inline int multi_push(lua_State*) {
			// do nothing
			return 0;
		}

		template <typename T, typename... Args>
		int multi_push(lua_State* L, T&& t, Args&&... args) {
			int pushcount = push(L, std::forward<T>(t));
			void(detail::swallow { (pushcount += stack::push(L, std::forward<Args>(args)), 0)... });
			return pushcount;
		}

		inline int multi_push_reference(lua_State*) {
			// do nothing
			return 0;
		}

		template <typename T, typename... Args>
		int multi_push_reference(lua_State* L, T&& t, Args&&... args) {
			int pushcount = stack::push_reference(L, std::forward<T>(t));
			void(detail::swallow { (pushcount += stack::push_reference(L, std::forward<Args>(args)), 0)... });
			return pushcount;
		}

		template <typename T, typename Handler>
		bool unqualified_check(lua_State* L, int index, Handler&& handler, record& tracking) {
			using Tu = meta::unqualified_t<T>;
			if constexpr (meta::meta_detail::is_adl_sol_lua_check_v<Tu>) {
				return sol_lua_check(types<Tu>(), L, index, std::forward<Handler>(handler), tracking);
			}
			else {
				unqualified_checker<Tu, lua_type_of_v<Tu>> c{};
				return c.check(L, index, std::forward<Handler>(handler), tracking);
			}
		}

		template <typename T, typename Handler>
		bool unqualified_check(lua_State* L, int index, Handler&& handler) {
			record tracking {};
			return unqualified_check<T>(L, index, std::forward<Handler>(handler), tracking);
		}

		template <typename T>
		bool unqualified_check(lua_State* L, int index = -lua_size<meta::unqualified_t<T>>::value) {
			auto handler = &no_panic;
			return unqualified_check<T>(L, index, handler);
		}

		template <typename T, typename Handler>
		bool check(lua_State* L, int index, Handler&& handler, record& tracking) {
			if constexpr (meta::meta_detail::is_adl_sol_lua_check_v<T>) {
				return sol_lua_check(types<T>(), L, index, std::forward<Handler>(handler), tracking);
			}
			else {
				using Tu = meta::unqualified_t<T>;
				qualified_checker<T, lua_type_of_v<Tu>> c{};
				return c.check(L, index, std::forward<Handler>(handler), tracking);
			}
		}

		template <typename T, typename Handler>
		bool check(lua_State* L, int index, Handler&& handler) {
			record tracking {};
			return check<T>(L, index, std::forward<Handler>(handler), tracking);
		}

		template <typename T>
		bool check(lua_State* L, int index = -lua_size<meta::unqualified_t<T>>::value) {
			auto handler = &no_panic;
			return check<T>(L, index, handler);
		}

		template <typename T, typename Handler>
		bool check_usertype(lua_State* L, int index, type, Handler&& handler, record& tracking) {
			using Tu = meta::unqualified_t<T>;
			using detail_t = meta::conditional_t<std::is_pointer_v<T>, detail::as_pointer_tag<Tu>, detail::as_value_tag<Tu>>;
			return check<detail_t>(L, index, std::forward<Handler>(handler), tracking);
		}

		template <typename T, typename Handler>
		bool check_usertype(lua_State* L, int index, Handler&& handler, record& tracking) {
			using Tu = meta::unqualified_t<T>;
			using detail_t = meta::conditional_t<std::is_pointer_v<T>, detail::as_pointer_tag<Tu>, detail::as_value_tag<Tu>>;
			return check<detail_t>(L, index, std::forward<Handler>(handler), tracking);
		}

		template <typename T, typename Handler>
		bool check_usertype(lua_State* L, int index, Handler&& handler) {
			record tracking {};
			return check_usertype<T>(L, index, std::forward<Handler>(handler), tracking);
		}

		template <typename T>
		bool check_usertype(lua_State* L, int index = -lua_size<meta::unqualified_t<T>>::value) {
			auto handler = &no_panic;
			return check_usertype<T>(L, index, handler);
		}

		template <typename T, typename Handler>
		decltype(auto) unqualified_check_get(lua_State* L, int index, Handler&& handler, record& tracking) {
			using Tu = meta::unqualified_t<T>;
			if constexpr (meta::meta_detail::is_adl_sol_lua_check_get_v<T>) {
				return sol_lua_check_get(types<T>(), L, index, std::forward<Handler>(handler), tracking);
			}
			else if constexpr (meta::meta_detail::is_adl_sol_lua_check_get_v<Tu>) {
				return sol_lua_check_get(types<Tu>(), L, index, std::forward<Handler>(handler), tracking);
			}
			else {
				unqualified_check_getter<Tu> cg {};
				return cg.get(L, index, std::forward<Handler>(handler), tracking);
			}
		}

		template <typename T, typename Handler>
		decltype(auto) unqualified_check_get(lua_State* L, int index, Handler&& handler) {
			record tracking {};
			return unqualified_check_get<T>(L, index, handler, tracking);
		}

		template <typename T>
		decltype(auto) unqualified_check_get(lua_State* L, int index = -lua_size<meta::unqualified_t<T>>::value) {
			auto handler = &no_panic;
			return unqualified_check_get<T>(L, index, handler);
		}

		template <typename T, typename Handler>
		decltype(auto) check_get(lua_State* L, int index, Handler&& handler, record& tracking) {
			if constexpr (meta::meta_detail::is_adl_sol_lua_check_get_v<T>) {
				return sol_lua_check_get(types<T>(), L, index, std::forward<Handler>(handler), tracking);
			}
			else {
				qualified_check_getter<T> cg {};
				return cg.get(L, index, std::forward<Handler>(handler), tracking);
			}
		}

		template <typename T, typename Handler>
		decltype(auto) check_get(lua_State* L, int index, Handler&& handler) {
			record tracking {};
			return check_get<T>(L, index, handler, tracking);
		}

		template <typename T>
		decltype(auto) check_get(lua_State* L, int index = -lua_size<meta::unqualified_t<T>>::value) {
			auto handler = &no_panic;
			return check_get<T>(L, index, handler);
		}

		namespace stack_detail {

			template <typename Handler>
			bool check_types(lua_State*, int, Handler&&, record&) {
				return true;
			}

			template <typename T, typename... Args, typename Handler>
			bool check_types(lua_State* L, int firstargument, Handler&& handler, record& tracking) {
				if (!stack::check<T>(L, firstargument + tracking.used, handler, tracking))
					return false;
				return check_types<Args...>(L, firstargument, std::forward<Handler>(handler), tracking);
			}

			template <typename... Args, typename Handler>
			bool check_types(types<Args...>, lua_State* L, int index, Handler&& handler, record& tracking) {
				return check_types<Args...>(L, index, std::forward<Handler>(handler), tracking);
			}

		} // namespace stack_detail

		template <typename... Args, typename Handler>
		bool multi_check(lua_State* L, int index, Handler&& handler, record& tracking) {
			return stack_detail::check_types<Args...>(L, index, std::forward<Handler>(handler), tracking);
		}

		template <typename... Args, typename Handler>
		bool multi_check(lua_State* L, int index, Handler&& handler) {
			record tracking {};
			return multi_check<Args...>(L, index, std::forward<Handler>(handler), tracking);
		}

		template <typename... Args>
		bool multi_check(lua_State* L, int index) {
			return multi_check<Args...>(L, index);
		}

		template <typename T>
		auto unqualified_get(lua_State* L, int index, record& tracking) -> decltype(stack_detail::unchecked_unqualified_get<T>(L, index, tracking)) {
#if SOL_IS_ON(SOL_SAFE_GETTER)
			static constexpr bool is_op = meta::is_optional_v<T>;
			if constexpr (is_op) {
				return stack_detail::unchecked_unqualified_get<T>(L, index, tracking);
			}
			else {
				if (is_lua_reference<T>::value) {
					return stack_detail::unchecked_unqualified_get<T>(L, index, tracking);
				}
				auto op = unqualified_check_get<T>(L, index, type_panic_c_str, tracking);
				return *std::move(op);
			}
#else
			return stack_detail::unchecked_unqualified_get<T>(L, index, tracking);
#endif
		}

		template <typename T>
		decltype(auto) unqualified_get(lua_State* L, int index = -lua_size<meta::unqualified_t<T>>::value) {
			record tracking {};
			return unqualified_get<T>(L, index, tracking);
		}

		template <typename T>
		auto get(lua_State* L, int index, record& tracking) -> decltype(stack_detail::unchecked_get<T>(L, index, tracking)) {
#if SOL_IS_ON(SOL_SAFE_GETTER)
			static constexpr bool is_op = meta::is_optional_v<T>;
			if constexpr (is_op) {
				return stack_detail::unchecked_get<T>(L, index, tracking);
			}
			else {
				if (is_lua_reference<T>::value) {
					return stack_detail::unchecked_get<T>(L, index, tracking);
				}
				auto op = check_get<T>(L, index, type_panic_c_str, tracking);
				return *std::move(op);
			}
#else
			return stack_detail::unchecked_get<T>(L, index, tracking);
#endif
		}

		template <typename T>
		decltype(auto) get(lua_State* L, int index = -lua_size<meta::unqualified_t<T>>::value) {
			record tracking {};
			return get<T>(L, index, tracking);
		}

		template <typename T>
		decltype(auto) get_usertype(lua_State* L, int index, record& tracking) {
			using UT = meta::conditional_t<std::is_pointer<T>::value, detail::as_pointer_tag<std::remove_pointer_t<T>>, detail::as_value_tag<T>>;
			return get<UT>(L, index, tracking);
		}

		template <typename T>
		decltype(auto) get_usertype(lua_State* L, int index = -lua_size_v<meta::unqualified_t<T>>) {
			record tracking {};
			return get_usertype<T>(L, index, tracking);
		}

		template <typename T>
		decltype(auto) pop(lua_State* L) {
			return popper<T> {}.pop(L);
		}

		template <bool global = false, bool raw = false, typename Key>
		void get_field(lua_State* L, Key&& key) {
			field_getter<meta::unqualified_t<Key>, global, raw> {}.get(L, std::forward<Key>(key));
		}

		template <bool global = false, bool raw = false, typename Key>
		void get_field(lua_State* L, Key&& key, int tableindex) {
			field_getter<meta::unqualified_t<Key>, global, raw> {}.get(L, std::forward<Key>(key), tableindex);
		}

		template <bool global = false, typename Key>
		void raw_get_field(lua_State* L, Key&& key) {
			get_field<global, true>(L, std::forward<Key>(key));
		}

		template <bool global = false, typename Key>
		void raw_get_field(lua_State* L, Key&& key, int tableindex) {
			get_field<global, true>(L, std::forward<Key>(key), tableindex);
		}

		template <bool global = false, bool raw = false, typename C = detail::non_lua_nil_t, typename Key>
		probe probe_get_field(lua_State* L, Key&& key) {
			return probe_field_getter<meta::unqualified_t<Key>, C, global, raw> {}.get(L, std::forward<Key>(key));
		}

		template <bool global = false, bool raw = false, typename C = detail::non_lua_nil_t, typename Key>
		probe probe_get_field(lua_State* L, Key&& key, int tableindex) {
			return probe_field_getter<meta::unqualified_t<Key>, C, global, raw> {}.get(L, std::forward<Key>(key), tableindex);
		}

		template <bool global = false, typename C = detail::non_lua_nil_t, typename Key>
		probe probe_raw_get_field(lua_State* L, Key&& key) {
			return probe_get_field<global, true, C>(L, std::forward<Key>(key));
		}

		template <bool global = false, typename C = detail::non_lua_nil_t, typename Key>
		probe probe_raw_get_field(lua_State* L, Key&& key, int tableindex) {
			return probe_get_field<global, true, C>(L, std::forward<Key>(key), tableindex);
		}

		template <bool global = false, bool raw = false, typename Key, typename Value>
		void set_field(lua_State* L, Key&& key, Value&& value) {
			field_setter<meta::unqualified_t<Key>, global, raw> {}.set(L, std::forward<Key>(key), std::forward<Value>(value));
		}

		template <bool global = false, bool raw = false, typename Key, typename Value>
		void set_field(lua_State* L, Key&& key, Value&& value, int tableindex) {
			field_setter<meta::unqualified_t<Key>, global, raw> {}.set(L, std::forward<Key>(key), std::forward<Value>(value), tableindex);
		}

		template <bool global = false, typename Key, typename Value>
		void raw_set_field(lua_State* L, Key&& key, Value&& value) {
			set_field<global, true>(L, std::forward<Key>(key), std::forward<Value>(value));
		}

		template <bool global = false, typename Key, typename Value>
		void raw_set_field(lua_State* L, Key&& key, Value&& value, int tableindex) {
			set_field<global, true>(L, std::forward<Key>(key), std::forward<Value>(value), tableindex);
		}

		template <typename T, typename F>
		void modify_unique_usertype_as(const stack_reference& obj, F&& f) {
			void* raw = lua_touserdata(obj.lua_state(), obj.stack_index());
			void* ptr_memory = detail::align_usertype_pointer(raw);
			void* uu_memory = detail::align_usertype_unique<T>(raw);
			T& uu = *static_cast<T*>(uu_memory);
			f(uu);
			*static_cast<void**>(ptr_memory) = static_cast<void*>(detail::unique_get(obj.lua_state(), uu));
		}

		template <typename F>
		void modify_unique_usertype(const stack_reference& obj, F&& f) {
			using bt = meta::bind_traits<meta::unqualified_t<F>>;
			using T = typename bt::template arg_at<0>;
			using Tu = meta::unqualified_t<T>;
			modify_unique_usertype_as<Tu>(obj, std::forward<F>(f));
		}

		namespace stack_detail {
			template <typename T, typename Handler>
			decltype(auto) check_get_arg(lua_State* L_, int index_, Handler&& handler_, record& tracking_) {
				if constexpr (meta::meta_detail::is_adl_sol_lua_check_access_v<T>) {
					sol_lua_check_access(types<meta::unqualified_t<T>>(), L_, index_, tracking_);
				}
				return check_get<T>(L_, index_, std::forward<Handler>(handler_), tracking_);
			}

			template <typename T>
			decltype(auto) unchecked_get_arg(lua_State* L_, int index_, record& tracking_) {
				if constexpr (meta::meta_detail::is_adl_sol_lua_check_access_v<T>) {
					sol_lua_check_access(types<meta::unqualified_t<T>>(), L_, index_, tracking_);
				}
				return unchecked_get<T>(L_, index_, tracking_);
			}
		} // namespace stack_detail

	} // namespace stack

	namespace detail {

		template <typename T>
		lua_CFunction make_destructor(std::true_type) {
			if constexpr (is_unique_usertype_v<T>) {
				return &unique_destroy<T>;
			}
			else if constexpr (!std::is_pointer_v<T>) {
				return &usertype_alloc_destroy<T>;
			}
			else {
				return &cannot_destroy<T>;
			}
		}

		template <typename T>
		lua_CFunction make_destructor(std::false_type) {
			return &cannot_destroy<T>;
		}

		template <typename T>
		lua_CFunction make_destructor() {
			return make_destructor<T>(std::is_destructible<T>());
		}

		struct no_comp {
			template <typename A, typename B>
			bool operator()(A&&, B&&) const {
				return false;
			}
		};

		template <typename T>
		int is_check(lua_State* L) {
			return stack::push(L, stack::check<T>(L, 1, &no_panic));
		}

		template <typename T>
		int member_default_to_string(std::true_type, lua_State* L) {
			decltype(auto) ts = stack::get<T>(L, 1).to_string();
			return stack::push(L, std::forward<decltype(ts)>(ts));
		}

		template <typename T>
		int member_default_to_string(std::false_type, lua_State* L) {
			return luaL_error(L,
			     "cannot perform to_string on '%s': no 'to_string' overload in namespace, 'to_string' member "
			     "function, or operator<<(ostream&, ...) present",
			     detail::demangle<T>().data());
		}

		template <typename T>
		int adl_default_to_string(std::true_type, lua_State* L) {
			using namespace std;
			decltype(auto) ts = to_string(stack::get<T>(L, 1));
			return stack::push(L, std::forward<decltype(ts)>(ts));
		}

		template <typename T>
		int adl_default_to_string(std::false_type, lua_State* L) {
			return member_default_to_string<T>(meta::supports_to_string_member<T>(), L);
		}

		template <typename T>
		int oss_default_to_string(std::true_type, lua_State* L) {
			std::ostringstream oss;
			oss << stack::unqualified_get<T>(L, 1);
			return stack::push(L, oss.str());
		}

		template <typename T>
		int oss_default_to_string(std::false_type, lua_State* L) {
			return adl_default_to_string<T>(meta::supports_adl_to_string<T>(), L);
		}

		template <typename T>
		int default_to_string(lua_State* L) {
			return oss_default_to_string<T>(meta::supports_op_left_shift<std::ostream, T>(), L);
		}

		template <typename T>
		int default_size(lua_State* L) {
			decltype(auto) self = stack::unqualified_get<T>(L, 1);
			return stack::push(L, self.size());
		}

		template <typename T, typename Op>
		int comparsion_operator_wrap(lua_State* L) {
			if constexpr (std::is_void_v<T>) {
				return stack::push(L, false);
			}
			else {
				auto maybel = stack::unqualified_check_get<T>(L, 1);
				if (!maybel) {
					return stack::push(L, false);
				}
				auto mayber = stack::unqualified_check_get<T>(L, 2);
				if (!mayber) {
					return stack::push(L, false);
				}
				decltype(auto) l = *maybel;
				decltype(auto) r = *mayber;
				if constexpr (std::is_same_v<no_comp, Op>) {
					std::equal_to<> op;
					return stack::push(L, op(detail::ptr(l), detail::ptr(r)));
				}
				else {
					if constexpr (std::is_same_v<std::equal_to<>, Op> // clang-format hack
					     || std::is_same_v<std::less_equal<>, Op>     //
					     || std::is_same_v<std::less_equal<>, Op>) {  //
						if (detail::ptr(l) == detail::ptr(r)) {
							return stack::push(L, true);
						}
					}
					Op op;
					return stack::push(L, op(detail::deref(l), detail::deref(r)));
				}
			}
		}

		template <typename T, typename IFx, typename Fx>
		void insert_default_registrations(IFx&& ifx, Fx&& fx);

		template <typename T, bool, bool>
		struct get_is_primitive : is_lua_primitive<T> { };

		template <typename T>
		struct get_is_primitive<T, true, false>
		: meta::neg<std::is_reference<decltype(sol_lua_get(types<T>(), nullptr, -1, std::declval<stack::record&>()))>> { };

		template <typename T>
		struct get_is_primitive<T, false, true>
		: meta::neg<std::is_reference<decltype(sol_lua_get(types<meta::unqualified_t<T>>(), nullptr, -1, std::declval<stack::record&>()))>> { };

		template <typename T>
		struct get_is_primitive<T, true, true> : get_is_primitive<T, true, false> { };

	} // namespace detail

	template <typename T>
	struct is_proxy_primitive
	: detail::get_is_primitive<T, meta::meta_detail::is_adl_sol_lua_get_v<T>, meta::meta_detail::is_adl_sol_lua_get_v<meta::unqualified_t<T>>> { };

} // namespace sol

#endif // SOL_STACK_CORE_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_STACK_REFERENCE_HPP
#define SOL_STACK_REFERENCE_HPP

#include <sol/types.hpp>

namespace sol {
	namespace detail {
		inline bool xmovable(lua_State* leftL, lua_State* rightL) {
			if (rightL == nullptr || leftL == nullptr || leftL == rightL) {
				return false;
			}
			const void* leftregistry = lua_topointer(leftL, LUA_REGISTRYINDEX);
			const void* rightregistry = lua_topointer(rightL, LUA_REGISTRYINDEX);
			return leftregistry == rightregistry;
		}
	} // namespace detail

	class stateless_stack_reference {
	private:
		friend class stack_reference;

		int m_index = 0;

		int registry_index() const noexcept {
			return LUA_NOREF;
		}

	public:
		stateless_stack_reference() noexcept = default;
		stateless_stack_reference(lua_nil_t) noexcept : stateless_stack_reference() {};
		stateless_stack_reference(lua_State* L_, int index_) noexcept : stateless_stack_reference(absolute_index(L_, index_)) {
		}
		stateless_stack_reference(lua_State*, absolute_index index_) noexcept : stateless_stack_reference(index_) {
		}
		stateless_stack_reference(lua_State*, raw_index index_) noexcept : stateless_stack_reference(index_) {
		}
		stateless_stack_reference(absolute_index index_) noexcept : m_index(index_) {
		}
		stateless_stack_reference(raw_index index_) noexcept : m_index(index_) {
		}
		stateless_stack_reference(lua_State*, ref_index) noexcept = delete;
		stateless_stack_reference(ref_index) noexcept = delete;
		stateless_stack_reference(const reference&) noexcept = delete;
		stateless_stack_reference(const stateless_stack_reference&) noexcept = default;
		stateless_stack_reference(stateless_stack_reference&& o) noexcept = default;
		stateless_stack_reference& operator=(stateless_stack_reference&&) noexcept = default;
		stateless_stack_reference& operator=(const stateless_stack_reference&) noexcept = default;

		int push(lua_State* L_) const noexcept {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L_, 1, "not enough Lua stack space to push a single reference value");
#endif // make sure stack doesn't overflow
			lua_pushvalue(L_, m_index);
			return 1;
		}

		void pop(lua_State* L_, int pop_count = 1) const noexcept {
			lua_pop(L_, pop_count);
		}

		int stack_index() const noexcept {
			return m_index;
		}

		const void* pointer(lua_State* L_) const noexcept {
			const void* pointer_id = lua_topointer(L_, stack_index());
			return pointer_id;
		}

		type get_type(lua_State* L_) const noexcept {
			int untyped_value = lua_type(L_, stack_index());
			return static_cast<type>(untyped_value);
		}

		bool valid(lua_State* L) const noexcept {
			type t = get_type(L);
			return t != type::lua_nil && t != type::none;
		}

		void reset(lua_State*) noexcept {
			m_index = 0;
		}

		void reset(lua_State* L_, int index_) noexcept {
			m_index = absolute_index(L_, index_);
		}

		void abandon(lua_State* = nullptr) noexcept {
			m_index = 0;
		}

		stateless_stack_reference copy(lua_State* L_) const noexcept {
			return stateless_stack_reference(L_, raw_index(m_index));
		}

		void copy_assign(lua_State*, const stateless_stack_reference& right) noexcept {
			m_index = right.m_index;
		}

		bool equals(lua_State* L_, const stateless_stack_reference& r) const noexcept {
			return lua_compare(L_, this->stack_index(), r.stack_index(), LUA_OPEQ) == 1;
		}

		bool equals(lua_State* L_, lua_nil_t) const noexcept {
			return valid(L_);
		}
	};

	class stack_reference : public stateless_stack_reference {
	private:
		lua_State* luastate = nullptr;

	public:
		stack_reference() noexcept = default;
		stack_reference(lua_nil_t) noexcept : stack_reference() {};
		stack_reference(lua_State* L, lua_nil_t) noexcept : stateless_stack_reference(L, 0), luastate(L) {
		}
		stack_reference(lua_State* L, int i) noexcept : stateless_stack_reference(L, i), luastate(L) {
		}
		stack_reference(lua_State* L, absolute_index i) noexcept : stateless_stack_reference(L, i), luastate(L) {
		}
		stack_reference(lua_State* L, raw_index i) noexcept : stateless_stack_reference(L, i), luastate(L) {
		}
		stack_reference(lua_State* L, ref_index i) noexcept = delete;
		stack_reference(lua_State* L, const reference& r) noexcept = delete;
		stack_reference(lua_State* L, const stack_reference& r) noexcept : luastate(L) {
			if (!r.valid()) {
				m_index = 0;
				return;
			}
			int i = r.stack_index();
			if (detail::xmovable(lua_state(), r.lua_state())) {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
				luaL_checkstack(L, 1, "not enough Lua stack space to push a single reference value");
#endif // make sure stack doesn't overflow
				lua_pushvalue(r.lua_state(), r.stack_index());
				lua_xmove(r.lua_state(), luastate, 1);
				i = absolute_index(luastate, -1);
			}
			m_index = i;
		}
		stack_reference(stack_reference&& o) noexcept = default;
		stack_reference& operator=(stack_reference&&) noexcept = default;
		stack_reference(const stack_reference&) noexcept = default;
		stack_reference& operator=(const stack_reference&) noexcept = default;

		int push() const noexcept {
			return push(lua_state());
		}

		int push(lua_State* L_) const noexcept {
			return stateless_stack_reference::push(L_);
		}

		void pop() const noexcept {
			pop(lua_state());
		}

		void pop(lua_State* L_, int pop_count_ = 1) const noexcept {
			stateless_stack_reference::pop(L_, pop_count_);
		}

		const void* pointer() const noexcept {
			return stateless_stack_reference::pointer(lua_state());
		}

		type get_type() const noexcept {
			return stateless_stack_reference::get_type(lua_state());
		}

		lua_State* lua_state() const noexcept {
			return luastate;
		}

		bool valid() const noexcept {
			return stateless_stack_reference::valid(lua_state());
		}

		void abandon() {
			stateless_stack_reference::abandon(lua_state());
		}
	};

	inline bool operator==(const stack_reference& l, const stack_reference& r) {
		return lua_compare(l.lua_state(), l.stack_index(), r.stack_index(), LUA_OPEQ) == 1;
	}

	inline bool operator!=(const stack_reference& l, const stack_reference& r) {
		return !operator==(l, r);
	}

	inline bool operator==(const stack_reference& lhs, const lua_nil_t&) {
		return !lhs.valid();
	}

	inline bool operator==(const lua_nil_t&, const stack_reference& rhs) {
		return !rhs.valid();
	}

	inline bool operator!=(const stack_reference& lhs, const lua_nil_t&) {
		return lhs.valid();
	}

	inline bool operator!=(const lua_nil_t&, const stack_reference& rhs) {
		return rhs.valid();
	}

	inline bool operator==(const stateless_stack_reference& l, const stateless_stack_reference& r) {
		return l.stack_index() == r.stack_index();
	}

	inline bool operator!=(const stateless_stack_reference& l, const stateless_stack_reference& r) {
		return l.stack_index() != r.stack_index();
	}

	struct stateless_stack_reference_equals {
		using is_transparent = std::true_type;

		stateless_stack_reference_equals(lua_State* L_) noexcept : m_L(L_) {
		}

		lua_State* lua_state() const noexcept {
			return m_L;
		}

		bool operator()(const stateless_stack_reference& lhs, const stateless_stack_reference& rhs) const {
			return lhs.equals(lua_state(), rhs);
		}

		bool operator()(lua_nil_t lhs, const stateless_stack_reference& rhs) const {
			return rhs.equals(lua_state(), lhs);
		}

		bool operator()(const stateless_stack_reference& lhs, lua_nil_t rhs) const {
			return lhs.equals(lua_state(), rhs);
		}

	private:
		lua_State* m_L;
	};

	struct stack_reference_equals {
		using is_transparent = std::true_type;

		bool operator()(const lua_nil_t& lhs, const stack_reference& rhs) const {
			return lhs == rhs;
		}

		bool operator()(const stack_reference& lhs, const lua_nil_t& rhs) const {
			return lhs == rhs;
		}

		bool operator()(const stack_reference& lhs, const stack_reference& rhs) const {
			return lhs == rhs;
		}
	};

	struct stateless_stack_reference_hash {
		using argument_type = stateless_stack_reference;
		using result_type = std::size_t;
		using is_transparent = std::true_type;

		stateless_stack_reference_hash(lua_State* L_) noexcept : m_L(L_) {
		}

		lua_State* lua_state() const noexcept {
			return m_L;
		}

		result_type operator()(const argument_type& lhs) const noexcept {
			std::hash<const void*> h;
			return h(lhs.pointer(lua_state()));
		}

	private:
		lua_State* m_L;
	};

	struct stack_reference_hash {
		using argument_type = stack_reference;
		using result_type = std::size_t;
		using is_transparent = std::true_type;

		result_type operator()(const argument_type& lhs) const noexcept {
			std::hash<const void*> h;
			return h(lhs.pointer());
		}
	};
} // namespace sol

#endif // SOL_STACK_REFERENCE_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_STACK_CHECK_HPP
#define SOL_STACK_CHECK_HPP

#include <sol/stack_check_unqualified.hpp>
#include <sol/stack_check_qualified.hpp>

#endif // SOL_STACK_CHECK_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_STACK_GET_HPP
#define SOL_STACK_GET_HPP

#include <sol/stack_get_unqualified.hpp>
#include <sol/stack_get_qualified.hpp>

#endif // SOL_STACK_GET_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_STACK_CHECK_GET_HPP
#define SOL_STACK_CHECK_GET_HPP

#include <sol/stack_check_get_unqualified.hpp>
#include <sol/stack_check_get_qualified.hpp>

#endif // SOL_STACK_CHECK_GET_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_STACK_PUSH_HPP
#define SOL_STACK_PUSH_HPP

#include <sol/stack_core.hpp>
#include <sol/raii.hpp>
#include <sol/optional.hpp>
#include <sol/usertype_traits.hpp>
#include <sol/policies.hpp>
#include <sol/unicode.hpp>
#include <sol/assert.hpp>

#include <memory>
#include <type_traits>
#include <cassert>
#include <limits>
#include <cmath>
#include <string_view>
#if SOL_IS_ON(SOL_STD_VARIANT)
#include <variant>
#endif // Can use variant

namespace sol { namespace stack {
	namespace stack_detail {
		template <typename T>
		inline bool integer_value_fits(const T& value) {
			// We check if we can rely on casts or a lack of padding bits to satisfy
			// the requirements here
			// If it lacks padding bits, we can jump back and forth between lua_Integer and whatever type without
			// loss of information
			constexpr bool is_same_signedness
				= (std::is_signed_v<T> && std::is_signed_v<lua_Integer>) || (std::is_unsigned_v<T> && std::is_unsigned_v<lua_Integer>);
			constexpr bool probaby_fits_within_lua_Integer = sizeof(T) == sizeof(lua_Integer)
#if SOL_IS_ON(SOL_ALL_INTEGER_VALUES_FIT)
				&& ((std::has_unique_object_representations_v<T> && std::has_unique_object_representations_v<lua_Integer>) ? true : is_same_signedness)
#else
				&& is_same_signedness
#endif
				;
			if constexpr (sizeof(T) < sizeof(lua_Integer) || probaby_fits_within_lua_Integer) {
				(void)value;
				return true;
			}
			else {
				auto u_min = static_cast<std::intmax_t>((std::numeric_limits<lua_Integer>::min)());
				auto u_max = static_cast<std::uintmax_t>((std::numeric_limits<lua_Integer>::max)());
				auto t_min = static_cast<std::intmax_t>((std::numeric_limits<T>::min)());
				auto t_max = static_cast<std::uintmax_t>((std::numeric_limits<T>::max)());
				return (u_min <= t_min || value >= static_cast<T>(u_min)) && (u_max >= t_max || value <= static_cast<T>(u_max));
			}
		}

		template <typename T>
		int msvc_is_ass_with_if_constexpr_push_enum(std::true_type, lua_State* L, const T& value) {
			if constexpr (meta::any_same_v<std::underlying_type_t<T>,
				              char
#if SOL_IS_ON(SOL_CHAR8_T)
				              ,
				              char8_t
#endif
				              ,
				              char16_t,
				              char32_t>) {
				if constexpr (std::is_signed_v<T>) {
					return stack::push(L, static_cast<std::int_least32_t>(value));
				}
				else {
					return stack::push(L, static_cast<std::uint_least32_t>(value));
				}
			}
			else {
				return stack::push(L, static_cast<std::underlying_type_t<T>>(value));
			}
		}

		template <typename T>
		int msvc_is_ass_with_if_constexpr_push_enum(std::false_type, lua_State*, const T&) {
			return 0;
		}
	} // namespace stack_detail

	inline int push_environment_of(lua_State* L, int target_index = -1) {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
		luaL_checkstack(L, 1, detail::not_enough_stack_space_environment);
#endif // make sure stack doesn't overflow
#if SOL_LUA_VERSION_I_ < 502
		// Use lua_getfenv
		lua_getfenv(L, target_index);
#else

		if (lua_iscfunction(L, target_index) != 0) {
			const char* maybe_upvalue_name = lua_getupvalue(L, target_index, 1);
			if (maybe_upvalue_name != nullptr) {
				// it worked, take this one
				return 1;
			}
		}
		// Nominally, we search for the `"_ENV"` value.
		// If we don't find it.... uh, well. We've got a problem?
		for (int upvalue_index = 1;; ++upvalue_index) {
			const char* maybe_upvalue_name = lua_getupvalue(L, target_index, upvalue_index);
			if (maybe_upvalue_name == nullptr) {
				push(L, lua_nil);
				break;
			}

			string_view upvalue_name(maybe_upvalue_name);
			if (upvalue_name == "_ENV") {
				// Keep this one!
				break;
			}
			// Discard what we received, loop back around
			lua_pop(L, 1);
		}
#endif
		return 1;
	}

	template <typename T>
	int push_environment_of(const T& target) {
		lua_State* target_L = target.lua_state();
		int target_index = absolute_index(target_L, -target.push());
		int env_count = push_environment_of(target_L, target_index);
		SOL_ASSERT(env_count == 1);
		lua_rotate(target_L, target_index, 1);
		lua_pop(target_L, 1);
		return env_count;
	}

	template <typename T>
	struct unqualified_pusher<detail::as_value_tag<T>> {
		template <typename F, typename... Args>
		static int push_fx(lua_State* L, F&& f, Args&&... args) {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L, 1, detail::not_enough_stack_space_userdata);
#endif // make sure stack doesn't overflow
       // Basically, we store all user-data like this:
       // If it's a movable/copyable value (no std::ref(x)), then we store the pointer to the new
       // data in the first sizeof(T*) bytes, and then however many bytes it takes to
       // do the actual object. Things that are std::ref or plain T* are stored as
       // just the sizeof(T*), and nothing else.
			T* obj = detail::usertype_allocate<T>(L);
			f();
			std::allocator<T> alloc {};
			std::allocator_traits<std::allocator<T>>::construct(alloc, obj, std::forward<Args>(args)...);
			return 1;
		}

		template <typename K, typename... Args>
		static int push_keyed(lua_State* L, K&& k, Args&&... args) {
			stack_detail::undefined_metatable fx(L, &k[0], &stack::stack_detail::set_undefined_methods_on<T>);
			return push_fx(L, fx, std::forward<Args>(args)...);
		}

		template <typename Arg, typename... Args>
		static int push(lua_State* L, Arg&& arg, Args&&... args) {
			if constexpr (std::is_same_v<meta::unqualified_t<Arg>, detail::with_function_tag>) {
				(void)arg;
				return push_fx(L, std::forward<Args>(args)...);
			}
			else {
				return push_keyed(L, usertype_traits<T>::metatable(), std::forward<Arg>(arg), std::forward<Args>(args)...);
			}
		}

		static int push(lua_State* L) {
			return push_keyed(L, usertype_traits<T>::metatable());
		}
	};

	template <typename T>
	struct unqualified_pusher<detail::as_pointer_tag<T>> {
		typedef meta::unqualified_t<T> U;

		template <typename F>
		static int push_fx(lua_State* L, F&& f, T* obj) {
			if (obj == nullptr)
				return stack::push(L, lua_nil);
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L, 1, detail::not_enough_stack_space_userdata);
#endif // make sure stack doesn't overflow
			T** pref = detail::usertype_allocate_pointer<T>(L);
			f();
			*pref = obj;
			return 1;
		}

		template <typename K>
		static int push_keyed(lua_State* L, K&& k, T* obj) {
			stack_detail::undefined_metatable fx(L, &k[0], &stack::stack_detail::set_undefined_methods_on<U*>);
			return push_fx(L, fx, obj);
		}

		template <typename Arg, typename... Args>
		static int push(lua_State* L, Arg&& arg, Args&&... args) {
			if constexpr (std::is_same_v<meta::unqualified_t<Arg>, detail::with_function_tag>) {
				(void)arg;
				return push_fx(L, std::forward<Args>(args)...);
			}
			else {
				return push_keyed(L, usertype_traits<U*>::metatable(), std::forward<Arg>(arg), std::forward<Args>(args)...);
			}
		}
	};

	template <>
	struct unqualified_pusher<detail::as_reference_tag> {
		template <typename T>
		static int push(lua_State* L, T&& obj) {
			return stack::push(L, detail::ptr(obj));
		}
	};

	namespace stack_detail {
		template <typename T>
		struct uu_pusher {
			using element = unique_usertype_element_t<T>;
			using actual = unique_usertype_actual_t<T>;

			template <typename Arg, typename... Args>
			static int push(lua_State* L, Arg&& arg, Args&&... args) {
				if constexpr (std::is_base_of_v<actual, meta::unqualified_t<Arg>>) {
					if (detail::unique_is_null(L, arg)) {
						return stack::push(L, lua_nil);
					}
					return push_deep(L, std::forward<Arg>(arg), std::forward<Args>(args)...);
				}
				else {
					return push_deep(L, std::forward<Arg>(arg), std::forward<Args>(args)...);
				}
			}

			template <typename... Args>
			static int push_deep(lua_State* L, Args&&... args) {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
				luaL_checkstack(L, 1, detail::not_enough_stack_space_userdata);
#endif // make sure stack doesn't overflow
				element** pointer_to_memory = nullptr;
				detail::unique_destructor* fx = nullptr;
				detail::unique_tag* id = nullptr;
				actual* typed_memory = detail::usertype_unique_allocate<element, actual>(L, pointer_to_memory, fx, id);
				if (luaL_newmetatable(L, &usertype_traits<d::u<std::remove_cv_t<element>>>::metatable()[0]) == 1) {
					detail::lua_reg_table registration_table {};
					int index = 0;
					detail::indexed_insert insert_callable(registration_table, index);
					detail::insert_default_registrations<element>(insert_callable, detail::property_always_true);
					registration_table[index] = { to_string(meta_function::garbage_collect).c_str(), detail::make_destructor<T>() };
					luaL_setfuncs(L, registration_table, 0);
				}
				lua_setmetatable(L, -2);
				*fx = detail::usertype_unique_alloc_destroy<element, actual>;
				*id = &detail::inheritance<element>::template type_unique_cast<actual>;
				detail::default_construct::construct(typed_memory, std::forward<Args>(args)...);
				*pointer_to_memory = detail::unique_get<T>(L, *typed_memory);
				return 1;
			}
		};
	} // namespace stack_detail

	template <typename T>
	struct unqualified_pusher<detail::as_unique_tag<T>> {
		template <typename... Args>
		static int push(lua_State* L, Args&&... args) {
			stack_detail::uu_pusher<T> p;
			(void)p;
			return p.push(L, std::forward<Args>(args)...);
		}
	};

	template <typename T, typename>
	struct unqualified_pusher {
		template <typename... Args>
		static int push(lua_State* L, Args&&... args) {
			using Tu = meta::unqualified_t<T>;
			if constexpr (is_lua_reference_v<Tu>) {
				using int_arr = int[];
				int_arr p { (std::forward<Args>(args).push(L))... };
				return p[0];
			}
			else if constexpr (std::is_same_v<Tu, bool>) {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
				luaL_checkstack(L, 1, detail::not_enough_stack_space_generic);
#endif // make sure stack doesn't overflow
				lua_pushboolean(L, std::forward<Args>(args)...);
				return 1;
			}
			else if constexpr (std::is_integral_v<Tu> || std::is_same_v<Tu, lua_Integer>) {
				const Tu& value(std::forward<Args>(args)...);
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
				luaL_checkstack(L, 1, detail::not_enough_stack_space_integral);
#endif // make sure stack doesn't overflow
#if SOL_LUA_VERSION_I_ >= 503
				if (stack_detail::integer_value_fits<Tu>(value)) {
					lua_pushinteger(L, static_cast<lua_Integer>(value));
					return 1;
				}
#endif // Lua 5.3 and above
#if SOL_IS_ON(SOL_NUMBER_PRECISION_CHECKS)
				if (static_cast<T>(llround(static_cast<lua_Number>(value))) != value) {
#if SOL_IS_OFF(SOL_EXCEPTIONS)
					// Is this really worth it?
					SOL_ASSERT_MSG(false, "integer value will be misrepresented in lua");
					lua_pushinteger(L, static_cast<lua_Integer>(value));
					return 1;
#else
					throw error(detail::direct_error, "integer value will be misrepresented in lua");
#endif // No Exceptions
				}
#endif // Safe Numerics and Number Precision Check
				lua_pushnumber(L, static_cast<lua_Number>(value));
				return 1;
			}
			else if constexpr (std::is_floating_point_v<Tu> || std::is_same_v<Tu, lua_Number>) {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
				luaL_checkstack(L, 1, detail::not_enough_stack_space_floating);
#endif // make sure stack doesn't overflow
				lua_pushnumber(L, std::forward<Args>(args)...);
				return 1;
			}
			else if constexpr (std::is_same_v<Tu, luaL_Stream*>) {
				luaL_Stream* source { std::forward<Args>(args)... };
				luaL_Stream* stream = static_cast<luaL_Stream*>(detail::alloc_newuserdata(L, sizeof(luaL_Stream)));
				stream->f = source->f;
#if SOL_IS_ON(SOL_LUAL_STREAM_USE_CLOSE_FUNCTION)
				stream->closef = source->closef;
#endif // LuaJIT and Lua 5.1 and below do not have
				return 1;
			}
			else if constexpr (std::is_same_v<Tu, luaL_Stream>) {
				luaL_Stream& source(std::forward<Args>(args)...);
				luaL_Stream* stream = static_cast<luaL_Stream*>(detail::alloc_newuserdata(L, sizeof(luaL_Stream)));
				stream->f = source.f;
#if SOL_IS_ON(SOL_LUAL_STREAM_USE_CLOSE_FUNCTION)
				stream->closef = source.closef;
#endif // LuaJIT and Lua 5.1 and below do not have
				return 1;
			}
			else if constexpr (std::is_enum_v<Tu>) {
				return stack_detail::msvc_is_ass_with_if_constexpr_push_enum(std::true_type(), L, std::forward<Args>(args)...);
			}
			else if constexpr (std::is_pointer_v<Tu>) {
				return stack::push<detail::as_pointer_tag<std::remove_pointer_t<T>>>(L, std::forward<Args>(args)...);
			}
			else if constexpr (is_unique_usertype_v<Tu>) {
				return stack::push<detail::as_unique_tag<T>>(L, std::forward<Args>(args)...);
			}
			else {
				return stack::push<detail::as_value_tag<T>>(L, std::forward<Args>(args)...);
			}
		}
	};

	template <typename T>
	struct unqualified_pusher<std::reference_wrapper<T>> {
		static int push(lua_State* L, const std::reference_wrapper<T>& t) {
			return stack::push(L, std::addressof(detail::deref(t.get())));
		}
	};

	template <typename T>
	struct unqualified_pusher<detail::as_table_tag<T>> {
		using has_kvp = meta::has_key_value_pair<meta::unqualified_t<std::remove_pointer_t<T>>>;

		static int push(lua_State* L, const T& tablecont) {
			return push(has_kvp(), std::false_type(), L, tablecont);
		}

		static int push(lua_State* L, const T& tablecont, nested_tag_t) {
			return push(has_kvp(), std::true_type(), L, tablecont);
		}

		static int push(std::true_type, lua_State* L, const T& tablecont) {
			return push(has_kvp(), std::true_type(), L, tablecont);
		}

		static int push(std::false_type, lua_State* L, const T& tablecont) {
			return push(has_kvp(), std::false_type(), L, tablecont);
		}

		template <bool is_nested>
		static int push(std::true_type, std::integral_constant<bool, is_nested>, lua_State* L, const T& tablecont) {
			auto& cont = detail::deref(detail::unwrap(tablecont));
			lua_createtable(L, static_cast<int>(cont.size()), 0);
			int tableindex = lua_gettop(L);
			for (const auto& pair : cont) {
				if (is_nested) {
					set_field(L, pair.first, as_nested_ref(pair.second), tableindex);
				}
				else {
					set_field(L, pair.first, pair.second, tableindex);
				}
			}
			return 1;
		}

		template <bool is_nested>
		static int push(std::false_type, std::integral_constant<bool, is_nested>, lua_State* L, const T& tablecont) {
			auto& cont = detail::deref(detail::unwrap(tablecont));
			lua_createtable(L, stack_detail::get_size_hint(cont), 0);
			int tableindex = lua_gettop(L);
			std::size_t index = 1;
			for (const auto& i : cont) {
#if SOL_LUA_VERSION_I_ >= 503
				int p = is_nested ? stack::push(L, as_nested_ref(i)) : stack::push(L, i);
				for (int pi = 0; pi < p; ++pi) {
					lua_seti(L, tableindex, static_cast<lua_Integer>(index++));
				}
#else
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
				luaL_checkstack(L, 1, detail::not_enough_stack_space_generic);
#endif // make sure stack doesn't overflow
				lua_pushinteger(L, static_cast<lua_Integer>(index));
				int p = is_nested ? stack::push(L, as_nested_ref(i)) : stack::push(L, i);
				if (p == 1) {
					++index;
					lua_settable(L, tableindex);
				}
				else {
					int firstindex = tableindex + 1 + 1;
					for (int pi = 0; pi < p; ++pi) {
						stack::push(L, index);
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
						luaL_checkstack(L, 1, detail::not_enough_stack_space_generic);
#endif // make sure stack doesn't overflow
						lua_pushvalue(L, firstindex);
						lua_settable(L, tableindex);
						++index;
						++firstindex;
					}
					lua_pop(L, 1 + p);
				}
#endif // Lua Version 5.3 and others
			}
			// TODO: figure out a better way to do this...?
			// set_field(L, -1, cont.size());
			return 1;
		}
	};

	template <typename T>
	struct unqualified_pusher<as_table_t<T>> {
		static int push(lua_State* L, const as_table_t<T>& value_) {
			using inner_t = std::remove_pointer_t<meta::unwrap_unqualified_t<T>>;
			if constexpr (is_container_v<inner_t>) {
				return stack::push<detail::as_table_tag<T>>(L, value_.value());
			}
			else {
				return stack::push(L, value_.value());
			}
		}

		static int push(lua_State* L, const T& value_) {
			using inner_t = std::remove_pointer_t<meta::unwrap_unqualified_t<T>>;
			if constexpr (is_container_v<inner_t>) {
				return stack::push<detail::as_table_tag<T>>(L, value_);
			}
			else {
				return stack::push(L, value_);
			}
		}
	};

	template <typename T>
	struct unqualified_pusher<nested<T>> {
		static int push(lua_State* L, const T& nested_value) noexcept {
			using Tu = meta::unwrap_unqualified_t<T>;
			using inner_t = std::remove_pointer_t<Tu>;
			if constexpr (is_container_v<inner_t>) {
				return stack::push<detail::as_table_tag<T>>(L, nested_value, nested_tag);
			}
			else {
				return stack::push<Tu>(L, nested_value);
			}
		}

		static int push(lua_State* L, const nested<T>& nested_wrapper_) noexcept {
			using Tu = meta::unwrap_unqualified_t<T>;
			using inner_t = std::remove_pointer_t<Tu>;
			if constexpr (is_container_v<inner_t>) {
				return stack::push<detail::as_table_tag<T>>(L, nested_wrapper_.value(), nested_tag);
			}
			else {
				return stack::push<Tu>(L, nested_wrapper_.value());
			}
		}
	};

	template <typename T>
	struct unqualified_pusher<std::initializer_list<T>> {
		static int push(lua_State* L, const std::initializer_list<T>& il) noexcept {
			unqualified_pusher<detail::as_table_tag<std::initializer_list<T>>> p {};
			return p.push(L, il);
		}
	};

	template <>
	struct unqualified_pusher<lua_nil_t> {
		static int push(lua_State* L, lua_nil_t) noexcept {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L, 1, detail::not_enough_stack_space_generic);
#endif // make sure stack doesn't overflow
			lua_pushnil(L);
			return 1;
		}
	};

	template <>
	struct unqualified_pusher<stack_count> {
		static int push(lua_State*, stack_count st) noexcept {
			return st.count;
		}
	};

	template <>
	struct unqualified_pusher<metatable_key_t> {
		static int push(lua_State* L, metatable_key_t) {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L, 1, detail::not_enough_stack_space_generic);
#endif // make sure stack doesn't overflow
			lua_pushlstring(L, to_string(meta_function::metatable).c_str(), 4);
			return 1;
		}
	};

	template <>
	struct unqualified_pusher<std::remove_pointer_t<lua_CFunction>> {
		static int push(lua_State* L, lua_CFunction func, int n = 0) noexcept {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L, 1, detail::not_enough_stack_space_generic);
#endif // make sure stack doesn't overflow
			lua_pushcclosure(L, func, n);
			return 1;
		}
	};

	template <>
	struct unqualified_pusher<lua_CFunction> {
		static int push(lua_State* L, lua_CFunction func, int n = 0) {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L, 1, detail::not_enough_stack_space_generic);
#endif // make sure stack doesn't overflow
			lua_pushcclosure(L, func, n);
			return 1;
		}
	};

#if SOL_IS_ON(SOL_USE_NOEXCEPT_FUNCTION_TYPE)
	template <>
	struct unqualified_pusher<std::remove_pointer_t<detail::lua_CFunction_noexcept>> {
		static int push(lua_State* L, detail::lua_CFunction_noexcept func, int n = 0) {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L, 1, detail::not_enough_stack_space_generic);
#endif // make sure stack doesn't overflow
			lua_pushcclosure(L, func, n);
			return 1;
		}
	};

	template <>
	struct unqualified_pusher<detail::lua_CFunction_noexcept> {
		static int push(lua_State* L, detail::lua_CFunction_noexcept func, int n = 0) {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L, 1, detail::not_enough_stack_space_generic);
#endif // make sure stack doesn't overflow
			lua_pushcclosure(L, func, n);
			return 1;
		}
	};
#endif // noexcept function type

	template <>
	struct unqualified_pusher<c_closure> {
		static int push(lua_State* L, c_closure cc) {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L, 1, detail::not_enough_stack_space_generic);
#endif // make sure stack doesn't overflow
			lua_pushcclosure(L, cc.c_function, cc.upvalues);
			return 1;
		}
	};

	template <typename Arg, typename... Args>
	struct unqualified_pusher<closure<Arg, Args...>> {
		template <std::size_t... I, typename T>
		static int push(std::index_sequence<I...>, lua_State* L, T&& c) {
			using f_tuple = decltype(std::forward<T>(c).upvalues);
			int pushcount = multi_push(L, std::get<I>(std::forward<f_tuple>(std::forward<T>(c).upvalues))...);
			return stack::push(L, c_closure(c.c_function, pushcount));
		}

		template <typename T>
		static int push(lua_State* L, T&& c) {
			return push(std::make_index_sequence<1 + sizeof...(Args)>(), L, std::forward<T>(c));
		}
	};

	template <>
	struct unqualified_pusher<void*> {
		static int push(lua_State* L, void* userdata) noexcept {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L, 1, detail::not_enough_stack_space_generic);
#endif // make sure stack doesn't overflow
			lua_pushlightuserdata(L, userdata);
			return 1;
		}
	};

	template <>
	struct unqualified_pusher<const void*> {
		static int push(lua_State* L, const void* userdata) noexcept {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L, 1, detail::not_enough_stack_space_generic);
#endif // make sure stack doesn't overflow
			lua_pushlightuserdata(L, const_cast<void*>(userdata));
			return 1;
		}
	};

	template <>
	struct unqualified_pusher<lightuserdata_value> {
		static int push(lua_State* L, lightuserdata_value userdata) noexcept {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L, 1, detail::not_enough_stack_space_generic);
#endif // make sure stack doesn't overflow
			lua_pushlightuserdata(L, userdata);
			return 1;
		}
	};

	template <typename T>
	struct unqualified_pusher<light<T>> {
		static int push(lua_State* L, light<T> l) noexcept {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L, 1, detail::not_enough_stack_space_generic);
#endif // make sure stack doesn't overflow
			lua_pushlightuserdata(L, static_cast<void*>(l.value()));
			return 1;
		}
	};

	template <typename T>
	struct unqualified_pusher<user<T>> {
		template <bool with_meta = true, typename Key, typename... Args>
		static int push_with(lua_State* L, Key&& name, Args&&... args) {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L, 1, detail::not_enough_stack_space_userdata);
#endif // make sure stack doesn't overflow
       // A dumb pusher
			T* data = detail::user_allocate<T>(L);
			if (with_meta) {
				// Make sure we have a plain GC set for this data
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
				luaL_checkstack(L, 1, detail::not_enough_stack_space_generic);
#endif // make sure stack doesn't overflow
				if (luaL_newmetatable(L, name) != 0) {
					lua_CFunction cdel = detail::user_alloc_destroy<T>;
					lua_pushcclosure(L, cdel, 0);
					lua_setfield(L, -2, "__gc");
				}
				lua_setmetatable(L, -2);
			}
			std::allocator<T> alloc {};
			std::allocator_traits<std::allocator<T>>::construct(alloc, data, std::forward<Args>(args)...);
			return 1;
		}

		template <typename Arg, typename... Args>
		static int push(lua_State* L, Arg&& arg, Args&&... args) {
			if constexpr (std::is_same_v<meta::unqualified_t<Arg>, metatable_key_t>) {
				const auto name = &arg[0];
				return push_with<true>(L, name, std::forward<Args>(args)...);
			}
			else if constexpr (std::is_same_v<meta::unqualified_t<Arg>, no_metatable_t>) {
				(void)arg;
				const auto name = &usertype_traits<meta::unqualified_t<T>>::user_gc_metatable()[0];
				return push_with<false>(L, name, std::forward<Args>(args)...);
			}
			else {
				const auto name = &usertype_traits<meta::unqualified_t<T>>::user_gc_metatable()[0];
				return push_with(L, name, std::forward<Arg>(arg), std::forward<Args>(args)...);
			}
		}

		static int push(lua_State* L, const user<T>& u) {
			const auto name = &usertype_traits<meta::unqualified_t<T>>::user_gc_metatable()[0];
			return push_with(L, name, u.value);
		}

		static int push(lua_State* L, user<T>&& u) {
			const auto name = &usertype_traits<meta::unqualified_t<T>>::user_gc_metatable()[0];
			return push_with(L, name, std::move(u.value()));
		}

		static int push(lua_State* L, no_metatable_t, const user<T>& u) {
			const auto name = &usertype_traits<meta::unqualified_t<T>>::user_gc_metatable()[0];
			return push_with<false>(L, name, u.value());
		}

		static int push(lua_State* L, no_metatable_t, user<T>&& u) {
			const auto name = &usertype_traits<meta::unqualified_t<T>>::user_gc_metatable()[0];
			return push_with<false>(L, name, std::move(u.value()));
		}
	};

	template <>
	struct unqualified_pusher<userdata_value> {
		static int push(lua_State* L, userdata_value data) {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L, 1, detail::not_enough_stack_space_userdata);
#endif // make sure stack doesn't overflow
			void** ud = detail::usertype_allocate_pointer<void>(L);
			*ud = data.value();
			return 1;
		}
	};

	template <>
	struct unqualified_pusher<const char*> {
		static int push_sized(lua_State* L, const char* str, std::size_t len) {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L, 1, detail::not_enough_stack_space_string);
#endif // make sure stack doesn't overflow
			lua_pushlstring(L, str, len);
			return 1;
		}

		static int push(lua_State* L, const char* str) {
			if (str == nullptr)
				return stack::push(L, lua_nil);
			return push_sized(L, str, std::char_traits<char>::length(str));
		}

		static int push(lua_State* L, const char* strb, const char* stre) {
			return push_sized(L, strb, static_cast<std::size_t>(stre - strb));
		}

		static int push(lua_State* L, const char* str, std::size_t len) {
			return push_sized(L, str, len);
		}
	};

	template <>
	struct unqualified_pusher<char*> {
		static int push_sized(lua_State* L, const char* str, std::size_t len) {
			unqualified_pusher<const char*> p {};
			(void)p;
			return p.push_sized(L, str, len);
		}

		static int push(lua_State* L, const char* str) {
			unqualified_pusher<const char*> p {};
			(void)p;
			return p.push(L, str);
		}

		static int push(lua_State* L, const char* strb, const char* stre) {
			unqualified_pusher<const char*> p {};
			(void)p;
			return p.push(L, strb, stre);
		}

		static int push(lua_State* L, const char* str, std::size_t len) {
			unqualified_pusher<const char*> p {};
			(void)p;
			return p.push(L, str, len);
		}
	};

	template <size_t N>
	struct unqualified_pusher<char[N]> {
		static int push(lua_State* L, const char (&str)[N]) {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L, 1, detail::not_enough_stack_space_string);
#endif // make sure stack doesn't overflow
			lua_pushlstring(L, str, std::char_traits<char>::length(str));
			return 1;
		}

		static int push(lua_State* L, const char (&str)[N], std::size_t sz) {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L, 1, detail::not_enough_stack_space_string);
#endif // make sure stack doesn't overflow
			lua_pushlstring(L, str, sz);
			return 1;
		}
	};

	template <>
	struct unqualified_pusher<char> {
		static int push(lua_State* L, char c) {
			const char str[2] = { c, '\0' };
			return stack::push(L, static_cast<const char*>(str), 1u);
		}
	};

#if SOL_IS_ON(SOL_CHAR8_T)
	template <>
	struct unqualified_pusher<const char8_t*> {
		static int push_sized(lua_State* L, const char8_t* str, std::size_t len) {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L, 1, detail::not_enough_stack_space_string);
#endif // make sure stack doesn't overflow
			lua_pushlstring(L, reinterpret_cast<const char*>(str), len);
			return 1;
		}

		static int push(lua_State* L, const char8_t* str) {
			if (str == nullptr)
				return stack::push(L, lua_nil);
			return push_sized(L, str, std::char_traits<char>::length(reinterpret_cast<const char*>(str)));
		}

		static int push(lua_State* L, const char8_t* strb, const char8_t* stre) {
			return push_sized(L, strb, static_cast<std::size_t>(stre - strb));
		}

		static int push(lua_State* L, const char8_t* str, std::size_t len) {
			return push_sized(L, str, len);
		}
	};

	template <>
	struct unqualified_pusher<char8_t*> {
		static int push_sized(lua_State* L, const char8_t* str, std::size_t len) {
			unqualified_pusher<const char8_t*> p {};
			(void)p;
			return p.push_sized(L, str, len);
		}

		static int push(lua_State* L, const char8_t* str) {
			unqualified_pusher<const char8_t*> p {};
			(void)p;
			return p.push(L, str);
		}

		static int push(lua_State* L, const char8_t* strb, const char8_t* stre) {
			unqualified_pusher<const char8_t*> p {};
			(void)p;
			return p.push(L, strb, stre);
		}

		static int push(lua_State* L, const char8_t* str, std::size_t len) {
			unqualified_pusher<const char8_t*> p {};
			(void)p;
			return p.push(L, str, len);
		}
	};

	template <size_t N>
	struct unqualified_pusher<char8_t[N]> {
		static int push(lua_State* L, const char8_t (&str)[N]) {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L, 1, detail::not_enough_stack_space_string);
#endif // make sure stack doesn't overflow
			const char* str_as_char = reinterpret_cast<const char*>(static_cast<const char8_t*>(str));
			lua_pushlstring(L, str_as_char, std::char_traits<char>::length(str_as_char));
			return 1;
		}

		static int push(lua_State* L, const char8_t (&str)[N], std::size_t sz) {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L, 1, detail::not_enough_stack_space_string);
#endif // make sure stack doesn't overflow
			lua_pushlstring(L, str, sz);
			return 1;
		}
	};

	template <>
	struct unqualified_pusher<char8_t> {
		static int push(lua_State* L, char8_t c) {
			const char8_t str[2] = { c, '\0' };
			return stack::push(L, static_cast<const char8_t*>(str), 1u);
		}
	};
#endif // char8_t


	template <typename Ch, typename Traits, typename Al>
	struct unqualified_pusher<std::basic_string<Ch, Traits, Al>> {
		static int push(lua_State* L, const std::basic_string<Ch, Traits, Al>& str) {
			if constexpr (!std::is_same_v<Ch, char>) {
				return stack::push(L, str.data(), str.size());
			}
			else {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
				luaL_checkstack(L, 1, detail::not_enough_stack_space_string);
#endif // make sure stack doesn't overflow
				lua_pushlstring(L, str.c_str(), str.size());
				return 1;
			}
		}

		static int push(lua_State* L, const std::basic_string<Ch, Traits, Al>& str, std::size_t sz) {
			if constexpr (!std::is_same_v<Ch, char>) {
				return stack::push(L, str.data(), sz);
			}
			else {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
				luaL_checkstack(L, 1, detail::not_enough_stack_space_string);
#endif // make sure stack doesn't overflow
				lua_pushlstring(L, str.c_str(), sz);
				return 1;
			}
		}
	};

	template <typename Ch, typename Traits>
	struct unqualified_pusher<basic_string_view<Ch, Traits>> {
		static int push(lua_State* L, const basic_string_view<Ch, Traits>& sv) {
			return stack::push(L, sv.data(), sv.length());
		}

		static int push(lua_State* L, const basic_string_view<Ch, Traits>& sv, std::size_t n) {
			return stack::push(L, sv.data(), n);
		}
	};

	template <>
	struct unqualified_pusher<meta_function> {
		static int push(lua_State* L, meta_function m) {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L, 1, detail::not_enough_stack_space_meta_function_name);
#endif // make sure stack doesn't overflow
			const std::string& str = to_string(m);
			lua_pushlstring(L, str.c_str(), str.size());
			return 1;
		}
	};

	template <>
	struct unqualified_pusher<absolute_index> {
		static int push(lua_State* L, absolute_index ai) {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L, 1, detail::not_enough_stack_space_generic);
#endif // make sure stack doesn't overflow
			lua_pushvalue(L, ai);
			return 1;
		}
	};

	template <>
	struct unqualified_pusher<raw_index> {
		static int push(lua_State* L, raw_index ri) {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L, 1, detail::not_enough_stack_space_generic);
#endif // make sure stack doesn't overflow
			lua_pushvalue(L, ri);
			return 1;
		}
	};

	template <>
	struct unqualified_pusher<ref_index> {
		static int push(lua_State* L, ref_index ri) {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L, 1, detail::not_enough_stack_space_generic);
#endif // make sure stack doesn't overflow
			lua_rawgeti(L, LUA_REGISTRYINDEX, ri);
			return 1;
		}
	};

	template <>
	struct unqualified_pusher<const wchar_t*> {
		static int push(lua_State* L, const wchar_t* wstr) {
			return push(L, wstr, std::char_traits<wchar_t>::length(wstr));
		}

		static int push(lua_State* L, const wchar_t* wstr, std::size_t sz) {
			return push(L, wstr, wstr + sz);
		}

		static int push(lua_State* L, const wchar_t* strb, const wchar_t* stre) {
			if constexpr (sizeof(wchar_t) == 2) {
				const char16_t* sb = reinterpret_cast<const char16_t*>(strb);
				const char16_t* se = reinterpret_cast<const char16_t*>(stre);
				return stack::push(L, sb, se);
			}
			else {
				const char32_t* sb = reinterpret_cast<const char32_t*>(strb);
				const char32_t* se = reinterpret_cast<const char32_t*>(stre);
				return stack::push(L, sb, se);
			}
		}
	};

	template <>
	struct unqualified_pusher<wchar_t*> {
		static int push(lua_State* L, const wchar_t* str) {
			unqualified_pusher<const wchar_t*> p {};
			(void)p;
			return p.push(L, str);
		}

		static int push(lua_State* L, const wchar_t* strb, const wchar_t* stre) {
			unqualified_pusher<const wchar_t*> p {};
			(void)p;
			return p.push(L, strb, stre);
		}

		static int push(lua_State* L, const wchar_t* str, std::size_t len) {
			unqualified_pusher<const wchar_t*> p {};
			(void)p;
			return p.push(L, str, len);
		}
	};

	template <>
	struct unqualified_pusher<const char16_t*> {
		static int convert_into(lua_State* L, char* start, std::size_t, const char16_t* strb, const char16_t* stre) {
			char* target = start;
			char32_t cp = 0;
			for (const char16_t* strtarget = strb; strtarget < stre;) {
				auto dr = unicode::utf16_to_code_point(strtarget, stre);
				if (dr.error != unicode::error_code::ok) {
					cp = unicode::unicode_detail::replacement;
				}
				else {
					cp = dr.codepoint;
				}
				auto er = unicode::code_point_to_utf8(cp);
				const char* utf8data = er.code_units.data();
				std::memcpy(target, utf8data, er.code_units_size);
				target += er.code_units_size;
				strtarget = dr.next;
			}

			return stack::push(L, start, target);
		}

		static int push(lua_State* L, const char16_t* u16str) {
			return push(L, u16str, std::char_traits<char16_t>::length(u16str));
		}

		static int push(lua_State* L, const char16_t* u16str, std::size_t sz) {
			return push(L, u16str, u16str + sz);
		}

		static int push(lua_State* L, const char16_t* strb, const char16_t* stre) {
			char sbo[SOL_OPTIMIZATION_STRING_CONVERSION_STACK_SIZE_I_];
			// if our max string space is small enough, use SBO
			// right off the bat
			std::size_t max_possible_code_units = static_cast<std::size_t>(static_cast<std::size_t>(stre - strb) * static_cast<std::size_t>(4));
			if (max_possible_code_units <= SOL_OPTIMIZATION_STRING_CONVERSION_STACK_SIZE_I_) {
				return convert_into(L, sbo, max_possible_code_units, strb, stre);
			}
			// otherwise, we must manually count/check size
			std::size_t needed_size = 0;
			for (const char16_t* strtarget = strb; strtarget < stre;) {
				auto dr = unicode::utf16_to_code_point(strtarget, stre);
				auto er = unicode::code_point_to_utf8(dr.codepoint);
				needed_size += er.code_units_size;
				strtarget = dr.next;
			}
			if (needed_size < SOL_OPTIMIZATION_STRING_CONVERSION_STACK_SIZE_I_) {
				return convert_into(L, sbo, needed_size, strb, stre);
			}
			std::string u8str("", 0);
			u8str.resize(needed_size);
			char* target = const_cast<char*>(u8str.data());
			return convert_into(L, target, needed_size, strb, stre);
		}
	};

	template <>
	struct unqualified_pusher<char16_t*> {
		static int push(lua_State* L, const char16_t* str) {
			unqualified_pusher<const char16_t*> p {};
			(void)p;
			return p.push(L, str);
		}

		static int push(lua_State* L, const char16_t* strb, const char16_t* stre) {
			unqualified_pusher<const char16_t*> p {};
			(void)p;
			return p.push(L, strb, stre);
		}

		static int push(lua_State* L, const char16_t* str, std::size_t len) {
			unqualified_pusher<const char16_t*> p {};
			(void)p;
			return p.push(L, str, len);
		}
	};

	template <>
	struct unqualified_pusher<const char32_t*> {
		static int convert_into(lua_State* L, char* start, std::size_t, const char32_t* strb, const char32_t* stre) {
			char* target = start;
			char32_t cp = 0;
			for (const char32_t* strtarget = strb; strtarget < stre;) {
				auto dr = unicode::utf32_to_code_point(strtarget, stre);
				if (dr.error != unicode::error_code::ok) {
					cp = unicode::unicode_detail::replacement;
				}
				else {
					cp = dr.codepoint;
				}
				auto er = unicode::code_point_to_utf8(cp);
				const char* data = er.code_units.data();
				std::memcpy(target, data, er.code_units_size);
				target += er.code_units_size;
				strtarget = dr.next;
			}
			return stack::push(L, start, target);
		}

		static int push(lua_State* L, const char32_t* u32str) {
			return push(L, u32str, u32str + std::char_traits<char32_t>::length(u32str));
		}

		static int push(lua_State* L, const char32_t* u32str, std::size_t sz) {
			return push(L, u32str, u32str + sz);
		}

		static int push(lua_State* L, const char32_t* strb, const char32_t* stre) {
			char sbo[SOL_OPTIMIZATION_STRING_CONVERSION_STACK_SIZE_I_];
			// if our max string space is small enough, use SBO
			// right off the bat
			std::size_t max_possible_code_units = static_cast<std::size_t>(static_cast<std::size_t>(stre - strb) * static_cast<std::size_t>(4));
			if (max_possible_code_units <= SOL_OPTIMIZATION_STRING_CONVERSION_STACK_SIZE_I_) {
				return convert_into(L, sbo, max_possible_code_units, strb, stre);
			}
			// otherwise, we must manually count/check size
			std::size_t needed_size = 0;
			for (const char32_t* strtarget = strb; strtarget < stre;) {
				auto dr = unicode::utf32_to_code_point(strtarget, stre);
				auto er = unicode::code_point_to_utf8(dr.codepoint);
				needed_size += er.code_units_size;
				strtarget = dr.next;
			}
			if (needed_size < SOL_OPTIMIZATION_STRING_CONVERSION_STACK_SIZE_I_) {
				return convert_into(L, sbo, needed_size, strb, stre);
			}
			std::string u8str("", 0);
			u8str.resize(needed_size);
			char* target = const_cast<char*>(u8str.data());
			return convert_into(L, target, needed_size, strb, stre);
		}
	};

	template <>
	struct unqualified_pusher<char32_t*> {
		static int push(lua_State* L, const char32_t* str) {
			unqualified_pusher<const char32_t*> p {};
			(void)p;
			return p.push(L, str);
		}

		static int push(lua_State* L, const char32_t* strb, const char32_t* stre) {
			unqualified_pusher<const char32_t*> p {};
			(void)p;
			return p.push(L, strb, stre);
		}

		static int push(lua_State* L, const char32_t* str, std::size_t len) {
			unqualified_pusher<const char32_t*> p {};
			(void)p;
			return p.push(L, str, len);
		}
	};

	template <size_t N>
	struct unqualified_pusher<wchar_t[N]> {
		static int push(lua_State* L, const wchar_t (&str)[N]) {
			return push(L, str, std::char_traits<wchar_t>::length(str));
		}

		static int push(lua_State* L, const wchar_t (&str)[N], std::size_t sz) {
			const wchar_t* str_ptr = static_cast<const wchar_t*>(str);
			return stack::push<const wchar_t*>(L, str_ptr, str_ptr + sz);
		}
	};

	template <size_t N>
	struct unqualified_pusher<char16_t[N]> {
		static int push(lua_State* L, const char16_t (&str)[N]) {
			return push(L, str, std::char_traits<char16_t>::length(str));
		}

		static int push(lua_State* L, const char16_t (&str)[N], std::size_t sz) {
			const char16_t* str_ptr = static_cast<const char16_t*>(str);
			return stack::push<const char16_t*>(L, str_ptr, str_ptr + sz);
		}
	};

	template <size_t N>
	struct unqualified_pusher<char32_t[N]> {
		static int push(lua_State* L, const char32_t (&str)[N]) {
			return push(L, str, std::char_traits<char32_t>::length(str));
		}

		static int push(lua_State* L, const char32_t (&str)[N], std::size_t sz) {
			const char32_t* str_ptr = static_cast<const char32_t*>(str);
			return stack::push<const char32_t*>(L, str_ptr, str_ptr + sz);
		}
	};

	template <>
	struct unqualified_pusher<wchar_t> {
		static int push(lua_State* L, wchar_t c) {
			const wchar_t str[2] = { c, '\0' };
			return stack::push(L, static_cast<const wchar_t*>(str), 1u);
		}
	};

	template <>
	struct unqualified_pusher<char16_t> {
		static int push(lua_State* L, char16_t c) {
			const char16_t str[2] = { c, '\0' };
			return stack::push(L, static_cast<const char16_t*>(str), 1u);
		}
	};

	template <>
	struct unqualified_pusher<char32_t> {
		static int push(lua_State* L, char32_t c) {
			const char32_t str[2] = { c, '\0' };
			return stack::push(L, static_cast<const char32_t*>(str), 1u);
		}
	};

	template <typename... Args>
	struct unqualified_pusher<std::tuple<Args...>> {
		template <std::size_t... I, typename T>
		static int push(std::index_sequence<I...>, lua_State* L, T&& t) {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L, static_cast<int>(sizeof...(I)), detail::not_enough_stack_space_generic);
#endif // make sure stack doesn't overflow
			int pushcount = 0;
			(void)detail::swallow { 0, (pushcount += stack::push(L, std::get<I>(std::forward<T>(t))), 0)... };
			return pushcount;
		}

		template <typename T>
		static int push(lua_State* L, T&& t) {
			return push(std::index_sequence_for<Args...>(), L, std::forward<T>(t));
		}
	};

	template <typename A, typename B>
	struct unqualified_pusher<std::pair<A, B>> {
		template <typename T>
		static int push(lua_State* L, T&& t) {
			int pushcount = stack::push(L, std::get<0>(std::forward<T>(t)));
			pushcount += stack::push(L, std::get<1>(std::forward<T>(t)));
			return pushcount;
		}
	};

	template <typename T>
	struct unqualified_pusher<T, std::enable_if_t<meta::is_optional_v<T>>> {
		using ValueType = typename meta::unqualified_t<T>::value_type;

		template <typename Optional>
		static int push(lua_State* L, Optional&& op) {
			using QualifiedValueType = meta::conditional_t<std::is_lvalue_reference_v<Optional>, ValueType&, ValueType&&>;
			if (!op) {
				return stack::push(L, nullopt);
			}
			return stack::push(L, static_cast<QualifiedValueType>(op.value()));
		}
	};

	template <typename T>
	struct unqualified_pusher<forward_as_value_t<T>> {
		static int push(lua_State* L, const forward_as_value_t<T>& value_) {
			return stack::push<T>(L, value_.value());
		}

		static int push(lua_State* L, forward_as_value_t<T>&& value_) {
			return stack::push<T>(L, std::move(value_).value());
		}
	};

	template <>
	struct unqualified_pusher<nullopt_t> {
		static int push(lua_State* L, nullopt_t) noexcept {
			return stack::push(L, lua_nil);
		}
	};

	template <>
	struct unqualified_pusher<std::nullptr_t> {
		static int push(lua_State* L, std::nullptr_t) noexcept {
			return stack::push(L, lua_nil);
		}
	};

	template <>
	struct unqualified_pusher<this_state> {
		static int push(lua_State*, const this_state&) noexcept {
			return 0;
		}
	};

	template <>
	struct unqualified_pusher<this_main_state> {
		static int push(lua_State*, const this_main_state&) noexcept {
			return 0;
		}
	};

	template <>
	struct unqualified_pusher<new_table> {
		static int push(lua_State* L, const new_table& nt) {
			lua_createtable(L, nt.sequence_hint, nt.map_hint);
			return 1;
		}
	};

	template <typename Allocator>
	struct unqualified_pusher<basic_bytecode<Allocator>> {
		template <typename T>
		static int push(lua_State* L, T&& bc, const char* bytecode_name) {
			const auto first = bc.data();
			const auto bcsize = bc.size();
			// pushes either the function, or an error
			// if it errors, shit goes south, and people can test that upstream
			(void)luaL_loadbuffer(
				L, reinterpret_cast<const char*>(first), static_cast<std::size_t>(bcsize * (sizeof(*first) / sizeof(const char))), bytecode_name);
			return 1;
		}

		template <typename T>
		static int push(lua_State* L, T&& bc) {
			return push(L, std::forward<bc>(bc), "bytecode");
		}
	};

#if SOL_IS_ON(SOL_STD_VARIANT)
	namespace stack_detail {

		struct push_function {
			lua_State* L;

			push_function(lua_State* L_) noexcept : L(L_) {
			}

			template <typename T>
			int operator()(T&& value) const {
				return stack::push<T>(L, std::forward<T>(value));
			}
		};

	} // namespace stack_detail

	template <typename... Tn>
	struct unqualified_pusher<std::variant<Tn...>> {
		static int push(lua_State* L, const std::variant<Tn...>& v) {
			return std::visit(stack_detail::push_function(L), v);
		}

		static int push(lua_State* L, std::variant<Tn...>&& v) {
			return std::visit(stack_detail::push_function(L), std::move(v));
		}
	};
#endif // Variant because Clang is terrible

}} // namespace sol::stack

#endif // SOL_STACK_PUSH_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_STACK_POP_HPP
#define SOL_STACK_POP_HPP

#include <sol/stack_core.hpp>
#include <sol/stack_get.hpp>
#include <utility>
#include <tuple>

namespace sol { namespace stack {
	template <typename T, typename>
	struct popper {
		inline static decltype(auto) pop(lua_State* L) {
			if constexpr (is_stack_based_v<meta::unqualified_t<T>>) {
				static_assert(!is_stack_based_v<meta::unqualified_t<T>>,
					"You cannot pop something that lives solely on the stack: it will not remain on the stack when popped and thusly will go out of "
					"scope!");
			}
			else {
				record tracking {};
				decltype(auto) r = get<T>(L, -lua_size<T>::value, tracking);
				lua_pop(L, tracking.used);
				return r;
			}
		}
	};
}} // namespace sol::stack

#endif // SOL_STACK_POP_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_STACK_FIELD_HPP
#define SOL_STACK_FIELD_HPP

#include <sol/stack_core.hpp>
#include <sol/stack_push.hpp>
#include <sol/stack_get.hpp>
#include <sol/stack_check_get.hpp>

namespace sol { namespace stack {

	namespace stack_detail {
		template <typename T, bool global, bool raw>
		inline constexpr bool is_get_direct_tableless_v = (global && !raw && meta::is_c_str_or_string_v<T>);

		template <typename T, bool global, bool raw>
		inline constexpr bool is_get_direct_v = (is_get_direct_tableless_v<T, global, raw>) // cf-hack
			|| (!global && !raw && (meta::is_c_str_or_string_v<T> || meta::is_string_of_v<T, char>)) // cf-hack
			|| (!global && raw && (std::is_integral_v<T> && !std::is_same_v<T, bool>))
#if SOL_LUA_VERSION_I_ >= 503
			|| (!global && !raw && (std::is_integral_v<T> && !std::is_same_v<T, bool>))
#endif // integer keys 5.3 or better
#if SOL_LUA_VERSION_I_ >= 502
			|| (!global && raw && std::is_pointer_v<T> && std::is_void_v<std::remove_pointer_t<T>>)
#endif // void pointer keys 5.2 or better
			;

		template <typename T, bool global, bool raw>
		inline constexpr bool is_set_direct_tableless_v = (global && !raw && meta::is_c_str_or_string_v<T>);

		template <typename T, bool global, bool raw>
		inline constexpr bool is_set_direct_v = (is_set_direct_tableless_v<T, global, raw>) // cf-hack
			|| (!global && !raw && (meta::is_c_str_or_string_v<T> || meta::is_string_of_v<T, char>)) // cf-hack
			|| (!global && raw && (std::is_integral_v<T> && !std::is_same_v<T, bool>))     // cf-hack
#if SOL_LUA_VERSION_I_ >= 503
			|| (!global && !raw && (std::is_integral_v<T> && !std::is_same_v<T, bool>))
#endif // integer keys 5.3 or better
#if SOL_LUA_VERSION_I_ >= 502
			|| (!global && raw && (std::is_pointer_v<T> && std::is_void_v<std::remove_pointer_t<T>>))
#endif // void pointer keys 5.2 or better
			;
	} // namespace stack_detail

	template <typename T, bool global, bool raw, typename>
	struct field_getter {
		static inline constexpr int default_table_index
			= meta::conditional_t<stack_detail::is_get_direct_v<T, global, raw>, std::integral_constant<int, -1>, std::integral_constant<int, -2>>::value;

		template <typename Key>
		void get(lua_State* L, Key&& key, int tableindex = default_table_index) {
			if constexpr (std::is_same_v<T, update_if_empty_t> || std::is_same_v<T, override_value_t> || std::is_same_v<T, create_if_nil_t>) {
				(void)L;
				(void)key;
				(void)tableindex;
			}
			else if constexpr (std::is_same_v<T, env_key_t>) {
				(void)key;
#if SOL_LUA_VERSION_I_ < 502
				// Use lua_setfenv
				lua_getfenv(L, tableindex);
#else
				// Use upvalues as explained in Lua 5.2 and beyond's manual
				if (lua_getupvalue(L, tableindex, 1) == nullptr) {
					push(L, lua_nil);
				}
#endif
			}
			else if constexpr (std::is_same_v<T, metatable_key_t>) {
				(void)key;
				if (lua_getmetatable(L, tableindex) == 0)
					push(L, lua_nil);
			}
			else if constexpr (raw) {
				if constexpr (std::is_integral_v<T> && !std::is_same_v<bool, T>) {
					lua_rawgeti(L, tableindex, static_cast<lua_Integer>(key));
				}
#if SOL_LUA_VERSION_I_ >= 502
				else if constexpr (std::is_pointer_v<T> && std::is_void_v<std::remove_pointer_t<T>>) {
					lua_rawgetp(L, tableindex, key);
				}
#endif // Lua 5.2.x+
				else {
					push(L, std::forward<Key>(key));
					lua_rawget(L, tableindex);
				}
			}
			else {
				if constexpr (meta::is_c_str_or_string_v<T>) {
					if constexpr (global) {
						(void)tableindex;
						lua_getglobal(L, &key[0]);
					}
					else {
						lua_getfield(L, tableindex, &key[0]);
					}
				}
				else if constexpr (std::is_same_v<T, meta_function>) {
					const auto& real_key = to_string(key);
					lua_getfield(L, tableindex, &real_key[0]);
				}
#if SOL_LUA_VERSION_I_ >= 503
				else if constexpr (std::is_integral_v<T> && !std::is_same_v<bool, T>) {
					lua_geti(L, tableindex, static_cast<lua_Integer>(key));
				}
#endif // Lua 5.3.x+
				else {
					push(L, std::forward<Key>(key));
					lua_gettable(L, tableindex);
				}
			}
		}
	};

	template <typename... Args, bool b, bool raw, typename C>
	struct field_getter<std::tuple<Args...>, b, raw, C> {
		template <std::size_t... I, typename Keys>
		void apply(std::index_sequence<0, I...>, lua_State* L, Keys&& keys, int tableindex) {
			get_field<b, raw>(L, std::get<0>(std::forward<Keys>(keys)), tableindex);
			void(detail::swallow { (get_field<false, raw>(L, std::get<I>(std::forward<Keys>(keys))), 0)... });
			reference saved(L, -1);
			lua_pop(L, static_cast<int>(sizeof...(I)));
			saved.push();
		}

		template <typename Keys>
		void get(lua_State* L, Keys&& keys) {
			apply(std::make_index_sequence<sizeof...(Args)>(), L, std::forward<Keys>(keys), lua_absindex(L, -1));
		}

		template <typename Keys>
		void get(lua_State* L, Keys&& keys, int tableindex) {
			apply(std::make_index_sequence<sizeof...(Args)>(), L, std::forward<Keys>(keys), tableindex);
		}
	};

	template <typename A, typename B, bool b, bool raw, typename C>
	struct field_getter<std::pair<A, B>, b, raw, C> {
		template <typename Keys>
		void get(lua_State* L, Keys&& keys, int tableindex) {
			get_field<b, raw>(L, std::get<0>(std::forward<Keys>(keys)), tableindex);
			get_field<false, raw>(L, std::get<1>(std::forward<Keys>(keys)));
			reference saved(L, -1);
			lua_pop(L, static_cast<int>(2));
			saved.push();
		}

		template <typename Keys>
		void get(lua_State* L, Keys&& keys) {
			get_field<b, raw>(L, std::get<0>(std::forward<Keys>(keys)));
			get_field<false, raw>(L, std::get<1>(std::forward<Keys>(keys)));
			reference saved(L, -1);
			lua_pop(L, static_cast<int>(2));
			saved.push();
		}
	};

	template <typename T, bool global, bool raw, typename>
	struct field_setter {
		static constexpr int default_table_index
			= meta::conditional_t<stack_detail::is_set_direct_v<T, global, raw>, std::integral_constant<int, -2>, std::integral_constant<int, -3>>::value;

		template <typename Key, typename Value>
		void set(lua_State* L, Key&& key, Value&& value, int tableindex = default_table_index) {
			if constexpr (std::is_same_v<T, update_if_empty_t> || std::is_same_v<T, override_value_t>) {
				(void)L;
				(void)key;
				(void)value;
				(void)tableindex;
			}
			else if constexpr (std::is_same_v<T, metatable_key_t>) {
				(void)key;
				push(L, std::forward<Value>(value));
				lua_setmetatable(L, tableindex);
			}
			else if constexpr (raw) {
				if constexpr (std::is_integral_v<T> && !std::is_same_v<bool, T>) {
					push(L, std::forward<Value>(value));
					lua_rawseti(L, tableindex, static_cast<lua_Integer>(key));
				}
#if SOL_LUA_VERSION_I_ >= 502
				else if constexpr (std::is_pointer_v<T> && std::is_void_v<std::remove_pointer_t<T>>) {
					push(L, std::forward<Value>(value));
					lua_rawsetp(L, tableindex, std::forward<Key>(key));
				}
#endif // Lua 5.2.x
				else {
					push(L, std::forward<Key>(key));
					push(L, std::forward<Value>(value));
					lua_rawset(L, tableindex);
				}
			}
			else {
				if constexpr (meta::is_c_str_or_string_v<T>) {
					if constexpr (global) {
						push(L, std::forward<Value>(value));
						lua_setglobal(L, &key[0]);
						(void)tableindex;
					}
					else {
						push(L, std::forward<Value>(value));
						lua_setfield(L, tableindex, &key[0]);
					}
				}
#if SOL_LUA_VERSION_I_ >= 503
				else if constexpr (std::is_integral_v<T> && !std::is_same_v<bool, T>) {
					push(L, std::forward<Value>(value));
					lua_seti(L, tableindex, static_cast<lua_Integer>(key));
				}
#endif // Lua 5.3.x
				else {
					push(L, std::forward<Key>(key));
					push(L, std::forward<Value>(value));
					lua_settable(L, tableindex);
				}
			}
		}
	};

	template <typename... Args, bool b, bool raw, typename C>
	struct field_setter<std::tuple<Args...>, b, raw, C> {
		template <bool g, std::size_t I, typename Keys, typename Value>
		void apply(std::index_sequence<I>, lua_State* L, Keys&& keys, Value&& value, int tableindex) {
			I < 1 ? set_field<g, raw>(L, std::get<I>(std::forward<Keys>(keys)), std::forward<Value>(value), tableindex)
				 : set_field<g, raw>(L, std::get<I>(std::forward<Keys>(keys)), std::forward<Value>(value));
		}

		template <bool g, std::size_t I0, std::size_t I1, std::size_t... I, typename Keys, typename Value>
		void apply(std::index_sequence<I0, I1, I...>, lua_State* L, Keys&& keys, Value&& value, int tableindex) {
			I0 < 1 ? get_field<g, raw>(L, std::get<I0>(std::forward<Keys>(keys)), tableindex)
				  : get_field<g, raw>(L, std::get<I0>(std::forward<Keys>(keys)), -1);
			apply<false>(std::index_sequence<I1, I...>(), L, std::forward<Keys>(keys), std::forward<Value>(value), -1);
		}

		template <bool g, std::size_t I0, std::size_t... I, typename Keys, typename Value>
		void top_apply(std::index_sequence<I0, I...>, lua_State* L, Keys&& keys, Value&& value, int tableindex) {
			apply<g>(std::index_sequence<I0, I...>(), L, std::forward<Keys>(keys), std::forward<Value>(value), tableindex);
			lua_pop(L, static_cast<int>(sizeof...(I)));
		}

		template <typename Keys, typename Value>
		void set(lua_State* L, Keys&& keys, Value&& value, int tableindex = -3) {
			top_apply<b>(std::make_index_sequence<sizeof...(Args)>(), L, std::forward<Keys>(keys), std::forward<Value>(value), tableindex);
		}
	};

	template <typename A, typename B, bool b, bool raw, typename C>
	struct field_setter<std::pair<A, B>, b, raw, C> {
		template <typename Keys, typename Value>
		void set(lua_State* L, Keys&& keys, Value&& value, int tableindex = -1) {
			get_field<b, raw>(L, std::get<0>(std::forward<Keys>(keys)), tableindex);
			set_field<false, raw>(L, std::get<1>(std::forward<Keys>(keys)), std::forward<Value>(value), lua_gettop(L));
			lua_pop(L, 1);
		}
	};
}} // namespace sol::stack

#endif // SOL_STACK_FIELD_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_STACK_PROBE_HPP
#define SOL_STACK_PROBE_HPP

#include <sol/stack_core.hpp>
#include <sol/stack_field.hpp>
#include <sol/stack_check.hpp>

namespace sol { namespace stack {
	template <typename T, typename P, bool b, bool raw, typename>
	struct probe_field_getter {
		template <typename Key>
		probe get(lua_State* L, Key&& key, int tableindex = -2) {
			if constexpr (!b) {
				if (!maybe_indexable(L, tableindex)) {
					return probe(false, 0);
				}
			}
			get_field<b, raw>(L, std::forward<Key>(key), tableindex);
			return probe(check<P>(L), 1);
		}
	};

	template <typename A, typename B, typename P, bool b, bool raw, typename C>
	struct probe_field_getter<std::pair<A, B>, P, b, raw, C> {
		template <typename Keys>
		probe get(lua_State* L, Keys&& keys, int tableindex = -2) {
			if (!b && !maybe_indexable(L, tableindex)) {
				return probe(false, 0);
			}
			get_field<b, raw>(L, std::get<0>(keys), tableindex);
			if (!maybe_indexable(L)) {
				return probe(false, 1);
			}
			get_field<false, raw>(L, std::get<1>(keys), tableindex);
			return probe(check<P>(L), 2);
		}
	};

	template <typename... Args, typename P, bool b, bool raw, typename C>
	struct probe_field_getter<std::tuple<Args...>, P, b, raw, C> {
		template <std::size_t I, typename Keys>
		probe apply(std::index_sequence<I>, int sofar, lua_State* L, Keys&& keys, int tableindex) {
			get_field<(I < 1) && b, raw>(L, std::get<I>(keys), tableindex);
			return probe(check<P>(L), sofar);
		}

		template <std::size_t I, std::size_t I1, std::size_t... In, typename Keys>
		probe apply(std::index_sequence<I, I1, In...>, int sofar, lua_State* L, Keys&& keys, int tableindex) {
			get_field < I<1 && b, raw>(L, std::get<I>(keys), tableindex);
			if (!maybe_indexable(L)) {
				return probe(false, sofar);
			}
			return apply(std::index_sequence<I1, In...>(), sofar + 1, L, std::forward<Keys>(keys), -1);
		}

		template <typename Keys>
		probe get(lua_State* L, Keys&& keys, int tableindex = -2) {
			if constexpr (!b) {
				if (!maybe_indexable(L, tableindex)) {
					return probe(false, 0);
				}
				return apply(std::index_sequence_for<Args...>(), 1, L, std::forward<Keys>(keys), tableindex);
			}
			else {
				return apply(std::index_sequence_for<Args...>(), 1, L, std::forward<Keys>(keys), tableindex);
			}
		}
	};
}} // namespace sol::stack

#endif // SOL_STACK_PROBE_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_ERROR_HPP
#define SOL_ERROR_HPP

#include <sol/compatibility.hpp>

#include <stdexcept>
#include <string>
#include <array>

namespace sol {
	namespace detail {
		struct direct_error_tag { };
		const auto direct_error = direct_error_tag {};

		struct error_result {
			int results;
			const char* format_string;
			std::array<const char*, 4> argument_strings;

			error_result() : results(0), format_string(nullptr) {
			}

			error_result(int results_) : results(results_), format_string(nullptr) {
			}

			error_result(const char* format_string_, const char* first_message_) : results(0), format_string(format_string_), argument_strings() {
				argument_strings[0] = first_message_;
			}
		};

		inline int handle_errors(lua_State* L, const error_result& er) {
			if (er.format_string == nullptr) {
				return er.results;
			}
			return luaL_error(L, er.format_string, er.argument_strings[0], er.argument_strings[1], er.argument_strings[2], er.argument_strings[3]);
		}

		class error_exception : public std::runtime_error {
		public:
			error_exception(const std::string& str) : error_exception(detail::direct_error, "lua: error: " + str) {
			}
			error_exception(std::string&& str) : error_exception(detail::direct_error, "lua: error: " + std::move(str)) {
			}
			error_exception(detail::direct_error_tag, const std::string& str) : std::runtime_error(str) {
			}
			error_exception(detail::direct_error_tag, std::string&& str) : std::runtime_error(str) {
			}

			error_exception(const error_exception& e) = default;
			error_exception(error_exception&& e) = default;
			error_exception& operator=(const error_exception& e) = default;
			error_exception& operator=(error_exception&& e) = default;
		};
	} // namespace detail

	class error : public std::runtime_error {
	private:
		// Because VC++ is upsetting, most of the time!
		std::string what_reason;

	public:
		error(const std::string& str) : error(detail::direct_error, "lua: error: " + str) {
		}
		error(std::string&& str) : error(detail::direct_error, "lua: error: " + std::move(str)) {
		}
		error(detail::direct_error_tag, const std::string& str) : std::runtime_error(str) {
		}
		error(detail::direct_error_tag, std::string&& str) : std::runtime_error(str) {
		}

		error(const error& e) = default;
		error(error&& e) = default;
		error& operator=(const error& e) = default;
		error& operator=(error&& e) = default;
	};

} // namespace sol

#endif // SOL_ERROR_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#pragma once

#ifndef SOL_ASSERT_HPP
#define SOL_ASSERT_HPP

#include <sol/forward.hpp>

#if SOL_IS_ON(SOL2_CI)

struct pre_main {
	pre_main() {
#ifdef _MSC_VER
		_set_abort_behavior(0, _WRITE_ABORT_MSG);
#endif
	}
} inline sol2_ci_dont_lock_ci_please = {};

#endif // Prevent lockup when doing Continuous Integration


// clang-format off

#if SOL_IS_ON(SOL_USER_ASSERT)
	#define SOL_ASSERT(...) SOL_C_ASSERT(__VA_ARGS__)
#else
	#if SOL_IS_ON(SOL_DEBUG_BUILD)
		#include <exception>
		#include <iostream>
		#include <cstdlib>

			#define SOL_ASSERT(...)                                                                                               \
				do {                                                                                                               \
					if (!(__VA_ARGS__)) {                                                                                           \
						std::cerr << "Assertion `" #__VA_ARGS__ "` failed in " << __FILE__ << " line " << __LINE__ << std::endl; \
						std::terminate();                                                                                        \
					}                                                                                                             \
				} while (false)
	#else
		#define SOL_ASSERT(...)           \
			do {                           \
				if (false) {              \
					(void)(__VA_ARGS__); \
				}                         \
			} while (false)
	#endif
#endif

#if SOL_IS_ON(SOL_USER_ASSERT_MSG)
	#define SOL_ASSERT_MSG(message, ...) SOL_ASSERT_MSG(message, __VA_ARGS__)
#else
	#if SOL_IS_ON(SOL_DEBUG_BUILD)
		#include <exception>
		#include <iostream>
		#include <cstdlib>

		#define SOL_ASSERT_MSG(message, ...)                                                                                                         \
			do {                                                                                                                                  \
				if (!(__VA_ARGS__)) {                                                                                                              \
					std::cerr << "Assertion `" #__VA_ARGS__ "` failed in " << __FILE__ << " line " << __LINE__ << ": " << message << std::endl; \
					std::terminate();                                                                                                           \
				}                                                                                                                                \
			} while (false)
	#else
		#define SOL_ASSERT_MSG(message, ...)    \
			do {                             \
				if (false) {                \
					(void)(__VA_ARGS__);   \
					(void)sizeof(message); \
				}                           \
			} while (false)
	#endif
#endif

// clang-format on

#endif // SOL_ASSERT_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_STACK_HPP
#define SOL_STACK_HPP

#include <sol/trampoline.hpp>
#include <sol/stack_core.hpp>
#include <sol/stack_reference.hpp>
#include <sol/stack_check.hpp>
#include <sol/stack_get.hpp>
#include <sol/stack_check_get.hpp>
#include <sol/stack_push.hpp>
#include <sol/stack_pop.hpp>
#include <sol/stack_field.hpp>
#include <sol/stack_probe.hpp>
#include <sol/error.hpp>
#include <sol/assert.hpp>

#include <cstring>
#include <array>

namespace sol {
	namespace detail {
		using typical_chunk_name_t = char[SOL_ID_SIZE_I_];
		using typical_file_chunk_name_t = char[SOL_FILE_ID_SIZE_I_];

		inline const std::string& default_chunk_name() {
			static const std::string name = "";
			return name;
		}

		template <std::size_t N>
		const char* make_chunk_name(const string_view& code, const std::string& chunkname, char (&basechunkname)[N]) {
			if (chunkname.empty()) {
				auto it = code.cbegin();
				auto e = code.cend();
				std::size_t i = 0;
				static const std::size_t n = N - 4;
				for (i = 0; i < n && it != e; ++i, ++it) {
					basechunkname[i] = *it;
				}
				if (it != e) {
					for (std::size_t c = 0; c < 3; ++i, ++c) {
						basechunkname[i] = '.';
					}
				}
				basechunkname[i] = '\0';
				return &basechunkname[0];
			}
			else {
				return chunkname.c_str();
			}
		}

		inline void clear_entries(stack_reference r) {
			stack::push(r.lua_state(), lua_nil);
			while (lua_next(r.lua_state(), -2)) {
				absolute_index key(r.lua_state(), -2);
				auto pn = stack::pop_n(r.lua_state(), 1);
				stack::set_field<false, true>(r.lua_state(), key, lua_nil, r.stack_index());
			}
		}

		inline void clear_entries(const reference& registry_reference) {
			auto pp = stack::push_pop(registry_reference);
			stack_reference ref(registry_reference.lua_state(), -1);
			clear_entries(ref);
		}
	} // namespace detail

	namespace stack {
		namespace stack_detail {
			template <typename T>
			inline int push_as_upvalues(lua_State* L, T& item) {
				typedef std::decay_t<T> TValue;
				static const std::size_t itemsize = sizeof(TValue);
				static const std::size_t voidsize = sizeof(void*);
				static const std::size_t voidsizem1 = voidsize - 1;
				static const std::size_t data_t_count = (sizeof(TValue) + voidsizem1) / voidsize;
				typedef std::array<void*, data_t_count> data_t;

				data_t data { {} };
				std::memcpy(&data[0], std::addressof(item), itemsize);
				int pushcount = 0;
				for (const auto& v : data) {
					lua_pushlightuserdata(L, v);
					pushcount += 1;
				}
				return pushcount;
			}

			template <typename T>
			inline std::pair<T, int> get_as_upvalues(lua_State* L, int index = 2) {
				static const std::size_t data_t_count = (sizeof(T) + (sizeof(void*) - 1)) / sizeof(void*);
				typedef std::array<void*, data_t_count> data_t;
				data_t voiddata { {} };
				for (std::size_t i = 0, d = 0; d < sizeof(T); ++i, d += sizeof(void*)) {
					voiddata[i] = lua_touserdata(L, upvalue_index(index++));
				}
				return std::pair<T, int>(*reinterpret_cast<T*>(static_cast<void*>(voiddata.data())), index);
			}

			template <typename T>
			inline std::pair<T, int> get_as_upvalues_using_function(lua_State* L, int function_index = -1) {
				static const std::size_t data_t_count = (sizeof(T) + (sizeof(void*) - 1)) / sizeof(void*);
				typedef std::array<void*, data_t_count> data_t;
				function_index = lua_absindex(L, function_index);
				int index = 0;
				data_t voiddata { {} };
				for (std::size_t d = 0; d < sizeof(T); d += sizeof(void*)) {
					// first upvalue is nullptr to respect environment shenanigans
					// So +2 instead of +1
					const char* upvalue_name = lua_getupvalue(L, function_index, index + 2);
					if (upvalue_name == nullptr) {
						// We should freak out here...
						break;
					}
					voiddata[index] = lua_touserdata(L, -1);
					++index;
				}
				lua_pop(L, index);
				return std::pair<T, int>(*reinterpret_cast<T*>(static_cast<void*>(voiddata.data())), index);
			}

			template <bool checked, typename Handler, typename Fx, typename... Args>
			static decltype(auto) eval(types<>, std::index_sequence<>, lua_State*, int, Handler&&, record&, Fx&& fx, Args&&... args) {
				return std::forward<Fx>(fx)(std::forward<Args>(args)...);
			}

			template <bool checked, typename Arg, typename... Args, std::size_t I, std::size_t... Is, typename Handler, typename Fx, typename... FxArgs>
			static decltype(auto) eval(types<Arg, Args...>, std::index_sequence<I, Is...>, lua_State* L_, int start_index_, Handler&& handler_,
			     record& tracking_, Fx&& fx_, FxArgs&&... fxargs_) {
#if 0 && SOL_IS_ON(SOL_PROPAGATE_EXCEPTIONS)
				// NOTE: THIS IS TERMPORARILY TURNED OFF BECAUSE IT IMPACTS ACTUAL SEMANTICS W.R.T. THINGS LIKE LUAJIT,
				// SO IT MUST REMAIN OFF UNTIL WE CAN ESTABLISH SIMILAR BEHAVIOR IN MODES WHERE `checked == false`!

				// We can save performance/time by letting errors unwind produced arguments
				// rather than checking everything once, and then potentially re-doing work
				if constexpr (checked) {
					return eval<checked>(types<Args...>(),
					     std::index_sequence<Is...>(),
					     L_,
					     start_index_,
					     std::forward<Handler>(handler_),
					     tracking_,
					     std::forward<Fx>(fx_),
					     std::forward<FxArgs>(fxargs_)...,
					     *stack_detail::check_get_arg<Arg>(L_, start_index_ + tracking_.used, handler_, tracking_));
				}
				else
#endif
				{
					return eval<checked>(types<Args...>(),
					     std::index_sequence<Is...>(),
					     L_,
					     start_index_,
					     std::forward<Handler>(handler_),
					     tracking_,
					     std::forward<Fx>(fx_),
					     std::forward<FxArgs>(fxargs_)...,
					     stack_detail::unchecked_get_arg<Arg>(L_, start_index_ + tracking_.used, tracking_));
				}
			}

			template <bool checkargs = detail::default_safe_function_calls, std::size_t... I, typename R, typename... Args, typename Fx, typename... FxArgs>
			inline decltype(auto) call(types<R>, types<Args...> argument_types_, std::index_sequence<I...> argument_indices_, lua_State* L_,
			     int start_index_, Fx&& fx_, FxArgs&&... args_) {
				static_assert(meta::all_v<meta::is_not_move_only<Args>...>,
				     "One of the arguments being bound is a move-only type, and it is not being taken by reference: this will break your code. Please take "
				     "a reference and std::move it manually if this was your intention.");
				argument_handler<types<R, Args...>> handler {};
				record tracking {};
#if SOL_IS_OFF(SOL_PROPAGATE_EXCEPTIONS)
				if constexpr (checkargs) {
					multi_check<Args...>(L_, start_index_, handler);
				}
#endif
				if constexpr (std::is_void_v<R>) {
					eval<checkargs>(
					     argument_types_, argument_indices_, L_, start_index_, handler, tracking, std::forward<Fx>(fx_), std::forward<FxArgs>(args_)...);
				}
				else {
					return eval<checkargs>(
					     argument_types_, argument_indices_, L_, start_index_, handler, tracking, std::forward<Fx>(fx_), std::forward<FxArgs>(args_)...);
				}
			}

			template <typename T>
			void raw_table_set(lua_State* L, T&& arg, int tableindex = -2) {
				int push_count = push(L, std::forward<T>(arg));
				SOL_ASSERT(push_count == 1);
				std::size_t unique_index = static_cast<std::size_t>(luaL_len(L, tableindex) + 1u);
				lua_rawseti(L, tableindex, static_cast<int>(unique_index));
			}

		} // namespace stack_detail

		template <typename T>
		int set_ref(lua_State* L, T&& arg, int tableindex = -2) {
			int push_count = push(L, std::forward<T>(arg));
			SOL_ASSERT(push_count == 1);
			return luaL_ref(L, tableindex);
		}

		template <bool check_args = detail::default_safe_function_calls, typename R, typename... Args, typename Fx, typename... FxArgs>
		inline decltype(auto) call(types<R> tr, types<Args...> ta, lua_State* L, int start, Fx&& fx, FxArgs&&... args) {
			using args_indices = std::make_index_sequence<sizeof...(Args)>;
			if constexpr (std::is_void_v<R>) {
				stack_detail::call<check_args>(tr, ta, args_indices(), L, start, std::forward<Fx>(fx), std::forward<FxArgs>(args)...);
			}
			else {
				return stack_detail::call<check_args>(tr, ta, args_indices(), L, start, std::forward<Fx>(fx), std::forward<FxArgs>(args)...);
			}
		}

		template <bool check_args = detail::default_safe_function_calls, typename R, typename... Args, typename Fx, typename... FxArgs>
		inline decltype(auto) call(types<R> tr, types<Args...> ta, lua_State* L, Fx&& fx, FxArgs&&... args) {
			if constexpr (std::is_void_v<R>) {
				call<check_args>(tr, ta, L, 1, std::forward<Fx>(fx), std::forward<FxArgs>(args)...);
			}
			else {
				return call<check_args>(tr, ta, L, 1, std::forward<Fx>(fx), std::forward<FxArgs>(args)...);
			}
		}

		template <bool check_args = detail::default_safe_function_calls, typename R, typename... Args, typename Fx, typename... FxArgs>
		inline decltype(auto) call_from_top(types<R> tr, types<Args...> ta, lua_State* L, Fx&& fx, FxArgs&&... args) {
			using expected_count_t = meta::count_for_pack<lua_size, Args...>;
			if constexpr (std::is_void_v<R>) {
				call<check_args>(tr,
				     ta,
				     L,
				     (std::max)(static_cast<int>(lua_gettop(L) - expected_count_t::value), static_cast<int>(0)),
				     std::forward<Fx>(fx),
				     std::forward<FxArgs>(args)...);
			}
			else {
				return call<check_args>(tr,
				     ta,
				     L,
				     (std::max)(static_cast<int>(lua_gettop(L) - expected_count_t::value), static_cast<int>(0)),
				     std::forward<Fx>(fx),
				     std::forward<FxArgs>(args)...);
			}
		}

		template <bool check_args = detail::default_safe_function_calls, bool clean_stack = true, typename Ret0, typename... Ret, typename... Args,
		     typename Fx, typename... FxArgs>
		inline int call_into_lua(types<Ret0, Ret...> tr, types<Args...> ta, lua_State* L, int start, Fx&& fx, FxArgs&&... fxargs) {
			if constexpr (std::is_void_v<Ret0>) {
				call<check_args>(tr, ta, L, start, std::forward<Fx>(fx), std::forward<FxArgs>(fxargs)...);
				if constexpr (clean_stack) {
					lua_settop(L, 0);
				}
				return 0;
			}
			else {
				(void)tr;
				decltype(auto) r
				     = call<check_args>(types<meta::return_type_t<Ret0, Ret...>>(), ta, L, start, std::forward<Fx>(fx), std::forward<FxArgs>(fxargs)...);
				using R = meta::unqualified_t<decltype(r)>;
				using is_stack = meta::any<is_stack_based<R>, std::is_same<R, absolute_index>, std::is_same<R, ref_index>, std::is_same<R, raw_index>>;
				if constexpr (clean_stack && !is_stack::value) {
					lua_settop(L, 0);
				}
				return push_reference(L, std::forward<decltype(r)>(r));
			}
		}

		template <bool check_args = detail::default_safe_function_calls, bool clean_stack = true, typename Fx, typename... FxArgs>
		inline int call_lua(lua_State* L, int start, Fx&& fx, FxArgs&&... fxargs) {
			using traits_type = lua_bind_traits<meta::unqualified_t<Fx>>;
			using args_list = typename traits_type::args_list;
			using returns_list = typename traits_type::returns_list;
			return call_into_lua<check_args, clean_stack>(returns_list(), args_list(), L, start, std::forward<Fx>(fx), std::forward<FxArgs>(fxargs)...);
		}

		inline call_syntax get_call_syntax(lua_State* L, const string_view& key, int index) {
			if (lua_gettop(L) < 1) {
				return call_syntax::dot;
			}
			luaL_getmetatable(L, key.data());
			auto pn = pop_n(L, 1);
			if (lua_compare(L, -1, index, LUA_OPEQ) != 1) {
				return call_syntax::dot;
			}
			return call_syntax::colon;
		}

		inline void script(
		     lua_State* L, lua_Reader reader, void* data, const std::string& chunkname = detail::default_chunk_name(), load_mode mode = load_mode::any) {
			detail::typical_chunk_name_t basechunkname = {};
			const char* chunknametarget = detail::make_chunk_name("lua_Reader", chunkname, basechunkname);
			if (lua_load(L, reader, data, chunknametarget, to_string(mode).c_str()) || lua_pcall(L, 0, LUA_MULTRET, 0)) {
				lua_error(L);
			}
		}

		inline void script(
		     lua_State* L, const string_view& code, const std::string& chunkname = detail::default_chunk_name(), load_mode mode = load_mode::any) {

			detail::typical_chunk_name_t basechunkname = {};
			const char* chunknametarget = detail::make_chunk_name(code, chunkname, basechunkname);
			if (luaL_loadbufferx(L, code.data(), code.size(), chunknametarget, to_string(mode).c_str()) || lua_pcall(L, 0, LUA_MULTRET, 0)) {
				lua_error(L);
			}
		}

		inline void script_file(lua_State* L, const std::string& filename, load_mode mode = load_mode::any) {
			if (luaL_loadfilex(L, filename.c_str(), to_string(mode).c_str()) || lua_pcall(L, 0, LUA_MULTRET, 0)) {
				lua_error(L);
			}
		}

		inline void luajit_exception_handler(lua_State* L, int (*handler)(lua_State*, lua_CFunction) = detail::c_trampoline) {
#if SOL_IS_ON(SOL_USE_LUAJIT_EXCEPTION_TRAMPOLINE)
			if (L == nullptr) {
				return;
			}
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L, 1, detail::not_enough_stack_space_generic);
#endif // make sure stack doesn't overflow
			lua_pushlightuserdata(L, (void*)handler);
			auto pn = pop_n(L, 1);
			luaJIT_setmode(L, -1, LUAJIT_MODE_WRAPCFUNC | LUAJIT_MODE_ON);
#else
			(void)L;
			(void)handler;
#endif
		}

		inline void luajit_exception_off(lua_State* L) {
#if SOL_IS_ON(SOL_USE_LUAJIT_EXCEPTION_TRAMPOLINE)
			if (L == nullptr) {
				return;
			}
			luaJIT_setmode(L, -1, LUAJIT_MODE_WRAPCFUNC | LUAJIT_MODE_OFF);
#else
			(void)L;
#endif
		}

		namespace stack_detail {
			inline error get_error(lua_State* L, int target) {
				auto maybe_exc = stack::check_get<error&>(L, target);
				if (maybe_exc.has_value()) {
					return maybe_exc.value();
				}
				return error(detail::direct_error, stack::get<std::string>(L, target));
			}

			inline detail::error_exception get_error_exception(lua_State* L, int target) {
				auto maybe_exc = stack::check_get<detail::error_exception&>(L, target);
				if (maybe_exc.has_value()) {
					return maybe_exc.value();
				}
				return detail::error_exception(detail::direct_error, stack::get<std::string>(L, target));
			}
		}
	} // namespace stack
} // namespace sol

#endif // SOL_STACK_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_MAKE_REFERENCE_HPP
#define SOL_MAKE_REFERENCE_HPP

#include <sol/reference.hpp>
#include <sol/stack.hpp>

namespace sol {

	template <typename R = reference, bool should_pop = !is_stack_based_v<R>, typename T>
	R make_reference(lua_State* L, T&& value) {
		int backpedal = stack::push(L, std::forward<T>(value));
		R r = stack::get<R>(L, -backpedal);
		if (should_pop) {
			lua_pop(L, backpedal);
		}
		return r;
	}

	template <typename T, typename R = reference, bool should_pop = !is_stack_based_v<R>, typename... Args>
	R make_reference(lua_State* L, Args&&... args) {
		int backpedal = stack::push<T>(L, std::forward<Args>(args)...);
		R r = stack::get<R>(L, -backpedal);
		if (should_pop) {
			lua_pop(L, backpedal);
		}
		return r;
	}

	template <typename R = reference, bool should_pop = !is_stack_based_v<R>, typename T>
	R make_reference_userdata(lua_State* L, T&& value) {
		int backpedal = stack::push_userdata(L, std::forward<T>(value));
		R r = stack::get<R>(L, -backpedal);
		if (should_pop) {
			lua_pop(L, backpedal);
		}
		return r;
	}

	template <typename T, typename R = reference, bool should_pop = !is_stack_based_v<R>, typename... Args>
	R make_reference_userdata(lua_State* L, Args&&... args) {
		int backpedal = stack::push_userdata<T>(L, std::forward<Args>(args)...);
		R r = stack::get<R>(L, -backpedal);
		if (should_pop) {
			lua_pop(L, backpedal);
		}
		return r;
	}

} // namespace sol

#endif // SOL_MAKE_REFERENCE_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_REFERENCE_HPP
#define SOL_REFERENCE_HPP

#include <sol/types.hpp>
#include <sol/stack_reference.hpp>

#include <functional>

namespace sol {
	namespace detail {
		inline const char (&default_main_thread_name())[9] {
			static const char name[9] = "sol.\xF0\x9F\x93\x8C";
			return name;
		}
	} // namespace detail

	namespace stack {
		inline void remove(lua_State* L_, int rawindex, int count) {
			if (count < 1)
				return;
			int top = lua_gettop(L_);
			if (top < 1) {
				return;
			}
			if (rawindex == -count || top == rawindex) {
				// Slice them right off the top
				lua_pop(L_, static_cast<int>(count));
				return;
			}

			// Remove each item one at a time using stack operations
			// Probably slower, maybe, haven't benchmarked,
			// but necessary
			int index = lua_absindex(L_, rawindex);
			if (index < 0) {
				index = lua_gettop(L_) + (index + 1);
			}
			int last = index + count;
			for (int i = index; i < last; ++i) {
				lua_remove(L_, index);
			}
		}

		struct push_popper_at {
			lua_State* L;
			int index;
			int count;
			push_popper_at(lua_State* L_, int index_ = -1, int count_ = 1) : L(L_), index(index_), count(count_) {
			}
			~push_popper_at() {
				remove(L, index, count);
			}
		};

		template <bool top_level>
		struct push_popper_n {
			lua_State* L;
			int pop_count;
			push_popper_n(lua_State* L_, int pop_count_) : L(L_), pop_count(pop_count_) {
			}
			push_popper_n(const push_popper_n&) = delete;
			push_popper_n(push_popper_n&&) = default;
			push_popper_n& operator=(const push_popper_n&) = delete;
			push_popper_n& operator=(push_popper_n&&) = default;
			~push_popper_n() {
				lua_pop(L, pop_count);
			}
		};

		template <>
		struct push_popper_n<true> {
			push_popper_n(lua_State*, int) {
			}
		};

		template <bool, typename T, typename = void>
		struct push_popper {
			using Tu = meta::unqualified_t<T>;
			T m_object;
			int m_index;

			push_popper(T object_) noexcept : m_object(object_), m_index(lua_absindex(m_object.lua_state(), -m_object.push())) {
			}

			int index_of(const Tu&) const noexcept {
				return m_index;
			}

			~push_popper() {
				m_object.pop();
			}
		};

		template <typename T, typename C>
		struct push_popper<true, T, C> {
			using Tu = meta::unqualified_t<T>;

			push_popper(T) noexcept {
			}

			int index_of(const Tu&) const noexcept {
				return -1;
			}

			~push_popper() {
			}
		};

		template <typename T>
		struct push_popper<false, T, std::enable_if_t<is_stack_based_v<meta::unqualified_t<T>>>> {
			using Tu = meta::unqualified_t<T>;

			push_popper(T) noexcept {
			}

			int index_of(const Tu& object_) const noexcept {
				return object_.stack_index();
			}

			~push_popper() {
			}
		};

		template <bool, typename T, typename = void>
		struct stateless_push_popper {
			using Tu = meta::unqualified_t<T>;
			lua_State* m_L;
			T m_object;
			int m_index;

			stateless_push_popper(lua_State* L_, T object_) noexcept : m_L(L_), m_object(object_), m_index(lua_absindex(m_L, -m_object.push(m_L))) {
			}

			int index_of(const Tu&) const noexcept {
				return m_index;
			}

			~stateless_push_popper() {
				m_object.pop(m_L);
			}
		};

		template <typename T, typename C>
		struct stateless_push_popper<true, T, C> {
			using Tu = meta::unqualified_t<T>;

			stateless_push_popper(lua_State*, T) noexcept {
			}

			int index_of(lua_State*, const Tu&) const noexcept {
				return -1;
			}

			~stateless_push_popper() {
			}
		};

		template <typename T>
		struct stateless_push_popper<false, T, std::enable_if_t<is_stack_based_v<meta::unqualified_t<T>>>> {
			using Tu = meta::unqualified_t<T>;
			lua_State* m_L;

			stateless_push_popper(lua_State* L_, T) noexcept : m_L(L_) {
			}

			int index_of(const Tu& object_) const noexcept {
				return object_.stack_index();
			}

			~stateless_push_popper() {
			}
		};

		template <bool top_level = false, typename T>
		push_popper<top_level, T> push_pop(T&& x) {
			return push_popper<top_level, T>(std::forward<T>(x));
		}

		template <bool top_level = false, typename T>
		stateless_push_popper<top_level, T> push_pop(lua_State* L_, T&& object_) {
			return stateless_push_popper<top_level, T>(L_, std::forward<T>(object_));
		}

		template <typename T>
		push_popper_at push_pop_at(T&& object_) {
			int push_count = object_.push();
			lua_State* L = object_.lua_state();
			return push_popper_at(L, lua_absindex(L, -push_count), push_count);
		}

		template <bool top_level = false>
		push_popper_n<top_level> pop_n(lua_State* L_, int pop_count_) {
			return push_popper_n<top_level>(L_, pop_count_);
		}
	} // namespace stack

	inline lua_State* main_thread(lua_State* L_, lua_State* backup_if_unsupported_ = nullptr) {
#if SOL_LUA_VERSION_I_ < 502
		if (L_ == nullptr)
			return backup_if_unsupported_;
		lua_getglobal(L_, detail::default_main_thread_name());
		auto pp = stack::pop_n(L_, 1);
		if (type_of(L_, -1) == type::thread) {
			return lua_tothread(L_, -1);
		}
		return backup_if_unsupported_;
#else
		if (L_ == nullptr)
			return backup_if_unsupported_;
		lua_rawgeti(L_, LUA_REGISTRYINDEX, LUA_RIDX_MAINTHREAD);
		lua_State* Lmain = lua_tothread(L_, -1);
		lua_pop(L_, 1);
		return Lmain;
#endif // Lua 5.2+ has the main thread unqualified_getter
	}

	namespace detail {
		struct no_safety_tag {
		} inline constexpr no_safety {};

		template <bool b>
		inline lua_State* pick_main_thread(lua_State* L_, lua_State* backup_if_unsupported = nullptr) {
			(void)L_;
			(void)backup_if_unsupported;
			if (b) {
				return main_thread(L_, backup_if_unsupported);
			}
			return L_;
		}
	} // namespace detail

	class stateless_reference {
	private:
		template <bool o_main_only>
		friend class basic_reference;

		int ref = LUA_NOREF;

		int copy_ref(lua_State* L_) const noexcept {
			if (ref == LUA_NOREF)
				return LUA_NOREF;
			push(L_);
			return luaL_ref(L_, LUA_REGISTRYINDEX);
		}

		lua_State* copy_assign_ref(lua_State* L_, lua_State* rL, const stateless_reference& r) {
			if (valid(L_)) {
				deref(L_);
			}
			ref = r.copy_ref(L_);
			return rL;
		}

		lua_State* move_assign(lua_State* L_, lua_State* rL, stateless_reference&& r) {
			if (valid(L_)) {
				deref(L_);
			}
			ref = r.ref;
			r.ref = LUA_NOREF;
			return rL;
		}

	protected:
		int stack_index() const noexcept {
			return -1;
		}

		stateless_reference(lua_State* L_, global_tag_t) noexcept {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L_, 1, "not enough Lua stack space to push this reference value");
#endif // make sure stack doesn't overflow
			lua_pushglobaltable(L_);
			ref = luaL_ref(L_, LUA_REGISTRYINDEX);
		}

		stateless_reference(int raw_ref_index) noexcept : ref(raw_ref_index) {
		}

	public:
		stateless_reference() noexcept = default;
		stateless_reference(lua_nil_t) noexcept : stateless_reference() {
		}
		stateless_reference(const stack_reference& r) noexcept : stateless_reference(r.lua_state(), r.stack_index()) {
		}
		stateless_reference(stack_reference&& r) noexcept : stateless_reference(r.lua_state(), r.stack_index()) {
		}
		stateless_reference(lua_State* L_, const stateless_reference& r) noexcept {
			if (r.ref == LUA_REFNIL) {
				ref = LUA_REFNIL;
				return;
			}
			if (r.ref == LUA_NOREF || L_ == nullptr) {
				ref = LUA_NOREF;
				return;
			}
			ref = r.copy_ref(L_);
		}

		stateless_reference(lua_State* L_, stateless_reference&& r) noexcept {
			if (r.ref == LUA_REFNIL) {
				ref = LUA_REFNIL;
				return;
			}
			if (r.ref == LUA_NOREF || L_ == nullptr) {
				ref = LUA_NOREF;
				return;
			}
			ref = r.ref;
			r.ref = LUA_NOREF;
		}

		stateless_reference(lua_State* L_, const stack_reference& r) noexcept {
			if (L_ == nullptr || r.lua_state() == nullptr || r.get_type() == type::none) {
				ref = LUA_NOREF;
				return;
			}
			if (r.get_type() == type::lua_nil) {
				ref = LUA_REFNIL;
				return;
			}
			if (L_ != r.lua_state() && !detail::xmovable(L_, r.lua_state())) {
				return;
			}
			r.push(L_);
			ref = luaL_ref(L_, LUA_REGISTRYINDEX);
		}

		stateless_reference(lua_State* L_, const stateless_stack_reference& r) noexcept : stateless_reference(L_, r.stack_index()) {
		}

		stateless_reference(lua_State* L_, int index = -1) noexcept {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L_, 1, "not enough Lua stack space to push this reference value");
#endif // make sure stack doesn't overflow
			lua_pushvalue(L_, index);
			ref = luaL_ref(L_, LUA_REGISTRYINDEX);
		}
		stateless_reference(lua_State* L_, absolute_index index_) noexcept : stateless_reference(L_, index_.index) {
		}
		stateless_reference(lua_State* L_, ref_index index_) noexcept {
			lua_rawgeti(L_, LUA_REGISTRYINDEX, index_.index);
			ref = luaL_ref(L_, LUA_REGISTRYINDEX);
		}
		stateless_reference(lua_State*, lua_nil_t) noexcept {
		}

		~stateless_reference() noexcept = default;

		stateless_reference(const stateless_reference& o) noexcept = delete;
		stateless_reference& operator=(const stateless_reference& r) noexcept = delete;

		stateless_reference(stateless_reference&& o) noexcept : ref(o.ref) {
			o.ref = LUA_NOREF;
		}

		stateless_reference& operator=(stateless_reference&& o) noexcept {
			ref = o.ref;
			o.ref = LUA_NOREF;
			return *this;
		}

		int push(lua_State* L_) const noexcept {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L_, 1, "not enough Lua stack space to push this reference value");
#endif // make sure stack doesn't overflow
			lua_rawgeti(L_, LUA_REGISTRYINDEX, ref);
			return 1;
		}

		void pop(lua_State* L_, int n = 1) const noexcept {
			lua_pop(L_, n);
		}

		int registry_index() const noexcept {
			return ref;
		}

		void reset(lua_State* L_) noexcept {
			if (valid(L_)) {
				deref(L_);
			}
			ref = LUA_NOREF;
		}

		void reset(lua_State* L_, int index_) noexcept {
			reset(L_);
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L_, 1, "not enough Lua stack space to push this reference value");
#endif // make sure stack doesn't overflow
			lua_pushvalue(L_, index_);
			ref = luaL_ref(L_, LUA_REGISTRYINDEX);
		}

		bool valid(lua_State*) const noexcept {
			return !(ref == LUA_NOREF || ref == LUA_REFNIL);
		}

		const void* pointer(lua_State* L_) const noexcept {
			int si = push(L_);
			const void* vp = lua_topointer(L_, -si);
			lua_pop(L_, si);
			return vp;
		}

		type get_type(lua_State* L_) const noexcept {
			int p = push(L_);
			int result = lua_type(L_, -1);
			pop(L_, p);
			return static_cast<type>(result);
		}

		void abandon(lua_State* = nullptr) {
			ref = LUA_NOREF;
		}

		void deref(lua_State* L_) const noexcept {
			luaL_unref(L_, LUA_REGISTRYINDEX, ref);
		}

		stateless_reference copy(lua_State* L_) const noexcept {
			if (!valid(L_)) {
				return {};
			}
			return stateless_reference(copy_ref(L_));
		}

		void copy_assign(lua_State* L_, const stateless_reference& right) noexcept {
			if (valid(L_)) {
				deref(L_);
			}
			if (!right.valid(L_)) {
				return;
			}
			ref = right.copy_ref(L_);
		}

		bool equals(lua_State* L_, const stateless_reference& r) const noexcept {
			auto ppl = stack::push_pop(L_, *this);
			auto ppr = stack::push_pop(L_, r);
			return lua_compare(L_, -1, -2, LUA_OPEQ) == 1;
		}

		bool equals(lua_State* L_, const stateless_stack_reference& r) const noexcept {
			auto ppl = stack::push_pop(L_, *this);
			return lua_compare(L_, -1, r.stack_index(), LUA_OPEQ) == 1;
		}

		bool equals(lua_State* L_, lua_nil_t) const noexcept {
			return valid(L_);
		}
	};

	template <bool main_only = false>
	class basic_reference : public stateless_reference {
	private:
		template <bool o_main_only>
		friend class basic_reference;
		lua_State* luastate = nullptr; // non-owning

		template <bool r_main_only>
		void copy_assign_complex(const basic_reference<r_main_only>& r) {
			if (valid()) {
				deref();
			}
			if (r.ref == LUA_REFNIL) {
				luastate = detail::pick_main_thread < main_only && !r_main_only > (r.lua_state(), r.lua_state());
				ref = LUA_REFNIL;
				return;
			}
			if (r.ref == LUA_NOREF) {
				luastate = r.luastate;
				ref = LUA_NOREF;
				return;
			}
			if (detail::xmovable(lua_state(), r.lua_state())) {
				r.push(lua_state());
				ref = luaL_ref(lua_state(), LUA_REGISTRYINDEX);
				return;
			}
			luastate = detail::pick_main_thread < main_only && !r_main_only > (r.lua_state(), r.lua_state());
			ref = r.copy_ref();
		}

		template <bool r_main_only>
		void move_assign(basic_reference<r_main_only>&& r) {
			if (valid()) {
				deref();
			}
			if (r.ref == LUA_REFNIL) {
				luastate = detail::pick_main_thread < main_only && !r_main_only > (r.lua_state(), r.lua_state());
				ref = LUA_REFNIL;
				return;
			}
			if (r.ref == LUA_NOREF) {
				luastate = r.luastate;
				ref = LUA_NOREF;
				return;
			}
			if (detail::xmovable(lua_state(), r.lua_state())) {
				r.push(lua_state());
				ref = luaL_ref(lua_state(), LUA_REGISTRYINDEX);
				return;
			}

			luastate = detail::pick_main_thread < main_only && !r_main_only > (r.lua_state(), r.lua_state());
			ref = r.ref;
			r.ref = LUA_NOREF;
			r.luastate = nullptr;
		}

	protected:
		basic_reference(lua_State* L_, global_tag_t) noexcept : basic_reference(detail::pick_main_thread<main_only>(L_, L_), global_tag, global_tag) {
		}

		basic_reference(lua_State* L_, global_tag_t, global_tag_t) noexcept : stateless_reference(L_, global_tag), luastate(L_) {
		}

		basic_reference(lua_State* oL, const basic_reference<!main_only>& o) noexcept : stateless_reference(oL, o), luastate(oL) {
		}

		void deref() const noexcept {
			return stateless_reference::deref(lua_state());
		}

		int copy_ref() const noexcept {
			return copy_ref(lua_state());
		}

		int copy_ref(lua_State* L_) const noexcept {
			return stateless_reference::copy_ref(L_);
		}

	public:
		basic_reference() noexcept = default;
		basic_reference(lua_nil_t) noexcept : basic_reference() {
		}
		basic_reference(const stack_reference& r) noexcept : basic_reference(r.lua_state(), r.stack_index()) {
		}
		basic_reference(stack_reference&& r) noexcept : basic_reference(r.lua_state(), r.stack_index()) {
		}
		template <bool r_main_only>
		basic_reference(lua_State* L_, const basic_reference<r_main_only>& r) noexcept : luastate(detail::pick_main_thread<main_only>(L_, L_)) {
			if (r.ref == LUA_REFNIL) {
				ref = LUA_REFNIL;
				return;
			}
			if (r.ref == LUA_NOREF || lua_state() == nullptr) {
				ref = LUA_NOREF;
				return;
			}
			if (detail::xmovable(lua_state(), r.lua_state())) {
				r.push(lua_state());
				ref = luaL_ref(lua_state(), LUA_REGISTRYINDEX);
				return;
			}
			ref = r.copy_ref();
		}

		template <bool r_main_only>
		basic_reference(lua_State* L_, basic_reference<r_main_only>&& r) noexcept : luastate(detail::pick_main_thread<main_only>(L_, L_)) {
			if (r.ref == LUA_REFNIL) {
				ref = LUA_REFNIL;
				return;
			}
			if (r.ref == LUA_NOREF || lua_state() == nullptr) {
				ref = LUA_NOREF;
				return;
			}
			if (detail::xmovable(lua_state(), r.lua_state())) {
				r.push(lua_state());
				ref = luaL_ref(lua_state(), LUA_REGISTRYINDEX);
				return;
			}
			ref = r.ref;
			r.ref = LUA_NOREF;
			r.luastate = nullptr;
		}

		basic_reference(lua_State* L_, const stack_reference& r) noexcept : luastate(detail::pick_main_thread<main_only>(L_, L_)) {
			if (lua_state() == nullptr || r.lua_state() == nullptr || r.get_type() == type::none) {
				ref = LUA_NOREF;
				return;
			}
			if (r.get_type() == type::lua_nil) {
				ref = LUA_REFNIL;
				return;
			}
			if (lua_state() != r.lua_state() && !detail::xmovable(lua_state(), r.lua_state())) {
				return;
			}
			r.push(lua_state());
			ref = luaL_ref(lua_state(), LUA_REGISTRYINDEX);
		}
		basic_reference(lua_State* L_, int index = -1) noexcept : luastate(detail::pick_main_thread<main_only>(L_, L_)) {
			// use L_ to stick with that state's execution stack
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L_, 1, "not enough Lua stack space to push this reference value");
#endif // make sure stack doesn't overflow
			lua_pushvalue(L_, index);
			ref = luaL_ref(L_, LUA_REGISTRYINDEX);
		}
		basic_reference(lua_State* L_, ref_index index) noexcept : luastate(detail::pick_main_thread<main_only>(L_, L_)) {
			lua_rawgeti(lua_state(), LUA_REGISTRYINDEX, index.index);
			ref = luaL_ref(lua_state(), LUA_REGISTRYINDEX);
		}
		basic_reference(lua_State* L_, lua_nil_t) noexcept : luastate(detail::pick_main_thread<main_only>(L_, L_)) {
		}

		~basic_reference() noexcept {
			if (lua_state() == nullptr || ref == LUA_NOREF)
				return;
			deref();
		}

		basic_reference(const basic_reference& o) noexcept : stateless_reference(o.copy_ref()), luastate(o.lua_state()) {
		}

		basic_reference(basic_reference&& o) noexcept : stateless_reference(std::move(o)), luastate(o.lua_state()) {
			o.luastate = nullptr;
		}

		basic_reference(const basic_reference<!main_only>& o) noexcept
		: basic_reference(detail::pick_main_thread<main_only>(o.lua_state(), o.lua_state()), o) {
		}

		basic_reference(basic_reference<!main_only>&& o) noexcept
		: stateless_reference(std::move(o)), luastate(detail::pick_main_thread<main_only>(o.lua_state(), o.lua_state())) {
			o.luastate = nullptr;
			o.ref = LUA_NOREF;
		}

		basic_reference& operator=(basic_reference&& r) noexcept {
			move_assign(std::move(r));
			return *this;
		}

		basic_reference& operator=(const basic_reference& r) noexcept {
			copy_assign_complex(r);
			return *this;
		}

		basic_reference& operator=(basic_reference<!main_only>&& r) noexcept {
			move_assign(std::move(r));
			return *this;
		}

		basic_reference& operator=(const basic_reference<!main_only>& r) noexcept {
			copy_assign_complex(r);
			return *this;
		}

		basic_reference& operator=(const lua_nil_t&) noexcept {
			reset();
			return *this;
		}

		template <typename Super>
		basic_reference& operator=(proxy_base<Super>&& r);

		template <typename Super>
		basic_reference& operator=(const proxy_base<Super>& r);

		int push() const noexcept {
			return push(lua_state());
		}

		void reset() noexcept {
			stateless_reference::reset(luastate);
			luastate = nullptr;
		}

		int push(lua_State* L_) const noexcept {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L_, 1, "not enough Lua stack space to push this reference value");
#endif // make sure stack doesn't overflow
			if (lua_state() == nullptr) {
				lua_pushnil(L_);
				return 1;
			}
			lua_rawgeti(lua_state(), LUA_REGISTRYINDEX, ref);
			if (L_ != lua_state()) {
				lua_xmove(lua_state(), L_, 1);
			}
			return 1;
		}

		void pop() const noexcept {
			pop(lua_state());
		}

		void pop(lua_State* L_, int n = 1) const noexcept {
			stateless_reference::pop(L_, n);
		}

		int registry_index() const noexcept {
			return stateless_reference::registry_index();
		}

		bool valid() const noexcept {
			return stateless_reference::valid(lua_state());
		}

		bool valid(lua_State* L_) const noexcept {
			return stateless_reference::valid(L_);
		}

		const void* pointer() const noexcept {
			return stateless_reference::pointer(lua_state());
		}

		explicit operator bool() const noexcept {
			return valid();
		}

		type get_type() const noexcept {
			return stateless_reference::get_type(lua_state());
		}

		lua_State* lua_state() const noexcept {
			return luastate;
		}
	};

	template <bool lb, bool rb>
	inline bool operator==(const basic_reference<lb>& l, const basic_reference<rb>& r) noexcept {
		auto ppl = stack::push_pop(l);
		auto ppr = stack::push_pop(r);
		return lua_compare(l.lua_state(), -1, -2, LUA_OPEQ) == 1;
	}

	template <bool lb, bool rb>
	inline bool operator!=(const basic_reference<lb>& l, const basic_reference<rb>& r) noexcept {
		return !operator==(l, r);
	}

	template <bool lb>
	inline bool operator==(const basic_reference<lb>& l, const stack_reference& r) noexcept {
		auto ppl = stack::push_pop(l);
		return lua_compare(l.lua_state(), -1, r.stack_index(), LUA_OPEQ) == 1;
	}

	template <bool lb>
	inline bool operator!=(const basic_reference<lb>& l, const stack_reference& r) noexcept {
		return !operator==(l, r);
	}

	template <bool rb>
	inline bool operator==(const stack_reference& l, const basic_reference<rb>& r) noexcept {
		auto ppr = stack::push_pop(r);
		return lua_compare(l.lua_state(), -1, r.stack_index(), LUA_OPEQ) == 1;
	}

	template <bool rb>
	inline bool operator!=(const stack_reference& l, const basic_reference<rb>& r) noexcept {
		return !operator==(l, r);
	}

	template <bool lb>
	inline bool operator==(const basic_reference<lb>& lhs, const lua_nil_t&) noexcept {
		return !lhs.valid();
	}

	template <bool rb>
	inline bool operator==(const lua_nil_t&, const basic_reference<rb>& rhs) noexcept {
		return !rhs.valid();
	}

	template <bool lb>
	inline bool operator!=(const basic_reference<lb>& lhs, const lua_nil_t&) noexcept {
		return lhs.valid();
	}

	template <bool rb>
	inline bool operator!=(const lua_nil_t&, const basic_reference<rb>& rhs) noexcept {
		return rhs.valid();
	}

	inline bool operator==(const stateless_reference& l, const stateless_reference& r) noexcept {
		return l.registry_index() == r.registry_index();
	}

	inline bool operator!=(const stateless_reference& l, const stateless_reference& r) noexcept {
		return l.registry_index() != r.registry_index();
	}

	inline bool operator==(const stateless_reference& lhs, const lua_nil_t&) noexcept {
		return lhs.registry_index() == LUA_REFNIL;
	}

	inline bool operator==(const lua_nil_t&, const stateless_reference& rhs) noexcept {
		return rhs.registry_index() == LUA_REFNIL;
	}

	inline bool operator!=(const stateless_reference& lhs, const lua_nil_t&) noexcept {
		return lhs.registry_index() != LUA_REFNIL;
	}

	inline bool operator!=(const lua_nil_t&, const stateless_reference& rhs) noexcept {
		return rhs.registry_index() != LUA_REFNIL;
	}

	struct stateless_reference_equals : public stateless_stack_reference_equals {
		using is_transparent = std::true_type;

		stateless_reference_equals(lua_State* L_) noexcept : stateless_stack_reference_equals(L_) {
		}

		bool operator()(const lua_nil_t& lhs, const stateless_reference& rhs) const noexcept {
			return rhs.equals(lua_state(), lhs);
		}

		bool operator()(const stateless_reference& lhs, const lua_nil_t& rhs) const noexcept {
			return lhs.equals(lua_state(), rhs);
		}

		bool operator()(const stateless_reference& lhs, const stateless_reference& rhs) const noexcept {
			return lhs.equals(lua_state(), rhs);
		}
	};

	struct reference_equals : public stack_reference_equals {
		using is_transparent = std::true_type;

		template <bool rb>
		bool operator()(const lua_nil_t& lhs, const basic_reference<rb>& rhs) const noexcept {
			return lhs == rhs;
		}

		template <bool lb>
		bool operator()(const basic_reference<lb>& lhs, const lua_nil_t& rhs) const noexcept {
			return lhs == rhs;
		}

		template <bool lb, bool rb>
		bool operator()(const basic_reference<lb>& lhs, const basic_reference<rb>& rhs) const noexcept {
			return lhs == rhs;
		}

		template <bool lb>
		bool operator()(const basic_reference<lb>& lhs, const stack_reference& rhs) const noexcept {
			return lhs == rhs;
		}

		template <bool rb>
		bool operator()(const stack_reference& lhs, const basic_reference<rb>& rhs) const noexcept {
			return lhs == rhs;
		}
	};

	struct stateless_reference_hash : public stateless_stack_reference_hash {
		using argument_type = stateless_reference;
		using result_type = std::size_t;
		using is_transparent = std::true_type;

		stateless_reference_hash(lua_State* L_) noexcept : stateless_stack_reference_hash(L_) {
		}

		result_type operator()(const stateless_reference& lhs) const noexcept {
			std::hash<const void*> h;
			return h(lhs.pointer(lua_state()));
		}
	};

	struct reference_hash : public stack_reference_hash {
		using argument_type = reference;
		using result_type = std::size_t;
		using is_transparent = std::true_type;

		template <bool lb>
		result_type operator()(const basic_reference<lb>& lhs) const noexcept {
			std::hash<const void*> h;
			return h(lhs.pointer());
		}
	};
} // namespace sol

#endif // SOL_REFERENCE_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_OBJECT_BASE_HPP
#define SOL_OBJECT_BASE_HPP

#include <sol/reference.hpp>
#include <sol/stack.hpp>

namespace sol {

	template <typename ref_t>
	class basic_object_base : public ref_t {
	private:
		using base_t = ref_t;

		template <typename T>
		decltype(auto) as_stack(std::true_type) const {
			return stack::get<T>(base_t::lua_state(), base_t::stack_index());
		}

		template <typename T>
		decltype(auto) as_stack(std::false_type) const {
			base_t::push();
			return stack::pop<T>(base_t::lua_state());
		}

		template <typename T>
		bool is_stack(std::true_type) const {
			return stack::check<T>(base_t::lua_state(), base_t::stack_index(), &no_panic);
		}

		template <typename T>
		bool is_stack(std::false_type) const {
			int r = base_t::registry_index();
			if (r == LUA_REFNIL)
				return meta::any_same<meta::unqualified_t<T>, lua_nil_t, nullopt_t, std::nullptr_t>::value ? true : false;
			if (r == LUA_NOREF)
				return false;
			auto pp = stack::push_pop(*this);
			return stack::check<T>(base_t::lua_state(), -1, &no_panic);
		}

	public:
		basic_object_base() noexcept = default;
		basic_object_base(const basic_object_base&) = default;
		basic_object_base(basic_object_base&&) = default;
		basic_object_base& operator=(const basic_object_base&) = default;
		basic_object_base& operator=(basic_object_base&&) = default;
		template <typename T, typename... Args, meta::enable<meta::neg<std::is_same<meta::unqualified_t<T>, basic_object_base>>> = meta::enabler>
		basic_object_base(T&& arg, Args&&... args) : base_t(std::forward<T>(arg), std::forward<Args>(args)...) {
		}

		template <typename T>
		decltype(auto) as() const {
			return as_stack<T>(is_stack_based<base_t>());
		}

		template <typename T>
		bool is() const {
			return is_stack<T>(is_stack_based<base_t>());
		}
	};
} // namespace sol

#endif // SOL_OBJECT_BASE_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_OBJECT_HPP
#define SOL_OBJECT_HPP

#include <sol/make_reference.hpp>
#include <sol/reference.hpp>
#include <sol/stack.hpp>
#include <sol/object_base.hpp>

namespace sol {

	template <typename base_type>
	class basic_object : public basic_object_base<base_type> {
	private:
		typedef basic_object_base<base_type> base_t;

		template <bool invert_and_pop = false>
		basic_object(std::integral_constant<bool, invert_and_pop>, lua_State* L_, int index_ = -1) noexcept : base_t(L_, index_) {
			if (invert_and_pop) {
				lua_pop(L_, -index_);
			}
		}

	protected:
		basic_object(detail::no_safety_tag, lua_nil_t n) : base_t(n) {
		}
		basic_object(detail::no_safety_tag, lua_State* L_, int index_) : base_t(L_, index_) {
		}
		basic_object(detail::no_safety_tag, lua_State* L_, ref_index index_) : base_t(L_, index_) {
		}
		template <typename T,
		     meta::enable<meta::neg<meta::any_same<meta::unqualified_t<T>, basic_object>>, meta::neg<std::is_same<base_type, stack_reference>>,
		          meta::neg<std::is_same<lua_nil_t, meta::unqualified_t<T>>>, is_lua_reference<meta::unqualified_t<T>>> = meta::enabler>
		basic_object(detail::no_safety_tag, T&& r) noexcept : base_t(std::forward<T>(r)) {
		}

		template <typename T, meta::enable<is_lua_reference<meta::unqualified_t<T>>> = meta::enabler>
		basic_object(detail::no_safety_tag, lua_State* L_, T&& r) noexcept : base_t(L_, std::forward<T>(r)) {
		}

	public:
		basic_object() noexcept = default;
		template <typename T,
		     meta::enable<meta::neg<std::is_same<meta::unqualified_t<T>, basic_object>>, meta::neg<std::is_same<base_type, stack_reference>>,
		          is_lua_reference<meta::unqualified_t<T>>> = meta::enabler>
		basic_object(T&& r) : base_t(std::forward<T>(r)) {
		}
		template <typename T, meta::enable<is_lua_reference<meta::unqualified_t<T>>> = meta::enabler>
		basic_object(lua_State* L_, T&& r) : base_t(L_, std::forward<T>(r)) {
		}
		basic_object(lua_State* L_, global_tag_t t) : base_t(L_, t) {
		}
		basic_object(lua_nil_t r) : base_t(r) {
		}
		basic_object(const basic_object&) = default;
		basic_object(basic_object&&) = default;
		basic_object(const stack_reference& r) noexcept : basic_object(r.lua_state(), r.stack_index()) {
		}
		basic_object(stack_reference&& r) noexcept : basic_object(r.lua_state(), r.stack_index()) {
		}
		template <typename Super>
		basic_object(const proxy_base<Super>& r) noexcept : basic_object(r.operator basic_object()) {
		}
		template <typename Super>
		basic_object(proxy_base<Super>&& r) noexcept : basic_object(r.operator basic_object()) {
		}
		basic_object(lua_State* L_, lua_nil_t r) noexcept : base_t(L_, r) {
		}
		basic_object(lua_State* L_, int index_ = -1) noexcept : base_t(L_, index_) {
		}
		basic_object(lua_State* L_, absolute_index index_) noexcept : base_t(L_, index_) {
		}
		basic_object(lua_State* L_, raw_index index_) noexcept : base_t(L_, index_) {
		}
		basic_object(lua_State* L_, ref_index index_) noexcept : base_t(L_, index_) {
		}
		template <typename T, typename... Args>
		basic_object(lua_State* L_, in_place_type_t<T>, Args&&... args) noexcept
		: basic_object(std::integral_constant<bool, !is_stack_based<base_t>::value>(), L_, -stack::push<T>(L_, std::forward<Args>(args)...)) {
		}
		template <typename T, typename... Args>
		basic_object(lua_State* L_, in_place_t, T&& arg, Args&&... args) noexcept
		: basic_object(L_, in_place_type<T>, std::forward<T>(arg), std::forward<Args>(args)...) {
		}
		basic_object& operator=(const basic_object&) = default;
		basic_object& operator=(basic_object&&) = default;
		basic_object& operator=(const base_type& b) {
			base_t::operator=(b);
			return *this;
		}
		basic_object& operator=(base_type&& b) {
			base_t::operator=(std::move(b));
			return *this;
		}
		template <typename Super>
		basic_object& operator=(const proxy_base<Super>& r) {
			this->operator=(r.operator basic_object());
			return *this;
		}
		template <typename Super>
		basic_object& operator=(proxy_base<Super>&& r) {
			this->operator=(r.operator basic_object());
			return *this;
		}
	};

	template <typename T>
	object make_object(lua_State* L_, T&& value) {
		return make_reference<object, true>(L_, std::forward<T>(value));
	}

	template <typename T, typename... Args>
	object make_object(lua_State* L_, Args&&... args) {
		return make_reference<T, object, true>(L_, std::forward<Args>(args)...);
	}

	template <typename T>
	object make_object_userdata(lua_State* L_, T&& value) {
		return make_reference_userdata<object, true>(L_, std::forward<T>(value));
	}

	template <typename T, typename... Args>
	object make_object_userdata(lua_State* L_, Args&&... args) {
		return make_reference_userdata<T, object, true>(L_, std::forward<Args>(args)...);
	}
} // namespace sol

#endif // SOL_OBJECT_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_UNSAFE_FUNCTION_HPP
#define SOL_UNSAFE_FUNCTION_HPP

#include <sol/reference.hpp>
#include <sol/object.hpp>
#include <sol/stack.hpp>
#include <sol/function_result.hpp>
#include <sol/function_types.hpp>
#include <sol/bytecode.hpp>
#include <sol/dump_handler.hpp>
#include <cstdint>

namespace sol {
	template <typename ref_t, bool aligned = false>
	class basic_function : public basic_object<ref_t> {
	private:
		using base_t = basic_object<ref_t>;

		void luacall(std::ptrdiff_t argcount, std::ptrdiff_t resultcount) const {
			lua_call(lua_state(), static_cast<int>(argcount), static_cast<int>(resultcount));
		}

		template <std::size_t... I, typename... Ret>
		auto invoke(types<Ret...>, std::index_sequence<I...>, std::ptrdiff_t n) const {
			luacall(n, lua_size<std::tuple<Ret...>>::value);
			return stack::pop<std::tuple<Ret...>>(lua_state());
		}

		template <std::size_t I, typename Ret, meta::enable<meta::neg<std::is_void<Ret>>> = meta::enabler>
		Ret invoke(types<Ret>, std::index_sequence<I>, std::ptrdiff_t n) const {
			luacall(n, lua_size<Ret>::value);
			return stack::pop<Ret>(lua_state());
		}

		template <std::size_t I>
		void invoke(types<void>, std::index_sequence<I>, std::ptrdiff_t n) const {
			luacall(n, 0);
		}

		unsafe_function_result invoke(types<>, std::index_sequence<>, std::ptrdiff_t n) const {
			int stacksize = lua_gettop(lua_state());
			int firstreturn = (std::max)(1, stacksize - static_cast<int>(n));
			luacall(n, LUA_MULTRET);
			int poststacksize = lua_gettop(lua_state());
			int returncount = poststacksize - (firstreturn - 1);
			return unsafe_function_result(lua_state(), firstreturn, returncount);
		}

	public:
		using base_t::lua_state;

		basic_function() = default;
		template <typename T,
		     meta::enable<meta::neg<std::is_same<meta::unqualified_t<T>, basic_function>>, meta::neg<std::is_same<base_t, stack_reference>>,
		          meta::neg<std::is_same<lua_nil_t, meta::unqualified_t<T>>>, is_lua_reference<meta::unqualified_t<T>>> = meta::enabler>
		basic_function(T&& r) noexcept : base_t(std::forward<T>(r)) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			if (!is_function<meta::unqualified_t<T>>::value) {
				auto pp = stack::push_pop(*this);
				constructor_handler handler {};
				stack::check<basic_function>(lua_state(), -1, handler);
			}
#endif // Safety
		}
		basic_function(const basic_function&) = default;
		basic_function& operator=(const basic_function&) = default;
		basic_function(basic_function&&) = default;
		basic_function& operator=(basic_function&&) = default;
		basic_function(const stack_reference& r) : basic_function(r.lua_state(), r.stack_index()) {
		}
		basic_function(stack_reference&& r) : basic_function(r.lua_state(), r.stack_index()) {
		}
		basic_function(lua_nil_t n) : base_t(n) {
		}
		template <typename T, meta::enable<is_lua_reference<meta::unqualified_t<T>>> = meta::enabler>
		basic_function(lua_State* L, T&& r) : base_t(L, std::forward<T>(r)) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			auto pp = stack::push_pop(*this);
			constructor_handler handler {};
			stack::check<basic_function>(lua_state(), -1, handler);
#endif // Safety
		}
		basic_function(lua_State* L, int index = -1) : base_t(L, index) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			constructor_handler handler {};
			stack::check<basic_function>(L, index, handler);
#endif // Safety
		}
		basic_function(lua_State* L, ref_index index) : base_t(L, index) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			auto pp = stack::push_pop(*this);
			constructor_handler handler {};
			stack::check<basic_function>(lua_state(), -1, handler);
#endif // Safety
		}

		template <typename Fx>
		int dump(lua_Writer writer, void* userdata, bool strip, Fx&& on_error) const {
			this->push();
			auto ppn = stack::push_popper_n<false>(this->lua_state(), 1);
			int r = lua_dump(this->lua_state(), writer, userdata, strip ? 1 : 0);
			if (r != 0) {
				return on_error(this->lua_state(), r, writer, userdata, strip);
			}
			return r;
		}

		int dump(lua_Writer writer, void* userdata, bool strip = false) const {
			return dump(writer, userdata, strip, &dump_throw_on_error);
		}

		template <typename Container = bytecode>
		Container dump() const {
			Container bc;
			(void)dump(static_cast<lua_Writer>(&basic_insert_dump_writer<Container>), static_cast<void*>(&bc), false, &dump_panic_on_error);
			return bc;
		}

		template <typename Container = bytecode, typename Fx>
		Container dump(Fx&& on_error) const {
			Container bc;
			(void)dump(static_cast<lua_Writer>(&basic_insert_dump_writer<Container>), static_cast<void*>(&bc), false, std::forward<Fx>(on_error));
			return bc;
		}

		template <typename... Args>
		unsafe_function_result operator()(Args&&... args) const {
			return call<>(std::forward<Args>(args)...);
		}

		template <typename... Ret, typename... Args>
		decltype(auto) operator()(types<Ret...>, Args&&... args) const {
			return call<Ret...>(std::forward<Args>(args)...);
		}

		template <typename... Ret, typename... Args>
		decltype(auto) call(Args&&... args) const {
			if (!aligned) {
				base_t::push();
			}
			int pushcount = stack::multi_push_reference(lua_state(), std::forward<Args>(args)...);
			return invoke(types<Ret...>(), std::make_index_sequence<sizeof...(Ret)>(), static_cast<std::ptrdiff_t>(pushcount));
		}
	};
} // namespace sol

#endif // SOL_UNSAFE_FUNCTION_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_PROTECTED_FUNCTION_HPP
#define SOL_PROTECTED_FUNCTION_HPP

#include <sol/reference.hpp>
#include <sol/object.hpp>
#include <sol/stack.hpp>
#include <sol/protected_function_result.hpp>
#include <sol/unsafe_function.hpp>
#include <sol/protected_handler.hpp>
#include <sol/bytecode.hpp>
#include <sol/dump_handler.hpp>

#include <cstdint>
#include <algorithm>

namespace sol {

	namespace detail {
		template <bool ShouldPush_, typename Handler_>
		inline void handle_protected_exception(
		     lua_State* L_, optional<const std::exception&> maybe_ex, const char* error, detail::protected_handler<ShouldPush_, Handler_>& handler_) {
			handler_.stack_index = 0;
			if (ShouldPush_) {
				handler_.target.push(L_);
				detail::call_exception_handler(L_, maybe_ex, error);
				lua_call(L_, 1, 1);
			}
			else {
				detail::call_exception_handler(L_, maybe_ex, error);
			}
		}
	} // namespace detail

	template <typename Reference, bool Aligned = false, typename Handler = reference>
	class basic_protected_function : public basic_object<Reference> {
	private:
		using base_t = basic_object<Reference>;
		using handler_t = Handler;
		inline static constexpr bool is_stack_handler_v = is_stack_based_v<handler_t>;

		basic_protected_function(std::true_type, const basic_protected_function& other_) noexcept
		: base_t(other_), m_error_handler(other_.m_error_handler.copy(lua_state())) {
		}

		basic_protected_function(std::false_type, const basic_protected_function& other_) noexcept : base_t(other_), m_error_handler(other_.m_error_handler) {
		}

	public:
		basic_protected_function() = default;
		template <typename T,
		     meta::enable<meta::neg<std::is_same<meta::unqualified_t<T>, basic_protected_function>>,
		          meta::neg<std::is_base_of<proxy_base_tag, meta::unqualified_t<T>>>, meta::neg<std::is_same<base_t, stack_reference>>,
		          meta::neg<std::is_same<lua_nil_t, meta::unqualified_t<T>>>, is_lua_reference<meta::unqualified_t<T>>> = meta::enabler>
		basic_protected_function(T&& r) noexcept : base_t(std::forward<T>(r)), m_error_handler(get_default_handler(r.lua_state())) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			if (!is_function<meta::unqualified_t<T>>::value) {
				auto pp = stack::push_pop(*this);
				constructor_handler handler {};
				stack::check<basic_protected_function>(lua_state(), -1, handler);
			}
#endif // Safety
		}
		basic_protected_function(const basic_protected_function& other_) noexcept
		: basic_protected_function(meta::boolean<is_stateless_lua_reference_v<Handler>>(), other_) {
		}
		basic_protected_function& operator=(const basic_protected_function& other_) {
			base_t::operator=(other_);
			if constexpr (is_stateless_lua_reference_v<Handler>) {
				m_error_handler.copy_assign(lua_state(), other_.m_error_handler);
			}
			else {
				m_error_handler = other_.m_error_handler;
			}
			return *this;
		}
		basic_protected_function(basic_protected_function&&) = default;
		basic_protected_function& operator=(basic_protected_function&&) = default;
		basic_protected_function(const basic_function<base_t>& b) : basic_protected_function(b, get_default_handler(b.lua_state())) {
		}
		basic_protected_function(basic_function<base_t>&& b) : basic_protected_function(std::move(b), get_default_handler(b.lua_state())) {
		}
		basic_protected_function(const basic_function<base_t>& b, handler_t eh) : base_t(b), m_error_handler(std::move(eh)) {
		}
		basic_protected_function(basic_function<base_t>&& b, handler_t eh) : base_t(std::move(b)), m_error_handler(std::move(eh)) {
		}
		basic_protected_function(const stack_reference& r) : basic_protected_function(r.lua_state(), r.stack_index(), get_default_handler(r.lua_state())) {
		}
		basic_protected_function(stack_reference&& r) : basic_protected_function(r.lua_state(), r.stack_index(), get_default_handler(r.lua_state())) {
		}
		basic_protected_function(const stack_reference& r, handler_t eh) : basic_protected_function(r.lua_state(), r.stack_index(), std::move(eh)) {
		}
		basic_protected_function(stack_reference&& r, handler_t eh) : basic_protected_function(r.lua_state(), r.stack_index(), std::move(eh)) {
		}

		template <typename Super>
		basic_protected_function(const proxy_base<Super>& p) : basic_protected_function(p, get_default_handler(p.lua_state())) {
		}
		template <typename Super>
		basic_protected_function(proxy_base<Super>&& p) : basic_protected_function(std::move(p), get_default_handler(p.lua_state())) {
		}
		template <typename Proxy, typename HandlerReference,
		     meta::enable<std::is_base_of<proxy_base_tag, meta::unqualified_t<Proxy>>,
		          meta::neg<is_lua_index<meta::unqualified_t<HandlerReference>>>> = meta::enabler>
		basic_protected_function(Proxy&& p, HandlerReference&& eh)
		: basic_protected_function(detail::force_cast<base_t>(p), make_reference<handler_t>(p.lua_state(), std::forward<HandlerReference>(eh))) {
		}

		template <typename T, meta::enable<is_lua_reference<meta::unqualified_t<T>>> = meta::enabler>
		basic_protected_function(lua_State* L_, T&& r) : basic_protected_function(L_, std::forward<T>(r), get_default_handler(L_)) {
		}
		template <typename T, meta::enable<is_lua_reference<meta::unqualified_t<T>>> = meta::enabler>
		basic_protected_function(lua_State* L_, T&& r, handler_t eh) : base_t(L_, std::forward<T>(r)), m_error_handler(std::move(eh)) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			auto pp = stack::push_pop(*this);
			constructor_handler handler {};
			stack::check<basic_protected_function>(lua_state(), -1, handler);
#endif // Safety
		}

		basic_protected_function(lua_nil_t n) : base_t(n), m_error_handler(n) {
		}

		basic_protected_function(lua_State* L_, int index_ = -1) : basic_protected_function(L_, index_, get_default_handler(L_)) {
		}
		basic_protected_function(lua_State* L_, int index_, handler_t eh) : base_t(L_, index_), m_error_handler(std::move(eh)) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			constructor_handler handler {};
			stack::check<basic_protected_function>(L_, index_, handler);
#endif // Safety
		}
		basic_protected_function(lua_State* L_, absolute_index index_) : basic_protected_function(L_, index_, get_default_handler(L_)) {
		}
		basic_protected_function(lua_State* L_, absolute_index index_, handler_t eh) : base_t(L_, index_), m_error_handler(std::move(eh)) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			constructor_handler handler {};
			stack::check<basic_protected_function>(L_, index_, handler);
#endif // Safety
		}
		basic_protected_function(lua_State* L_, raw_index index_) : basic_protected_function(L_, index_, get_default_handler(L_)) {
		}
		basic_protected_function(lua_State* L_, raw_index index_, handler_t eh) : base_t(L_, index_), m_error_handler(std::move(eh)) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			constructor_handler handler {};
			stack::check<basic_protected_function>(L_, index_, handler);
#endif // Safety
		}
		basic_protected_function(lua_State* L_, ref_index index_) : basic_protected_function(L_, index_, get_default_handler(L_)) {
		}
		basic_protected_function(lua_State* L_, ref_index index_, handler_t eh) : base_t(L_, index_), m_error_handler(std::move(eh)) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			auto pp = stack::push_pop(*this);
			constructor_handler handler {};
			stack::check<basic_protected_function>(lua_state(), -1, handler);
#endif // Safety
		}

		using base_t::lua_state;

		template <typename Fx>
		int dump(lua_Writer writer, void* userdata_pointer_, bool strip, Fx&& on_error) const {
			this->push();
			auto ppn = stack::push_popper_n<false>(this->lua_state(), 1);
			int r = lua_dump(this->lua_state(), writer, userdata_pointer_, strip ? 1 : 0);
			if (r != 0) {
				return on_error(this->lua_state(), r, writer, userdata_pointer_, strip);
			}
			return r;
		}

		int dump(lua_Writer writer, void* userdata_pointer_, bool strip = false) const {
			return dump(writer, userdata_pointer_, strip, &dump_pass_on_error);
		}

		template <typename Container = bytecode>
		Container dump() const {
			Container bc;
			(void)dump(static_cast<lua_Writer>(&basic_insert_dump_writer<Container>), static_cast<void*>(&bc), false, &dump_throw_on_error);
			return bc;
		}

		template <typename Container = bytecode, typename Fx>
		Container dump(Fx&& on_error) const {
			Container bc;
			(void)dump(static_cast<lua_Writer>(&basic_insert_dump_writer<Container>), static_cast<void*>(&bc), false, std::forward<Fx>(on_error));
			return bc;
		}

		template <typename... Args>
		protected_function_result operator()(Args&&... args) const {
			return call<>(std::forward<Args>(args)...);
		}

		template <typename... Ret, typename... Args>
		decltype(auto) operator()(types<Ret...>, Args&&... args) const {
			return call<Ret...>(std::forward<Args>(args)...);
		}

		template <typename... Ret, typename... Args>
		decltype(auto) call(Args&&... args) const {
			if constexpr (!Aligned) {
				// we do not expect the function to already be on the stack: push it
				if (m_error_handler.valid(lua_state())) {
					detail::protected_handler<true, handler_t> h(lua_state(), m_error_handler);
					base_t::push();
					int pushcount = stack::multi_push_reference(lua_state(), std::forward<Args>(args)...);
					return invoke(types<Ret...>(), std::make_index_sequence<sizeof...(Ret)>(), pushcount, h);
				}
				else {
					detail::protected_handler<false, handler_t> h(lua_state(), m_error_handler);
					base_t::push();
					int pushcount = stack::multi_push_reference(lua_state(), std::forward<Args>(args)...);
					return invoke(types<Ret...>(), std::make_index_sequence<sizeof...(Ret)>(), pushcount, h);
				}
			}
			else {
				// the function is already on the stack at the right location
				if (m_error_handler.valid()) {
					// the handler will be pushed onto the stack manually,
					// since it's not already on the stack this means we need to push our own
					// function on the stack too and swap things to be in-place
					if constexpr (!is_stack_handler_v) {
						// so, we need to remove the function at the top and then dump the handler out ourselves
						base_t::push();
					}
					detail::protected_handler<true, handler_t> h(lua_state(), m_error_handler);
					if constexpr (!is_stack_handler_v) {
						lua_replace(lua_state(), -3);
						h.stack_index = lua_absindex(lua_state(), -2);
					}
					int pushcount = stack::multi_push_reference(lua_state(), std::forward<Args>(args)...);
					return invoke(types<Ret...>(), std::make_index_sequence<sizeof...(Ret)>(), pushcount, h);
				}
				else {
					detail::protected_handler<false, handler_t> h(lua_state(), m_error_handler);
					int pushcount = stack::multi_push_reference(lua_state(), std::forward<Args>(args)...);
					return invoke(types<Ret...>(), std::make_index_sequence<sizeof...(Ret)>(), pushcount, h);
				}
			}
		}

		~basic_protected_function() {
			if constexpr (is_stateless_lua_reference_v<handler_t>) {
				this->m_error_handler.reset(lua_state());
			}
		}

		static handler_t get_default_handler(lua_State* L_) {
			return detail::get_default_handler<handler_t, is_main_threaded_v<base_t>>(L_);
		}

		template <typename T>
		static void set_default_handler(const T& ref) {
			detail::set_default_handler(ref.lua_state(), ref);
		}

		auto get_error_handler() const noexcept {
			if constexpr (is_stateless_lua_reference_v<handler_t>) {
				if constexpr (is_stack_based_v<handler_t>) {
					return stack_reference(lua_state(), m_error_handler.stack_index());
				}
				else {
					return basic_reference<is_main_threaded_v<base_t>>(lua_state(), ref_index(m_error_handler.registry_index()));
				}
			}
			else {
				return m_error_handler;
			}
		}

		template <typename ErrorHandler_>
		void set_error_handler(ErrorHandler_&& error_handler_) noexcept {
			static_assert(!is_stack_based_v<handler_t> || is_stack_based_v<ErrorHandler_>,
			     "A stack-based error handler can only be set from a parameter that is also stack-based.");
			if constexpr (std::is_rvalue_reference_v<ErrorHandler_>) {
				m_error_handler = std::forward<ErrorHandler_>(error_handler_);
			}
			else {
				m_error_handler.copy_assign(lua_state(), std::forward<ErrorHandler_>(error_handler_));
			}
		}

		void abandon () noexcept {
			this->m_error_handler.abandon();
			base_t::abandon();
		}

	private:
		handler_t m_error_handler;

		template <bool b>
		call_status luacall(std::ptrdiff_t argcount, std::ptrdiff_t result_count_, detail::protected_handler<b, handler_t>& h) const {
			return static_cast<call_status>(lua_pcall(lua_state(), static_cast<int>(argcount), static_cast<int>(result_count_), h.stack_index));
		}

		template <std::size_t... I, bool b, typename... Ret>
		auto invoke(types<Ret...>, std::index_sequence<I...>, std::ptrdiff_t n, detail::protected_handler<b, handler_t>& h) const {
			luacall(n, sizeof...(Ret), h);
			return stack::pop<std::tuple<Ret...>>(lua_state());
		}

		template <std::size_t I, bool b, typename Ret>
		Ret invoke(types<Ret>, std::index_sequence<I>, std::ptrdiff_t n, detail::protected_handler<b, handler_t>& h) const {
			luacall(n, 1, h);
			return stack::pop<Ret>(lua_state());
		}

		template <std::size_t I, bool b>
		void invoke(types<void>, std::index_sequence<I>, std::ptrdiff_t n, detail::protected_handler<b, handler_t>& h) const {
			luacall(n, 0, h);
		}

		template <bool b>
		protected_function_result invoke(types<>, std::index_sequence<>, std::ptrdiff_t n, detail::protected_handler<b, handler_t>& h) const {
			int stacksize = lua_gettop(lua_state());
			int poststacksize = stacksize;
			int firstreturn = 1;
			int returncount = 0;
			call_status code = call_status::ok;
#if SOL_IS_ON(SOL_EXCEPTIONS) && SOL_IS_OFF(SOL_PROPAGATE_EXCEPTIONS)
			try {
#endif // No Exceptions
				firstreturn = (std::max)(1, static_cast<int>(stacksize - n - static_cast<int>(h.valid() && !is_stack_handler_v)));
				code = luacall(n, LUA_MULTRET, h);
				poststacksize = lua_gettop(lua_state()) - static_cast<int>(h.valid() && !is_stack_handler_v);
				returncount = poststacksize - (firstreturn - 1);
#if SOL_IS_ON(SOL_EXCEPTIONS) && SOL_IS_OFF(SOL_PROPAGATE_EXCEPTIONS)
			}
			// Handle C++ errors thrown from C++ functions bound inside of lua
			catch (const char* error) {
				detail::handle_protected_exception(lua_state(), optional<const std::exception&>(nullopt), error, h);
				firstreturn = lua_gettop(lua_state());
				return protected_function_result(lua_state(), firstreturn, 0, 1, call_status::runtime);
			}
			catch (const std::string& error) {
				detail::handle_protected_exception(lua_state(), optional<const std::exception&>(nullopt), error.c_str(), h);
				firstreturn = lua_gettop(lua_state());
				return protected_function_result(lua_state(), firstreturn, 0, 1, call_status::runtime);
			}
			catch (const std::exception& error) {
				detail::handle_protected_exception(lua_state(), optional<const std::exception&>(error), error.what(), h);
				firstreturn = lua_gettop(lua_state());
				return protected_function_result(lua_state(), firstreturn, 0, 1, call_status::runtime);
			}
#if SOL_IS_ON(SOL_EXCEPTIONS_CATCH_ALL)
			// LuaJIT cannot have the catchall when the safe propagation is on
			// but LuaJIT will swallow all C++ errors
			// if we don't at least catch std::exception ones
			catch (...) {
				detail::handle_protected_exception(lua_state(), optional<const std::exception&>(nullopt), detail::protected_function_error, h);
				firstreturn = lua_gettop(lua_state());
				return protected_function_result(lua_state(), firstreturn, 0, 1, call_status::runtime);
			}
#endif // Always catch edge case
#else
			// do not handle exceptions: they can be propogated into C++ and keep all type information / rich information
#endif // Exceptions vs. No Exceptions
			return protected_function_result(lua_state(), firstreturn, returncount, returncount, code);
		}
	};
} // namespace sol

#endif // SOL_FUNCTION_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_FUNCTION_HPP
#define SOL_FUNCTION_HPP

#include <sol/stack.hpp>
#include <sol/unsafe_function.hpp>
#include <sol/protected_function.hpp>
#include <sol/bytecode.hpp>
#include <functional>

namespace sol {
	template <typename... Ret, typename... Args>
	decltype(auto) stack_proxy::call(Args&&... args) {
		stack_function sf(this->lua_state(), this->stack_index());
		return sf.template call<Ret...>(std::forward<Args>(args)...);
	}

	inline protected_function_result::protected_function_result(unsafe_function_result&& o) noexcept
	: L(o.lua_state()), index(o.stack_index()), returncount(o.return_count()), popcount(o.return_count()), err(o.status()) {
		// Must be manual, otherwise destructor will screw us
		// return count being 0 is enough to keep things clean
		// but we will be thorough
		o.abandon();
	}

	inline protected_function_result& protected_function_result::operator=(unsafe_function_result&& o) noexcept {
		L = o.lua_state();
		index = o.stack_index();
		returncount = o.return_count();
		popcount = o.return_count();
		err = o.status();
		// Must be manual, otherwise destructor will screw us
		// return count being 0 is enough to keep things clean
		// but we will be thorough
		o.abandon();
		return *this;
	}

	inline unsafe_function_result::unsafe_function_result(protected_function_result&& o) noexcept
	: L(o.lua_state()), index(o.stack_index()), returncount(o.return_count()) {
		// Must be manual, otherwise destructor will screw us
		// return count being 0 is enough to keep things clean
		// but we will be thorough
		o.abandon();
	}
	inline unsafe_function_result& unsafe_function_result::operator=(protected_function_result&& o) noexcept {
		L = o.lua_state();
		index = o.stack_index();
		returncount = o.return_count();
		// Must be manual, otherwise destructor will screw us
		// return count being 0 is enough to keep things clean
		// but we will be thorough
		o.abandon();
		return *this;
	}

	namespace detail {
		template <typename... R>
		struct std_shim {
			unsafe_function lua_func_;

			std_shim(unsafe_function lua_func) : lua_func_(std::move(lua_func)) {
			}

			template <typename... Args>
			meta::return_type_t<R...> operator()(Args&&... args) {
				return lua_func_.call<R...>(std::forward<Args>(args)...);
			}
		};

		template <>
		struct std_shim<void> {
			unsafe_function lua_func_;

			std_shim(unsafe_function lua_func) : lua_func_(std::move(lua_func)) {
			}

			template <typename... Args>
			void operator()(Args&&... args) {
				lua_func_.call<void>(std::forward<Args>(args)...);
			}
		};
	} // namespace detail

	namespace stack {
		template <typename Signature>
		struct unqualified_getter<std::function<Signature>> {
			typedef meta::bind_traits<Signature> fx_t;
			typedef typename fx_t::args_list args_lists;
			typedef meta::tuple_types<typename fx_t::return_type> return_types;

			template <typename... R>
			static std::function<Signature> get_std_func(types<R...>, lua_State* L, int index) {
				detail::std_shim<R...> fx(unsafe_function(L, index));
				return fx;
			}

			static std::function<Signature> get(lua_State* L, int index, record& tracking) {
				tracking.use(1);
				type t = type_of(L, index);
				if (t == type::none || t == type::lua_nil) {
					return nullptr;
				}
				return get_std_func(return_types(), L, index);
			}
		};

		template <typename Allocator>
		struct unqualified_getter<basic_bytecode<Allocator>> {
			static basic_bytecode<Allocator> get(lua_State* L, int index, record& tracking) {
				tracking.use(1);
				stack_function sf(L, index);
				return sf.dump(&dump_panic_on_error);
			}
		};
	} // namespace stack

} // namespace sol

#endif // SOL_FUNCTION_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_USERTYPE_CORE_HPP
#define SOL_USERTYPE_CORE_HPP

#include <sol/wrapper.hpp>
#include <sol/stack.hpp>
#include <sol/types.hpp>
#include <sol/stack_reference.hpp>
#include <sol/usertype_traits.hpp>
#include <sol/inheritance.hpp>
#include <sol/raii.hpp>
#include <sol/deprecate.hpp>
#include <sol/object.hpp>
#include <sol/function_types.hpp>
#include <sol/usertype_container_launch.hpp>

#include <sstream>
#include <type_traits>

namespace sol {
	namespace u_detail {
		constexpr const lua_Integer toplevel_magic = static_cast<lua_Integer>(0xCCC2CCC1);

		constexpr const int environment_index = 1;
		constexpr const int usertype_storage_index = 2;
		constexpr const int usertype_storage_base_index = 3;
		constexpr const int exact_function_index = 4;
		constexpr const int magic_index = 5;

		constexpr const int simple_usertype_storage_index = 2;
		constexpr const int index_function_index = 3;
		constexpr const int new_index_function_index = 4;

		constexpr const int base_walking_failed_index = -32467;
		constexpr const int lookup_failed_index = -42469;

		enum class submetatable_type {
			// must be sequential
			value,
			reference,
			unique,
			const_reference,
			const_value,
			// must be LAST!
			named
		};

		inline auto make_string_view(string_view s) {
			return s;
		}

#if SOL_IS_ON(SOL_CHAR8_T)
		inline auto make_string_view(const char8_t* s) {
			return string_view(reinterpret_cast<const char*>(s));
		}
#endif

		inline auto make_string_view(call_construction) {
			return string_view(to_string(meta_function::call_function));
		}

		inline auto make_string_view(meta_function mf) {
			return string_view(to_string(mf));
		}

		inline auto make_string_view(base_classes_tag) {
			return string_view(detail::base_class_cast_key());
		}

		template <typename Arg>
		inline std::string make_string(Arg&& arg) {
			string_view s = make_string_view(arg);
			return std::string(s.data(), s.size());
		}

		inline int is_indexer(string_view s) {
			if (s == to_string(meta_function::index)) {
				return 1;
			}
			else if (s == to_string(meta_function::new_index)) {
				return 2;
			}
			return 0;
		}

		inline int is_indexer(meta_function mf) {
			if (mf == meta_function::index) {
				return 1;
			}
			else if (mf == meta_function::new_index) {
				return 2;
			}
			return 0;
		}

		inline int is_indexer(call_construction) {
			return 0;
		}
	} // namespace u_detail

	namespace detail {

		template <typename T, typename IFx, typename Fx>
		inline void insert_default_registrations(IFx&& ifx, Fx&& fx) {
			(void)ifx;
			(void)fx;
			if constexpr (is_automagical<T>::value) {
				if (fx(meta_function::less_than)) {
					if constexpr (meta::supports_op_less<T>::value) {
						lua_CFunction f = &comparsion_operator_wrap<T, std::less<>>;
						ifx(meta_function::less_than, f);
					}
				}
				if (fx(meta_function::less_than_or_equal_to)) {
					if constexpr (meta::supports_op_less_equal<T>::value) {
						lua_CFunction f = &comparsion_operator_wrap<T, std::less_equal<>>;
						ifx(meta_function::less_than_or_equal_to, f);
					}
				}
				if (fx(meta_function::equal_to)) {
					if constexpr (meta::supports_op_equal<T>::value) {
						lua_CFunction f = &comparsion_operator_wrap<T, std::equal_to<>>;
						ifx(meta_function::equal_to, f);
					}
					else {
						lua_CFunction f = &comparsion_operator_wrap<T, no_comp>;
						ifx(meta_function::equal_to, f);
					}
				}
				if (fx(meta_function::pairs)) {
					ifx(meta_function::pairs, &container_detail::u_c_launch<as_container_t<T>>::pairs_call);
				}
				if (fx(meta_function::length)) {
					if constexpr (meta::has_size<const T>::value || meta::has_size<T>::value) {
						auto f = &default_size<T>;
						ifx(meta_function::length, f);
					}
				}
				if (fx(meta_function::to_string)) {
					if constexpr (is_to_stringable_v<T>) {
						if constexpr (!meta::is_probably_stateless_lambda_v<T> && !std::is_member_pointer_v<T>) {
							auto f = &detail::static_trampoline<&default_to_string<T>>;
							ifx(meta_function::to_string, f);
						}
					}
				}
				if (fx(meta_function::call_function)) {
					if constexpr (is_callable_v<T>) {
						if constexpr (meta::call_operator_deducible_v<T>) {
							auto f = &c_call<decltype(&T::operator()), &T::operator()>;
							ifx(meta_function::call_function, f);
						}
					}
				}
			}
		}
	} // namespace detail

	namespace stack { namespace stack_detail {
		template <typename X>
		void set_undefined_methods_on(stack_reference t) {
			using T = std::remove_pointer_t<X>;

			lua_State* L = t.lua_state();

			t.push();

			detail::lua_reg_table l {};
			int index = 0;
			detail::indexed_insert insert_fx(l, index);
			detail::insert_default_registrations<T>(insert_fx, detail::property_always_true);
			if constexpr (!std::is_pointer_v<X>) {
				l[index] = luaL_Reg { to_string(meta_function::garbage_collect).c_str(), detail::make_destructor<T>() };
			}
			luaL_setfuncs(L, l, 0);

			// __type table
			lua_createtable(L, 0, 2);
			const std::string& name = detail::demangle<T>();
			lua_pushlstring(L, name.c_str(), name.size());
			lua_setfield(L, -2, "name");
			lua_CFunction is_func = &detail::is_check<T>;
			lua_pushcclosure(L, is_func, 0);
			lua_setfield(L, -2, "is");
			lua_setfield(L, t.stack_index(), to_string(meta_function::type).c_str());

			t.pop();
		}
	}} // namespace stack::stack_detail
} // namespace sol

#endif // SOL_USERTYPE_CORE_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_USERTYPE_CONTAINER_LAUNCH_HPP
#define SOL_USERTYPE_CONTAINER_LAUNCH_HPP

#include <sol/stack.hpp>
#include <sol/usertype_container.hpp>

#include <unordered_map>

namespace sol {

	namespace container_detail {
		template <typename X>
		struct u_c_launch {
			using T = std::remove_pointer_t<meta::unqualified_t<X>>;
			using uc = usertype_container<T>;
			using default_uc = usertype_container_default<T>;

			static inline int real_index_get_traits(std::true_type, lua_State* L) {
				return uc::index_get(L);
			}

			static inline int real_index_get_traits(std::false_type, lua_State* L) {
				return default_uc::index_get(L);
			}

			static inline int real_index_call(lua_State* L) {
				static const std::unordered_map<string_view, lua_CFunction> calls {
					{ "at", &real_at_call },
					{ "get", &real_get_call },
					{ "set", &real_set_call },
					{ "size", &real_length_call },
					{ "add", &real_add_call },
					{ "empty", &real_empty_call },
					{ "insert", &real_insert_call },
					{ "clear", &real_clear_call },
					{ "find", &real_find_call },
					{ "index_of", &real_index_of_call },
					{ "erase", &real_erase_call },
					{ "pairs", &pairs_call },
					{ "next", &next_call },
				};
				auto maybenameview = stack::unqualified_check_get<string_view>(L, 2);
				if (maybenameview) {
					const string_view& name = *maybenameview;
					auto it = calls.find(name);
					if (it != calls.cend()) {
						return stack::push(L, it->second);
					}
				}
				return real_index_get_traits(container_detail::has_traits_index_get<uc>(), L);
			}

			static inline int real_at_traits(std::true_type, lua_State* L) {
				return uc::at(L);
			}

			static inline int real_at_traits(std::false_type, lua_State* L) {
				return default_uc::at(L);
			}

			static inline int real_at_call(lua_State* L) {
				return real_at_traits(container_detail::has_traits_at<uc>(), L);
			}

			static inline int real_get_traits(std::true_type, lua_State* L) {
				return uc::get(L);
			}

			static inline int real_get_traits(std::false_type, lua_State* L) {
				return default_uc::get(L);
			}

			static inline int real_get_call(lua_State* L) {
				return real_get_traits(container_detail::has_traits_get<uc>(), L);
			}

			static inline int real_set_traits(std::true_type, lua_State* L) {
				return uc::set(L);
			}

			static inline int real_set_traits(std::false_type, lua_State* L) {
				return default_uc::set(L);
			}

			static inline int real_set_call(lua_State* L) {
				return real_set_traits(container_detail::has_traits_set<uc>(), L);
			}

			static inline int real_index_set_traits(std::true_type, lua_State* L) {
				return uc::index_set(L);
			}

			static inline int real_index_set_traits(std::false_type, lua_State* L) {
				return default_uc::index_set(L);
			}

			static inline int real_new_index_call(lua_State* L) {
				return real_index_set_traits(container_detail::has_traits_index_set<uc>(), L);
			}

			static inline int real_pairs_traits(std::true_type, lua_State* L) {
				return uc::pairs(L);
			}

			static inline int real_pairs_traits(std::false_type, lua_State* L) {
				return default_uc::pairs(L);
			}

			static inline int real_pairs_call(lua_State* L) {
				return real_pairs_traits(container_detail::has_traits_pairs<uc>(), L);
			}

			static inline int real_ipairs_traits(std::true_type, lua_State* L) {
				return uc::ipairs(L);
			}

			static inline int real_ipairs_traits(std::false_type, lua_State* L) {
				return default_uc::ipairs(L);
			}

			static inline int real_ipairs_call(lua_State* L) {
				return real_ipairs_traits(container_detail::has_traits_ipairs<uc>(), L);
			}

			static inline int real_next_traits(std::true_type, lua_State* L) {
				return uc::next(L);
			}

			static inline int real_next_traits(std::false_type, lua_State* L) {
				return default_uc::next(L);
			}

			static inline int real_next_call(lua_State* L) {
				return real_next_traits(container_detail::has_traits_next<uc>(), L);
			}

			static inline int real_size_traits(std::true_type, lua_State* L) {
				return uc::size(L);
			}

			static inline int real_size_traits(std::false_type, lua_State* L) {
				return default_uc::size(L);
			}

			static inline int real_length_call(lua_State* L) {
				return real_size_traits(container_detail::has_traits_size<uc>(), L);
			}

			static inline int real_add_traits(std::true_type, lua_State* L) {
				return uc::add(L);
			}

			static inline int real_add_traits(std::false_type, lua_State* L) {
				return default_uc::add(L);
			}

			static inline int real_add_call(lua_State* L) {
				return real_add_traits(container_detail::has_traits_add<uc>(), L);
			}

			static inline int real_insert_traits(std::true_type, lua_State* L) {
				return uc::insert(L);
			}

			static inline int real_insert_traits(std::false_type, lua_State* L) {
				return default_uc::insert(L);
			}

			static inline int real_insert_call(lua_State* L) {
				return real_insert_traits(container_detail::has_traits_insert<uc>(), L);
			}

			static inline int real_clear_traits(std::true_type, lua_State* L) {
				return uc::clear(L);
			}

			static inline int real_clear_traits(std::false_type, lua_State* L) {
				return default_uc::clear(L);
			}

			static inline int real_clear_call(lua_State* L) {
				return real_clear_traits(container_detail::has_traits_clear<uc>(), L);
			}

			static inline int real_empty_traits(std::true_type, lua_State* L) {
				return uc::empty(L);
			}

			static inline int real_empty_traits(std::false_type, lua_State* L) {
				return default_uc::empty(L);
			}

			static inline int real_empty_call(lua_State* L) {
				return real_empty_traits(container_detail::has_traits_empty<uc>(), L);
			}

			static inline int real_erase_traits(std::true_type, lua_State* L) {
				return uc::erase(L);
			}

			static inline int real_erase_traits(std::false_type, lua_State* L) {
				return default_uc::erase(L);
			}

			static inline int real_erase_call(lua_State* L) {
				return real_erase_traits(container_detail::has_traits_erase<uc>(), L);
			}

			static inline int real_find_traits(std::true_type, lua_State* L) {
				return uc::find(L);
			}

			static inline int real_find_traits(std::false_type, lua_State* L) {
				return default_uc::find(L);
			}

			static inline int real_find_call(lua_State* L) {
				return real_find_traits(container_detail::has_traits_find<uc>(), L);
			}

			static inline int real_index_of_call(lua_State* L) {
				if constexpr (container_detail::has_traits_index_of<uc>()) {
					return uc::index_of(L);
				}
				else {
					return default_uc::index_of(L);
				}
			}

			static inline int add_call(lua_State* L) {
				return detail::typed_static_trampoline<decltype(&real_add_call), (&real_add_call)>(L);
			}

			static inline int erase_call(lua_State* L) {
				return detail::typed_static_trampoline<decltype(&real_erase_call), (&real_erase_call)>(L);
			}

			static inline int insert_call(lua_State* L) {
				return detail::typed_static_trampoline<decltype(&real_insert_call), (&real_insert_call)>(L);
			}

			static inline int clear_call(lua_State* L) {
				return detail::typed_static_trampoline<decltype(&real_clear_call), (&real_clear_call)>(L);
			}

			static inline int empty_call(lua_State* L) {
				return detail::typed_static_trampoline<decltype(&real_empty_call), (&real_empty_call)>(L);
			}

			static inline int find_call(lua_State* L) {
				return detail::typed_static_trampoline<decltype(&real_find_call), (&real_find_call)>(L);
			}

			static inline int index_of_call(lua_State* L) {
				return detail::typed_static_trampoline<decltype(&real_index_of_call), (&real_index_of_call)>(L);
			}

			static inline int length_call(lua_State* L) {
				return detail::typed_static_trampoline<decltype(&real_length_call), (&real_length_call)>(L);
			}

			static inline int pairs_call(lua_State* L) {
				return detail::typed_static_trampoline<decltype(&real_pairs_call), (&real_pairs_call)>(L);
			}

			static inline int ipairs_call(lua_State* L) {
				return detail::typed_static_trampoline<decltype(&real_ipairs_call), (&real_ipairs_call)>(L);
			}

			static inline int next_call(lua_State* L) {
				return detail::typed_static_trampoline<decltype(&real_next_call), (&real_next_call)>(L);
			}

			static inline int at_call(lua_State* L) {
				return detail::typed_static_trampoline<decltype(&real_at_call), (&real_at_call)>(L);
			}

			static inline int get_call(lua_State* L) {
				return detail::typed_static_trampoline<decltype(&real_get_call), (&real_get_call)>(L);
			}

			static inline int set_call(lua_State* L) {
				return detail::typed_static_trampoline<decltype(&real_set_call), (&real_set_call)>(L);
			}

			static inline int index_call(lua_State* L) {
				return detail::typed_static_trampoline<decltype(&real_index_call), (&real_index_call)>(L);
			}

			static inline int new_index_call(lua_State* L) {
				return detail::typed_static_trampoline<decltype(&real_new_index_call), (&real_new_index_call)>(L);
			}
		};
	} // namespace container_detail

	namespace stack {
		namespace stack_detail {
			template <typename T, bool is_shim = false>
			struct metatable_setup {
				lua_State* L;

				metatable_setup(lua_State* L) : L(L) {
				}

				void operator()() {
					using meta_usertype_container
					     = container_detail::u_c_launch<meta::conditional_t<is_shim, as_container_t<std::remove_pointer_t<T>>, std::remove_pointer_t<T>>>;
					static const char* metakey
					     = is_shim ? &usertype_traits<as_container_t<std::remove_pointer_t<T>>>::metatable()[0] : &usertype_traits<T>::metatable()[0];
					static const std::array<luaL_Reg, 20> reg = { {
						// clang-format off
						{ "__pairs", &meta_usertype_container::pairs_call },
						{ "__ipairs", &meta_usertype_container::ipairs_call },
						{ "__len", &meta_usertype_container::length_call },
						{ "__index", &meta_usertype_container::index_call },
						{ "__newindex", &meta_usertype_container::new_index_call },
						{ "pairs", &meta_usertype_container::pairs_call },
						{ "next", &meta_usertype_container::next_call },
						{ "at", &meta_usertype_container::at_call },
						{ "get", &meta_usertype_container::get_call },
						{ "set", &meta_usertype_container::set_call },
						{ "size", &meta_usertype_container::length_call },
						{ "empty", &meta_usertype_container::empty_call },
						{ "clear", &meta_usertype_container::clear_call },
						{ "insert", &meta_usertype_container::insert_call },
						{ "add", &meta_usertype_container::add_call },
						{ "find", &meta_usertype_container::find_call },
						{ "index_of", &meta_usertype_container::index_of_call },
						{ "erase", &meta_usertype_container::erase_call },
						std::is_pointer<T>::value ? luaL_Reg{ nullptr, nullptr } : luaL_Reg{ "__gc", &detail::usertype_alloc_destroy<T> },
						{ nullptr, nullptr }
						// clang-format on
					} };

					if (luaL_newmetatable(L, metakey) == 1) {
						luaL_setfuncs(L, reg.data(), 0);
					}
					lua_setmetatable(L, -2);
				}
			};
		} // namespace stack_detail

		template <typename T>
		struct unqualified_pusher<as_container_t<T>> {
			using C = meta::unqualified_t<T>;

			static int push_lvalue(std::true_type, lua_State* L, const C& cont) {
				stack_detail::metatable_setup<C*, true> fx(L);
				return stack::push<detail::as_pointer_tag<const C>>(L, detail::with_function_tag(), fx, detail::ptr(cont));
			}

			static int push_lvalue(std::false_type, lua_State* L, const C& cont) {
				stack_detail::metatable_setup<C, true> fx(L);
				return stack::push<detail::as_value_tag<C>>(L, detail::with_function_tag(), fx, cont);
			}

			static int push_rvalue(std::true_type, lua_State* L, C&& cont) {
				stack_detail::metatable_setup<C, true> fx(L);
				return stack::push<detail::as_value_tag<C>>(L, detail::with_function_tag(), fx, std::move(cont));
			}

			static int push_rvalue(std::false_type, lua_State* L, const C& cont) {
				return push_lvalue(std::is_lvalue_reference<T>(), L, cont);
			}

			static int push(lua_State* L, const as_container_t<T>& as_cont) {
				return push_lvalue(std::is_lvalue_reference<T>(), L, as_cont.value());
			}

			static int push(lua_State* L, as_container_t<T>&& as_cont) {
				return push_rvalue(meta::all<std::is_rvalue_reference<T>, meta::neg<std::is_lvalue_reference<T>>>(), L, std::forward<T>(as_cont.value()));
			}
		};

		template <typename T>
		struct unqualified_pusher<as_container_t<T*>> {
			using C = std::add_pointer_t<meta::unqualified_t<std::remove_pointer_t<T>>>;

			static int push(lua_State* L, T* cont) {
				stack_detail::metatable_setup<C> fx(L);
				return stack::push<detail::as_pointer_tag<T>>(L, detail::with_function_tag(), fx, cont);
			}
		};

		template <typename T>
		struct unqualified_pusher<T, std::enable_if_t<is_container_v<T>>> {
			using C = T;

			template <typename... Args>
			static int push(lua_State* L, Args&&... args) {
				stack_detail::metatable_setup<C> fx(L);
				return stack::push<detail::as_value_tag<T>>(L, detail::with_function_tag(), fx, std::forward<Args>(args)...);
			}
		};

		template <typename T>
		struct unqualified_pusher<T*, std::enable_if_t<is_container_v<T>>> {
			using C = std::add_pointer_t<meta::unqualified_t<std::remove_pointer_t<T>>>;

			static int push(lua_State* L, T* cont) {
				stack_detail::metatable_setup<C> fx(L);
				return stack::push<detail::as_pointer_tag<T>>(L, detail::with_function_tag(), fx, cont);
			}
		};
	} // namespace stack

} // namespace sol

#endif // SOL_USERTYPE_CONTAINER_LAUNCH_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_USERTYPE_STORAGE_HPP
#define SOL_USERTYPE_STORAGE_HPP

#include <sol/usertype_core.hpp>
#include <sol/make_reference.hpp>

#include <bitset>
#include <unordered_map>
#include <memory>

namespace sol { namespace u_detail {

	struct usertype_storage_base;
	template <typename T>
	struct usertype_storage;

	optional<usertype_storage_base&> maybe_get_usertype_storage_base(lua_State* L_, int index);
	usertype_storage_base& get_usertype_storage_base(lua_State* L_, const char* gcmetakey);
	template <typename T>
	optional<usertype_storage<T>&> maybe_get_usertype_storage(lua_State* L_);
	template <typename T>
	usertype_storage<T>& get_usertype_storage(lua_State* L_);

	using index_call_function = int(lua_State*, void*);
	using change_indexing_mem_func = void (usertype_storage_base::*)(
		lua_State*, submetatable_type, void*, stateless_stack_reference&, lua_CFunction, lua_CFunction, lua_CFunction, lua_CFunction);

	struct index_call_storage {
		index_call_function* index;
		index_call_function* new_index;
		void* binding_data;
	};

	struct new_index_call_storage : index_call_storage {
		void* new_binding_data;
	};

	struct binding_base {
		virtual void* data() = 0;
		virtual ~binding_base() {
		}
	};

	template <typename K, typename Fq, typename T = void>
	struct binding : binding_base {
		using uF = meta::unqualified_t<Fq>;
		using F = meta::conditional_t<meta::is_c_str_of_v<uF, char>
#if SOL_IS_ON(SOL_CHAR8_T)
			     || meta::is_c_str_of_v<uF, char8_t>
#endif
			     || meta::is_c_str_of_v<uF, char16_t> || meta::is_c_str_of_v<uF, char32_t> || meta::is_c_str_of_v<uF, wchar_t>,
			std::add_pointer_t<std::add_const_t<std::remove_all_extents_t<Fq>>>, std::decay_t<Fq>>;
		F data_;

		template <typename... Args>
		binding(Args&&... args) : data_(std::forward<Args>(args)...) {
		}

		virtual void* data() override {
			return static_cast<void*>(std::addressof(data_));
		}

		template <bool is_index = true, bool is_variable = false>
		static inline int call_with_(lua_State* L_, void* target) {
			constexpr int boost = !detail::is_non_factory_constructor<F>::value && std::is_same<K, call_construction>::value ? 1 : 0;
			auto& f = *static_cast<F*>(target);
			return call_detail::call_wrapped<T, is_index, is_variable, boost>(L_, f);
		}

		template <bool is_index = true, bool is_variable = false>
		static inline int call_(lua_State* L_) {
			void* f = stack::get<void*>(L_, upvalue_index(usertype_storage_index));
			return call_with_<is_index, is_variable>(L_, f);
		}

		template <bool is_index = true, bool is_variable = false>
		static inline int call(lua_State* L_) {
			int r = detail::typed_static_trampoline<decltype(&call_<is_index, is_variable>), (&call_<is_index, is_variable>)>(L_);
			if constexpr (meta::is_specialization_of_v<uF, yielding_t>) {
				return lua_yield(L_, r);
			}
			else {
				return r;
			}
		}

		template <bool is_index = true, bool is_variable = false>
		static inline int index_call_with_(lua_State* L_, void* target) {
			if constexpr (!is_variable) {
				if constexpr (is_lua_c_function_v<std::decay_t<F>>) {
					auto& f = *static_cast<std::decay_t<F>*>(target);
					return stack::push(L_, f);
				}
				else {
					// set up upvalues
					// for a chained call
					int upvalues = 0;
					upvalues += stack::push(L_, nullptr);
					upvalues += stack::push(L_, target);
					auto cfunc = &call<is_index, is_variable>;
					return stack::push(L_, c_closure(cfunc, upvalues));
				}
			}
			else {
				constexpr int boost = !detail::is_non_factory_constructor<F>::value && std::is_same<K, call_construction>::value ? 1 : 0;
				auto& f = *static_cast<F*>(target);
				return call_detail::call_wrapped<T, is_index, is_variable, boost>(L_, f);
			}
		}

		template <bool is_index = true, bool is_variable = false>
		static inline int index_call_(lua_State* L_) {
			void* f = stack::get<void*>(L_, upvalue_index(usertype_storage_index));
			return index_call_with_<is_index, is_variable>(L_, f);
		}

		template <bool is_index = true, bool is_variable = false>
		static inline int index_call(lua_State* L_) {
			int r = detail::typed_static_trampoline<decltype(&index_call_<is_index, is_variable>), (&index_call_<is_index, is_variable>)>(L_);
			if constexpr (meta::is_specialization_of_v<uF, yielding_t>) {
				return lua_yield(L_, r);
			}
			else {
				return r;
			}
		}
	};

	inline int index_fail(lua_State* L_) {
		if (lua_getmetatable(L_, 1) == 1) {
			int metatarget = lua_gettop(L_);
			stack::get_field<false, true>(L_, stack_reference(L_, raw_index(2)), metatarget);
			return 1;
		}
		// With runtime extensibility, we can't
		// hard-error things. They have to
		// return nil, like regular table types
		return stack::push(L_, lua_nil);
	}

	inline int index_target_fail(lua_State* L_, void*) {
		return index_fail(L_);
	}

	inline int new_index_fail(lua_State* L_) {
		return luaL_error(L_, "sol: cannot set (new_index) into this object: no defined new_index operation on usertype");
	}

	inline int new_index_target_fail(lua_State* L_, void*) {
		return new_index_fail(L_);
	}

	struct string_for_each_metatable_func {
		bool is_destruction = false;
		bool is_index = false;
		bool is_new_index = false;
		bool is_static_index = false;
		bool is_static_new_index = false;
		bool poison_indexing = false;
		bool is_unqualified_lua_CFunction = false;
		bool is_unqualified_lua_reference = false;
		std::string* p_key = nullptr;
		reference* p_binding_ref = nullptr;
		lua_CFunction call_func = nullptr;
		index_call_storage* p_ics = nullptr;
		usertype_storage_base* p_usb = nullptr;
		void* p_derived_usb = nullptr;
		lua_CFunction idx_call = nullptr, new_idx_call = nullptr, meta_idx_call = nullptr, meta_new_idx_call = nullptr;
		change_indexing_mem_func change_indexing;

		void operator()(lua_State* L_, submetatable_type smt_, stateless_reference& fast_index_table_) {
			std::string& key = *p_key;
			usertype_storage_base& usb = *p_usb;
			index_call_storage& ics = *p_ics;

			if (smt_ == submetatable_type::named) {
				// do not override __call or
				// other specific meta functions on named metatable:
				// we need that for call construction
				// and other amenities
				return;
			}
			int fast_index_table_push = fast_index_table_.push(L_);
			stateless_stack_reference t(L_, -fast_index_table_push);
			if (poison_indexing) {
				(usb.*change_indexing)(L_, smt_, p_derived_usb, t, idx_call, new_idx_call, meta_idx_call, meta_new_idx_call);
			}
			if (is_destruction
				&& (smt_ == submetatable_type::reference || smt_ == submetatable_type::const_reference || smt_ == submetatable_type::named
				     || smt_ == submetatable_type::unique)) {
				// gc does not apply to us here
				// for reference types (raw T*, std::ref)
				// for the named metatable itself,
				// or for unique_usertypes, which do their own custom destroyion
				t.pop(L_);
				return;
			}
			if (is_index || is_new_index || is_static_index || is_static_new_index) {
				// do not serialize the new_index and index functions here directly
				// we control those...
				t.pop(L_);
				return;
			}
			if (is_unqualified_lua_CFunction) {
				stack::set_field<false, true>(L_, key, call_func, t.stack_index());
			}
			else if (is_unqualified_lua_reference) {
				reference& binding_ref = *p_binding_ref;
				stack::set_field<false, true>(L_, key, binding_ref, t.stack_index());
			}
			else {
				stack::set_field<false, true>(L_, key, make_closure(call_func, nullptr, ics.binding_data), t.stack_index());
			}
			t.pop(L_);
		}
	};

	struct lua_reference_func {
		reference key;
		reference value;

		void operator()(lua_State* L_, submetatable_type smt_, stateless_reference& fast_index_table_) {
			if (smt_ == submetatable_type::named) {
				return;
			}
			int fast_index_table_push = fast_index_table_.push(L_);
			stateless_stack_reference t(L_, -fast_index_table_push);
			stack::set_field<false, true>(L_, key, value, t.stack_index());
			t.pop(L_);
		}
	};

	struct update_bases_func {
		detail::inheritance_check_function base_class_check_func;
		detail::inheritance_cast_function base_class_cast_func;
		lua_CFunction idx_call, new_idx_call, meta_idx_call, meta_new_idx_call;
		usertype_storage_base* p_usb;
		void* p_derived_usb;
		change_indexing_mem_func change_indexing;

		void operator()(lua_State* L_, submetatable_type smt_, stateless_reference& fast_index_table_) {
			int fast_index_table_push = fast_index_table_.push(L_);
			stateless_stack_reference t(L_, -fast_index_table_push);
			stack::set_field(L_, detail::base_class_check_key(), reinterpret_cast<void*>(base_class_check_func), t.stack_index());
			stack::set_field(L_, detail::base_class_cast_key(), reinterpret_cast<void*>(base_class_cast_func), t.stack_index());
			// change indexing, forcefully
			(p_usb->*change_indexing)(L_, smt_, p_derived_usb, t, idx_call, new_idx_call, meta_idx_call, meta_new_idx_call);
			t.pop(L_);
		}
	};

	struct binding_data_equals {
		void* binding_data;

		binding_data_equals(void* b) : binding_data(b) {
		}

		bool operator()(const std::unique_ptr<binding_base>& ptr) const {
			return binding_data == ptr->data();
		}
	};

	struct usertype_storage_base {
	public:
		lua_State* m_L;
		std::vector<std::unique_ptr<binding_base>> storage;
		std::vector<std::unique_ptr<char[]>> string_keys_storage;
		std::unordered_map<string_view, index_call_storage> string_keys;
		std::unordered_map<stateless_reference, stateless_reference, stateless_reference_hash, stateless_reference_equals> auxiliary_keys;
		stateless_reference value_index_table;
		stateless_reference reference_index_table;
		stateless_reference unique_index_table;
		stateless_reference const_reference_index_table;
		stateless_reference const_value_index_table;
		stateless_reference named_index_table;
		stateless_reference type_table;
		stateless_reference gc_names_table;
		stateless_reference named_metatable;
		new_index_call_storage base_index;
		new_index_call_storage static_base_index;
		bool is_using_index;
		bool is_using_new_index;
		std::bitset<64> properties;

		usertype_storage_base(lua_State* L_)
		: m_L(L_)
		, storage()
		, string_keys_storage()
		, string_keys()
		, auxiliary_keys(0, stateless_reference_hash(L_), stateless_reference_equals(L_))
		, value_index_table()
		, reference_index_table()
		, unique_index_table()
		, const_reference_index_table()
		, const_value_index_table()
		, named_index_table()
		, type_table(make_reference<stateless_reference>(L_, create))
		, gc_names_table(make_reference<stateless_reference>(L_, create))
		, named_metatable(make_reference<stateless_reference>(L_, create))
		, base_index()
		, static_base_index()
		, is_using_index(false)
		, is_using_new_index(false)
		, properties() {
			base_index.binding_data = nullptr;
			base_index.index = index_target_fail;
			base_index.new_index = new_index_target_fail;
			base_index.new_binding_data = nullptr;
			static_base_index.binding_data = nullptr;
			static_base_index.index = index_target_fail;
			static_base_index.new_binding_data = this;
			static_base_index.new_index = new_index_target_set;
		}

		template <typename Fx>
		void for_each_table(lua_State* L_, Fx&& fx) {
			for (int i = 0; i < 6; ++i) {
				submetatable_type smt = static_cast<submetatable_type>(i);
				stateless_reference* p_fast_index_table = nullptr;
				switch (smt) {
				case submetatable_type::const_value:
					p_fast_index_table = &this->const_value_index_table;
					break;
				case submetatable_type::reference:
					p_fast_index_table = &this->reference_index_table;
					break;
				case submetatable_type::unique:
					p_fast_index_table = &this->unique_index_table;
					break;
				case submetatable_type::const_reference:
					p_fast_index_table = &this->const_reference_index_table;
					break;
				case submetatable_type::named:
					p_fast_index_table = &this->named_index_table;
					break;
				case submetatable_type::value:
				default:
					p_fast_index_table = &this->value_index_table;
					break;
				}
				fx(L_, smt, *p_fast_index_table);
			}
		}

		void add_entry(string_view sv, index_call_storage ics) {
			string_keys_storage.emplace_back(new char[sv.size()]);
			std::unique_ptr<char[]>& sv_storage = string_keys_storage.back();
			std::memcpy(sv_storage.get(), sv.data(), sv.size());
			string_view stored_sv(sv_storage.get(), sv.size());
			string_keys.insert_or_assign(std::move(stored_sv), std::move(ics));
		}

		template <typename T, typename... Bases>
		void update_bases(lua_State* L_, bases<Bases...>) {
			static_assert(sizeof(void*) <= sizeof(detail::inheritance_check_function),
				"The size of this data pointer is too small to fit the inheritance checking function: Please file "
				"a bug report.");
			static_assert(sizeof(void*) <= sizeof(detail::inheritance_cast_function),
				"The size of this data pointer is too small to fit the inheritance checking function: Please file "
				"a bug report.");
			static_assert(!meta::any_same<T, Bases...>::value, "base classes cannot list the original class as part of the bases");
			if constexpr (sizeof...(Bases) > 0) {
				(void)detail::swallow { 0, ((weak_derive<Bases>::value = true), 0)... };

				void* derived_this = static_cast<void*>(static_cast<usertype_storage<T>*>(this));

				update_bases_func for_each_fx;
				for_each_fx.base_class_check_func = &detail::inheritance<T>::template type_check_with<Bases...>;
				for_each_fx.base_class_cast_func = &detail::inheritance<T>::template type_cast_with<Bases...>;
				for_each_fx.idx_call = &usertype_storage<T>::template index_call_with_bases<false, Bases...>;
				for_each_fx.new_idx_call = &usertype_storage<T>::template index_call_with_bases<true, Bases...>;
				for_each_fx.meta_idx_call = &usertype_storage<T>::template meta_index_call_with_bases<false, Bases...>;
				for_each_fx.meta_new_idx_call = &usertype_storage<T>::template meta_index_call_with_bases<true, Bases...>;
				for_each_fx.p_usb = this;
				for_each_fx.p_derived_usb = derived_this;
				for_each_fx.change_indexing = &usertype_storage_base::change_indexing;
				for_each_fx.p_derived_usb = derived_this;
				this->for_each_table(L_, for_each_fx);
			}
			else {
				(void)L_;
			}
		}

		void clear() {
			if (value_index_table.valid(m_L)) {
				stack::clear(m_L, value_index_table);
			}
			if (reference_index_table.valid(m_L)) {
				stack::clear(m_L, reference_index_table);
			}
			if (unique_index_table.valid(m_L)) {
				stack::clear(m_L, unique_index_table);
			}
			if (const_reference_index_table.valid(m_L)) {
				stack::clear(m_L, const_reference_index_table);
			}
			if (const_value_index_table.valid(m_L)) {
				stack::clear(m_L, const_value_index_table);
			}
			if (named_index_table.valid(m_L)) {
				stack::clear(m_L, named_index_table);
			}
			if (type_table.valid(m_L)) {
				stack::clear(m_L, type_table);
			}
			if (gc_names_table.valid(m_L)) {
				stack::clear(m_L, gc_names_table);
			}
			if (named_metatable.valid(m_L)) {
				auto pp = stack::push_pop(m_L, named_metatable);
				int named_metatable_index = pp.index_of(named_metatable);
				if (lua_getmetatable(m_L, named_metatable_index) == 1) {
					stack::clear(m_L, absolute_index(m_L, -1));
				}
				stack::clear(m_L, named_metatable);
			}

			value_index_table.reset(m_L);
			reference_index_table.reset(m_L);
			unique_index_table.reset(m_L);
			const_reference_index_table.reset(m_L);
			const_value_index_table.reset(m_L);
			named_index_table.reset(m_L);
			type_table.reset(m_L);
			gc_names_table.reset(m_L);
			named_metatable.reset(m_L);

			storage.clear();
			string_keys.clear();
			auxiliary_keys.clear();
			string_keys_storage.clear();
		}

		template <bool is_new_index, typename Base>
		static void base_walk_index(lua_State* L_, usertype_storage_base& self, bool& keep_going, int& base_result) {
			using bases = typename base<Base>::type;
			if (!keep_going) {
				return;
			}
			(void)L_;
			(void)self;
#if SOL_IS_ON(SOL_USE_UNSAFE_BASE_LOOKUP)
			usertype_storage_base& base_storage = get_usertype_storage<Base>(L_);
			base_result = self_index_call<is_new_index, true>(bases(), L_, base_storage);
#else
			optional<usertype_storage<Base>&> maybe_base_storage = maybe_get_usertype_storage<Base>(L_);
			if (static_cast<bool>(maybe_base_storage)) {
				base_result = self_index_call<is_new_index, true>(bases(), L_, *maybe_base_storage);
				keep_going = base_result == base_walking_failed_index;
			}
#endif // Fast versus slow, safe base lookup
		}

		template <bool is_new_index = false, bool base_walking = false, bool from_named_metatable = false, typename... Bases>
		static inline int self_index_call(types<Bases...>, lua_State* L, usertype_storage_base& self) {
			if constexpr (!from_named_metatable || !is_new_index) {
				type k_type = stack::get<type>(L, 2);
				if (k_type == type::string) {
					index_call_storage* target = nullptr;
					string_view k = stack::get<string_view>(L, 2);
					{
						auto it = self.string_keys.find(k);
						if (it != self.string_keys.cend()) {
							target = &it->second;
						}
					}
					if (target != nullptr) {
						// let the target decide what to do, unless it's named...
						if constexpr (is_new_index) {
							return (target->new_index)(L, target->binding_data);
						}
						else {
							return (target->index)(L, target->binding_data);
						}
					}
				}
				else if (k_type != type::lua_nil && k_type != type::none) {
					stateless_reference* target = nullptr;
					{
						stack_reference k = stack::get<stack_reference>(L, 2);
						auto it = self.auxiliary_keys.find(k);
						if (it != self.auxiliary_keys.cend()) {
							target = &it->second;
						}
					}
					if (target != nullptr) {
						if constexpr (is_new_index) {
							// set value and return
							target->reset(L, 3);
							return 0;
						}
						else {
							// push target to return
							// what we found
							return stack::push(L, *target);
						}
					}
				}
			}

			// retrieve bases and walk through them.
			bool keep_going = true;
			int base_result;
			(void)keep_going;
			(void)base_result;
			(void)detail::swallow { 1, (base_walk_index<is_new_index, Bases>(L, self, keep_going, base_result), 1)... };
			if constexpr (sizeof...(Bases) > 0) {
				if (!keep_going) {
					return base_result;
				}
			}
			if constexpr (base_walking) {
				// if we're JUST base-walking then don't index-fail, just
				// return the false bits
				return base_walking_failed_index;
			}
			else if constexpr (from_named_metatable) {
				if constexpr (is_new_index) {
					return self.static_base_index.new_index(L, self.static_base_index.new_binding_data);
				}
				else {
					return self.static_base_index.index(L, self.static_base_index.binding_data);
				}
			}
			else {
				if constexpr (is_new_index) {
					return self.base_index.new_index(L, self.base_index.new_binding_data);
				}
				else {
					return self.base_index.index(L, self.base_index.binding_data);
				}
			}
		}

		void change_indexing(lua_State* L_, submetatable_type submetatable_, void* derived_this_, stateless_stack_reference& t_, lua_CFunction index_,
			lua_CFunction new_index_, lua_CFunction meta_index_, lua_CFunction meta_new_index_) {
			usertype_storage_base& this_base = *this;
			void* base_this = static_cast<void*>(&this_base);

			this->is_using_index |= true;
			this->is_using_new_index |= true;
			if (submetatable_ == submetatable_type::named) {
				stack::set_field(L_, metatable_key, named_index_table, t_.stack_index());
				stateless_stack_reference stack_metametatable(L_, -named_metatable.push(L_));
				stack::set_field<false, true>(L_,
					meta_function::index,
					make_closure(meta_index_, nullptr, derived_this_, base_this, nullptr, toplevel_magic),
					stack_metametatable.stack_index());
				stack::set_field<false, true>(L_,
					meta_function::new_index,
					make_closure(meta_new_index_, nullptr, derived_this_, base_this, nullptr, toplevel_magic),
					stack_metametatable.stack_index());
				stack_metametatable.pop(L_);
			}
			else {
				stack::set_field<false, true>(
					L_, meta_function::index, make_closure(index_, nullptr, derived_this_, base_this, nullptr, toplevel_magic), t_.stack_index());
				stack::set_field<false, true>(
					L_, meta_function::new_index, make_closure(new_index_, nullptr, derived_this_, base_this, nullptr, toplevel_magic), t_.stack_index());
			}
		}

		template <typename T = void, typename Key, typename Value>
		void set(lua_State* L, Key&& key, Value&& value);

		static int new_index_target_set(lua_State* L, void* target) {
			usertype_storage_base& self = *static_cast<usertype_storage_base*>(target);
			self.set(L, reference(L, raw_index(2)), reference(L, raw_index(3)));
			return 0;
		}

		~usertype_storage_base() {
			value_index_table.reset(m_L);
			reference_index_table.reset(m_L);
			unique_index_table.reset(m_L);
			const_reference_index_table.reset(m_L);
			const_value_index_table.reset(m_L);
			named_index_table.reset(m_L);
			type_table.reset(m_L);
			gc_names_table.reset(m_L);
			named_metatable.reset(m_L);

			auto auxiliary_first = auxiliary_keys.cbegin();
			auto auxiliary_last = auxiliary_keys.cend();
			while (auxiliary_first != auxiliary_last) {
				// save a copy to what we're going to destroy
				auto auxiliary_target = auxiliary_first;
				// move the iterator up by 1
				++auxiliary_first;
				// extract the node and destroy the key
				auto extracted_node = auxiliary_keys.extract(auxiliary_target);
				extracted_node.key().reset(m_L);
				extracted_node.mapped().reset(m_L);
				// continue if auxiliary_first hasn't been exhausted
			}
		}
	};

	template <typename T>
	struct usertype_storage : usertype_storage_base {

		using usertype_storage_base::usertype_storage_base;

		template <bool is_new_index, bool from_named_metatable>
		static inline int index_call_(lua_State* L) {
			using bases = typename base<T>::type;
			usertype_storage_base& self = stack::get<light<usertype_storage_base>>(L, upvalue_index(usertype_storage_index));
			return self_index_call<is_new_index, false, from_named_metatable>(bases(), L, self);
		}

		template <bool is_new_index, bool from_named_metatable, typename... Bases>
		static inline int index_call_with_bases_(lua_State* L) {
			using bases = types<Bases...>;
			usertype_storage_base& self = stack::get<light<usertype_storage_base>>(L, upvalue_index(usertype_storage_index));
			return self_index_call<is_new_index, false, from_named_metatable>(bases(), L, self);
		}

		template <bool is_new_index>
		static inline int index_call(lua_State* L) {
			return detail::static_trampoline<&index_call_<is_new_index, false>>(L);
		}

		template <bool is_new_index, typename... Bases>
		static inline int index_call_with_bases(lua_State* L) {
			return detail::static_trampoline<&index_call_with_bases_<is_new_index, false, Bases...>>(L);
		}

		template <bool is_new_index>
		static inline int meta_index_call(lua_State* L) {
			return detail::static_trampoline<&index_call_<is_new_index, true>>(L);
		}

		template <bool is_new_index, typename... Bases>
		static inline int meta_index_call_with_bases(lua_State* L) {
			return detail::static_trampoline<&index_call_with_bases_<is_new_index, true, Bases...>>(L);
		}

		template <typename Key, typename Value>
		inline void set(lua_State* L, Key&& key, Value&& value);
	};

	template <typename T, typename Key, typename Value>
	void usertype_storage_base::set(lua_State* L, Key&& key, Value&& value) {
		using ValueU = meta::unwrap_unqualified_t<Value>;
		using KeyU = meta::unwrap_unqualified_t<Key>;
		using Binding = binding<KeyU, ValueU, T>;
		using is_var_bind = is_variable_binding<ValueU>;
		if constexpr (std::is_same_v<KeyU, call_construction>) {
			(void)key;
			std::unique_ptr<Binding> p_binding = std::make_unique<Binding>(std::forward<Value>(value));
			Binding& b = *p_binding;
			this->storage.push_back(std::move(p_binding));

			this->named_index_table.push(L);
			absolute_index metametatable_index(L, -1);
			std::string_view call_metamethod_name = to_string(meta_function::call);
			lua_pushlstring(L, call_metamethod_name.data(), call_metamethod_name.size());
			stack::push(L, nullptr);
			stack::push(L, b.data());
			lua_CFunction target_func = &b.template call<false, false>;
			lua_pushcclosure(L, target_func, 2);
			lua_rawset(L, metametatable_index);
			this->named_index_table.pop(L);
		}
		else if constexpr (std::is_same_v<KeyU, base_classes_tag>) {
			(void)key;
			this->update_bases<T>(L, std::forward<Value>(value));
		}
		else if constexpr ((meta::is_string_like_or_constructible<KeyU>::value || std::is_same_v<KeyU, meta_function>)) {
			std::string s = u_detail::make_string(std::forward<Key>(key));
			auto storage_it = this->storage.end();
			auto string_it = this->string_keys.find(s);
			if (string_it != this->string_keys.cend()) {
				const auto& binding_data = string_it->second.binding_data;
				storage_it = std::find_if(this->storage.begin(), this->storage.end(), binding_data_equals(binding_data));
				this->string_keys.erase(string_it);
			}

			std::unique_ptr<Binding> p_binding = std::make_unique<Binding>(std::forward<Value>(value));
			Binding& b = *p_binding;
			if (storage_it != this->storage.cend()) {
				*storage_it = std::move(p_binding);
			}
			else {
				this->storage.push_back(std::move(p_binding));
			}

			bool is_index = (s == to_string(meta_function::index));
			bool is_new_index = (s == to_string(meta_function::new_index));
			bool is_static_index = (s == to_string(meta_function::static_index));
			bool is_static_new_index = (s == to_string(meta_function::static_new_index));
			bool is_destruction = s == to_string(meta_function::garbage_collect);
			bool poison_indexing = (!is_using_index || !is_using_new_index) && (is_var_bind::value || is_index || is_new_index);
			void* derived_this = static_cast<void*>(static_cast<usertype_storage<T>*>(this));
			index_call_storage ics;
			ics.binding_data = b.data();
			ics.index = is_index || is_static_index ? &Binding::template call_with_<true, is_var_bind::value>
				                                   : &Binding::template index_call_with_<true, is_var_bind::value>;
			ics.new_index = is_new_index || is_static_new_index ? &Binding::template call_with_<false, is_var_bind::value>
				                                               : &Binding::template index_call_with_<false, is_var_bind::value>;

			string_for_each_metatable_func for_each_fx;
			for_each_fx.is_destruction = is_destruction;
			for_each_fx.is_index = is_index;
			for_each_fx.is_new_index = is_new_index;
			for_each_fx.is_static_index = is_static_index;
			for_each_fx.is_static_new_index = is_static_new_index;
			for_each_fx.poison_indexing = poison_indexing;
			for_each_fx.p_key = &s;
			for_each_fx.p_ics = &ics;
			if constexpr (is_lua_c_function_v<ValueU>) {
				for_each_fx.is_unqualified_lua_CFunction = true;
				for_each_fx.call_func = *static_cast<lua_CFunction*>(ics.binding_data);
			}
			else if constexpr (is_lua_reference_or_proxy_v<ValueU>) {
				for_each_fx.is_unqualified_lua_reference = true;
				for_each_fx.p_binding_ref = static_cast<reference*>(ics.binding_data);
			}
			else {
				for_each_fx.call_func = &b.template call<false, is_var_bind::value>;
			}
			for_each_fx.p_usb = this;
			for_each_fx.p_derived_usb = derived_this;
			for_each_fx.idx_call = &usertype_storage<T>::template index_call<false>;
			for_each_fx.new_idx_call = &usertype_storage<T>::template index_call<true>;
			for_each_fx.meta_idx_call = &usertype_storage<T>::template meta_index_call<false>;
			for_each_fx.meta_new_idx_call = &usertype_storage<T>::template meta_index_call<true>;
			for_each_fx.change_indexing = &usertype_storage_base::change_indexing;
			// set base index and base new_index
			// functions here
			if (is_index) {
				this->base_index.index = ics.index;
				this->base_index.binding_data = ics.binding_data;
			}
			if (is_new_index) {
				this->base_index.new_index = ics.new_index;
				this->base_index.new_binding_data = ics.binding_data;
			}
			if (is_static_index) {
				this->static_base_index.index = ics.index;
				this->static_base_index.binding_data = ics.binding_data;
			}
			if (is_static_new_index) {
				this->static_base_index.new_index = ics.new_index;
				this->static_base_index.new_binding_data = ics.binding_data;
			}
			this->for_each_table(L, for_each_fx);
			this->add_entry(s, std::move(ics));
		}
		else {
			// the reference-based implementation might compare poorly and hash
			// poorly in some cases...
			if constexpr (is_lua_reference_v<KeyU> && is_lua_reference_v<ValueU>) {
				if (key.get_type() == type::string) {
					stack::push(L, key);
					std::string string_key = stack::pop<std::string>(L);
					this->set<T>(L, string_key, std::forward<Value>(value));
				}
				else {
					lua_reference_func ref_additions_fx { key, value };

					this->for_each_table(L, ref_additions_fx);
					this->auxiliary_keys.insert_or_assign(std::forward<Key>(key), std::forward<Value>(value));
				}
			}
			else {
				reference ref_key = make_reference(L, std::forward<Key>(key));
				reference ref_value = make_reference(L, std::forward<Value>(value));
				lua_reference_func ref_additions_fx { ref_key, ref_value };

				this->for_each_table(L, ref_additions_fx);
				this->auxiliary_keys.insert_or_assign(std::move(ref_key), std::move(ref_value));
			}
		}
	}

	template <typename T>
	template <typename Key, typename Value>
	void usertype_storage<T>::set(lua_State* L, Key&& key, Value&& value) {
		static_cast<usertype_storage_base&>(*this).set<T>(L, std::forward<Key>(key), std::forward<Value>(value));
	}

	template <typename T>
	inline void clear_usertype_registry_names(lua_State* L) {
		using u_traits = usertype_traits<T>;
		using u_const_traits = usertype_traits<const T>;
		using u_unique_traits = usertype_traits<d::u<T>>;
		using u_ref_traits = usertype_traits<T*>;
		using u_const_ref_traits = usertype_traits<T const*>;

		stack_reference registry(L, raw_index(LUA_REGISTRYINDEX));
		registry.push();
		// eliminate all named entries for this usertype
		// in the registry (luaL_newmetatable does
		// [name] = new table
		// in registry upon creation
		stack::set_field(L, &u_traits::metatable()[0], lua_nil, registry.stack_index());
		stack::set_field(L, &u_const_traits::metatable()[0], lua_nil, registry.stack_index());
		stack::set_field(L, &u_const_ref_traits::metatable()[0], lua_nil, registry.stack_index());
		stack::set_field(L, &u_ref_traits::metatable()[0], lua_nil, registry.stack_index());
		stack::set_field(L, &u_unique_traits::metatable()[0], lua_nil, registry.stack_index());
		registry.pop();
	}

	template <typename T>
	inline int destroy_usertype_storage(lua_State* L) noexcept {
		clear_usertype_registry_names<T>(L);
		return detail::user_alloc_destroy<usertype_storage<T>>(L);
	}

	template <typename T>
	inline usertype_storage<T>& create_usertype_storage(lua_State* L) {
		const char* gcmetakey = &usertype_traits<T>::gc_table()[0];

		// Make sure userdata's memory is properly in lua first,
		// otherwise all the light userdata we make later will become invalid
		int usertype_storage_push_count = stack::push<user<usertype_storage<T>>>(L, no_metatable, L);
		stack_reference usertype_storage_ref(L, -usertype_storage_push_count);

		// create and push onto the stack a table to use as metatable for this GC
		// we create a metatable to attach to the regular gc_table
		// so that the destructor is called for the usertype storage
		int usertype_storage_metatabe_count = stack::push(L, new_table(0, 1));
		stack_reference usertype_storage_metatable(L, -usertype_storage_metatabe_count);
		// set the destroyion routine on the metatable
		stack::set_field(L, meta_function::garbage_collect, &destroy_usertype_storage<T>, usertype_storage_metatable.stack_index());
		// set the metatable on the usertype storage userdata
		stack::set_field(L, metatable_key, usertype_storage_metatable, usertype_storage_ref.stack_index());
		usertype_storage_metatable.pop();

		// set the usertype storage and its metatable
		// into the global table...
		stack::set_field<true>(L, gcmetakey, usertype_storage_ref);
		usertype_storage_ref.pop();

		// then retrieve the lua-stored version so we have a well-pinned
		// reference that does not die
		stack::get_field<true>(L, gcmetakey);
		usertype_storage<T>& target_umt = stack::pop<user<usertype_storage<T>>>(L);
		return target_umt;
	}

	inline optional<usertype_storage_base&> maybe_as_usertype_storage_base(lua_State* L, int index) {
		if (type_of(L, index) != type::lightuserdata) {
			return nullopt;
		}
		usertype_storage_base& base_storage = *static_cast<usertype_storage_base*>(stack::get<void*>(L, index));
		return base_storage;
	}

	inline optional<usertype_storage_base&> maybe_get_usertype_storage_base_inside(lua_State* L, int index) {
		// okay, maybe we're looking at a table that is nested?
		if (type_of(L, index) != type::table) {
			return nullopt;
		}
		stack::get_field(L, meta_function::storage, index);
		auto maybe_storage_base = maybe_as_usertype_storage_base(L, -1);
		lua_pop(L, 1);
		return maybe_storage_base;
	}

	inline optional<usertype_storage_base&> maybe_get_usertype_storage_base(lua_State* L, int index) {
		// If we can get the index directly as this type, go for it
		auto maybe_already_is_usertype_storage_base = maybe_as_usertype_storage_base(L, index);
		if (maybe_already_is_usertype_storage_base) {
			return maybe_already_is_usertype_storage_base;
		}
		return maybe_get_usertype_storage_base_inside(L, index);
	}


	inline optional<usertype_storage_base&> maybe_get_usertype_storage_base(lua_State* L, const char* gcmetakey) {
		stack::get_field<true>(L, gcmetakey);
		auto maybe_storage = maybe_as_usertype_storage_base(L, lua_gettop(L));
		lua_pop(L, 1);
		return maybe_storage;
	}

	inline usertype_storage_base& get_usertype_storage_base(lua_State* L, const char* gcmetakey) {
		stack::get_field<true>(L, gcmetakey);
		stack::record tracking;
		usertype_storage_base& target_umt = stack::stack_detail::unchecked_unqualified_get<user<usertype_storage_base>>(L, -1, tracking);
		lua_pop(L, 1);
		return target_umt;
	}

	template <typename T>
	inline optional<usertype_storage<T>&> maybe_get_usertype_storage(lua_State* L) {
		const char* gcmetakey = &usertype_traits<T>::gc_table()[0];
		stack::get_field<true>(L, gcmetakey);
		int target = lua_gettop(L);
		if (!stack::check<user<usertype_storage<T>>>(L, target)) {
			return nullopt;
		}
		usertype_storage<T>& target_umt = stack::pop<user<usertype_storage<T>>>(L);
		return target_umt;
	}

	template <typename T>
	inline usertype_storage<T>& get_usertype_storage(lua_State* L) {
		const char* gcmetakey = &usertype_traits<T>::gc_table()[0];
		stack::get_field<true>(L, gcmetakey);
		usertype_storage<T>& target_umt = stack::pop<user<usertype_storage<T>>>(L);
		return target_umt;
	}

	template <typename T>
	inline void clear_usertype_storage(lua_State* L) {
		using u_traits = usertype_traits<T>;

		const char* gcmetakey = &u_traits::gc_table()[0];
		stack::get_field<true>(L, gcmetakey);
		if (!stack::check<user<usertype_storage<T>>>(L)) {
			lua_pop(L, 1);
			return;
		}
		usertype_storage<T>& target_umt = stack::pop<user<usertype_storage<T>>>(L);
		target_umt.clear();

		clear_usertype_registry_names<T>(L);

		stack::set_field<true>(L, gcmetakey, lua_nil);
	}

	template <typename T, automagic_flags enrollment_flags>
	inline int register_usertype(lua_State* L_, automagic_enrollments enrollments_ = {}) {
		using u_traits = usertype_traits<T>;
		using u_const_traits = usertype_traits<const T>;
		using u_unique_traits = usertype_traits<d::u<T>>;
		using u_ref_traits = usertype_traits<T*>;
		using u_const_ref_traits = usertype_traits<T const*>;
		using uts = usertype_storage<T>;

		// always have __new_index point to usertype_storage method
		// have __index always point to regular fast-lookup
		// meta_method table
		// if __new_index is invoked, runtime-swap
		// to slow __index if necessary
		// (no speed penalty because function calls
		// are all read-only -- only depend on __index
		// to retrieve function and then call happens VIA Lua)

		// __type entry:
		// table contains key -> value lookup,
		// where key is entry in metatable
		// and value is type information as a string as
		// best as we can give it

		// name entry:
		// string that contains raw class name,
		// as defined from C++

		// is entry:
		// checks if argument supplied is of type T

		// __storage entry:
		// a light userdata pointing to the storage
		// mostly to enable this new abstraction
		// to not require the type name `T`
		// to get at the C++ usertype storage within


		// we then let typical definitions potentially override these intrinsics
		// it's the user's fault if they override things or screw them up:
		// these names have been reserved and documented since sol2

		// STEP 0: tell the old usertype (if it exists)
		// to fuck off
		clear_usertype_storage<T>(L_);

		// STEP 1: Create backing store for usertype storage
		// Pretty much the most important step.
		// STEP 2: Create Lua tables used for fast method indexing.
		// This is done inside of the storage table's constructor
		usertype_storage<T>& storage = create_usertype_storage<T>(L_);
		usertype_storage_base& base_storage = storage;
		void* light_storage = static_cast<void*>(&storage);
		void* light_base_storage = static_cast<void*>(&base_storage);


		// STEP 3: set up GC escape hatch table entirely
		storage.gc_names_table.push(L_);
		stateless_stack_reference gnt(L_, -1);
		stack::set_field(L_, submetatable_type::named, &u_traits::gc_table()[0], gnt.stack_index());
		stack::set_field(L_, submetatable_type::const_value, &u_const_traits::metatable()[0], gnt.stack_index());
		stack::set_field(L_, submetatable_type::const_reference, &u_const_ref_traits::metatable()[0], gnt.stack_index());
		stack::set_field(L_, submetatable_type::reference, &u_ref_traits::metatable()[0], gnt.stack_index());
		stack::set_field(L_, submetatable_type::unique, &u_unique_traits::metatable()[0], gnt.stack_index());
		stack::set_field(L_, submetatable_type::value, &u_traits::metatable()[0], gnt.stack_index());
		gnt.pop(L_);

		// STEP 4: add some useful information to the type table
		stateless_stack_reference stacked_type_table(L_, -storage.type_table.push(L_));
		stack::set_field(L_, "name", detail::demangle<T>(), stacked_type_table.stack_index());
		stack::set_field(L_, "is", &detail::is_check<T>, stacked_type_table.stack_index());
		stacked_type_table.pop(L_);

		// STEP 5: create and hook up metatable,
		// add intrinsics
		// this one is the actual meta-handling table,
		// the next one will be the one for
		int for_each_backing_metatable_calls = 0;
		auto for_each_backing_metatable = [&](lua_State* L_, submetatable_type smt_, stateless_reference& fast_index_table_) {
			// Pointer types, AKA "references" from C++
			const char* metakey = nullptr;
			switch (smt_) {
			case submetatable_type::const_value:
				metakey = &u_const_traits::metatable()[0];
				break;
			case submetatable_type::reference:
				metakey = &u_ref_traits::metatable()[0];
				break;
			case submetatable_type::unique:
				metakey = &u_unique_traits::metatable()[0];
				break;
			case submetatable_type::const_reference:
				metakey = &u_const_ref_traits::metatable()[0];
				break;
			case submetatable_type::named:
				metakey = &u_traits::user_metatable()[0];
				break;
			case submetatable_type::value:
			default:
				metakey = &u_traits::metatable()[0];
				break;
			}

			luaL_newmetatable(L_, metakey);
			if (smt_ == submetatable_type::named) {
				// the named table itself
				// gets the associated name value
				storage.named_metatable.reset(L_, -1);
				lua_pop(L_, 1);
				// but the thing we perform the methods on
				// is still the metatable of the named
				// table
				lua_createtable(L_, 0, 6);
			}
			stateless_stack_reference t(L_, -1);
			fast_index_table_.reset(L_, t.stack_index());
			stack::set_field<false, true>(L_, meta_function::type, storage.type_table, t.stack_index());
			// destructible? serialize default destructor here
			// otherwise, not destructible: serialize a "hey you messed up"
			switch (smt_) {
			case submetatable_type::const_reference:
			case submetatable_type::reference:
			case submetatable_type::named:
				break;
			case submetatable_type::unique:
				if constexpr (std::is_destructible_v<T>) {
					stack::set_field<false, true>(L_, meta_function::garbage_collect, &detail::unique_destroy<T>, t.stack_index());
				}
				else {
					stack::set_field<false, true>(L_, meta_function::garbage_collect, &detail::cannot_destroy<T>, t.stack_index());
				}
				break;
			case submetatable_type::value:
			case submetatable_type::const_value:
			default:
				if constexpr (std::is_destructible_v<T>) {
					stack::set_field<false, true>(L_, meta_function::garbage_collect, detail::make_destructor<T>(), t.stack_index());
				}
				else {
					stack::set_field<false, true>(L_, meta_function::garbage_collect, &detail::cannot_destroy<T>, t.stack_index());
				}
				break;
			}

			static_assert(sizeof(void*) <= sizeof(detail::inheritance_check_function),
				"The size of this data pointer is too small to fit the inheritance checking function: file a bug "
				"report.");
			static_assert(sizeof(void*) <= sizeof(detail::inheritance_cast_function),
				"The size of this data pointer is too small to fit the inheritance checking function: file a bug "
				"report.");
			stack::set_field<false, true>(L_, detail::base_class_check_key(), reinterpret_cast<void*>(&detail::inheritance<T>::type_check), t.stack_index());
			stack::set_field<false, true>(L_, detail::base_class_cast_key(), reinterpret_cast<void*>(&detail::inheritance<T>::type_cast), t.stack_index());

			auto prop_fx = detail::properties_enrollment_allowed(for_each_backing_metatable_calls, storage.properties, enrollments_);
			auto insert_fx = [&L_, &t, &storage](meta_function mf, lua_CFunction reg) {
				stack::set_field<false, true>(L_, mf, reg, t.stack_index());
				storage.properties[static_cast<std::size_t>(mf)] = true;
			};
			detail::insert_default_registrations<T>(insert_fx, prop_fx);

			// There are no variables, so serialize the fast function stuff
			// be sure to reset the index stuff to the non-fast version
			// if the user ever adds something later!
			if (smt_ == submetatable_type::named) {
				// add escape hatch storage pointer and gc names
				stack::set_field<false, true>(L_, meta_function::storage, light_base_storage, t.stack_index());
				stack::set_field<false, true>(L_, meta_function::gc_names, storage.gc_names_table, t.stack_index());

				// fancy new_indexing when using the named table
				{
					absolute_index named_metatable_index(L_, -storage.named_metatable.push(L_));
					stack::set_field<false, true>(L_, metatable_key, t, named_metatable_index);
					storage.named_metatable.pop(L_);
				}
				stack_reference stack_metametatable(L_, -storage.named_index_table.push(L_));
				stack::set_field<false, true>(L_,
					meta_function::index,
					make_closure(uts::template meta_index_call<false>, nullptr, light_storage, light_base_storage, nullptr, toplevel_magic),
					stack_metametatable.stack_index());
				stack::set_field<false, true>(L_,
					meta_function::new_index,
					make_closure(uts::template meta_index_call<true>, nullptr, light_storage, light_base_storage, nullptr, toplevel_magic),
					stack_metametatable.stack_index());
				stack_metametatable.pop();
			}
			else {
				// otherwise just plain for index,
				// and elaborated for new_index
				stack::set_field<false, true>(L_, meta_function::index, t, t.stack_index());
				stack::set_field<false, true>(L_,
					meta_function::new_index,
					make_closure(uts::template index_call<true>, nullptr, light_storage, light_base_storage, nullptr, toplevel_magic),
					t.stack_index());
				storage.is_using_new_index = true;
			}

			++for_each_backing_metatable_calls;
			fast_index_table_.reset(L_, t.stack_index());
			t.pop(L_);
		};

		storage.for_each_table(L_, for_each_backing_metatable);

		// can only use set AFTER we initialize all the metatables
		if constexpr (std::is_default_constructible_v<T> && has_flag(enrollment_flags, automagic_flags::default_constructor)) {
			if (enrollments_.default_constructor) {
				storage.set(L_, meta_function::construct, constructors<T()>());
			}
		}

		// return the named metatable we want names linked into
		storage.named_metatable.push(L_);
		return 1;
	}
}} // namespace sol::u_detail

#endif // SOL_USERTYPE_STORAGE_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_USERTYPE_PROXY_HPP
#define SOL_USERTYPE_PROXY_HPP

#include <sol/traits.hpp>
#include <sol/function.hpp>
#include <sol/protected_function.hpp>
#include <sol/proxy_base.hpp>

namespace sol {
	template <typename Table, typename Key>
	struct usertype_proxy : public proxy_base<usertype_proxy<Table, Key>> {
	private:
		using key_type = detail::proxy_key_t<Key>;

		template <typename T, std::size_t... I>
		decltype(auto) tuple_get(std::index_sequence<I...>) const& {
			return tbl.template traverse_get<T>(std::get<I>(key)...);
		}

		template <typename T, std::size_t... I>
		decltype(auto) tuple_get(std::index_sequence<I...>) && {
			return tbl.template traverse_get<T>(std::get<I>(std::move(key))...);
		}

		template <std::size_t... I, typename T>
		void tuple_set(std::index_sequence<I...>, T&& value) & {
			if constexpr (sizeof...(I) > 1) {
				tbl.traverse_set(std::get<I>(key)..., std::forward<T>(value));
			}
			else {
				tbl.set(std::get<I>(key)..., std::forward<T>(value));
			}
		}

		template <std::size_t... I, typename T>
		void tuple_set(std::index_sequence<I...>, T&& value) && {
			if constexpr (sizeof...(I) > 1) {
				tbl.traverse_set(std::get<I>(std::move(key))..., std::forward<T>(value));
			}
			else {
				tbl.set(std::get<I>(std::move(key))..., std::forward<T>(value));
			}
		}

	public:
		Table tbl;
		key_type key;

		template <typename T>
		usertype_proxy(Table table, T&& k) : tbl(table), key(std::forward<T>(k)) {
		}

		template <typename T>
		usertype_proxy& set(T&& item) & {
			using idx_seq = std::make_index_sequence<std::tuple_size_v<meta::unqualified_t<key_type>>>;
			tuple_set(idx_seq(), std::forward<T>(item));
			return *this;
		}

		template <typename T>
		usertype_proxy&& set(T&& item) && {
			using idx_seq = std::make_index_sequence<std::tuple_size_v<meta::unqualified_t<key_type>>>;
			std::move(*this).tuple_set(idx_seq(), std::forward<T>(item));
			return std::move(*this);
		}

		template <typename T>
		usertype_proxy& operator=(T&& other) & {
			return set(std::forward<T>(other));
		}

		template <typename T>
		usertype_proxy&& operator=(T&& other) && {
			return std::move(*this).set(std::forward<T>(other));
		}

		template <typename T>
		usertype_proxy& operator=(std::initializer_list<T> other) & {
			return set(std::move(other));
		}

		template <typename T>
		usertype_proxy&& operator=(std::initializer_list<T> other) && {
			return std::move(*this).set(std::move(other));
		}

		template <typename T>
		decltype(auto) get() const& {
			using idx_seq = std::make_index_sequence<std::tuple_size_v<meta::unqualified_t<key_type>>>;
			return tuple_get<T>(idx_seq());
		}

		template <typename T>
		decltype(auto) get() && {
			using idx_seq = std::make_index_sequence<std::tuple_size_v<meta::unqualified_t<key_type>>>;
			return std::move(*this).template tuple_get<T>(idx_seq());
		}

		template <typename K>
		decltype(auto) operator[](K&& k) const& {
			auto keys = meta::tuplefy(key, std::forward<K>(k));
			return usertype_proxy<Table, decltype(keys)>(tbl, std::move(keys));
		}

		template <typename K>
		decltype(auto) operator[](K&& k) & {
			auto keys = meta::tuplefy(key, std::forward<K>(k));
			return usertype_proxy<Table, decltype(keys)>(tbl, std::move(keys));
		}

		template <typename K>
		decltype(auto) operator[](K&& k) && {
			auto keys = meta::tuplefy(std::move(key), std::forward<K>(k));
			return usertype_proxy<Table, decltype(keys)>(tbl, std::move(keys));
		}

		template <typename... Ret, typename... Args>
		decltype(auto) call(Args&&... args) {
#if !defined(__clang__) && defined(_MSC_FULL_VER) && _MSC_FULL_VER >= 191200000
			// MSVC is ass sometimes
			return get<function>().call<Ret...>(std::forward<Args>(args)...);
#else
			return get<function>().template call<Ret...>(std::forward<Args>(args)...);
#endif
		}

		template <typename... Args>
		decltype(auto) operator()(Args&&... args) {
			return call<>(std::forward<Args>(args)...);
		}

		bool valid() const {
			auto pp = stack::push_pop(tbl);
			auto p = stack::probe_get_field<std::is_same<meta::unqualified_t<Table>, global_table>::value>(lua_state(), key, lua_gettop(lua_state()));
			lua_pop(lua_state(), p.levels);
			return p;
		}

		int push() const noexcept {
			return push(this->lua_state());
		}

		int push(lua_State* L) const noexcept {
			return get<reference>().push(L);
		}

		type get_type() const {
			type t = type::none;
			auto pp = stack::push_pop(tbl);
			auto p = stack::probe_get_field<std::is_same<meta::unqualified_t<Table>, global_table>::value>(lua_state(), key, lua_gettop(lua_state()));
			if (p) {
				t = type_of(lua_state(), -1);
			}
			lua_pop(lua_state(), p.levels);
			return t;
		}

		lua_State* lua_state() const {
			return tbl.lua_state();
		}
	};
} // namespace sol

#endif // SOL_USERTYPE_PROXY_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_METATABLE_HPP
#define SOL_METATABLE_HPP

#include <sol/table_core.hpp>
#include <sol/usertype.hpp>

namespace sol {

	template <typename base_type>
	class basic_metatable : public basic_table<base_type> {
		typedef basic_table<base_type> base_t;
		friend class state;
		friend class state_view;

	protected:
		basic_metatable(detail::no_safety_tag, lua_nil_t n) : base_t(n) {
		}
		basic_metatable(detail::no_safety_tag, lua_State* L, int index) : base_t(L, index) {
		}
		basic_metatable(detail::no_safety_tag, lua_State* L, ref_index index) : base_t(L, index) {
		}
		template <typename T,
		     meta::enable<meta::neg<meta::any_same<meta::unqualified_t<T>, basic_metatable>>, meta::neg<std::is_same<base_type, stack_reference>>,
		          meta::neg<std::is_same<lua_nil_t, meta::unqualified_t<T>>>, is_lua_reference<meta::unqualified_t<T>>> = meta::enabler>
		basic_metatable(detail::no_safety_tag, T&& r) noexcept : base_t(std::forward<T>(r)) {
		}
		template <typename T, meta::enable<is_lua_reference<meta::unqualified_t<T>>> = meta::enabler>
		basic_metatable(detail::no_safety_tag, lua_State* L, T&& r) noexcept : base_t(L, std::forward<T>(r)) {
		}

		template <typename R, typename... Args, typename Fx, typename Key, typename = std::invoke_result_t<Fx, Args...>>
		void set_fx(types<R(Args...)>, Key&& key, Fx&& fx) {
			set_resolved_function<R(Args...)>(std::forward<Key>(key), std::forward<Fx>(fx));
		}

		template <typename Fx, typename Key, meta::enable<meta::is_specialization_of<meta::unqualified_t<Fx>, overload_set>> = meta::enabler>
		void set_fx(types<>, Key&& key, Fx&& fx) {
			set(std::forward<Key>(key), std::forward<Fx>(fx));
		}

		template <typename Fx, typename Key, typename... Args,
		     meta::disable<meta::is_specialization_of<meta::unqualified_t<Fx>, overload_set>> = meta::enabler>
		void set_fx(types<>, Key&& key, Fx&& fx, Args&&... args) {
			set(std::forward<Key>(key), as_function_reference(std::forward<Fx>(fx), std::forward<Args>(args)...));
		}

		template <typename... Sig, typename... Args, typename Key>
		void set_resolved_function(Key&& key, Args&&... args) {
			set(std::forward<Key>(key), as_function_reference<function_sig<Sig...>>(std::forward<Args>(args)...));
		}

	public:
		using base_t::lua_state;

		basic_metatable() noexcept = default;
		basic_metatable(const basic_metatable&) = default;
		basic_metatable(basic_metatable&&) = default;
		basic_metatable& operator=(const basic_metatable&) = default;
		basic_metatable& operator=(basic_metatable&&) = default;
		basic_metatable(const stack_reference& r) : basic_metatable(r.lua_state(), r.stack_index()) {
		}
		basic_metatable(stack_reference&& r) : basic_metatable(r.lua_state(), r.stack_index()) {
		}
		template <typename T, meta::enable_any<is_lua_reference<meta::unqualified_t<T>>> = meta::enabler>
		basic_metatable(lua_State* L, T&& r) : base_t(L, std::forward<T>(r)) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			auto pp = stack::push_pop(*this);
			constructor_handler handler {};
			stack::check<basic_metatable>(lua_state(), -1, handler);
#endif // Safety
		}
		basic_metatable(lua_State* L, int index = -1) : basic_metatable(detail::no_safety, L, index) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			constructor_handler handler {};
			stack::check<basic_metatable>(L, index, handler);
#endif // Safety
		}
		basic_metatable(lua_State* L, ref_index index) : basic_metatable(detail::no_safety, L, index) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			auto pp = stack::push_pop(*this);
			constructor_handler handler {};
			stack::check<basic_metatable>(lua_state(), -1, handler);
#endif // Safety
		}
		template <typename T,
		     meta::enable<meta::neg<meta::any_same<meta::unqualified_t<T>, basic_metatable>>, meta::neg<std::is_same<base_type, stack_reference>>,
		          meta::neg<std::is_same<lua_nil_t, meta::unqualified_t<T>>>, is_lua_reference<meta::unqualified_t<T>>> = meta::enabler>
		basic_metatable(T&& r) noexcept : basic_metatable(detail::no_safety, std::forward<T>(r)) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			if (!is_table<meta::unqualified_t<T>>::value) {
				auto pp = stack::push_pop(*this);
				constructor_handler handler {};
				stack::check<basic_metatable>(base_t::lua_state(), -1, handler);
			}
#endif // Safety
		}
		basic_metatable(lua_nil_t r) noexcept : basic_metatable(detail::no_safety, r) {
		}

		template <typename Key, typename Value>
		basic_metatable<base_type>& set(Key&& key, Value&& value);

		template <typename Sig, typename Key, typename... Args>
		basic_metatable& set_function(Key&& key, Args&&... args) {
			set_fx(types<Sig>(), std::forward<Key>(key), std::forward<Args>(args)...);
			return *this;
		}

		template <typename Key, typename... Args>
		basic_metatable& set_function(Key&& key, Args&&... args) {
			set_fx(types<>(), std::forward<Key>(key), std::forward<Args>(args)...);
			return *this;
		}

		void unregister() {
			using ustorage_base = u_detail::usertype_storage_base;

			lua_State* L = this->lua_state();

			auto pp = stack::push_pop(*this);
			int top = lua_gettop(L);

			stack_reference mt(L, -1);
			stack::get_field(L, meta_function::gc_names, mt.stack_index());
			if (type_of(L, -1) != type::table) {
				lua_settop(L, top);
				return;
			}
			stack_reference gc_names_table(L, -1);
			stack::get_field(L, meta_function::storage, mt.stack_index());
			if (type_of(L, -1) != type::lightuserdata) {
				lua_settop(L, top);
				return;
			}
			ustorage_base& base_storage = *static_cast<ustorage_base*>(stack::get<void*>(L, -1));
			std::array<string_view, 6> registry_traits;
			for (std::size_t i = 0; i < registry_traits.size(); ++i) {
				u_detail::submetatable_type smt = static_cast<u_detail::submetatable_type>(i);
				stack::get_field<false, true>(L, smt, gc_names_table.stack_index());
				registry_traits[i] = stack::get<string_view>(L, -1);
			}

			// get the registry
			stack_reference registry(L, raw_index(LUA_REGISTRYINDEX));
			registry.push();
			// eliminate all named entries for this usertype
			// in the registry (luaL_newmetatable does
			// [name] = new table
			// in registry upon creation)
			for (std::size_t i = 0; i < registry_traits.size(); ++i) {
				u_detail::submetatable_type smt = static_cast<u_detail::submetatable_type>(i);
				const string_view& gcmetakey = registry_traits[i];
				if (smt == u_detail::submetatable_type::named) {
					// use .data() to make it treat it like a c string,
					// which it is...
					stack::set_field<true>(L, gcmetakey.data(), lua_nil);
				}
				else {
					// do not change the values in the registry: they need to be present
					// no matter what, for safety's sake
					// stack::set_field(L, gcmetakey, lua_nil, registry.stack_index());
				}
			}

			// destroy all storage and tables
			base_storage.clear();

			// 6 strings from gc_names table,
			// + 1 registry,
			// + 1 gc_names table
			// + 1 light userdata of storage
			// + 1 registry
			// 10 total, 4 left since popping off 6 gc_names tables
			lua_settop(L, top);
		}
	};

} // namespace sol

#endif // SOL_METATABLE_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_USERTYPE_HPP
#define SOL_USERTYPE_HPP

#include <sol/usertype_core.hpp>
#include <sol/usertype_container_launch.hpp>
#include <sol/usertype_storage.hpp>
#include <sol/usertype_proxy.hpp>
#include <sol/metatable.hpp>

namespace sol {

	template <typename T, typename base_type>
	class basic_usertype : private basic_metatable<base_type> {
	private:
		using base_t = basic_metatable<base_type>;
		using table_base_t = basic_table<base_type>;

		template <typename>
		friend class basic_metatable;

		template <bool, typename>
		friend class basic_table_core;

		template <std::size_t... I, typename... Args>
		void tuple_set(std::index_sequence<I...>, std::tuple<Args...>&& args) {
			(void)args;
			(void)detail::swallow { 0, (this->set(std::get<I * 2>(std::move(args)), std::get<I * 2 + 1>(std::move(args))), 0)... };
		}

		template <typename R, typename... Args, typename Fx, typename Key, typename = std::invoke_result_t<Fx, Args...>>
		void set_fx(types<R(Args...)>, Key&& key, Fx&& fx) {
			set_resolved_function<R(Args...)>(std::forward<Key>(key), std::forward<Fx>(fx));
		}

		template <typename Fx, typename Key, meta::enable<meta::is_specialization_of<meta::unqualified_t<Fx>, overload_set>> = meta::enabler>
		void set_fx(types<>, Key&& key, Fx&& fx) {
			set(std::forward<Key>(key), std::forward<Fx>(fx));
		}

		template <typename Fx, typename Key, typename... Args,
		     meta::disable<meta::is_specialization_of<meta::unqualified_t<Fx>, overload_set>> = meta::enabler>
		void set_fx(types<>, Key&& key, Fx&& fx, Args&&... args) {
			set(std::forward<Key>(key), as_function_reference(std::forward<Fx>(fx), std::forward<Args>(args)...));
		}

		template <typename... Sig, typename... Args, typename Key>
		void set_resolved_function(Key&& key, Args&&... args) {
			set(std::forward<Key>(key), as_function_reference<function_sig<Sig...>>(std::forward<Args>(args)...));
		}

	public:
		using base_t::base_t;

		using base_t::get;
		using base_t::lua_state;
		using base_t::pop;
		using base_t::push;
		using base_t::traverse_get;
		using base_t::traverse_set;
		using base_t::unregister;

		template <typename Key, typename Value>
		basic_usertype& set(Key&& key, Value&& value) {
			optional<u_detail::usertype_storage<T>&> maybe_uts = u_detail::maybe_get_usertype_storage<T>(this->lua_state());
			if (maybe_uts) {
				u_detail::usertype_storage<T>& uts = *maybe_uts;
				uts.set(this->lua_state(), std::forward<Key>(key), std::forward<Value>(value));
			}
			else {
				using ValueU = meta::unqualified_t<Value>;
				// cannot get metatable: try regular table set?
				if constexpr (detail::is_non_factory_constructor_v<ValueU> || detail::is_policy_v<ValueU>) {
					// tag constructors so we don't get destroyed by lack of info
					table_base_t::set(std::forward<Key>(key), detail::tagged<T, Value>(std::forward<Value>(value)));
				}
				else {
					table_base_t::set(std::forward<Key>(key), std::forward<Value>(value));
				}
			}
			return *this;
		}

		template <typename Sig, typename Key, typename... Args>
		basic_usertype& set_function(Key&& key, Args&&... args) {
			set_fx(types<Sig>(), std::forward<Key>(key), std::forward<Args>(args)...);
			return *this;
		}

		template <typename Key, typename... Args>
		basic_usertype& set_function(Key&& key, Args&&... args) {
			set_fx(types<>(), std::forward<Key>(key), std::forward<Args>(args)...);
			return *this;
		}

		template <typename Key>
		usertype_proxy<basic_usertype&, std::decay_t<Key>> operator[](Key&& key) {
			return usertype_proxy<basic_usertype&, std::decay_t<Key>>(*this, std::forward<Key>(key));
		}

		template <typename Key>
		usertype_proxy<const basic_usertype&, std::decay_t<Key>> operator[](Key&& key) const {
			return usertype_proxy<const basic_usertype&, std::decay_t<Key>>(*this, std::forward<Key>(key));
		}
	};

} // namespace sol

#endif // SOL_USERTYPE_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_TABLE_CORE_HPP
#define SOL_TABLE_CORE_HPP

#include <sol/table_proxy.hpp>
#include <sol/stack.hpp>
#include <sol/function_types.hpp>
#include <sol/table_iterator.hpp>
#include <sol/pairs_iterator.hpp>
#include <sol/types.hpp>
#include <sol/object.hpp>
#include <sol/usertype.hpp>
#include <sol/optional.hpp>

namespace sol {
	namespace detail {
		template <std::size_t n>
		struct clean {
			lua_State* L;
			clean(lua_State* luastate) : L(luastate) {
			}
			~clean() {
				lua_pop(L, static_cast<int>(n));
			}
		};

		struct ref_clean {
			lua_State* L;
			int& pop_count;

			ref_clean(lua_State* L_, int& pop_count_) noexcept : L(L_), pop_count(pop_count_) {
			}
			~ref_clean() {
				lua_pop(L, static_cast<int>(pop_count));
			}
		};

		inline int fail_on_newindex(lua_State* L_) {
			return luaL_error(L_, "sol: cannot modify the elements of an enumeration table");
		}

	} // namespace detail

	template <bool top_level, typename ref_t>
	class basic_table_core : public basic_object<ref_t> {
	private:
		using base_t = basic_object<ref_t>;

		friend class state;
		friend class state_view;
		template <typename, typename>
		friend class basic_usertype;
		template <typename>
		friend class basic_metatable;

		template <typename T>
		using is_get_direct_tableless = meta::boolean<stack::stack_detail::is_get_direct_tableless_v<T, top_level, false>>;

		template <typename T>
		using is_raw_get_direct_tableless = std::false_type;

		template <typename T>
		using is_set_direct_tableless = meta::boolean<stack::stack_detail::is_set_direct_tableless_v<T, top_level, false>>;

		template <typename T>
		using is_raw_set_direct_tableless = std::false_type;

		template <bool raw, typename... Ret, typename... Keys>
		decltype(auto) tuple_get(int table_index, Keys&&... keys) const {
			if constexpr (sizeof...(Ret) < 2) {
				return traverse_get_single_maybe_tuple<raw, Ret...>(table_index, std::forward<Keys>(keys)...);
			}
			else {
				using multi_ret = decltype(stack::pop<std::tuple<Ret...>>(nullptr));
				return multi_ret(traverse_get_single_maybe_tuple<raw, Ret>(table_index, std::forward<Keys>(keys))...);
			}
		}

		template <bool raw, typename Ret, size_t... I, typename Key>
		decltype(auto) traverse_get_single_tuple(int table_index, std::index_sequence<I...>, Key&& key) const {
			return traverse_get_single<raw, Ret>(table_index, std::get<I>(std::forward<Key>(key))...);
		}

		template <bool raw, typename Ret, typename Key>
		decltype(auto) traverse_get_single_maybe_tuple(int table_index, Key&& key) const {
			if constexpr (meta::is_tuple_v<meta::unqualified_t<Key>>) {
				return traverse_get_single_tuple<raw, Ret>(
				     table_index, std::make_index_sequence<std::tuple_size_v<meta::unqualified_t<Key>>>(), std::forward<Key>(key));
			}
			else {
				return traverse_get_single<raw, Ret>(table_index, std::forward<Key>(key));
			}
		}

		template <bool raw, typename Ret, typename... Keys>
		decltype(auto) traverse_get_single(int table_index, Keys&&... keys) const {
			constexpr static bool global = (meta::count_for_to_pack_v < 1, is_get_direct_tableless, meta::unqualified_t<Keys>... >> 0);
			if constexpr (meta::is_optional_v<meta::unqualified_t<Ret>>) {
				int popcount = 0;
				detail::ref_clean c(base_t::lua_state(), popcount);
				return traverse_get_deep_optional<global, raw, detail::insert_mode::none, Ret>(popcount, table_index, std::forward<Keys>(keys)...);
			}
			else {
				detail::clean<sizeof...(Keys) - meta::count_for_pack_v<detail::is_insert_mode, meta::unqualified_t<Keys>...>> c(base_t::lua_state());
				return traverse_get_deep<global, raw, detail::insert_mode::none, Ret>(table_index, std::forward<Keys>(keys)...);
			}
		}

		template <bool raw, typename Pairs, std::size_t... I>
		void tuple_set(std::index_sequence<I...>, Pairs&& pairs) {
			constexpr static bool global = (meta::count_even_for_pack_v < is_set_direct_tableless,
			     meta::unqualified_t<decltype(std::get<I * 2>(std::forward<Pairs>(pairs)))>... >> 0);
			auto pp = stack::push_pop<global>(*this);
			int table_index = pp.index_of(*this);
			lua_State* L = base_t::lua_state();
			(void)table_index;
			(void)L;
			void(detail::swallow { (stack::set_field<(top_level), raw>(
			                             L, std::get<I * 2>(std::forward<Pairs>(pairs)), std::get<I * 2 + 1>(std::forward<Pairs>(pairs)), table_index),
			     0)... });
		}

		template <bool global, bool raw, detail::insert_mode mode, typename T, typename Key, typename... Keys>
		decltype(auto) traverse_get_deep(int table_index, Key&& key, Keys&&... keys) const {
			if constexpr (std::is_same_v<meta::unqualified_t<Key>, create_if_nil_t>) {
				(void)key;
				return traverse_get_deep<false, raw, static_cast<detail::insert_mode>(mode | detail::insert_mode::create_if_nil), T>(
				     table_index, std::forward<Keys>(keys)...);
			}
			else {
				lua_State* L = base_t::lua_state();
				stack::get_field<global, raw>(L, std::forward<Key>(key), table_index);
				if constexpr (sizeof...(Keys) > 0) {
					if constexpr ((mode & detail::insert_mode::create_if_nil) == detail::insert_mode::create_if_nil) {
						type t = type_of(L, -1);
						if (t == type::lua_nil || t == type::none) {
							lua_pop(L, 1);
							stack::push(L, new_table(0, 0));
						}
					}
					return traverse_get_deep<false, raw, mode, T>(lua_gettop(L), std::forward<Keys>(keys)...);
				}
				else {
					if constexpr ((mode & detail::insert_mode::create_if_nil) == detail::insert_mode::create_if_nil) {
						type t = type_of(L, -1);
						if ((t == type::lua_nil || t == type::none) && (is_table_like_v<T>)) {
							lua_pop(L, 1);
							stack::push(L, new_table(0, 0));
						}
					}
					return stack::get<T>(L);
				}
			}
		}

		template <bool global, bool raw, detail::insert_mode mode, typename T, typename Key, typename... Keys>
		decltype(auto) traverse_get_deep_optional(int& popcount, int table_index, Key&& key, Keys&&... keys) const {
			if constexpr (std::is_same_v<meta::unqualified_t<Key>, create_if_nil_t>) {
				constexpr detail::insert_mode new_mode = static_cast<detail::insert_mode>(mode | detail::insert_mode::create_if_nil);
				(void)key;
				return traverse_get_deep_optional<global, raw, new_mode, T>(popcount, table_index, std::forward<Keys>(keys)...);
			}
			else if constexpr (std::is_same_v<meta::unqualified_t<Key>, update_if_empty_t>) {
				constexpr detail::insert_mode new_mode = static_cast<detail::insert_mode>(mode | detail::insert_mode::update_if_empty);
				(void)key;
				return traverse_get_deep_optional<global, raw, new_mode, T>(popcount, table_index, std::forward<Keys>(keys)...);
			}
			else if constexpr (std::is_same_v<meta::unqualified_t<Key>, override_value_t>) {
				constexpr detail::insert_mode new_mode = static_cast<detail::insert_mode>(mode | detail::insert_mode::override_value);
				(void)key;
				return traverse_get_deep_optional<global, raw, new_mode, T>(popcount, table_index, std::forward<Keys>(keys)...);
			}
			else {
				if constexpr (sizeof...(Keys) > 0) {
					lua_State* L = base_t::lua_state();
					auto p = stack::probe_get_field<global, raw>(L, std::forward<Key>(key), table_index);
					popcount += p.levels;
					if (!p.success) {
						if constexpr ((mode & detail::insert_mode::create_if_nil) == detail::insert_mode::create_if_nil) {
							lua_pop(L, 1);
							constexpr bool is_seq = meta::count_for_to_pack_v < 1, std::is_integral, Keys... >> 0;
							stack::push(L, new_table(static_cast<int>(is_seq), static_cast<int>(!is_seq)));
							stack::set_field<global, raw>(L, std::forward<Key>(key), stack_reference(L, -1), table_index);
						}
						else {
							return T(nullopt);
						}
					}
					return traverse_get_deep_optional<false, raw, mode, T>(popcount, lua_gettop(L), std::forward<Keys>(keys)...);
				}
				else {
					using R = decltype(stack::get<T>(nullptr));
					using value_type = typename meta::unqualified_t<R>::value_type;
					lua_State* L = base_t::lua_state();
					auto p = stack::probe_get_field<global, raw, value_type>(L, key, table_index);
					popcount += p.levels;
					if (!p.success) {
						if constexpr ((mode & detail::insert_mode::create_if_nil) == detail::insert_mode::create_if_nil) {
							lua_pop(L, 1);
							stack::push(L, new_table(0, 0));
							stack::set_field<global, raw>(L, std::forward<Key>(key), stack_reference(L, -1), table_index);
							if (stack::check<value_type>(L, lua_gettop(L), &no_panic)) {
								return stack::get<T>(L);
							}
						}
						return R(nullopt);
					}
					return stack::get<T>(L);
				}
			}
		}

		template <bool global, bool raw, detail::insert_mode mode, typename Key, typename... Keys>
		void traverse_set_deep(int table_index, Key&& key, Keys&&... keys) const {
			using KeyU = meta::unqualified_t<Key>;
			if constexpr (std::is_same_v<KeyU, update_if_empty_t>) {
				(void)key;
				traverse_set_deep<global, raw, static_cast<detail::insert_mode>(mode | detail::insert_mode::update_if_empty)>(
				     table_index, std::forward<Keys>(keys)...);
			}
			else if constexpr (std::is_same_v<KeyU, create_if_nil_t>) {
				(void)key;
				traverse_set_deep<global, raw, static_cast<detail::insert_mode>(mode | detail::insert_mode::create_if_nil)>(
				     table_index, std::forward<Keys>(keys)...);
			}
			else if constexpr (std::is_same_v<KeyU, override_value_t>) {
				(void)key;
				traverse_set_deep<global, raw, static_cast<detail::insert_mode>(mode | detail::insert_mode::override_value)>(
				     table_index, std::forward<Keys>(keys)...);
			}
			else {
				lua_State* L = base_t::lua_state();
				if constexpr (sizeof...(Keys) == 1) {
					if constexpr ((mode & detail::insert_mode::update_if_empty) == detail::insert_mode::update_if_empty) {
						auto p = stack::probe_get_field<global, raw>(L, key, table_index);
						lua_pop(L, p.levels);
						if (!p.success) {
							stack::set_field<global, raw>(L, std::forward<Key>(key), std::forward<Keys>(keys)..., table_index);
						}
					}
					else {
						stack::set_field<global, raw>(L, std::forward<Key>(key), std::forward<Keys>(keys)..., table_index);
					}
				}
				else {
					if constexpr (mode != detail::insert_mode::none) {
						stack::get_field<global, raw>(L, key, table_index);
						type vt = type_of(L, -1);
						if constexpr ((mode & detail::insert_mode::update_if_empty) == detail::insert_mode::update_if_empty
						     || (mode & detail::insert_mode::create_if_nil) == detail::insert_mode::create_if_nil) {
							if (vt == type::lua_nil || vt == type::none) {
								constexpr bool is_seq = meta::count_for_to_pack_v < 1, std::is_integral, Keys... >> 0;
								lua_pop(L, 1);
								stack::push(L, new_table(static_cast<int>(is_seq), static_cast<int>(!is_seq)));
								stack::set_field<global, raw>(L, std::forward<Key>(key), stack_reference(L, -1), table_index);
							}
						}
						else {
							if (vt != type::table) {
								constexpr bool is_seq = meta::count_for_to_pack_v < 1, std::is_integral, Keys... >> 0;
								lua_pop(L, 1);
								stack::push(L, new_table(static_cast<int>(is_seq), static_cast<int>(!is_seq)));
								stack::set_field<global, raw>(L, std::forward<Key>(key), stack_reference(L, -1), table_index);
							}
						}
					}
					else {
						stack::get_field<global, raw>(L, std::forward<Key>(key), table_index);
					}
					traverse_set_deep<false, raw, mode>(lua_gettop(L), std::forward<Keys>(keys)...);
				}
			}
		}

	protected:
		basic_table_core(detail::no_safety_tag, lua_nil_t n) : base_t(n) {
		}
		basic_table_core(detail::no_safety_tag, lua_State* L, int index) : base_t(L, index) {
		}
		basic_table_core(detail::no_safety_tag, lua_State* L, ref_index index) : base_t(L, index) {
		}
		template <typename T,
		     meta::enable<meta::neg<meta::any_same<meta::unqualified_t<T>, basic_table_core>>, meta::neg<std::is_same<ref_t, stack_reference>>,
		          meta::neg<std::is_same<lua_nil_t, meta::unqualified_t<T>>>, is_lua_reference<meta::unqualified_t<T>>> = meta::enabler>
		basic_table_core(detail::no_safety_tag, T&& r) noexcept : base_t(std::forward<T>(r)) {
		}
		template <typename T, meta::enable<is_lua_reference<meta::unqualified_t<T>>> = meta::enabler>
		basic_table_core(detail::no_safety_tag, lua_State* L, T&& r) noexcept : base_t(L, std::forward<T>(r)) {
		}

	public:
		using iterator = basic_table_iterator<ref_t>;
		using const_iterator = iterator;

		using base_t::lua_state;

		basic_table_core() noexcept = default;
		basic_table_core(const basic_table_core&) = default;
		basic_table_core(basic_table_core&&) = default;
		basic_table_core& operator=(const basic_table_core&) = default;
		basic_table_core& operator=(basic_table_core&&) = default;

		basic_table_core(const stack_reference& r) : basic_table_core(r.lua_state(), r.stack_index()) {
		}

		basic_table_core(stack_reference&& r) : basic_table_core(r.lua_state(), r.stack_index()) {
		}

		template <typename T, meta::enable_any<is_lua_reference<meta::unqualified_t<T>>> = meta::enabler>
		basic_table_core(lua_State* L, T&& r) : base_t(L, std::forward<T>(r)) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			auto pp = stack::push_pop(*this);
			int table_index = pp.index_of(*this);
			constructor_handler handler {};
			stack::check<basic_table_core>(lua_state(), table_index, handler);
#endif // Safety
		}

		basic_table_core(lua_State* L, const new_table& nt) : base_t(L, -stack::push(L, nt)) {
			if (!is_stack_based<meta::unqualified_t<ref_t>>::value) {
				lua_pop(L, 1);
			}
		}

		basic_table_core(lua_State* L, int index = -1) : basic_table_core(detail::no_safety, L, index) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			constructor_handler handler {};
			stack::check<basic_table_core>(L, index, handler);
#endif // Safety
		}

		basic_table_core(lua_State* L, ref_index index) : basic_table_core(detail::no_safety, L, index) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			auto pp = stack::push_pop(*this);
			int table_index = pp.index_of(*this);
			constructor_handler handler {};
			stack::check<basic_table_core>(lua_state(), table_index, handler);
#endif // Safety
		}

		template <typename T,
		     meta::enable<meta::neg<meta::any_same<meta::unqualified_t<T>, basic_table_core>>, meta::neg<std::is_same<ref_t, stack_reference>>,
		          meta::neg<std::is_same<lua_nil_t, meta::unqualified_t<T>>>, is_lua_reference<meta::unqualified_t<T>>> = meta::enabler>
		basic_table_core(T&& r) noexcept : basic_table_core(detail::no_safety, std::forward<T>(r)) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			if (!is_table<meta::unqualified_t<T>>::value) {
				auto pp = stack::push_pop(*this);
				int table_index = pp.index_of(*this);
				constructor_handler handler {};
				stack::check<basic_table_core>(lua_state(), table_index, handler);
			}
#endif // Safety
		}

		basic_table_core(lua_nil_t r) noexcept : basic_table_core(detail::no_safety, r) {
		}

		basic_table_core(lua_State* L, global_tag_t t) noexcept : base_t(L, t) {
		}

		iterator begin() const {
			if (this->get_type() == type::table) {
				return iterator(*this);
			}
			return iterator();
		}

		iterator end() const {
			return iterator();
		}

		const_iterator cbegin() const {
			return begin();
		}

		const_iterator cend() const {
			return end();
		}

		basic_pairs_range<basic_table_core> pairs() noexcept {
			return basic_pairs_range<basic_table_core>(*this);
		}

		basic_pairs_range<const basic_table_core> pairs() const noexcept {
			return basic_pairs_range<const basic_table_core>(*this);
		}

		void clear() {
			auto pp = stack::push_pop<false>(*this);
			int table_index = pp.index_of(*this);
			stack::clear(lua_state(), table_index);
		}

		template <typename... Ret, typename... Keys>
		decltype(auto) get(Keys&&... keys) const {
			static_assert(sizeof...(Keys) == sizeof...(Ret), "number of keys and number of return types do not match");
			constexpr static bool global = meta::all<meta::boolean<top_level>, is_get_direct_tableless<meta::unqualified_t<Keys>>...>::value;
			auto pp = stack::push_pop<global>(*this);
			int table_index = pp.index_of(*this);
			return tuple_get<false, Ret...>(table_index, std::forward<Keys>(keys)...);
		}

		template <typename T, typename Key>
		decltype(auto) get_or(Key&& key, T&& otherwise) const {
			typedef decltype(get<T>("")) U;
			optional<U> option = get<optional<U>>(std::forward<Key>(key));
			if (option) {
				return static_cast<U>(option.value());
			}
			return static_cast<U>(std::forward<T>(otherwise));
		}

		template <typename T, typename Key, typename D>
		decltype(auto) get_or(Key&& key, D&& otherwise) const {
			optional<T> option = get<optional<T>>(std::forward<Key>(key));
			if (option) {
				return static_cast<T>(option.value());
			}
			return static_cast<T>(std::forward<D>(otherwise));
		}

		template <typename T, typename... Keys>
		decltype(auto) traverse_get(Keys&&... keys) const {
			static_assert(sizeof...(Keys) > 0, "must pass at least 1 key to get");
			constexpr static bool global = (meta::count_for_to_pack_v < 1, is_get_direct_tableless, meta::unqualified_t<Keys>... >> 0);
			auto pp = stack::push_pop<global>(*this);
			int table_index = pp.index_of(*this);
			return traverse_get_single<false, T>(table_index, std::forward<Keys>(keys)...);
		}

		template <typename... Keys>
		basic_table_core& traverse_set(Keys&&... keys) {
			static_assert(sizeof...(Keys) > 1, "must pass at least 1 key and 1 value to set");
			constexpr static bool global
			     = (meta::count_when_for_to_pack_v < detail::is_not_insert_mode, 1, is_set_direct_tableless, meta::unqualified_t<Keys>... >> 0);
			auto pp = stack::push_pop<global>(*this);
			int table_index = pp.index_of(*this);
			lua_State* L = base_t::lua_state();
			auto pn = stack::pop_n(L, static_cast<int>(sizeof...(Keys) - 2 - meta::count_for_pack_v<detail::is_insert_mode, meta::unqualified_t<Keys>...>));
			traverse_set_deep<top_level, false, detail::insert_mode::none>(table_index, std::forward<Keys>(keys)...);
			return *this;
		}

		template <typename... Args>
		basic_table_core& set(Args&&... args) {
			if constexpr (sizeof...(Args) == 2) {
				traverse_set(std::forward<Args>(args)...);
			}
			else {
				tuple_set<false>(std::make_index_sequence<sizeof...(Args) / 2>(), std::forward_as_tuple(std::forward<Args>(args)...));
			}
			return *this;
		}

		template <typename... Ret, typename... Keys>
		decltype(auto) raw_get(Keys&&... keys) const {
			static_assert(sizeof...(Keys) == sizeof...(Ret), "number of keys and number of return types do not match");
			constexpr static bool global = (meta::count_for_to_pack_v < 1, is_raw_get_direct_tableless, meta::unqualified_t<Keys>... >> 0);
			auto pp = stack::push_pop<global>(*this);
			int table_index = pp.index_of(*this);
			return tuple_get<true, Ret...>(table_index, std::forward<Keys>(keys)...);
		}

		template <typename T, typename Key>
		decltype(auto) raw_get_or(Key&& key, T&& otherwise) const {
			typedef decltype(raw_get<T>("")) U;
			optional<U> option = raw_get<optional<U>>(std::forward<Key>(key));
			if (option) {
				return static_cast<U>(option.value());
			}
			return static_cast<U>(std::forward<T>(otherwise));
		}

		template <typename T, typename Key, typename D>
		decltype(auto) raw_get_or(Key&& key, D&& otherwise) const {
			optional<T> option = raw_get<optional<T>>(std::forward<Key>(key));
			if (option) {
				return static_cast<T>(option.value());
			}
			return static_cast<T>(std::forward<D>(otherwise));
		}

		template <typename T, typename... Keys>
		decltype(auto) traverse_raw_get(Keys&&... keys) const {
			constexpr static bool global = (meta::count_for_to_pack_v < 1, is_raw_get_direct_tableless, meta::unqualified_t<Keys>... >> 0);
			auto pp = stack::push_pop<global>(*this);
			int table_index = pp.index_of(*this);
			return traverse_get_single<true, T>(table_index, std::forward<Keys>(keys)...);
		}

		template <typename... Keys>
		basic_table_core& traverse_raw_set(Keys&&... keys) {
			constexpr static bool global = (meta::count_for_to_pack_v < 1, is_raw_set_direct_tableless, meta::unqualified_t<Keys>... >> 0);
			auto pp = stack::push_pop<global>(*this);
			lua_State* L = base_t::lua_state();
			auto pn = stack::pop_n(L, static_cast<int>(sizeof...(Keys) - 2 - meta::count_for_pack_v<detail::is_insert_mode, meta::unqualified_t<Keys>...>));
			traverse_set_deep<top_level, true, false>(std::forward<Keys>(keys)...);
			return *this;
		}

		template <typename... Args>
		basic_table_core& raw_set(Args&&... args) {
			tuple_set<true>(std::make_index_sequence<sizeof...(Args) / 2>(), std::forward_as_tuple(std::forward<Args>(args)...));
			return *this;
		}

		template <typename Class, typename Key>
		usertype<Class> new_usertype(Key&& key);

		template <typename Class, typename Key, automagic_flags enrollment_flags>
		usertype<Class> new_usertype(Key&& key, constant_automagic_enrollments<enrollment_flags> enrollment);

		template <typename Class, typename Key>
		usertype<Class> new_usertype(Key&& key, automagic_enrollments enrollment);

		template <typename Class, typename Key, typename Arg, typename... Args,
		     typename = std::enable_if_t<!std::is_base_of_v<automagic_enrollments, meta::unqualified_t<Arg>>>>
		usertype<Class> new_usertype(Key&& key, Arg&& arg, Args&&... args);

		template <bool read_only = true, typename... Args>
		table new_enum(const string_view& name, Args&&... args) {
			table target = create_with(std::forward<Args>(args)...);
			if constexpr (read_only) {
				// Need to create a special iterator to handle this
				table x
				     = create_with(meta_function::new_index, detail::fail_on_newindex, meta_function::index, target, meta_function::pairs, stack::stack_detail::readonly_pairs);
				table shim = create_named(name, metatable_key, x);
				return shim;
			}
			else {
				set(name, target);
				return target;
			}
		}

		template <typename T, bool read_only = true>
		table new_enum(const string_view& name, std::initializer_list<std::pair<string_view, T>> items) {
			table target = create(static_cast<int>(items.size()), static_cast<int>(0));
			for (const auto& kvp : items) {
				target.set(kvp.first, kvp.second);
			}
			if constexpr (read_only) {
				table x = create_with(meta_function::new_index, detail::fail_on_newindex, meta_function::index, target);
				table shim = create_named(name, metatable_key, x);
				return shim;
			}
			else {
				set(name, target);
				return target;
			}
		}

		template <typename Key = object, typename Value = object, typename Fx>
		void for_each(Fx&& fx) const {
			lua_State* L = base_t::lua_state();
			if constexpr (std::is_invocable_v<Fx, Key, Value>) {
				auto pp = stack::push_pop(*this);
				int table_index = pp.index_of(*this);
				stack::push(L, lua_nil);
				while (lua_next(L, table_index)) {
					Key key(L, -2);
					Value value(L, -1);
					auto pn = stack::pop_n(L, 1);
					fx(key, value);
				}
			}
			else {
				auto pp = stack::push_pop(*this);
				int table_index = pp.index_of(*this);
				stack::push(L, lua_nil);
				while (lua_next(L, table_index)) {
					Key key(L, -2);
					Value value(L, -1);
					auto pn = stack::pop_n(L, 1);
					std::pair<Key&, Value&> keyvalue(key, value);
					fx(keyvalue);
				}
			}
		}

		size_t size() const {
			auto pp = stack::push_pop(*this);
			int table_index = pp.index_of(*this);
			lua_State* L = base_t::lua_state();
			lua_len(L, table_index);
			return stack::pop<size_t>(L);
		}

		bool empty() const {
			return cbegin() == cend();
		}

		template <typename T>
		auto operator[](T&& key) & {
			return table_proxy<basic_table_core&, detail::proxy_key_t<T>>(*this, std::forward<T>(key));
		}

		template <typename T>
		auto operator[](T&& key) const& {
			return table_proxy<const basic_table_core&, detail::proxy_key_t<T>>(*this, std::forward<T>(key));
		}

		template <typename T>
		auto operator[](T&& key) && {
			return table_proxy<basic_table_core, detail::proxy_key_t<T>>(std::move(*this), std::forward<T>(key));
		}

		template <typename Sig, typename Key, typename... Args>
		basic_table_core& set_function(Key&& key, Args&&... args) {
			set_fx(types<Sig>(), std::forward<Key>(key), std::forward<Args>(args)...);
			return *this;
		}

		template <typename Key, typename... Args>
		basic_table_core& set_function(Key&& key, Args&&... args) {
			set_fx(types<>(), std::forward<Key>(key), std::forward<Args>(args)...);
			return *this;
		}

		template <typename... Args>
		basic_table_core& add(Args&&... args) {
			auto pp = stack::push_pop(*this);
			int table_index = pp.index_of(*this);
			lua_State* L = base_t::lua_state();
			(void)detail::swallow { 0, (stack::stack_detail::raw_table_set(L, std::forward<Args>(args), table_index), 0)... };
			return *this;
		}

	private:
		template <typename R, typename... Args, typename Fx, typename Key, typename = std::invoke_result_t<Fx, Args...>>
		void set_fx(types<R(Args...)>, Key&& key, Fx&& fx) {
			set_resolved_function<R(Args...)>(std::forward<Key>(key), std::forward<Fx>(fx));
		}

		template <typename Fx, typename Key, meta::enable<meta::is_specialization_of<meta::unqualified_t<Fx>, overload_set>> = meta::enabler>
		void set_fx(types<>, Key&& key, Fx&& fx) {
			set(std::forward<Key>(key), std::forward<Fx>(fx));
		}

		template <typename Fx, typename Key, typename... Args,
		     meta::disable<meta::is_specialization_of<meta::unqualified_t<Fx>, overload_set>> = meta::enabler>
		void set_fx(types<>, Key&& key, Fx&& fx, Args&&... args) {
			set(std::forward<Key>(key), as_function_reference(std::forward<Fx>(fx), std::forward<Args>(args)...));
		}

		template <typename... Sig, typename... Args, typename Key>
		void set_resolved_function(Key&& key, Args&&... args) {
			set(std::forward<Key>(key), as_function_reference<function_sig<Sig...>>(std::forward<Args>(args)...));
		}

	public:
		static inline table create(lua_State* L, int narr = 0, int nrec = 0) {
			lua_createtable(L, narr, nrec);
			table result(L);
			lua_pop(L, 1);
			return result;
		}

		template <typename Key, typename Value, typename... Args>
		static inline table create(lua_State* L, int narr, int nrec, Key&& key, Value&& value, Args&&... args) {
			lua_createtable(L, narr, nrec);
			table result(L);
			result.set(std::forward<Key>(key), std::forward<Value>(value), std::forward<Args>(args)...);
			lua_pop(L, 1);
			return result;
		}

		template <typename... Args>
		static inline table create_with(lua_State* L, Args&&... args) {
			static_assert(sizeof...(Args) % 2 == 0, "You must have an even number of arguments for a key, value ... list.");
			constexpr int narr = static_cast<int>(meta::count_odd_for_pack_v<std::is_integral, Args...>);
			return create(L, narr, static_cast<int>((sizeof...(Args) / 2) - narr), std::forward<Args>(args)...);
		}

		table create(int narr = 0, int nrec = 0) {
			return create(base_t::lua_state(), narr, nrec);
		}

		template <typename Key, typename Value, typename... Args>
		table create(int narr, int nrec, Key&& key, Value&& value, Args&&... args) {
			return create(base_t::lua_state(), narr, nrec, std::forward<Key>(key), std::forward<Value>(value), std::forward<Args>(args)...);
		}

		template <typename Name>
		table create(Name&& name, int narr = 0, int nrec = 0) {
			table x = create(base_t::lua_state(), narr, nrec);
			this->set(std::forward<Name>(name), x);
			return x;
		}

		template <typename Name, typename Key, typename Value, typename... Args>
		table create(Name&& name, int narr, int nrec, Key&& key, Value&& value, Args&&... args) {
			table x = create(base_t::lua_state(), narr, nrec, std::forward<Key>(key), std::forward<Value>(value), std::forward<Args>(args)...);
			this->set(std::forward<Name>(name), x);
			return x;
		}

		template <typename... Args>
		table create_with(Args&&... args) {
			return create_with(base_t::lua_state(), std::forward<Args>(args)...);
		}

		template <typename Name, typename... Args>
		table create_named(Name&& name, Args&&... args) {
			static const int narr = static_cast<int>(meta::count_even_for_pack_v<std::is_integral, Args...>);
			return create(std::forward<Name>(name), narr, (sizeof...(Args) / 2) - narr, std::forward<Args>(args)...);
		}
	};
} // namespace sol

#endif // SOL_TABLE_CORE_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_LUA_TABLE_HPP
#define SOL_LUA_TABLE_HPP

#include <sol/table_core.hpp>

namespace sol {

	template <typename ref_t>
	struct basic_lua_table : basic_table_core<false, ref_t> {
	private:
		using base_t = basic_table_core<false, ref_t>;

		friend class state;
		friend class state_view;

	public:
		using base_t::lua_state;

		basic_lua_table() noexcept = default;
		basic_lua_table(const basic_lua_table&) = default;
		basic_lua_table(basic_lua_table&&) = default;
		basic_lua_table& operator=(const basic_lua_table&) = default;
		basic_lua_table& operator=(basic_lua_table&&) = default;
		basic_lua_table(const stack_reference& r) : basic_lua_table(r.lua_state(), r.stack_index()) {
		}
		basic_lua_table(stack_reference&& r) : basic_lua_table(r.lua_state(), r.stack_index()) {
		}
		template <typename T, meta::enable_any<is_lua_reference<meta::unqualified_t<T>>> = meta::enabler>
		basic_lua_table(lua_State* L, T&& r) : base_t(L, std::forward<T>(r)) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			auto pp = stack::push_pop(*this);
			constructor_handler handler {};
			stack::check<basic_lua_table>(lua_state(), -1, handler);
#endif // Safety
		}
		basic_lua_table(lua_State* L, const new_table& nt) : base_t(L, nt) {
			if (!is_stack_based<meta::unqualified_t<ref_t>>::value) {
				lua_pop(L, 1);
			}
		}
		basic_lua_table(lua_State* L, int index = -1) : base_t(detail::no_safety, L, index) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			constructor_handler handler {};
			stack::check<basic_lua_table>(L, index, handler);
#endif // Safety
		}
		basic_lua_table(lua_State* L, ref_index index) : base_t(detail::no_safety, L, index) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			auto pp = stack::push_pop(*this);
			constructor_handler handler {};
			stack::check<basic_lua_table>(lua_state(), -1, handler);
#endif // Safety
		}
		template <typename T,
		     meta::enable<meta::neg<meta::any_same<meta::unqualified_t<T>, basic_lua_table>>, meta::neg<std::is_same<ref_t, stack_reference>>,
		          meta::neg<std::is_same<lua_nil_t, meta::unqualified_t<T>>>, is_lua_reference<meta::unqualified_t<T>>> = meta::enabler>
		basic_lua_table(T&& r) noexcept : basic_lua_table(detail::no_safety, std::forward<T>(r)) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			if (!is_table<meta::unqualified_t<T>>::value) {
				auto pp = stack::push_pop(*this);
				constructor_handler handler {};
				stack::check<basic_lua_table>(lua_state(), -1, handler);
			}
#endif // Safety
		}
		basic_lua_table(lua_nil_t r) noexcept : basic_lua_table(detail::no_safety, r) {
		}
	};

} // namespace sol

#endif // SOL_LUA_TABLE_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_TABLE_HPP
#define SOL_TABLE_HPP

#include <sol/table_core.hpp>
#include <sol/lua_table.hpp>
#include <sol/usertype.hpp>

namespace sol {
	typedef table_core<false> table;

	template <bool is_global, typename base_type>
	template <typename Class, typename Key>
	usertype<Class> basic_table_core<is_global, base_type>::new_usertype(Key&& key) {
		constant_automagic_enrollments<> enrollments {};
		return this->new_usertype<Class>(std::forward<Key>(key), std::move(enrollments));
	}

	template <bool is_global, typename base_type>
	template <typename Class, typename Key, automagic_flags enrollment_flags>
	usertype<Class> basic_table_core<is_global, base_type>::new_usertype(Key&& key, constant_automagic_enrollments<enrollment_flags> enrollments) {
		int mt_index = u_detail::register_usertype<Class, enrollment_flags>(this->lua_state(), std::move(enrollments));
		usertype<Class> mt(this->lua_state(), -mt_index);
		lua_pop(this->lua_state(), 1);
		set(std::forward<Key>(key), mt);
		return mt;
	}

	template <bool is_global, typename base_type>
	template <typename Class, typename Key>
	usertype<Class> basic_table_core<is_global, base_type>::new_usertype(Key&& key, automagic_enrollments enrollments) {
		int mt_index = u_detail::register_usertype<Class, automagic_flags::all>(this->lua_state(), std::move(enrollments));
		usertype<Class> mt(this->lua_state(), -mt_index);
		lua_pop(this->lua_state(), 1);
		set(std::forward<Key>(key), mt);
		return mt;
	}

	template <bool is_global, typename base_type>
	template <typename Class, typename Key, typename Arg, typename... Args, typename>
	usertype<Class> basic_table_core<is_global, base_type>::new_usertype(Key&& key, Arg&& arg, Args&&... args) {
		constexpr automagic_flags enrollment_flags = meta::any_same_v<no_construction, meta::unqualified_t<Arg>, meta::unqualified_t<Args>...>
		     ? clear_flags(automagic_flags::all, automagic_flags::default_constructor)
		     : automagic_flags::all;
		constant_automagic_enrollments<enrollment_flags> enrollments;
		enrollments.default_constructor = !detail::any_is_constructor_v<Arg, Args...>;
		enrollments.destructor = !detail::any_is_destructor_v<Arg, Args...>;
		usertype<Class> ut = this->new_usertype<Class>(std::forward<Key>(key), std::move(enrollments));
		static_assert(sizeof...(Args) % 2 == static_cast<std::size_t>(!detail::any_is_constructor_v<Arg>),
		     "you must pass an even number of arguments to new_usertype after first passing a constructor");
		if constexpr (detail::any_is_constructor_v<Arg>) {
			ut.set(meta_function::construct, std::forward<Arg>(arg));
			ut.tuple_set(std::make_index_sequence<(sizeof...(Args)) / 2>(), std::forward_as_tuple(std::forward<Args>(args)...));
		}
		else {
			ut.tuple_set(std::make_index_sequence<(sizeof...(Args) + 1) / 2>(), std::forward_as_tuple(std::forward<Arg>(arg), std::forward<Args>(args)...));
		}
		return ut;
	}

	template <typename base_type>
	template <typename Key, typename Value>
	basic_metatable<base_type>& basic_metatable<base_type>::set(Key&& key, Value&& value) {
		this->push();
		lua_State* L = this->lua_state();
		int target = lua_gettop(L);
		optional<u_detail::usertype_storage_base&> maybe_uts = nullopt;
		maybe_uts = u_detail::maybe_get_usertype_storage_base(L, target);
		if (maybe_uts) {
			u_detail::usertype_storage_base& uts = *maybe_uts;
			uts.set(L, std::forward<Key>(key), std::forward<Value>(value));
			return *this;
		}
		else {
			base_t::set(std::forward<Key>(key), std::forward<Value>(value));
		}
		this->pop();
		return *this;
	}

	namespace stack {
		template <>
		struct unqualified_getter<metatable_key_t> {
			static metatable get(lua_State* L, int index = -1) {
				if (lua_getmetatable(L, index) == 0) {
					return metatable(L, ref_index(LUA_REFNIL));
				}
				return metatable(L, -1);
			}
		};
	} // namespace stack
} // namespace sol

#endif // SOL_TABLE_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_STATE_VIEW_HPP
#define SOL_STATE_VIEW_HPP

#include <sol/error.hpp>
#include <sol/table.hpp>
#include <sol/environment.hpp>
#include <sol/load_result.hpp>
#include <sol/state_handling.hpp>

#include <memory>
#include <cstddef>

namespace sol {

	class state_view {
	private:
		lua_State* L;
		table reg;
		global_table global;

		optional<object> is_loaded_package(const std::string& key) {
			auto loaded = reg.traverse_get<optional<object>>("_LOADED", key);
			bool is53mod = loaded && !(loaded->is<bool>() && !loaded->as<bool>());
			if (is53mod)
				return loaded;
#if SOL_LUA_VERSION_I_ <= 501
			auto loaded51 = global.traverse_get<optional<object>>("package", "loaded", key);
			bool is51mod = loaded51 && !(loaded51->is<bool>() && !loaded51->as<bool>());
			if (is51mod)
				return loaded51;
#endif
			return nullopt;
		}

		template <typename T>
		void ensure_package(const std::string& key, T&& sr) {
#if SOL_LUA_VERSION_I_ <= 501
			auto pkg = global["package"];
			if (!pkg.valid()) {
				pkg = create_table_with("loaded", create_table_with(key, sr));
			}
			else {
				auto ld = pkg["loaded"];
				if (!ld.valid()) {
					ld = create_table_with(key, sr);
				}
				else {
					ld[key] = sr;
				}
			}
#endif
			auto loaded = reg["_LOADED"];
			if (!loaded.valid()) {
				loaded = create_table_with(key, sr);
			}
			else {
				loaded[key] = sr;
			}
		}

		template <typename Fx>
		object require_core(const std::string& key, Fx&& action, bool create_global = true) {
			optional<object> loaded = is_loaded_package(key);
			if (loaded && loaded->valid())
				return std::move(*loaded);
			int before = lua_gettop(L);
			action();
			int after = lua_gettop(L);
			if (before == after) {
				// I mean, you were supposed to return
				// something, ANYTHING, from your requires script. I guess I'll just
				// but some trash in here, it's on you after that?
				ensure_package(key, static_cast<void*>(L));
				return object(L, lua_nil);
			}
			stack_reference sr(L, -1);
			if (create_global)
				set(key, sr);
			ensure_package(key, sr);
			return stack::pop<object>(L);
		}

	public:
		using iterator = typename global_table::iterator;
		using const_iterator = typename global_table::const_iterator;

		state_view(lua_State* Ls) : L(Ls), reg(Ls, LUA_REGISTRYINDEX), global(Ls, global_tag) {
		}

		state_view(this_state Ls) : state_view(Ls.L) {
		}

		lua_State* lua_state() const {
			return L;
		}

		template <typename... Args>
		void open_libraries(Args&&... args) {
			static_assert(meta::all_same<lib, meta::unqualified_t<Args>...>::value, "all types must be libraries");
			if constexpr (sizeof...(args) == 0) {
				luaL_openlibs(L);
				return;
			}
			else {
				lib libraries[1 + sizeof...(args)] = { lib::count, std::forward<Args>(args)... };

				for (auto&& library : libraries) {
					switch (library) {
#if SOL_LUA_VERSION_I_ <= 501 && SOL_IS_ON(SOL_USE_LUAJIT)
					case lib::coroutine:
#endif // luajit opens coroutine base stuff
					case lib::base:
						luaL_requiref(L, "base", luaopen_base, 1);
						lua_pop(L, 1);
						break;
					case lib::package:
						luaL_requiref(L, "package", luaopen_package, 1);
						lua_pop(L, 1);
						break;
#if SOL_IS_OFF(SOL_USE_LUAJIT)
					case lib::coroutine:
#if SOL_LUA_VERSION_I_ > 501
						luaL_requiref(L, "coroutine", luaopen_coroutine, 1);
						lua_pop(L, 1);
#endif // Lua 5.2+ only
						break;
#endif // Not LuaJIT - comes builtin
					case lib::string:
						luaL_requiref(L, "string", luaopen_string, 1);
						lua_pop(L, 1);
						break;
					case lib::table:
						luaL_requiref(L, "table", luaopen_table, 1);
						lua_pop(L, 1);
						break;
					case lib::math:
						luaL_requiref(L, "math", luaopen_math, 1);
						lua_pop(L, 1);
						break;
					case lib::bit32:
#if SOL_IS_ON(SOL_USE_LUAJIT)
						luaL_requiref(L, "bit32", luaopen_bit, 1);
						lua_pop(L, 1);
#elif SOL_IS_ON(SOL_LUA_BIT32_LIB)
						luaL_requiref(L, "bit32", luaopen_bit32, 1);
						lua_pop(L, 1);
#else
#endif
						break;
					case lib::io:
						luaL_requiref(L, "io", luaopen_io, 1);
						lua_pop(L, 1);
						break;
					case lib::os:
						luaL_requiref(L, "os", luaopen_os, 1);
						lua_pop(L, 1);
						break;
					case lib::debug:
						luaL_requiref(L, "debug", luaopen_debug, 1);
						lua_pop(L, 1);
						break;
					case lib::utf8:
#if SOL_LUA_VERSION_I_ > 502 && SOL_IS_OFF(SOL_USE_LUAJIT)
						luaL_requiref(L, "utf8", luaopen_utf8, 1);
						lua_pop(L, 1);
#endif // Lua 5.3+ only
						break;
					case lib::ffi:
#if SOL_IS_ON(SOL_USE_LUAJIT) && SOL_IS_OFF(SOL_LUAJIT_FFI_DISABLED)
						luaL_requiref(L, "ffi", luaopen_ffi, 1);
						lua_pop(L, 1);
#endif // LuaJIT only
						break;
					case lib::jit:
#if SOL_IS_ON(SOL_USE_LUAJIT)
						luaL_requiref(L, "jit", luaopen_jit, 0);
						lua_pop(L, 1);
#endif // LuaJIT Only
						break;
					case lib::count:
					default:
						break;
					}
				}
			}
		}

		object require(const std::string& key, lua_CFunction open_function, bool create_global = true) {
			luaL_requiref(L, key.c_str(), open_function, create_global ? 1 : 0);
			return stack::pop<object>(L);
		}

		object require_script(const std::string& key, const string_view& code, bool create_global = true,
		     const std::string& chunkname = detail::default_chunk_name(), load_mode mode = load_mode::any) {
			auto action = [this, &code, &chunkname, &mode]() { stack::script(L, code, chunkname, mode); };
			return require_core(key, action, create_global);
		}

		object require_file(const std::string& key, const std::string& filename, bool create_global = true, load_mode mode = load_mode::any) {
			auto action = [this, &filename, &mode]() { stack::script_file(L, filename, mode); };
			return require_core(key, action, create_global);
		}

		void clear_package_loaders() {
			optional<table> maybe_package = this->global["package"];
			if (!maybe_package) {
				// package lib wasn't opened
				// open package lib
				return;
			}
			table& package = *maybe_package;
			// yay for version differences...
			// one day Lua 5.1 will die a peaceful death
			// and its old bones will find blissful rest
			auto loaders_proxy = package
#if SOL_LUA_VERSION_I_ < 502
			     ["loaders"]
#else
			     ["searchers"]
#endif
			     ;
			if (!loaders_proxy.valid()) {
				// nothing to clear
				return;
			}
			// we need to create the table for loaders
			// table does not exist, so create and move forward
			loaders_proxy = new_table(1, 0);
		}

		template <typename Fx>
		void add_package_loader(Fx&& fx, bool clear_all_package_loaders = false) {
			optional<table> maybe_package = this->global["package"];
			if (!maybe_package) {
				// package lib wasn't opened
				// open package lib
				return;
			}
			table& package = *maybe_package;
			// yay for version differences...
			// one day Lua 5.1 will die a peaceful death
			// and its old bones will find blissful rest
			auto loaders_proxy = package
#if SOL_LUA_VERSION_I_ < 502
			     ["loaders"]
#else
			     ["searchers"]
#endif
			     ;
			bool make_new_table = clear_all_package_loaders || !loaders_proxy.valid();
			if (make_new_table) {
				// we need to create the table for loaders
				// table does not exist, so create and move forward
				loaders_proxy = new_table(1, 0);
			}
			optional<table> maybe_loaders = loaders_proxy;
			if (!maybe_loaders) {
				// loaders/searches
				// thing exists in package, but it
				// ain't a table or a table-alike...!
				return;
			}
			table loaders = loaders_proxy;
			loaders.add(std::forward<Fx>(fx));
		}

		template <typename E>
		protected_function_result do_reader(lua_Reader reader, void* data, const basic_environment<E>& env,
		     const std::string& chunkname = detail::default_chunk_name(), load_mode mode = load_mode::any) {
			detail::typical_chunk_name_t basechunkname = {};
			const char* chunknametarget = detail::make_chunk_name("lua_Reader", chunkname, basechunkname);
			load_status x = static_cast<load_status>(lua_load(L, reader, data, chunknametarget, to_string(mode).c_str()));
			if (x != load_status::ok) {
				return protected_function_result(L, absolute_index(L, -1), 0, 1, static_cast<call_status>(x));
			}
			stack_aligned_protected_function pf(L, -1);
			set_environment(env, pf);
			return pf();
		}

		protected_function_result do_reader(
		     lua_Reader reader, void* data, const std::string& chunkname = detail::default_chunk_name(), load_mode mode = load_mode::any) {
			detail::typical_chunk_name_t basechunkname = {};
			const char* chunknametarget = detail::make_chunk_name("lua_Reader", chunkname, basechunkname);
			load_status x = static_cast<load_status>(lua_load(L, reader, data, chunknametarget, to_string(mode).c_str()));
			if (x != load_status::ok) {
				return protected_function_result(L, absolute_index(L, -1), 0, 1, static_cast<call_status>(x));
			}
			stack_aligned_protected_function pf(L, -1);
			return pf();
		}

		template <typename E>
		protected_function_result do_string(const string_view& code, const basic_environment<E>& env,
		     const std::string& chunkname = detail::default_chunk_name(), load_mode mode = load_mode::any) {
			detail::typical_chunk_name_t basechunkname = {};
			const char* chunknametarget = detail::make_chunk_name(code, chunkname, basechunkname);
			load_status x = static_cast<load_status>(luaL_loadbufferx(L, code.data(), code.size(), chunknametarget, to_string(mode).c_str()));
			if (x != load_status::ok) {
				return protected_function_result(L, absolute_index(L, -1), 0, 1, static_cast<call_status>(x));
			}
			stack_aligned_protected_function pf(L, -1);
			set_environment(env, pf);
			return pf();
		}

		protected_function_result do_string(
		     const string_view& code, const std::string& chunkname = detail::default_chunk_name(), load_mode mode = load_mode::any) {
			detail::typical_chunk_name_t basechunkname = {};
			const char* chunknametarget = detail::make_chunk_name(code, chunkname, basechunkname);
			load_status x = static_cast<load_status>(luaL_loadbufferx(L, code.data(), code.size(), chunknametarget, to_string(mode).c_str()));
			if (x != load_status::ok) {
				return protected_function_result(L, absolute_index(L, -1), 0, 1, static_cast<call_status>(x));
			}
			stack_aligned_protected_function pf(L, -1);
			return pf();
		}

		template <typename E>
		protected_function_result do_file(const std::string& filename, const basic_environment<E>& env, load_mode mode = load_mode::any) {
			load_status x = static_cast<load_status>(luaL_loadfilex(L, filename.c_str(), to_string(mode).c_str()));
			if (x != load_status::ok) {
				return protected_function_result(L, absolute_index(L, -1), 0, 1, static_cast<call_status>(x));
			}
			stack_aligned_protected_function pf(L, -1);
			set_environment(env, pf);
			return pf();
		}

		protected_function_result do_file(const std::string& filename, load_mode mode = load_mode::any) {
			load_status x = static_cast<load_status>(luaL_loadfilex(L, filename.c_str(), to_string(mode).c_str()));
			if (x != load_status::ok) {
				return protected_function_result(L, absolute_index(L, -1), 0, 1, static_cast<call_status>(x));
			}
			stack_aligned_protected_function pf(L, -1);
			return pf();
		}

		template <typename Fx,
		     meta::disable_any<meta::is_string_constructible<meta::unqualified_t<Fx>>,
		          meta::is_specialization_of<meta::unqualified_t<Fx>, basic_environment>> = meta::enabler>
		protected_function_result safe_script(
		     lua_Reader reader, void* data, Fx&& on_error, const std::string& chunkname = detail::default_chunk_name(), load_mode mode = load_mode::any) {
			protected_function_result pfr = do_reader(reader, data, chunkname, mode);
			if (!pfr.valid()) {
				return on_error(L, std::move(pfr));
			}
			return pfr;
		}

		protected_function_result safe_script(
		     lua_Reader reader, void* data, const std::string& chunkname = detail::default_chunk_name(), load_mode mode = load_mode::any) {
			return safe_script(reader, data, script_default_on_error, chunkname, mode);
		}

		template <typename Fx,
		     meta::disable_any<meta::is_string_constructible<meta::unqualified_t<Fx>>,
		          meta::is_specialization_of<meta::unqualified_t<Fx>, basic_environment>> = meta::enabler>
		protected_function_result safe_script(
		     const string_view& code, Fx&& on_error, const std::string& chunkname = detail::default_chunk_name(), load_mode mode = load_mode::any) {
			protected_function_result pfr = do_string(code, chunkname, mode);
			if (!pfr.valid()) {
				return on_error(L, std::move(pfr));
			}
			return pfr;
		}

		template <typename Fx, typename E>
		protected_function_result safe_script(const string_view& code, const basic_environment<E>& env, Fx&& on_error,
		     const std::string& chunkname = detail::default_chunk_name(), load_mode mode = load_mode::any) {
			protected_function_result pfr = do_string(code, env, chunkname, mode);
			if (!pfr.valid()) {
				return on_error(L, std::move(pfr));
			}
			return pfr;
		}

		template <typename E>
		protected_function_result safe_script(const string_view& code, const basic_environment<E>& env,
		     const std::string& chunkname = detail::default_chunk_name(), load_mode mode = load_mode::any) {
			return safe_script(code, env, script_default_on_error, chunkname, mode);
		}

		protected_function_result safe_script(
		     const string_view& code, const std::string& chunkname = detail::default_chunk_name(), load_mode mode = load_mode::any) {
			return safe_script(code, script_default_on_error, chunkname, mode);
		}

		template <typename Fx,
		     meta::disable_any<meta::is_string_constructible<meta::unqualified_t<Fx>>,
		          meta::is_specialization_of<meta::unqualified_t<Fx>, basic_environment>> = meta::enabler>
		protected_function_result safe_script_file(const std::string& filename, Fx&& on_error, load_mode mode = load_mode::any) {
			protected_function_result pfr = do_file(filename, mode);
			if (!pfr.valid()) {
				return on_error(L, std::move(pfr));
			}
			return pfr;
		}

		template <typename Fx, typename E>
		protected_function_result safe_script_file(
		     const std::string& filename, const basic_environment<E>& env, Fx&& on_error, load_mode mode = load_mode::any) {
			protected_function_result pfr = do_file(filename, env, mode);
			if (!pfr.valid()) {
				return on_error(L, std::move(pfr));
			}
			return pfr;
		}

		template <typename E>
		protected_function_result safe_script_file(const std::string& filename, const basic_environment<E>& env, load_mode mode = load_mode::any) {
			return safe_script_file(filename, env, script_default_on_error, mode);
		}

		protected_function_result safe_script_file(const std::string& filename, load_mode mode = load_mode::any) {
			return safe_script_file(filename, script_default_on_error, mode);
		}

		template <typename E>
		unsafe_function_result unsafe_script(lua_Reader reader, void* data, const basic_environment<E>& env,
		     const std::string& chunkname = detail::default_chunk_name(), load_mode mode = load_mode::any) {
			detail::typical_chunk_name_t basechunkname = {};
			const char* chunknametarget = detail::make_chunk_name("lua_Reader", chunkname, basechunkname);
			int index = lua_gettop(L);
			if (lua_load(L, reader, data, chunknametarget, to_string(mode).c_str())) {
				lua_error(L);
			}
			set_environment(env, stack_reference(L, raw_index(index + 1)));
			if (lua_pcall(L, 0, LUA_MULTRET, 0)) {
				lua_error(L);
			}
			int postindex = lua_gettop(L);
			int returns = postindex - index;
			return unsafe_function_result(L, (std::max)(postindex - (returns - 1), 1), returns);
		}

		unsafe_function_result unsafe_script(
		     lua_Reader reader, void* data, const std::string& chunkname = detail::default_chunk_name(), load_mode mode = load_mode::any) {
			int index = lua_gettop(L);
			stack::script(L, reader, data, chunkname, mode);
			int postindex = lua_gettop(L);
			int returns = postindex - index;
			return unsafe_function_result(L, (std::max)(postindex - (returns - 1), 1), returns);
		}

		template <typename E>
		unsafe_function_result unsafe_script(const string_view& code, const basic_environment<E>& env,
		     const std::string& chunkname = detail::default_chunk_name(), load_mode mode = load_mode::any) {
			detail::typical_chunk_name_t basechunkname = {};
			const char* chunknametarget = detail::make_chunk_name(code, chunkname, basechunkname);
			int index = lua_gettop(L);
			if (luaL_loadbufferx(L, code.data(), code.size(), chunknametarget, to_string(mode).c_str())) {
				lua_error(L);
			}
			set_environment(env, stack_reference(L, raw_index(index + 1)));
			if (lua_pcall(L, 0, LUA_MULTRET, 0)) {
				lua_error(L);
			}
			int postindex = lua_gettop(L);
			int returns = postindex - index;
			return unsafe_function_result(L, (std::max)(postindex - (returns - 1), 1), returns);
		}

		unsafe_function_result unsafe_script(
		     const string_view& code, const std::string& chunkname = detail::default_chunk_name(), load_mode mode = load_mode::any) {
			int index = lua_gettop(L);
			stack::script(L, code, chunkname, mode);
			int postindex = lua_gettop(L);
			int returns = postindex - index;
			return unsafe_function_result(L, (std::max)(postindex - (returns - 1), 1), returns);
		}

		template <typename E>
		unsafe_function_result unsafe_script_file(const std::string& filename, const basic_environment<E>& env, load_mode mode = load_mode::any) {
			int index = lua_gettop(L);
			if (luaL_loadfilex(L, filename.c_str(), to_string(mode).c_str())) {
				lua_error(L);
			}
			set_environment(env, stack_reference(L, raw_index(index + 1)));
			if (lua_pcall(L, 0, LUA_MULTRET, 0)) {
				lua_error(L);
			}
			int postindex = lua_gettop(L);
			int returns = postindex - index;
			return unsafe_function_result(L, (std::max)(postindex - (returns - 1), 1), returns);
		}

		unsafe_function_result unsafe_script_file(const std::string& filename, load_mode mode = load_mode::any) {
			int index = lua_gettop(L);
			stack::script_file(L, filename, mode);
			int postindex = lua_gettop(L);
			int returns = postindex - index;
			return unsafe_function_result(L, (std::max)(postindex - (returns - 1), 1), returns);
		}

		template <typename Fx,
		     meta::disable_any<meta::is_string_constructible<meta::unqualified_t<Fx>>,
		          meta::is_specialization_of<meta::unqualified_t<Fx>, basic_environment>> = meta::enabler>
		protected_function_result script(
		     const string_view& code, Fx&& on_error, const std::string& chunkname = detail::default_chunk_name(), load_mode mode = load_mode::any) {
			return safe_script(code, std::forward<Fx>(on_error), chunkname, mode);
		}

		template <typename Fx,
		     meta::disable_any<meta::is_string_constructible<meta::unqualified_t<Fx>>,
		          meta::is_specialization_of<meta::unqualified_t<Fx>, basic_environment>> = meta::enabler>
		protected_function_result script_file(const std::string& filename, Fx&& on_error, load_mode mode = load_mode::any) {
			return safe_script_file(filename, std::forward<Fx>(on_error), mode);
		}

		template <typename Fx, typename E>
		protected_function_result script(const string_view& code, const basic_environment<E>& env, Fx&& on_error,
		     const std::string& chunkname = detail::default_chunk_name(), load_mode mode = load_mode::any) {
			return safe_script(code, env, std::forward<Fx>(on_error), chunkname, mode);
		}

		template <typename Fx, typename E>
		protected_function_result script_file(const std::string& filename, const basic_environment<E>& env, Fx&& on_error, load_mode mode = load_mode::any) {
			return safe_script_file(filename, env, std::forward<Fx>(on_error), mode);
		}

		protected_function_result script(
		     const string_view& code, const environment& env, const std::string& chunkname = detail::default_chunk_name(), load_mode mode = load_mode::any) {
			return safe_script(code, env, script_default_on_error, chunkname, mode);
		}

		protected_function_result script_file(const std::string& filename, const environment& env, load_mode mode = load_mode::any) {
			return safe_script_file(filename, env, script_default_on_error, mode);
		}

#if SOL_IS_ON(SOL_SAFE_FUNCTION_OBJECTS)
		protected_function_result script(
		     lua_Reader reader, void* data, const std::string& chunkname = detail::default_chunk_name(), load_mode mode = load_mode::any) {
			return safe_script(reader, data, chunkname, mode);
		}

		protected_function_result script(
		     const string_view& code, const std::string& chunkname = detail::default_chunk_name(), load_mode mode = load_mode::any) {
			return safe_script(code, chunkname, mode);
		}

		protected_function_result script_file(const std::string& filename, load_mode mode = load_mode::any) {
			return safe_script_file(filename, mode);
		}
#else
		unsafe_function_result script(const string_view& code, const std::string& chunkname = detail::default_chunk_name(), load_mode mode = load_mode::any) {
			return unsafe_script(code, chunkname, mode);
		}

		unsafe_function_result script_file(const std::string& filename, load_mode mode = load_mode::any) {
			return unsafe_script_file(filename, mode);
		}
#endif
		load_result load(const string_view& code, const std::string& chunkname = detail::default_chunk_name(), load_mode mode = load_mode::any) {
			detail::typical_chunk_name_t basechunkname = {};
			const char* chunknametarget = detail::make_chunk_name(code, chunkname, basechunkname);
			load_status x = static_cast<load_status>(luaL_loadbufferx(L, code.data(), code.size(), chunknametarget, to_string(mode).c_str()));
			return load_result(L, absolute_index(L, -1), 1, 1, x);
		}

		load_result load_buffer(const char* buff, size_t size, const std::string& chunkname = detail::default_chunk_name(), load_mode mode = load_mode::any) {
			return load(string_view(buff, size), chunkname, mode);
		}

		load_result load_buffer(
		     const std::byte* buff, size_t size, const std::string& chunkname = detail::default_chunk_name(), load_mode mode = load_mode::any) {
			return load(string_view(reinterpret_cast<const char*>(buff), size), chunkname, mode);
		}

		load_result load_file(const std::string& filename, load_mode mode = load_mode::any) {
			load_status x = static_cast<load_status>(luaL_loadfilex(L, filename.c_str(), to_string(mode).c_str()));
			return load_result(L, absolute_index(L, -1), 1, 1, x);
		}

		load_result load(lua_Reader reader, void* data, const std::string& chunkname = detail::default_chunk_name(), load_mode mode = load_mode::any) {
			detail::typical_chunk_name_t basechunkname = {};
			const char* chunknametarget = detail::make_chunk_name("lua_Reader", chunkname, basechunkname);
			load_status x = static_cast<load_status>(lua_load(L, reader, data, chunknametarget, to_string(mode).c_str()));
			return load_result(L, absolute_index(L, -1), 1, 1, x);
		}

		iterator begin() const {
			return global.begin();
		}

		iterator end() const {
			return global.end();
		}

		const_iterator cbegin() const {
			return global.cbegin();
		}

		const_iterator cend() const {
			return global.cend();
		}

		global_table globals() const {
			// if we return a reference
			// we'll be screwed a bit
			return global;
		}

		global_table& globals() {
			return global;
		}

		table registry() const {
			return reg;
		}

		std::size_t memory_used() const {
			return total_memory_used(lua_state());
		}

		int stack_top() const {
			return stack::top(L);
		}

		int stack_clear() {
			int s = stack_top();
			lua_pop(L, s);
			return s;
		}

		bool supports_gc_mode(gc_mode mode) const noexcept {
#if SOL_LUA_VERSION_I_ >= 504
			// supports all modes
			(void)mode;
			return true;
#endif
			return mode == gc_mode::default_value;
		}

		bool is_gc_on() const {
#if SOL_LUA_VERSION_I_ >= 502
			return lua_gc(lua_state(), LUA_GCISRUNNING, 0) == 1;
#else
			// You cannot turn it off in Lua 5.1
			return true;
#endif
		}

		void collect_garbage() {
			lua_gc(lua_state(), LUA_GCCOLLECT, 0);
		}

		void collect_gc() {
			collect_garbage();
		}

		bool step_gc(int step_size_kilobytes) {
			// THOUGHT: std::chrono-alikes to map "kilobyte size" here...?
			// Make it harder to give MB or KB to a B parameter...?
			// Probably overkill for now.
#if SOL_LUA_VERSION_I_ >= 504
			// The manual implies that this function is almost always successful...
			// is it?? It could depend on the GC mode...
			return lua_gc(lua_state(), LUA_GCSTEP, step_size_kilobytes) != 0;
#else
			return lua_gc(lua_state(), LUA_GCSTEP, step_size_kilobytes) == 1;
#endif
		}

		void restart_gc() {
			lua_gc(lua_state(), LUA_GCRESTART, 0);
		}

		void stop_gc() {
			lua_gc(lua_state(), LUA_GCSTOP, 0);
		}

		// Returns the old GC mode. Check support using the supports_gc_mode function.
		gc_mode change_gc_mode_incremental(int pause, int step_multiplier, int step_byte_size) {
			// "What the fuck does any of this mean??"
			// http://www.lua.org/manual/5.4/manual.html#2.5.1

			// THOUGHT: std::chrono-alikes to map "byte size" here...?
			// Make it harder to give MB or KB to a B parameter...?
			// Probably overkill for now.
#if SOL_LUA_VERSION_I_ >= 504
			int old_mode = lua_gc(lua_state(), LUA_GCINC, pause, step_multiplier, step_byte_size);
			if (old_mode == LUA_GCGEN) {
				return gc_mode::generational;
			}
			else if (old_mode == LUA_GCINC) {
				return gc_mode::incremental;
			}
#else
			lua_gc(lua_state(), LUA_GCSETPAUSE, pause);
			lua_gc(lua_state(), LUA_GCSETSTEPMUL, step_multiplier);
			(void)step_byte_size; // means nothing in older versions
#endif
			return gc_mode::default_value;
		}

		// Returns the old GC mode. Check support using the supports_gc_mode function.
		gc_mode change_gc_mode_generational(int minor_multiplier, int major_multiplier) {
#if SOL_LUA_VERSION_I_ >= 504
			// "What does this shit mean?"
			// http://www.lua.org/manual/5.4/manual.html#2.5.2
			int old_mode = lua_gc(lua_state(), LUA_GCGEN, minor_multiplier, major_multiplier);
			if (old_mode == LUA_GCGEN) {
				return gc_mode::generational;
			}
			else if (old_mode == LUA_GCINC) {
				return gc_mode::incremental;
			}
#else
			(void)minor_multiplier;
			(void)major_multiplier;
#endif
			return gc_mode::default_value;
		}

		operator lua_State*() const {
			return lua_state();
		}

		void set_panic(lua_CFunction panic) {
			lua_atpanic(lua_state(), panic);
		}

		void set_exception_handler(exception_handler_function handler) {
			set_default_exception_handler(lua_state(), handler);
		}

		template <typename... Args, typename... Keys>
		decltype(auto) get(Keys&&... keys) const {
			return global.get<Args...>(std::forward<Keys>(keys)...);
		}

		template <typename T, typename Key>
		decltype(auto) get_or(Key&& key, T&& otherwise) const {
			return global.get_or(std::forward<Key>(key), std::forward<T>(otherwise));
		}

		template <typename T, typename Key, typename D>
		decltype(auto) get_or(Key&& key, D&& otherwise) const {
			return global.get_or<T>(std::forward<Key>(key), std::forward<D>(otherwise));
		}

		template <typename... Args>
		state_view& set(Args&&... args) {
			global.set(std::forward<Args>(args)...);
			return *this;
		}

		template <typename T, typename... Keys>
		decltype(auto) traverse_get(Keys&&... keys) const {
			return global.traverse_get<T>(std::forward<Keys>(keys)...);
		}

		template <typename... Args>
		state_view& traverse_set(Args&&... args) {
			global.traverse_set(std::forward<Args>(args)...);
			return *this;
		}

		template <typename Class, typename... Args>
		usertype<Class> new_usertype(Args&&... args) {
			return global.new_usertype<Class>(std::forward<Args>(args)...);
		}

		template <bool read_only = true, typename... Args>
		state_view& new_enum(const string_view& name, Args&&... args) {
			global.new_enum<read_only>(name, std::forward<Args>(args)...);
			return *this;
		}

		template <typename T, bool read_only = true>
		state_view& new_enum(const string_view& name, std::initializer_list<std::pair<string_view, T>> items) {
			global.new_enum<T, read_only>(name, std::move(items));
			return *this;
		}

		template <typename Fx>
		void for_each(Fx&& fx) {
			global.for_each(std::forward<Fx>(fx));
		}

		template <typename T>
		table_proxy<global_table&, detail::proxy_key_t<T>> operator[](T&& key) {
			return global[std::forward<T>(key)];
		}

		template <typename T>
		table_proxy<const global_table&, detail::proxy_key_t<T>> operator[](T&& key) const {
			return global[std::forward<T>(key)];
		}

		template <typename Sig, typename... Args, typename Key>
		state_view& set_function(Key&& key, Args&&... args) {
			global.set_function<Sig>(std::forward<Key>(key), std::forward<Args>(args)...);
			return *this;
		}

		template <typename... Args, typename Key>
		state_view& set_function(Key&& key, Args&&... args) {
			global.set_function(std::forward<Key>(key), std::forward<Args>(args)...);
			return *this;
		}

		template <typename Name>
		table create_table(Name&& name, int narr = 0, int nrec = 0) {
			return global.create(std::forward<Name>(name), narr, nrec);
		}

		template <typename Name, typename Key, typename Value, typename... Args>
		table create_table(Name&& name, int narr, int nrec, Key&& key, Value&& value, Args&&... args) {
			return global.create(std::forward<Name>(name), narr, nrec, std::forward<Key>(key), std::forward<Value>(value), std::forward<Args>(args)...);
		}

		template <typename Name, typename... Args>
		table create_named_table(Name&& name, Args&&... args) {
			table x = global.create_with(std::forward<Args>(args)...);
			global.set(std::forward<Name>(name), x);
			return x;
		}

		table create_table(int narr = 0, int nrec = 0) {
			return create_table(lua_state(), narr, nrec);
		}

		template <typename Key, typename Value, typename... Args>
		table create_table(int narr, int nrec, Key&& key, Value&& value, Args&&... args) {
			return create_table(lua_state(), narr, nrec, std::forward<Key>(key), std::forward<Value>(value), std::forward<Args>(args)...);
		}

		template <typename... Args>
		table create_table_with(Args&&... args) {
			return create_table_with(lua_state(), std::forward<Args>(args)...);
		}

		static inline table create_table(lua_State* L, int narr = 0, int nrec = 0) {
			return global_table::create(L, narr, nrec);
		}

		template <typename Key, typename Value, typename... Args>
		static inline table create_table(lua_State* L, int narr, int nrec, Key&& key, Value&& value, Args&&... args) {
			return global_table::create(L, narr, nrec, std::forward<Key>(key), std::forward<Value>(value), std::forward<Args>(args)...);
		}

		template <typename... Args>
		static inline table create_table_with(lua_State* L, Args&&... args) {
			return global_table::create_with(L, std::forward<Args>(args)...);
		}
	};
} // namespace sol

#endif // SOL_STATE_VIEW_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_STATE_HPP
#define SOL_STATE_HPP

#include <sol/state_view.hpp>
#include <sol/thread.hpp>

namespace sol {

	class state : private std::unique_ptr<lua_State, detail::state_deleter>, public state_view {
	private:
		typedef std::unique_ptr<lua_State, detail::state_deleter> unique_base;

	public:
		state(lua_CFunction panic = default_at_panic) : unique_base(luaL_newstate()), state_view(unique_base::get()) {
			set_default_state(unique_base::get(), panic);
		}

		state(lua_CFunction panic, lua_Alloc alfunc, void* alpointer = nullptr)
		: unique_base(lua_newstate(alfunc, alpointer)), state_view(unique_base::get()) {
			set_default_state(unique_base::get(), panic);
		}

		state(const state&) = delete;
		state(state&&) = default;
		state& operator=(const state&) = delete;
		state& operator=(state&& that) {
			state_view::operator=(std::move(that));
			unique_base::operator=(std::move(that));
			return *this;
		}

		using state_view::get;

		~state() {
		}
	};
} // namespace sol

#endif // SOL_STATE_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_FUNCTION_RESULT_HPP
#define SOL_FUNCTION_RESULT_HPP

#include <sol/protected_function_result.hpp>
#include <sol/unsafe_function_result.hpp>

#include <cstdint>

namespace sol {

	namespace detail {
		template <>
		struct is_speshul<unsafe_function_result> : std::true_type { };
		template <>
		struct is_speshul<protected_function_result> : std::true_type { };

		template <std::size_t I, typename... Args, typename T>
		stack_proxy get(types<Args...>, meta::index_value<0>, meta::index_value<I>, const T& fr) {
			return stack_proxy(fr.lua_state(), fr.stack_index() + static_cast<int>(I));
		}

		template <std::size_t I, std::size_t N, typename Arg, typename... Args, typename T, meta::enable<meta::boolean<(N > 0)>> = meta::enabler>
		stack_proxy get(types<Arg, Args...>, meta::index_value<N>, meta::index_value<I>, const T& fr) {
			return get(types<Args...>(), meta::index_value<N - 1>(), meta::index_value<I + lua_size<Arg>::value>(), fr);
		}
	} // namespace detail

	template <>
	struct tie_size<unsafe_function_result> : std::integral_constant<std::size_t, SIZE_MAX> { };

	template <>
	struct tie_size<protected_function_result> : std::integral_constant<std::size_t, SIZE_MAX> { };

	template <std::size_t I>
	stack_proxy get(const unsafe_function_result& fr) {
		return stack_proxy(fr.lua_state(), fr.stack_index() + static_cast<int>(I));
	}

	template <std::size_t I, typename... Args>
	stack_proxy get(types<Args...> t, const unsafe_function_result& fr) {
		return detail::get(t, meta::index_value<I>(), meta::index_value<0>(), fr);
	}

	template <std::size_t I>
	stack_proxy get(const protected_function_result& fr) {
		return stack_proxy(fr.lua_state(), fr.stack_index() + static_cast<int>(I));
	}

	template <std::size_t I, typename... Args>
	stack_proxy get(types<Args...> t, const protected_function_result& fr) {
		return detail::get(t, meta::index_value<I>(), meta::index_value<0>(), fr);
	}
} // namespace sol

#endif // SOL_FUNCTION_RESULT_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_THREAD_HPP
#define SOL_THREAD_HPP

#include <sol/reference.hpp>
#include <sol/object.hpp>
#include <sol/stack.hpp>
#include <sol/state_view.hpp>

namespace sol {
	struct lua_thread_state {
		lua_State* L;

		lua_thread_state(lua_State* Ls) : L(Ls) {
		}

		lua_State* lua_state() const noexcept {
			return L;
		}
		operator lua_State*() const noexcept {
			return lua_state();
		}
		lua_State* operator->() const noexcept {
			return lua_state();
		}
	};

	namespace stack {
		template <>
		struct unqualified_pusher<lua_thread_state> {
			int push(lua_State*, lua_thread_state lts) {
				lua_pushthread(lts.L);
				return 1;
			}
		};

		template <>
		struct unqualified_getter<lua_thread_state> {
			lua_thread_state get(lua_State* L, int index, record& tracking) {
				tracking.use(1);
				lua_thread_state lts(lua_tothread(L, index));
				return lts;
			}
		};

		template <>
		struct unqualified_check_getter<lua_thread_state> {
			template <typename Handler>
			optional<lua_thread_state> get(lua_State* L, int index, Handler&& handler, record& tracking) {
				lua_thread_state lts(lua_tothread(L, index));
				if (lts.lua_state() == nullptr) {
					handler(L, index, type::thread, type_of(L, index), "value is not a valid thread type");
					return nullopt;
				}
				tracking.use(1);
				return lts;
			}
		};
	} // namespace stack

	template <typename ref_t>
	class basic_thread : public basic_object<ref_t> {
	private:
		using base_t = basic_object<ref_t>;

	public:
		using base_t::lua_state;

		basic_thread() noexcept = default;
		basic_thread(const basic_thread&) = default;
		basic_thread(basic_thread&&) = default;
		template <typename T,
		     meta::enable<meta::neg<std::is_same<meta::unqualified_t<T>, basic_thread>>, is_lua_reference<meta::unqualified_t<T>>> = meta::enabler>
		basic_thread(T&& r) : base_t(std::forward<T>(r)) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			auto pp = stack::push_pop(*this);
			constructor_handler handler {};
			stack::check<basic_thread>(lua_state(), -1, handler);
#endif // Safety
		}
		basic_thread(const stack_reference& r) : basic_thread(r.lua_state(), r.stack_index()) {};
		basic_thread(stack_reference&& r) : basic_thread(r.lua_state(), r.stack_index()) {};
		basic_thread& operator=(const basic_thread&) = default;
		basic_thread& operator=(basic_thread&&) = default;
		template <typename T, meta::enable<is_lua_reference<meta::unqualified_t<T>>> = meta::enabler>
		basic_thread(lua_State* L, T&& r) : base_t(L, std::forward<T>(r)) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			auto pp = stack::push_pop(*this);
			constructor_handler handler {};
			stack::check<basic_thread>(lua_state(), -1, handler);
#endif // Safety
		}
		basic_thread(lua_State* L, int index = -1) : base_t(L, index) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			constructor_handler handler {};
			stack::check<basic_thread>(L, index, handler);
#endif // Safety
		}
		basic_thread(lua_State* L, ref_index index) : base_t(L, index) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			auto pp = stack::push_pop(*this);
			constructor_handler handler {};
			stack::check<basic_thread>(lua_state(), -1, handler);
#endif // Safety
		}
		basic_thread(lua_State* L, lua_State* actualthread) : basic_thread(L, lua_thread_state { actualthread }) {
		}
		basic_thread(lua_State* L, this_state actualthread) : basic_thread(L, lua_thread_state { actualthread.L }) {
		}
		basic_thread(lua_State* L, lua_thread_state actualthread) : base_t(L, -stack::push(L, actualthread)) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			constructor_handler handler {};
			stack::check<basic_thread>(lua_state(), -1, handler);
#endif // Safety
			if (!is_stack_based<base_t>::value) {
				lua_pop(lua_state(), 1);
			}
		}

		state_view state() const {
			return state_view(this->thread_state());
		}

		bool is_main_thread() const {
			return stack::is_main_thread(this->thread_state());
		}

		lua_State* thread_state() const {
			auto pp = stack::push_pop(*this);
			lua_State* lthread = lua_tothread(lua_state(), -1);
			return lthread;
		}

		thread_status status() const {
			lua_State* lthread = thread_state();
			auto lstat = static_cast<thread_status>(lua_status(lthread));
			if (lstat == thread_status::ok) {
				lua_Debug ar;
				if (lua_getstack(lthread, 0, &ar) > 0)
					return thread_status::ok;
				else if (lua_gettop(lthread) == 0)
					return thread_status::dead;
				else
					return thread_status::yielded;
			}
			return lstat;
		}

		basic_thread create() {
			return create(lua_state());
		}

		static basic_thread create(lua_State* L) {
			lua_newthread(L);
			basic_thread result(L);
			if (!is_stack_based<base_t>::value) {
				lua_pop(L, 1);
			}
			return result;
		}
	};

	typedef basic_thread<reference> thread;
	typedef basic_thread<stack_reference> stack_thread;
} // namespace sol

#endif // SOL_THREAD_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_PROTECTED_HANDLER_HPP
#define SOL_PROTECTED_HANDLER_HPP

#include <sol/reference.hpp>
#include <sol/stack.hpp>
#include <sol/protected_function_result.hpp>
#include <sol/unsafe_function.hpp>
#include <cstdint>

namespace sol { namespace detail {
	inline const char (&default_handler_name())[9] {
		static const char name[9] = "sol.\xF0\x9F\x94\xA9";
		return name;
	}

	template <bool ShouldPush, typename Target = reference>
	struct protected_handler {
		lua_State* m_L;
		const Target& target;
		int stack_index;

		protected_handler(std::false_type, lua_State* L_, const Target& target_) : m_L(L_), target(target_), stack_index(0) {
			if (ShouldPush) {
				stack_index = lua_gettop(L_) + 1;
				target.push(L_);
			}
		}

		protected_handler(std::true_type, lua_State* L_, const Target& target_) : m_L(L_), target(target_), stack_index(0) {
			if (ShouldPush) {
				stack_index = target.stack_index();
			}
		}

		protected_handler(lua_State* L_, const Target& target_) : protected_handler(meta::boolean<is_stack_based_v<Target>>(), L_, target_) {
		}

		bool valid() const noexcept {
			return ShouldPush;
		}

		~protected_handler() {
			if constexpr (!is_stack_based_v<Target>) {
				if (stack_index != 0) {
					lua_remove(m_L, stack_index);
				}
			}
		}
	};

	template <typename Base, typename T>
	inline basic_function<Base> force_cast(T& p) {
		return p;
	}

	template <typename Reference, bool IsMainReference = false>
	inline Reference get_default_handler(lua_State* L_) {
		if (is_stack_based_v<Reference> || L_ == nullptr)
			return Reference(L_, lua_nil);
		L_ = IsMainReference ? main_thread(L_, L_) : L_;
		lua_getglobal(L_, default_handler_name());
		auto pp = stack::pop_n(L_, 1);
		return Reference(L_, -1);
	}

	template <typename T>
	inline void set_default_handler(lua_State* L, const T& ref) {
		if (L == nullptr) {
			return;
		}
		if (!ref.valid()) {
#if SOL_IS_ON(SOL_SAFE_STACK_CHECK)
			luaL_checkstack(L, 1, detail::not_enough_stack_space_generic);
#endif // make sure stack doesn't overflow
			lua_pushnil(L);
			lua_setglobal(L, default_handler_name());
		}
		else {
			ref.push(L);
			lua_setglobal(L, default_handler_name());
		}
	}
}} // namespace sol::detail

#endif // SOL_PROTECTED_HANDLER_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_COROUTINE_HPP
#define SOL_COROUTINE_HPP

#include <sol/reference.hpp>
#include <sol/object.hpp>
#include <sol/stack.hpp>
#include <sol/function_result.hpp>
#include <sol/thread.hpp>
#include <sol/protected_handler.hpp>

namespace sol {
	template <typename Reference>
	class basic_coroutine : public basic_object<Reference> {
	private:
		using base_t = basic_object<Reference>;
		using handler_t = reference;

	private:
		call_status stats = call_status::yielded;

		void luacall(std::ptrdiff_t argcount, std::ptrdiff_t) {
#if SOL_LUA_VERSION_I_ >= 504
			int nresults;
			stats = static_cast<call_status>(lua_resume(lua_state(), nullptr, static_cast<int>(argcount), &nresults));
#else
			stats = static_cast<call_status>(lua_resume(lua_state(), nullptr, static_cast<int>(argcount)));
#endif
		}

		template <std::size_t... I, typename... Ret>
		auto invoke(types<Ret...>, std::index_sequence<I...>, std::ptrdiff_t n) {
			luacall(n, sizeof...(Ret));
			return stack::pop<std::tuple<Ret...>>(lua_state());
		}

		template <std::size_t I, typename Ret>
		Ret invoke(types<Ret>, std::index_sequence<I>, std::ptrdiff_t n) {
			luacall(n, 1);
			return stack::pop<Ret>(lua_state());
		}

		template <std::size_t I>
		void invoke(types<void>, std::index_sequence<I>, std::ptrdiff_t n) {
			luacall(n, 0);
		}

		protected_function_result invoke(types<>, std::index_sequence<>, std::ptrdiff_t n) {
			int firstreturn = 1;
			luacall(n, LUA_MULTRET);
			int poststacksize = lua_gettop(this->lua_state());
			int returncount = poststacksize - (firstreturn - 1);
			if (error()) {
				if (m_error_handler.valid()) {
					string_view err = stack::get<string_view>(this->lua_state(), poststacksize);
					m_error_handler.push();
					stack::push(this->lua_state(), err);
					lua_call(lua_state(), 1, 1);
				}
				return protected_function_result(this->lua_state(), lua_absindex(this->lua_state(), -1), 1, returncount, status());
			}
			return protected_function_result(this->lua_state(), firstreturn, returncount, returncount, status());
		}

	public:
		using base_t::lua_state;

		basic_coroutine() = default;
		template <typename T,
		     meta::enable<meta::neg<std::is_same<meta::unqualified_t<T>, basic_coroutine>>,
		          meta::neg<std::is_base_of<proxy_base_tag, meta::unqualified_t<T>>>, meta::neg<std::is_same<base_t, stack_reference>>,
		          meta::neg<std::is_same<lua_nil_t, meta::unqualified_t<T>>>, is_lua_reference<meta::unqualified_t<T>>> = meta::enabler>
		basic_coroutine(T&& r) noexcept
		: base_t(std::forward<T>(r)), m_error_handler(detail::get_default_handler<reference, is_main_threaded<base_t>::value>(r.lua_state())) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			if (!is_function<meta::unqualified_t<T>>::value) {
				auto pp = stack::push_pop(*this);
				constructor_handler handler {};
				stack::check<basic_coroutine>(lua_state(), -1, handler);
			}
#endif // Safety
		}

		basic_coroutine(const basic_coroutine& other) = default;
		basic_coroutine& operator=(const basic_coroutine&) = default;

		basic_coroutine(basic_coroutine&& other) noexcept : base_t(std::move(other)), m_error_handler(this->lua_state(), std::move(other.m_error_handler)) {
		}

		basic_coroutine& operator=(basic_coroutine&& other) noexcept {
			base_t::operator=(std::move(other));
			// must change the state, since it could change on the coroutine type
			m_error_handler = handler_t(this->lua_state(), std::move(other.m_error_handler));
			return *this;
		}

		basic_coroutine(const basic_function<base_t>& b) noexcept
		: basic_coroutine(b, detail::get_default_handler<reference, is_main_threaded<base_t>::value>(b.lua_state())) {
		}
		basic_coroutine(basic_function<base_t>&& b) noexcept
		: basic_coroutine(std::move(b), detail::get_default_handler<reference, is_main_threaded<base_t>::value>(b.lua_state())) {
		}
		basic_coroutine(const basic_function<base_t>& b, handler_t eh) noexcept : base_t(b), m_error_handler(std::move(eh)) {
		}
		basic_coroutine(basic_function<base_t>&& b, handler_t eh) noexcept : base_t(std::move(b)), m_error_handler(std::move(eh)) {
		}
		basic_coroutine(const stack_reference& r) noexcept
		: basic_coroutine(r.lua_state(), r.stack_index(), detail::get_default_handler<reference, is_main_threaded<base_t>::value>(r.lua_state())) {
		}
		basic_coroutine(stack_reference&& r) noexcept
		: basic_coroutine(r.lua_state(), r.stack_index(), detail::get_default_handler<reference, is_main_threaded<base_t>::value>(r.lua_state())) {
		}
		basic_coroutine(const stack_reference& r, handler_t eh) noexcept : basic_coroutine(r.lua_state(), r.stack_index(), std::move(eh)) {
		}
		basic_coroutine(stack_reference&& r, handler_t eh) noexcept : basic_coroutine(r.lua_state(), r.stack_index(), std::move(eh)) {
		}

		template <typename Super>
		basic_coroutine(const proxy_base<Super>& p)
		: basic_coroutine(p, detail::get_default_handler<reference, is_main_threaded<base_t>::value>(p.lua_state())) {
		}
		template <typename Super>
		basic_coroutine(proxy_base<Super>&& p)
		: basic_coroutine(std::move(p), detail::get_default_handler<reference, is_main_threaded<base_t>::value>(p.lua_state())) {
		}
		template <typename Proxy, typename HandlerReference,
		     meta::enable<std::is_base_of<proxy_base_tag, meta::unqualified_t<Proxy>>,
		          meta::neg<is_lua_index<meta::unqualified_t<HandlerReference>>>> = meta::enabler>
		basic_coroutine(Proxy&& p, HandlerReference&& eh) : basic_coroutine(detail::force_cast<base_t>(p), std::forward<HandlerReference>(eh)) {
		}

		template <typename T, meta::enable<is_lua_reference<meta::unqualified_t<T>>> = meta::enabler>
		basic_coroutine(lua_State* L, T&& r) noexcept
		: basic_coroutine(L, std::forward<T>(r), detail::get_default_handler<reference, is_main_threaded<base_t>::value>(L)) {
		}
		template <typename T, meta::enable<is_lua_reference<meta::unqualified_t<T>>> = meta::enabler>
		basic_coroutine(lua_State* L, T&& r, handler_t eh) : base_t(L, std::forward<T>(r)), m_error_handler(std::move(eh)) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			auto pp = stack::push_pop(*this);
			constructor_handler handler {};
			stack::check<basic_coroutine>(lua_state(), -1, handler);
#endif // Safety
		}

		basic_coroutine(lua_nil_t n) : base_t(n), m_error_handler(n) {
		}

		basic_coroutine(lua_State* L, int index = -1)
		: basic_coroutine(L, index, detail::get_default_handler<reference, is_main_threaded<base_t>::value>(L)) {
		}
		basic_coroutine(lua_State* L, int index, handler_t eh) : base_t(L, index), m_error_handler(std::move(eh)) {
#ifdef SOL_SAFE_REFERENCES
			constructor_handler handler {};
			stack::check<basic_coroutine>(L, index, handler);
#endif // Safety
		}
		basic_coroutine(lua_State* L, absolute_index index)
		: basic_coroutine(L, index, detail::get_default_handler<reference, is_main_threaded<base_t>::value>(L)) {
		}
		basic_coroutine(lua_State* L, absolute_index index, handler_t eh) : base_t(L, index), m_error_handler(std::move(eh)) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			constructor_handler handler {};
			stack::check<basic_coroutine>(L, index, handler);
#endif // Safety
		}
		basic_coroutine(lua_State* L, raw_index index)
		: basic_coroutine(L, index, detail::get_default_handler<reference, is_main_threaded<base_t>::value>(L)) {
		}
		basic_coroutine(lua_State* L, raw_index index, handler_t eh) : base_t(L, index), m_error_handler(std::move(eh)) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			constructor_handler handler {};
			stack::check<basic_coroutine>(L, index, handler);
#endif // Safety
		}
		basic_coroutine(lua_State* L, ref_index index)
		: basic_coroutine(L, index, detail::get_default_handler<reference, is_main_threaded<base_t>::value>(L)) {
		}
		basic_coroutine(lua_State* L, ref_index index, handler_t eh) : base_t(L, index), m_error_handler(std::move(eh)) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			auto pp = stack::push_pop(*this);
			constructor_handler handler {};
			stack::check<basic_coroutine>(lua_state(), -1, handler);
#endif // Safety
		}

		call_status status() const noexcept {
			return stats;
		}

		bool error() const noexcept {
			call_status cs = status();
			return cs != call_status::ok && cs != call_status::yielded;
		}

		bool runnable() const noexcept {
			return base_t::valid() && (status() == call_status::yielded);
		}

		explicit operator bool() const noexcept {
			return runnable();
		}

		template <typename... Args>
		protected_function_result operator()(Args&&... args) {
			return call<>(std::forward<Args>(args)...);
		}

		template <typename... Ret, typename... Args>
		decltype(auto) operator()(types<Ret...>, Args&&... args) {
			return call<Ret...>(std::forward<Args>(args)...);
		}

		template <typename... Ret, typename... Args>
		decltype(auto) call(Args&&... args) {
			// some users screw up coroutine.create
			// and try to use it with sol::coroutine without ever calling the first resume in Lua
			// this makes the stack incompatible with other kinds of stacks: protect against this
			// make sure coroutines don't screw us over
			base_t::push();
			int pushcount = stack::multi_push_reference(lua_state(), std::forward<Args>(args)...);
			return invoke(types<Ret...>(), std::make_index_sequence<sizeof...(Ret)>(), pushcount);
		}

	private:
		handler_t m_error_handler;
	};
} // namespace sol

#endif // SOL_COUROUTINE_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_USERDATA_HPP
#define SOL_USERDATA_HPP

#include <sol/object_base.hpp>
#include <sol/table.hpp>

namespace sol {
	template <typename base_type>
	class basic_userdata : public basic_table<base_type> {
	private:
		using base_t = basic_table<base_type>;

	public:
		using base_t::lua_state;

		basic_userdata() noexcept = default;
		template <typename T,
		     meta::enable<meta::neg<std::is_same<meta::unqualified_t<T>, basic_userdata>>, meta::neg<std::is_same<base_t, stack_reference>>,
		          is_lua_reference<meta::unqualified_t<T>>> = meta::enabler>
		basic_userdata(T&& r) noexcept : base_t(std::forward<T>(r)) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			if (!is_userdata<meta::unqualified_t<T>>::value) {
				auto pp = stack::push_pop(*this);
				type_assert(lua_state(), -1, type::userdata);
			}
#endif // Safety
		}
		basic_userdata(const basic_userdata&) = default;
		basic_userdata(basic_userdata&&) = default;
		basic_userdata& operator=(const basic_userdata&) = default;
		basic_userdata& operator=(basic_userdata&&) = default;
		basic_userdata(const stack_reference& r) : basic_userdata(r.lua_state(), r.stack_index()) {
		}
		basic_userdata(stack_reference&& r) : basic_userdata(r.lua_state(), r.stack_index()) {
		}
		template <typename T, meta::enable<is_lua_reference<meta::unqualified_t<T>>> = meta::enabler>
		basic_userdata(lua_State* L, T&& r) : base_t(L, std::forward<T>(r)) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			auto pp = stack::push_pop(*this);
			constructor_handler handler {};
			stack::check<basic_userdata>(L, -1, handler);
#endif // Safety
		}
		basic_userdata(lua_State* L, int index = -1) : base_t(detail::no_safety, L, index) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			constructor_handler handler {};
			stack::check<basic_userdata>(L, index, handler);
#endif // Safety
		}
		basic_userdata(lua_State* L, ref_index index) : base_t(detail::no_safety, L, index) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			auto pp = stack::push_pop(*this);
			constructor_handler handler {};
			stack::check<basic_userdata>(L, -1, handler);
#endif // Safety
		}
	};

	template <typename base_type>
	class basic_lightuserdata : public basic_object_base<base_type> {
		typedef basic_object_base<base_type> base_t;

	public:
		using base_t::lua_state;

		basic_lightuserdata() noexcept = default;
		template <typename T,
		     meta::enable<meta::neg<std::is_same<meta::unqualified_t<T>, basic_lightuserdata>>, meta::neg<std::is_same<base_t, stack_reference>>,
		          is_lua_reference<meta::unqualified_t<T>>> = meta::enabler>
		basic_lightuserdata(T&& r) noexcept : base_t(std::forward<T>(r)) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			if (!is_lightuserdata<meta::unqualified_t<T>>::value) {
				auto pp = stack::push_pop(*this);
				type_assert(lua_state(), -1, type::lightuserdata);
			}
#endif // Safety
		}
		basic_lightuserdata(const basic_lightuserdata&) = default;
		basic_lightuserdata(basic_lightuserdata&&) = default;
		basic_lightuserdata& operator=(const basic_lightuserdata&) = default;
		basic_lightuserdata& operator=(basic_lightuserdata&&) = default;
		basic_lightuserdata(const stack_reference& r) : basic_lightuserdata(r.lua_state(), r.stack_index()) {
		}
		basic_lightuserdata(stack_reference&& r) : basic_lightuserdata(r.lua_state(), r.stack_index()) {
		}
		template <typename T, meta::enable<is_lua_reference<meta::unqualified_t<T>>> = meta::enabler>
		basic_lightuserdata(lua_State* L, T&& r) : basic_lightuserdata(L, std::forward<T>(r)) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			auto pp = stack::push_pop(*this);
			constructor_handler handler {};
			stack::check<basic_lightuserdata>(lua_state(), -1, handler);
#endif // Safety
		}
		basic_lightuserdata(lua_State* L, int index = -1) : base_t(L, index) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			constructor_handler handler {};
			stack::check<basic_lightuserdata>(L, index, handler);
#endif // Safety
		}
		basic_lightuserdata(lua_State* L, ref_index index) : base_t(L, index) {
#if SOL_IS_ON(SOL_SAFE_REFERENCES)
			auto pp = stack::push_pop(*this);
			constructor_handler handler {};
			stack::check<basic_lightuserdata>(lua_state(), index, handler);
#endif // Safety
		}
	};

} // namespace sol

#endif // SOL_USERDATA_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this Spermission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_AS_ARGS_HPP
#define SOL_AS_ARGS_HPP

#include <sol/stack.hpp>

namespace sol {
	template <typename T>
	struct as_args_t {
		T src;
	};

	template <typename Source>
	auto as_args(Source&& source) {
		return as_args_t<Source> { std::forward<Source>(source) };
	}

	namespace stack {
		template <typename T>
		struct unqualified_pusher<as_args_t<T>> {
			int push(lua_State* L, const as_args_t<T>& e) {
				int p = 0;
				for (const auto& i : e.src) {
					p += stack::push(L, i);
				}
				return p;
			}
		};
	} // namespace stack
} // namespace sol

#endif // SOL_AS_ARGS_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_STACK_PROXY_HPP
#define SOL_STACK_PROXY_HPP

#include <sol/stack_proxy_base.hpp>

namespace sol {
	struct stack_proxy : public stack_proxy_base {
	public:
		stack_proxy() : stack_proxy_base() {
		}
		stack_proxy(lua_State* L, int index) : stack_proxy_base(L, index) {
		}

		template <typename... Ret, typename... Args>
		decltype(auto) call(Args&&... args);

		template <typename... Args>
		decltype(auto) operator()(Args&&... args) {
			return call<>(std::forward<Args>(args)...);
		}
	};

	namespace stack {
		template <>
		struct unqualified_getter<stack_proxy> {
			static stack_proxy get(lua_State* L, int index, record& tracking) {
				tracking.use(0);
				return stack_proxy(L, index);
			}
		};

		template <>
		struct unqualified_pusher<stack_proxy> {
			static int push(lua_State*, const stack_proxy& ref) {
				return ref.push();
			}
		};
	} // namespace stack
} // namespace sol

#endif // SOL_STACK_PROXY_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_STACK_ITERATOR_HPP
#define SOL_STACK_ITERATOR_HPP

#include <sol/stack.hpp>
#include <limits>
#include <iterator>

namespace sol {
	template <typename proxy_t, bool is_const>
	struct stack_iterator {
		typedef meta::conditional_t<is_const, const proxy_t, proxy_t> reference;
		typedef meta::conditional_t<is_const, const proxy_t*, proxy_t*> pointer;
		typedef proxy_t value_type;
		typedef std::ptrdiff_t difference_type;
		typedef std::random_access_iterator_tag iterator_category;
		lua_State* L;
		int index;
		int stacktop;
		proxy_t sp;

		stack_iterator() : L(nullptr), index((std::numeric_limits<int>::max)()), stacktop((std::numeric_limits<int>::max)()), sp() {
		}
		stack_iterator(const stack_iterator<proxy_t, true>& r) : L(r.L), index(r.index), stacktop(r.stacktop), sp(r.sp) {
		}
		stack_iterator(lua_State* luastate, int idx, int topidx) : L(luastate), index(idx), stacktop(topidx), sp(luastate, idx) {
		}

		reference operator*() {
			return proxy_t(L, index);
		}

		reference operator*() const {
			return proxy_t(L, index);
		}

		pointer operator->() {
			sp = proxy_t(L, index);
			return &sp;
		}

		pointer operator->() const {
			const_cast<proxy_t&>(sp) = proxy_t(L, index);
			return &sp;
		}

		stack_iterator& operator++() {
			++index;
			return *this;
		}

		stack_iterator operator++(int) {
			auto r = *this;
			this->operator++();
			return r;
		}

		stack_iterator& operator--() {
			--index;
			return *this;
		}

		stack_iterator operator--(int) {
			auto r = *this;
			this->operator--();
			return r;
		}

		stack_iterator& operator+=(difference_type idx) {
			index += static_cast<int>(idx);
			return *this;
		}

		stack_iterator& operator-=(difference_type idx) {
			index -= static_cast<int>(idx);
			return *this;
		}

		difference_type operator-(const stack_iterator& r) const {
			return index - r.index;
		}

		stack_iterator operator+(difference_type idx) const {
			stack_iterator r = *this;
			r += idx;
			return r;
		}

		reference operator[](difference_type idx) const {
			return proxy_t(L, index + static_cast<int>(idx));
		}

		bool operator==(const stack_iterator& r) const {
			if (stacktop == (std::numeric_limits<int>::max)()) {
				return r.index == r.stacktop;
			}
			else if (r.stacktop == (std::numeric_limits<int>::max)()) {
				return index == stacktop;
			}
			return index == r.index;
		}

		bool operator!=(const stack_iterator& r) const {
			return !(this->operator==(r));
		}

		bool operator<(const stack_iterator& r) const {
			return index < r.index;
		}

		bool operator>(const stack_iterator& r) const {
			return index > r.index;
		}

		bool operator<=(const stack_iterator& r) const {
			return index <= r.index;
		}

		bool operator>=(const stack_iterator& r) const {
			return index >= r.index;
		}
	};

	template <typename proxy_t, bool is_const>
	inline stack_iterator<proxy_t, is_const> operator+(
	     typename stack_iterator<proxy_t, is_const>::difference_type n, const stack_iterator<proxy_t, is_const>& r) {
		return r + n;
	}
} // namespace sol

#endif // SOL_STACK_ITERATOR_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_VARIADIC_ARGS_HPP
#define SOL_VARIADIC_ARGS_HPP

#include <sol/stack.hpp>
#include <sol/stack_proxy.hpp>
#include <sol/stack_iterator.hpp>
#include <limits>
#include <iterator>

namespace sol {
	struct variadic_args {
	private:
		lua_State* L;
		int index;
		int stacktop;

	public:
		typedef stack_proxy reference_type;
		typedef stack_proxy value_type;
		typedef stack_proxy* pointer;
		typedef std::ptrdiff_t difference_type;
		typedef std::size_t size_type;
		typedef stack_iterator<stack_proxy, false> iterator;
		typedef stack_iterator<stack_proxy, true> const_iterator;
		typedef std::reverse_iterator<iterator> reverse_iterator;
		typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

		variadic_args() = default;
		variadic_args(lua_State* luastate, int stackindex = -1) : L(luastate), index(lua_absindex(luastate, stackindex)), stacktop(lua_gettop(luastate)) {
		}
		variadic_args(lua_State* luastate, int stackindex, int lastindex) : L(luastate), index(lua_absindex(luastate, stackindex)), stacktop(lastindex) {
		}
		variadic_args(const variadic_args&) = default;
		variadic_args& operator=(const variadic_args&) = default;
		variadic_args(variadic_args&& o) : L(o.L), index(o.index), stacktop(o.stacktop) {
			// Must be manual, otherwise destructor will screw us
			// return count being 0 is enough to keep things clean
			// but will be thorough
			o.L = nullptr;
			o.index = 0;
			o.stacktop = 0;
		}
		variadic_args& operator=(variadic_args&& o) {
			L = o.L;
			index = o.index;
			stacktop = o.stacktop;
			// Must be manual, otherwise destructor will screw us
			// return count being 0 is enough to keep things clean
			// but will be thorough
			o.L = nullptr;
			o.index = 0;
			o.stacktop = 0;
			return *this;
		}

		iterator begin() {
			return iterator(L, index, stacktop + 1);
		}
		iterator end() {
			return iterator(L, stacktop + 1, stacktop + 1);
		}
		const_iterator begin() const {
			return const_iterator(L, index, stacktop + 1);
		}
		const_iterator end() const {
			return const_iterator(L, stacktop + 1, stacktop + 1);
		}
		const_iterator cbegin() const {
			return begin();
		}
		const_iterator cend() const {
			return end();
		}

		reverse_iterator rbegin() {
			return std::reverse_iterator<iterator>(begin());
		}
		reverse_iterator rend() {
			return std::reverse_iterator<iterator>(end());
		}
		const_reverse_iterator rbegin() const {
			return std::reverse_iterator<const_iterator>(begin());
		}
		const_reverse_iterator rend() const {
			return std::reverse_iterator<const_iterator>(end());
		}
		const_reverse_iterator crbegin() const {
			return std::reverse_iterator<const_iterator>(cbegin());
		}
		const_reverse_iterator crend() const {
			return std::reverse_iterator<const_iterator>(cend());
		}

		int push() const {
			return push(L);
		}

		int push(lua_State* target) const {
			int pushcount = 0;
			for (int i = index; i <= stacktop; ++i) {
				lua_pushvalue(L, i);
				pushcount += 1;
			}
			if (target != L) {
				lua_xmove(L, target, pushcount);
			}
			return pushcount;
		}

		template <typename T>
		decltype(auto) get(difference_type index_offset = 0) const {
			return stack::get<T>(L, index + static_cast<int>(index_offset));
		}

		type get_type(difference_type index_offset = 0) const noexcept {
			return type_of(L, index + static_cast<int>(index_offset));
		}

		stack_proxy operator[](difference_type index_offset) const {
			return stack_proxy(L, index + static_cast<int>(index_offset));
		}

		lua_State* lua_state() const {
			return L;
		};
		int stack_index() const {
			return index;
		};
		int leftover_count() const {
			return stacktop - (index - 1);
		}
		std::size_t size() const {
			return static_cast<std::size_t>(leftover_count());
		}
		int top() const {
			return stacktop;
		}
	};

	namespace stack {
		template <>
		struct unqualified_getter<variadic_args> {
			static variadic_args get(lua_State* L, int index, record& tracking) {
				tracking.last = 0;
				return variadic_args(L, index);
			}
		};

		template <>
		struct unqualified_pusher<variadic_args> {
			static int push(lua_State* L, const variadic_args& ref) {
				return ref.push(L);
			}
		};
	} // namespace stack
} // namespace sol

#endif // SOL_VARIADIC_ARGS_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_AS_RETURNS_HPP
#define SOL_AS_RETURNS_HPP

#include <sol/traits.hpp>
#include <sol/stack.hpp>
#include <sol/ebco.hpp>

namespace sol {
	template <typename T>
	struct as_returns_t : private detail::ebco<T> {
	private:
		using base_t = detail::ebco<T>;

	public:
		using base_t::base_t;
		using base_t::value;
	};

	template <typename Source>
	auto as_returns(Source&& source) {
		return as_returns_t<std::decay_t<Source>> { std::forward<Source>(source) };
	}

	namespace stack {
		template <typename T>
		struct unqualified_pusher<as_returns_t<T>> {
			int push(lua_State* L, const as_returns_t<T>& e) {
				auto& src = detail::unwrap(e.value());
				int p = 0;
				for (const auto& i : src) {
					p += stack::push(L, i);
				}
				return p;
			}
		};
	} // namespace stack
} // namespace sol

#endif // SOL_AS_RETURNS_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_VARIADIC_RESULTS_HPP
#define SOL_VARIADIC_RESULTS_HPP

#include <sol/stack.hpp>
#include <sol/object.hpp>
#include <sol/as_returns.hpp>
#include <sol/function_result.hpp>
#include <sol/protected_function_result.hpp>

#include <vector>

namespace sol {

	template <typename Al = typename std::allocator<object>>
	struct basic_variadic_results : public std::vector<object, Al> {
	private:
		using base_t = std::vector<object, Al>;

	public:
		basic_variadic_results() : base_t() {
		}

		basic_variadic_results(unsafe_function_result fr) : base_t() {
			this->reserve(fr.return_count());
			this->insert(this->cend(), fr.begin(), fr.end());
		}

		basic_variadic_results(protected_function_result fr) : base_t() {
			this->reserve(fr.return_count());
			this->insert(this->cend(), fr.begin(), fr.end());
		}

		template <typename Arg0, typename... Args,
		     meta::disable_any<std::is_same<meta::unqualified_t<Arg0>, basic_variadic_results>, std::is_same<meta::unqualified_t<Arg0>, function_result>,
		          std::is_same<meta::unqualified_t<Arg0>, protected_function_result>> = meta::enabler>
		basic_variadic_results(Arg0&& arg0, Args&&... args) : base_t(std::forward<Arg0>(arg0), std::forward<Args>(args)...) {
		}

		basic_variadic_results(const basic_variadic_results&) = default;
		basic_variadic_results(basic_variadic_results&&) = default;
		basic_variadic_results& operator=(const basic_variadic_results&) = default;
		basic_variadic_results& operator=(basic_variadic_results&&) = default;
	};

	struct variadic_results : public basic_variadic_results<> {
	private:
		using base_t = basic_variadic_results<>;

	public:
		using base_t::base_t;
	};

	template <typename Al>
	struct is_container<basic_variadic_results<Al>> : std::false_type { };

	template <>
	struct is_container<variadic_results> : std::false_type { };

	namespace stack {
		template <typename Al>
		struct unqualified_pusher<basic_variadic_results<Al>> {
			int push(lua_State* L, const basic_variadic_results<Al>& e) {
				int p = 0;
				for (const auto& i : e) {
					p += stack::push(L, i);
				}
				return p;
			}
		};

		template <>
		struct unqualified_pusher<variadic_results> {
			int push(lua_State* L, const variadic_results& r) {
				using base_t = basic_variadic_results<>;
				return stack::push(L, static_cast<const base_t&>(r));
			}
		};
	} // namespace stack

} // namespace sol

#endif // SOL_VARIADIC_RESULTS_HPP
// sol2

// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_LUA_VALUE_HPP
#define SOL_LUA_VALUE_HPP

#include <sol/stack.hpp>
#include <sol/reference.hpp>
#include <sol/make_reference.hpp>

namespace sol {
	struct lua_value {
	public:
		struct arr : detail::ebco<std::initializer_list<lua_value>> {
		private:
			using base_t = detail::ebco<std::initializer_list<lua_value>>;

		public:
			using base_t::base_t;
		};

	private:
		template <typename T>
		using is_reference_or_lua_value_init_list
		     = meta::any<meta::is_specialization_of<T, std::initializer_list>, std::is_same<T, reference>, std::is_same<T, arr>>;

		template <typename T>
		using is_lua_value_single_constructible = meta::any<std::is_same<T, lua_value>, is_reference_or_lua_value_init_list<T>>;

		static lua_State*& thread_local_lua_state() {
#if SOL_IS_ON(SOL_USE_THREAD_LOCAL)
			static thread_local lua_State* L = nullptr;
#else
			static lua_State* L = nullptr;
#endif
			return L;
		}

		reference ref_value;

	public:
		static void set_lua_state(lua_State* L) {
			thread_local_lua_state() = L;
		}

		template <typename T, meta::disable<is_reference_or_lua_value_init_list<meta::unqualified_t<T>>> = meta::enabler>
		lua_value(lua_State* L_, T&& value) : lua_value(((set_lua_state(L_)), std::forward<T>(value))) {
		}

		template <typename T, meta::disable<is_lua_value_single_constructible<meta::unqualified_t<T>>> = meta::enabler>
		lua_value(T&& value) : ref_value(make_reference(thread_local_lua_state(), std::forward<T>(value))) {
		}

		lua_value(lua_State* L_, std::initializer_list<std::pair<lua_value, lua_value>> il)
		: lua_value([&L_, &il]() {
			set_lua_state(L_);
			return std::move(il);
		}()) {
		}

		lua_value(std::initializer_list<std::pair<lua_value, lua_value>> il) : ref_value(make_reference(thread_local_lua_state(), std::move(il))) {
		}

		lua_value(lua_State* L_, arr il)
		: lua_value([&L_, &il]() {
			set_lua_state(L_);
			return std::move(il);
		}()) {
		}

		lua_value(arr il) : ref_value(make_reference(thread_local_lua_state(), std::move(il.value()))) {
		}

		lua_value(lua_State* L_, reference r)
		: lua_value([&L_, &r]() {
			set_lua_state(L_);
			return std::move(r);
		}()) {
		}

		lua_value(reference r) : ref_value(std::move(r)) {
		}

		lua_value(const lua_value&) noexcept = default;
		lua_value(lua_value&&) = default;
		lua_value& operator=(const lua_value&) = default;
		lua_value& operator=(lua_value&&) = default;

		const reference& value() const& {
			return ref_value;
		}

		reference& value() & {
			return ref_value;
		}

		reference&& value() && {
			return std::move(ref_value);
		}

		template <typename T>
		decltype(auto) as() const {
			ref_value.push();
			return stack::pop<T>(ref_value.lua_state());
		}

		template <typename T>
		bool is() const {
			int r = ref_value.registry_index();
			if (r == LUA_REFNIL)
				return meta::any_same<meta::unqualified_t<T>, lua_nil_t, nullopt_t, std::nullptr_t>::value ? true : false;
			if (r == LUA_NOREF)
				return false;
			auto pp = stack::push_pop(ref_value);
			return stack::check<T>(ref_value.lua_state(), -1, &no_panic);
		}
	};

	using array_value = typename lua_value::arr;

	namespace stack {
		template <>
		struct unqualified_pusher<lua_value> {
			static int push(lua_State* L, const lua_value& lv) {
				return stack::push(L, lv.value());
			}

			static int push(lua_State* L, lua_value&& lv) {
				return stack::push(L, std::move(lv).value());
			}
		};

		template <>
		struct unqualified_getter<lua_value> {
			static lua_value get(lua_State* L, int index, record& tracking) {
				return lua_value(L, stack::get<reference>(L, index, tracking));
			}
		};
	} // namespace stack
} // namespace sol

#endif // SOL_LUA_VALUE_HPP
// The MIT License (MIT)

// Copyright (c) 2013-2022 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_HPP
#define SOL_HPP

#include <sol/version.hpp>

#if SOL_IS_ON(SOL_INSIDE_UNREAL_ENGINE)
#ifdef check
#pragma push_macro("check")
#undef check
#endif
#endif // Unreal Engine 4 Bullshit

#if SOL_IS_ON(SOL_COMPILER_GCC)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#pragma GCC diagnostic ignored "-Wconversion"
#if __GNUC__ > 6
#pragma GCC diagnostic ignored "-Wnoexcept-type"
#endif
#elif SOL_IS_ON(SOL_COMPILER_CLANG)
// we'll just let this alone for now
#elif SOL_IS_ON(SOL_COMPILER_VCXX)
#pragma warning(push)
#pragma warning(disable : 4505) // unreferenced local function has been removed GEE THANKS
#endif                          // clang++ vs. g++ vs. VC++

#include <sol/forward.hpp>
#include <sol/forward_detail.hpp>
#include <sol/assert.hpp>
#include <sol/bytecode.hpp>
#include <sol/stack.hpp>
#include <sol/object.hpp>
#include <sol/function.hpp>
#include <sol/protected_function.hpp>
#include <sol/usertype.hpp>
#include <sol/table.hpp>
#include <sol/state.hpp>
#include <sol/coroutine.hpp>
#include <sol/thread.hpp>
#include <sol/userdata.hpp>
#include <sol/metatable.hpp>
#include <sol/as_args.hpp>
#include <sol/variadic_args.hpp>
#include <sol/variadic_results.hpp>
#include <sol/lua_value.hpp>

#if SOL_IS_ON(SOL_COMPILER_GCC)
#pragma GCC diagnostic pop
#elif SOL_IS_ON(SOL_COMPILER_CLANG)
// we'll just let this alone for now
#elif SOL_IS_ON(SOL_COMPILER_VCXX)
#pragma warning(pop)
#endif // g++

#if SOL_IS_ON(SOL_INSIDE_UNREAL_ENGINE)
#undef check
#pragma pop_macro("check")
#endif // Unreal Engine 4 Bullshit

#endif // SOL_HPP
#endif // SOL_SINGLE_INCLUDE_HPP
