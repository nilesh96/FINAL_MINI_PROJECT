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
     vector< Iobserver * > m_observers;
     vector < pair<float ,char> > m_vect;
     float m_fTemp;
     char m_cState;
   public:
     int  Temp_Attach(Iobserver *) override;
     void Temp_Detach(Iobserver *) override;
     void Temp_Notify ( void ) override;
     void Temp_Get_Data(void);
     void Temp_Display_Data( void );
     void Temp_Set_Data( void );
};
#endif//__TEMPSENSOR_H__
