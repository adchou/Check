#ifndef CHECKBOOK
#define CHECKBOOK
#include<fstream>
#include<iostream>
#include<string>
#include "check.h"

class CheckBook{

    public:
        static const int CAPACITY = 200;
        CheckBook(); 
        void deposit(double dep);
        void show_all(std::ostream& outs)const;
        void load_from_file(std::istream& ins);

        int get_used() { return used;}

        Check get_check(int i); 

    private:

        Check data[CAPACITY];
        int used;
        double balance;

};







#endif