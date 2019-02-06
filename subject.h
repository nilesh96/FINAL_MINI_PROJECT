#ifndef SUBJECT_H
#define SUBJECT_H
#include"observer.h"
class ISubject
{
   public:	   
      ISubject()=default;

      virtual ~ISubject() { }
      virtual int Temp_Attach (Iobserver *) = 0;
      virtual void Temp_Detach (Iobserver *) =  0;
      virtual void Temp_Notify(void) = 0;
};
#endif
