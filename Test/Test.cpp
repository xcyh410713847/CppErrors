// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "CppErrors.h"

void normalTest4(CppErrors<string>& cppErrors)
{
	CPP_ERRORS_WRAP(cppErrors, "normalTest4 error");
}

void normalTest3(CppErrors<string>& cppErrors)
{
	normalTest4(cppErrors);
	CPP_ERRORS_WRAP(cppErrors, "normalTest3 error");
}

void normalTest2(CppErrors<string>& cppErrors)
{
	normalTest3(cppErrors);
	CPP_ERRORS_WRAP(cppErrors, "normalTest2 error");
}

void normalTest1(CppErrors<string>& cppErrors)
{
	normalTest2(cppErrors);
	CPP_ERRORS_WRAP(cppErrors, "normalTest1 error");
}

void normalTest() {
	CppErrors<string> cppErrors;
	normalTest1(cppErrors);

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

void globalTest4()
{
	GLOBAL_CPP_ERRORS_WRAP("globalTest4 error");
}

void globalTest3()
{
	globalTest4();
	GLOBAL_CPP_ERRORS_WRAP("globalTest3 error");
}

void globalTest2()
{
	globalTest3();
	GLOBAL_CPP_ERRORS_WRAP("globalTest2 error");
}

void globalTest1()
{
	globalTest2();
	GLOBAL_CPP_ERRORS_WRAP("globalTest1 error");
}

void globalTest()
{
	GLOBAL_CPP_ERRORS_CLEAR;
	globalTest1();

	if (GLOBAL_CPP_ERRORS_IS_VALID)
	{
		cout << "globalCppErrors is valid" << endl;

		for (auto& error : GLOBAL_CPP_ERRORS_GET_ERRORS)
		{
			cout << error << endl;
		}

		cout << "first error: " << GLOBAL_CPP_ERRORS_GET_FIRST_ERROR << endl;
	}
	else
	{
		cout << "globalCppErrors is invalid" << endl;
	}
}

int main()
{
	normalTest();

	cout << endl;
	
	globalTest();

	return 0;
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
