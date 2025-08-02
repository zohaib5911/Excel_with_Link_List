#ifndef CELL_H
#define CELL_H
#include <iostream>

using namespace std;

template <typename T>
class Cell{
public:
    T value; // stores value 
    int row;    
    int column;
    Cell* right;
    Cell* down;
    Cell():right(nullptr),down(nullptr){}    
    Cell(T val ,int r = 0 ,int c = 0): value(val),row(r),column(c),right(nullptr),down(nullptr){}
};
#endif