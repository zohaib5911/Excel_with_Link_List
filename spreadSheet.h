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
    Cell<T>* getCell(int row,int col){
        Cell<T>* temp = head;
        for(int i=0;i<row;i++)  temp = temp->down;
        for(int i=0;i<col;i++)  temp = temp->right;
        return temp;
    }
    void setValue(string target,string t1,string t2){
        int row_1 =  target[0] - 'a';
        int col_1 = target[1] - '0';
        int row_2 = t1[0] - 'a';
        int col_2 = t1[1] - '0';
        int row_3 = t2[0] - 'a';
        int col_3 = t2[1] - '0';
        cout<<row_1<<" _ "<<col_1;
        setValue(row_1,col_1,row_2,col_2,row_3,col_3);
    }    
    void setValue(int row_1,int col_1,int row_2,int col_2,int row_3,int col_3){
        Cell<T>* r = getCell(row_1,col_1);
        Cell<T>* t1 = getCell(row_2,col_2);
        Cell<T>* t2 = getCell(row_3,col_3);
        if(r && t1 && t2){
            char op;
            cout<<"Enter sign (*,/,+,-) : ";
            cin>>op;
            switch (op)
            {
            case '+' : r->value = t1->value + t2->value;    break;
            case '-' : r->value = t1->value - t2->value;    break;
            case '*' : r->value = t1->value * t2->value;    break;
            case '/' : 
                if(t2->value == 0){
                    cout<<"Error Divide is not possible\n";
                }
                r->value = t1->value / t2->value;
                break;
            default:
                cout << "Invalid operator entered.\n";
            }
        }
    }
    void setValue(int row, int col, T value) {
        Cell<T>* temp = head;
        for (int i = 0; i < row && temp; ++i) {
            temp = temp->down;
        }
        for (int j = 0; j < col && temp; ++j) {
            temp = temp->right;
        }
        if (temp) {
            temp->value = value;
        }
    }

    T getValue(int row,int col){
        Cell<T> * temp = head;
        for(int i = 0; i < row; i++){
            temp = temp->down;
        }
        for(int j = 0; j < col; j++){
            temp = temp->right;
        }
        if(temp){
            return temp->value;
        }
        else {
            return T{};
        }
    }

    void insertRow(int r){
        for(int i=0;i<columns;i++){
            T val;
            cout<<"Enter Value at ["<<r<<"]["<<i<<"]"<<" : ";
            cin>>val;
            setValue(r,i,val);
        }
    }

    void insertCol(int col){
        for(int i=0;i<rows;i++){
            T val;
            cout<<"Enter Value at ["<<i<<"]["<<col<<"]"<<" : ";
            cin>>val;
            setValue(i,col,val);
        }
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
    ~SpreadSheet() {
        Cell<T>* row_ptr = head;
        while (row_ptr) {
            Cell<T>* col_ptr = row_ptr;
            row_ptr = row_ptr->down;
            while (col_ptr) {
                Cell<T>* next_col = col_ptr->right;
                delete col_ptr;
                col_ptr = next_col;
            }
        }
    }

};

#endif