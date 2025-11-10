#include <gtest/gtest.h>
#include "../include/SinglyLinkedList.h"

class SinglyLinkedListTest : public ::testing::Test {
protected:
    void SetUp() override {
        list.pushBack(1);
        list.pushBack(2);
        list.pushBack(3);
    }

    SinglyLinkedList list;
};

TEST_F(SinglyLinkedListTest, InitialSize) {
    auto vec = list.toVector();
    EXPECT_EQ(vec.size(), 3);
}

TEST_F(SinglyLinkedListTest, PushFront) {
    list.pushFront(0);
    auto vec = list.toVector();
    EXPECT_EQ(vec[0], 0);
    EXPECT_EQ(vec.size(), 4);
}

TEST_F(SinglyLinkedListTest, PushBack) {
    list.pushBack(4);
    auto vec = list.toVector();
    EXPECT_EQ(vec[3], 4);
    EXPECT_EQ(vec.size(), 4);
}

TEST_F(SinglyLinkedListTest, Contains) {
    EXPECT_TRUE(list.contains(2));
    EXPECT_FALSE(list.contains(99));
}

TEST_F(SinglyLinkedListTest, DeleteByValue) {
    bool removed = list.delByValue(2);
    EXPECT_TRUE(removed);
    EXPECT_FALSE(list.contains(2));

    removed = list.delByValue(99);
    EXPECT_FALSE(removed);
}

TEST_F(SinglyLinkedListTest, InsertBefore) {
    list.insertBefore(2, 99);
    auto vec = list.toVector();
    EXPECT_EQ(vec[1], 99);
}

TEST_F(SinglyLinkedListTest, InsertAfter) {
    list.insertAfter(2, 99);
    auto vec = list.toVector();
    EXPECT_EQ(vec[2], 99);
}
