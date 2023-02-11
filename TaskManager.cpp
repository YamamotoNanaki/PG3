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

	cout << "�^�X�N��ǉ����܂�" << endl;
	cout << "�L���҂�ID����͂��Ă�������" << endl;
	cout << "�L�����Z���̏ꍇ��0����͂��Ă�������" << endl << endl;
	pm->DrawID();

	cin >> id;
	cout << endl;
	if (id == 0)
	{
		cout << "�L�����Z�����܂���" << endl << endl;
		return;
	}
	while (!pm->IDCheck(id))
	{
		cout << "ID�����݂��܂���" << endl;
		cout << "�ē��͂��Ă�������" << endl;
		cout << "�L�����Z���̏ꍇ��0����͂��Ă�������" << endl << endl;
		pm->DrawID();
		cin >> id;
		cout << endl;
		if (id == 0)
		{
			cout << "�L�����Z�����܂���" << endl << endl;
			return;
		}
	}

	cout << "�S���҂�ID����͂��Ă�������" << endl;
	cin >> pic;
	cout << endl;
	if (pic == 0)
	{
		cout << "�L�����Z�����܂���" << endl << endl;
		return;
	}
	while (!pm->IDCheck(pic))
	{
		cout << "ID�����݂��܂���" << endl;
		cout << "�ē��͂��Ă�������" << endl << endl;
		pm->DrawID();
		cin >> pic;
		cout << endl;
	}

	cout << "�^�X�N�̖��O����͂��Ă�������" << endl << endl;
	cin >> taskName;
	cout << "�^�X�N�̓��e����͂��Ă�������" << endl << endl;
	cin >> content;
	cout << "�^�X�N�̏d�v�x����͂��Ă�������" << endl << endl;
	cin >> priority;
	cout << "�^�X�N�̊�������͂��Ă�������" << endl << endl;
	deadLine.Set();
	unsigned int next = 0;
	for (int i = 0; i < nextID.size(); i++)
	{
		if (nextID[i])
		{
			next = i + 1;
			break;
		}
	}
	if (next == 0)
	{
		next = nextID.size() + 1;
	}
	tasks.push_back(make_unique<Task>(next, id, pic, taskName, content, priority, deadLine));
	nextID.push_back(false);
	cout << endl << endl;
}

void TaskManager::SetTaskName()
{
	unsigned int num;
	for (unique_ptr<Task>& itr : tasks)
	{
		itr.get()->DrawID();
	}

	cout << endl;
	cout << "�^�X�N����ύX���܂�" << endl;
	cout << "�ύX����^�X�N��ID����͂��Ă�������" << endl;
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
		cout << "ID��������܂���ł���" << endl;
		cout << "������L�����Z�����܂�" << endl << endl;
		return;
	}
	string name;
	cout << "���O����͂��Ă�������" << endl << endl;
	cin >> name;
	cout << endl;
	for (unique_ptr<Task>& itr : tasks)
	{
		if (itr.get()->GetID() == num)
		{
			itr.get()->SetTaskName(name);

			cout << endl;
			return;
		}
	}
	cout << "���炩�̃G���[�ɂ��ύX�ł��܂���ł���" << endl << endl;
}

void TaskManager::SetPIC()
{
	unsigned int num;
	for (unique_ptr<Task>& itr : tasks)
	{
		itr.get()->DrawID();
	}

	cout << endl;
	cout << "�S���҂�ύX���܂�" << endl;
	cout << "�ύX����^�X�N��ID����͂��Ă�������" << endl;
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
		cout << "ID��������܂���ł���" << endl;
		cout << "������L�����Z�����܂�" << endl << endl;
		return;
	}
	unsigned int id;
	cout << "�S���҂�id����͂��Ă�������" << endl << endl;

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
	cout << "���炩�̃G���[�ɂ��ύX�ł��܂���ł���" << endl << endl;
}

void TaskManager::SetStatus()
{
	unsigned int num;
	for (unique_ptr<Task>& itr : tasks)
	{
		itr.get()->DrawID();
	}

	cout << endl;
	cout << "�X�e�[�^�X��ύX���܂�" << endl;
	cout << "�ύX����^�X�N��ID����͂��Ă�������" << endl;
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
		cout << "ID��������܂���ł���" << endl;
		cout << "������L�����Z�����܂�" << endl << endl;
		return;
	}
	int status;
	cout << "�X�e�[�^�X����͂��Ă�������" << endl;
	cout << "0 : ������" << endl;
	cout << "1 : ����" << endl << endl;
	cin >> status;
	cout << endl;
	while (!(status == 0 || status == 1))
	{
		cout << "���݂��Ȃ��X�e�[�^�X�ł�" << endl;
		cout << "�ē��͂��Ă�������" << endl;
		cout << "0 : ������" << endl;
		cout << "1 : ����" << endl << endl;
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
	cout << "���炩�̃G���[�ɂ��ύX�ł��܂���ł���" << endl << endl;
}

void TaskManager::SetPriority()
{
	unsigned int num;
	for (unique_ptr<Task>& itr : tasks)
	{
		itr.get()->DrawID();
	}

	cout << endl;
	cout << "�d�v�x��ύX���܂�" << endl;
	cout << "�ύX����^�X�N��ID����͂��Ă�������" << endl;
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
		cout << "ID��������܂���ł���" << endl;
		cout << "������L�����Z�����܂�" << endl << endl;
		return;
	}
	string priority;
	cout << "�d�v�x����͂��Ă�������" << endl << endl;
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
	cout << "���炩�̃G���[�ɂ��ύX�ł��܂���ł���" << endl << endl;
}

void TaskManager::SetContent()
{
	unsigned int num;
	for (unique_ptr<Task>& itr : tasks)
	{
		itr.get()->DrawID();
	}

	cout << endl;
	cout << "���e��ύX���܂�" << endl;
	cout << "�ύX����^�X�N��ID����͂��Ă�������" << endl;
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
		cout << "ID��������܂���ł���" << endl;
		cout << "������L�����Z�����܂�" << endl << endl;
		return;
	}
	string content;
	cout << "���e����͂��Ă�������" << endl << endl;
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
	cout << "���炩�̃G���[�ɂ��ύX�ł��܂���ł���" << endl << endl;
}

void TaskManager::SetDeadLine()
{
	unsigned int num;
	for (unique_ptr<Task>& itr : tasks)
	{
		itr.get()->DrawID();
	}

	cout << endl;
	cout << "������ύX���܂�" << endl;
	cout << "�ύX����^�X�N��ID����͂��Ă�������" << endl;
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
		cout << "ID��������܂���ł���" << endl;
		cout << "������L�����Z�����܂�" << endl << endl;
		return;
	}
	Date date;
	cout << "��������͂��Ă�������" << endl << endl;
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
	cout << "���炩�̃G���[�ɂ��ύX�ł��܂���ł���" << endl << endl;
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
	cout << "�^�X�N���폜���܂�" << endl;
	cout << "�폜����^�X�N��ID����͂��Ă�������" << endl;
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
	for (auto it = tasks.begin(); it != tasks.end();) {
		if (it->get()->GetID() == num) {
			it = tasks.erase(it);
			nextID[i] = true;
			for (int i = nextID.size() - 1; i >= 0; i--)
			{
				if (nextID[i])nextID.pop_back();
				else
				{
					break;
				}
			}
			cout << "�폜���������܂���" << endl << endl;
			return;
		}
		else {
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