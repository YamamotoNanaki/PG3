#include "PersonManager.h"
#include <iostream>
#include <fstream>

using namespace std;

PersonManager::~PersonManager()
{
	people.clear();
}

PersonManager* PersonManager::GetInstance()
{
	static PersonManager inst;
	return &inst;
}

void PersonManager::AddPerson()
{
	string name;
	unsigned short attendanceNum;
	string className;
	cout << "人物を追加します" << endl;
	cout << "出席番号を入力してください" << endl;
	cout << "キャンセルの場合は0を入力してください" << endl << endl;
	cin >> attendanceNum;
	if (attendanceNum == 0)
	{
		cout << "キャンセルしました" << endl << endl;
		return;
	}
	cout << endl;
	cout << "クラスを入力してください" << endl;
	cin >> className;
	cout << endl;
	cout << "名前を入力してください" << endl;
	cin >> name;
	unsigned int next = 1;
	for (next = 1; next < people.size() + 1; next++)
	{
		bool flag = true;
		for (auto it = people.begin(); it != people.end();)
		{
			if (it->get()->GetID() == next)
			{
				flag = false;
				break;
			}
			else
			{
				++it;
			}
		}
		if (flag)
		{
			break;
		}
	}
	people.push_back(make_unique<Person>(next, name, attendanceNum, className));
	cout << endl;
	people.back().get()->Draw();
	cout << endl << endl;
}

void PersonManager::SetName()
{
	unsigned int num;
	for (unique_ptr<Person>& itr : people)
	{
		itr.get()->DrawID();
	}
	cout << endl;
	cout << "名前を変更します" << endl;
	cout << "変更する人物のIDを入力してください" << endl;
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
	for (unique_ptr<Person>& itr : people)
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
	string name;
	cout << "名前を入力してください" << endl << endl;
	cin >> name;
	cout << endl;
	for (unique_ptr<Person>& itr : people)
	{
		if (itr.get()->GetID() == num)
		{
			itr.get()->SetName(name);

			cout << endl;
			return;
		}
	}
	cout << "何らかのエラーにより変更できませんでした" << endl << endl;
}

void PersonManager::SetAttendance()
{
	unsigned int num;
	for (unique_ptr<Person>& itr : people)
	{
		itr.get()->DrawID();
	}
	cout << endl;
	cout << "出席番号を変更します" << endl;
	cout << "変更する人物のIDを入力してください" << endl;
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
	for (unique_ptr<Person>& itr : people)
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
	unsigned short attendance;
	cout << "出席番号を入力してください" << endl << endl;
	cin >> attendance;
	cout << endl;
	for (unique_ptr<Person>& itr : people)
	{
		if (itr.get()->GetID() == num)
		{
			itr.get()->SetAttendanceNum(attendance);
			cout << endl;
			return;
		}
	}
	cout << "何らかのエラーにより変更できませんでした" << endl << endl;
}

void PersonManager::SetClassName()
{
	unsigned int num;
	for (unique_ptr<Person>& itr : people)
	{
		itr.get()->DrawID();
	}
	cout << endl;
	cout << "クラスを変更します" << endl;
	cout << "変更する人物のIDを入力してください" << endl;
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
	for (unique_ptr<Person>& itr : people)
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
	string className;
	cout << "クラスを入力してください" << endl << endl;
	cin >> className;
	cout << endl;
	for (unique_ptr<Person>& itr : people)
	{
		if (itr.get()->GetID() == num)
		{
			itr.get()->SetClassName(className);
			cout << endl;
			return;
		}
	}
	cout << "何らかのエラーにより変更できませんでした" << endl << endl;
}

void PersonManager::SetAllChange()
{
	unsigned int num;
	for (unique_ptr<Person>& itr : people)
	{
		itr.get()->DrawID();
	}
	cout << endl;
	cout << "人物情報を全て変更します" << endl;
	cout << "変更する人物のIDを入力してください" << endl;
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
	for (unique_ptr<Person>& itr : people)
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
	string className;
	cout << "クラスを入力してください" << endl << endl;
	cin >> className;
	cout << endl;
	for (unique_ptr<Person>& itr : people)
	{
		if (itr.get()->GetID() == num)
		{
			itr.get()->SetClassName(className);
			break;
		}
	}
	unsigned short attendance;
	cout << "出席番号を入力してください" << endl << endl;
	cin >> attendance;
	cout << endl;
	for (unique_ptr<Person>& itr : people)
	{
		if (itr.get()->GetID() == num)
		{
			itr.get()->SetAttendanceNum(attendance);
			break;
		}
	}
	string name;
	cout << "名前を入力してください" << endl << endl;
	cin >> name;
	cout << endl;
	for (unique_ptr<Person>& itr : people)
	{
		if (itr.get()->GetID() == num)
		{
			itr.get()->SetName(name);
			break;
		}
	}
	cout << endl;
}

void PersonManager::Draw()
{
	for (unique_ptr<Person>& itr : people)
	{
		itr.get()->Draw();
	}
}

void PersonManager::Draw(unsigned int PICID)
{
	for (unique_ptr<Person>& itr : people)
	{
		if (itr.get()->GetID() == PICID)
		{
			itr.get()->Draw();
			return;
		}
	}
}

void PersonManager::DrawID()
{
	for (unique_ptr<Person>& itr : people)
	{
		itr.get()->DrawID();
	}
}

bool PersonManager::IDCheck(unsigned int PIC)
{
	for (auto& itr : people)
	{
		if (itr.get()->GetID() == PIC)
		{
			return true;
		}
	}
	return false;
}

void PersonManager::DeletePerson()
{
	unsigned int num;
	for (unique_ptr<Person>& itr : people)
	{
		itr.get()->DrawID();
	}

	cout << endl;
	cout << "登録されている人物を削除します" << endl;
	cout << "削除する人物のIDを入力してください" << endl;
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
	for (auto it = people.begin(); it != people.end();)
	{
		if (it->get()->GetID() == num)
		{
			it = people.erase(it);
			cout << "削除が完了しました" << endl << endl;
			return;
		}
		else
		{
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

size_t PersonManager::GetPeopleSize()
{
	return people.size();
}

void PersonManager::InPut()
{
	ifstream reading_file;
	string faile = "Person.txt";
	reading_file.open(faile, ios::out);
	string str;
	string className;
	string name;
	unsigned int id;
	unsigned int attendanceNum;
	while (getline(reading_file, str))
	{
		if (str == "id")
		{
			getline(reading_file, str);
			id = std::stoi(str);
		}
		else if (str == "class")
		{
			getline(reading_file, str);
			className = str;
		}
		else if (str == "attendance")
		{
			getline(reading_file, str);
			attendanceNum = std::stoi(str);
		}
		else if (str == "name")
		{
			getline(reading_file, str);
			name = str;
			people.push_back(make_unique<Person>(id, name, attendanceNum, className));
		}
	}
	reading_file.close();
}

void PersonManager::OutPut()
{
	ofstream writing_file;
	string faile = "Person.txt";
	writing_file.open(faile, ios::out);
	for (unique_ptr<Person>& itr : people)
	{
		itr.get()->OutPut(writing_file);
	}
	writing_file.close();
}
