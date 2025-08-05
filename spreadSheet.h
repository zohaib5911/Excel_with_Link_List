#ifndef SPREADSHEAT_H
#define SPREADSHEAT_H
#include <iostream>
#include <string>
#include <vector>
#include <limits>   // to use numaric limits
#include "cell.h"

using namespace std;
template<typename T>
struct dependency;

template <typename T>
class SpreadSheet{
    int rows,columns;
    vector<dependency<T>> dependTracker;
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
        
    void addRow() {
        Cell<T>* lastRow = head;
        while (lastRow->down != nullptr) {
            lastRow = lastRow->down;
        }
        Cell<T>* newRowHead = new Cell<T>(0, rows, 0);
        Cell<T>* currentNew = newRowHead;

        for (int j = 1; j < columns; ++j) {
            Cell<T>* newCell = new Cell<T>(0, rows, j);
            currentNew->right = newCell;
            currentNew = newCell;
        }
        Cell<T>* above = lastRow;
        currentNew = newRowHead;

        while (above != nullptr && currentNew != nullptr) {
            above->down = currentNew;
            above = above->right;
            currentNew = currentNew->right;
        }
        rows++;
    }
    void addColumn() {
        Cell<T>* row = head;
        while (row != nullptr) {
            Cell<T>* colPtr = row;
            while (colPtr->right != nullptr) {
                colPtr = colPtr->right;
            }
            Cell<T>* newCell = new Cell<T>(0, colPtr->row, columns); 
            colPtr->right = newCell;
            row = row->down;
        }
        columns++;
    }

    void setCell() {
        string str;
        cout << "Enter in this format only : (A1=A2+A3): ";
        getline(cin, str);
        if (str.length() < 6 || str[2] != '=') {
            cout << "Invalid format!" << endl;
            return;
        }
        string resultCell = str.substr(0, 2);    // A1
        char op = str[5];                        // +, -, *, /
        string term1 = str.substr(3, 2);         // A2
        string term2 = str.substr(6, 2);         // A3
        strToRC(resultCell, term1, term2, op);  // Call your custom function
    }


    void setCell(int row, int col, T value) {
        Cell<T>* temp = head;
        for (int i = 0; i < row && temp; ++i) {
            temp = temp->down;
        }
        for (int j = 0; j < col && temp; ++j) {
            temp = temp->right;
        }
        if (temp) {
            temp->value = value;
            recalculate();
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
            setCell(r,i,val);
        }
    }

    void insertCol(int col){
        for(int i=0;i<rows;i++){
            T val;
            cout<<"Enter Value at ["<<i<<"]["<<col<<"]"<<" : ";
            cin>>val;
            setCell(i,col,val);
        }
    }
    T rowMax(int row){
        if(row>rows || head==nullptr){ return T(); }
        T m = numeric_limits<T>::min();;
        Cell<T>* temp = head;
        for(int i=0;i<row;i++) temp=temp->down;
        for(int i=0;i<columns;i++){
            m=max(temp->value,m);
            temp=temp->right;
        }
        return m;
    }

    T rowMin(int row){
        if(row>rows || head==nullptr){ return T(); }
        T m = numeric_limits<T>::max();
        Cell<T>* temp = head;
        for(int i=0;i<row;i++) temp=temp->down;
        for(int i=0;i<columns;i++){
            m=min(temp->value,m);
            temp=temp->right;
        }
        return m;
    }

    T colMax(int col){
        if(col>columns || head==nullptr){ return T(); }
        T m = numeric_limits<T>::min();
        Cell<T>* temp = head;
        for(int i=0;i<col;i++) temp=temp->right;
        for(int i=0;i<rows;i++){
            m=max(temp->value,m);
            temp=temp->down;
        }
        return m;
    }

    int colMin(int col){
        if(col>columns || head==nullptr){ return T(); }
        T m = numeric_limits<T>::max();
        Cell<T>* temp = head;
        for(int i=0;i<col;i++) temp=temp->right;
        for(int i=0;i<rows;i++){
            m=min(temp->value,m);
            temp=temp->down;
        }
        return m;
    }

    friend ostream& operator<<(ostream& os, const SpreadSheet& obj) {
        cout << "\n------- Spread Sheet -------\n";
        os << "\t";
        for (int col = 0; col < obj.columns; col++) {
            os << static_cast<char>('A' + col) << "\t";
        }
        os << endl;

        Cell<T>* row_ptr = obj.head;
        int row = 0;
        while (row_ptr != nullptr) {
            os << row << "\t";  
            Cell<T>* col_ptr = row_ptr;
            while (col_ptr != nullptr) {
                os << col_ptr->value << "\t";
                col_ptr = col_ptr->right;
            }
            os << endl;
            row_ptr = row_ptr->down;
            row++;
        }
    return os;
    }

    

    void emptyRow(int row){
        Cell<T>* temp = head;
        for(int i=0;i<row;i++) temp=temp->down;
        for(int i=0;i<columns;i++){
            temp->value=0;
            temp=temp->right;
        }
    }
    void emptycol(int col){
        Cell<T>* temp = head;
        for(int i=0;i<col;i++) temp=temp->right;
        for(int i=0;i<rows;i++){
            temp->value=0;
            temp=temp->down;
        }
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

private :

    Cell<T>* getCell(int row,int col){
        Cell<T>* temp = head;
        for(int i=0;i<row;i++)  temp = temp->down;
        for(int i=0;i<col;i++)  temp = temp->right;
        return temp;
    }
      
    void putValue(int row_1,int col_1,int row_2,int col_2,int row_3,int col_3,char op){
        Cell<T>* r = getCell(row_1,col_1);
        Cell<T>* t1 = getCell(row_2,col_2);
        Cell<T>* t2 = getCell(row_3,col_3);
        if(r && t1 && t2){
            dependTracker.push_back({r, t1, t2, op});
            signOperator(r,t1,t2,op);
            recalculate();
        }
    }

    void signOperator(Cell<T>* r,Cell<T>* t1,Cell<T>* t2,char op){
        switch (op)
            {
            case '+' : r->value = t1->value + t2->value;    break;
            case '-' : r->value = t1->value - t2->value;    break;
            case '*' : r->value = t1->value * t2->value;    break;
            case '/' : 
                if(t2->value == 0){
                    cout<<"Error Divide is not possible\n";
                    return;
                }
                else 
                    r->value = t1->value / t2->value;
                break;
            default:
                cout << "Invalid operator entered.\n";
            }
    }

    void strToRC(string target,string t1,string t2,char op){
        int col_1 =  target[0] - 'A';
        int row_1 = target[1] - '0';
        int col_2 = t1[0] - 'A';
        int row_2 = t1[1] - '0';
        int col_3 = t2[0] - 'A';
        int row_3 = t2[1] - '0';
        putValue(row_1,col_1,row_2,col_2,row_3,col_3,op);
    }   

    void recalculate(){
        for(auto& i : dependTracker){
             signOperator(i.r, i.t1, i.t2, i.op);
        }
    } 

};

template <typename T>
struct dependency{
    Cell<T>* r;
    Cell<T>* t1;
    Cell<T>* t2;
    char op;
};


#endif