
cmake_minimum_required(VERSION 3.25)

project(toml_parser)

add_subdirectory(tomlplusplus)

set(ENTRY_POINT
	main.cpp)

set(SOURCE_FILES
	private/app.cpp)

add_executable(${PROJECT_NAME})

target_precompile_headers(${PROJECT_NAME}
	PRIVATE private/pch.hpp)

target_include_directories(${PROJECT_NAME}
	PRIVATE public private
	PRIVATE tomlplusplus/include)

target_sources(${PROJECT_NAME}
	PRIVATE ${ENTRY_POINT} ${SOURCE_FILES})
