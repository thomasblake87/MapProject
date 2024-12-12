#include "schedule.h"
#include <fstream>

using namespace std;

int main() {
	schedule schedule;

	//Open data file
	ifstream input("classes.csv");
	
	schedule.initSchedule(input);
	input.close();

	//Menu
	int choice = 0;
	while(choice != 5) {
		cout << "Choose an option: " << endl;
		cout << "1. Print full schedule" << endl;
		cout << "2. Print by subject" << endl;
		cout << "3. Print by subject and catalog number" << endl;
		cout << "4. Print by instructor's last name" << endl;
		cout << "5. Quit" << endl;
		cin >> choice;


		if (choice == 1) {
			schedule.printHeader();
			schedule.print();
		}
		else if (choice == 2) {
			string sub = "XXX";
			cout << "Please enter the subject (3 letters): ";
			cin >> sub;
			if (sub.length() != 3) {
				sub = "XXX";
				cout << "\nThe subject must be 3 letters.\n";
			}
			else {
				schedule.printHeader();
				schedule.findBySubject(sub);
			}
		}
		else if (choice == 3) {
			string sub = "XXX";
			cout << "Please enter the subject (3 letters): ";
			cin >> sub;
			if (sub.length() != 3) {
				sub = "XXX";
				cout << "\nThe subject must be 3 letters.\n";
			}
			string cat = "111";
			cout << "Please enter a catalog number (1-3 numbers): ";
			cin >> cat;
			if (cat.length() > 3 || cat.length() < 1) {
				cat = "111";
				cout << "\nThe catalog number must be 1-3 numbers.\n";
			}
			else {
				schedule.printHeader();
				schedule.findBySubjectAndCatalog(sub, cat);
			}
		}
		else if (choice == 4) {
			string lName = "";
			cout << "Please enter the instructors last name: ";
			cin >> lName;
			schedule.findByInstructor(lName);
		}
	}
}