
cmake_minimum_required(VERSION 3.1)
project(Tutorial)

find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(OpenCV REQUIRED)
find_package(glfw3 REQUIRED)
include_directories(
    ${GLEW_INCLUDE_DIRS}
    ${glfw3_INCLUDE_DIRS}
    ${OpenCV_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}/common/
)


add_executable(t1
    ${PROJECT_SOURCE_DIR}/t1/t1.cpp
)
target_link_libraries(
    t1
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${glfw3_LIBRARIES}
    glfw
)

add_executable(t2
  ${PROJECT_SOURCE_DIR}/t2/t2.cpp
    ${PROJECT_SOURCE_DIR}/common/shader.cpp
)
target_link_libraries(
    t2
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${glfw3_LIBRARIES}
    glfw
)


add_executable(t3
  ${PROJECT_SOURCE_DIR}/t3/t3.cpp
    ${PROJECT_SOURCE_DIR}/common/shader.cpp
)
target_link_libraries(
    t3
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${glfw3_LIBRARIES}
    glfw
)


add_executable(t5
  ${PROJECT_SOURCE_DIR}/t5/t5.cpp
    ${PROJECT_SOURCE_DIR}/common/shader.cpp
    ${PROJECT_SOURCE_DIR}/common/texture.cpp
)
target_link_libraries(
    t5
    ${OPENGL_LIBRARIES}
    ${OpenCV_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${glfw3_LIBRARIES}
    glfw
)