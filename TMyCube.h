#ifndef TMyCube_H
#define TMyCube_H

#include <iostream>

class TMyCube {

public:
    enum Eside {es_White=0,es_Yellow=1,es_Red=2,es_Green=3,es_Orange=4,es_Blue=5};
    enum Emove {es_R=0,es_L=1,es_U=2,es_D=3,es_F=4,es_B=5,es_Rant=6,es_Lant=7,es_Uant=8,es_Dant=9,es_Fant=10,es_Bant=11};
    int cubies[9][6];
    TMyCube();
    TMyCube(const TMyCube &c);
    static bool compare(const TMyCube&c1,const TMyCube&c2);
    static std::string format(Emove *array, int count);
public:
    std::string printSequence(std::string);
    void moves(Emove *array, int count);
    void outputGrid();
    void R_clockwise();
    void L_clockwise();
    void U_clockwise();
    void D_clockwise();
    void F_clockwise();
    void B_clockwise();
    void R_anticlockwise();
    void L_anticlockwise();
    void U_anticlockwise();
    void D_anticlockwise();
    void F_anticlockwise();
    void B_anticlockwise();
};

#endif
