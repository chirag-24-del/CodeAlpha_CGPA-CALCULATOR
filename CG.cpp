#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // for std::setprecision

using namespace std;

// Function to calculate GPA and total credits
void calculateGPAAndCGPA(const vector<pair<string, pair<int, double>>>& courses, double& gpa, int& totalCredits, double& totalGradePoints) {
    totalCredits = 0;
    totalGradePoints = 0.0;

    for (const auto& course : courses) {
        int credits = course.second.first;
        double gradePoint = course.second.second;
        totalCredits += credits;
        totalGradePoints += gradePoint * credits;
    }

    gpa = (totalCredits > 0) ? (totalGradePoints / totalCredits) : 0.0;
}

// Function to display results
void displayResults(const vector<pair<string, pair<int, double>>>& courses, double gpa, int totalCredits, double totalGradePoints) {
    cout << "Course Details:\n";
    for (const auto& course : courses) {
        cout << "Course: " << course.first << ", Credits: " << course.second.first
             << ", Grade Point: " << course.second.second << endl;
    }

    cout << fixed << setprecision(2);
    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "GPA for the semester: " << gpa << endl;
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;
    cin.ignore(); // to ignore the newline character after entering numCourses

    vector<pair<string, pair<int, double>>> courses;

    for (int i = 0; i < numCourses; ++i) {
        string courseName;
        int credits;
        double gradePoint;

        cout << "Enter the name of course " << (i + 1) << ": ";
        getline(cin, courseName);

        cout << "Enter the credits for " << courseName << ": ";
        cin >> credits;

        cout << "Enter the grade point for " << courseName << ": ";
        cin >> gradePoint;
        cin.ignore(); // to ignore the newline character after entering gradePoint

        courses.emplace_back(courseName, make_pair(credits, gradePoint));
    }

    double gpa;
    int totalCredits;
    double totalGradePoints;

    calculateGPAAndCGPA(courses, gpa, totalCredits, totalGradePoints);
    displayResults(courses, gpa, totalCredits, totalGradePoints);

    return 0;
}
