#include<gtest/gtest.h>
#include"TestClass.h"

using namespace std;

int TestBankDummy::mArgc = 0;
char** TestBankDummy::mArgs = NULL;
BankDummy* TestBankDummy::pM = NULL;

TestBankDummy::TestBankDummy(void)
{

}

TestBankDummy::~TestBankDummy(void)
{

}

void TestBankDummy::SetUpTestCase()
{
	cout << "Set up test cases." << endl;

	if ( pM != NULL )
	{
		delete pM;
	}

	pM = new BankDummy("nilesh",1234,1200);
}

void TestBankDummy::TearDownTestCase()
{
	cout << "Tear down test cases." << endl;

	delete pM;
}

void TestBankDummy::SetUp(void)
{

}

void TestBankDummy::TearDown(void)
{

}

TEST_F(TestBankDummy, chkbalance_1 )
{
	float s=7200 ;
	pM->deposit(1234,6000);
        ASSERT_EQ(s,pM->chkbalance(1234));
}
TEST_F(TestBankDummy, chkbalance_2 )
{
	float s=900 ;
	pM->withdraw(1234,-300);
        ASSERT_EQ(s,pM->chkbalance(1234));
}
/*
TEST_F(TestBankDummy, chkbalance_3 )
{
	float s=1600,p=1200 ;
	pM->withdraw(1234,200);
	EXPECT_EQ(p,pM->chkbalance(1234));
	pM->deposit(1234,400);
        ASSERT_EQ(s,pM->chkbalance(1234));
}
TEST_F ( TestMathDummy, getsum_2 )
{
	int s = 6;
	pM->add();
	ASSERT_EQ ( s, pM->getsum() );
}*/
