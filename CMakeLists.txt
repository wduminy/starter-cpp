cmake_minimum_required(VERSION 3.15.0)

# General
project(MyProject VERSION 1.0.0)
set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20 -Wall")
set (CMAKE_CXX_FLAGS_RELEASE "-Ofast")

# Console app
add_executable(console_app)
set (SOURCE_DIRS "domain" "console")
foreach(DIR in ${SOURCE_DIRS})
	file(GLOB SOURCES "src/${DIR}/*.cpp")
	target_sources(console_app PUBLIC ${SOURCES})
endforeach()
target_include_directories(console_app PRIVATE "src")
target_compile_definitions(console_app PUBLIC NO_TESTING) # exclude the testing code

# Testing
if (EXISTS "${CMAKE_SOURCE_DIR}/src/gtest/src/gtest-all.cc")
else()
	message("Trying to install google test")
	execute_process(COMMAND "./get-gtest.sh" "1.8.1" WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
endif()

if (EXISTS "${CMAKE_SOURCE_DIR}/src/gtest/src/gtest-all.cc")
	# Test app
	add_executable(test_app "src/gtest/src/gtest-all.cc" "src/gtest/src/gtest_main.cc")
	set (SOURCE_DIRS "domain" "test")
	foreach(DIR in ${SOURCE_DIRS})
		file(GLOB SOURCES "src/${DIR}/*.cpp")
		target_sources(test_app PUBLIC ${SOURCES})
	endforeach()
	target_include_directories(test_app PRIVATE "src" "src/gtest")
else()
	message("Gtest could not be found.  Testing is disabled")
endif()