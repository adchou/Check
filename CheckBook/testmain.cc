#include "checkbook.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
    CheckBook checkS;
    
    ifstream ifs;
    ifs.open("test.txt");
    checkS.load_from_file(ifs);
    ifs.close();
    double m = 21.2;
    //checkS.deposit(m);
    checkS.average();
    
   checkS.show_all(cout);
}