#pragma once

using namespace std;

class Comp_number {
private:
    double imaginary_part;
    double valid_part;

public:

    Comp_number(double real, double imaginary) : valid_part(real), imaginary_part(imaginary) {}

    void set_imaginary_part(double number);

    void set_valid_part(double number);

    double get_imaginary_part();

    double get_valid_part();

    void print();

    Comp_number operator+(const Comp_number& B);

    Comp_number operator-(const Comp_number& B);

    Comp_number operator*(const Comp_number& B);

    Comp_number operator/(const Comp_number& B);

    bool operator==(const Comp_number& B);

    bool operator!=(const Comp_number& B);

    bool operator==(double num);

    bool operator!=(double num);

    double module();

    Comp_number comp_pow(int step);

};
