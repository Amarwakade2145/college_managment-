#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Student {
public:
    string name;
    int rollNumber;
    string department;
    int marks;  
    Student(string name, int rollNumber, string department, int marks)
        : name(name), rollNumber(rollNumber), department(department), marks(marks) {}
    void display() const {
        cout << "Student Name: " << name << ", Roll Number: " << rollNumber << ", Department: " << department << ", Marks: " << marks << endl;
    }
};
class Faculty {
public:
    string name;
    string department;
    Faculty(string name, string department) : name(name), department(department) {}
    void display() const {
        cout << "Faculty Name: " << name << ", Department: " << department << endl;
    }
};
void showFaculty(const vector<Faculty>& facultyList, const string& department) {
    cout << "\nFaculty members in " << department << " department:" << endl;
    bool found = false;
    for (const auto& faculty : facultyList) {
        if (faculty.department == department) {
            faculty.display();
            found = true;
        }
    }
    if (!found) {
        cout << "No faculty members found in this department!" << endl;
    }
}

void showStudents(const vector<Student>& studentList, const string& department) {
    cout << "\nStudents in " << department << " department:" << endl;
    bool found = false;
    int studentCount = 0;
    int highestMarks = -1;
    string topperName;
    for (const auto& student : studentList) {
        if (student.department == department) {
            student.display();
            studentCount++;
            if (student.marks > highestMarks) {
                highestMarks = student.marks;
                topperName = student.name;
            }
            found = true;
        }
    }
    if (!found) {
        cout << "No students found in this department!" << endl;
    } else {
        cout << "\nTopper in " << department << ": " << topperName << " with " << highestMarks << " marks" << endl;
        cout << "Strength of " << department << " department: " << studentCount << " students" << endl;
    }
}

int main() {
    vector<Faculty> facultyList;
    facultyList.push_back(Faculty("Dr. Anil Joshi", "BCA"));
    facultyList.push_back(Faculty("Prof. Neha Deshmukh", "BCA"));
    facultyList.push_back(Faculty("Dr. Rajesh Kumar", "B.Tech"));
    facultyList.push_back(Faculty("Prof. Ravi Yadav", "B.Sc"));
    facultyList.push_back(Faculty("Dr. Meena Verma", "MBA"));
    facultyList.push_back(Faculty("Prof. Rajiv Sharma", "MCA"));

    vector<Student> studentList;
    studentList.push_back(Student("Yash Chipade", 101, "BCA", 89));
    studentList.push_back(Student("Shubham Raskar", 102, "BCA", 92));
    studentList.push_back(Student("Tejas Raykar", 103, "B.Tech", 85));
    studentList.push_back(Student("Akash Varma", 104, "B.Sc", 88));
    studentList.push_back(Student("Anurag Singh", 105, "MBA", 91));
    studentList.push_back(Student("Sanchit Sharma", 106, "MCA", 83));
    studentList.push_back(Student("Vedant Sharma", 107, "BBA", 75));
    studentList.push_back(Student("Rani Yadav", 108, "MBA", 94));

    char choice;
    bool exitProgram = false;

    while (!exitProgram) {
        cout << "\nWelcome to JSPM College, Wagholi" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Enter 'a' to view Faculty" << endl;
        cout << "Enter 'b' to view Students" << endl;
        cout << "Enter 'q' to Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 'a': {
                char deptChoice;
                cout << "\nSelect Department for Faculty:" << endl;
                cout << "1. BCA" << endl;
                cout << "2. B.Tech" << endl;
                cout << "3. B.Sc" << endl;
                cout << "4. MBA" << endl;
                cout << "5. MCA" << endl;
                cout << "6. BBA" << endl;
                cout << "Enter your choice: ";
                cin >> deptChoice;

                string department;
                switch(deptChoice) {
                    case '1': department = "BCA"; break;
                    case '2': department = "B.Tech"; break;
                    case '3': department = "B.Sc"; break;
                    case '4': department = "MBA"; break;
                    case '5': department = "MCA"; break;
                    case '6': department = "BBA"; break;
                    default: cout << "Invalid choice!" << endl; continue;
                }

                showFaculty(facultyList, department);
                break;
            }
            case 'b': {
                char deptChoice;
                cout << "\nSelect Department for Students:" << endl;
                cout << "1. BCA" << endl;
                cout << "2. B.Tech" << endl;
                cout << "3. B.Sc" << endl;
                cout << "4. MBA" << endl;
                cout << "5. MCA" << endl;
                cout << "6. BBA" << endl;
                cout << "Enter your choice: ";
                cin >> deptChoice;

                string department;
                switch(deptChoice) {
                    case '1': department = "BCA"; break;
                    case '2': department = "B.Tech"; break;
                    case '3': department = "B.Sc"; break;
                    case '4': department = "MBA"; break;
                    case '5': department = "MCA"; break;
                    case '6': department = "BBA"; break;
                    default: cout << "Invalid choice!" << endl; continue;
                }

                showStudents(studentList, department);
                break;
            }
            case 'q':
                exitProgram = true;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    cout << "Exiting program. Thank you for using JSPM College system!" << endl;

    return 0;
}