#include"tempmoniter.h"
#include"controller.h"
#include<iostream>
#include<pthread.h>
#include<vector>
#include<algorithm>
using namespace std;
/*Paramitrized constructor and initialize the nId*/
CTempmoniter:: CTempmoniter(int temp_nId)
{
	nId = temp_nId;
}

CTempmoniter:: CTempmoniter(float val,char ch,int temp_nId)
{       m_fValue = val;
	m_szState = ch; 
	nId = temp_nId;
}
/* Moniter_Converting the data from c to f and f to c*/
float CTempmoniter :: Moniter_Convert()
{
	if(m_szState =='c'||m_szState == 'C')
	{
		m_fValue = (m_fValue * 1.8) + 32;
		m_szState = 'f';
	}
	else if(m_szState == 'f' || m_szState == 'F')
	{
		m_fValue =((m_fValue-32) / 1.8 );
		m_szState = 'c';
	}
	else
	{
		cout << "state is invalnId" << endl;
	}

         CMainController objController( m_fValue, m_szState );
	 objController.Controller_Tempwrite();
	 return m_fValue;
	
}
/* Thread function that is joined from the Moniter_Update function*/
void*  CTempmoniter::Thread(void *p)
{
	CTempmoniter *ptr = static_cast< CTempmoniter *> (p);
	//cout << "in temperature thread function " <<endl;
	ptr->Moniter_Convert();
	return nullptr;
}
/* override function defination and data is Moniter_Updated from the Ctempsensor class */
void CTempmoniter::Moniter_Update(float temp,char state)
{
	m_fValue = temp;
	m_szState = state;
	cout << "tempmoniter class client nId= " << nId<< endl;
	cout << temp << " " << state << endl;
	pthread_t th;
	pthread_create(&th,NULL,Thread,(void *)this);
	pthread_join(th,NULL);
}
