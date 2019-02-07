/*************Start*******************************
 * Author : Nilesh kumar
 * File   : acmoniter.cpp
 * Date   : 01/02/2019
*************End**********************************/

#include"acmoniter.h"
#include"controller.h"
#include<iostream>
#include<pthread.h>
#include<string>
using namespace std;

/*paramitrized constructor to initialize the client id */
CAcmoniter::CAcmoniter(int nTemp)
{
    m_nId = nTemp;
}
/*function for the checking the status of AC  */ 
void CAcmoniter:: Moniter_Check()
{
    string str;
    if(m_szState=='c' || m_szState == 'C')
	{
	  if(m_fValue > 40)
	      str = "warm";
	  else if(m_fValue >=20 && m_fValue <=40)
	      str = "Medium";
	  else
	      str="cool";
	} 
    else if(m_szState == 'f' || m_szState == 'F')
	{
	  if(m_fValue >104)
		str= "warm";
	  else if(m_fValue >= 68 && m_fValue <= 104  ) 
		str="medium";
	  else
		str = "cool";
	}
    else 
	{
		cout << "state is invalid " << endl;
	}

    CMainController objController(str);
    objController.Controller_Acwrite();
}	

/*Thread function  */
void * CAcmoniter::Moniter_Thread( void *p )
{
    CAcmoniter *ptr = static_cast< CAcmoniter * > (p);
    ptr->Moniter_Check();
    return nullptr;
}

void CAcmoniter:: Moniter_Update(float temp , char state)
{
    cout << "In acmoniter class client m_nId =" << m_nId << endl;
    cout <<temp <<" "<< state << endl; 
    m_fValue = temp;
    m_szState = state;
    pthread_t th;
    pthread_create( &th , NULL , Moniter_Thread , (void *)this);
    pthread_join( th , NULL );

}
