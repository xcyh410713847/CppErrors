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

#pragma region CppErrors

template<typename T>
class CppErrors
{
	vector<T> errors;

public:
	CppErrors() {};
	~CppErrors() {
		errors.clear();
	}

	// 添加错误
	void AddError(const T& error) {
		errors.push_back(error);
	}

	// 获取错误列表
	const vector<T> GetErrors() const {
		return errors;
	};

	// 获取首个错误
	const T GetFirstError() const {
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

	// 清空错误
	void Clear() {
		errors.clear();
	}
};

#define CPP_ERRORS_WRAP(cppErrors, error)	\
{	\
	stringstream ss;	\
	ss << "[" << __FILE__ << ":" << __LINE__ << "(" << __FUNCTION__ << ")] " << error;	\
	cppErrors.AddError(ss.str());	\
}

#pragma endregion

#pragma region GlobalCppErrors

CppErrors<string> globalCppErrors;

#define GLOBAL_CPP_ERRORS_WRAP(error)		CPP_ERRORS_WRAP(globalCppErrors, error)
#define GLOBAL_CPP_ERRORS_CLEAR				globalCppErrors.Clear()
#define GLOBAL_CPP_ERRORS_IS_VALID			globalCppErrors.IsValid()
#define GLOBAL_CPP_ERRORS_GET_ERRORS		globalCppErrors.GetErrors()
#define GLOBAL_CPP_ERRORS_GET_FIRST_ERROR	globalCppErrors.GetFirstError()

#pragma endregion

#endif // __CPP_ERRORS_H__
