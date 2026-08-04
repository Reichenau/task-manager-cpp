#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <limits>

#include "TaskManager.hpp"
#include "Task.hpp"

void printInfoMenu(){
    std::cout << "---------- Task Manager Menu ----------" << std::endl;
    std::cout << "0 - exit.\n" <<
                 "1 - show menu.\n" <<
                 "2 - add new task.\n" <<
                 "3 - remove task.\n" <<
                 "4 - complete task.\n" <<
                 "5 - clear task list.\n" <<
                 "6 - show task list.\n" <<
                 "> ";
}

void showTaskList(const std::vector<Task>& tasks){
    std::cout << "---------------------------" << std::endl;
    for (const auto& task: tasks){
        std::cout << "ID: " << task.getId() << " " << 
                     "Title: " << task.getTitle() << " " <<
                     "Desc: " << task.getDescription() << " " <<
                     "Status: " << task.getStatus() << " ";
        switch (task.getPriority())
        {
        case Task::TaskPriority::LOW: std::cout << "Priority: Low " << std::endl; break;
        case Task::TaskPriority::MEDIUM: std::cout << "Priority: Medium " << std::endl; break;
        case Task::TaskPriority::HIGH: std::cout << "Priority: high " << std::endl; break;
        }
    }
}

int main(int argc, char* argv[]){
    
    TaskManager taskManager;
    char userInput;
    bool isExit{false};
    printInfoMenu();
    while (!isExit){
        std::cout << "Enter the desired number to select a command\n> ";
        std::cin >> userInput;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (userInput)
        {
        case '0':
            isExit = true;
            break;
        case '1':{
            printInfoMenu();
            break;}
        case '2':{
            std::string title;
            std::cout << "Enter title task.\n> ";
            std::getline(std::cin, title);
            
            std::string desc;
            std::cout << "Enter description.\n> ";
            std::getline(std::cin, desc);

            taskManager.addTask(title, desc);
            break;}
        case '3':{
            std::size_t id;
            std::cout << "Enter the id of task.\n> ";
            std::cin >> id;

            taskManager.removeTask(id);
            break;}
        case '4':{
            std::size_t id;
            std::cout << "Enter the id of task.\n> ";
            std::cin >> id;

            taskManager.completeTask(id);
            break;}
        case '5':{
            taskManager.clear();
            break;}
        case '6':
            showTaskList(taskManager.getTasks());
            break;
        default:
            break;
        }
    }
    return 0;
}