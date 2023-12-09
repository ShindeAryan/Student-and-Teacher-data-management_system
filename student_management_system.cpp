#include <iostream>
#include <fstream>
#include "student.h"

void teacher_portal(user * u1);
void student_portal(user *u1);

int main()
{
	user* u1 = nullptr;

	
	int choice1;
	do {
		system("cls");
		std::cout << "\t\t\t\t**********Student and Teacher Data Registration and Management System**********\n\n\n";
		std::cout << "Use the system as \n\n";
		std::cout << "1 :: Teacher\n";
		std::cout << "2 :: Student\n";
		std::cout << "3 :: Exit\n";

		std::cout << "\nEnter choice ::";
		std::cin >> choice1;

		switch (choice1) {
			case 1:
				teacher_portal(u1);
				break;
			case 2:
				student_portal(u1);
				break;
			case 3:
				std::cout << "\nThank you for using our system\n\n\n";
				break;
			default:
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid Selection\nPress any enter key to return.......";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				
		}

	} while (choice1 != 3);

	return 0;
}
