#include "wall2.hpp"

#include <cppitertools/itertools.hpp>

void Wall2::initializeGL(GLuint program) {
  // Unit quad on the xy plane
  // clang-format off
  std::array vertices{glm::vec3(-4.0f, 1.0f,  0.0f), 
                      glm::vec3(-4.0f, -1.0f, 0.0f),
                      glm::vec3( 4.0f, 1.0f,  0.0f),
                      glm::vec3( 4.0f, -1.0f, 0.0f)};
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

void Wall2::paintGL() {
  // Draw wall
  abcg::glBindVertexArray(m_VAO);
  glm::mat4 model{1.0f};
  model = glm::mat4(1.0);
  model = glm::translate(model, glm::vec3(-1.0f, 0.0f, 2.0f));
  model = glm::rotate(model, glm::radians(90.0f), glm::vec3(0, 1, 0));
  abcg::glUniformMatrix4fv(m_modelMatrixLoc, 1, GL_FALSE, &model[0][0]);
  abcg::glUniform4f(m_colorLoc, 0.51f, 0.57f, 0.79f, 1.0f);
  abcg::glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  abcg::glBindVertexArray(0);
}

void Wall2::terminateGL() {
  abcg::glDeleteBuffers(1, &m_VBO);
  abcg::glDeleteVertexArrays(1, &m_VAO);
}