#include "TaskManager.h"
#include "PersonManager.h"
#include <iostream>

using namespace std;

TaskManager::~TaskManager()
{
	tasks.clear();
}

TaskManager* TaskManager::GetInstance()
{
	static TaskManager inst;
	return &inst;
}

void TaskManager::AddTask()
{
	unsigned int id;
	unsigned int pic;
	string taskName;
	string content;
	string priority;
	Date deadLine;
	PersonManager* pm = PersonManager::GetInstance();

	cout << "タスクを追加します" << endl;
	cout << "記入者のIDを入力してください" << endl;
	cout << "キャンセルの場合は0を入力してください" << endl << endl;
	pm->DrawID();

	cin >> id;
	cout << endl;
	if (id == 0)
	{
		cout << "キャンセルしました" << endl << endl;
		return;
	}
	while (!pm->IDCheck(id))
	{
		cout << "IDが存在しません" << endl;
		cout << "再入力してください" << endl;
		cout << "キャンセルの場合は0を入力してください" << endl << endl;
		pm->DrawID();
		cin >> id;
		cout << endl;
		if (id == 0)
		{
			cout << "キャンセルしました" << endl << endl;
			return;
		}
	}

	cout << "担当者のIDを入力してください" << endl;
	cin >> pic;
	cout << endl;
	if (pic == 0)
	{
		cout << "キャンセルしました" << endl << endl;
		return;
	}
	while (!pm->IDCheck(pic))
	{
		cout << "IDが存在しません" << endl;
		cout << "再入力してください" << endl << endl;
		pm->DrawID();
		cin >> pic;
		cout << endl;
	}

	cout << "タスクの名前を入力してください" << endl << endl;
	cin >> taskName;
	cout << "タスクの内容を入力してください" << endl << endl;
	cin >> content;
	cout << "タスクの重要度を入力してください" << endl << endl;
	cin >> priority;
	cout << "タスクの期限を入力してください" << endl << endl;
	deadLine.Set();
	unsigned int next = 1;
	for (next; next < tasks.size() + 1; next++)
	{
		for (auto it = tasks.begin(); it != tasks.end();)
		{
			if (it->get()->GetID() == next)
			{
				break;
			}
			else
			{
				++it;
			}
		}
	}
	tasks.push_back(make_unique<Task>(next, id, pic, taskName, content, priority, deadLine));
	cout << endl << endl;
}

//void TaskManager::SetTaskName()
//{
//	unsigned int num;
//	for (unique_ptr<Task>& itr : tasks)
//	{
//		itr.get()->DrawID();
//	}
//
//	cout << endl;
//	cout << "タスク名を変更します" << endl;
//	cout << "変更するタスクのIDを入力してください" << endl;
//	cout << "操作をキャンセルする場合0を入力してください" << endl << endl;
//	cin >> num;
//	cout << endl;
//
//	if (num == 0)
//	{
//		cout << "操作をキャンセルします" << endl << endl;
//		return;
//	}
//	cout << endl;
//	bool flag = false;
//	for (unique_ptr<Task>& itr : tasks)
//	{
//		if (itr.get()->GetID() == num)
//		{
//			flag = true;
//			break;
//		}
//	}
//	if (!flag)
//	{
//		cout << "IDが見つかりませんでした" << endl;
//		cout << "操作をキャンセルします" << endl << endl;
//		return;
//	}
//	string name;
//	cout << "名前を入力してください" << endl << endl;
//	cin >> name;
//	cout << endl;
//	for (unique_ptr<Task>& itr : tasks)
//	{
//		if (itr.get()->GetID() == num)
//		{
//			itr.get()->SetTaskName(name);
//
//			cout << endl;
//			return;
//		}
//	}
//	cout << "何らかのエラーにより変更できませんでした" << endl << endl;
//}

