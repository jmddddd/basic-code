#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cstdlib>

struct Student {
    std::string name;
    std::string major;
    std::string student_id;
    char grade;
};

std::vector<std::string> names = {"Jeongmin Woo", "Jisoo Kim", "Minho Lee", "Soojin Park", "Hyunwoo Choi", 
                                  "Jiwon Jung", "Seojin Kang", "Yuna Kim", "Hyejin Lee", "Donghyun Kim"};
std::vector<std::string> majors = {"Department of Automotive and IT Convergence", "Department of Computer Science", 
                                   "Department of Electrical Engineering", "Department of Mechanical Engineering", 
                                   "Department of Civil Engineering"};
std::vector<char> grades = {'A', 'B', 'C', 'D', 'F'};

std::string generateStudentID() {
    return "2022" + std::to_string(rand() % 9000 + 1000);
}

int partition(std::vector<Student>& students, int low, int high) {
    char pivot = students[high].grade;
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (students[j].grade < pivot) {
            ++i;
            std::swap(students[i], students[j]);
        }
    }
    std::swap(students[i + 1], students[high]);
    return i + 1;
}

void quickSort(std::vector<Student>& students, int low, int high) {
    if (low < high) {
        int pivot = partition(students, low, high);
        quickSort(students, low, pivot - 1);
        quickSort(students, pivot + 1, high);
    }
}

int main() {
    srand(time(0));
    std::vector<Student> students;

    for (int i = 0; i < 10; ++i) {
        Student student;
        student.name = names[i];
        student.major = majors[rand() % majors.size()];
        student.student_id = generateStudentID();
        student.grade = grades[rand() % grades.size()];
        students.push_back(student);
    }

    quickSort(students, 0, students.size() - 1);

    for (const auto& student : students) {
        std::cout << student.name << ", " << student.major << ", " << student.student_id << ", " << student.grade << std::endl;
    }

    return 0;
}