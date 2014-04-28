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

TEST_F(ListTest, pushFrontIncreasesSizeAndUpdateEmptiness)
{
	list.pushFront(42);
	EXPECT_EQ(1, list.size());
	EXPECT_FALSE(list.isEmpty());
}

TEST_F(ListTest, popFrontFromEmptyList)
{
	EXPECT_THROW(list.popFront(), std::length_error);
}

TEST_F(ListTest, pushFrontPopFrontSingleton)
{
	list.pushFront(42);
	EXPECT_EQ(42, list.popFront());
	EXPECT_EQ(1, list.size());
	EXPECT_FALSE(list.isEmpty());
}