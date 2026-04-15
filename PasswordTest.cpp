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

// test 'count_leading_characters' function
TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("Z"));
}
TEST(PasswordTest, mixed_case_password)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("ZZz"));
}
TEST(PasswordTest, empty_char_password)
{
	Password my_password;
	ASSERT_EQ(0, my_password.count_leading_characters(""));
}
TEST(PasswordTest, duplicate_char_password)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("aabb"));
}
TEST(PasswordTest, mixed_duplicate_char_password)
{
	Password my_password;
	EXPECT_EQ(2, my_password.count_leading_characters("Aabb"));
	EXPECT_EQ(2, my_password.count_leading_characters("aaBb"));
}
// test 'has_mixed_case' function
TEST(PasswordTest, mixed_char_password_check)
{
	Password my_password;
	EXPECT_TRUE(my_password.has_mixed_case("Aabb"));
	EXPECT_TRUE(my_password.has_mixed_case("aaBb"));
	
}
TEST(PasswordTest, char_password_check)
{
	Password my_password;
	EXPECT_FALSE(my_password.has_mixed_case("ab"));
	EXPECT_FALSE(my_password.has_mixed_case("AB"));
}
// test 'get_unique_chars'
TEST(PasswordTest, unique_char_check_happy_case)
{
	Password my_password;
	string input = "Password#01";
	ASSERT_EQ(10, my_password.get_unique_chars(input));
}
