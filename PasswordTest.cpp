/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};
//Count leading character test cases
TEST(PracticeTest, one_letter_password)//Passes
{
        Password my_password;
        int actual = my_password.count_leading_characters("a");
        ASSERT_EQ(1, actual);
}
TEST(PracticeTest, empty_letter_password)//Fails
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}
TEST(PracticeTest, two_letter_password)//Passes
{
        Password my_password;
        int actual = my_password.count_leading_characters("ttrtt");
        ASSERT_EQ(2, actual);
}
TEST(PracticeTest, same_letter_password)//Passes
{
    	Password my_password;
    	int actual = my_password.count_leading_characters("aaaaa");
    	ASSERT_EQ(5, actual);
}
TEST(PracticeTest, uppercase_password)//Passes
{
    	Password my_password;
    	int actual = my_password.count_leading_characters("AAAaa");
    	ASSERT_EQ(3, actual);
}
//Mixed cases tests
TEST(PracticeTest, allUppercase_password)//Should fail
{
    	Password my_password;
    	bool actual = my_password.has_mixed_case("ABCDEF");
    	ASSERT_FALSE(actual);//Expected to fail so false
}//Result: Does indeed fail 
TEST(PracticeTest, mixedcase_number_password)//Should pass
{
    	Password my_password;
    	bool actual = my_password.has_mixed_case("aBAAb");
    	ASSERT_TRUE(actual);
}//Result: Fails due to numbers
TEST(PracticeTest, mixedcase_with_spaces)
{
    	Password my_password;
    	bool actual = my_password.has_mixed_case("A b C d");
    	ASSERT_TRUE(actual);//Should pass because A and b
}//Results: Fails due to spaces
TEST(PracticeTest, mixedcase_empty)//Should fail no characters
{
    	Password my_password;
    	bool actual = my_password.has_mixed_case("");
    	ASSERT_FALSE(actual);
}//Result: Passes so failed case 
TEST(PracticeTest, single_uppercase)//Should fail
{
    Password my_password;
    bool actual = my_password.has_mixed_case("A");
    ASSERT_FALSE(actual);
}//Result: Fails need another character lowercase
TEST(PracticeTest, single_lowercase)//Should fail
{
    Password my_password;
    bool actual = my_password.has_mixed_case("r");
    ASSERT_FALSE(actual);
}//Result: Fails need another character uppercase
