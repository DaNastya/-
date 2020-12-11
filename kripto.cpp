#include "kripto.h"
#include <fstream>
#include<Windows.h>
#include <string>
#include <cmath>
#include <locale>
bool cripto::format(string& len)
{
	bool flag = true;
	string s;
	for (unsigned int i = 0; i < len.size(); i++) {
		if (len[i] <= 'Z' && len[i] >= 'A' || len[i] <= 'z' && len[i] >= 'a') {
			if (len[i] <= 'Z' && len[i] >= 'A') len[i] = tolower(len[i]);
			s += len[i];
		}
		else if (len[i] <= '�' && len[i] >= '�' || len[i] <= '�' && len[i] >= '�') flag = false;
	}
	len = s;
	return flag;
}


long Enigma::mod26(long a)//����������� �����
{
	return (a % 26 + 26) % 26;
}

int Enigma::li(char l)//���������� ��� ����� �� 0-25
{
	return l - 'a';
}

int Enigma::indexof(char* array, int find)//���������� ������� �������
{
	return strchr(array, find) - array;
}

void cripto::cod(istream & in, ostream & out, bool iflag, bool oflag)
{
	if (iflag == false)
	{
		cout << "������� ������ ��� �����������:" << endl;//���� ������ � ����������, 
		//���� ������ ������ ��� ������ �������� ������� �����, ���� ������
		in.ignore();
		getline(in, line);
		while (true) {
			try {

				if (!format(line)) throw "\x1b[31m������ ��������� ����������� �������\x1b[0m";
				if (line == "") throw "\x1b[31m������� ������ ������\x1b[0m";
				line = CodOrDecod(1);
				if (oflag == false)out << "�������������� ������: " << endl;
				out << line;
				out << endl;
				break;
			}
			catch (const char* a) {

				cout << a << endl << "������ ������ ������" << endl;
				getline(in, line);
			}
		}
	}
	else
	{
		if (!in.eof()) {
			do
			{
				try {
					getline(in, line);
					if (line == "") throw "\x1b[31m������� ������ ������ � �����\x1b[0m";
					if (!format(line)) throw "\x1b[31m� ������ ���������� ����������� �������, ��� ������������ �� �����\x1b[0m";
					line = CodOrDecod(1);
					if (oflag == false)out << "�������������� ������: " << endl;
					out << line;
					out << endl;
				}
				catch (const char* error) {
					cout << error << endl;

				}
			} while (!in.eof());
		}
		else cout << "���� ����\x1b[0m" << endl;
	}
}

void cripto::decod(istream & in, ostream & out, bool iflag, bool oflag)
{
	if (oflag == false)
	{
		try {
			if (iflag == true) {
				if (!in.eof()) {
					do {
						getline(in, line);
						if (!format(line)) throw "\x1b[31m� ������ ���������� ����������� �������, ��� ������������ �� �����\x1b[0m";
						line = CodOrDecod(0);
						if (oflag == false)out << "�������������� ������: " << endl;
						out << line;
						out << endl;
					} while (!in.eof());
				}
				else throw "\x1b[31m���� ����";
			}
			else {
				if (line == "0") throw "\x1b[31m��������� ��� ������������� �� �������\x1b[0m";
				line = CodOrDecod(0);
				cout << "�������������� ������: " << endl;
				cout << line;
				cout << endl;
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
					getline(in, line);
					if (line == "") throw "\x1b[31m������� ������ ������ � �����\x1b[0m";
					if (!format(line)) throw "\x1b[31m� ������ ���������� ����������� �������, ��� ������������ �� �����\x1b[0m";
					line = CodOrDecod(0);
					if (oflag == false)out << "�������������� ������: " << endl;
					out << line;
					out << endl;
				}
				catch (const char* error) {
					cout << error << endl;

				}
			} while (!in.eof());
		}
		else cout << "\x1b[31m���� ����\x1b[0m" << endl;

	}
}

string& Ceasar::CaesarCodOrDecod(int shift)
{
	unsigned char code; //�������� ���������� � ��������� ��������� 0-255 ��� ����, ����� �������� �� ��������� � ��������, ����� ������ ������ 127
	for (size_t i = 0; i < line.size(); i++) {
		if (line[i] <= 'z' && line[i] >= 'a') {
			code = line[i] + (shift % 26);
			if (code > 'z') code -= 26;
			else if (code < 'a') code += 26;
			line[i] = code;
		}
	}
	return line;
}

string & Ceasar::CodOrDecod(int flag)
{
	
	cout << "������� �����" << endl << "->";
	while (!(cin >> shift))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "\x1b[31m������������ �����\x1b[0m" << endl;
	}
	if (flag == 1) {
		return (CaesarCodOrDecod(shift));
	}
	else return (CaesarCodOrDecod(-shift));
}
string& Vishner::VishnerCodOrDecod(int flag)
{
	for (size_t i = 0; i < line.size(); i++)
	{
		int c = line[i];
		if (flag == 1) {
			c += key[i] - 'a';
		}
		else c -= key[i] - 'a';
		if (c > 'z') c -= 26;
		else if (c < 'a') c += 26;
		line[i] = c;
	}
	return line;
}

string & Vishner::CodOrDecod(int flag)
{
	cout << "������� ������� �����" << endl;
	cin.ignore();
	getline(cin, code);
	while (true) {
		try {
			if (!format(code)) throw "\x1b[31m������� ����� �������� ����������� �������\x1b[0m";
			if (line.size() < code.size()) throw "\x1b[31m������� ����� ������ ����� ���������\x1b[0m";
			getKey();
			if (flag == 1) {
				return (VishnerCodOrDecod(1));
			}
			else return (VishnerCodOrDecod(0));

		}
		catch (const char* error) {
			cout << error << endl << "������� ����� ������� �����" << endl;
			getline(cin, code);
		}
	}

}

string & Vishner::getKey()
{
	key = line;
	int size = code.size();
	for (size_t k = 0; k < line.size(); k++) {//������ ����
		key[k] = code[k % size];
	}
	return key;
}

string& Enigma::EnigmaCodOrDecod()
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
	//������������ ��������� �������� ������� (��� ����� �� 0-25)
	int L = li(key[0]);
	int M = li(key[1]);
	int R = li(key[2]);

	string output;

	for (unsigned int x = 0; x < line.size(); x++) {
		int ct_letter = li(line[x]);
		/*�������� �������*/
		R = mod26(R + 1);//������ �����
		if (R == li(key[2])) M = mod26(M + 1);//���� ������ ���������� ���������, ��������� ����������� 
		if (M == li(key[1])) L = mod26(L + 1);//���� ����������� ��������� ����������, ��������� �����
		/*���� � ������*/
		char a = rotors[2][mod26(R + ct_letter)];//������ �����
		char b = rotors[1][mod26(M + li(a) - R)];//����������� �����
		char c = rotors[0][mod26(L + li(b) - M)];//����� �����

		char ref = reflector[mod26(li(c) - L)];//���������
		/*�������� ����*/

		int d = mod26(indexof(rotors[0], alpha[mod26(li(ref) + L)]) - L);//�����
		int e = mod26(indexof(rotors[1], alpha[mod26(d + M)]) - M);//����� 
		char f = alpha[mod26(indexof(rotors[2], alpha[mod26(e + R)]) - R)];//������ (� �������, ��� ������� �������� ������������ �����)

		output += f;//������ �������������� ����� � �������� ������
	}
	line = output;
	return line;
}

string & Enigma::CodOrDecod(int flag)
{
	return (EnigmaCodOrDecod());
}

