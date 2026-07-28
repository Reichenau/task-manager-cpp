#include "Task.hpp"

void Task::changePriority(TaskPriority priority){
    if (m_priority != priority) m_priority = priority;
}

void Task::markCompleted(){
    m_done = true;
}