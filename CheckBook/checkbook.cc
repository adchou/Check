#include "checkbook.h"
#include<iostream>
#include <cctype>
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
void CheckBook::number_sort()
{
    size_t num;
    for(int i = 0 ; i < used; i++)
    {
        num = i;
        for(int j = i; j < used; j++)
        {
            if(data[j].get_num() < data[i].get_num())
            {
                num = j;
            }

        }
        swap(data[i], data[num]);
    }
}
void CheckBook::alpha_sort()
{
    size_t num;
    for(int i = 0 ; i < used; i++)
    {
        num = i;
        for(int j = i; j < used; j++)
        {
            if(data[j].get_payto() < data[i].get_payto())
            {
                num = j;
            }

        }
        swap(data[i], data[num]);
    }
}
void CheckBook::date_sort()
{
    size_t num;
    for(int i = 0 ; i < used; i++)
    {
        num = i;
        for(int j = i; j < used; j++)
        {
            if(data[j].get_date() < data[i].get_date())
            {
                num = j;
            }

        }
        swap(data[i], data[num]);
    }
}
void CheckBook::remove(int checknum)
{
    for(int i = 0; i < used; i++)
    {
        if(data[i].get_num() == checknum)
        {
            //balance -= data[i].get_amount();
            data[i] = data[used - 1];
            used--;
        }
    }
}
void CheckBook::average()
{
    double average;
    double sum;
    for(int i = 0; i < used; i++)
    {
        sum += data[i].get_amount();
    }
    average = sum / used;
}
Check CheckBook::get_check(int i) {
    return data[i]; 
}