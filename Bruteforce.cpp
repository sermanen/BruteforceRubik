#include <iostream>
#include <semaphore.h>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>

#include "Bruteforce.h"

Bruteforce::Bruteforce(Cube &origcube,Cube &target):m_origcube(false),m_target(false)
{
    m_origcube = origcube;
    m_target   = target;
}
bool Bruteforce::move(int deepness)
{
    bool find=false;
    long base=13;
    std::string moves[13];
    moves[ 0] = "R";
    moves[ 1] = "R";
    moves[ 2] = "L";
    moves[ 3] = "U";
    moves[ 4] = "D";
    moves[ 5] = "F";
    moves[ 6] = "B";
    moves[ 7] = "RRR";
    moves[ 8] = "LLL";
    moves[ 9] = "UUU";
    moves[10] = "DDD";
    moves[11] = "FFF";
    moves[12] = "BBB";
    long maxiteration=1;
    for(int d=0;d<deepness;d++){
        maxiteration*=base;
    }

    //maxiteration=10000000;

    timeval t0,t1;
    gettimeofday(&t0,NULL);

    std::cout<<"start Bruteforce "<<maxiteration<<std::endl;

    sem_t m_semQueue;
    sem_init(&m_semQueue, 0, 1);
    long ps = maxiteration/100;

#pragma omp parallel for
    for(long i=0;i<maxiteration;i++){
        long number12=0;
        long number12_next=i;
        std::string scramble;
        do{
            number12=number12_next%base;
            scramble+=moves[number12];
            number12_next=number12_next/base;
        }while(number12_next>0);
        Cube origcube(false);
        origcube.moves(scramble);
        bool ret = checkCube(origcube);
        if(ret){
            sem_wait(&m_semQueue);
            m_scrambles.push_back(scramble);
            find=true;
            std::cout << "i="<<i<<" formula="<<scramble<< std::endl;
            sem_post(&m_semQueue);
            //break;
        }
        //if(i%ps==0){
        //    std::cout << "ps="<<100.0*((double)i/(double)maxiteration)<< std::endl;
        //}
    }
    sem_destroy(&m_semQueue);

    gettimeofday(&t1,NULL);
    double dt = ((double)t1.tv_sec-(double)t0.tv_sec)+((double)t1.tv_usec-(double)t0.tv_usec)/1000000.0;
    double speed = (double)maxiteration/dt;
    printf("Bruteforce speed = %lf Mv/s time=%lf\n",speed,dt);
    //m_scrambles;
    return find;

}
bool Bruteforce::checkCube(Cube &cube)
{
    bool ret = true;
    for (int sticker=0; sticker<9; ++sticker) {
        for (int side=0; side<6; ++side) {
            if(m_target.cubies[sticker][side]!= cube.cubies[sticker][side]){
                return false;
            }
        }
    }
    return ret;
}

