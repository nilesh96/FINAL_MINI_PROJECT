/*************Start*******************************
 * Author : Nilesh kumar
 * File   : controller.cpp
 * Date   : 04/02/2019
**************************************************/

#include"controller.h"
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

/* Paramitrized constuctor for initialize the object to the string */
CMainController::CMainController(string strVal)
{
    m_strAc_state = strVal;
}

/* paramitrized constructor for initialize the object to the m_fTemperature and state */
CMainController::CMainController(float Temp,char State)
{
    m_fTemperature = Temp;
    m_Change_State = State;
}

/* Function for writing the data into file . Data is sending by the Tempmoniter class */
void CMainController::Controller_Tempwrite( void )
{
    ofstream output ("simulate.txt", ios::out | ios::app );
    output << "Temperature=" << m_fTemperature<< m_Change_State << "\t\t";
    output.close();
}

/* function for writing the Acmoniter class data inside the  file . */ 
void CMainController::Controller_Acwrite( void )
{
    ofstream output( "simulate.txt" , ios::out | ios::app );
    output << "AC=" << m_strAc_state << "\n";
    output.close();
}

