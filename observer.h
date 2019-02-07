/*************Start*******************************
 * Author : Nilesh kumar
 * File   : observer.h
 * Date   : 30/01/2019
**************************************************/
#ifndef __OBSERVER_H__
#define __OBSERVER_H__

class IObserver
{
   public:
        IObserver()  {  }
	virtual ~ IObserver() {  }
	virtual void Moniter_Update ( float ,char ) = 0;

};
#endif//__OBSERVER_H__
