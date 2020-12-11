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
//void printvec(vector<cripto> &c);
class cripto //класс направлен на объединение всех методов по кодированию и декодированию 
{
protected:
	string line;
	bool format(string& len);
	cripto() { line = "0"; }
public:
	virtual string& CodOrDecod(int flag) = 0;
	void cod(istream& in, ostream& out, bool iflag, bool oflag);
	void decod(istream& in, ostream& out, bool iflag, bool oflag);
	string getlen() { return line; }
};

class Ceasar : public cripto
{
	int shift = 0;
	string& CaesarCodOrDecod(int shift);

public:
	Ceasar() { line = "0";	
	}
	string& CodOrDecod(int flag)override;//переделать исключения
	

};
class Vishner : public cripto
{
	string key;
	string code;
	string& VishnerCodOrDecod(int flag);
public:
	Vishner() { line = "0";
	code = "0";
	key = "0";
	}
	string& CodOrDecod(int flag)override;

	string& getKey();

};

class Enigma : public cripto
{
	string code;
	string& EnigmaCodOrDecod();
	long mod26(long a);
	int li(char l);
	int indexof(char* array, int find);
public:
	Enigma() { line = "0"; }
	string& CodOrDecod(int flag)override;
	

};

