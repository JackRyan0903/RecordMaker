#pragma once
#include <iostream>			// for cout // cin
#include <sstream>			// for ostringstrim

const int MAX_EMPLOYEE_NUM = 100000;		// 최대 등록 인원 수

class CEmployee{
public:
	// CEmployee 객체의 정보를 출력 양식에 맞추어 출력합니다.
	void ShowEmployeeInfo()	const;

public:
	CEmployee(const int &iEmployeeNum, const int &iScore);
	~CEmployee();

private:
	std::ostringstream m_strEmployeeNum;	// 사원번호를 저장할 문자열스트림 객체
	int m_iScore;			// 사원 점수

};