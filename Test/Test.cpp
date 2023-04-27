// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "CppErrors.h"

void test4(CppErrors& cppErrors)
{
	CPP_ERRORS_WRAP(cppErrors, "test4 error");
}

void test3(CppErrors& cppErrors)
{
	test4(cppErrors);
	CPP_ERRORS_WRAP(cppErrors, "test3 error");
}

void test2(CppErrors& cppErrors)
{
	test3(cppErrors);
	CPP_ERRORS_WRAP(cppErrors, "test2 error");
}

void test1(CppErrors& cppErrors)
{
	test2(cppErrors);
	CPP_ERRORS_WRAP(cppErrors, "test1 error");
}

int main()
{
	CppErrors cppErrors;
	test1(cppErrors);
	
	if (cppErrors.IsValid())
	{
		cout << "cppErrors is valid" << endl;
		
		for (auto& error : cppErrors.GetErrors())
		{
			cout << error << endl;
		}
		

		cout << "first error: " << cppErrors.GetFirstError() << endl;
	}
	else
	{
		cout << "cppErrors is invalid" << endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
