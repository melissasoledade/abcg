#ifndef WALL3_HPP_
#define WALL3_HPP_

#include "abcg.hpp"

class Wall3 {
 public:
  void initializeGL(GLuint program);
  void paintGL();
  void terminateGL();

 private:
  GLuint m_VAO{};
  GLuint m_VBO{};

  GLint m_modelMatrixLoc{};
  GLint m_colorLoc{};
};

#endif