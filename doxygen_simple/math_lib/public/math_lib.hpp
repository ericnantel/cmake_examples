
#ifndef MATH_LIB_HPP
#define MATH_LIB_HPP

/**
 * @file math_lib.hpp
 * @brief Library Header File
 * @author Eric Nantel
 * @version 1.0
 * @date 2025-11-01
 * @copyright (c) 2025 Eric Nantel. All Rights Reserved.
 * This project is released under the BSD 3-Clause License.
 * Source code is available on GitHub website.
 * @link https://github.com/ericnantel/cmake_examples @endlink
 */

#ifdef MATH_DLL_EXPORTS

#ifdef _WIN32
#define MATH_API __decltype(dllexport)
#else
#define MATH_API __attribute__((visibility("default")))
#endif

#else

#ifdef _WIN32
#define MATH_API __decltype(dllimport)
#else
#define MATH_API
#endif

#endif

extern "C"
{
	/**
	 * @struct vec3
	 * @brief 3-D Vector structure for algebra
	 */
	struct MATH_API vec3
	{
		float x; /**< (field) x */
		float y; /**< (field) y */
		float z; /**< (field) z */
	};

	/**
	 * @struct ray3
	 * @brief 3-D Ray structure for algebra
	 */
	struct MATH_API ray3
	{
		vec3 origin; /**< (field) origin */
		vec3 direction; /**< (field) direction */
	};

	/**
	 * @fn void vec3_length(const vec3& v, float& l)
	 * @brief Calculates length l of a vector v
	 * @note Expects a non-null vector v
	 * @param v vector
	 * @param t float (ref)
	 * @return void
	 */
	void vec3_length(const vec3& v, float& l);

	/**
	 * @fn void vec3_normalize(vec3& v)
	 * @brief Normalizes a vector v
	 * @note Expects a non-null vector v
	 * @param v vector (ref)
	 * @return void
	 */
	void vec3_normalize(vec3& v);

	/**
	 * @fn void ray3_get_point(const ray3& r, const float t, vec3& v)
	 * @brief Sets vector v with point at distance t from the ray r
	 * @note Expects ray r to have a normalized direction
	 * @param r ray
	 * @param t distance
	 * @param v vector (ref)
	 * @return void
	 */
	void ray3_get_point(const ray3& r, const float t, vec3& v);
}

#endif
