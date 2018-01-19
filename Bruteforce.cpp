#include <iostream>
#include <semaphore.h>
#include <sys/time.h>
#include <time.h>
#include <stdio.h>

#include "Bruteforce.h"

Bruteforce::Bruteforce(TMyCube &origcube, TMyCube &target)
{
    m_origcube = origcube;
    m_target   = target;
    sem_t m_semQueue;
    sem_init(&m_semQueue, 0, 1);

    m_base=0;
    m_moves[m_base++]=TMyCube::es_R;
    m_moves[m_base++]=TMyCube::es_U;
    m_moves[m_base++]=TMyCube::es_B;
    m_moves[m_base++]=TMyCube::es_F;
    m_moves[m_base++]=TMyCube::es_D;
    m_moves[m_base++]=TMyCube::es_L;
    m_moves[m_base++]=TMyCube::es_Lant;
    m_moves[m_base++]=TMyCube::es_Dant;
    m_moves[m_base++]=TMyCube::es_Fant;
    m_moves[m_base++]=TMyCube::es_Bant;
    m_moves[m_base++]=TMyCube::es_Uant;
    m_moves[m_base++]=TMyCube::es_Rant;
}
Bruteforce::~Bruteforce()
{
    sem_destroy(&m_semQueue);
}

bool Bruteforce::deepness_1()
{
    int deepness=1;
    bool find=false;
#pragma omp parallel for
    for(int b=0;b<m_base;b++){
        TMyCube::Emove array[2];
        TMyCube c(m_origcube);
        array[0]=m_moves[b];
        c.moves(array,deepness);
        bool cmp = TMyCube::compare(c,m_target);
        if(cmp){
            sem_wait(&m_semQueue);
            std::string s = TMyCube::format(array,deepness);
            m_scrambles.push_back(s);
            find=true;
            std::cout << "formula="<<s<< std::endl;
            sem_post(&m_semQueue);
        }
    }
    return find;
}

bool Bruteforce::deepness_2()
{
    bool find=false;
    int deepness=2;
#pragma omp parallel for
    for(int b0=0;b0<m_base;b0++){
        TMyCube::Emove array[2];
        array[0]=m_moves[b0];
        for(int b1=0;b1<m_base;b1++){
            TMyCube c(m_origcube);
            array[1]=m_moves[b1];
            c.moves(array,deepness);
            bool cmp = TMyCube::compare(c,m_target);
            if(cmp){
                sem_wait(&m_semQueue);
                std::string s = TMyCube::format(array,deepness);
                m_scrambles.push_back(s);
                find=true;
                std::cout << "formula="<<s<< std::endl;
                sem_post(&m_semQueue);
            }
        }
    }
    return find;
}

bool Bruteforce::deepness_3()
{
    bool find=false;
    int deepness=3;
#pragma omp parallel for
    for(int b0=0;b0<m_base;b0++){
        TMyCube::Emove array[3];
        array[0]=m_moves[b0];
        for(int b1=0;b1<m_base;b1++){
            array[1]=m_moves[b1];
            for(int b2=0;b2<m_base;b2++){
                TMyCube c(m_origcube);
                array[2]=m_moves[b2];
                c.moves(array,deepness);
                bool cmp = TMyCube::compare(c,m_target);
                if(cmp){
                    sem_wait(&m_semQueue);
                    std::string s = TMyCube::format(array,deepness);
                    m_scrambles.push_back(s);
                    find=true;
                    std::cout << "formula="<<s<< std::endl;
                    sem_post(&m_semQueue);
                }
            }
        }
    }
    return find;
}

bool Bruteforce::deepness_4()
{
    bool find=false;
    int deepness=4;
#pragma omp parallel for
    for(int b0=0;b0<m_base;b0++){
        TMyCube::Emove array[4];
        array[0]=m_moves[b0];
        for(int b1=0;b1<m_base;b1++){
            array[1]=m_moves[b1];
            for(int b2=0;b2<m_base;b2++){
                array[2]=m_moves[b2];
                for(int b3=0;b3<m_base;b3++){
                    TMyCube c(m_origcube);
                    array[3]=m_moves[b3];
                    c.moves(array,deepness);
                    bool cmp = TMyCube::compare(c,m_target);
                    if(cmp){
                        sem_wait(&m_semQueue);
                        std::string s = TMyCube::format(array,deepness);
                        m_scrambles.push_back(s);
                        find=true;
                        std::cout <<"formula="<<s<< std::endl;
                        sem_post(&m_semQueue);
                    }
                }
            }
        }
    }
    return find;
}

