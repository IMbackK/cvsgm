cmake_minimum_required(VERSION 3.0)

project(texsegm)

set(SRC_FILES
	main.cpp
	)

set(RESOURCE_LOCATION data)

find_package(OpenCV REQUIRED)

link_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries( ${PROJECT_NAME} pthread ${OpenCV_LIBS})
target_include_directories(${PROJECT_NAME} PRIVATE  ${OpenCV_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PRIVATE "-std=c++2a" "-Wall" "-O2" "-g" "-fno-strict-aliasing" "-Wfatal-errors" "-Wno-reorder")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -s")

set(CMAKE_INSTALL_PREFIX "/usr")
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
