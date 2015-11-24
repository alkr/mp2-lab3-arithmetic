#include "stack.h"
#include <gtest.h>

#include <gtest.h>
#include "stack.h"

TEST(stack, can_create_stack_with_possitive_size)
{
	ASSERT_NO_THROW(stack<int> st(5));
}

TEST(stack, cant_create_stack_with_negative_size)
{
	ASSERT_ANY_THROW(stack<int> st(-5));
}


TEST(stack, can_do_stack_with_size) {
	stack<int> st(10);
	EXPECT_EQ(0, st.size());
}

TEST(stack, can_push) {
	stack<int> st(10);
	st.push(2);
	EXPECT_EQ(2, st.get());
}

TEST(stack, stack_full) {
	stack<int> st(1);
	st.push(1);
	EXPECT_EQ(true, st.full());
}

TEST(stack, stack_not_empty) {
	stack<int> st(10);
	st.push(1);
	EXPECT_EQ(false, st.empty());
}

TEST(stack, stack_not_full) {
	stack<int> st(10);
	EXPECT_EQ(false, st.full());
}

TEST(stack, stack_empty) {
	stack<int> st(10);
	EXPECT_EQ(true, st.empty());
}
TEST(stack, stacks_with_different_size_are_not_equal) {
	stack<int> st(9);
	stack<int> st1(1);
	EXPECT_EQ(false, st==st1);
}

TEST(stack, stacks_with_equal_size_are_equal) {
	stack<int> st(9);
	stack<int> st1(9);
	EXPECT_EQ(true, st==st1);
}

TEST(stack, different_stacks_with_equel_size_are_not_equal) {
	stack<int> st(9);
	st.push(1);
	stack<int> st1(9);
	st1.push(2);
	EXPECT_EQ(false, st==st1);
}
TEST(stack, get){
	stack<int> q(10);
	q.push(1);
	int t=q.get();
	EXPECT_EQ(1,t);
}

TEST(stack, get_and_size){
	stack<int> q(10);
	q.push(1);
	int t=q.get();
	EXPECT_EQ(0,q.size());
}

TEST(stack, push_and_size){
	stack<int> q(10);
	q.push(1);
	EXPECT_EQ(1,q.size());
}