/*************Start*******************************
 * Author : Nilesh kumar
 * File   : acmoniter.h
 * Date   : 01/02/2019
**************************************************/


#ifndef __ACMONITER__H
#define __ACMONITER_H__
#include"observer.h"
class CAcmoniter:public IObserver
{
   private:
      float m_fValue ;
      char m_szState;
      int m_nId;	
   public:
        CAcmoniter() = default;
        CAcmoniter( int );
	void Moniter_Update ( float, char ) override;
	void Moniter_Check();
	static void * Moniter_Thread( void * );
};
#endif
// __ACMONNITER_H__
