#pragma once
#include "Man.h"
using namespace std;    
class Student : public Man {
private:
    string university;
    int course;

public:
    Student();
    Student(string name, int age,   string university, int course);

   
    Student(const Student& other);

    
    Student& operator=(const Student& other);

    string getUniversity() const;
    int getCourse() const;
    void setUniversity(string university);
    void setCourse(int course);

    operator string() const;

    friend ostream& operator<<(ostream& out, const Student& s);
    friend istream& operator>>(istream& in, Student& s);
};