#include "wall4.hpp"

#include <cppitertools/itertools.hpp>

void Wall4::initializeGL(GLuint program) {
  // Unit quad on the xy plane
  // clang-format off
  std::array vertices{glm::vec3(-2.5f, 1.0f,  0.0f), 
                      glm::vec3(-2.5f, -1.0f, 0.0f),
                      glm::vec3( 2.5f, 1.0f,  0.0f),
                      glm::vec3( 2.5f, -1.0f, 0.0f)};
  // clang-format on                      

  // Generate VBO
  abcg::glGenBuffers(1, &m_VBO);
  abcg::glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
  abcg::glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(),
                     GL_STATIC_DRAW);
  abcg::glBindBuffer(GL_ARRAY_BUFFER, 0);

  // Create VAO and bind vertex attributes
  abcg::glGenVertexArrays(1, &m_VAO);
  abcg::glBindVertexArray(m_VAO);
  abcg::glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
  const GLint posAttrib{abcg::glGetAttribLocation(program, "inPosition")};
  abcg::glEnableVertexAttribArray(posAttrib);
  abcg::glVertexAttribPointer(posAttrib, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
  abcg::glBindBuffer(GL_ARRAY_BUFFER, 0);
  abcg::glBindVertexArray(0);

  // Save location of uniform variables
  m_modelMatrixLoc = abcg::glGetUniformLocation(program, "modelMatrix");
  m_colorLoc = abcg::glGetUniformLocation(program, "color");
}

void Wall4::paintGL() {

abcg::glBindVertexArray(m_VAO);
  // Draw wall
  glm::mat4 model{1.0f};
  model = glm::mat4(1.0);
  model = glm::translate(model, glm::vec3(3.5f, 0.0f, 0.5f));
  abcg::glUniformMatrix4fv(m_modelMatrixLoc, 1, GL_FALSE, &model[0][0]);
  abcg::glUniform4f(m_colorLoc, 0.51f, 0.57f, 0.79f, 1.0f);
  abcg::glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  abcg::glBindVertexArray(0);
}

void Wall4::terminateGL() {
  abcg::glDeleteBuffers(1, &m_VBO);
  abcg::glDeleteVertexArrays(1, &m_VAO);
}