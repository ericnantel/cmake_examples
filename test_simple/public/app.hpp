
#ifndef APP_HPP
#define APP_HPP

/**
 * @file app.hpp
 * @brief Application Header
 * @author Eric Nantel
 * @version 1.0
 * @date 2025-11-01
 * @copyright (c) 2025 Eric Nantel. All Rights Reserved.
 * This project is released under the BSD 3-Clause License.
 * Source code is available on GitHub website.
 * @link https://github.com/ericnantel/cmake_examples @endlink
 */

#include "math_lib.hpp"

/**
 * @fn void app_print_ray_point(const ray3& r, const float t)
 * @brief Prints point at distance t from the ray r
 * @param r ray
 * @param t distance
 * @return void
 */
void app_print_ray_point(const ray3& r, const float t);

#endif
