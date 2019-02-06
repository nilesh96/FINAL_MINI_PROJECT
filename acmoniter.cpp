#include"acmoniter.h"
#include"controller.h"
#include<iostream>
#include<pthread.h>
#include<string>
using namespace std;

CAcmoniter::CAcmoniter(int temp)
   {
   	   id = temp;
   }
   
void CAcmoniter:: check()
{
    string str;
    if(temp_state=='c' || temp_state == 'C')
	{
	  if(value > 40)
	      str = "warm";
	  else if(value >=20 && value <=40)
	      str = "Medium";
	  else
	      str="cool";
	} 
    else if(temp_state == 'f' || temp_state == 'F')
	{
	  if(value >104)
		str= "warm";
	  else if(value >= 68 && value <= 104  ) 
		str="medium";
	  else
		str = "cool";
	}
    else 
	{
		cout << "state is invalid " << endl;
	}

	Cmaincontroller objController(str);

	objController.Acwrite();
}	
void * CAcmoniter::Thread2(void *p)
{
	CAcmoniter *ptr = static_cast<CAcmoniter *> (p);
//	cout << "in ac moniter thread " << endl;
	ptr->check();
	return nullptr;
}
void CAcmoniter:: update(float temp , char state)
{
	cout << "In acmoniter class client id =" << id << endl;
	cout <<temp <<" "<< state << endl; 
	value = temp;
	temp_state = state;
//	cout << temp << " " << state << endl;
	pthread_t th;
	pthread_create( &th , NULL , Thread2 , (void *)this);
	pthread_join( th , NULL );

}
