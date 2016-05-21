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
	// 난수 엔진을 이용하여 랜덤한 사원 번호와 랜덤한 점수를 넣어 CEmployee 객체를 생성
	// 중복방지를 위하여 미리 사용가능한 사원 번호를 저장하는 vector를 만듬
	// 하나의 사원 번호가 사용될 시 vector에서 지워짐
	void MakeEmployeesInfo();

	// list에 저장된 모든 사원 정보들을 출력
	void ShowEmployeesInfo() const;

public:
	CEmployeeManager();

	~CEmployeeManager();


public:
	void SetNumOfEmployees(const int &iNumOfEmployees);

private:
	int m_iNumOfEmployees;				// 사원 수
	std::vector<int> m_vRestNumbers;				// 사용 가능한 사원 번호를 저장하는 vector
	std::list<std::unique_ptr<CEmployee>> m_listEmployees;		// 사원 객체들을 관리하는 list

};