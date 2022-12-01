#include "IFList.h"
#include <functional>
#include <string>

using namespace IF;
using namespace std;

int OperationList(List<string>& list)
{
	int n;
	cout << "1.要素の表示 " << endl;
	cout << "2.要素の挿入 " << endl;
	if (!list.Empty())
	{
		cout << "3.要素の編集 " << endl;
		cout << "4.要素の削除 " << endl;
	}
	cout << endl;
	cout << "---------------------------" << endl;
	cout << "操作を選択してください" << endl;
	cin >> n;
	cout << endl;
	return n - 1;
}

bool DisplayAll(List<string>& list)
{
	cout << "要素一覧 :" << endl << "{" << endl;
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
	if (list.Size() == 0)
	{
		cout << endl << "}" << endl << endl;
	}
	cout << "要素数 : " << list.Size() << endl << endl;
	cout << "---------------------------" << endl;
	int n;
	cout << "1.要素の表示に戻る " << endl;
	cout << "2.要素の操作に戻る " << endl;
	cout << endl;
	cout << "操作を選択してください" << endl;
	cin >> n;
	cout << endl;
	return n - 1;
}

bool DisplayNum(List<string>& list)
{
	cout << "表示したい要素の順番を指定してください " << endl;
	int n;
	cin >> n;
	cout << endl;
	cout << n << " : " << list[n] << endl << endl;
	cout << "1.要素の表示に戻る " << endl;
	cout << "2.要素の操作に戻る " << endl << endl;
	cout << "操作を選択してください" << endl;
	cin >> n;
	cout << endl;
	return n - 1;
}

void DisplayList(List<string>& list)
{
	while (true)
	{
		int n;
		cout << "1.要素の一覧表示 " << endl;
		cout << "2.順番を指定して要素を表示 " << endl;
		cout << "9.要素操作に戻る " << endl << endl;
		cout << "---------------------------" << endl;
		cout << "操作を選択してください" << endl;
		cin >> n;
		cout << endl;
		system("cls");
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
		system("cls");
	}
}

void InsertList(List<string>& list)
{
	string instr;
	cout << "要素を追加する場所を指定してください。最後尾に追加する場合は何も入力しないでください " << endl;
	string str;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	getline(cin, instr);
	cout << endl;
	cout << endl;
	cout << "追加する要素の値を入力してください " << endl;
	cin >> str;
	cout << endl;
	if (instr == "\0")
	{
		list.PushBack(str);
		int i = list.Size() - 1;
		cout << "要素" << list[i] << "が" << i << "番目に挿入されました " << endl << endl;
		cout << endl << "9.要素操作に戻る " << endl << endl;
		cout << "---------------------------" << endl;
		cout << "操作を選択してください" << endl;
		cin >> i;
		return;
	}
	int i = std::stoi(instr);
	if (i > list.Size())
	{
		list.PushBack(str);
		i = list.Size() - 1;
	}
	else
	{
		list.Insert(str, i);
	}
	cout << "要素" << list[i] << "が" << i << "番目に挿入されました " << endl << endl;
	cout << endl << "9.要素操作に戻る " << endl << endl;
	cout << "---------------------------" << endl;
	cout << "操作を選択してください" << endl;
	cin >> i;
	return;
	cout << endl;
}

void DeleteList(List<string>& list)
{
	int i;
	cout << "削除したい要素の番号を指定してください " << endl;
	cin >> i;
	cout << endl;
	if (i > list.Size())
	{
		cout << i << "番目の要素が見つかりませんでした" << endl;
	}
	else
	{
		cout << i << "番目の要素" << list.Erase(i) << "を削除しました " << endl << endl;
	}
	cout << endl << "9.要素操作に戻る " << endl << endl;
	cout << "---------------------------" << endl;
	cout << "操作を選択してください" << endl;
	cout << endl;
}

void EditList(List<string>& list)
{
	int i;
	cout << "編集したい要素の番号を指定してください " << endl;
	cin >> i;
	if (i < list.Size())
	{
		string str;
		cout << i << "番目の要素の変更する値を入力してください " << endl;
		cin >> str;
		cout << endl;
		list[i] = str;
		cout << i << "番目の要素が" << list[i] << "に変更されました" << endl << endl;
	}
	else
	{
		cout << i << "番目の要素が見つかりませんでした" << endl << endl;
	}
	cout << endl << "9.要素操作に戻る " << endl << endl;
	cout << "---------------------------" << endl;
	cout << "操作を選択してください" << endl;
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
		system("cls");
		f[n](list);
		system("cls");
	}

	system("pause");
	return 0;
}