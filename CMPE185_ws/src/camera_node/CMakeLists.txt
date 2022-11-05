cmake_minimum_required(VERSION 3.8)
project(camera_node)

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(OpenCV 4.2 REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(rclcpp REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

include_directories(include)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(camera_node_exe src/camera_node_main.cpp src/camera.cpp src/camera_node.cpp)
target_link_libraries(camera_node_exe ${OpenCV_LIBS})
ament_target_dependencies(camera_node_exe rclcpp cv_bridge)

install(TARGETS
  camera_node_exe
  DESTINATION lib/${PROJECT_NAME})

ament_package()
