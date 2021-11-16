project(lookatPacman)
add_executable(${PROJECT_NAME} camera.cpp ground.cpp main.cpp openglwindow.cpp wall.cpp wall2.cpp)
enable_abcg(${PROJECT_NAME})