void TaskManager::SetPIC()
{
	unsigned int num;
	for (unique_ptr<Task>& itr : tasks)
	{
		itr.get()->DrawID();
	}

	cout << endl;
	cout << "担当者を変更します" << endl;
	cout << "変更するタスクのIDを入力してください" << endl;
	cout << "操作をキャンセルする場合0を入力してください" << endl << endl;
	cin >> num;
	cout << endl;

	if (num == 0)
	{
		cout << "操作をキャンセルします" << endl << endl;
		return;
	}
	cout << endl;
	bool flag = false;
	for (unique_ptr<Task>& itr : tasks)
	{
		if (itr.get()->GetID() == num)
		{
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		cout << "IDが見つかりませんでした" << endl;
		cout << "操作をキャンセルします" << endl << endl;
		return;
	}
	unsigned int id;
	cout << "担当者のidを入力してください" << endl << endl;

	PersonManager::GetInstance()->DrawID();
	cout << endl;
	cin >> id;
	cout << endl;
	for (unique_ptr<Task>& itr : tasks)
	{
		if (itr.get()->GetID() == num)
		{
			itr.get()->SetPIC(id);

			cout << endl;
			return;
		}
	}
	cout << "何らかのエラーにより変更できませんでした" << endl << endl;
}

void TaskManager::SetStatus()
{
	unsigned int num;
	for (unique_ptr<Task>& itr : tasks)
	{
		itr.get()->DrawID();
	}

	cout << endl;
	cout << "ステータスを変更します" << endl;
	cout << "変更するタスクのIDを入力してください" << endl;
	cout << "操作をキャンセルする場合0を入力してください" << endl << endl;
	cin >> num;
	cout << endl;

	if (num == 0)
	{
		cout << "操作をキャンセルします" << endl << endl;
		return;
	}
	cout << endl;
	bool flag = false;
	for (unique_ptr<Task>& itr : tasks)
	{
		if (itr.get()->GetID() == num)
		{
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		cout << "IDが見つかりませんでした" << endl;
		cout << "操作をキャンセルします" << endl << endl;
		return;
	}
	int status;
	cout << "ステータスを入力してください" << endl;
	cout << "0 : 未完了" << endl;
	cout << "1 : 完了" << endl << endl;
	cin >> status;
	cout << endl;
	while (!(status == 0 || status == 1))
	{
		cout << "存在しないステータスです" << endl;
		cout << "再入力してください" << endl;
		cout << "0 : 未完了" << endl;
		cout << "1 : 完了" << endl << endl;
		cin >> status;
		cout << endl;
	}
	for (unique_ptr<Task>& itr : tasks)
	{
		if (itr.get()->GetID() == num)
		{
			itr.get()->SetStatus(status);

			cout << endl;
			return;
		}
	}
	cout << "何らかのエラーにより変更できませんでした" << endl << endl;
}

void TaskManager::SetPriority()
{
	unsigned int num;
	for (unique_ptr<Task>& itr : tasks)
	{
		itr.get()->DrawID();
	}

	cout << endl;
	cout << "重要度を変更します" << endl;
	cout << "変更するタスクのIDを入力してください" << endl;
	cout << "操作をキャンセルする場合0を入力してください" << endl << endl;
	cin >> num;
	cout << endl;

	if (num == 0)
	{
		cout << "操作をキャンセルします" << endl << endl;
		return;
	}
	cout << endl;
	bool flag = false;
	for (unique_ptr<Task>& itr : tasks)
	{
		if (itr.get()->GetID() == num)
		{
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		cout << "IDが見つかりませんでした" << endl;
		cout << "操作をキャンセルします" << endl << endl;
		return;
	}
	string priority;
	cout << "重要度を入力してください" << endl << endl;
	cin >> priority;
	cout << endl;
	for (unique_ptr<Task>& itr : tasks)
	{
		if (itr.get()->GetID() == num)
		{
			itr.get()->SetPriority(priority);

			cout << endl;
			return;
		}
	}
	cout << "何らかのエラーにより変更できませんでした" << endl << endl;
}

void TaskManager::SetContent()
{
	unsigned int num;
	for (unique_ptr<Task>& itr : tasks)
	{
		itr.get()->DrawID();
	}

	cout << endl;
	cout << "内容を変更します" << endl;
	cout << "変更するタスクのIDを入力してください" << endl;
	cout << "操作をキャンセルする場合0を入力してください" << endl << endl;
	cin >> num;
	cout << endl;

	if (num == 0)
	{
		cout << "操作をキャンセルします" << endl << endl;
		return;
	}
	cout << endl;
	bool flag = false;
	for (unique_ptr<Task>& itr : tasks)
	{
		if (itr.get()->GetID() == num)
		{
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		cout << "IDが見つかりませんでした" << endl;
		cout << "操作をキャンセルします" << endl << endl;
		return;
	}
	string content;
	cout << "内容を入力してください" << endl << endl;
	cin >> content;
	cout << endl;
	for (unique_ptr<Task>& itr : tasks)
	{
		if (itr.get()->GetID() == num)
		{
			itr.get()->SetContent(content);

			cout << endl;
			return;
		}
	}
	cout << "何らかのエラーにより変更できませんでした" << endl << endl;
}

void TaskManager::SetDeadLine()
{
	unsigned int num;
	for (unique_ptr<Task>& itr : tasks)
	{
		itr.get()->DrawID();
	}

	cout << endl;
	cout << "期限を変更します" << endl;
	cout << "変更するタスクのIDを入力してください" << endl;
	cout << "操作をキャンセルする場合0を入力してください" << endl << endl;
	cin >> num;
	cout << endl;

	if (num == 0)
	{
		cout << "操作をキャンセルします" << endl << endl;
		return;
	}
	cout << endl;
	bool flag = false;
	for (unique_ptr<Task>& itr : tasks)
	{
		if (itr.get()->GetID() == num)
		{
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		cout << "IDが見つかりませんでした" << endl;
		cout << "操作をキャンセルします" << endl << endl;
		return;
	}
	Date date;
	cout << "期限を入力してください" << endl << endl;
	date.Set();
	for (unique_ptr<Task>& itr : tasks)
	{
		if (itr.get()->GetID() == num)
		{
			itr.get()->SetDeadLine(date);

			cout << endl;
			return;
		}
	}
	cout << "何らかのエラーにより変更できませんでした" << endl << endl;
}

void TaskManager::Draw()
{
	for (unique_ptr<Task>& itr : tasks)
	{
		itr.get()->Draw();
	}
}

void TaskManager::DeleteTask()
{
	unsigned int num;
	for (unique_ptr<Task>& itr : tasks)
	{
		itr.get()->DrawID();
	}

	cout << endl;
	cout << "タスクを削除します" << endl;
	cout << "削除するタスクのIDを入力してください" << endl;
	cout << "操作をキャンセルする場合0を入力してください" << endl << endl;
	cin >> num;
	cout << endl;

	if (num == 0)
	{
		cout << "操作をキャンセルします" << endl << endl;
		return;
	}
	cout << endl;
	bool flag = false;
	int i = 0;
	for (auto it = tasks.begin(); it != tasks.end();) {
		if (it->get()->GetID() == num) {
			it = tasks.erase(it);
			cout << "削除が完了しました" << endl << endl;
			return;
		}
		else {
			++it;
			i++;
		}
	}
	if (!flag)
	{
		cout << "IDが見つかりませんでした" << endl;
		cout << "操作をキャンセルします" << endl << endl;
		return;
	}
}

void TaskManager::OutPut()
{
	ofstream writing_file;
	string faile = "Task.json";
	writing_file.open(faile, ios::out);
	for (unique_ptr<Task>& itr : tasks)
	{
		itr.get()->OutPut(writing_file);
	}
	writing_file.close();
}

void TaskManager::InPut()
{
	ifstream reading_file;
	string faile = "Task.json";
	reading_file.open(faile, ios::out);
	string str;
	string taskName;
	string content;
	string priority;
	bool status;
	unsigned int taskId;
	unsigned int entryP;
	unsigned int PIC;
	unsigned short deadLineYear = 0;
	unsigned short deadLineMonth = 0;
	while (getline(reading_file, str))
	{
		if (str == "id")
		{
			getline(reading_file, str);
			taskId = std::stoi(str);
		}
		else if (str == "taskName")
		{
			getline(reading_file, str);
			taskName = str;
		}
		else if (str == "content")
		{
			getline(reading_file, str);
			content = str;
		}
		else if (str == "priority")
		{
			getline(reading_file, str);
			priority = str;
		}
		else if (str == "entryP")
		{
			getline(reading_file, str);
			entryP = std::stoi(str);
		}
		else if (str == "PIC")
		{
			getline(reading_file, str);
			PIC = std::stoi(str);
		}
		else if (str == "status")
		{
			getline(reading_file, str);
			status = std::stoi(str);
		}
		else if (str == "deadLineYear")
		{
			getline(reading_file, str);
			deadLineYear = std::stoi(str);
		}
		else if (str == "deadLineMonth")
		{
			getline(reading_file, str);
			deadLineMonth = std::stoi(str);
		}
		else if (str == "deadLineDay")
		{
			getline(reading_file, str);
			Date date;
			date.day = std::stoi(str);
			date.month = deadLineMonth;
			date.year = deadLineYear;
			tasks.push_back(make_unique<Task>(taskId, entryP, PIC, taskName, content, priority, date, status));
		}
	}
	reading_file.close();
}
