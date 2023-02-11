#pragma once
#include <string>
#include "Date.h"

class Task
{
private:
	unsigned int taskId;
	unsigned int entryP;
	unsigned int PIC;
	std::string taskName;
	std::string content;
	std::string priority;
	Date deadLine;
	bool status = false;
public:
	Task(unsigned int taskId, unsigned int entryP, unsigned int PIC, std::string taskName, std::string content, std::string priority, Date deadLine);
	void SetStatus(bool status);
	void SetPIC(unsigned int PIC);
	void SetTaskName(std::string taskName);
	void SetPriority(std::string priority);
	void SetContent(std::string content);
	void SetDeadLine(Date deadLine);
	void Draw();
	void DrawID();
	unsigned int GetID();
};

