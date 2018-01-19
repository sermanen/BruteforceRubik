#include "TMyCube.h"
#include <iostream>
#include <sstream>      // std::stringstream


TMyCube::TMyCube(const TMyCube &c)
{
    for (int sticker=0; sticker<9; sticker++) {
        for (int side=0; side<6; side++) {
            cubies[sticker][side] = c.cubies[sticker][side];
        }
    }
}
TMyCube::TMyCube()
{
    int m=0;
    for (int sticker=0; sticker<9; sticker++) {
        for (int side=0; side<6; side++) {
            //cubies[sticker][side] = side;
            cubies[sticker][side] = m++;
        }
    }
}

std::string TMyCube::format(Emove *array, int count) {
    std::string formatted;

    for(int i=0;i<count;i++){
        switch(array[i]){
        case es_R:
            formatted+="R ";
            break;
        case es_L:
            formatted+="L ";
            break;
        case es_U:
            formatted+="U ";
            break;
        case es_D:
            formatted+="D ";
            break;
        case es_F:
            formatted+="F ";
            break;
        case es_B:
            formatted+="B ";
            break;
        case es_Rant:
            formatted+="R' ";
            break;
        case es_Lant:
            formatted+="L' ";
            break;
        case es_Uant:
            formatted+="U' ";
            break;
        case es_Dant:
            formatted+="D' ";
            break;
        case es_Fant:
            formatted+="F' ";
            break;
        case es_Bant:
            formatted+="B' ";
            break;
        default:
            break;
        }
    }

    return formatted;

}

bool TMyCube::compare(const TMyCube&c1,const TMyCube&c2)
{
    for (int sticker=0; sticker<9; sticker++) {
        for (int side=0; side<6; side++) {
            //cubies[sticker][side] = side;
            if(c1.cubies[sticker][side] != c2.cubies[sticker][side]){
                return false;
            }
        }
    }
    return true;
}

void TMyCube::moves(Emove *array, int count)
{
    for(int i=0;i<count;i++){
        switch(array[i]){
        case es_R:
            R_clockwise();
            break;
        case es_L:
            L_clockwise();
            break;
        case es_U:
            U_clockwise();
            break;
        case es_D:
            D_clockwise();
            break;
        case es_F:
            F_clockwise();
            break;
        case es_B:
            B_clockwise();
            break;
        case es_Rant:
            R_anticlockwise();
            break;
        case es_Lant:
            L_anticlockwise();
            break;
        case es_Uant:
            U_anticlockwise();
            break;
        case es_Dant:
            D_anticlockwise();
            break;
        case es_Fant:
            F_anticlockwise();
            break;
        case es_Bant:
            B_anticlockwise();
            break;
        default:
            break;
        }
    }
}
void TMyCube::outputGrid()
{
    const char *cmask="wyrgob";
    std::string mask[9*6];
    char string[5];

    for (int m=0,i=0;i<9;++i) {
        for (int j=0;j<6;++j) {
            std::stringstream ss;
            ss<<cmask[j]<<i;
            mask[m++]=ss.str();
        }
    }

    for(int i=0;i<3;i++)std::cout<<"    ";
    for(int i=0;i<3;i++)std::cout<<"["<<mask[cubies[i+0][es_Yellow]]<<"]";
    for(int i=0;i<6;i++)std::cout<<"    ";
    std::cout << std::endl;

    for(int i=0;i<3;i++)std::cout<<"    ";
    for(int i=0;i<3;i++)std::cout<<"["<<mask[cubies[i+3][es_Yellow]]<<"]";
    for(int i=0;i<6;i++)std::cout<<"    ";
    std::cout << std::endl;

    for(int i=0;i<3;i++)std::cout<<"    ";
    for(int i=0;i<3;i++)std::cout<<"["<<mask[cubies[i+6][es_Yellow]]<<"]";
    for(int i=0;i<6;i++)std::cout<<"    ";
    std::cout << std::endl;

    for(int i=0;i<3;i++)std::cout<<"["<<mask[cubies[0+i][es_Blue]]<<"]";
    for(int i=0;i<3;i++)std::cout<<"["<<mask[cubies[0+i][es_Red]]<<"]";
    for(int i=0;i<3;i++)std::cout<<"["<<mask[cubies[0+i][es_Green]]<<"]";
    for(int i=0;i<3;i++)std::cout<<"["<<mask[cubies[0+i][es_Orange]]<<"]";
    std::cout << std::endl;

    for(int i=0;i<3;i++)std::cout<<"["<<mask[cubies[3+i][es_Blue]]<<"]";
    for(int i=0;i<3;i++)std::cout<<"["<<mask[cubies[3+i][es_Red]]<<"]";
    for(int i=0;i<3;i++)std::cout<<"["<<mask[cubies[3+i][es_Green]]<<"]";
    for(int i=0;i<3;i++)std::cout<<"["<<mask[cubies[3+i][es_Orange]]<<"]";
    std::cout << std::endl;

    for(int i=0;i<3;i++)std::cout<<"["<<mask[cubies[6+i][es_Blue]]<<"]";
    for(int i=0;i<3;i++)std::cout<<"["<<mask[cubies[6+i][es_Red]]<<"]";
    for(int i=0;i<3;i++)std::cout<<"["<<mask[cubies[6+i][es_Green]]<<"]";
    for(int i=0;i<3;i++)std::cout<<"["<<mask[cubies[6+i][es_Orange]]<<"]";
    std::cout << std::endl;

    for(int i=0;i<3;i++)std::cout<<"    ";
    for(int i=0;i<3;i++)std::cout<<"["<<mask[cubies[i+0][es_White]]<<"]";
    for(int i=0;i<6;i++)std::cout<<"    ";
    std::cout << std::endl;

    for(int i=0;i<3;i++)std::cout<<"    ";
    for(int i=0;i<3;i++)std::cout<<"["<<mask[cubies[i+3][es_White]]<<"]";
    for(int i=0;i<6;i++)std::cout<<"    ";
    std::cout << std::endl;

    for(int i=0;i<3;i++)std::cout<<"    ";
    for(int i=0;i<3;i++)std::cout<<"["<<mask[cubies[i+6][es_White]]<<"]";
    for(int i=0;i<6;i++)std::cout<<"    ";
    std::cout << std::endl;
}

