#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Person {
public:
    string pname;
    int level;
    int pid;
    static int total;

    Person(string n, int l) {
        pname = n;
        level = l;
        pid = ++total;
    }

    bool operator>(const Person& other) const {
        return level > other.level;
    }
};

int Person::total = 0;

void displayOptions() {
    cout << "\nPatient Queue System\n";
    cout << "1. Insert Patient\n";
    cout << "2. Attend Patient\n";
    cout << "3. List Queue\n";
    cout << "4. Illness Priority\n";
    cout << "5. Quit\n";
    cout << "Select: ";
}

void illnessList() {
    cout << "\nIllness Categories:\n";
    cout << "1. Heart Attack - 1\n";
    cout << "2. Stroke - 1\n";
    cout << "3. Severe Burn - 2\n";
    cout << "4. Broken Leg - 2\n";
    cout << "5. Fractured Arm - 2\n";
    cout << "6. Fever - 3\n";
    cout << "7. Food Poisoning - 3\n";
    cout << "8. Migraine - 3\n";
    cout << "9. Mild Cold - 4\n";
    cout << "10. Small Cut - 4\n";
}

int main() {
    priority_queue<Person, vector<Person>, greater<Person>> queue;
    int option;

    do {
        displayOptions();
        cin >> option;
        cin.ignore();

        if (option == 1) {
            string pname;
            int plevel;
            cout << "Patient name: ";
            getline(cin, pname);
            illnessList();
            cout << "Enter priority (1-4): ";
            cin >> plevel;
            queue.push(Person(pname, plevel));
            cout << "Patient recorded.\n";
        } 
        else if (option == 2) {
            if (!queue.empty()) {
                Person current = queue.top();
                queue.pop();
                cout << "Now treating: " << current.pname << " (Priority: " << current.level << ")\n";
            } else {
                cout << "Queue empty.\n";
            }
        } 
        else if (option == 3) {
            if (queue.empty()) {
                cout << "Queue empty.\n";
            } else {
                priority_queue<Person, vector<Person>, greater<Person>> temp = queue;
                cout << "Pending Patients:\n";
                while (!temp.empty()) {
                    Person p = temp.top();
                    cout << "- " << p.pname << " (Priority: " << p.level << ")\n";
                    temp.pop();
                }
            }
        }
        else if (option == 4) {
            illnessList();
        }
        else if (option == 5) {
            cout << "System terminated.\n";
        } 
        else {
            cout << "Invalid entry.\n";
        }
    } while (option != 5);

    return 0;
}
