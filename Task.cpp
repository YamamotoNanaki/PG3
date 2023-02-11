#include "Task.h"
#include "PersonManager.h"
#include <iostream>

using namespace std;

Task::Task(unsigned int taskId, unsigned int entryP, unsigned int PIC, std::string taskName, std::string content, std::string priority, Date deadLine)
	:taskId(taskId), entryP(entryP), PIC(PIC), taskName(taskName), content(content), priority(priority), deadLine(deadLine) {}

void Task::SetStatus(bool status)
{
	string nows = this->status ? "����" : "������";
	string s = status ? "����" : "������";

	cout << "�X�e�[�^�X�� " << nows << " ���� " << s << " �ɕύX���܂���" << endl << endl;
	this->status = status;
}

void Task::SetPIC(unsigned int PIC)
{
	cout << "�S���҂� ";
	PersonManager::GetInstance()->Draw(this->PIC);
	cout << " ���� ";
	PersonManager::GetInstance()->Draw(PIC);
	cout << " �ɕύX���܂���" << endl << endl;
	this->PIC = PIC;
}

void Task::SetTaskName(std::string taskName)
{
	cout << "���O�� " << this->taskName << " ���� " << taskName << " �ɕύX���܂���" << endl << endl;
	this->taskName = taskName;
}

void Task::SetPriority(std::string priority)
{
	cout << "�d�v�x�� " << this->priority << " ���� " << priority << " �ɕύX���܂���" << endl << endl;
	this->priority = priority;
}

void Task::SetContent(std::string content)
{
	cout << "���e�� " << this->content << " ���� " << content << " �ɕύX���܂���" << endl << endl;
	this->content = content;
}

void Task::SetDeadLine(Date deadLine)
{
	cout << "������ ";
	this->deadLine.Draw();
	cout << " ���� ";
	deadLine.Draw();
	cout << " �ɕύX���܂���" << endl << endl;
	this->deadLine = deadLine;
}

void Task::Draw()
{
	cout << "�^�X�N : " << taskName << endl;
	cout << "�L���� : ";
	PersonManager::GetInstance()->Draw(entryP);
	cout << "�S���� : ";
	PersonManager::GetInstance()->Draw(PIC);
	cout << "�d�v�x : " << priority << endl;
	cout << "���e   : " << content << endl;
	string s = status ? "����" : "������";
	cout << "�X�e�[�^�X   : " << s << endl;
	if (!status)
	{
		cout << "����   : ";
		deadLine.Draw();
		int d = deadLine.DaysDifference();
		if (d >= 0)
		{
			cout << "�c�����: " << d << endl;
		}
		else if (d < 0)
		{
			cout << "���ߓ���" << -d << endl;
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
