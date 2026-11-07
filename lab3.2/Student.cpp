#include "Student.h"
using namespace std;    

Student::Student() : Man(), university("Невідомо"), course(1) {}

Student::Student(string name, int age, string university, int course)
    : Man(name, age)
{
    setUniversity( university);
    setCourse(course);
}

Student::Student(const Student& other)
    : Man(other) 
{
    university = other.university;
    course = other.course;
}


Student& Student::operator=(const Student& other) {
    if (this != &other) {
       Man::operator=(other); 
        university = other.university;
        course = other.course;
    }
    return *this;
}

void Student::setUniversity(string university) {
    if (university.empty()) {
        cerr << "Помилка: Назва університету не може бути порожньою!" << endl;
        exit(1);
    }
    this->university = university;
}

void Student::setCourse(int course) {
    if (course < 1 || course > 6) {
        cerr << "Помилка: Курс має бути від 1 до 6!" << endl;
        exit(1);
    }
    this->course = course;
}

std::string Student::getUniversity() const { return university; }
int Student::getCourse() const { return course; }

Student::operator string() const {
    return "Студент [Ім'я: " + name + ", Вік: " + to_string(age) +
        ", ВНЗ: " + university + ", Курс: " + to_string(course) + "]";
}


std::ostream& operator<<(std::ostream& out, const Student& s) {
    out << (const Man&)s; 
    out << " " << s.university << " " << s.course;
    return out;
}


istream& operator>>(istream& in, Student& s) {
    in >> (Man&)s; 

    std::string tempUniv;
    int tempCourse;
    in >> tempUniv >> tempCourse;
    s.setUniversity(tempUniv); 
    s.setCourse(tempCourse);
    return in;
}