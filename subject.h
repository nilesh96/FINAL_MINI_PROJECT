/*************Start*******************************
 * Author : Nilesh kumar
 * File   : subject.h
 * Date   : 30/01/2019
**************************************************/
#ifndef SUBJECT_H
#define SUBJECT_H
#include"observer.h"
class ISubject
{
   public:	   
      ISubject()=default;
      virtual ~ISubject() { }

      virtual int Temp_Attach ( IObserver * ) = 0;
      virtual void Temp_Detach ( IObserver * ) =  0;
      virtual void Temp_Notify ( void ) = 0;
};
#endif//__SUBJECT_H__
