/*************************************************************************
**文件: Test.cpp
**作者: shyfan
**日期: 2023/04/28 15:32:00
**功能:
*************************************************************************/

#include <iostream>

#include "CppErrors.h"

void test4(CppErrors<string> &cppErrors1, CppErrors<string> &cppErrors2)
{
    CPP_ERRORS_WRAP(cppErrors1, "test4 error");
    CPP_ERRORS_WRAP_TRACE(cppErrors2, "test4 error");
}

void test3(CppErrors<string> &cppErrors1, CppErrors<string> &cppErrors2)
{
    test4(cppErrors1, cppErrors2);
    CPP_ERRORS_WRAP(cppErrors1, "test3 error");
    CPP_ERRORS_WRAP_TRACE(cppErrors2, "test3 error");
}

void test2(CppErrors<string> &cppErrors1, CppErrors<string> &cppErrors2)
{
    test3(cppErrors1, cppErrors2);
    CPP_ERRORS_WRAP(cppErrors1, "test2 error");
    CPP_ERRORS_WRAP_TRACE(cppErrors2, "test2 error");
}

void test1(CppErrors<string> &cppErrors1, CppErrors<string> &cppErrors2)
{
    test2(cppErrors1, cppErrors2);
    CPP_ERRORS_WRAP(cppErrors1, "test1 error");
    CPP_ERRORS_WRAP_TRACE(cppErrors2, "test1 error");
}

void test()
{
    CppErrors<string> cppErrors1;
    CppErrors<string> cppErrors2;
    test1(cppErrors1, cppErrors2);

    // 打印错误
    if (cppErrors1.IsValid())
    {
        cout << "cppErrors1 is valid" << endl;

        for (auto &error : cppErrors1.GetErrors())
        {
            cout << error << endl;
        }

        cout << "first error: " << cppErrors1.GetFirstError() << endl;
    }
    else
    {
        cout << "cppErrors1 is invalid" << endl;
    }

    // 打印堆栈
    if (cppErrors2.IsValid())
    {
        cout << "cppErrors2 is valid" << endl;

        for (auto &errorTrace : cppErrors2.GetErrorTrace())
        {
            cout << errorTrace << endl;
        }

        cout << "first error: " << cppErrors2.GetFirstError() << endl;
    }
    else
    {
        cout << "cppErrors2 is invalid" << endl;
    }

    // 测试空错误获得首个错误
    CppErrors<string> cppErrorsEmpty;
    cout << "empty error first error: " << cppErrorsEmpty.GetFirstError() << endl;
}

int main()
{
    test();

    return 0;
}
