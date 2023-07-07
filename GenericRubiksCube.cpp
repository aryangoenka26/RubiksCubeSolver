//
// Created by Aryan Goenka
//

#include "GenericRubiksCube.h"
#include <vector>
#include <algorithm>
#include <time.h>
using namespace std;
//
//Given a color return it's first letter
//

 char GenericRubiksCube::getColorLetter(GenericRubiksCube::COLOR color) {
     if (color == COLOR::BLUE) {
         return 'B';
     } else if (color == COLOR::GREEN) {
         return 'G';
     } else if (color == COLOR::RED) {
         return 'R';
     } else if (color == COLOR::YELLOW) {
         return 'Y';
     } else if (color == COLOR::WHITE) {
         return 'W';
     } else{        // last remaining color option is orange
         return 'O';
     }
}
string GenericRubiksCube::getMove(GenericRubiksCube::MOVE ind) {
    if (ind == MOVE::L) {
        return "L";
    } else if (ind == MOVE::LPRIME) {
        return "L'";
    } else if (ind == MOVE::L2) {
        return "L2";
    } else if (ind == MOVE::R) {
        return "R";
    } else if (ind == MOVE::RPRIME) {
        return "R'";
    } else if (ind == MOVE::R2) {
        return "R2";
    } else if (ind == MOVE::U) {
        return "U";
    } else if (ind == MOVE::UPRIME) {
        return "U'";
    } else if (ind == MOVE::U2) {
        return "U2";
    } else if (ind == MOVE::D) {
        return "D";
    } else if (ind == MOVE::DPRIME) {
        return "D'";
    } else if (ind == MOVE::D2) {
        return "D2";
    } else if (ind == MOVE::F) {
        return "F";
    } else if (ind == MOVE::FPRIME) {
        return "F'";
    } else if (ind == MOVE::F2) {
        return "F2";
    } else if (ind == MOVE::B) {
        return "B";
    } else if (ind == MOVE::BPRIME) {
        return "B'";
    } else{     // only remaining option B2
        return "B2";
    }
}
/*
 * Perform a move operation on using a Move index.
 */
GenericRubiksCube &GenericRubiksCube::move(GenericRubiksCube::MOVE ind) {
    if (ind == MOVE::L) {
        return this->l();
    } else if (ind == MOVE::LPRIME) {
        return this->lPrime();
    } else if (ind == MOVE::L2) {
        return this->l2();
    } else if (ind == MOVE::R) {
        return this->r();
    } else if (ind == MOVE::RPRIME) {
        return this->rPrime();
    } else if (ind == MOVE::R2) {
        return this->r2();
    } else if (ind == MOVE::U) {
        return this->u();
    } else if (ind == MOVE::UPRIME) {
        return this->uPrime();
    } else if (ind == MOVE::U2) {
        return this->u2();
    } else if (ind == MOVE::D) {
        return this->d();
    } else if (ind == MOVE::DPRIME) {
        return this->dPrime();
    } else if (ind == MOVE::D2) {
        return this->d2();
    } else if (ind == MOVE::F) {
        return this->f();
    } else if (ind == MOVE::FPRIME) {
        return this->fPrime();
    } else if (ind == MOVE::F2) {
        return this->f2();
    } else if (ind == MOVE::B) {
        return this->b();
    } else if (ind == MOVE::BPRIME) {
        return this->bPrime();
    } else{         // last one is b2
        return this->b2();
    }
}
/*
 * Invert a move.
 */
GenericRubiksCube &GenericRubiksCube::invert(GenericRubiksCube::MOVE ind) {
    if (ind == MOVE::L) {
        return this->lPrime();
    } else if (ind == MOVE::LPRIME) {
        return this->l();
    } else if (ind == MOVE::L2) {
        return this->l2();
    } else if (ind == MOVE::R) {
        return this->rPrime();
    } else if (ind == MOVE::RPRIME) {
        return this->r();
    } else if (ind == MOVE::R2) {
        return this->r2();
    } else if (ind == MOVE::U) {
        return this->uPrime();
    } else if (ind == MOVE::UPRIME) {
        return this->u();
    } else if (ind == MOVE::U2) {
        return this->u2();
    } else if (ind == MOVE::D) {
        return this->dPrime();
    } else if (ind == MOVE::DPRIME) {
        return this->d();
    } else if (ind == MOVE::D2) {
        return this->d2();
    } else if (ind == MOVE::F) {
        return this->fPrime();
    } else if (ind == MOVE::FPRIME) {
        return this->f();
    } else if (ind == MOVE::F2) {
        return this->f2();
    } else if (ind == MOVE::B) {
        return this->bPrime();
    } else if (ind == MOVE::BPRIME) {
        return this->b();
    } else{         // handled by b2 for case b2
        return this->b2();
    }
}
 void GenericRubiksCube::print() const {
     cout << "Rubik's Cube:\n\n";

     for (int row = 0; row <= 2; row++) {
         for (unsigned i = 0; i < 7; i++) cout << " ";
         for (int col = 0; col <= 2; col++) {
             cout << getColorLetter(getColor(FACE::UP, row, col)) << " ";
         }
         cout << "\n";
     }
     cout<<"\n";

     for (int row = 0; row <= 2; row++) {

         for (int col = 0; col <= 2; col++) {
             cout << getColorLetter(getColor(FACE::LEFT, row, col)) << " ";
         }
         cout << " ";

         for (int col = 0; col <= 2; col++) {
             cout << getColorLetter(getColor(FACE::FRONT, row, col)) << " ";
         }
         cout << " ";

         for (int col = 0; col <= 2; col++) {
             cout << getColorLetter(getColor(FACE::RIGHT, row, col)) << " ";
         }
         cout << " ";

         for (int col = 0; col <= 2; col++) {
             cout << getColorLetter(getColor(FACE::BACK, row, col)) << " ";
         }
         cout << "\n";
     }

     cout << "\n";

     for (int row = 0; row <= 2; row++) {
         for (unsigned i = 0; i < 7; i++) cout << " ";
         for (int col = 0; col <= 2; col++) {
             cout << getColorLetter(getColor(FACE::DOWN, row, col)) << " ";
         }
         cout << "\n";
     }
     cout << "\n";
 }

