
cmake_minimum_required(VERSION 3.25)

project(doxygen_simple)

set(TARGET
	${PROJECT_NAME})

add_subdirectory(math_lib)

add_executable(${TARGET})

set(ENTRY_POINT
	main.cpp)

set(PRIVATE_PCH_FILES
	private/pch.hpp)

set(PUBLIC_HEADER_FILES
	public/app.hpp)

set(PRIVATE_SOURCE_FILES
	private/app.cpp)

target_precompile_headers(${TARGET}
	PRIVATE ${PRIVATE_PCH_FILES})

target_include_directories(${TARGET}
	PRIVATE public private
	PRIVATE math_lib/public)

target_sources(${TARGET}
	PRIVATE ${ENTRY_POINT} ${PRIVATE_SOURCE_FILES})

target_link_libraries(${TARGET}
	PRIVATE math_lib)

find_package(Doxygen OPTIONAL_COMPONENTS dot)
if (DOXYGEN_FOUND)
	set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/doxygen)
	set(DOXYGEN_FILE_PATTERNS *.c *.cxx *.cpp *.h *.hxx *.hpp)
	set(DOXYGEN_GENERATE_HTML YES)
	set(DOXYGEN_GENERATE_MAN NO)
	# set(DOXYGEN_HAVE_DOT YES)
	doxygen_add_docs(doxygen_target ${PROJECT_SOURCE_DIR} ALL
		COMMENT "Generating API Documentation with Doxygen.")
else()
	message("Doxygen is not found. Cannot generate docs")
endif()
