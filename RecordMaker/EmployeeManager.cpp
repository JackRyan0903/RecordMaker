#include "EmployeeManager.h"

CEmployeeManager::CEmployeeManager() : m_iNumOfEmployees(0)
{

	m_vRestNumbers.reserve(MAX_EMPLOYEE_NUM);

	// vector에 0부터 최대 등록인원수-1 까지의 숫자를 순차적으로 넣는다.
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
	// 랜덤하게 점수를 만들기 위한 함수 생성
	auto MakeRandomScore = std::bind(std::uniform_int_distribution<>{0, 99}, std::default_random_engine{ (unsigned int)time(nullptr) });

	for (int i = 0; i < m_iNumOfEmployees; ++i){

		// 랜덤하게 사원번호를 가져올 인덱스를 만드는 함수 생성			
		auto MakeRandomNumber = std::bind(std::uniform_int_distribution<>{0, (int)m_vRestNumbers.size() - 1}, std::default_random_engine{ (unsigned int)time(nullptr) });
		int iRandomNumber = MakeRandomNumber();

		// 난수를 이용하여 그 해당 인덱스의 숫자를 가져와 사원 번호를 생성, 난수를 이용하여 사원 점수를 생성
		m_listEmployees.push_back(std::make_unique<CEmployee>(m_vRestNumbers[iRandomNumber], MakeRandomScore()));

		// 한번 사용한 난수 인덱스는 해당 사원번호를 vector에서 삭제(중복 방지)	
		m_vRestNumbers.erase(m_vRestNumbers.begin() + iRandomNumber);

	}

}

// list에 저장된 모든 사원 정보들을 출력
void CEmployeeManager::ShowEmployeesInfo() const
{

	for (const auto &iter : m_listEmployees){

		iter->ShowEmployeeInfo();

	}

}

void CEmployeeManager::SetNumOfEmployees(const int &iNumOfEmployees)
{

	// 유효범위 [0, 최대 등록 가능 인원] 확인 후 set
	if (0 <= iNumOfEmployees && iNumOfEmployees <= MAX_EMPLOYEE_NUM){

		m_iNumOfEmployees = iNumOfEmployees;

	}

}