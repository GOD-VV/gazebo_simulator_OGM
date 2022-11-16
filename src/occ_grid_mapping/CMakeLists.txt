cmake_minimum_required(VERSION 2.8.3)
project(occ_grid_mapping)


add_compile_options(-std=c++11)
#SET(CMAKE_BUILD_TYPE Release)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
  cv_bridge
  geometry_msgs
  nav_msgs
  sensor_msgs
  std_msgs
  tf
)


catkin_package(
)

find_package(OpenCV 3.0 QUIET)
find_package(Eigen3  REQUIRED)

include_directories(
${catkin_INCLUDE_DIRS}
${PROJECT_SOURCE_DIR}
${PROJECT_SOURCE_DIR}/include
${EIGEN3_INCLUDE_DIR}
)

add_library(${PROJECT_NAME} SHARED
src/grid_mapping.cpp
src/grid_mapper.cpp
)

target_link_libraries(${PROJECT_NAME}
${catkin_LIBRARIES}
${OpenCV_LIBS}
${EIGEN3_LIBS}
)

add_executable(mapping
src/mapping.cpp)
target_link_libraries(mapping
  ${catkin_LIBRARIES}
  ${PROJECT_NAME}
)

add_executable(odometry
src/odometry.cpp)
target_link_libraries(odometry
  ${catkin_LIBRARIES}
  ${PROJECT_NAME}
)

