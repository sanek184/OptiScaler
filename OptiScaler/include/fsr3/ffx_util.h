// This file is part of the FidelityFX SDK.
//
// Copyright (c) 2023 Advanced Micro Devices, Inc. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#pragma once

#include "ffx_types.h"

namespace Fsr3
{
/// @defgroup Utils Utilities
/// Utility Macros used by the FidelityFX SDK
///
/// @ingroup ffxHost

/// The value of Pi.
///
/// @ingroup Utils
const float FFX_PI = 3.141592653589793f;

/// An epsilon value for floating point numbers.
///
/// @ingroup Utils
const float FFX_EPSILON = 1e-06f;

/// Helper macro to create the version number.
///
/// @ingroup Utils
#define FFX_MAKE_VERSION(major, minor, patch) ((major << 22) | (minor << 12) | patch)

///< Use this to specify no version.
///
/// @ingroup Utils
#define FFX_UNSPECIFIED_VERSION 0xFFFFAD00

/// Helper macro to avoid warnings about unused variables.
///
/// @ingroup Utils
#define FFX_UNUSED(x) ((void) (x))

/// Helper macro to align an integer to the specified power of 2 boundary
///
/// @ingroup Utils
#define FFX_ALIGN_UP(x, y) (((x) + ((y) - 1)) & ~((y) - 1))

/// Helper macro to check if a value is aligned.
///
/// @ingroup Utils
#define FFX_IS_ALIGNED(x) (((x) != 0) && ((x) & ((x) - 1)))

/// Helper macro to compute the rounded-up integer division of two unsigned integers
///
/// @ingroup Utils
#define FFX_DIVIDE_ROUNDING_UP(x, y) ((x + y - 1) / y)

/// Helper macro to stringify a value.
///
/// @ingroup Utils
#define FFX_STR(s) FFX_XSTR(s)
#define FFX_XSTR(s) #s

/// Helper macro to forward declare a structure.
///
/// @ingroup Utils
#define FFX_FORWARD_DECLARE(x) typedef struct x x

/// Helper macro to return the maximum of two values.
///
/// @ingroup Utils
#define FFX_MAXIMUM(x, y) (((x) > (y)) ? (x) : (y))

/// Helper macro to return the minimum of two values.
///
/// @ingroup Utils
#define FFX_MINIMUM(x, y) (((x) < (y)) ? (x) : (y))

/// Helper macro to do safe free on a pointer.
///
/// @ingroup Utils
#define FFX_SAFE_FREE(x)                                                                                               \
    if (x)                                                                                                             \
    free(x)

/// Helper macro to return the abs of an integer value.
///
/// @ingroup Utils
#define FFX_ABSOLUTE(x) (((x) < 0) ? (-(x)) : (x))

/// Helper macro to return sign of a value.
///
/// @ingroup Utils
#define FFX_SIGN(x) (((x) < 0) ? -1 : 1)

/// Helper macro to work out the number of elements in an array.
///
/// @ingroup Utils
#define FFX_ARRAY_ELEMENTS(x) (int32_t) ((sizeof(x) / sizeof(0 [x])) / ((size_t) (!(sizeof(x) % sizeof(0 [x])))))

/// The maximum length of a path that can be specified to the FidelityFX API.
///
/// @ingroup Utils
#define FFX_MAXIMUM_PATH (260)

/// Helper macro to check if the specified key is set in a bitfield.
///
/// @ingroup Utils
#define FFX_CONTAINS_FLAG(options, key) ((options & key) == key)
} // namespace Fsr3