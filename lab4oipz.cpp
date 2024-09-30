#include <iostream>
#include <vector>
#include <string>
using namespace std;
void GUI();

string correctLogin = "admin";
string correctPassword = "1234";

vector<string> students;
vector<int> grades;

void authorization() {
    
    string login, password;
    cout << "Enter login: ";
    cin >> login;
    cout << "Enter password: ";
    cin >> password;
    cin.ignore();
    if (login == correctLogin && password == correctPassword) {
        cout << "Authorization successful" << endl;
        GUI();
    } else {
        cout << "Incorrect login or password, try again " << endl;
        authorization();
    }
}

void enterData(vector<string>& students, vector<int>& grades) {
    string student;
    int grade;
    cout << "Enter students name ";
    getline(cin, student);

    cout << "Enter students grade ";
    cin >> grade;
    cin.ignore();
    if (grade >= 0 && grade <= 100) {
        students.push_back(student);
        grades.push_back(grade);
        cout << "Data was entered" << endl;
    } else {
        cout << "Invalid grade" << endl;
    }
    GUI();
}

double calculateAverage(const vector<int>& grades) {
    double sum = 0;

    for (int grade : grades) {
        sum += grade;
    }

    return (grades.size() == 0) ? 0 : sum / grades.size();
}

void displayMarks(const vector<string>& students, const vector<int>& grades) {
    cout << "Students` marks: " << endl;
    for (int i = 0; i < students.size(); ++i) {
        cout << students[i] << ": " << grades[i] << endl;
    }
    GUI();
}

void generateGroupReport(const vector<string>& students, const vector<int>& grades) {
    int maxGrade = 0;
    int bestStudent = 0;
    for (int i = 0; i < grades.size(); i++){
        if (grades[i] > maxGrade) 
        {
            maxGrade = grades[i];
            bestStudent = i;
        }
    }
    cout << "Best student is " << students[bestStudent] << " with grade " << maxGrade << endl;


    double average = calculateAverage(grades);
    cout << "Average grade: " << average << endl;
    GUI();
}
void GUI(){
    string input;
    cout<< "Enter (data) to insert student`s information, (marks) to display students` ranks, (report) to display student`s report, or (end) to close the program ";
    getline(cin, input);
    if (input == "data") enterData(students, grades);
    else if(input == "marks") displayMarks(students, grades);
    else if(input == "report") generateGroupReport(students, grades);
    else if(input == "end") exit(0);
    else {
        cout << "Incorrect input, try again" << endl;
        GUI();
    }
}

int main() {
    authorization();
    return 0;
}