void TMyCube::R_clockwise()
{
    int newCubies[9][6];
    for (int i=0;i<9;++i) {
        for (int j=0;j<6;++j) {
            newCubies[i][j] = cubies[i][j];
        }
    }

    //Orange->White
    cubies[2][0] = newCubies[6][4];
    cubies[5][0] = newCubies[3][4];
    cubies[8][0] = newCubies[0][4];

    //White->Red
    cubies[2][2] = newCubies[2][0];
    cubies[5][2] = newCubies[5][0];
    cubies[8][2] = newCubies[8][0];

    //Red->Yellow
    cubies[2][1] = newCubies[2][2];
    cubies[5][1] = newCubies[5][2];
    cubies[8][1] = newCubies[8][2];

    //Yellow->Orange
    cubies[6][4] = newCubies[2][1];
    cubies[3][4] = newCubies[5][1];
    cubies[0][4] = newCubies[8][1];

    //Rotate Green
    cubies[0][3] = newCubies[6][3];
    cubies[1][3] = newCubies[3][3];
    cubies[2][3] = newCubies[0][3];
    cubies[3][3] = newCubies[7][3];
    cubies[5][3] = newCubies[1][3];
    cubies[6][3] = newCubies[8][3];
    cubies[7][3] = newCubies[5][3];
    cubies[8][3] = newCubies[2][3];
}

void TMyCube::L_clockwise()
{
    int newCubies[9][6];
    for (int i=0;i<9;++i) {
        for (int j=0;j<6;++j) {
            newCubies[i][j] = cubies[i][j];
        }
    }

    //White->Orange
    cubies[2][4] = newCubies[6][0];
    cubies[5][4] = newCubies[3][0];
    cubies[8][4] = newCubies[0][0];

    //Orange->Yellow
    cubies[6][1] = newCubies[2][4];
    cubies[3][1] = newCubies[5][4];
    cubies[0][1] = newCubies[8][4];

    //Yellow->Red
    cubies[0][2] = newCubies[0][1];
    cubies[3][2] = newCubies[3][1];
    cubies[6][2] = newCubies[6][1];

    //Red->White
    cubies[0][0] = newCubies[0][2];
    cubies[3][0] = newCubies[3][2];
    cubies[6][0] = newCubies[6][2];

    //Rotate Blue
    cubies[0][5] = newCubies[6][5];
    cubies[1][5] = newCubies[3][5];
    cubies[2][5] = newCubies[0][5];
    cubies[3][5] = newCubies[7][5];
    cubies[5][5] = newCubies[1][5];
    cubies[6][5] = newCubies[8][5];
    cubies[7][5] = newCubies[5][5];
    cubies[8][5] = newCubies[2][5];
}

