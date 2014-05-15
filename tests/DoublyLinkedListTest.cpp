#include <gtest/gtest.h>

#include <stdexcept>
#include "DoublyLinkedList.h"

using structures::DoublyLinkedList;

class DoublyLinkedListTest : public testing::Test {
public:
	DoublyLinkedList<int> list;
};

TEST_F(DoublyLinkedListTest, emptyListIsEmpty)
{
	EXPECT_TRUE(list.isEmpty());
}

TEST_F(DoublyLinkedListTest, sizeOfEmptyListEqualsZero)
{
	EXPECT_EQ(0, list.size());
}

TEST_F(DoublyLinkedListTest, pushPopFrontOneElement)
{
	list.pushFront(42);
	EXPECT_EQ(1, list.size());
	EXPECT_FALSE(list.isEmpty());
	EXPECT_EQ(42, list.popFront());
	EXPECT_EQ(0, list.size());
	EXPECT_TRUE(list.isEmpty());
}

TEST_F(DoublyLinkedListTest, popFrontFromEmptyList)
{
	EXPECT_THROW(list.popFront(), std::out_of_range);
}

TEST_F(DoublyLinkedListTest, pushPopFrontManyElements)
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

TEST_F(DoublyLinkedListTest, pushPopBackOneElement)
{
	list.pushBack(42);
	EXPECT_EQ(1, list.size());
	EXPECT_EQ(42, list.popBack());
	EXPECT_EQ(0, list.size());
}

TEST_F(DoublyLinkedListTest, pushPopBackManyElements)
{
	list.pushBack(42);
	list.pushBack(1908);
	list.pushBack(9);
	EXPECT_EQ(3 , list.size());
	EXPECT_FALSE(list.isEmpty());
	EXPECT_EQ(9, list.popBack());
	EXPECT_EQ(1908, list.popBack());
	EXPECT_EQ(42, list.popBack());
	EXPECT_EQ(0, list.size());
	EXPECT_TRUE(list.isEmpty());
}

TEST_F(DoublyLinkedListTest, isCreatedEmpty)
{
  EXPECT_EQ(0, list.size());
}

TEST_F(DoublyLinkedListTest, pushBackPushesOnBack)
{
  list.pushBack(42);
  EXPECT_EQ(1, list.size());
  EXPECT_EQ(42, list.at(0));
  list.pushBack(1963);
  EXPECT_EQ(42, list.at(0));
  EXPECT_EQ(1963, list.at(1));
  EXPECT_EQ(2, list.size());
}

TEST_F(DoublyLinkedListTest, pushFrontPushesOnFront)
{
  list.pushFront(42);
  EXPECT_EQ(1, list.size());
  EXPECT_EQ(42, list.at(0));
  list.pushFront(1963);
  EXPECT_EQ(1963, list.at(0));
  EXPECT_EQ(42, list.at(1));
  EXPECT_EQ(2, list.size());
}

TEST_F(DoublyLinkedListTest, insert)
{
  list.pushBack(42);
  list.pushBack(13);
  list.insert(1, 1963);
  EXPECT_EQ(42, list.at(0));
  EXPECT_EQ(1963, list.at(1));
  EXPECT_EQ(13, list.at(2));
  EXPECT_EQ(3, list.size());
}

TEST_F(DoublyLinkedListTest, popBack)
{
  list.pushBack(42);
  list.pushBack(1963);
  EXPECT_EQ(1963, list.popBack());
  EXPECT_EQ(1, list.size());
}

TEST_F(DoublyLinkedListTest, popFront)
{
  list.pushBack(42);
  list.pushBack(1963);
  EXPECT_EQ(42, list.popFront());
  EXPECT_EQ(1, list.size());
}

TEST_F(DoublyLinkedListTest, remove)
{
  list.pushBack(42);
  list.pushBack(1963);
  list.pushBack(13);
  EXPECT_EQ(1963, list.remove(1));
  EXPECT_EQ(2, list.size());
}

TEST_F(DoublyLinkedListTest, accessOutOfRange)
{
  EXPECT_THROW(list.at(13), std::out_of_range);
  EXPECT_THROW(list.insert(13, 42), std::out_of_range);
  EXPECT_THROW(list.remove(13), std::out_of_range);
}

TEST_F(DoublyLinkedListTest, boundariesWithNoProblems)
{
  list.insert(0, 42);
  EXPECT_EQ(1, list.size());
  EXPECT_EQ(42, list.at(0));
  EXPECT_EQ(42, list.remove(0));
  EXPECT_EQ(0, list.size());
}

TEST_F(DoublyLinkedListTest, removalsFromEmptyThrow)
{
  EXPECT_THROW(list.popBack(), std::out_of_range);
  EXPECT_THROW(list.popFront(), std::out_of_range);
  EXPECT_THROW(list.remove(13), std::out_of_range);
}