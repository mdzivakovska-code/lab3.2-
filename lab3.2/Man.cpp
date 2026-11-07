#include "Man.h"
using namespace std;

Man::Man() : name("Невідомо"), age(0) {}


Man::Man (string name, int age) {
    setName(name);
    setAge(age);
}

Man::Man(const Man& other) : name(other.name), age(other.age) {}


Man& Man::operator=(const Man& other) {
    if (this != &other) {
        name = other.name;
        age = other.age;
    }
    return *this;
}


void Man::setName(string name) {
    if (name.empty()) {
        cerr << "Помилка: Ім'я не може бути порожнім!" << endl;
        exit(1); 
    }   
    this->name = name;
}

void Man::setAge(int age) {
    if (age < 0 || age > 120) {
        cerr << "Помилка: Неприпустимий вік!" << endl;
        exit(1);
    }
    this->age = age;
}

string Man::getName() const { return name; }
int Man::getAge() const { return age; }


Man::operator string() const {
    return "Людина [Ім'я: " + name + ", Вік: " + to_string(age) + "]";
}


std::ostream& operator<<(std::ostream& out, const Man& p) {
    out << p.name << " " << p.age;
    return out;
}

std::istream& operator>>(std::istream& in, Man& p) {
    string tempName;
    int tempAge;
    in >> tempName >> tempAge;
    p.setName(tempName); 
    p.setAge(tempAge);
    return in;
}