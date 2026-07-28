#include <gtest/gtest.h>

#include "TaskManager.hpp"

class TaskManagerTest: public testing::Test{
protected:
    void SetUp() override{
        Task::resetId();

        tm.addTask("Task 1", "Description 1");
        tm.addTask("Task 2", "Description 2");
        tm.addTask("Task 3", "Description 3");
    }

    void TearDown() override{}
    TaskManager tm;
};

TEST(TaskTest, GetTitle){
    Task::resetId();
    Task t("Task", "Description");
    EXPECT_EQ(t.getTitle(), "Task");
}

TEST(TaskTest, GetDescription){
    Task::resetId();
    Task t("Task", "Description");
    EXPECT_EQ(t.getDescription(), "Description");
}

TEST(TaskTest, GetStatus){
    Task::resetId();
    Task t("Task", "Description");
    EXPECT_FALSE(t.getStatus());
}

TEST(TaskTest, GetId){
    Task::resetId();
    Task t("Task", "Description");
    EXPECT_EQ(t.getId(), 1);
}

TEST(TaskTest, GetPriority){
    Task::resetId();
    Task t("Task", "Description");
    EXPECT_EQ(t.getPriority(), Task::TaskPriority::LOW);
}

TEST(TaskTest, ChangePriorityToLow){
    Task::resetId();
    Task t("Task", "Description");
    t.changePriority(Task::TaskPriority::LOW);
    EXPECT_EQ(t.getPriority(), Task::TaskPriority::LOW);
}

TEST(TaskTest, ChangePriorityToMedium){
    Task::resetId();
    Task t("Task", "Description");
    t.changePriority(Task::TaskPriority::MEDIUM);
    EXPECT_EQ(t.getPriority(), Task::TaskPriority::MEDIUM);
}

TEST(TaskTest, ChangePriorityToHigh){
    Task::resetId();
    Task t("Task", "Description");
    t.changePriority(Task::TaskPriority::HIGH);
    EXPECT_EQ(t.getPriority(), Task::TaskPriority::HIGH);
}

TEST(TaskTest, MarkCompleted){
    Task::resetId();
    Task t("Task", "Description");
    t.markCompleted();
    EXPECT_TRUE(t.getStatus());
}

// --------- TASKMANAGER ---------
TEST_F(TaskManagerTest, addTask){
    std::size_t before{tm.getTasks().size()};
    tm.addTask("Task 4", "Description 4");
    EXPECT_GT(tm.getTasks().size(), before);
}

TEST_F(TaskManagerTest, RemoveTask){
    std::size_t before{tm.getTasks().size()};
    tm.removeTask(2);
    EXPECT_LT(tm.getTasks().size(), before);
}

TEST_F(TaskManagerTest, CompleteTask){
    tm.completeTask(2);
    EXPECT_TRUE(tm.getTasks()[1].getStatus());
}

TEST_F(TaskManagerTest, GetCompleted){
    tm.completeTask(1);
    tm.completeTask(2);
    EXPECT_EQ(tm.getCompleted().size(), 2);
}

TEST_F(TaskManagerTest, GetPending){
    tm.completeTask(1);
    tm.completeTask(2);
    EXPECT_EQ(tm.getPending().size(), 1);
}


int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}