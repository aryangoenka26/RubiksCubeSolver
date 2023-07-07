//
// Created by Aryan Goenka
//
#include "CornerDBMaker.h"
#include<queue>
using namespace std;

CornerDBMaker::CornerDBMaker(string _fileName) {
    fileName = _fileName;
}

CornerDBMaker::CornerDBMaker(string _fileName, uint8_t init_val) {
    fileName = _fileName;
    cornerDB = CornerPatternDatabase(init_val);
}

bool CornerDBMaker::bfsAndStore() {
    RubiksCubeBitboard cube;
    queue<RubiksCubeBitboard> q;
    q.push(cube);
    cornerDB.setNumMoves(cube, 0);
    int curr_depth = 0;
    int max_depth = 9;  // Set the maximum depth for the BFS
    while (!q.empty() && curr_depth < max_depth) {
        int n = q.size();
        curr_depth++;
        for (int counter = 0; counter < n; counter++) {
            RubiksCubeBitboard node = q.front();
            q.pop();
            for (int i = 0; i < 18; i++) {
                auto curr_move = GenericRubiksCube::MOVE(i);
                RubiksCubeBitboard new_node = node;  // Create a copy of the node
                new_node.move(curr_move);
                if ((int) cornerDB.getNumMoves(new_node) > curr_depth) {
                    cornerDB.setNumMoves(new_node, curr_depth);
                    q.push(new_node);
                }
            }
        }
    }

    cornerDB.toFile(fileName);
    return true;
}
