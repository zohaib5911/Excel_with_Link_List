#include <iostream>
#include <string>
#include "spreadSheet.h"
using namespace std;

int main(){

    SpreadSheet<int> obj(5,5);
    // cout<<obj;

    // cout<<"\nSet value\n";
    obj.setValue(3,3,33);
    obj.setValue(4,4,44);
    // cout<<obj;

    // cout<<"\nGet value : \n";
    // cout <<"Value at 3 ,3  : "<<obj.getValue(3,3)<<endl;

    // obj.insertRow(0);

    obj.setValue(1,1,3,3,4,4);

    // obj.setValue("a0","d3","e4");
    cout<<endl<<obj<<endl;
    obj.setValue(3,3,0);
    cout<<"\n--------------------\n";
    cout<<obj;
    return 0;
}