bool Bruteforce::deepness_5()
{
    bool find=false;
    int deepness=5;
#pragma omp parallel for
    for(int b0=0;b0<m_base;b0++){
        TMyCube::Emove array[5];
        array[0]=m_moves[b0];
        for(int b1=0;b1<m_base;b1++){
            array[1]=m_moves[b1];
            for(int b2=0;b2<m_base;b2++){
                array[2]=m_moves[b2];
                for(int b3=0;b3<m_base;b3++){
                    array[3]=m_moves[b3];
                    for(int b4=0;b4<m_base;b4++){
                        TMyCube c(m_origcube);
                        array[4]=m_moves[b4];
                        c.moves(array,deepness);
                        bool cmp = TMyCube::compare(c,m_target);
                        if(cmp){
                            sem_wait(&m_semQueue);
                            std::string s = TMyCube::format(array,deepness);
                            m_scrambles.push_back(s);
                            find=true;
                            std::cout <<"formula="<<s<< std::endl;
                            sem_post(&m_semQueue);
                        }
                    }
                }
            }
        }
    }
    return find;
}
bool Bruteforce::deepness_6()
{
    bool find=false;
    int deepness=6;
#pragma omp parallel for
    for(int b0=0;b0<m_base;b0++){
        TMyCube::Emove array[6];
        array[0]=m_moves[b0];
        for(int b1=0;b1<m_base;b1++){
            array[1]=m_moves[b1];
            for(int b2=0;b2<m_base;b2++){
                array[2]=m_moves[b2];
                for(int b3=0;b3<m_base;b3++){
                    array[3]=m_moves[b3];
                    for(int b4=0;b4<m_base;b4++){
                        array[4]=m_moves[b4];
                        for(int b5=0;b5<m_base;b5++){
                            TMyCube c(m_origcube);
                            array[5]=m_moves[b5];
                            c.moves(array,deepness);
                            bool cmp = TMyCube::compare(c,m_target);
                            if(cmp){
                                sem_wait(&m_semQueue);
                                std::string s = TMyCube::format(array,deepness);
                                m_scrambles.push_back(s);
                                find=true;
                                std::cout <<"formula="<<s<< std::endl;
                                sem_post(&m_semQueue);
                            }
                        }
                    }
                }
            }
        }
    }
    return find;
}

bool Bruteforce::deepness_7()
{
    bool find=false;
    int deepness=7;
#pragma omp parallel for
    for(int b0=0;b0<m_base;b0++){
        TMyCube::Emove array[7];
        array[0]=m_moves[b0];
        for(int b1=0;b1<m_base;b1++){
            array[1]=m_moves[b1];
            for(int b2=0;b2<m_base;b2++){
                array[2]=m_moves[b2];
                for(int b3=0;b3<m_base;b3++){
                    array[3]=m_moves[b3];
                    for(int b4=0;b4<m_base;b4++){
                        array[4]=m_moves[b4];
                        for(int b5=0;b5<m_base;b5++){
                            array[5]=m_moves[b5];
                            for(int b6=0;b6<m_base;b6++){
                                TMyCube c(m_origcube);
                                array[6]=m_moves[b6];
                                c.moves(array,deepness);
                                bool cmp = TMyCube::compare(c,m_target);
                                if(cmp){
                                    sem_wait(&m_semQueue);
                                    std::string s = TMyCube::format(array,deepness);
                                    m_scrambles.push_back(s);
                                    find=true;
                                    std::cout <<"formula="<<s<< std::endl;
                                    sem_post(&m_semQueue);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return find;
}

bool Bruteforce::deepness_8()
{
    bool find=false;
    int deepness=8;
#pragma omp parallel for
    for(int b0=0;b0<m_base;b0++){
        TMyCube::Emove array[8];
        array[0]=m_moves[b0];
        for(int b1=0;b1<m_base;b1++){
            array[1]=m_moves[b1];
            for(int b2=0;b2<m_base;b2++){
                array[2]=m_moves[b2];
                for(int b3=0;b3<m_base;b3++){
                    array[3]=m_moves[b3];
                    for(int b4=0;b4<m_base;b4++){
                        array[4]=m_moves[b4];
                        for(int b5=0;b5<m_base;b5++){
                            array[5]=m_moves[b5];
                            for(int b6=0;b6<m_base;b6++){
                                array[6]=m_moves[b6];
                                for(int b7=0;b7<m_base;b7++){
                                    TMyCube c(m_origcube);
                                    array[7]=m_moves[b7];
                                    c.moves(array,deepness);
                                    bool cmp = TMyCube::compare(c,m_target);
                                    if(cmp){
                                        sem_wait(&m_semQueue);
                                        std::string s = TMyCube::format(array,deepness);
                                        m_scrambles.push_back(s);
                                        find=true;
                                        std::cout <<"formula="<<s<< std::endl;
                                        sem_post(&m_semQueue);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return find;
}


bool Bruteforce::move2(int deepness)
{
    bool find=false;

    long maxiteration=1;
    for(int d=0;d<deepness;d++){
        maxiteration*=m_base;
    }

    //maxiteration=20;

    find = find || deepness_1();
    find = find || deepness_2();
    find = find || deepness_3();
    find = find || deepness_4();
    find = find || deepness_5();
    find = find || deepness_6();
    find = find || deepness_7();
    find = find || deepness_8();

    return find;
}
bool Bruteforce::move(int deepness)
{
    bool find=false;
    long base=12;
    TMyCube::Emove moves[13];
    int cnt=0;
    moves[cnt++]=TMyCube::es_R;
    moves[cnt++]=TMyCube::es_U;
    moves[cnt++]=TMyCube::es_B;
    moves[cnt++]=TMyCube::es_F;
    moves[cnt++]=TMyCube::es_D;
    moves[cnt++]=TMyCube::es_L;
    moves[cnt++]=TMyCube::es_Lant;
    moves[cnt++]=TMyCube::es_Dant;
    moves[cnt++]=TMyCube::es_Fant;
    moves[cnt++]=TMyCube::es_Bant;
    moves[cnt++]=TMyCube::es_Uant;
    moves[cnt++]=TMyCube::es_Rant;

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

//#pragma omp parallel for
    for(long i=0;i<maxiteration;i++){
        long number12=0;
        long number12_next=i;
        std::string scramble;
        do{
            number12=number12_next%base;
            scramble+=moves[number12];
            number12_next=number12_next/base;
        }while(number12_next>0);
        TMyCube origcube;
        //origcube.moves(scramble);
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
bool Bruteforce::checkCube(TMyCube &cube)
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

