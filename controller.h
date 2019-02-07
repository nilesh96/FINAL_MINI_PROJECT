/*************Start*******************************
 * Author : Nilesh kumar
 * File   : controller.h
 * Date   : 04/02/2019
**************************************************/

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include<iostream>
#include<string.h>
class CMainController
{
        float m_fTemperature;
	char m_Change_State;
	std :: string m_strAc_state;
  public:
	CMainController() = default;
	CMainController( std :: string ) ;
	CMainController( float,char );
        void Controller_Acwrite( void );
	void Controller_Tempwrite( void );
	  
};
#endif//__CONTROLLER_H__
