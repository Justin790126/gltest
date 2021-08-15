
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
include_directories(
    ${GLEW_INCLUDE_DIRS}
    ${glfw3_INCLUDE_DIRS}
)


add_executable(t1 t1.cpp)
target_link_libraries(
    t1
    ${OPENGL_LIBRARIES}
    ${GLEW_LIBRARIES}
    ${glfw3_LIBRARIES}
    glfw
)