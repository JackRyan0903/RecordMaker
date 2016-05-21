#pragma once
#include <vector>			// for vector
#include <list>				// for list
#include <memory>			// for unique_ptr
#include <random>			// for random engine
#include <ctime>			// for time function
#include <functional>		// for bind

#include "Employee.h"

class CEmployeeManager{
public:
	// ���� ������ �̿��Ͽ� ������ ��� ��ȣ�� ������ ������ �־� CEmployee ��ü�� ����
	// �ߺ������� ���Ͽ� �̸� ��밡���� ��� ��ȣ�� �����ϴ� vector�� ����
	// �ϳ��� ��� ��ȣ�� ���� �� vector���� ������
	void MakeEmployeesInfo();

	// list�� ����� ��� ��� �������� ���
	void ShowEmployeesInfo() const;

public:
	CEmployeeManager();

	~CEmployeeManager();


public:
	void SetNumOfEmployees(const int &iNumOfEmployees);

private:
	int m_iNumOfEmployees;				// ��� ��
	std::vector<int> m_vRestNumbers;				// ��� ������ ��� ��ȣ�� �����ϴ� vector
	std::list<std::unique_ptr<CEmployee>> m_listEmployees;		// ��� ��ü���� �����ϴ� list

};