void TMyCube::U_clockwise()
{
    int newCubies[9][6];
    for (int i=0;i<9;++i) {
        for (int j=0;j<6;++j) {
            newCubies[i][j] = cubies[i][j];
        }
    }

    //Orange->Green
    cubies[0][3] = newCubies[0][4];
    cubies[1][3] = newCubies[1][4];
    cubies[2][3] = newCubies[2][4];

    //Green->Red
    cubies[0][2] = newCubies[0][3];
    cubies[1][2] = newCubies[1][3];
    cubies[2][2] = newCubies[2][3];

    //Red->Blue
    cubies[0][5] = newCubies[0][2];
    cubies[1][5] = newCubies[1][2];
    cubies[2][5] = newCubies[2][2];

    //Blue->Orange
    cubies[0][4] = newCubies[0][5];
    cubies[1][4] = newCubies[1][5];
    cubies[2][4] = newCubies[2][5];

    //Rotate Yellow
    cubies[0][1] = newCubies[6][1];
    cubies[1][1] = newCubies[3][1];
    cubies[2][1] = newCubies[0][1];
    cubies[3][1] = newCubies[7][1];
    cubies[5][1] = newCubies[1][1];
    cubies[6][1] = newCubies[8][1];
    cubies[7][1] = newCubies[5][1];
    cubies[8][1] = newCubies[2][1];
}
void TMyCube::D_clockwise()
{
    int newCubies[9][6];
    for (int i=0;i<9;++i) {
        for (int j=0;j<6;++j) {
            newCubies[i][j] = cubies[i][j];
        }
    }

    //Orange->Blue
    cubies[6][5] = newCubies[6][4];
    cubies[7][5] = newCubies[7][4];
    cubies[8][5] = newCubies[8][4];

    //Blue->Red
    cubies[6][2] = newCubies[6][5];
    cubies[7][2] = newCubies[7][5];
    cubies[8][2] = newCubies[8][5];

    //Red->Green
    cubies[6][3] = newCubies[6][2];
    cubies[7][3] = newCubies[7][2];
    cubies[8][3] = newCubies[8][2];

    //Green->Orange
    cubies[6][4] = newCubies[6][3];
    cubies[7][4] = newCubies[7][3];
    cubies[8][4] = newCubies[8][3];

    //Rotate White
    cubies[0][0] = newCubies[6][0];
    cubies[1][0] = newCubies[3][0];
    cubies[2][0] = newCubies[0][0];
    cubies[3][0] = newCubies[7][0];
    cubies[5][0] = newCubies[1][0];
    cubies[6][0] = newCubies[8][0];
    cubies[7][0] = newCubies[5][0];
    cubies[8][0] = newCubies[2][0];
}
void TMyCube::F_clockwise()
{
    int newCubies[9][6];
    for (int i=0;i<9;++i) {
        for (int j=0;j<6;++j) {
            newCubies[i][j] = cubies[i][j];
        }
    }

    //Blue->Yellow
    cubies[8][1] = newCubies[2][5];
    cubies[7][1] = newCubies[5][5];
    cubies[6][1] = newCubies[8][5];

    //Yellow->Green
    cubies[0][3] = newCubies[6][1];
    cubies[3][3] = newCubies[7][1];
    cubies[6][3] = newCubies[8][1];

    //Green->White
    cubies[2][0] = newCubies[0][3];
    cubies[1][0] = newCubies[3][3];
    cubies[0][0] = newCubies[6][3];

    //White->Blue
    cubies[2][5] = newCubies[0][0];
    cubies[5][5] = newCubies[1][0];
    cubies[8][5] = newCubies[2][0];

    //Rotate Red
    cubies[0][2] = newCubies[6][2];
    cubies[1][2] = newCubies[3][2];
    cubies[2][2] = newCubies[0][2];
    cubies[3][2] = newCubies[7][2];
    cubies[5][2] = newCubies[1][2];
    cubies[6][2] = newCubies[8][2];
    cubies[7][2] = newCubies[5][2];
    cubies[8][2] = newCubies[2][2];
}
void TMyCube::B_clockwise()
{
    int newCubies[9][6];
    for (int i=0;i<9;++i) {
        for (int j=0;j<6;++j) {
            newCubies[i][j] = cubies[i][j];
        }
    }

    //Yellow->Blue
    cubies[6][5] = newCubies[0][1];
    cubies[3][5] = newCubies[1][1];
    cubies[0][5] = newCubies[2][1];

    //Blue->White
    cubies[6][0] = newCubies[0][5];
    cubies[7][0] = newCubies[3][5];
    cubies[8][0] = newCubies[6][5];

    //White->Green
    cubies[8][3] = newCubies[6][0];
    cubies[5][3] = newCubies[7][0];
    cubies[2][3] = newCubies[8][0];

    //Green->Yellow
    cubies[0][1] = newCubies[2][3];
    cubies[1][1] = newCubies[5][3];
    cubies[2][1] = newCubies[8][3];

    //Rotate Orange
    cubies[0][4] = newCubies[6][4];
    cubies[1][4] = newCubies[3][4];
    cubies[2][4] = newCubies[0][4];
    cubies[3][4] = newCubies[7][4];
    cubies[5][4] = newCubies[1][4];
    cubies[6][4] = newCubies[8][4];
    cubies[7][4] = newCubies[5][4];
    cubies[8][4] = newCubies[2][4];
}
void TMyCube::R_anticlockwise()
{
    int newCubies[9][6];
    for (int i=0;i<9;++i) {
        for (int j=0;j<6;++j) {
            newCubies[i][j] = cubies[i][j];
        }
    }

    //Orange->White
    cubies[2][0] = newCubies[2][es_Red];
    cubies[5][0] = newCubies[5][es_Red];
    cubies[8][0] = newCubies[8][es_Red];

    //White->Red
    cubies[2][2] = newCubies[2][es_Yellow];
    cubies[5][2] = newCubies[5][es_Yellow];
    cubies[8][2] = newCubies[8][es_Yellow];

    //Red->Yellow
    cubies[2][1] = newCubies[6][es_Orange];
    cubies[5][1] = newCubies[3][es_Orange];
    cubies[8][1] = newCubies[0][es_Orange];

    //Yellow->Orange
    cubies[6][4] = newCubies[2][es_White];
    cubies[3][4] = newCubies[5][es_White];
    cubies[0][4] = newCubies[8][es_White];

    //Rotate Green
    cubies[0][es_Green] = newCubies[2][es_Green];
    cubies[1][es_Green] = newCubies[5][es_Green];
    cubies[2][es_Green] = newCubies[8][es_Green];
    cubies[3][es_Green] = newCubies[1][es_Green];
    cubies[5][es_Green] = newCubies[7][es_Green];
    cubies[6][es_Green] = newCubies[0][es_Green];
    cubies[7][es_Green] = newCubies[3][es_Green];
    cubies[8][es_Green] = newCubies[6][es_Green];
}
void TMyCube::L_anticlockwise()
{
    int newCubies[9][6];
    for (int i=0;i<9;++i) {
        for (int j=0;j<6;++j) {
            newCubies[i][j] = cubies[i][j];
        }
    }

    //White->Orange
    cubies[2][4] = newCubies[6][1];
    cubies[5][4] = newCubies[3][1];
    cubies[8][4] = newCubies[0][1];

    //Orange->Yellow
    cubies[6][1] = newCubies[6][2];
    cubies[3][1] = newCubies[3][2];
    cubies[0][1] = newCubies[0][2];

    //Yellow->Red
    cubies[0][2] = newCubies[0][0];
    cubies[3][2] = newCubies[3][0];
    cubies[6][2] = newCubies[6][0];

    //Red->White
    cubies[0][0] = newCubies[8][4];
    cubies[3][0] = newCubies[5][4];
    cubies[6][0] = newCubies[2][4];

    //Rotate Blue
    cubies[0][5] = newCubies[2][5];
    cubies[1][5] = newCubies[5][5];
    cubies[2][5] = newCubies[8][5];
    cubies[3][5] = newCubies[1][5];
    cubies[5][5] = newCubies[7][5];
    cubies[6][5] = newCubies[0][5];
    cubies[7][5] = newCubies[3][5];
    cubies[8][5] = newCubies[6][5];
}
void TMyCube::U_anticlockwise()
{
    int newCubies[9][6];
    for (int i=0;i<9;++i) {
        for (int j=0;j<6;++j) {
            newCubies[i][j] = cubies[i][j];
        }
    }

    //Orange->Green
    cubies[0][3] = newCubies[0][2];
    cubies[1][3] = newCubies[1][2];
    cubies[2][3] = newCubies[2][2];

    //Green->Red
    cubies[0][2] = newCubies[0][5];
    cubies[1][2] = newCubies[1][5];
    cubies[2][2] = newCubies[2][5];

    //Red->Blue
    cubies[0][5] = newCubies[0][4];
    cubies[1][5] = newCubies[1][4];
    cubies[2][5] = newCubies[2][4];

    //Blue->Orange
    cubies[0][4] = newCubies[0][3];
    cubies[1][4] = newCubies[1][3];
    cubies[2][4] = newCubies[2][3];

    //Rotate Yellow
    cubies[0][1] = newCubies[2][1];
    cubies[1][1] = newCubies[5][1];
    cubies[2][1] = newCubies[8][1];
    cubies[3][1] = newCubies[1][1];
    cubies[5][1] = newCubies[7][1];
    cubies[6][1] = newCubies[0][1];
    cubies[7][1] = newCubies[3][1];
    cubies[8][1] = newCubies[6][1];

}
void TMyCube::D_anticlockwise()
{
    int newCubies[9][6];
    for (int i=0;i<9;++i) {
        for (int j=0;j<6;++j) {
            newCubies[i][j] = cubies[i][j];
        }
    }

    //Red->Blue
    cubies[6][5] = newCubies[6][2];
    cubies[7][5] = newCubies[7][2];
    cubies[8][5] = newCubies[8][2];

    //Green->Red
    cubies[6][2] = newCubies[6][3];
    cubies[7][2] = newCubies[7][3];
    cubies[8][2] = newCubies[8][3];

    //Orange->Green
    cubies[6][3] = newCubies[6][4];
    cubies[7][3] = newCubies[7][4];
    cubies[8][3] = newCubies[8][4];

    //Blue->Orange
    cubies[6][4] = newCubies[6][5];
    cubies[7][4] = newCubies[7][5];
    cubies[8][4] = newCubies[8][5];

    //Rotate White
    cubies[0][0] = newCubies[2][0];
    cubies[1][0] = newCubies[5][0];
    cubies[2][0] = newCubies[8][0];
    cubies[3][0] = newCubies[1][0];
    cubies[5][0] = newCubies[7][0];
    cubies[6][0] = newCubies[0][0];
    cubies[7][0] = newCubies[3][0];
    cubies[8][0] = newCubies[6][0];
}
void TMyCube::F_anticlockwise()
{
    int newCubies[9][6];
    for (int i=0;i<9;++i) {
        for (int j=0;j<6;++j) {
            newCubies[i][j] = cubies[i][j];
        }
    }

    //Green->Yellow
    cubies[8][1] = newCubies[6][3];
    cubies[7][1] = newCubies[3][3];
    cubies[6][1] = newCubies[0][3];

    //White->Green
    cubies[0][3] = newCubies[2][0];
    cubies[3][3] = newCubies[1][0];
    cubies[6][3] = newCubies[0][0];

    //Blue->White
    cubies[2][0] = newCubies[8][5];
    cubies[1][0] = newCubies[5][5];
    cubies[0][0] = newCubies[2][5];

    //Yellow->Blue
    cubies[2][5] = newCubies[8][1];
    cubies[5][5] = newCubies[7][1];
    cubies[8][5] = newCubies[6][1];

    //Rotate Red
    cubies[0][2] = newCubies[2][2];
    cubies[1][2] = newCubies[5][2];
    cubies[2][2] = newCubies[8][2];
    cubies[3][2] = newCubies[1][2];
    cubies[5][2] = newCubies[7][2];
    cubies[6][2] = newCubies[0][2];
    cubies[7][2] = newCubies[3][2];
    cubies[8][2] = newCubies[6][2];
}
void TMyCube::B_anticlockwise()
{
    int newCubies[9][6];
    for (int i=0;i<9;++i) {
        for (int j=0;j<6;++j) {
            newCubies[i][j] = cubies[i][j];
        }
    }

    //White->Blue
    cubies[6][5] = newCubies[8][0];
    cubies[3][5] = newCubies[7][0];
    cubies[0][5] = newCubies[6][0];

    //Green->White
    cubies[6][0] = newCubies[8][3];
    cubies[7][0] = newCubies[5][3];
    cubies[8][0] = newCubies[2][3];

    //Yellow->Green
    cubies[8][3] = newCubies[2][1];
    cubies[5][3] = newCubies[1][1];
    cubies[2][3] = newCubies[0][1];

    //Blue->Yellow
    cubies[0][1] = newCubies[6][5];
    cubies[1][1] = newCubies[3][5];
    cubies[2][1] = newCubies[0][5];

    //Rotate Orange
    cubies[0][4] = newCubies[2][4];
    cubies[1][4] = newCubies[5][4];
    cubies[2][4] = newCubies[8][4];
    cubies[3][4] = newCubies[1][4];
    cubies[5][4] = newCubies[7][4];
    cubies[6][4] = newCubies[0][4];
    cubies[7][4] = newCubies[3][4];
    cubies[8][4] = newCubies[6][4];
}
