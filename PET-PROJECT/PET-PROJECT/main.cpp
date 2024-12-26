#include <iostream>
#include <fstream>
#include <string>

class PasswordManager
{
public:
	void SignUp() {
		std::string login, password;
		std::cout << "������� �����: ";
		std::cin >> login;
		std::cout << "������� ������: ";
		std::cin >> password;

		std::ofstream logFile("login.txt", std::ios::app);
		std::ofstream passFile("password.txt", std::ios::app);

		if (!logFile.is_open() || !passFile.is_open()) {
			std::cout << "ERROR ��� �������� �����, �� �� ��� �� ������ ��?" << std::endl;
			return;
		}



		logFile << login << std::endl;
		passFile << password << std::endl;

		std::cout << "׸���� ���� ������!" << std::endl;

		logFile.close();
		passFile.close();
	}


	void Entrance() {
		std::string login, password;
		std::cout << "������� �����: ";
		std::cin >> login;
		std::cout << "������� ������: ";
		std::cin >> password;

		std::ifstream logFile("login.txt");
		std::ifstream passFile("password.txt");

		if (!logFile.is_open() || !passFile.is_open()) {
			std::cout << "ERROR �������* ��� �������� �����!" << std::endl;
			return;
		}

		std::string savedLogin, savedPassword;
		bool loginFound = false;

		while (std::getline(logFile, savedLogin) && std::getline(passFile, savedPassword)) {
			if (login == savedLogin && password == savedPassword) {
				std::cout << "���� ������ ��� � ���� �����!" << std::endl;
				loginFound = true;
				break;
			}
		}
		if (!loginFound) {
			std::cout << "EROOOOOOOOOOOR ������ ��� ����� ��������!" << std::endl;
		}

		logFile.close();
		passFile.close();
	}
};

int main() {
	setlocale(LC_ALL, "RU");
	PasswordManager manager;
	int choice;

	std::cout << "��� �� ������� �������? \n1 - ���� \n2 - ����������� \n�������� 1 ��� 2 � ��������� �� ���� ��� ������: ";
	std::cin >> choice;

	if (choice == 1) {
		manager.Entrance();
	}
	else if (choice == 2) {
		manager.SignUp();
	}
	else {
		std::cout << "������ �� �� ������, ��� ������ �����";
	}
	return 0;
}