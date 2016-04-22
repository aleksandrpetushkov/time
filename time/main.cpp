#include "Time.h"
#include "gtest/gtest.h"


using namespace std;

TEST(compare)
{
	Time tm(55, 40, 30, 20);
	Time tm2(31, 40, 30, 20);
	ASSERT_LE(tm, tm2);
	ASSERT_GE(tm2, tm);
	ASSERT_EQ(tm, tm2);
	tm.addHours(1);
	ASSERT_GE(tm, tm2);
	ASSERT_LE(tm2, tm);
	ASSERT_GT(tm, tm2);
	ASSERT_LT(tm2, tm);
	ASSERT_NE(tm, tm2);
	ASSERT_EQ(tm.H(), 8);
	tm.addMin(1);
	ASSERT_EQ(tm.M(), 41);
	tm.addSec(1);
	ASSERT_EQ(tm.S(), 31);
	tm.addMsec(1);
	ASSERT_EQ(tm.Ms(), 21);
}





int main(int argc, char* argv[])
{

	
	
	Time tm(55, 75,0, 30);
	tm.addSec(1);
	cout << tm.S() << endl;
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	cin.get();
}