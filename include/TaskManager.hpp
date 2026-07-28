#pragma once
#include <vector>
#include <string>

#include "Task.hpp"

class TaskManager{
private:
    std::vector<Task> m_tasks;
public:
    void addTask(const std::string& title, const std::string& desc);
    void removeTask(std::size_t id);
    void completeTask(std::size_t id);
    
    std::vector<Task> getTasks() const {return m_tasks;}
    std::vector<Task> getPending() const;
    std::vector<Task> getCompleted() const;
    void clear();
};