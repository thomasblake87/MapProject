#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <utility>
#include <string>
#include <sstream>
#include "scheduleItem.h"

using namespace std;

class schedule {
private:
    map<string, scheduleItem> scheduleMap;

    // Helper function: creates a unique key
    string createKey(const string& subject, const string& catalog, const string& section) {
        return subject + "_" + catalog + "_" + section;
    }

public:
    // Add a scheduleItem to the map
    void addEntry(const scheduleItem& item) {
        string key = createKey(item.getSubject(), item.getCatalog(), item.getSection());
        scheduleMap[key] = item;
    }

    // Initialize schedule from a file
    void initSchedule(ifstream& file) {
        string line;
        getline(file, line); // Skip the header row

        while (getline(file, line)) {
            istringstream stream(line);
            string subject, catalog, section, component, session, instructor;
            int units = 0, totEnrl = 0, capEnrl = 0;

            getline(stream, subject, ',');
            getline(stream, catalog, ',');
            getline(stream, section, ',');
            getline(stream, component, ',');
            getline(stream, session, ',');
            stream.ignore(256, ',');
            stream >> units;
            stream.ignore(256, ',');
            stream >> totEnrl;
            stream.ignore(256, ',');
            stream >> capEnrl;
            stream.ignore(256, '"');
            getline(stream, instructor, '"');

            scheduleItem item(subject, catalog, section, component, session, units, totEnrl, capEnrl, instructor);
            addEntry(item);
        }
    }

    void printHeader() const {
        cout << "Subject " << "Catalog " << "Section " << "Component " << "Session " << "Units " << "Total enrolled " << "Cap enrolled " << "Instructor " << endl;
    }

    // Print the schedule
    void print() const {
        for (auto x = scheduleMap.begin(); x != scheduleMap.end(); ++x) {
            x->second.print();
        }
    }

    // Find by subject
    void findBySubject(const string& subject) const {
        for (auto x = scheduleMap.begin(); x != scheduleMap.end(); ++x) {
            if (x->second.getSubject() == subject) {
                x->second.print();
            }
        }
    }

    // Find by subject and catalog
    void findBySubjectAndCatalog(const string& subject, const string& catalog) const {
        for (auto x = scheduleMap.begin(); x != scheduleMap.end(); ++x) {
            if (x->second.getSubject() == subject && x->second.getCatalog() == catalog) {
                x->second.print();
            }
        }
    }

    // Find by instructor
    void findByInstructor(const string& lastName) const {
        for (auto x = scheduleMap.begin(); x != scheduleMap.end(); ++x) {
            if (x->second.getInstructor().find(lastName) != -1) {
                x->second.print();
            }
        }
    }
};

#endif
