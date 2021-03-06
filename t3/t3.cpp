#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
GLFWwindow *window;

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "shader.h"



using namespace glm;

int main() {
  glewExperimental = true; // Needed for core profile
  if (!glfwInit()) {
    fprintf(stderr, "Failed to initialize GLFW\n");
    return -1;
  }

  glfwWindowHint(GLFW_SAMPLES, 4);               // 4x antialiasing
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,
                 GL_TRUE); // To make MacOS happy; should not be needed
  glfwWindowHint(GLFW_OPENGL_PROFILE,
                 GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL

  // Open a window and create its OpenGL context
   // (In the accompanying source code, this variable is
                      // global for simplicity)
  window = glfwCreateWindow(1024, 768, "Tutorial 01", NULL, NULL);
  if (window == NULL) {
    fprintf(stderr,
            "Failed to open GLFW window. If you have an Intel GPU, they are "
            "not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window); // Initialize GLEW
  glewExperimental = true;        // Needed in core profile
  if (glewInit() != GLEW_OK) {
    fprintf(stderr, "Failed to initialize GLEW\n");
    return -1;
  }

  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

  glClearColor(0,0,0.4,0);



  GLuint VertexArrayID;
  glGenVertexArrays(1, &VertexArrayID);
  glBindVertexArray(VertexArrayID);

  GLuint programID = LoadShaders( "t3/t3.vertexshader", "t3/t3.fragmentshader" );
  GLuint MatrixID = glGetUniformLocation(programID, "MVP");

  glm::mat4 Projection = glm::perspective(
    glm::radians(45.0f),
    4.0f/3.0f ,0.1f,100.0f);

  glm::mat4 View = glm::lookAt(
    glm::vec3(4,3,3),
    glm::vec3(0,0,0),
    glm::vec3(0,1,0)
  );

  glm::mat4 Model = glm::mat4(1.0f);

  glm::mat4 mvp = Projection*View*Model;




  static const GLfloat g_vertex_buffer_data[] = {
    -1.0f, -1.0f, 0.0f,
    1.0f, -1.0f, 0.0f,
    0.0f,  1.0f, 0.0f,
  };

   GLuint vertexbuffer;
   glGenBuffers(1, &vertexbuffer);
   glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
   glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

  do {
    // Clear the screen. It's not mentioned before Tutorial 02, but it can cause
    // flickering, so it's there nonetheless.
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(programID);

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);
    // Draw nothing, see you in tutorial 2 !
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
        0,
        3,
        GL_FLOAT,
        GL_FALSE,
        0,
        (void*)0
    );

    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0);


    // Swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();

  } // Check if the ESC key was pressed or the window was closed
  while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
         glfwWindowShouldClose(window) == 0);
}
