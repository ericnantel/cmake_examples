/**
 * @file math_lib.cpp
 * @brief Library Source File
 * @author Eric Nantel
 * @version 1.0
 * @date 2025-11-01
 * @copyright (c) 2025 Eric Nantel. All Rights Reserved.
 * This project is released under the BSD 3-Clause License.
 * Source code is available on GitHub website.
 * @link https://github.com/ericnantel/cmake_examples @endlink
 */


#include "pch.hpp"
#include "math_lib.hpp"

extern "C"
{
	void vec3_length(const vec3& v, float& t)
	{
		const float sqr_magnitude = (v.x * v.x + v.y * v.y + v.z * v.z);
		t = sqrtf(sqr_magnitude);
	}

	void vec3_normalize(vec3& v)
	{
		const float sqr_magnitude = (v.x * v.x + v.y * v.y + v.z * v.z);
		if (sqr_magnitude != 0.0f)
		{
			const float inv_magnitude = (1.0f / sqrtf(sqr_magnitude));
			v.x *= inv_magnitude;
			v.y *= inv_magnitude;
			v.z *= inv_magnitude;
		}
	}

	void ray3_get_point(const ray3& r, const float t, vec3& v)
	{
		v.x = r.origin.x + r.direction.x * t;
		v.y = r.origin.y + r.direction.y * t;
		v.z = r.origin.z + r.direction.z * t;
	}
}
