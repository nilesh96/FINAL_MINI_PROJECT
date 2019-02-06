#ifndef tempmoniter_h
#define tempmoniter_h
#include"observer.h"
#include<vector>
#include<iostream>
#include<algorithm>
class CTempmoniter:public Iobserver
{
	float value;
	char temp_state;
	int id;
  public:
	  
     //vector<pair<float ,char>> v1;
        CTempmoniter() = default;       	
	CTempmoniter(int );
	void convert();
	static void* Thread(void *);
	void update(float,char)override;
		
        	
};
#endif
