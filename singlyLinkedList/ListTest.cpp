#include <gtest/gtest.h>
#include "List.h"

class ListTest : public testing::Test {
public:
	List<int>  list;
};

TEST_F(ListTest, pushFrontPopFrontOneElement)
{
	list.pushFront(5);
	EXPECT_EQ(1 , list.length());
	EXPECT_EQ(5 , list.popFront());
}

TEST_F(ListTest, isListEmpty)
{
	EXPECT_TRUE(list.isEmpty());
	EXPECT_EQ(0 , list.length());
	list.pushFront(42);
	EXPECT_FALSE(list.isEmpty());
}

TEST_F(ListTest, pushFrontPopFrontManyElements)
{
	list.pushFront(42);
	list.pushFront(2048);
	list.pushFront(7);
	EXPECT_EQ(3, list.length());
	EXPECT_EQ(7, list.popFront());
	EXPECT_EQ(2048, list.popFront());
	EXPECT_EQ(42, list.popFront());
}

TEST_F(ListTest, popFromEmptyList)
{
	EXPECT_THROW(list.popFront() , std::range_error);
}

TEST_F(ListTest, pushBackPopBackOneElement)
{
	list.pushBack(42);
	EXPECT_EQ(1, list.length());
	EXPECT_EQ(42, list.popBack());
}