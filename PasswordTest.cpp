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
TEST(PasswordTest, count_leading_characters__single_char)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("Z"));
}
TEST(PasswordTest, count_leading_characters__mixed_char);
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("ZZz"));
}
TEST(PasswordTest, count_leading_characters__empty_char);
{
	Password my_password;
	ASSERT_EQ(0, my_password.count_leading_characters(""));
}
TEST(PasswordTest, count_leading_characters__dup_char);
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("aabb"));
}
TEST(PasswordTest, count_leading_characters__mixed_dup_char_1)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("Aabb"));
}
TEST(PasswordTest, count_leading_characters__mixed_dup_char_2)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("aaBb"));
}
// test 'has_mixed_case' function
TEST(PasswordTest, has_mixed_case__mixed_char_password_check_1)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("Aabb"));
}
TEST(PasswordTest, has_mixed_case__mixed_char_password_check_2)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("aaBb"));
}
TEST(PasswordTest, has_mixed_case__char_password_check_1)
{
	Password my_password;
	EXPECT_FALSE(my_password.has_mixed_case("ab"));
}
TEST(PasswordTest, has_mixed_case__char_password_check_1)
{
	Password my_password;
	EXPECT_FALSE(my_password.has_mixed_case("AB"));
}
// test 'get_unique_chars'
TEST(PasswordTest, get_unique_chars__standard_test)
{
	Password my_password;
	string input = "Password#01";
	ASSERT_EQ(10, my_password.get_unique_chars(input));
}
TEST(PasswordTest, get_unique_chars__upper_chars)
{
	Password my_password;
	string input = "ABC";
	ASSERT_EQ(3, my_password.get_unique_chars(input));
}
TEST(PasswordTest, get_unique_chars__lower_chars)
{
	Password my_password;
	string input = "abc";
	ASSERT_EQ(3, my_password.get_unique_chars(input));
}
TEST(PasswordTest, get_unique_chars__empty_char)
{
	Password my_password;
	string input = "";
	ASSERT_EQ(0, my_password.get_unique_chars(input));
}
TEST(PasswordTest, get_unique_chars__single_dup_lower_char)
{
	Password my_password;
	string input = "aaa";
	ASSERT_EQ(1, my_password.get_unique_chars(input));
}
TEST(PasswordTest, get_unique_chars__single_dup_upper_char)
{
	Password my_password;
	string input = "AAA";
	ASSERT_EQ(1, my_password.get_unique_chars(input));
}