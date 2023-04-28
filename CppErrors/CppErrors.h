/*************************************************************************
**文件: CppErrors.h
**作者: shyfan
**日期: 2023/04/27 17:59:40
**功能:
*************************************************************************/

#ifndef __CPP_ERRORS_H__
#define __CPP_ERRORS_H__

#include <vector>
#include <string>
#include <sstream>

using namespace std;

string emptyTrace = "";

template <typename T>
class CppErrors
{
	vector<T> errors;
	vector<string> errorTrace;

public:
	CppErrors(){};
	~CppErrors()
	{
		errors.clear();
	}

	// 添加错误
	void AddError(const T &error, string trace)
	{
		errors.push_back(error);
		errorTrace.push_back(trace);
	}

	// 获取错误列表
	const vector<T> GetErrors() const
	{
		return errors;
	};

	// 获取首个错误
	const T GetFirstError() const
	{
		if (errors.size() > 0)
		{
			return errors[0];
		}
		else
		{
			return "";
		}
	}

	// 是否有效
	bool IsValid() const
	{
		return !errors.empty();
	}

	// 清空错误
	void Clear()
	{
		errors.clear();
	}
};

// 不带堆栈的错误
#define CPP_ERRORS_WRAP(cppErrors, error) cppErrors.AddError(error, emptyTrace)

// 带堆栈的错误
#define CPP_ERRORS_WRAP_TRACE(cppErrors, error, trace)                            \
	{                                                                             \
		stringstream ss;                                                          \
		ss << "[" << __FILE__ << ":" << __LINE__ << "(" << __FUNCTION__ << ")] "; \
		cppErrors.AddError(error, ss.str());                                      \
	}

#endif // __CPP_ERRORS_H__
