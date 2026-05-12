
cmake_minimum_required(VERSION 3.25)

project(math_lib)

set(TARGET
	${PROJECT_NAME})

add_library(${TARGET} STATIC)

set(PRIVATE_PCH_FILES
	private/pch.hpp)

set(PUBLIC_HEADER_FILES
	public/math_lib.hpp)

set(PRIVATE_SOURCE_FILES
	private/math_lib.cpp)

target_precompile_headers(${TARGET}
	PRIVATE ${PRIVATE_PCH_FILES})

target_include_directories(${TARGET}
	PUBLIC public
	PRIVATE private)

target_sources(${TARGET}
	PRIVATE ${PRIVATE_SOURCE_FILES})
