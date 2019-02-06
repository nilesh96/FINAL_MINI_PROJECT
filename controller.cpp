#include"controller.h"
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
Cmaincontroller::Cmaincontroller(string st)
{
	ac_state = st;
}
Cmaincontroller::Cmaincontroller(float temp,char state)
	{
		temperature = temp;
		change_state =state;
	}
void Cmaincontroller::Tempwrite(void)
{
	ofstream output("simulate.txt",ios::out |ios::app);
	output << "Temperature=" << temperature<< change_state<< "\t\t";
        output.close();
}
void Cmaincontroller::Acwrite(void)
{
	ofstream output("simulate.txt",ios::out |ios::app);
	output << "AC=" << ac_state <<"\n";
        output.close();
}

