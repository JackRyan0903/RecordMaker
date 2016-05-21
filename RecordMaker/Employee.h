#pragma once
#include <iostream>			// for cout // cin
#include <sstream>			// for ostringstrim

const int MAX_EMPLOYEE_NUM = 100000;		// �ִ� ��� �ο� ��

class CEmployee{
public:
	// CEmployee ��ü�� ������ ��� ��Ŀ� ���߾� ����մϴ�.
	void ShowEmployeeInfo()	const;

public:
	CEmployee(const int &iEmployeeNum, const int &iScore);
	~CEmployee();

private:
	std::ostringstream m_strEmployeeNum;	// �����ȣ�� ������ ���ڿ���Ʈ�� ��ü
	int m_iScore;			// ��� ����

};