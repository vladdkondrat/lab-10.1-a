#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

// Перелічуваний тип для спеціальностей
enum Speciality { COMPUTER_SCIENCE, INFORMATICS, MATH_ECONOMICS, PHYSICS_INFORMATICS, LABOR_TEACHING };
string specialityStr[] = { "COMPUTER_SCIENCE", "INFORMATICS", "MATH_ECONOMICS", "PHYSICS_INFORMATICS", "LABOR_TEACHING" };

// Структура для зберігання інформації про студента
struct Student {
    string surname;
    int course;
    Speciality speciality;
    int physicsGrade;
    int mathGrade;
    int informaticsGrade;
};

// Функція для введення інформації про студентів
void inputStudents(vector<Student>& students, int n) {
    for (int i = 0; i < n; i++) {
        Student s;
        cout << "surname ";
        cin >> s.surname;
        cout << "course ";
        cin >> s.course;
        int spec;
        cout << "speciality(0 - COMPUTER_SCIENCE, 1 -INFORMATICS, 2 - MATH_ECONOMICS, 3 -PHYSICS_INFORMATICS, 4 - LABOR_TEACHING): ";
        cin >> spec;
        s.speciality = static_cast<Speciality>(spec);
        cout << "Enter a grade in Physics: ";
        cin >> s.physicsGrade;
        cout << "Enter a grade in Math: ";
        cin >> s.mathGrade;
        cout << "Enter a grade in Informatic: ";
        cin >> s.informaticsGrade;
        students.push_back(s);
    }
}

// Функція для виведення масиву студентів
void printStudents(const vector<Student>& students) {
    cout << "===================================================================" << endl;
    cout << "| № | Surname     | Coure | Speciality        | Physic | Math| Informatic |" << endl;
    cout << "-------------------------------------------------------------------" << endl;

    for (size_t i = 0; i < students.size(); i++) {
        cout << "| " << setw(2) << i + 1 << " | " << setw(12) << left << students[i].surname
            << " | " << setw(4) << right << students[i].course
            << " | " << setw(20) << left << specialityStr[students[i].speciality]
            << " | " << setw(6) << students[i].physicsGrade
            << " | " << setw(10) << students[i].mathGrade
            << " | " << setw(12) << students[i].informaticsGrade << " |" << endl;
    }
    cout << "===================================================================" << endl;
}

// Функція для підрахунку оцінок з математики
int countMathGrades(const vector<Student>& students, int grade) {
    int count = 0;
    for (const auto& student : students) {
        if (student.mathGrade == grade) {
            count++;
        }
    }
    return count;
}

// Функція для виведення студентів з оцінками 5 з фізики та математики
void printTopStudents(const vector<Student>& students) {
    cout << "Students who received 5 in Physics and Mathematics:" << endl;
    for (const auto& student : students) {
        if (student.physicsGrade == 5 && student.mathGrade == 5) {
            cout << student.surname << endl;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    vector<Student> students;
    inputStudents(students, n);

    printStudents(students);

    // Завдання: кількість оцінок з математики
    int grade5 = countMathGrades(students, 5);
    int grade4 = countMathGrades(students, 4);
    int grade3 = countMathGrades(students, 3);
    cout << "Number of grades: 5 in Mathematics: " << grade5 << endl;
    cout << "Number of grades: 4 in Mathematics " << grade4 << endl;
    cout << "Number of grades: 3 in Mathematics " << grade3 << endl;

    // Завдання: прізвища студентів з оцінками 5 з фізики і математики
    printTopStudents(students);

    return 0;
}
