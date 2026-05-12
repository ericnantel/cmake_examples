
cmake_minimum_required(VERSION 3.25)

project(unity_native_plugin)

set(SOURCE_FILES
	private/math_utils.cpp)

add_library(${PROJECT_NAME} SHARED)

target_include_directories(${PROJECT_NAME}
	PRIVATE public private)

target_sources(${PROJECT_NAME}
	PRIVATE ${SOURCE_FILES})
