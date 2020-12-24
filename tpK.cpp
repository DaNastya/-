#include <iostream>
#include"kripto.h"
using namespace std;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector<cripto*> C;
	Ceasar Ces;Vishner Vis;Enigma Eni;
	string namef;
	int num = 1;
	bool inf = false;
	bool off = false;
	ifstream fin;
	fstream fout;
	int i = 0;
	while (true)
	{
		system("cls");
		cout << "Выберите откуда будет производиться запись:" << endl;
		cout << "|1| - С консоли" << endl;
		cout << "|2| - Из файла" << endl;
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
		}
		catch (const char* error) {
			cout << error << endl;
			system("pause");
			continue;
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
				C[i]->cod((inf == true) ? fin : cin,inf,off );
				i++;
				break;
			case 2:
				C.push_back(new Vishner());
				C[i]->cod((inf == true) ? fin : cin,inf ,off );
				i++;
				break;
			case 3:
				C.push_back(new Enigma());
				C[i]->cod((inf == true) ? fin : cin,inf,off);
				i++;
				break;

			default:
				cout << "Выход в меню" << endl;
				break;
			}
			system("pause");
		}
		else if (num == 2) {
			
				if (inf == false) {
					while (true) {
						try {
							if (C.size() == 0) throw "\x1b[31mВы не кодировали сообщения, выберите файл или закодируйте какое-нибудь сообщение\x1b[0m";
							cout << "Выберите сообщение для декодирования" << endl;
							for (size_t i = 0; i < C.size(); i++) {
								cout << i + 1 << "|" << endl;
								C[i]->getlen();

							}
							cin >> i;
							if (i > C.size()) throw i;
							else break;
						}
						catch (int i) {
							cout << "Ведено не верное значение, выберете сообщение под номером меньше " << C.size() << endl;
							cin >> i;
						
						}
					}
					C[i - 1]->decod(cin,false,off);
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
						C[i]->cod(fin,true,off);
						break;
					case 2:
						C.push_back(new Vishner());
						C[i]->cod(fin,true,off);

						break;
					case 3:
						C.push_back(new Enigma());
						C[i]->cod(fin,true,off);

						break;

					default:
						cout << "Выход в меню" << endl;
						break;
					}
					system("pause");

				}
			}
		else if (num == 0) {
			C.clear();
			if (inf == true)fin.close();
			if (off == true)fout.close();
			inf = off = false;
			return 0;
		}
		cout << "Хотите записать сообщение в файл?" << endl;
		cout << "|1| - Да" << endl;
		cout << "|2| - Нет" << endl;
		cin >> num;
		if (num == 1)
		{
			try {
				off = true;
				cout << "Введите название файла(без формата): " << endl;
				cin.get();
				getline(cin, namef);
				namef = initName(namef);
				if (!formatname(namef)) throw namef;

			}
			catch (string namef) {
				cout << "\x1b[31mНельзя создать файл с таким именем\x1b[0m\nИмя файла измененено на " << namef << endl;
				
			}
			fout.open(namef, ios::out);
			C[i - 1]->recording(fout);
			fout.close();
			system("pause");
		}
			
		if (inf == true)fin.close();
		inf = off = false;
	}

}
