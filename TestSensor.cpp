#include<gtest/gtest.h>
#include"TestSensor.h"

using namespace std;

int TestSensorDummy::mArgc = 0;
char** TestSensorDummy::mArgs = NULL;
CTempSensor* TestSensorDummy::pSensor= NULL;
CTempSensor* TestSensorDummy::pSensor1 = NULL;
CTempSensor* TestSensorDummy::pSensor2 = NULL;

TestSensorDummy::TestSensorDummy( void )
{

}

TestSensorDummy::~TestSensorDummy( void )
{

}

void TestSensorDummy::SetUpTestCase()
{
	cout << "Set up test cases." << endl;

	if ( pSensor != NULL || pSensor1 != NULL || pSensor2 != NULL )
	{
		delete pSensor;
		delete pSensor1;
		delete pSensor2;
	}

	pSensor = new CTempSensor();
	pSensor1 = new CTempSensor();
	pSensor2 = new CTempSensor();
}

void TestSensorDummy::TearDownTestCase()
{
	cout << "Tear down test cases." << endl;

	delete pSensor;
	delete pSensor1;
	delete pSensor2;
}

void TestSensorDummy::SetUp(void)
{

}

void TestSensorDummy::TearDown(void)
{

}

TEST_F(TestSensorDummy, File_open_1 )
{
	bool bRet = pSensor->Temp_Get_Data();
	cout << "Return vlaue " << bRet << endl;
        ASSERT_FALSE( bRet );
}
/*
TEST_F(TestSensorDummy, convert_2 )
{
	float s=98 ;
        ASSERT_EQ(s,pSensor->Moniter_Convert());
}

TEST_F(TestSensorDummy, convert_3 )
{
	float s=35.5556;
        ASSERT_EQ(s,pSensor1->Moniter_Convert());
}
TEST_F(TestSensorDummy, convert_4 )
{
	float s = 0;
        ASSERT_EQ(s,pSensor2->Moniter_Convert());
}*/
