#ifndef CUBE_H
#define CUBE_H

#include <iostream>

class Cube {

public:
    enum Eside {es_White=0,es_Yellow=1,es_Red=2,es_Green=3,es_Orange=4,es_Blue=5};
    int cubies[9][6];
    /* Set up Cube.
  If scramble set, call scramble.
  Else, set up a solved cube */
    Cube(bool);

    /* By default scramble sets
  cubies to a random state,
  using combination of move functions */
private: void scramble();

public:
    std::string printSequence(std::string);
    void moves(std::string);
    void output();
    void outputGrid();
    void R(int);
    void L(int);
    void U(int);
    void D(int);
    void F(int);
    void B(int);
};
#endif
