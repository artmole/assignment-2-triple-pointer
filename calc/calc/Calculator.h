#pragma once
#include "stdafx.h"

using namespace std;

class Calculator {
private:
	string args;
	stack<double> Operands;
	stack<char> Functions;

	void new_operand(int);
	void new_function(char);
	double get_number(int&);
	int get_priority(char);
	double calc(double a, double b, char func);
	void pop_func();
public:
	Calculator(string input);
	~Calculator();
	double GetAnswear();
};