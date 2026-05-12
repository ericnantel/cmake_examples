
# cmake_minimum_required(VERSION 3.25)
cmake_minimum_required(VERSION 3.9)

project(test_simple)

set(TARGET
	${PROJECT_NAME})

add_subdirectory(math_lib)

add_executable(${TARGET})

set(TARGET_PRECOMPILE_HEADERS
	private/pch.hpp)

set(TARGET_INCLUDE_DIRECTORIES
	public
	private
	math_lib/public)

set(TARGET_SOURCES
	main.cpp
	private/app.cpp)

set(TARGET_LINK_LIBRARIES
	math_lib)

target_precompile_headers(${TARGET}
	PRIVATE ${TARGET_PRECOMPILE_HEADERS})

target_include_directories(${TARGET}
	PRIVATE ${TARGET_INCLUDE_DIRECTORIES})

target_sources(${TARGET}
	PRIVATE ${TARGET_SOURCES})

target_link_libraries(${TARGET}
	PRIVATE ${TARGET_LINK_LIBRARIES})

enable_testing()

add_test(NAME NormalTest COMMAND ${TARGET})
add_test(NAME TimeoutTest COMMAND ${TARGET})
set_tests_properties(TimeoutTest PROPERTIES
	TIMEOUT 1)

if (WIN32)
	set(GTEST_ROOT
		~/scoop/apps/googletest/current
		CACHE PATH "Scoop (Windows) path to googletest")
elseif(APPLE)
	set(GTEST_ROOT
		/opt/homebrew/opt/googletest
		CACHE PATH "Homebrew (MacOS) path to googletest")
elseif(UNIX)
	# NOTE: Tested with Ubuntu using Apt
	if (EXISTS /usr/src/googletest)
		if (NOT EXISTS ${GTEST_ROOT})
			message("\
			****NOTE from author Eric Nantel****
			Found GoogleTest Package Installed..
			You may need to build its CMake project..
			Do the following commands in the Terminal:
			    cd /usr/src/googletest
				sudo rm -rf build
				sudo mkdir build
				cd build
				sudo cmake ..
				sudo make
			Then you can come back to your CMake project..
			Then do the following commands in the Terminal:
			    rm -rf build
				cmake --preset default
				cmake --build --preset default
				ctest --preset default
			You can also run ./build/GoogleTests for better logs.
			****----------------------------****
			")
			set(GTEST_ROOT
				/usr/src/googletest
				CACHE PATH "Unix (Ubuntu) path to googletest")
			set(GTEST_INCLUDE_DIR
				${GTEST_ROOT}/googletest/include
				CACHE PATH "Unix (Ubuntu) path to googletest includes")
			set(GTEST_LIBRARY
				${GTEST_ROOT}/build/lib/libgtest.a
				CACHE PATH "Unix (Ubuntu) path to gtest static library")
			set(GTEST_MAIN_LIBRARY
				${GTEST_ROOT}/build/lib/libgtest_main.a
				CACHE PATH "Unix (Ubuntu) path to gtest_main static library")
		endif()
	else()
		message("\
		****NOTE from author Eric Nantel****
		GoogleTest Package Not Installed..
		This is an optional package..
		Do the following commands in the Terminal:
		    sudo apt install googletest
		    whereis googletest
		****----------------------------****
		")
	endif()
endif()
find_package(GTest REQUIRED)
if (GTest_FOUND)
	set(GTEST_TARGET
		GoogleTests)
	set(GTEST_TARGET_PRECOMPILE_HEADERS
		${TARGET_PRECOMPILE_HEADERS})
	set(GTEST_TARGET_INCLUDE_DIRECTORIES
		${GTEST_INCLUDE_DIR}
		${TARGET_INCLUDE_DIRECTORIES})
	set(GTEST_TARGET_SOURCES
		test.cpp
		private/app.cpp)
	set(GTEST_TARGET_LINK_LIBRARIES
		GTest::gtest_main
		${TARGET_LINK_LIBRARIES})

	add_executable(${GTEST_TARGET})

	target_precompile_headers(${GTEST_TARGET}
		PRIVATE ${GTEST_TARGET_PRECOMPILE_HEADERS})

	target_include_directories(${GTEST_TARGET}
		PRIVATE ${GTEST_TARGET_INCLUDE_DIRECTORIES})

	target_sources(${GTEST_TARGET}
		PRIVATE ${GTEST_TARGET_SOURCES})

	target_link_libraries(${GTEST_TARGET}
		PRIVATE ${GTEST_TARGET_LINK_LIBRARIES})
	
	add_test(NAME AllGoogleTests COMMAND ${GTEST_TARGET})

	# include(GoogleTest)
	# gtest_add_tests(${GTEST_TARGET} "" AUTO)

	# include(GoogleTest)
	# gtest_discover_tests(${GTEST_TARGET} "" AUTO)
else()
	message("GTest is not found. Cannot generate GoogleTest tests")
endif()
