#include "IFList.h"
#include <functional>
#include <string>

using namespace IF;
using namespace std;

int OperationList(List<string>& list)
{
	int n;
	cout << "0.要素の表示 " << endl;
	cout << "1.要素の挿入 " << endl;
	if (!list.Empty())
	{
		cout << "2.要素の編集 " << endl;
		cout << "3.要素の削除 " << endl;
	}
	cout << endl;
	cout << "---------------------------" << endl;
	cout << "操作を選択してください" << endl;
	cin >> n;
	cout << endl;
	return n;
}

bool DisplayAll(List<string>& list)
{
	cout << "要素一覧 " << endl;
	list.Print();
	cout << endl;
	cout << list.Size() << endl;
	cout << endl;
	cout << "---------------------------" << endl;
	int n;
	cout << "0.要素の表示に戻る " << endl;
	cout << "1.要素の操作に戻る " << endl;
	cout << endl;
	cout << "操作を選択してください" << endl;
	cin >> n;
	cout << endl;
	return n;
}

bool DisplayNum(List<string>& list)
{
	cout << "表示したい要素の順番を指定してください " << endl;
	int n;
	cin >> n;
	cout << endl;
	cout << n << "番目の要素は" << list[n] << "です" << endl;
	cout << endl;
	cout << "0.要素の表示に戻る " << endl;
	cout << "1.要素の操作に戻る " << endl;
	cout << endl;
	cout << "操作を選択してください" << endl;
	cin >> n;
	cout << endl;
	return n;
}

void DisplayList(List<string>& list)
{
	while (true)
	{
		int n;
		cout << "1.要素の一覧表示 " << endl;
		cout << "2.順番を指定して要素を表示 " << endl;
		cout << "9.要素操作に戻る " << endl;
		cout << endl;
		cout << "---------------------------" << endl;
		cout << "操作を選択してください" << endl;
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
	cout << "要素を追加する場所を指定してください。最後尾に追加する場合は-1を、先頭に追加する場合は-2を入力してください " << endl;
	cin >> i;
	cout << endl;
	if (i > list.Size() && !(i == -1 || i == -2))
	{
		cout << i << "番目の要素が見つかりませんでした" << endl;
		cout << endl;
		return;
	}
	cout << endl;
	cout << "追加する要素の値を入力してください " << endl;
	cin >> str;
	cout << endl;
	if (i == -1)
	{
		list.PushBack(str);
		cout << "要素" << list[list.Size() - 1] << "が" << "最後尾に追加されました " << endl;
	}
	else if (i == -2)
	{
		list.PushFront(str);
		cout << "要素" << list[0] << "が" << "先頭に追加されました " << endl;
	}
	else
	{
		list.Insert(str, i);
		cout << "要素" << list[i] << "が" << i << "番目に挿入されました " << endl;
	}
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
		cout << i << "番目の要素" << list.Erase(i) << "を削除しました " << endl;
	}
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
		cout << i << "番目の要素が" << list[i] << "に変更されました" << endl;
	}
	else
	{
		cout << i << "番目の要素が見つかりませんでした" << endl;
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