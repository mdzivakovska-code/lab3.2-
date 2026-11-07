#include "pch.h"
#include "CppUnitTest.h"
#include "../lab3.2/Man.h"
#include "../lab3.2/Student.h"
#include "../lab3.2/Man.cpp"
#include "../lab3.2/Student.cpp"  
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            Man p("Іван", 25);

            Assert::AreEqual(string("Іван"), p.getName());
            Assert::AreEqual(25, p.getAge());
        }

        TEST_METHOD(StudentConstructor_SetsBaseAndDerivedValues)
        {
            Student s("Марія", 19, "ДДПУ", 2);

      
            Assert::AreEqual(string("Марія"), s.getName());
            Assert::AreEqual(19, s.getAge());

         
            Assert::AreEqual(string("ДДПУ"), s.getUniversity());
            Assert::AreEqual(2, s.getCourse());
        }

        TEST_METHOD(PersonStringConversion_FormatsStringCorrectly)
        {
            Man p("Олег", 30);
            string expected = "Людина [Ім'я: Олег, Вік: 30]";

            Assert::AreEqual(expected, (string)p);
        }

        TEST_METHOD(StudentStringConversion_FormatsStringCorrectly)
        {
            Student s("Анна", 20, "ЛНУ", 3);
            string expected = "Студент [Ім'я: Анна, Вік: 20, ВНЗ: ЛНУ, Курс: 3]";

            Assert::AreEqual(expected, (string)s);
        }

        TEST_METHOD(StudentCopyConstructor_CopiesAllFields)
        {
            Student original("Максим", 21, "КПІ", 4);
            Student copy(original);

            Assert::AreEqual(string("Максим"), copy.getName());
            Assert::AreEqual(21, copy.getAge());
            Assert::AreEqual(string("КПІ"), copy.getUniversity());
            Assert::AreEqual(4, copy.getCourse());
        }
    };
}
