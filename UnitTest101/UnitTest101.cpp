#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 10.1/lab 10.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101
{
	TEST_CLASS(UnitTest101)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			{ vector<Student> students = { 
				{"Ivanov", 1, COMPUTER_SCIENCE, 5, 5, 5},
                {"Petrov", 2, INFORMATICS, 4, 4, 4},
				{"Sidorov", 3, MATH_ECONOMICS, 3, 3, 3}, 
				{"Smith", 1, PHYSICS_INFORMATICS, 5, 5, 5} }; 
			Assert::AreEqual(2, countMathGrades(students, 5));
			Assert::AreEqual(1, countMathGrades(students, 4));
			Assert::AreEqual(1, countMathGrades(students, 3)); }
		}
	};
}
