#include "kripto.h"

using namespace std;
bool formatname(string &len)
{
	int flag = true;
	string format;
	for (auto i : len) {
		if (i == '/' || i == '?' || i == '\\' || i == '*' || i == '<' || i == '>' || i == ':')flag = false;
		else format += i;

	}
	len = format;
	return flag;
}
string initName(string& name)
{
	cout << "Выберите формат файла: " << endl;
	cout << "|1| - .txt;" << endl;
	cout << "|2| - .doc;" << endl;
	cout << "|3| - .rtf;" << endl;
	int ans = 0;
	cin >> ans;
	switch (ans)
	{
	case 1:
		return name + ".txt";
		break;
	case 2:
		return name + ".doc";
		break;
	case 3:
		return name + ".rtf";
		break;
	}

}
