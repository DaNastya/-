#include <iostream>

#include"kripto.h"
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<cripto*> C;
	Ceasar Ces;
	Vishner Vis;
	Enigma Eni;
	string namef;
	int num = 1;
	bool inf = false;
	bool off = false;
	ifstream fin;
	fstream fout;
	int i = 0;
	while (num != 0)
	{
		system("cls");
		cout << "Выберите входной поток данных:" << endl;
		cout << "|1| - Консоль;" << endl;
		cout << "|2| - Файл;" << endl;
		cin >> num;
		try {
			if (num == 2) {
				inf = true;
				cout << "Введите название файла(без формата): " << endl;
				cin.get();
				getline(cin, namef);
				namef = initName(namef);
				fin.open(namef, ios::in);
				if (!fin.is_open())
					throw "\x1b[31mНевозможно найти файл с таким именем\x1b[0m";
			}
			cout << "Выберите выходной поток данных:" << endl;
			cout << "|1| - Консоль;" << endl;
			cout << "|2| - Файл;" << endl;
			cin >> num;
			if (num == 2)
			{
				off = true;
				cout << "Введите название файла(без формата): " << endl;
				cin.get();
				getline(cin, namef);
				namef = initName(namef);
				if (!formatname(namef)) throw namef;
				fout.open(namef, ios::out);
			}
		}
		catch (const char* error) {
			cout << error << endl;
			system("pause");
			continue;
		}
		catch (string namef) {
			cout << "\x1b[31mНельзя создать файл с таким именем\x1b[0m\nИмя файла измененено на " << namef << endl;
			fout.open(namef, ios::out);
		}
		system("pause");
		system("cls");
		cout << "Выбор операции" << endl;
		cout << "|1|-Зашифровать\n|2|-Расшифровать\n|0|-Выход из программы" << endl;
		cin >> num;
		if (num == 1) {
			cout << "|1|-Шифр Цезаря\n|2|-Шифр Вижнера\n|3|-Шифр Энигма\n|0|- для выхода\n->";
			cin >> num;

			switch (num)
			{
			case 1:
				C.push_back(new Ceasar());
				C[i]->cod(
					(inf == true) ? fin : cin,
					(off == true) ? fout : cout,
					(inf == true) ? true : false,
					(off == true) ? true : false
				);
				i++;
				break;
			case 2:
				C.push_back(new Vishner());
				C[i]->cod(
					(inf == true) ? fin : cin,
					(off == true) ? fout : cout,
					(inf == true) ? true : false,
					(off == true) ? true : false);
				i++;
				break;
			case 3:
				C.push_back(new Enigma());
				C[i]->cod(
					(inf == true) ? fin : cin,
					(off == true) ? fout : cout,
					(inf == true) ? true : false,
					(off == true) ? true : false);
				i++;
				break;

			default:
				cout << "Выход в меню" << endl;
				break;
			}
			system("pause");
		}
		else if (num == 2) {

			try {
				if (inf == false) {
					if (C.size() == 0) throw "\x1b[31mВы не кодировали сообщения, выберите файл или закодируйте какое-нибудь сообщение\x1b[0m";
					cout << "Выберите сообщение для декодирования" << endl;
					for (size_t i = 0; i < C.size(); i++) {
						cout << i + 1 << " " << C[i]->getlen() << endl;

					}
					cin >> i;
					C[i - 1]->decod(
						cin,
						(off == true) ? fout : cout,
						false,
						(off == true) ? true : false
					);
					system("pause");
				}
				else {
					cout << "Каким способом зашифрован файл" << endl;
					cout << "|1|-Шифр Цезаря\n|2|-Шифр Вижнера\n|3|-Шифр Энигма\n|0|- для выхода\n->";
					cin >> num;
					switch (num)
					{
					case 1:
						C.push_back(new Ceasar());
						C[i]->cod(
							fin,
							(off == true) ? fout : cout,
							true,
							(off == true) ? true : false
						);
						break;
					case 2:
						C.push_back(new Vishner());
						C[i]->cod(
							fin,
							(off == true) ? fout : cout,
							true,
							(off == true) ? true : false);

						break;
					case 3:
						C.push_back(new Enigma());
						C[i]->cod(
							fin,
							(off == true) ? fout : cout,
							false,
							(off == true) ? true : false);

						break;

					default:
						cout << "Выход в меню" << endl;
						break;
					
						
					}
					system("pause");

				}
			}
			catch (const char* error) {
				cout << error << endl;
			}

		}
		else if (num == 0) {
			C.clear();
			if (inf == true)fin.close();
			if (off == true)fout.close();
			inf = off = false;
			return 0;
		}
		if (inf == true)fin.close();
		if (off == true)fout.close();
		inf = off = false;
	}

}
