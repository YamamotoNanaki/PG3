#include "IFList.h"
#include <functional>
#include <string>

using namespace IF;
using namespace std;

int OperationList(List<string>& list)
{
	int n;
	cout << "1.�v�f�̕\�� " << endl;
	cout << "2.�v�f�̑}�� " << endl;
	if (!list.Empty())
	{
		cout << "3.�v�f�̕ҏW " << endl;
		cout << "4.�v�f�̍폜 " << endl;
	}
	cout << endl;
	cout << "---------------------------" << endl;
	cout << "�����I�����Ă�������" << endl;
	cin >> n;
	cout << endl;
	return n - 1;
}

bool DisplayAll(List<string>& list)
{
	cout << "�v�f�ꗗ :" << endl << "{" << endl;
	for (int i = 0; i < list.Size(); i++)
	{
		cout << "  " << i << " : " << "\"" << list[i] << "\"";
		if (i == list.Size() - 1)
		{
			cout << endl << "}" << endl << endl;
		}
		else
		{
			cout << "," << endl;
		}
	}
	cout << "�v�f�� : " << list.Size() << endl << endl;
	cout << "---------------------------" << endl;
	int n;
	cout << "1.�v�f�̕\���ɖ߂� " << endl;
	cout << "2.�v�f�̑���ɖ߂� " << endl;
	cout << endl;
	cout << "�����I�����Ă�������" << endl;
	cin >> n;
	cout << endl;
	return n - 1;
}

bool DisplayNum(List<string>& list)
{
	cout << "�\���������v�f�̏��Ԃ��w�肵�Ă������� " << endl;
	int n;
	cin >> n;
	cout << endl;
	cout << n << " : " << list[n] << endl << endl;
	cout << "1.�v�f�̕\���ɖ߂� " << endl;
	cout << "2.�v�f�̑���ɖ߂� " << endl << endl;
	cout << "�����I�����Ă�������" << endl;
	cin >> n;
	cout << endl;
	return n - 1;
}

void DisplayList(List<string>& list)
{
	while (true)
	{
		int n;
		cout << "1.�v�f�̈ꗗ�\�� " << endl;
		cout << "2.���Ԃ��w�肵�ėv�f��\�� " << endl;
		cout << "9.�v�f����ɖ߂� " << endl << endl;
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
	string instr;
	cout << "�v�f��ǉ�����ꏊ���w�肵�Ă��������B�Ō���ɒǉ�����ꍇ�͉������͂��Ȃ��ł������� " << endl;
	string str;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	getline(cin, instr);
	cout << endl;
	cout << endl;
	cout << "�ǉ�����v�f�̒l����͂��Ă������� " << endl;
	cin >> str;
	cout << endl;
	if (instr == "\0")
	{
		list.PushBack(str);
		int i = list.Size() - 1;
		cout << "�v�f" << list[i] << "��" << i << "�Ԗڂɑ}������܂��� " << endl;
		return;
	}
	int i = std::stoi(instr);
	if (i >= list.Size())
	{
		list.PushBack(str);
		i = list.Size() - 1;
	}
	else
	{
		list.Insert(str, i);
	}
	cout << "�v�f" << list[i] << "��" << i << "�Ԗڂɑ}������܂��� " << endl;
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