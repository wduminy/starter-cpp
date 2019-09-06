cmake_minimum_required(VERSION 3.15.0)

# General
project(MyProject VERSION 1.0.0)
set (CMAKE_CXX_STANDARD 17) 
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")
set (CMAKE_CXX_FLAGS_RELEASE "-Ofast")
file(GLOB CONSOLE_SOURCES "src/console/*.cpp")

# Console
add_executable(console_app ${CONSOLE_SOURCES})

add_custom_target(run-console
	COMMAND console_app
)

# Google test
if (EXISTS "${CMAKE_SOURCE_DIR}/src/gtest/src/gtest-all.cc") 
else()
	message("Trying to install google test")
	execute_process(COMMAND "./get-gtest.sh" "1.8.1" WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
endif()

if (EXISTS "${CMAKE_SOURCE_DIR}/src/gtest/src/gtest-all.cc") 
	file(GLOB TEST_SOURCES "src/tests/*.cpp")
	file(GLOB GTEST_SOURCES "src/gtest/src/*.cc")
	add_executable(test_app "src/gtest/src/gtest-all.cc" "src/gtest/src/gtest_main.cc" ${CONSOLE_SOURCES})
	target_include_directories(test_app PUBLIC "src" "src/gtest")
	target_compile_definitions(test_app PUBLIC TESTING)
	add_custom_target(run-test
		COMMAND test_app
	)
else()
	message("Gtest could not be found.  Testing is disabled")
endif()