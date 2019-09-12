#include "checkbook.h"
#include<iostream>
#include<string>

using namespace std;

CheckBook::CheckBook()
{
    used = 0;
    balance = 0;
}
void CheckBook::load_from_file(istream& ins)
{
    
    while(!ins.eof() && used < CAPACITY)
    {
        ins >> data[used];

        used++;
    }
}
void CheckBook::deposit(double dep)
{
    balance += dep;
}
void CheckBook::show_all(ostream& outs)const{
	if(used == 0)
    {
	    cout<<"Empty list.\n";
    }
	else
    {
	    for(size_t i = 0; i<used; ++i)
        {
		    outs<<data[i]<<endl;
        }
}
}

Check CheckBook::get_check(int i) {
    return data[i]; 
}