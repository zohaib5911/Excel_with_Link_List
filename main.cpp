#include <iostream>
#include <cstdlib>
#include "spreadSheet.h"
using namespace std;

int main(){

    int row,col;
    cout<<"Enter Number of Rows : ";
    cin >> row;
    cout<<"Enter Number of Columns : ";
    cin >> col;
    SpreadSheet<int> obj(row,col);
    int choice;

    do {
        system("cls");  

        cout << "\n=========== Mini Excel ===========" << endl;
        cout << "1. Display Sheet" << endl;
        cout << "2. Set Cell Value" << endl;
        cout << "3. Set Cell Formula (A1=A2+A3)" << endl;
        cout << "4. Add Row" << endl;
        cout << "5. Add Column" << endl;
        cout << "6. Empty Row" << endl;
        cout << "7. Empty Column" << endl;
        cout << "8. Row Max" << endl;
        cout << "9. Row Min" << endl;
        cout << "10. Column Max" << endl;
        cout << "11. Column Min" << endl;
        cout << "12. Insert Row with Values" << endl;
        cout << "13. Insert Column with Values" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << obj;
                break;
            case 2: {
                int r, c, val;
                cout << "Enter row, col, value: ";
                cin >> r >> c >> val;
                obj.setCell(r, c, val);
                cout << obj;
                break;
            }
            case 3:
                cin.ignore();
                obj.setCell();
                cout << obj;
                break;
            case 4:
                obj.addRow();
                cout << obj;
                break;
            case 5:
                obj.addColumn();
                cout << obj;
                break;
            case 6: {
                int r;
                cout << "Enter row to empty: ";
                cin >> r;
                obj.emptyRow(r);
                cout << obj;
                break;
            }
            case 7: {
                int c;
                cout << "Enter column to empty: ";
                cin >> c;
                obj.emptycol(c);
                cout << obj;
                break;
            }
            case 8: {
                int r;
                cout << "Enter row: ";
                cin >> r;
                cout << "Max: " << obj.rowMax(r) << endl;
                break;
            }
            case 9: {
                int r;
                cout << "Enter row: ";
                cin >> r;
                cout << "Min: " << obj.rowMin(r) << endl;
                break;
            }
            case 10: {
                int c;
                cout << "Enter column: ";
                cin >> c;
                cout << "Max: " << obj.colMax(c) << endl;
                break;
            }
            case 11: {
                int c;
                cout << "Enter column: ";
                cin >> c;
                cout << "Min: " << obj.colMin(c) << endl;
                break;
            }
            case 12: {
                int r;
                cout << "Enter row number to insert values into: ";
                cin >> r;
                obj.insertRow(r);
                cout << obj;
                break;
            }
            case 13: {
                int c;
                cout << "Enter column number to insert values into: ";
                cin >> c;
                obj.insertCol(c);
                cout << obj;
                break;
            }
        }

        if (choice != 0) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }

    } while (choice != 0);



    return 0;
}