#include<iostream>
#include"tempmoniter.h"
#include"tempsensor.h"
#include"acmoniter.h"
using namespace std;
int main()
{
    CTempSensor *pcTemp;

    CAcmoniter *pcAcsub;
    pcAcsub = new CAcmoniter(2);

    CTempmoniter *pcTempsub;
    pcTempsub = new CTempmoniter(1);

    pcTemp= new CTempSensor();
    pcTemp->Temp_Get_Data();
//  pcTemp->display_data();
   
    pcTemp->Temp_Attach(pcTempsub);
    pcTemp->Temp_Attach(pcAcsub);
    pcTemp->Temp_Set_Data();
    delete pcTempsub;
    delete pcAcsub;
    delete pcTemp;
    return 0;
}
