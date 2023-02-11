#pragma once
#include <list>
#include <memory>
#include <vector>
#include "Task.h"

class TaskManager
{
private:
    std::list<std::unique_ptr<Task>> tasks;
    std::vector<bool>nextID;
    TaskManager() {};
    ~TaskManager();
public:
    TaskManager(const TaskManager& obj) = delete;
    TaskManager operator=(const TaskManager& obj) = delete;
    static TaskManager* GetInstance();
    void AddTask();
    //void SetTaskName();
    void SetPIC();
    void SetStatus();
    void SetPriority();
    void SetContent();
    void SetDeadLine();
    void Draw();
    void DeleteTask();
};

