/**************START********************************
 * Name : Nilesh kumar
 * File : TestTemp.h
 * Date : 06/02/2019
**************END *********************************/

#ifndef TESTCLASS_H
#define TESTCLASS_H

#include<iostream>
#include<gtest/gtest.h>
#include"observer.h"
#include"subject.h"
#include"tempsensor.h"
#include"acmoniter.h"
#include"controller.h"
#include"tempmoniter.h"

using namespace std;
class TestTempDummy : public ::testing::Test
{
public:
	TestTempDummy();
	virtual ~TestTempDummy();
	static void SetUpTestCase ();
	static void TearDownTestCase ();
	virtual void SetUp ( void );
	virtual void TearDown ( void );

	static int mArgc;
	static char** mArgs;

	static CTempmoniter *pTemp,*pTemp1,*pTemp2;
};
#endif //__TEST_TEMP_H__
