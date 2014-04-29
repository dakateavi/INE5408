#include <gtest/gtest.h>
#include <stdexcept>

#include "List.h"

class ListTest : public testing::Test {
public:
	List<int> list;
};

TEST_F(ListTest, emptyListIsEmpty)
{
	EXPECT_TRUE(list.isEmpty());
}

TEST_F(ListTest, sizeOfEmptyListEqualsZero)
{
	EXPECT_EQ(0, list.size());
}

TEST_F(ListTest, pushPopFrontOneElement)
{
	list.pushFront(42);
	EXPECT_EQ(1, list.size());
	EXPECT_FALSE(list.isEmpty());
	EXPECT_EQ(42, list.popFront());
	EXPECT_EQ(0, list.size());
	EXPECT_TRUE(list.isEmpty());
}

TEST_F(ListTest, popFrontFromEmptyList)
{
	EXPECT_THROW(list.popFront(), std::length_error);
}

TEST_F(ListTest, pushPopFrontManyElements)
{
	list.pushFront(42);
	list.pushFront(1908);
	list.pushFront(9);
	EXPECT_EQ(3 , list.size());
	EXPECT_FALSE(list.isEmpty());
	EXPECT_EQ(9, list.popFront());
	EXPECT_EQ(1908, list.popFront());
	EXPECT_EQ(42, list.popFront());
	EXPECT_EQ(0, list.size());
	EXPECT_TRUE(list.isEmpty());
}

TEST_F(ListTest, pushPopBackOneElement)
{
	list.pushBack(42);
	EXPECT_EQ(1, list.size());
	EXPECT_FALSE(list.isEmpty());
	EXPECT_EQ(42, list.popBack());
	EXPECT_EQ(0, list.size());
	EXPECT_TRUE(list.isEmpty());
}

TEST_F(ListTest, pushPopBackManyElements)
{
	list.pushBack(42);
	list.pushBack(1908);
	list.pushBack(9);
	EXPECT_EQ(3 , list.size());
	EXPECT_FALSE(list.isEmpty());
	EXPECT_EQ(9, list.popBack());
	//EXPECT_EQ(1908, list.popBack());
	//EXPECT_EQ(42, list.popBack());
	//EXPECT_EQ(0, list.size());
	//EXPECT_TRUE(list.isEmpty());
}