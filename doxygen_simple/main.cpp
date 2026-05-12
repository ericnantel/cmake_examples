/**
 * @file main.cpp
 * @brief Application Main Source File
 * @author Eric Nantel
 * @version 1.0
 * @date 2025-11-01
 * @copyright (c) 2025 Eric Nantel. All Rights Reserved.
 * This project is released under the BSD 3-Clause License.
 * Source code is available on GitHub website.
 * @link https://github.com/ericnantel/cmake_examples @endlink
 */

#include "app.hpp"
#include <cstdlib>

int main(int argc, char* argv[])
{
	const vec3 origin = {0.0f, 0.0f, 0.0f};
	const vec3 direction = {1.0f, 0.0f, 0.0f};
	ray3 ray = {
		.origin = origin,
		.direction = direction
	};
	vec3_normalize(ray.direction);
	const float distance = 250.0f;

	app_print_ray_point(ray, distance);

    return EXIT_SUCCESS;
}
