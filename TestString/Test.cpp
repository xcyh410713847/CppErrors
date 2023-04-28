/*************************************************************************
**文件: Test.cpp
**作者: shyfan
**日期: 2023/04/28 15:32:00
**功能:
*************************************************************************/

#include <iostream>

#include "CppErrors.h"

void test4(CppErrors<string> &cppErrors)
{
    CPP_ERRORS_WRAP(cppErrors, "test4 error");
}

void test3(CppErrors<string> &cppErrors)
{
    test4(cppErrors);
    CPP_ERRORS_WRAP(cppErrors, "test3 error");
}

void test2(CppErrors<string> &cppErrors)
{
    test3(cppErrors);
    CPP_ERRORS_WRAP(cppErrors, "test2 error");
}

void test1(CppErrors<string> &cppErrors)
{
    test2(cppErrors);
    CPP_ERRORS_WRAP(cppErrors, "test1 error");
}

void test()
{
    CppErrors<string> cppErrors;
    test1(cppErrors);

    if (cppErrors.IsValid())
    {
        cout << "cppErrors is valid" << endl;

        for (auto &error : cppErrors.GetErrors())
        {
            cout << error << endl;
        }

        cout << "first error: " << cppErrors.GetFirstError() << endl;
    }
    else
    {
        cout << "cppErrors is invalid" << endl;
    }

    // 测试空错误获得首个错误
    CppErrors<string> cppErrors2;
    cout << "empty error first error: " << cppErrors2.GetFirstError() << endl;
}

int main()
{
    test();

    return 0;
}
