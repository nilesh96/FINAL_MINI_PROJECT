#include"tempmoniter.h"
#include"controller.h"
#include<iostream>
#include<pthread.h>
#include<vector>
#include<algorithm>
using namespace std;
/*Paramitrized constructor and initialize the id*/
CTempmoniter:: CTempmoniter(int temp_id)
{
	id = temp_id;
}
/* converting the data from c to f and f to c*/
void CTempmoniter :: convert()
{
	if(temp_state =='c'||temp_state == 'C')
	{
		value = (value * 1.8) + 32;
		temp_state = 'f';
	}
	else if(temp_state == 'f' || temp_state == 'F')
	{
		value =((value-32) / 1.8 );
		temp_state = 'c';
	}
	else
	{
		cout << "state is invalid" << endl;
	}

         Cmaincontroller objController( value, temp_state );
	 objController.Tempwrite();
	
}
/* Thread function that is joined from the update function*/
void*  CTempmoniter::Thread(void *p)
{
	CTempmoniter *ptr = static_cast< CTempmoniter *> (p);
	//cout << "in temperature thread function " <<endl;
	ptr->convert();
	return nullptr;
}
/* override function defination and data is updated from the Ctempsensor class */
void CTempmoniter::update(float temp,char state)
{
	value = temp;
	temp_state = state;
	cout << "tempmoniter class client id= " << id<< endl;
	cout << temp << " " << state << endl;
	pthread_t th;
	pthread_create(&th,NULL,Thread,(void *)this);
	pthread_join(th,NULL);
}
