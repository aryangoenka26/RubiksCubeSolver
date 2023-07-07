//
// Created by Aryan Goenka
//

#ifndef RUBIKSCUBESOLVER_CORNERPATTERNDATABASE_H
#define RUBIKSCUBESOLVER_CORNERPATTERNDATABASE_H
#include "../GenericRubiksCube.h"
#include "PatternDataBase.h"
#include "PermutationIndexer.h"
using namespace std;

class CornerPatternDatabase : public PatternDatabase {

    typedef GenericRubiksCube::FACE F;

    PermutationIndexer<8> permIndexer;

public:
    CornerPatternDatabase();
    CornerPatternDatabase(uint8_t init_val);
    uint32_t getDatabaseIndex(const GenericRubiksCube& cube) const;

};
#endif //RUBIKSCUBESOLVER_CORNERPATTERNDATABASE_H
