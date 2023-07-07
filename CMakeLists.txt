cmake_minimum_required(VERSION 3.25)
project(RubiksCubeSolver)

set(CMAKE_CXX_STANDARD 17)

add_executable(RubiksCubeSolver main.cpp GenericRubiksCube.cpp GenericRubiksCube.h RubiksCube3dArray.cpp RubiksCube1dArray.cpp RubiksCubeBitboard.cpp DFSSolver.h BFSSolver.h IDDFS.h IDAstarSolver.h PatternDataBase/NibbleArray.h PatternDataBase/NibbleArray.cpp PatternDataBase/PatternDataBase.h PatternDataBase/PatternDataBase.cpp PatternDataBase/CornerPatternDataBase.h PatternDataBase/CornerPatternDataBase.cpp PatternDataBase/PermutationIndexer.h PatternDataBase/math.h PatternDataBase/math.cpp PatternDataBase/CornerDBMaker.h PatternDataBase/CornerDBMaker.cpp)
