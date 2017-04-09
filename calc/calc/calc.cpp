// calc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int main(int argc, char* argv[])
{
	string input;
	for (int i = 1; i < argc; ++i)
		input += argv[i];

	Calculator calc(input);
	printf("%f", calc.GetAnswear());

	//system("pause");
    return 0;
}

