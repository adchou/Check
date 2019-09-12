/*******************************************************************
    This is the implementation file for the Check class. For more 
information about the class see check.h.
    Students are expected to implement some of the functions shown 
below.
	John Dolan	Ohio University		September 2019
******************************************************************/
#include "check.h"
using namespace std;

    Check::Check(Date d, string p, int num,double amt){
	checknum = num;
	date = d;
	payto = p;
	amount = amt;
	}
    // Input and output functions
    void Check::write_check(std::istream& ins){
	/* You are to write the implementation of this function to read 
	from the keyboard or a file. Remember to use getline to read the 
	payto.  */


    	} 
    void Check::output(std::ostream& outs)const{
	/* You are to write the implementation of this function to write 
	to the monitor or to a file. Remember not to put labels into the 
	file.*/

	}
	void load_from_file(istream& ins, const Check& c)
	{
		double tempAmount;
		int checknum;
		Date date;
		string payto;
		while(ins.peek() == '\n' || ins.peek() == '\r')
		{
			ins.ignore();
		}
		while(!ins.eof())
		{
		ins >> tempAmount;
		ins >> checknum;
		ins >> date;
		ins >> payto;
		
		}    
	}
	
	int deposit(ostream& outs, const Check& c)
	{
		double currentBalance = c.get_amount();
		double depamount = c;
		double newBalance = currentBalance + depamount;
		

	}

ostream& operator << (ostream& outs, const Check& c){
        c.output(outs);
        return outs;
}

istream& operator >> (istream& ins, Check& c){
        c.write_check(ins);
        return ins;
}


