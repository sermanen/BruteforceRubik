#include "Cube.h"
#include "Cross.h"
#include "Corners.h"
#include "Edges.h"
#include "OLL.h"
#include "PLL.h"
#include "Bruteforce.h"
#include "TMyCube.h"
#include <iostream>

std::string format(std::string);

int main(int argc, char **argv) {

/*
    Cube myCube(false);
    int scrambleNum = 0;
    //std::string argString = "U R U' L' U R' U' L";
    std::string argString = "R' D' R D";

    std::string scramble = format(argString);
    std::cout << "Scramble #" << scrambleNum << ": ";
    myCube.moves(scramble);
    Cross::solveCross(myCube);
    std::cout << "Cross solved" << std::endl;
    Corners::solveCorners(myCube);
    std::cout << "Corners solved" << std::endl;
    Edges::solveEdges(myCube);
    std::cout << "Edges solved" << std::endl;;
    OLL::solveOLL(myCube);
    std::cout << "OLL solved" << std::endl;
    PLL::solvePLL(myCube);
    std::cout << "PLL solved" << std::endl;
*/
    Cube Cube_orig(false);
    Cube Cube_target(false);
    //Cube_target.moves(scramble);
    //Cube_target.moves("RURU");
    //Cube_target.cubies[0][Cube::es_Red]=Cube::es_Yellow;
    //Cube_target.cubies[2][Cube::es_Red]=Cube::es_Green;
    //Cube_target.cubies[0][Cube::es_Blue]=Cube::es_Yellow;
    //Cube_target.cubies[2][Cube::es_Blue]=Cube::es_Red;
    //Cube_target.cubies[2][Cube::es_Orange]=Cube::es_Blue;
    //Cube_target.cubies[0][Cube::es_Green]=Cube::es_Yellow;
    //Cube_target.cubies[0][Cube::es_Yellow]=Cube::es_Orange;
    //Cube_target.cubies[6][Cube::es_Yellow]=Cube::es_Blue;
    //Cube_target.cubies[8][Cube::es_Yellow]=Cube::es_Red;


    Cube_target.moves("BBB");
    Cube_target.outputGrid();

    //Bruteforce bruteforce(Cube_orig,Cube_target);
    //bool find = bruteforce.move(8);

    std::cout << "TMyCube:" << std::endl;

    TMyCube c;
    TMyCube::Emove array[30];
    int cnt=0;
    array[cnt++]=TMyCube::es_R;
    array[cnt++]=TMyCube::es_U;
    array[cnt++]=TMyCube::es_B;
    array[cnt++]=TMyCube::es_F;
    array[cnt++]=TMyCube::es_D;
    array[cnt++]=TMyCube::es_L;
    array[cnt++]=TMyCube::es_Lant;
    array[cnt++]=TMyCube::es_Dant;
    array[cnt++]=TMyCube::es_Fant;
    array[cnt++]=TMyCube::es_Bant;
    array[cnt++]=TMyCube::es_Uant;
    array[cnt++]=TMyCube::es_Rant;


    c.moves(array,cnt);
    c.outputGrid();

    TMyCube c2;

    bool cmp = TMyCube::compare(c,c2);
    std::cout << "compare = "<<((cmp)?"true":"false")<< std::endl;


    /*
    while (std::getline(std::cin, argString)) {
        ++scrambleNum;
        std::string scramble = format(argString);
        std::cout << "Scramble #" << scrambleNum << ": ";
        myCube.moves(scramble);
        Cross::solveCross(myCube);
        std::cout << "Cross solved" << std::endl;
        Corners::solveCorners(myCube);
        std::cout << "Corners solved" << std::endl;
        Edges::solveEdges(myCube);
        std::cout << "Edges solved" << std::endl;;
        OLL::solveOLL(myCube);
        std::cout << "OLL solved" << std::endl;
        PLL::solvePLL(myCube);
        std::cout << "PLL solved" << std::endl;
    }
    */
    return 0;
}

std::string format(std::string s) {
    std::string formatted;

    for (int i=0; i<s.length(); ++i) {
        if (s[i] == '\'') {
            formatted += s[i-1];
            formatted += s[i-1];
        }
        else if (s[i] == '2') {
            formatted += s[i-1];
        }
        else if (s[i] == ' ') {

        }
        else {
            formatted += s[i];
        }
    }

    return formatted;

}