// performs random moves on the rubiksCube and returns a vector containing the moves performed
 vector<GenericRubiksCube::MOVE> GenericRubiksCube::randomShuffleCube(unsigned int times) {
    vector<MOVE> moves_performed;
    srand(time(0));
    for (unsigned int i = 0; i < times; i++) {
        unsigned int selectMove = (rand() % 18);
        moves_performed.push_back(static_cast<MOVE>(selectMove));
        this->move(static_cast<MOVE>(selectMove));
    }
    return moves_performed;
}

string GenericRubiksCube::getCornerColorString(uint8_t ind) const {
    string str="";
    switch (ind) {
//        UFR
        case 0:
            str += getColorLetter(getColor(FACE::UP, 2, 2));
            str += getColorLetter(getColor(FACE::FRONT, 0, 2));
            str += getColorLetter(getColor(FACE::RIGHT, 0, 0));
            break;

//            UFL
        case 1:
            str += getColorLetter(getColor(FACE::UP, 2, 0));
            str += getColorLetter(getColor(FACE::FRONT, 0, 0));
            str += getColorLetter(getColor(FACE::LEFT, 0, 2));
            break;

//            UBL
        case 2:
            str += getColorLetter(getColor(FACE::UP, 0, 0));
            str += getColorLetter(getColor(FACE::BACK, 0, 2));
            str += getColorLetter(getColor(FACE::LEFT, 0, 0));
            break;

//            UBR
        case 3:
            str += getColorLetter(getColor(FACE::UP, 0, 2));
            str += getColorLetter(getColor(FACE::BACK, 0, 0));
            str += getColorLetter(getColor(FACE::RIGHT, 0, 2));
            break;

//            DFR
        case 4:
            str += getColorLetter(getColor(FACE::DOWN, 0, 2));
            str += getColorLetter(getColor(FACE::FRONT, 2, 2));
            str += getColorLetter(getColor(FACE::RIGHT, 2, 0));
            break;

//            DFL
        case 5:
            str += getColorLetter(getColor(FACE::DOWN, 0, 0));
            str += getColorLetter(getColor(FACE::FRONT, 2, 0));
            str += getColorLetter(getColor(FACE::LEFT, 2, 2));
            break;

//            DBR
        case 6:
            str += getColorLetter(getColor(FACE::DOWN, 2, 2));
            str += getColorLetter(getColor(FACE::BACK, 2, 0));
            str += getColorLetter(getColor(FACE::RIGHT, 2, 2));
            break;

//            DBL
        case 7:
            str += getColorLetter(getColor(FACE::DOWN, 2, 0));
            str += getColorLetter(getColor(FACE::BACK, 2, 2));
            str += getColorLetter(getColor(FACE::LEFT, 2, 0));
            break;
    }
    return str;
}

uint8_t GenericRubiksCube::getCornerIndex(uint8_t ind) const {
    string corner = getCornerColorString(ind);

    uint8_t ret = 0;
    for (auto c: corner) {
        if (c != 'W' && c != 'Y') continue;
        if (c == 'Y') {
            ret |= (1 << 2);
        }
    }

    for (auto c: corner) {
        if (c != 'R' && c != 'O') continue;
        if (c == 'O') {
            ret |= (1 << 1);
        }
    }

    for (auto c: corner) {
        if (c != 'B' && c != 'G') continue;
        if (c == 'G') {
            ret |= (1 << 0);
        }
    }
    return ret;
}

uint8_t GenericRubiksCube::getCornerOrientation(uint8_t ind) const {
    string corner = getCornerColorString(ind);

    string actual_str = "";

    for (auto c: corner) {
        if (c != 'W' && c != 'Y') continue;
        actual_str.push_back(c);
    }

    if (corner[1] == actual_str[0]) {
        return 1;
    } else if (corner[2] == actual_str[0]) {
        return 2;
    } else return 0;
}
