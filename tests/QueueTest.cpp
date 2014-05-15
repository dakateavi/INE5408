#include <gtest/gtest.h>
#include "Queue.h"

class QueueTest : public testing::Test {
public:
	Queue<int>  queue;
};

TEST_F(QueueTest, pushOneElement)
{
	EXPECT_TRUE(queue.isEmpty());
	EXPECT_EQ(0 , queue.length());
	queue.push(42);
	EXPECT_FALSE(queue.isEmpty());
	EXPECT_EQ(1 , queue.length());
}

TEST_F(QueueTest, pushPopOneElement)
{
	EXPECT_TRUE(queue.isEmpty());
	EXPECT_EQ(0 , queue.length());
	queue.push(42);
	EXPECT_FALSE(queue.isEmpty());
	EXPECT_EQ(1 , queue.length());
	EXPECT_EQ(42 , queue.pop());
	EXPECT_EQ(0 , queue.length());
	EXPECT_TRUE(queue.isEmpty());
}


TEST_F(QueueTest, pushPopManyElements)
{
	queue.push(42);
	queue.push(2048);
	queue.push(7);

	EXPECT_EQ(3, queue.length());

	EXPECT_EQ(42, queue.pop());
	EXPECT_EQ(2048, queue.pop());
	EXPECT_EQ(7, queue.pop());
}

TEST_F(QueueTest, popFromEmptyQueue)
{
	EXPECT_THROW(queue.pop() , std::out_of_range);
}

TEST_F(DoublyLinkedQueueTest, isCreatedEmpty)
{
	EXPECT_EQ(queue.size(), 0);
}

TEST_F(DoublyLinkedQueueTest, topOnEmptyThrows)
{
	EXPECT_THROW(queue.top(), std::out_of_range);
}

TEST_F(DoublyLinkedQueueTest, pushOneElement)
{
	queue.push(42);
	EXPECT_EQ(queue.size(), 1);
}

TEST_F(DoublyLinkedQueueTest, pushManyElements)
{
	queue.push(42);
	queue.push(1963);
	queue.push(13);
	EXPECT_EQ(3, queue.size());
	EXPECT_EQ(42, queue.top());
}

TEST_F(DoublyLinkedQueueTest, popFromSingletonMakesEmpty)
{
	queue.push(42);
	EXPECT_EQ(42, queue.pop());
	EXPECT_EQ(0, queue.size());
}

TEST_F(DoublyLinkedQueueTest, popAll)
{
	queue.push(42);
	queue.push(1963);
	queue.push(13);
	EXPECT_EQ(42, queue.pop());
	EXPECT_EQ(2, queue.size());
	EXPECT_EQ(1963, queue.pop());
	EXPECT_EQ(1, queue.size());
	EXPECT_EQ(13, queue.pop());
	EXPECT_EQ(0, queue.size());
}

TEST_F(DoublyLinkedQueueTest, popFromEmptyThrows)
{
	EXPECT_THROW(queue.pop(), std::out_of_range);
}