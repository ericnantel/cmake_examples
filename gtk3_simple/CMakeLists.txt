
cmake_minimum_required(VERSION 3.25)

project(gtk3_simple)

find_package(gtk REQUIRED)

set(TARGET
	${PROJECT_NAME})

add_executable(${TARGET})

# target_precompile_headers(${TARGET}
# 	PRIVATE private/pch.hpp)

target_include_directories(${TARGET}
	PRIVATE public private)
	# PRIVATE ${gtk_INCLUDE_DIR})

target_sources(${TARGET}
	PRIVATE main.cpp)

target_link_libraries(${TARGET}
	PRIVATE gtk::gtk)

