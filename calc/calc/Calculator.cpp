#include "stdafx.h"

Calculator::Calculator(string input)
{
	args = input + ")";
	Operands.Clear();
	Functions.Clear();
}

Calculator::~Calculator()
{

}

double Calculator::GetAnswear()
{
	Functions.Push('(');
	for (int i = 0; i < args.length(); ++i)
	{
		if (isdigit(args[i]))
		{
			new_operand(get_number(i));
		}
		else
		{
			new_function(args[i]);
		}
	}
	return Operands.Pop();
}

void Calculator::new_operand(int a)
{
	Operands.Push(a);
}

void Calculator::new_function(char a)
{
	if (a == '(')
	{
		Functions.Push(a);
		return;
	}
	if (a == ')')
	{
		while (Functions.Back() != '(')
			pop_func();
		Functions.Pop();
		return;
	}
	while (get_priority(a) >= get_priority(Functions.Back()))
	{
		pop_func();
	}
	Functions.Push(a);
}

double Calculator::get_number(int & i)
{
	string num;
	while (isdigit(args[i]) || args[i] == '.' || args[i] == ',')
	{
		if (args[i] == ',')
			num += '.';
		else
			num += args[i];
		++i;
	}	
	--i;
	return stod(num);
}

void Calculator::pop_func()
{
	Operands.Push(calc(Operands.Pop(), Operands.Pop(), Functions.Pop()));
}

int Calculator::get_priority(char a)
{
	switch (a) {
	case '+': case '-':
		return 3;
		break;
	case '*': case '/':
		return 2;
		break;
	case '^':
		return 1;
		break;
	case '(': case ')':
		return 4;
		break;
	default:
		printf("Unknown operation %c\n", a);
		return -1;
	}
}

double Calculator::calc(double a, double b, char func)
{
	switch (func)
	{
	case '+':
		return a + b;
		break;
	case '-':
		return a - b;
		break;
	case '*':
		return a * b;
		break;
	case '/':
		return a / b;
		break;
	case '^':
		return pow(b, a);
		break;
	}
}

