#include "Task.h"
#include "PersonManager.h"
#include <iostream>

using namespace std;

Task::Task(unsigned int taskId, unsigned int entryP, unsigned int PIC, std::string taskName, std::string content, std::string priority, Date deadLine)
	:taskId(taskId), entryP(entryP), PIC(PIC), taskName(taskName), content(content), priority(priority), deadLine(deadLine) {}

void Task::SetStatus(bool status)
{
	string nows = this->status ? "完了" : "未完了";
	string s = status ? "完了" : "未完了";

	cout << "ステータスを " << nows << " から " << s << " に変更しました" << endl << endl;
	this->status = status;
}

void Task::SetPIC(unsigned int PIC)
{
	cout << "担当者を ";
	PersonManager::GetInstance()->Draw(this->PIC);
	cout << " から ";
	PersonManager::GetInstance()->Draw(PIC);
	cout << " に変更しました" << endl << endl;
	this->PIC = PIC;
}

void Task::SetTaskName(std::string taskName)
{
	cout << "名前を " << this->taskName << " から " << taskName << " に変更しました" << endl << endl;
	this->taskName = taskName;
}

void Task::SetPriority(std::string priority)
{
	cout << "重要度を " << this->priority << " から " << priority << " に変更しました" << endl << endl;
	this->priority = priority;
}

void Task::SetContent(std::string content)
{
	cout << "内容を " << this->content << " から " << content << " に変更しました" << endl << endl;
	this->content = content;
}

void Task::SetDeadLine(Date deadLine)
{
	cout << "期限を ";
	this->deadLine.Draw();
	cout << " から ";
	deadLine.Draw();
	cout << " に変更しました" << endl << endl;
	this->deadLine = deadLine;
}

void Task::Draw()
{
	cout << "タスク : " << taskName << endl;
	cout << "記入者 : ";
	PersonManager::GetInstance()->Draw(entryP);
	cout << "担当者 : ";
	PersonManager::GetInstance()->Draw(PIC);
	cout << "重要度 : " << priority << endl;
	cout << "内容   : " << content << endl;
	string s = status ? "完了" : "未完了";
	cout << "ステータス   : " << s << endl;
	if (!status)
	{
		cout << "期限   : ";
		deadLine.Draw();
		int d = deadLine.DaysDifference();
		if (d >= 0)
		{
			cout << "残り日数: " << d << endl;
		}
		else if (d < 0)
		{
			cout << "超過日数" << -d << endl;
		}
		cout << endl << endl;
	}
}

void Task::DrawID()
{
	cout << taskId << " : " << taskName << endl;
}

unsigned int Task::GetID()
{
	return taskId;
}
