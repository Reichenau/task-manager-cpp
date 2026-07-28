#pragma once
#include <string>
#include <vector>

class Task{
public:
    enum class TaskPriority
    {
        LOW,
        MEDIUM,
        HIGH
    };
private:
    std::string m_title;
    std::string m_description;
    bool m_done{false};
    inline static std::size_t next_id{1};
    const std::size_t m_id;
    TaskPriority m_priority{TaskPriority::LOW};
public:
    Task(const std::string& title, const std::string& desc)
    : m_title(title), m_description(desc), m_id(next_id++) {}

    void changePriority(TaskPriority priority);
    void markCompleted();

    std::string getTitle() const {return m_title;}
    std::string getDescription() const {return m_description;}
    bool getStatus() const {return m_done;}
    std::size_t getId() const {return m_id;}
    TaskPriority getPriority() const {return m_priority;}

    static void resetId() { next_id = 1; }
};