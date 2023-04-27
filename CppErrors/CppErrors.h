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

class CppErrors
{
	vector<string> errors;

public:
	CppErrors() {};
	~CppErrors() {
		errors.clear();
	}

	// 添加错误
	void AddError(const string& error) {
		errors.push_back(error);
	}

	// 获取错误列表
	const vector<string> GetErrors() const {
		return errors;
	};

	// 获取首个错误
	const string GetFirstError() const {
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
	bool IsValid() const {
		return !errors.empty();
	}
};

#define CPP_ERRORS_WRAP(cppErrors, error)	\
{	\
	stringstream ss;	\
	ss << "[" << __FILE__ << ":" << __LINE__ << "(" << __FUNCTION__ << ")] " << error;	\
	cppErrors.AddError(ss.str());	\
}

#endif // __CPP_ERRORS_H__
