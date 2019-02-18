/**************START********************************
 * Name : Nilesh kumar
 * File : TestSensor.h
 * Date : 07/02/2019
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
class TestSensorDummy : public ::testing::Test
{
public:
	TestSensorDummy();
	virtual ~TestSensorDummy();
	static void SetUpTestCase ();
	static void TearDownTestCase ();
	virtual void SetUp ( void );
	virtual void TearDown ( void );

	static int mArgc;
	static char** mArgs;

	static CTempSensor *pSensor,*pSensor1,*pSensor2;
};
#endif //__TEST_TEMP_H__
