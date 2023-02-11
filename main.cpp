#include <cstdlib>
#include <iostream>
#include "PersonManager.h"
#include "TaskManager.h"

void main()
{
	Date::SetToday();
	PersonManager* pm = PersonManager::GetInstance();
	TaskManager* tm = TaskManager::GetInstance();

	pm->AddPerson();
	pm->AddPerson();

	tm->AddTask();
	tm->AddTask();
	tm->Draw();
	tm->DeleteTask();
	tm->Draw();
	system("PAUSE");
}