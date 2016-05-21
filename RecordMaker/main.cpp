/*
	
	RecordMaker

	이 코드는 Visual Studio 2012 버전에서 C++ 11 기준으로 작성 되었습니다.
	코드 작성자 : 정성화	Jack_Ryan@naver.com
	작성 일시 : 2016-05-15

*/

#include "EmployeeManager.h"



int main(int argc, char *argv[])
{

	try{

		if (2 != argc){

			throw (std::string("인자 오류 !!!"));

		}

		if (0 <= atoi(argv[1]) && atoi(argv[1]) <= MAX_EMPLOYEE_NUM){

			// CEmlplyeeManager 객체 생성
			std::unique_ptr<CEmployeeManager> cpEmployeeManager{ new CEmployeeManager };

			// 명령 인자로 입력 받은 숫자를 Set
			cpEmployeeManager->SetNumOfEmployees(atoi(argv[1]));
			cpEmployeeManager->MakeEmployeesInfo();
			cpEmployeeManager->ShowEmployeesInfo();

		}
		else{
		
			throw(std::string("정확한 숫자를 입력하시오 !!!"));

		}

	}
	catch (const std::string &strError){

		std::cout << strError << std::endl;

	}


	return 0;
}