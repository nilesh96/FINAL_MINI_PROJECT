#include<gtest/gtest.h>
#include"TestTemp.h"

using namespace std;

int TestTempDummy::mArgc = 0;
char** TestTempDummy::mArgs = NULL;
CTempmoniter* TestTempDummy::pTemp= NULL;
CTempmoniter* TestTempDummy::pTemp1 = NULL;
CTempmoniter* TestTempDummy::pTemp2 = NULL;

TestTempDummy::TestTempDummy(void)
{

}

TestTempDummy::~TestTempDummy(void)
{

}

void TestTempDummy::SetUpTestCase()
{
	cout << "Set up test cases." << endl;

	if ( pTemp != NULL || pTemp1 != NULL || pTemp2 != NULL )
	{
		delete pTemp;
		delete pTemp1;
		delete pTemp2;
	}

	pTemp = new CTempmoniter(20,'c',1);
	pTemp1 = new CTempmoniter(96,'f',1);
	pTemp2 = new CTempmoniter(0,'F',1);
}

void TestTempDummy::TearDownTestCase()
{
	cout << "Tear down test cases." << endl;

	delete pTemp;
	delete pTemp1;
	delete pTemp2;
}

void TestTempDummy::SetUp(void)
{

}

void TestTempDummy::TearDown(void)
{

}

TEST_F(TestTempDummy, convert_1 )
{
	float s=68;
        ASSERT_EQ(s,pTemp->Moniter_Convert());
}

TEST_F(TestTempDummy, convert_2 )
{
	float s=98 ;
        ASSERT_EQ(s,pTemp->Moniter_Convert());
}

TEST_F(TestTempDummy, convert_3 )
{
	float s=35.5556;
        ASSERT_EQ(s,pTemp1->Moniter_Convert());
}
TEST_F(TestTempDummy, convert_4 )
{
	float s = 0;
        ASSERT_EQ(s,pTemp2->Moniter_Convert());
}
