
#include "app.hpp"
#include <cstdlib>

#include <gtest/gtest.h>

TEST(MathAPIVec3, MathAPIVec3Length)
{
	vec3 v = {
		.x = 3.0f,
		.y = 4.0f,
		.z = 0.0f
	};
	float length;
	vec3_length(v, length);
	EXPECT_EQ(length, 5.0f);
}

TEST(MathAPIVec3, MathAPIVec3Normalize)
{
	vec3 v = {
		.x = 5.0f,
		.y = 0.0f,
		.z = 0.0f
	};
	vec3_normalize(v);
	float length;
	vec3_length(v, length);
	EXPECT_EQ(length, 1.0f);
}

TEST(MathAPIRay3, MathAPIRay3GetPoint)
{
	vec3 origin = {
		.x = 0.0f,
		.y = 0.0f,
		.z = 0.0f
	};
	vec3 direction = {
		.x = 1.0f,
		.y = 0.0f,
		.z = 0.0f
	};
	vec3_normalize(direction);
	ray3 ray = {
		.origin = origin,
		.direction = direction
	};
	float distance = 300.0f;
	vec3 point;
	ray3_get_point(ray, distance, point);
	EXPECT_EQ(point.x, 300.0f);
	EXPECT_EQ(point.y, 0.0f);
	EXPECT_EQ(point.z, 0.0f);
}

int main(int argc, char* argv[])
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
