#ifndef SCHEDULEITEM_H
#define SCHEDULEITEM_H

#include <iostream>
#include <string>

using namespace std;

class scheduleItem
{
private:
	string subject, catalog, section, component, session, instructor;
	int units, totEnrl, capEnrl;

public:
	//Constructor default
	scheduleItem(string sub = "", string cat = "", string sec = "", string comp = "", string sess = "", int uni = 0, int totEn = 0, int capEn = 0, string inst = "") :
		subject(sub), catalog(cat), section(sec), component(comp), session(sess), units(uni), totEnrl(totEn), capEnrl(capEn), instructor(inst) {}

	//Getters
	string getSubject() const {
		return subject;
	}
	string getCatalog() const {
		return catalog;
	}
	string getSection() const {
		return section;
	}
	string getComponent() const {
		return component;
	}
	string getSession() const {
		return session;
	}
	int getUnits() const {
		return units;
	}
	int getTotEnrl() const {
		return totEnrl;
	}
	int getCapEnrl() const {
		return capEnrl;
	}
	string getInstructor() const {
		return instructor;
	}

	//Overload operators
	bool operator==(const scheduleItem& key) const {
		return subject == key.subject && catalog == key.catalog && section == key.section;
	}

	bool operator!=(const scheduleItem& key) const {
		return !(*this == key);
	}

	bool operator>=(const scheduleItem& key) const {
		string actualKey = subject + "_" + catalog + "_" + section;
		string otherKey = key.subject + key.catalog + key.section;
	}

	void print() const {
		std::cout << subject << "     " << catalog << "     " << section << "     "
			<< component << "       " << session << "      " << units << "     "
			<< totEnrl << "             " << capEnrl << "           " << instructor << std::endl;
	}
};

#endif //SCHEDULEITEM_H