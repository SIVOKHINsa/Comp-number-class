#include "Comp_number_class.h"
#include <iostream>

const double E = 1e-7;

void Comp_number::set_imaginary_part(double number) {
    imaginary_part = number;
}

void Comp_number::set_valid_part(double number) {
    valid_part = number;
}

double Comp_number::get_imaginary_part() {
    return imaginary_part;
}

double Comp_number::get_valid_part() {
    return valid_part;
}

void Comp_number::print() {
    std::cout << valid_part << (imaginary_part < 0 ? " - " : " + ") 
        << abs(imaginary_part) << "i" << endl;
}

Comp_number Comp_number::operator+(const Comp_number& B) {
    double valid_part_res = valid_part + B.valid_part;
    double imaginary_part_res = imaginary_part + B.imaginary_part;

    return Comp_number(valid_part_res, imaginary_part_res);
}

Comp_number Comp_number::operator-(const Comp_number& B) {
    double valid_part_res = valid_part - B.valid_part;
    double imaginary_part_res = imaginary_part - B.imaginary_part;

    return Comp_number(valid_part_res, imaginary_part_res);
}

Comp_number Comp_number::operator*(const Comp_number& B) {
    double valid_part_res = valid_part * B.valid_part - imaginary_part * B.imaginary_part;
    double imaginary_part_res = B.imaginary_part * valid_part + imaginary_part * B.valid_part;

    return Comp_number(valid_part_res, imaginary_part_res);
}

Comp_number Comp_number::operator/(const Comp_number& B) {
    double valid_part_res = (valid_part * B.valid_part + imaginary_part * B.imaginary_part) /
        (B.valid_part * B.valid_part + B.imaginary_part * B.imaginary_part);
    double imaginary_part_res = (imaginary_part * B.valid_part - valid_part * B.imaginary_part) /
        (B.valid_part * B.valid_part + B.imaginary_part * B.imaginary_part);

    return Comp_number(valid_part_res, imaginary_part_res);
}

bool Comp_number::operator==(const Comp_number& B) {
    return (fabs(valid_part - B.valid_part) < E && fabs(imaginary_part - B.imaginary_part) < E);
}

bool Comp_number::operator!=(const Comp_number& B) {
    return !(fabs(valid_part - B.valid_part) < E && fabs(imaginary_part - B.imaginary_part) < E);
}

bool Comp_number::operator==(double num) {
    return fabs(valid_part - num) < E;
}

bool Comp_number::operator!=(double num) {
    return !(fabs(valid_part - num) < E);
}

double Comp_number::module() {
    return sqrt(pow(valid_part, 2) + pow(imaginary_part, 2)); 
}

Comp_number Comp_number::comp_pow(int step){
    double modul = module();
    double angle = atan(imaginary_part / valid_part);
    double valid_part_res = pow(modul, step) * cos(angle * step);
    double imaginary_part_res = pow(modul, step) * sin(angle * step);

    return Comp_number(valid_part_res, imaginary_part_res);
}

