#include "kripto.h"
#include <conio.h>
#include <math.h>

bool cripto::format(string& len)
{
	bool flag = true;
	string s;
	for (unsigned int i = 0; i < len.size(); i++) {
		if (len[i] <= 'Z' && len[i] >= 'A' || len[i] <= 'z' && len[i] >= 'a') {
			if (len[i] <= 'Z' && len[i] >= 'A') len[i] = tolower(len[i]);
			s += len[i];
		}
		else if (len[i] <= 'Я' && len[i] >= 'А' || len[i] <= 'я' && len[i] >= 'а') flag = false;
	}
	len = s;
	return flag;
}


long Enigma::mod26(long a)//циклический сдвиг
{
	return (a % 26 + 26) % 26;
}

int Enigma::li(char l)//возвращает код буквы от 0-25
{
	return l - 'a';
}

int Enigma::indexof(char* array, int find)//вычисление индекса массива
{
	return strchr(array, find) - array;
}

void cripto::cod(istream & in,  bool iflag, bool oflag)
{
	int code = 0;
	string LINE;
	if (iflag == false)
	{
		cout << "Введите строку для кодирования:" << endl;//ввод строки с клавиатуры,
		in.ignore();
		getline(in, LINE);
		while (true) {
			try {
		//если пустая строка или строка содержит русские буквы, ввод заново
			
					if (!format(LINE)) throw "\x1b[31mСтрока содержала запрещённые символы\x1b[0m";
					if (LINE.size()==0) throw "\x1b[31mСтрока пустая\x1b[0m";
					line.push_back(LINE);
					cout << "Нажмите 'esc', чтобы закончить ввод" << endl;
					code = _getch();
					if (code == 27) {
						line = CodOrDecod(1);
						for (int j = 0; j < line.size(); j++) {

							cout << line[j] << endl;
						}
						break;
					}
					else{
						cout << "Введите строку для кодирования:" << endl;//ввод строки с клавиатуры, 
						getline(cin, LINE);
					}

			}

			catch (const char* a) {

				cout << a << endl << "Ведите строку заново" << endl;
				getline(in, LINE);
			}
		}
	}
	else
	{
		if (!in.eof()) {
			do
			{
				try {
					
						getline(in, LINE);
						if (LINE == "") throw "\x1b[31mВ файле есть пустая строка\x1b[0m";
						if (!format(LINE)) throw "\x1b[31mСтрока содержит кирилицу\x1b[0m";
						line.push_back(LINE);
						
				}
				catch (const char* error) {
					cout << error << endl;

				}
				
			} while (!in.eof());
			line = CodOrDecod(1);
			for (int j = 0; j < line.size(); j++) {
				cout << line[j] << endl;
			}
		}
		else cout << "\x1b[31mФайл пуст\x1b[0m" << endl;
	}
}

void cripto::decod(istream & in,  bool iflag, bool oflag)
{
	string LINE;
	if (oflag == false)
	{
		try {
			if (iflag == true) {
				if (!in.eof()) {
					do {
						getline(in, LINE);
						if (!format(LINE)) throw "\x1b[31mСтрока содержит кирилицу\x1b[0m";
						line.push_back(LINE);
					} while (!in.eof());
					line = CodOrDecod(0);
				}
				else throw "\x1b[31mФайл пуст";
			}
			else {
				line = CodOrDecod(0);
				cout << "Декодированная строка: " << endl;
				for (int j = 0; j < line.size(); j++) {
					cout << line[j] << endl;
				}
			}
		}
		catch (const char* error) {
			cout << error << endl;

		}
	}
	else
	{
		if (!in.eof()) {
			do
			{

				try {
					getline(in, LINE);
					if (LINE == "") throw "\x1b[31mВ файле пустая строка\x1b[0m";
					if (!format(LINE)) throw "\x1b[31mСтрока содержит кирилицу\x1b[0m";
					line.push_back(LINE);
				}
				catch (const char* error) {
					cout << error << endl;

				}
				CodOrDecod(0);
			} while (!in.eof());
		}
		else cout << "\x1b[31mФайл пуст\x1b[0m" << endl;

	}
}

void cripto::getlen()
{
	for (int i = 0; i < line.size(); i++) {
		cout << line[i] << endl;
	}
}

void cripto::recording(ostream & out)
{
	for (int i = 0; i < line.size(); i++)
			out << line[i] << "\n";
}

