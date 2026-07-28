#include <vector>
#include <string>

#include "TaskManager.hpp"
#include "Task.hpp"

void TaskManager::addTask(const std::string& title, const std::string& desc){
    m_tasks.push_back(Task(title, desc));
}

void TaskManager::removeTask(std::size_t id){
    std::erase_if(m_tasks, [id](const Task& task) {
        return task.getId() == id;
    });
}

void TaskManager::completeTask(std::size_t id){
    auto it = std::ranges::find_if(m_tasks, [id](const Task& task) {
        return task.getId() == id;
    });

    if (it != m_tasks.end()) it->markCompleted();
}

std::vector<Task> TaskManager::getPending() const {
    std::vector<Task> result;
    for (const auto& task: m_tasks){
        if (!task.getStatus()) result.push_back(task);
    }
    return result;
}

std::vector<Task> TaskManager::getCompleted() const{
    std::vector<Task> result;
    for (const auto& task: m_tasks){
        if (task.getStatus()) result.push_back(task);
    }
    return result;
}

void TaskManager::clear(){
    m_tasks.clear();
}
