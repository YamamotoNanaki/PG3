#include "IFList.h"
#include <functional>
#include <string>

using namespace IF;
using namespace std;

int OperationList(List<string>& list)
{
	int n;
	cout << "1.—v‘f‚Ì•\Ž¦ " << endl;
	cout << "2.—v‘f‚Ì‘}“ü " << endl;
	if (!list.Empty())
	{
		cout << "3.—v‘f‚Ì•ÒW " << endl;
		cout << "4.—v‘f‚Ìíœ " << endl;
	}
	cout << endl;
	cout << "---------------------------" << endl;
	cout << "‘€ì‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢" << endl;
	cin >> n;
	cout << endl;
	return n - 1;
}

bool DisplayAll(List<string>& list)
{
	cout << "—v‘fˆê—— :" << endl << "{" << endl;
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
	cout << "—v‘f” : " << list.Size() << endl << endl;
	cout << "---------------------------" << endl;
	int n;
	cout << "1.—v‘f‚Ì•\Ž¦‚É–ß‚é " << endl;
	cout << "2.—v‘f‚Ì‘€ì‚É–ß‚é " << endl;
	cout << endl;
	cout << "‘€ì‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢" << endl;
	cin >> n;
	cout << endl;
	return n - 1;
}

bool DisplayNum(List<string>& list)
{
	cout << "•\Ž¦‚µ‚½‚¢—v‘f‚Ì‡”Ô‚ðŽw’è‚µ‚Ä‚­‚¾‚³‚¢ " << endl;
	int n;
	cin >> n;
	cout << endl;
	cout << n << " : " << list[n] << endl << endl;
	cout << "1.—v‘f‚Ì•\Ž¦‚É–ß‚é " << endl;
	cout << "2.—v‘f‚Ì‘€ì‚É–ß‚é " << endl << endl;
	cout << "‘€ì‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢" << endl;
	cin >> n;
	cout << endl;
	return n - 1;
}

void DisplayList(List<string>& list)
{
	while (true)
	{
		int n;
		cout << "1.—v‘f‚Ìˆê——•\Ž¦ " << endl;
		cout << "2.‡”Ô‚ðŽw’è‚µ‚Ä—v‘f‚ð•\Ž¦ " << endl;
		cout << "9.—v‘f‘€ì‚É–ß‚é " << endl << endl;
		cout << "---------------------------" << endl;
		cout << "‘€ì‚ð‘I‘ð‚µ‚Ä‚­‚¾‚³‚¢" << endl;
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
	cout << "—v‘f‚ð’Ç‰Á‚·‚éêŠ‚ðŽw’è‚µ‚Ä‚­‚¾‚³‚¢BÅŒã”ö‚É’Ç‰Á‚·‚éê‡‚Í‰½‚à“ü—Í‚µ‚È‚¢‚Å‚­‚¾‚³‚¢ " << endl;
	string str;
	if (cin.fail())
	{
		cin.clear();
	}
	cin.ignore(1024, '\n');
	getline(cin, instr);
	cout << endl;
	cout << endl;
	cout << "’Ç‰Á‚·‚é—v‘f‚Ì’l‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ " << endl;
	cin >> str;
	cout << endl;
	if (instr == "\0")
	{
		list.PushBack(str);
		int i = list.Size() - 1;
		cout << "—v‘f" << list[i] << "‚ª" << i << "”Ô–Ú‚É‘}“ü‚³‚ê‚Ü‚µ‚½ " << endl;
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
	cout << "—v‘f" << list[i] << "‚ª" << i << "”Ô–Ú‚É‘}“ü‚³‚ê‚Ü‚µ‚½ " << endl;
	cout << endl;
}

void DeleteList(List<string>& list)
{
	int i;
	cout << "íœ‚µ‚½‚¢—v‘f‚Ì”Ô†‚ðŽw’è‚µ‚Ä‚­‚¾‚³‚¢ " << endl;
	cin >> i;
	cout << endl;
	if (i > list.Size())
	{
		cout << i << "”Ô–Ú‚Ì—v‘f‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½" << endl;
	}
	else
	{
		cout << i << "”Ô–Ú‚Ì—v‘f" << list.Erase(i) << "‚ðíœ‚µ‚Ü‚µ‚½ " << endl;
	}
	cout << endl;
}

void EditList(List<string>& list)
{
	int i;
	cout << "•ÒW‚µ‚½‚¢—v‘f‚Ì”Ô†‚ðŽw’è‚µ‚Ä‚­‚¾‚³‚¢ " << endl;
	cin >> i;
	if (i < list.Size())
	{
		string str;
		cout << i << "”Ô–Ú‚Ì—v‘f‚Ì•ÏX‚·‚é’l‚ð“ü—Í‚µ‚Ä‚­‚¾‚³‚¢ " << endl;
		cin >> str;
		cout << endl;
		list[i] = str;
		cout << i << "”Ô–Ú‚Ì—v‘f‚ª" << list[i] << "‚É•ÏX‚³‚ê‚Ü‚µ‚½" << endl;
	}
	else
	{
		cout << i << "”Ô–Ú‚Ì—v‘f‚ªŒ©‚Â‚©‚è‚Ü‚¹‚ñ‚Å‚µ‚½" << endl;
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