#include "Employee.h"


CEmployee::CEmployee(const int &iEmployeeNum, const int &iScore) : m_iScore(iScore)
{

	m_strEmployeeNum << "NT";		// 문자열 가장 앞에 "NT" 라는 문자 삽입

	// 10000 부터 10씩 나누어 가면서 순차적으로 iEmployeeNum을 나누어 보고
	// 그 결과가 0이라는 것은 그 자리 수보다 작은 수므로 문자열 앞에 '0'을 추가해줌
	for (int i = MAX_EMPLOYEE_NUM / 10; i != 1; i /= 10){

		if (0 == iEmployeeNum / i)
		{
			m_strEmployeeNum << '0';
		}
		else{

			break;

		}

	}

	// 마지막으로 숫자를 문자열에 삽입
	m_strEmployeeNum << iEmployeeNum;

}

CEmployee::~CEmployee()
{

}

void CEmployee::ShowEmployeeInfo()	const
{
	std::cout << m_strEmployeeNum.str() << " " << m_iScore << std::endl;
}