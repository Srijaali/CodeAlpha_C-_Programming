// The user’s input is used to compute the CGPA, which
// includes information like the number of courses taken and
// the grades earned in each one. The program also shows each
// student’s overall course grade. CGPA Calculator calculates a
// student’s Cumulative Grade Point Average (CGPA) from the
// given exam results. The program can show the individual
// grades of each course, calculate total credits and total grade
// points achieved, determine the GPA for the semester, and
// based on all the data, it can generate and present the CGPA
// of the student.

#include <iostream>
using namespace std;

class CGPA{
    private:
    float grades[10];
    int courses;
    int creditHours[10];
    int totalCredits;
    float gpa;
    float totalGradePoints;
    int ccredits;
    float totalcgpa;


    public:
    CGPA() : courses(0) , totalCredits(0) , gpa(0.0) , totalGradePoints(0.0) , ccredits(0) , totalcgpa(0.0) {}

   void calcCGPA(){
        cout << "Enter the numer of courses you have taken this semester: " << endl;
        cin >> courses;

        for(int i=0; i<courses; i++){
            cout << "Enter the credit hour for course " << i+1 << endl;
            cin>>creditHours[i];
        }

        for(int i=0;i<courses; i++){
            cout << "enter the grade for course " << i+1 << "(1.00-4.00): " <<endl;
            cin>>grades[i];
        }

        for(int i=0;i<courses;i++){
            cout << "Grades for course " << i+1 << ": " << grades[i] << endl; 
        }
   }

    void calculateGPA() {
        totalCredits = 0;
        totalGradePoints = 0.0;

        for (int i = 0; i < courses; i++) {
            totalCredits += creditHours[i];
            totalGradePoints += creditHours[i] * grades[i];
        }

        if (totalCredits > 0) {
            gpa = totalGradePoints / totalCredits;
        }

        cout << "Total credit hours: " << totalCredits << endl;
        cout << "The GPA is: " << gpa << endl;
    }
       

    
 void calculateCGPA() {
        float cgpa = 0.0;
        if (ccredits > 0) {
            cgpa = totalcgpa / ccredits;
        }
        cout << "The Cumulative GPA (CGPA) is: " << cgpa << endl;
    }
};

int main() {
    char choice;
    CGPA result;

    do {
        result.calcCGPA();
        result.calculateGPA();
        
        cout << "Do you want to enter another semester's data? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    result.calculateCGPA();

    return 0;
}
