#include <iostream>
#include <fstream>
#include <string>

class PasswordManager
{
public:
	void SignUp() {
		std::string login, password;
		std::cout << "¬ведите логин: ";
		std::cin >> login;
		std::cout << "¬ведите пароль: ";
		std::cin >> password;

		std::ofstream logFile("login.txt", std::ios::app);
		std::ofstream passFile("password.txt", std::ios::app);

		if (!logFile.is_open() || !passFile.is_open()) {
			std::cout << "ERROR при открытии файла, ты чЄ как не родной аа?" << std::endl;
			return;
		}



		logFile << login << std::endl;
		passFile << password << std::endl;

		std::cout << "„Єткий вход родной!" << std::endl;

		logFile.close();
		passFile.close();
	}


	void Entrance() {
		std::string login, password;
		std::cout << "¬ведите Ћогин: ";
		std::cin >> login;
		std::cout << "¬ведите пароль: ";
		std::cin >> password;

		std::ifstream logFile("login.txt");
		std::ifstream passFile("password.txt");

		if (!logFile.is_open() || !passFile.is_open()) {
			std::cout << "ERROR ћј«ј‘ј * ѕ–» ќ“ –џ“»» ‘ј…Ћј!" << std::endl;
			return;
		}

		std::string savedLogin, savedPassword;
		bool loginFound = false;

		while (std::getline(logFile, savedLogin) && std::getline(passFile, savedPassword)) {
			if (login == savedLogin && password == savedPassword) {
				std::cout << "¬ход чЄткий как и твои чЄтки!" << std::endl;
				loginFound = true;
				break;
			}
		}
		if (!loginFound) {
			std::cout << "EROOOOOOOOOOOR ѕј–ќЋ№ »Ћ» Ћќ√»Ќ Ќ≈¬≈–Ќџ…!" << std::endl;
		}

		logFile.close();
		passFile.close();
	}
};

int main() {
	setlocale(LC_ALL, "RU");
	PasswordManager manager;
	int choice;

	std::cout << "„то вы желаете сделать? \n1 - ¬ход \n2 - –егистраци€ \nЌапишите 1 или 2 в завимости от того что хотите: ";
	std::cin >> choice;

	if (choice == 1) {
		manager.Entrance();
	}
	else if (choice == 2) {
		manager.SignUp();
	}
	else {
		std::cout << "Ѕратан ты не чЄткий, как чЄткие чЄтки";
	}
	return 0;
}