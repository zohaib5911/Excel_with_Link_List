#include <iostream>
#include <string>
#include "spreadSheet.h"
using namespace std;

int main(){

    SpreadSheet<int> obj(5,5);
    cout<<obj;

    cout<<"\nSet value\n";
    obj.setValue(3,3,33);
    cout<<obj;

    cout<<"\nGet value : \n";
    cout <<"Value at 3 ,3  : "<<obj.getValue(3,3)<<endl;
    return 0;
}