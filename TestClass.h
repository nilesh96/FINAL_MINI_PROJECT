//#ifndef TESTCLASS_H
//#define TESTCLASS_H

#include<iostream>
#include<gtest/gtest.h>
#include"class.h"

using namespace std;


class BankDummy : public bank
{
public:
	BankDummy(string s, int ac,float f ):bank(s, ac,f)
	{
		cout << "Constructor" << endl;
	}
	
	FRIEND_TEST ( TestBankDummy, chkbalance_1);
	FRIEND_TEST ( TestBankDummy, chkbalance_2);
	friend class TestBankDummy;

};

class TestBankDummy : public ::testing::Test
{
public:
	TestBankDummy();
	virtual ~TestBankDummy();
	static void SetUpTestCase ();
	static void TearDownTestCase ();
	virtual void SetUp ( void );
	virtual void TearDown ( void );

	static int mArgc;
	static char** mArgs;

	static BankDummy *pM;
};

