/*******************start*********************************************
 * Author - Nilesh kumar
 * File - tempsensor.h
 * Date - 04/02/2019
*********END**********************************************************/

#ifndef __TEMPSENSOR_H__
#define __TEMPSENSOR_H__

#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>
#include"subject.h"
#include"observer.h"
using namespace std;
class CTempSensor:public ISubject
{
   private:
     vector< IObserver * > m_observers;
     vector < pair<float ,char> > m_vect;
     float m_fTemp;
     char m_cState;
   public:
     int  Temp_Attach(IObserver *) override;
     void Temp_Detach(IObserver *) override;
     void Temp_Notify ( void ) override;
     void Temp_Get_Data(void);
     void Temp_Display_Data( void );
     void Temp_Set_Data( void );
};
#endif//__TEMPSENSOR_H__
