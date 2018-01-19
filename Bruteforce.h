#ifndef Bruteforce_H
#define Bruteforce_H

#include <vector>
#include <semaphore.h>

#include "TMyCube.h"

class Bruteforce {

public:
    Bruteforce(TMyCube &origcube,TMyCube &target);
    ~Bruteforce();
    bool move(int deepness);
    bool move2(int deepness);
    std::vector<std::string> m_scrambles;
private:
    bool checkCube(TMyCube &cube);
    bool deepness_1();
    bool deepness_2();
    bool deepness_3();
    bool deepness_4();
    bool deepness_5();
    bool deepness_6();
    bool deepness_7();
    bool deepness_8();
    TMyCube m_origcube;
    TMyCube m_target;
    sem_t   m_semQueue;
    TMyCube::Emove m_moves[12];
    int m_base;
};

#endif
