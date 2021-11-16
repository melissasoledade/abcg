#ifndef WALL4_HPP_
#define WALL4_HPP_

#include "abcg.hpp"

class Wall4 {
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