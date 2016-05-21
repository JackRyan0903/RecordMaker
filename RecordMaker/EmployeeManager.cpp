#include "EmployeeManager.h"

CEmployeeManager::CEmployeeManager() : m_iNumOfEmployees(0)
{

	m_vRestNumbers.reserve(MAX_EMPLOYEE_NUM);

	// vector�� 0���� �ִ� ����ο���-1 ������ ���ڸ� ���������� �ִ´�.
	for (int i = 0; i < MAX_EMPLOYEE_NUM; ++i){

		m_vRestNumbers.push_back(i);

	}

}


CEmployeeManager::~CEmployeeManager()
{

		m_vRestNumbers.clear();
		m_listEmployees.clear();

}

void CEmployeeManager::MakeEmployeesInfo()
{
	// �����ϰ� ������ ����� ���� �Լ� ����
	auto MakeRandomScore = std::bind(std::uniform_int_distribution<>{0, 99}, std::default_random_engine{ (unsigned int)time(nullptr) });

	for (int i = 0; i < m_iNumOfEmployees; ++i){

		// �����ϰ� �����ȣ�� ������ �ε����� ����� �Լ� ����			
		auto MakeRandomNumber = std::bind(std::uniform_int_distribution<>{0, (int)m_vRestNumbers.size() - 1}, std::default_random_engine{ (unsigned int)time(nullptr) });
		int iRandomNumber = MakeRandomNumber();

		// ������ �̿��Ͽ� �� �ش� �ε����� ���ڸ� ������ ��� ��ȣ�� ����, ������ �̿��Ͽ� ��� ������ ����
		m_listEmployees.push_back(std::make_unique<CEmployee>(m_vRestNumbers[iRandomNumber], MakeRandomScore()));

		// �ѹ� ����� ���� �ε����� �ش� �����ȣ�� vector���� ����(�ߺ� ����)	
		m_vRestNumbers.erase(m_vRestNumbers.begin() + iRandomNumber);

	}

}

// list�� ����� ��� ��� �������� ���
void CEmployeeManager::ShowEmployeesInfo() const
{

	for (const auto &iter : m_listEmployees){

		iter->ShowEmployeeInfo();

	}

}

void CEmployeeManager::SetNumOfEmployees(const int &iNumOfEmployees)
{

	// ��ȿ���� [0, �ִ� ��� ���� �ο�] Ȯ�� �� set
	if (0 <= iNumOfEmployees && iNumOfEmployees <= MAX_EMPLOYEE_NUM){

		m_iNumOfEmployees = iNumOfEmployees;

	}

}