#include "checkbook.h"
#include "check.h"
#include<iostream>
#include <cctype>
#include<string>

using namespace std;

Checkbook::Checkbook()
{
    //default variables from CheckBook class to 0
    used = 0;
    balance = 0;
}
void Checkbook::load_from_file(istream& ins)
{

    //reading the the file until the end of file or when capacity has been reached
    while(!ins.eof() && used < CAPACITY)
    {
        //load into the arrary at the number used is currently at
        ins >> data[used];

        //increment used
        used++;
    }
}
void Checkbook::deposit(double dep)
{
    //set balance by adding deposit amount to orignal balance
    balance += dep;
}
void Checkbook::show_all(ostream& outs)const{
    //checking for empty list
	if(used == 0)
    {
	    cout<<"Empty list.\n";
    }
	else
    {
        //if list isnt empty output the entire list
	    for(size_t i = 0; i<used; ++i)
        {
		    outs<<data[i]<<endl;
        }
}
}
void Checkbook::number_sort()
{
    //declare a unsigned num to hold i(count)
    size_t num;
    //loop through the array
    for(int i = 0 ; i < used; i++)
    {
        num = i;
        //declare variable j and set equal to i
        for(int j = i; j < used; j++)
        {
            //checking to see if next number is less
            if(data[j].get_num() < data[i].get_num())
            {
                //set it equal to num if it is
                num = j;
            }

        }
        //swap the two elements
        swap(data[i], data[num]);
    }
}
void Checkbook::payto_sort()
{
    //declare a unsigned num to hold i(count)
    size_t num;
    //loop through the array
    for(int i = 0 ; i < used; i++)
    {
        num = i;
        //declare variable j and set equal to i
        for(int j = i; j < used; j++)
        {
            //checking to see if next number is less
            if(data[j].get_payto() < data[i].get_payto())
            {
                //set it equal to num if it is
                num = j;
            }

        }
        //swap the two elements
        swap(data[i], data[num]);
    }
}
void Checkbook::date_sort()
{
     //declare a unsigned num to hold i(count)
    size_t num;
    //loop through the array
    for(int i = 0 ; i < used; i++)
    {
        num = i;
        //declare variable j and set equal to i
        for(int j = i; j < used; j++)
        {
            //checking to see if next number is less
            if(data[j].get_date() < data[i].get_date())
            {
                 //set it equal to num if it is
                num = j;
            }

        }
         //swap the two elements
        swap(data[i], data[num]);
    }
}
void Checkbook::remove(int checknum)
{
    //loop through the array
    for(int i = 0; i < used; i++)
    {
        //based on the get num function checking to see if the array is holding it already
        if(data[i].get_num() == checknum)
        {
            //remove the element at the specified location
            //balance -= data[i].get_amount();
            data[i] = data[used - 1];
            //decrease used(count)
            used--;
        }
    }
}
double Checkbook::average()
{
    //declare two variables to hold average and sum
    double average;
    double sum;
    for(int i = 0; i < used; i++)
    {
        sum += data[i].get_amount();
    }
    average = sum / used;
    return average;
}
void Checkbook::show(string payee)
{
    string payto;
    cout << "Enter the payee to view" << endl;
    cin >> payto;
    for(int i = 0; i < used; i++)
    {
        if(payto == data[i].get_payto())
        {
            cout << data[i] << endl;
        }
    }
}
void Checkbook::save(std::ostream& outs)
{
    
}
Check Checkbook::get_check(int i) {
    return data[i]; 
}