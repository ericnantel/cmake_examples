
cmake_minimum_required(VERSION 3.25)

project(mailman)

# add_subdirectory(tomlplusplus)
find_package(tomlplusplus REQUIRED)

find_package(OpenGL REQUIRED)

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "GLFW lib only")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "GLFW lib only")
set(GLFW_INSTALL OFF CACHE BOOL "GLFW lib only")
# add_subdirectory(glfw)
find_package(glfw3 REQUIRED)

set(TARGET
	${PROJECT_NAME})

add_executable(${TARGET})

target_precompile_headers(${TARGET}
	PRIVATE private/pch.hpp)

target_include_directories(${TARGET}
	PRIVATE public private
	# PRIVATE tomlplusplus/include
	PRIVATE ${tomlplusplus_INCLUDE_DIR}
	PRIVATE ${OPENGL_INCLUDE_DIRS}
	# PRIVATE ${GLFW_SOURCE_DIR}/deps
	# PRIVATE ${GLFW_SOURCE_DIR}/deps/glad/gl.h
	# PRIVATE ${GLFW_SOURCE_DIR}/deps/glad/vulkan.h)
	PRIVATE ${glfw3_INCLUDE_DIR}/../../b/src/deps
	PRIVATE ${glfw3_INCLUDE_DIR}/../../b/src/deps/glad/gl.h
	PRIVATE ${glfw3_INCLUDE_DIR}/../../b/src/deps/glad/vulkan.h)
	# PRIVATE ${glfw3_INCLUDE_DIR})

target_sources(${TARGET}
	PRIVATE main.cpp private/app.cpp)

target_link_libraries(${TARGET}
	PRIVATE ${OPENGL_LIBRARIES}
	PRIVATE glfw)

find_package(Doxygen OPTIONAL_COMPONENTS dot)
if (DOXYGEN_FOUND)
	# set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doxygen)
	# set(DOXYGEN_FILE_PATTERNS *.c *.cxx *.cpp *.h *.hxx *.hpp)
	# set(DOXYGEN_GENERATE_HTML YES)
	# set(DOXYGEN_GENERATE_MAN NO)
	# # set(DOXYGEN_HAVE_DOT YES)
	# doxygen_add_docs(doxygen_target ${PROJECT_SOURCE_DIR} ALL
	# 	COMMENT "Generating API Documentation with Doxygen.")
else()
	message("Doxygen is not found. Cannot generate docs")
endif()

enable_testing()

# TODO: Add CTests here

find_package(GTest REQUIRED)
if (GTest_FOUND)
	# TODO: Add GoogleTests
	# set(GTEST_TARGET
	# 	GoogleTests)
	# set(GTEST_TARGET_PRECOMPILE_HEADERS
	# 	${TARGET_PRECOMPILE_HEADERS})
	# set(GTEST_TARGET_INCLUDE_DIRECTORIES
	# 	${GTEST_INCLUDE_DIR}
	# 	${TARGET_INCLUDE_DIRECTORIES})
	# set(GTEST_TARGET_SOURCES
	# 	test.cpp
	# 	private/app.cpp)
	# set(GTEST_TARGET_LINK_LIBRARIES
	# 	GTest::gtest_main
	# 	${TARGET_LINK_LIBRARIES})

	# add_executable(${GTEST_TARGET})

	# target_precompile_headers(${GTEST_TARGET}
	# 	PRIVATE ${GTEST_TARGET_PRECOMPILE_HEADERS})

	# target_include_directories(${GTEST_TARGET}
	# 	PRIVATE ${GTEST_TARGET_INCLUDE_DIRECTORIES})

	# target_sources(${GTEST_TARGET}
	# 	PRIVATE ${GTEST_TARGET_SOURCES})

	# target_link_libraries(${GTEST_TARGET}
	# 	PRIVATE ${GTEST_TARGET_LINK_LIBRARIES})
	
	# add_test(NAME AllGoogleTests COMMAND ${GTEST_TARGET})



	# include(GoogleTest)
	# gtest_add_tests(${GTEST_TARGET} "" AUTO)

	# include(GoogleTest)
	# gtest_discover_tests(${GTEST_TARGET} "" AUTO)
else()
	message("GTest is not found. Cannot generate GoogleTest tests")
endif()