vector<string>& Ceasar::CaesarCodOrDecod(int shift)
{
	unsigned char code; //вводится переменная с возможным значением 0-255 для того, чтобы смещение не приводило к ситуации, когда символ больше 127
	for (size_t i = 0; i < line.size(); i++) {
		for (size_t j = 0; j < line[i].size(); j++) {
			if (line[i][j] <= 'z' && line[i][j] >= 'a') {
				code = line[i][j] + (shift % 26);
				if (code > 'z') code -= 26;
				else if (code < 'a') code += 26;
				line[i][j] = code;
			}
		}
	}
	return line;
}

vector<string> & Ceasar::CodOrDecod(int flag)
{
	
	cout << "Введите сдвиг" << endl << "->";
	while (!(cin >> shift))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\x1b[31mНекорректный сдвиг\x1b[0m" << endl;
	}
	if (flag == 1) {
		return (CaesarCodOrDecod(shift));
	}
	else return (CaesarCodOrDecod(-shift));
}
vector<string>& Vishner::VishnerCodOrDecod(int flag)
{
	for (size_t i = 0; i < line.size(); i++)
	{
		for (size_t j = 0; j < line[i].size(); j++) {
			int c = line[i][j];
			if (flag == 1) {
				c += key[i][j] - 'a';
			}
			else c -= key[i][j] - 'a';
			if (c > 'z') c -= 26;
			else if (c < 'a') c += 26;
			line[i][j] = c;
		}
	}
	return line;
}

vector<string> & Vishner::CodOrDecod(int flag)
{
	cout << "Введите кодовое слово" << endl;
	cin >> code;
	while (true) {
		try {
			if (!format(code)) throw "\x1b[31mКодовое слово содержит запрещенные символы\x1b[0m";
			getKey();
			if (flag == 1) {
				return (VishnerCodOrDecod(1));
			}
			else return (VishnerCodOrDecod(0));

		}
		catch (const char* error) {
			cout << error << endl << "Введите новое кодовое слово" << endl;
			cin >> code;
		}
	}

}

vector<string> & Vishner::getKey()
{
	key = line;
	int size = code.size();
	for (size_t i = 0; i < line.size(); i++) {//делаем ключ
		for (size_t j = 0,k=0; j < line[i].size(); j++) {
			key[i][j]=code[k];
			if (k != size - 1) k++;
			else k = 0;
		}
	}
	return key;
}

vector<string>& Enigma::EnigmaCodOrDecod()
{
	char alpha[] = "abcdefghijklmnopqrstuvwxyz";
	char rotors[3][27] =
	{
	  "ekmflgdqvzntowyhxuspaibrcj",
	  "ajdksiruxblhwtmcqgznpyfvoe",
	  "bdfhjlcprtxvznyeiwgakmusqo"
	};
	char reflector[] = "yruhqsldpxngokmiebfzcwvjat";
	char key[] = "cuq";
	//присваивание начальных значений роторам (код буквы от 0-25)
	for (int i = 0; i < line.size(); i++) {
		int L = li(key[0]);
		int M = li(key[1]);
		int R = li(key[2]);

		string output;

		for (unsigned int x = 0; x < line[i].size(); x++) {
			int ct_letter = li(line[i][x]);
			/*повороты роторов*/
			R = mod26(R + 1);//правый ротор
			if (R == li(key[2])) M = mod26(M + 1);//если правый повернулся полностью, повернуть центральный 
			if (M == li(key[1])) L = mod26(L + 1);//если центральный полностью повернулся, повернуть левый
			/*вход в машину*/
			char a = rotors[2][mod26(R + ct_letter)];//правый ротор
			char b = rotors[1][mod26(M + li(a) - R)];//центральный ротор
			char c = rotors[0][mod26(L + li(b) - M)];//левый ротор

			char ref = reflector[mod26(li(c) - L)];//рефлектор
			/*обратный путь*/

			int d = mod26(indexof(rotors[0], alpha[mod26(li(ref) + L)]) - L);//левый
			int e = mod26(indexof(rotors[1], alpha[mod26(d + M)]) - M);//центр 
			char f = alpha[mod26(indexof(rotors[2], alpha[mod26(e + R)]) - R)];//правый (в массиве, где алфавит выбирает получившуюся букву)

			output += f;//цапись закодированной буквы в выходную строку
		}
		line[i] = output;
	}
	
	return line;
}
vector<string> & Enigma::CodOrDecod(int flag)
{
	return (EnigmaCodOrDecod());
}

