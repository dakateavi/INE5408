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