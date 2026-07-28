#include <gtest/gtest.h>

#include "TaskManager.hpp"

class TaskManagetTest: public testing::Test{
protected:
    void SetUp() override{
        t.addTask("Task 1", "Description 1");
        t.addTask("Task 2", "Description 2");
        t.addTask("Task 3", "Description 3");
    }

    void TearDown() override{
        Task::resetId();
    }
    TaskManager t;
};

TEST(TaskTest, GetTitle){
    Task t("Task", "Description");
    EXPECT_EQ(t.getTitle(), "Task");
}

TEST(TaskTest, GetDescription){
    Task t("Task", "Description");
    EXPECT_EQ(t.getDescription(), "Description");
}

TEST(TaskTest, GetStatus){
    Task t("Task", "Description");
    EXPECT_FALSE(t.getStatus());
}

TEST(TaskTest, GetId){
    Task::resetId();
    Task t("Task", "Description");
    EXPECT_EQ(t.getId(), 1);
}

TEST(TaskTest, GetPriority){
    Task t("Task", "Description");
    EXPECT_EQ(t.getPriority(), Task::TaskPriority::LOW);
}

TEST(TaskTest, ChangePriorityToLow){
    Task t("Task", "Description");
    t.changePriority(Task::TaskPriority::LOW);
    EXPECT_EQ(t.getPriority(), Task::TaskPriority::LOW);
}

TEST(TaskTest, ChangePriorityToMedium){
    Task t("Task", "Description");
    t.changePriority(Task::TaskPriority::MEDIUM);
    EXPECT_EQ(t.getPriority(), Task::TaskPriority::MEDIUM);
}

TEST(TaskTest, ChangePriorityToHigh){
    Task t("Task", "Description");
    t.changePriority(Task::TaskPriority::HIGH);
    EXPECT_EQ(t.getPriority(), Task::TaskPriority::HIGH);
}

TEST(TaskTest, MarkCompleted){
    Task t("Task", "Description");
    t.markCompleted();
    EXPECT_TRUE(t.getStatus());
}


int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}