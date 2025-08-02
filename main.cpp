#include <iostream>
#include <string>
#include "spreadSheet.h"
using namespace std;

int main(){

    SpreadSheet<int> obj(5,5);
    cout<<obj;


    return 0;
}