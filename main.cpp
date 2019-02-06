#include<iostream>
#include"tempmoniter.h"
#include"tempsensor.h"
#include"acmoniter.h"
using namespace std;
int main()
{
    CTempSensor *ptr;

    CAcmoniter *Acsub;
    Acsub = new CAcmoniter(2);

    CTempmoniter *Tempsub;
    Tempsub = new CTempmoniter(1);

    ptr= new CTempSensor();
    ptr->Temp_Get_Data();
//  ptr->display_data();
   
    ptr->Temp_Attach(Tempsub);
    ptr->Temp_Attach(Acsub);
    ptr->Temp_Set_Data();
    delete Tempsub;
    delete Acsub;
    delete ptr;
    return 0;
}
