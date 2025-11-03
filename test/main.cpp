#include <iostream>
using namespace std;

int calculateTotal(int marks[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) sum += marks[i];
    return sum;
}

string findGrade(float avg) {
    if (avg >= 90) return "A+";
    else if (avg >= 80) return "A";
    else if (avg >= 70) return "B";
    else if (avg >= 60) return "C";
    else return "F";
}

void verifyGrade(int total, string grade) {
    if ((total >= 450 && grade != "A+") ||
        (total >= 400 && total < 450 && grade != "A") ||
        (total >= 350 && total < 400 && grade != "B") ||
        (total >= 300 && total < 350 && grade != "C") ||
        (total < 300 && grade != "F")) {
        cout << "Mismatch" << endl;
    }
}

int main() {
    int students;
    cout << "Enter number of students: ";
    cin >> students;

    for (int i = 0; i < students; i++) {
        int n;
        cout << "Enter number of subjects for student " << i + 1 << ": ";
        cin >> n;

        int marks[100];
        cout << "Enter marks: ";
        for (int j = 0; j < n; j++) cin >> marks[j];

        int total = calculateTotal(marks, n);
        float avg = (float)total / n;
        string grade = findGrade(avg);

        cout << "Total: " << total << ", Average: " << avg << ", Grade: " << grade << endl;
        verifyGrade(total, grade);
    }

    return 0;
}
