/*************Start*******************************
 * Author : Nilesh kumar
 * File   : tempmoniter.h
 * Date   : 31/01/2019
**************************************************/
#ifndef __TEMPMONITER_H__
#define __TEMPMONITER_H__
#include"observer.h"
#include<vector>
#include<iostream>
#include<algorithm>

class CTempmoniter:public IObserver
{
	float m_fValue;
	char m_szState;
	int nId;
  public:
	  
     //vector<pair<float ,char>> v1;
        CTempmoniter() = default;       	
	CTempmoniter(int );
	void Moniter_Convert();
	static void* Thread(void *);
	void Moniter_Update(float,char)override;
		
        	
};
#endif//__TEMPMONITER_H__
