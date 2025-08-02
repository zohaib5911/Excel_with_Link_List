#ifndef SPREADSHEAT_H
#define SPREADSHEAT_H
#include <iostream>
#include <string>
#include "cell.h"

using namespace std;

template <typename T>
class SpreadSheet{
    int rows,columns;
    Cell<T>* head;
public:
    SpreadSheet(int r,int col):rows(r),columns(col),head(nullptr){
       if(rows == 0 || columns == 0) return;
       Cell<T>*** grid = new Cell<T>**[rows];
       for(int i=0;i<rows;i++){
        grid[i] = new Cell<T>* [columns];
            for(int j=0;j<columns;j++){
                grid[i][j] = new Cell<T>(0,i,j);
            }
       }
       for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (j + 1 < columns)
                    grid[i][j]->right = grid[i][j + 1];
                if (i + 1 < rows)
                    grid[i][j]->down = grid[i + 1][j];
            }
        }
         head = grid[0][0];
    }

    friend ostream& operator<<(ostream& os, const SpreadSheet& obj) {
    Cell<T>* row_ptr = obj.head;
    while (row_ptr != nullptr) {
        Cell<T>* col_ptr = row_ptr;
        while (col_ptr != nullptr) {
            os << col_ptr->value << "\t"; 
            col_ptr = col_ptr->right;
        }
        os << endl;
        row_ptr = row_ptr->down;
    }
    return os;
}


};

#endif