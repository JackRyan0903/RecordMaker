/*
	
	RecordMaker

	�� �ڵ�� Visual Studio 2012 �������� C++ 11 �������� �ۼ� �Ǿ����ϴ�.
	�ڵ� �ۼ��� : ����ȭ	Jack_Ryan@naver.com
	�ۼ� �Ͻ� : 2016-05-15

*/

#include "EmployeeManager.h"



int main(int argc, char *argv[])
{

	try{

		if (2 != argc){

			throw (std::string("���� ���� !!!"));

		}

		if (0 <= atoi(argv[1]) && atoi(argv[1]) <= MAX_EMPLOYEE_NUM){

			// CEmlplyeeManager ��ü ����
			std::unique_ptr<CEmployeeManager> cpEmployeeManager{ new CEmployeeManager };

			// ��� ���ڷ� �Է� ���� ���ڸ� Set
			cpEmployeeManager->SetNumOfEmployees(atoi(argv[1]));
			cpEmployeeManager->MakeEmployeesInfo();
			cpEmployeeManager->ShowEmployeesInfo();

		}
		else{
		
			throw(std::string("��Ȯ�� ���ڸ� �Է��Ͻÿ� !!!"));

		}

	}
	catch (const std::string &strError){

		std::cout << strError << std::endl;

	}


	return 0;
}