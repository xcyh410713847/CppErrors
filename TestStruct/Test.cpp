/*************************************************************************
**文件: Test.cpp
**作者: shyfan
**日期: 2023/04/28 16:17:54
**功能:
*************************************************************************/

#include <iostream>

#include "CppErrors.h"

struct Error
{
    string message;
    int code;
};

void test4(CppErrors<Error> &cppErrors)
{
    Error error{"test4 error", 4};
    CPP_ERRORS_WRAP(cppErrors, error);
}

void test3(CppErrors<Error> &cppErrors)
{
    test4(cppErrors);
    Error error{"test3 error", 3};
    CPP_ERRORS_WRAP(cppErrors, error);
}

void test2(CppErrors<Error> &cppErrors)
{
    test3(cppErrors);
    Error error{"test2 error", 2};
    CPP_ERRORS_WRAP(cppErrors, error);
}

void test1(CppErrors<Error> &cppErrors)
{
    test2(cppErrors);
    Error error{"test1 error", 1};
    CPP_ERRORS_WRAP(cppErrors, error);
}

void test()
{
    CppErrors<Error> cppErrors;
    test1(cppErrors);

    if (cppErrors.IsValid())
    {
        cout << "cppErrors is valid" << endl;

        for (auto &error : cppErrors.GetErrors())
        {
            cout << "code " << error.code << " message " << error.message << endl;
        }

        Error error = cppErrors.GetFirstError();
        cout << "first error: code " << error.code << " message " << error.message << endl;
    }
    else
    {
        cout << "cppErrors is invalid" << endl;
    }
}

int main()
{
    test();

    return 0;
}
