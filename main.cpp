#include "IFList.h"
#include <functional>
#include <string>

using namespace IF;
using namespace std;

int OperationList(List<string>& list)
{
	int n;
	cout << "0.�v�f�̕\�� " << endl;
	cout << "1.�v�f�̑}�� " << endl;
	if (!list.Empty())
	{
		cout << "2.�v�f�̕ҏW " << endl;
		cout << "3.�v�f�̍폜 " << endl;
	}
	cout << endl;
	cout << "---------------------------" << endl;
	cout << "�����I�����Ă�������" << endl;
	cin >> n;
	cout << endl;
	return n;
}

bool DisplayAll(List<string>& list)
{
	cout << "�v�f�ꗗ " << endl;
	list.Print();
	cout << endl;
	cout << list.Size() << endl;
	cout << endl;
	cout << "---------------------------" << endl;
	int n;
	cout << "0.�v�f�̕\���ɖ߂� " << endl;
	cout << "1.�v�f�̑���ɖ߂� " << endl;
	cout << endl;
	cout << "�����I�����Ă�������" << endl;
	cin >> n;
	cout << endl;
	return n;
}

bool DisplayNum(List<string>& list)
{
	cout << "�\���������v�f�̏��Ԃ��w�肵�Ă������� " << endl;
	int n;
	cin >> n;
	cout << endl;
	cout << n << "�Ԗڂ̗v�f��" << list[n] << "�ł�" << endl;
	cout << endl;
	cout << "0.�v�f�̕\���ɖ߂� " << endl;
	cout << "1.�v�f�̑���ɖ߂� " << endl;
	cout << endl;
	cout << "�����I�����Ă�������" << endl;
	cin >> n;
	cout << endl;
	return n;
}

void DisplayList(List<string>& list)
{
	while (true)
	{
		int n;
		cout << "1.�v�f�̈ꗗ�\�� " << endl;
		cout << "2.���Ԃ��w�肵�ėv�f��\�� " << endl;
		cout << "9.�v�f����ɖ߂� " << endl;
		cout << endl;
		cout << "---------------------------" << endl;
		cout << "�����I�����Ă�������" << endl;
		cin >> n;
		cout << endl;
		if (n == 1)
		{
			bool a = DisplayAll(list);
			if (a)return;
		}
		else if (n == 2)
		{
			bool a = DisplayNum(list);
			if (a)return;
		}
		else return;
	}
}

void InsertList(List<string>& list)
{
	string str;
	int i;
	cout << "�v�f��ǉ�����ꏊ���w�肵�Ă��������B�Ō���ɒǉ�����ꍇ��-1���A�擪�ɒǉ�����ꍇ��-2����͂��Ă������� " << endl;
	cin >> i;
	cout << endl;
	if (i > list.Size() && !(i == -1 || i == -2))
	{
		cout << i << "�Ԗڂ̗v�f��������܂���ł���" << endl;
		cout << endl;
		return;
	}
	cout << endl;
	cout << "�ǉ�����v�f�̒l����͂��Ă������� " << endl;
	cin >> str;
	cout << endl;
	if (i == -1)
	{
		list.PushBack(str);
		cout << "�v�f" << list[list.Size() - 1] << "��" << "�Ō���ɒǉ�����܂��� " << endl;
	}
	else if (i == -2)
	{
		list.PushFront(str);
		cout << "�v�f" << list[0] << "��" << "�擪�ɒǉ�����܂��� " << endl;
	}
	else
	{
		list.Insert(str, i);
		cout << "�v�f" << list[i] << "��" << i << "�Ԗڂɑ}������܂��� " << endl;
	}
	cout << endl;
}

void DeleteList(List<string>& list)
{
	int i;
	cout << "�폜�������v�f�̔ԍ����w�肵�Ă������� " << endl;
	cin >> i;
	cout << endl;
	if (i > list.Size())
	{
		cout << i << "�Ԗڂ̗v�f��������܂���ł���" << endl;
	}
	else
	{
		cout << i << "�Ԗڂ̗v�f" << list.Erase(i) << "���폜���܂��� " << endl;
	}
	cout << endl;
}

void EditList(List<string>& list)
{
	int i;
	cout << "�ҏW�������v�f�̔ԍ����w�肵�Ă������� " << endl;
	cin >> i;
	if (i < list.Size())
	{
		string str;
		cout << i << "�Ԗڂ̗v�f�̕ύX����l����͂��Ă������� " << endl;
		cin >> str;
		cout << endl;
		list[i] = str;
		cout << i << "�Ԗڂ̗v�f��" << list[i] << "�ɕύX����܂���" << endl;
	}
	else
	{
		cout << i << "�Ԗڂ̗v�f��������܂���ł���" << endl;
	}
	cout << endl;
}

int main()
{
	int n;
	List<string> list;
	std::function<void(List<string>&)>f[4] = { DisplayList,InsertList,EditList,DeleteList };

	while (true)
	{
		n = OperationList(list);
		f[n](list);
	}

	system("pause");
	return 0;
}