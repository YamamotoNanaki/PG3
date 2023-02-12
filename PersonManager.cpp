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
	cout << "�l����ǉ����܂�" << endl;
	cout << "�o�Ȕԍ�����͂��Ă�������" << endl;
	cout << "�L�����Z���̏ꍇ��0����͂��Ă�������" << endl << endl;
	cin >> attendanceNum;
	if (attendanceNum == 0)
	{
		cout << "�L�����Z�����܂���" << endl << endl;
		return;
	}
	cout << endl;
	cout << "�N���X����͂��Ă�������" << endl;
	cin >> className;
	cout << endl;
	cout << "���O����͂��Ă�������" << endl;
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
	cout << "���O��ύX���܂�" << endl;
	cout << "�ύX����l����ID����͂��Ă�������" << endl;
	cout << "������L�����Z������ꍇ0����͂��Ă�������" << endl << endl;
	cin >> num;
	cout << endl;
	if (num == 0)
	{
		cout << "������L�����Z�����܂�" << endl << endl;
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
		cout << "ID��������܂���ł���" << endl;
		cout << "������L�����Z�����܂�" << endl << endl;
		return;
	}
	string name;
	cout << "���O����͂��Ă�������" << endl << endl;
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
	cout << "���炩�̃G���[�ɂ��ύX�ł��܂���ł���" << endl << endl;
}

void PersonManager::SetAttendance()
{
	unsigned int num;
	for (unique_ptr<Person>& itr : people)
	{
		itr.get()->DrawID();
	}
	cout << endl;
	cout << "�o�Ȕԍ���ύX���܂�" << endl;
	cout << "�ύX����l����ID����͂��Ă�������" << endl;
	cout << "������L�����Z������ꍇ0����͂��Ă�������" << endl << endl;
	cin >> num;
	cout << endl;
	if (num == 0)
	{
		cout << "������L�����Z�����܂�" << endl << endl;
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
		cout << "ID��������܂���ł���" << endl;
		cout << "������L�����Z�����܂�" << endl << endl;
		return;
	}
	unsigned short attendance;
	cout << "�o�Ȕԍ�����͂��Ă�������" << endl << endl;
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
	cout << "���炩�̃G���[�ɂ��ύX�ł��܂���ł���" << endl << endl;
}

void PersonManager::SetClassName()
{
	unsigned int num;
	for (unique_ptr<Person>& itr : people)
	{
		itr.get()->DrawID();
	}
	cout << endl;
	cout << "�N���X��ύX���܂�" << endl;
	cout << "�ύX����l����ID����͂��Ă�������" << endl;
	cout << "������L�����Z������ꍇ0����͂��Ă�������" << endl << endl;
	cin >> num;
	cout << endl;
	if (num == 0)
	{
		cout << "������L�����Z�����܂�" << endl << endl;
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
		cout << "ID��������܂���ł���" << endl;
		cout << "������L�����Z�����܂�" << endl << endl;
		return;
	}
	string className;
	cout << "�N���X����͂��Ă�������" << endl << endl;
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
	cout << "���炩�̃G���[�ɂ��ύX�ł��܂���ł���" << endl << endl;
}

void PersonManager::SetAllChange()
{
	unsigned int num;
	for (unique_ptr<Person>& itr : people)
	{
		itr.get()->DrawID();
	}
	cout << endl;
	cout << "�l������S�ĕύX���܂�" << endl;
	cout << "�ύX����l����ID����͂��Ă�������" << endl;
	cout << "������L�����Z������ꍇ0����͂��Ă�������" << endl << endl;
	cin >> num;
	cout << endl;
	if (num == 0)
	{
		cout << "������L�����Z�����܂�" << endl << endl;
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
		cout << "ID��������܂���ł���" << endl;
		cout << "������L�����Z�����܂�" << endl << endl;
		return;
	}
	string className;
	cout << "�N���X����͂��Ă�������" << endl << endl;
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
	cout << "�o�Ȕԍ�����͂��Ă�������" << endl << endl;
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
	cout << "���O����͂��Ă�������" << endl << endl;
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
	cout << "�o�^����Ă���l�����폜���܂�" << endl;
	cout << "�폜����l����ID����͂��Ă�������" << endl;
	cout << "������L�����Z������ꍇ0����͂��Ă�������" << endl << endl;
	cin >> num;
	cout << endl;

	if (num == 0)
	{
		cout << "������L�����Z�����܂�" << endl << endl;
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
			cout << "�폜���������܂���" << endl << endl;
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
		cout << "ID��������܂���ł���" << endl;
		cout << "������L�����Z�����܂�" << endl << endl;
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
