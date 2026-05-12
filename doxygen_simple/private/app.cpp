/**
 * @file app.cpp
 * @brief Application Source File
 * @author Eric Nantel
 * @version 1.0
 * @date 2025-11-01
 * @copyright (c) 2025 Eric Nantel. All Rights Reserved.
 * This project is released under the BSD 3-Clause License.
 * Source code is available on GitHub website.
 * @link https://github.com/ericnantel/cmake_examples @endlink
 */


#include "app.hpp"
#include "pch.hpp"

void app_print_ray_point(const ray3& r, const float t)
{
	vec3 v = { 0.0f, 0.0f, 0.0f };
	ray3_get_point(r, t, v);

	std::cout << "point is (" << v.x << "," << v.y << "," << v.z << ")" << std::endl;
}

