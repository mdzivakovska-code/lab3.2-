#include <iostream>
#include "Man.h"
#include "Student.h"
#include"windows.h"
using namespace std;

Man processPerson(Man  p) {
    cout << "--- Функція processPerson викликана ---" << endl;
    cout << "Отримано об'єкт: " << string(p) << endl;
    p.setAge(p.getAge() + 1); 
    return p;
}

int main() {
   
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);

    cout << "1. Створення об'єктів та перевірка конструкторів:\n";
    Man p1("Іван", 25);
    Student s1("Марія", 19, "ДДПУ", 2);

    cout << string(p1) << endl;
    cout << string(s1) << endl;

    cout << "\n2. Демонстрація принципу підстановки:\n";

    Man p2 = processPerson(s1);
    cout << "Результат після функції: " << string(p2) << endl;

    std::cout << "\n3. Перевірка конструктора копіювання та присвоєння (Student):\n";
    Student s2 = s1; 
    Student s3;
    s3 = s2;        

    s3.setName("Олексій"); 
    std::cout << "s2 (копія): " << (std::string)s2 << std::endl;
    std::cout << "s3 (після присвоєння та зміни): " << (std::string)s3 << std::endl;

    std::cout << "\n4. Масив об'єктів та потокове введення/виведення:\n";
    const int SIZE = 2;
    Student students[SIZE];

  
    cout << "Введіть дані 2 студентів (Ім'я Вік Університет Курс):\n";
     for(int i = 0; i < SIZE; i++) {
    cin >> students[i];
    }

    cout << "\nВиведення масиву через потоки:\n";
     for(int i = 0; i < SIZE; i++) {
         cout << students[i] << endl;
    }

    cout << "\n5. Перевірка валідації (викличе помилку і завершить програму):\n";
    cout << "Спроба встановити від'ємний вік...\n";
    p1.setAge(-5); 

    return 0;
}