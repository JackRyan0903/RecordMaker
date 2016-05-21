#include "Employee.h"


CEmployee::CEmployee(const int &iEmployeeNum, const int &iScore) : m_iScore(iScore)
{

	m_strEmployeeNum << "NT";		// ���ڿ� ���� �տ� "NT" ��� ���� ����

	// 10000 ���� 10�� ������ ���鼭 ���������� iEmployeeNum�� ������ ����
	// �� ����� 0�̶�� ���� �� �ڸ� ������ ���� ���Ƿ� ���ڿ� �տ� '0'�� �߰�����
	for (int i = MAX_EMPLOYEE_NUM / 10; i != 1; i /= 10){

		if (0 == iEmployeeNum / i)
		{
			m_strEmployeeNum << '0';
		}
		else{

			break;

		}

	}

	// ���������� ���ڸ� ���ڿ��� ����
	m_strEmployeeNum << iEmployeeNum;

}

CEmployee::~CEmployee()
{

}

void CEmployee::ShowEmployeeInfo()	const
{
	std::cout << m_strEmployeeNum.str() << " " << m_iScore << std::endl;
}