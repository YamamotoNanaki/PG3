#include <cstdlib>
#include <iostream>
#include "PersonManager.h"
#include "TaskManager.h"

using namespace std;

void main()
{
	Date::SetToday();
	PersonManager* pm = PersonManager::GetInstance();
	TaskManager* tm = TaskManager::GetInstance();
	pm->InPut();
	tm->InPut();
	int decision = 1;
	while (decision != 0)
	{
		std::system("cls");
		size_t psize = pm->GetPeopleSize();
		bool flag = true;
		int decisionMax = 2;
		if (psize == 0)
		{
			flag = false;
			decisionMax = 1;
		}
		cout << "タスク管理システム" << endl << endl;
		cout << "操作したい内容を選んでください" << endl;
		cout << "1 : 担当者操作" << endl;
		if (flag)cout << "2 : タスク操作" << endl;
		cout << "0 : 終了" << endl;
		cin >> decision;
		cout << endl;
		while (!(decision >= 0 && decision <= decisionMax))
		{
			cout << "操作が存在しません" << endl;
			cout << "再入力してください" << endl;
			cout << "1 : 担当者操作" << endl;
			cout << "2 : タスク操作" << endl;
			cout << "0 : 終了" << endl;
			cin >> decision;
			cout << endl;
		}
		std::system("cls");
		if (decision == 1)
		{
			cout << "担当者管理" << endl << endl;
			cout << "操作したい内容を選んでください" << endl;
			cout << "1 : 担当者の追加" << endl;
			cout << "2 : 担当者の内容変更" << endl;
			cout << "3 : 担当者の削除" << endl;
			cout << "4 : 担当者を全て表示" << endl;
			cin >> decision;
			cout << endl;
			while (!(decision >= 1 && decision <= 4))
			{
				cout << "操作が存在しません" << endl;
				cout << "再入力してください" << endl;
				cout << "1 : 担当者の追加" << endl;
				cout << "2 : 担当者の内容変更" << endl;
				cout << "3 : 担当者の削除" << endl;
				cout << "4 : 担当者を全て表示" << endl;
				cin >> decision;
				cout << endl;
			}
			std::system("cls");
			if (decision == 1)
			{
				pm->AddPerson();
			}
			else if (decision == 2)
			{
				cout << "担当者の内容変更" << endl << endl;
				cout << "操作したい内容を選んでください" << endl;
				cout << "1 : 担当者の氏名変更" << endl;
				cout << "2 : 担当者の出席番号変更" << endl;
				cout << "3 : 担当者のクラス変更" << endl;
				cout << "4 : 担当者の全ての要素を変更" << endl;
				cin >> decision;
				cout << endl;
				while (!(decision >= 1 && decision <= 4))
				{
					cout << "担当者の内容変更" << endl << endl;
					cout << "操作したい内容を選んでください" << endl;
					cout << "1 : 担当者の氏名変更" << endl;
					cout << "2 : 担当者の出席番号変更" << endl;
					cout << "3 : 担当者のクラス変更" << endl;
					cout << "4 : 担当者の全ての要素を変更" << endl;
					cin >> decision;
					cout << endl;
				}
				std::system("cls");
				if (decision == 1)
				{
					pm->SetName();
				}
				else if (decision == 2)
				{
					pm->SetAttendance();
				}
				else if (decision == 3)
				{
					pm->SetClassName();
				}
				else if (decision == 4)
				{
					pm->SetAllChange();
				}
			}
			else if (decision == 3)
			{
				pm->DeletePerson();
			}
			else if (decision == 4)
			{
				pm->Draw();
			}
			pm->OutPut();
			cout << endl;
			cout << "操作後の担当者状況" << endl;
			pm->Draw();
			system("PAUSE");
		}
		else if (decision == 2)
		{
			cout << "タスク管理" << endl << endl;
			cout << "操作したい内容を選んでください" << endl;
			cout << "1 : タスクの追加" << endl;
			cout << "2 : タスクの内容変更" << endl;
			cout << "3 : タスクの削除" << endl;
			cout << "4 : タスクを全て表示" << endl;
			cin >> decision;
			cout << endl;
			while (!(decision >= 1 && decision <= 4))
			{
				cout << "操作が存在しません" << endl;
				cout << "再入力してください" << endl;
				cout << "1 : タスクの追加" << endl;
				cout << "2 : タスクの内容変更" << endl;
				cout << "3 : タスクの削除" << endl;
				cout << "4 : タスクを全て表示" << endl;
				cin >> decision;
				cout << endl;
			}
			std::system("cls");
			if (decision == 1)
			{
				tm->AddTask();
			}
			else if (decision == 2)
			{
				cout << "タスクの内容変更" << endl << endl;
				cout << "操作したい内容を選んでください" << endl;
				cout << "1 : タスクの担当者の変更" << endl;
				cout << "2 : タスクの内容変更" << endl;
				cout << "3 : タスクの重要度変更" << endl;
				cout << "4 : タスクの期限変更" << endl;
				cout << "5 : タスクのステータス変更" << endl;
				cin >> decision;
				cout << endl;
				while (!(decision >= 1 && decision <= 5))
				{
					cout << "タスクの内容変更" << endl << endl;
					cout << "操作したい内容を選んでください" << endl;
					cout << "1 : タスクの担当者の変更" << endl;
					cout << "2 : タスクの内容変更" << endl;
					cout << "3 : タスクの重要度変更" << endl;
					cout << "4 : タスクの期限変更" << endl;
					cout << "5 : タスクのステータス変更" << endl;
					cin >> decision;
					cout << endl;
				}
				std::system("cls");
				if (decision == 1)
				{
					tm->SetPIC();
				}
				else if (decision == 2)
				{
					tm->SetContent();
				}
				else if (decision == 3)
				{
					tm->SetPriority();
				}
				else if (decision == 4)
				{
					tm->SetDeadLine();
				}
				else if (decision == 5)
				{
					tm->SetStatus();
				}
			}
			else if (decision == 3)
			{
				tm->DeleteTask();
			}
			else if (decision == 4)
			{
				tm->Draw();
			}
			tm->OutPut();

			cout << endl;
			cout << "操作後のタスク状況" << endl;
			tm->Draw();
			system("PAUSE");
		}
	}
	system("PAUSE");
}