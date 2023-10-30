#include "Comp_number_class.h"
#include <iostream>
#include <assert.h>

using namespace std;

void TestgetValidPart(){
	Comp_number t1(4.1, -7);
	assert(t1.get_valid_part() == 4.1);
	cout << "TestgetValidPart is OK" << endl;
}

void TestgetImaginaryPart() {
	Comp_number t1(4.1, -7);
	assert(t1.get_imaginary_part() == -7);
	cout << "TestgetImaginaryPart is OK" << endl;
}

void TestMethodSet() {
	Comp_number t1(4.1, -7);
	t1.set_valid_part(7);
	t1.set_imaginary_part(91);
	assert(t1.get_valid_part() == 7);
	assert(t1.get_imaginary_part() == 91);
	cout << "TestMethodSet is OK" << endl;
}

void TestMethodModule(){
	Comp_number t1(4, -3);
	assert(t1.module() == 5);
	cout << "TestMethodModule is OK" << endl;
}

void TestEqualityOperators()
{
	Comp_number t1(4.1, -7), t2(4.1, -7), t3(1, 5);
	double num = 5;
	assert(t1 == t2);
	assert(t1 != t3);
	assert(t1 != num);
	cout << "TestEqualityOperators is OK" << endl;
}

void TestSumOperators() {
	Comp_number t1(4.1, -7), t2(4.1, -7);
	Comp_number sum = t1 + t2, ans(8.2, -14);
	assert(sum == ans);
	cout << "TestSumOperators is OK" << endl;

}

void TestSubtractionOperators() {
	Comp_number t1(4.1, -7), t2(1, 5);
	Comp_number subtraction = t1 - t2, ans(3.1, -12);
	assert(subtraction == ans);
	cout << "TestSubtractionOperators is OK" << endl;
}

void TestMultiplicationOperators() {
	Comp_number t1(4.1, -7), t2(1, 5);
	Comp_number multiplication = t1 * t2, ans(39.1, 13.5);
	assert(multiplication == ans);
	cout << "TestMultiplicationOperators is OK" << endl;
}

void TestDivisionOperators() {
	Comp_number t1(4.1, -7), t2(4.1, -7);
	Comp_number division = t1 / t2, ans(1, 0);
	assert(division == ans);
	cout << "TestDivisionOperators is OK" << endl;
}

void TestCompPowMethod() {
	Comp_number t1(2, 3), ans(-46, 9);
	assert(t1.comp_pow(3) == ans);
	cout << "TestCompPowMethod is OK" << endl;
}


int main() {
	TestgetValidPart();
	TestgetImaginaryPart();
	TestMethodSet();
	TestMethodModule();
	TestEqualityOperators();
	TestSumOperators();
	TestSubtractionOperators();
	TestMultiplicationOperators();
	TestDivisionOperators();
	TestCompPowMethod();
	return 0;
}