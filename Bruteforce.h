#ifndef Bruteforce_H
#define Bruteforce_H

#include "Cube.h"
#include <vector>

class Bruteforce {

public:
    Bruteforce(Cube &origcube,Cube &target);
    bool move(int deepness);
    std::vector<std::string> m_scrambles;
private:
    bool checkCube(Cube &cube);
    Cube m_origcube;
    Cube m_target;
};

#endif
