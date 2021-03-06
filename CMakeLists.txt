PROJECT(Rosbuild-Stub)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
SET(arch ${})

SET(CMAKE_CXX_FLAGS "-std=c++11 -Wall -Werror -lglog")

IF(${CMAKE_BUILD_TYPE} MATCHES "Release")
  MESSAGE(STATUS "Additional Flags for Release mode")
  SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -O3 -DNDEBUG -march=native")
ELSEIF(${CMAKE_BUILD_TYPE} MATCHES "Debug")
  MESSAGE(STATUS "Additional Flags for Debug mode")
  SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -g")
ENDIF()

INCLUDE($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)

ROSBUILD_INIT()
SET(ROS_BUILD_STATIC_LIBS true)
SET(ROS_BUILD_SHARED_LIBS true)

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

ROSBUILD_GENMSG()
ROSBUILD_GENSRV()

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src)

SET(libs roslib roscpp)

ROSBUILD_ADD_EXECUTABLE(helloworld
   src/helloworld.cc)
TARGET_LINK_LIBRARIES(helloworld ${libs})
