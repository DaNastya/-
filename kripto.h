#pragma once
#include <iostream>
#include <fstream>
#include<Windows.h>
#include <string>
#include <vector>
#include <cmath>
#include <locale>
using namespace std;
bool formatname(string &len);
string initName(string& name);
class cripto //класс направлен на объединение всех методов по кодированию и декодированию 
{
protected:
	vector<string> line;
	bool format(string& len);
	cripto() {
	}
public:
	virtual vector<string>& CodOrDecod(int flag) = 0;//виртуальная функция
	void cod(istream& in, bool iflag, bool oflag);
	void decod(istream& in, bool iflag, bool oflag);
	void getlen();
	void recording(ostream& out);//запись в файлы
};

class Ceasar : public cripto
{
	int shift = 0;
	vector<string>& CaesarCodOrDecod(int shift);

public:
	Ceasar():cripto() { 	
	}
	vector<string>& CodOrDecod(int flag)override;
};
class Vishner : public cripto
{
	vector<string> key;
	string code;
	vector<string>& VishnerCodOrDecod(int flag);
public:
	Vishner() :cripto() {
		code = "0";
	}
	vector<string>& CodOrDecod(int flag)override;

	vector<string>& getKey();

};

class Enigma : public cripto
{
	vector<string>& EnigmaCodOrDecod();
	long mod26(long a);
	int li(char l);
	int indexof(char* array, int find);
public:
	Enigma() :cripto() { }
	vector<string>& CodOrDecod(int flag)override;
	

};

