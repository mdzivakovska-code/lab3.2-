#pragma once
#include <iostream>
#include <string>
#include <cstdlib> 
using namespace std;   

class Man {
protected:
    string name;
    int age;

public:
  
    Man();
    Man(std::string name, int age);
    Man(const Man& other); 

    
    Man& operator=(const Man& other);

    virtual ~Man() = default;

  
    string getName() const;
    int getAge() const;
    void setName(string name);
    void setAge(int age);

    operator string() const;

    friend ostream& operator<<(ostream& out, const Man& p);
    friend istream& operator>>( istream& in, Man& p);
};