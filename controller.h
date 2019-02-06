#ifndef CONTROLLER_H
#define CONTROLLER_H
#include<iostream>
#include<string.h>
class Cmaincontroller
{
        float temperature;
	char change_state;
	std :: string ac_state;
  public:
	Cmaincontroller() = default;
	Cmaincontroller( std :: string);
	Cmaincontroller(float,char);
        void Acwrite(void);
	void Tempwrite(void);
	  
};
#endif
