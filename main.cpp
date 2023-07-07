
#include <iostream>
using namespace std;
#include "GenericRubiksCube.cpp"
#include "RubiksCube3dArray.cpp"
#include "RubiksCube1dArray.cpp"
#include "DFSSolver.h"
#include "BFSSolver.h"
#include "IDDFS.h"
#include "IDAstarSolver.h"

#include "PatternDataBase/CornerPatternDataBase.cpp"
#include "PatternDataBase/CornerDBMaker.cpp"
#include "PatternDataBase/PatternDataBase.cpp"
#include "PatternDataBase/NibbleArray.cpp"

int main() {
// Representation testing
    // RubiksCube3dArray obj3Darray;
    // obj3Darray.print();

    // RubiksCube1dArray obj1dArray;
    // RubiksCubeBitboard objBitboard;
    // RubiksCube3dArray cube1;
    // RubiksCube3dArray cube2;

    // cube2.l();

    // if(cube1==cube2)
    //     cout<<"Cube are same"<<endl;
    // else
    //     cout<<"Cube are not same"<<endl;
    // RubiksCubeBitboard cube1;
    // RubiksCubeBitboard cube2;
    // if(cube1 == cube2) cout << "Is equal\n";
    // else cout << "Not Equal\n";

    // cube1.randomShuffleCube(1);

    // if(cube1 == cube2) cout << "Is equal\n";
    // else cout << "Not Equal\n";

    // cube2 = cube1;

    // if(cube1 == cube2) cout << "Is equal\n";
    // else cout << "Not Equal\n";

// DFS Solver
    // RubiksCube3dArray cube;
    // cube.print();

    // // shuffle 6 times
    // vector<GenericRubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
    // cout << "Shuffling moves are: " << endl;
    // for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    // cout << endl;

    // cout << "SHUFFLED CUBE:" << endl;
    // cube.print();

    // // passing max depth as 8 to dfs solver
    // DFSSolver<RubiksCube3dArray, Hash3d> dfsSolver(cube, 8);
    // vector<GenericRubiksCube::MOVE> solve_moves = dfsSolver.solve();

    // cout << "Moves to solve the cube are:" << endl;
    // for (auto move: solve_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // dfsSolver.rubiksCube.print();

    
// BFS Solver
    // RubiksCubeBitboard cube;
    // cube.print();

    // // shuffle 6 times
    // vector<GenericRubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
    // cout << "Shuffling moves are: " << endl;
    // for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    // cout << endl;

    // cout << "SHUFFLED CUBE:" << endl;
    // cube.print();

    // // passing max depth as 8 to dfs solver
    // BFSSolver<RubiksCubeBitboard, HashBitboard> bfsSolver(cube);
    // vector<GenericRubiksCube::MOVE> solve_moves = bfsSolver.solve();

    // cout << "Moves to solve the cube are:" << endl;
    // for (auto move: solve_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    // bfsSolver.rubiksCube.print();
//

// IDDFS Solver
    RubiksCube3dArray cube;
    cube.print();

    // shuffle 6 times
    vector<GenericRubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(6);
    cout << "Shuffling moves are: " << endl;
    for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    cout << endl;

    cout << "SHUFFLED CUBE:" << endl;
    cube.print();

    // passing max depth as 8 to dfs solver
    IDDFSSolver<RubiksCube3dArray, Hash3d> iddfsSolver(cube, 8);
    vector<GenericRubiksCube::MOVE> solve_moves = iddfsSolver.solve();

    cout << "Moves to solve the cube are:" << endl;
    for (auto move: solve_moves) cout << cube.getMove(move) << " ";
    cout << "\n";
    iddfsSolver.rubiksCube.print();

// IDA*
    // RubiksCube3dArray cube;
    // cube.print();

    // vector<GenericRubiksCube::MOVE> shuffle_moves = cube.randomShuffleCube(5);
    // cout << "Shuffling moves are: " << endl;
    // for (auto move: shuffle_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    
    // cout<<"This is shuffled Rubiks Cube"<<endl;
    // cube.print();

    // cout<<"Now lets solve the cube by IDAstar algorithm"<<endl;
    // IDAstarSolver<RubiksCube3dArray, Hash3d> IDAstarSolver(cube,"DataBase/CornerDepth5V1.txt");
    
    // vector<GenericRubiksCube::MOVE> solve_moves = IDAstarSolver.solve();
    // for (auto move: solve_moves) cout << cube.getMove(move) << " ";
    // cout << "\n";
    
    // IDAstarSolver.rubiksCube.print();
}