#include "globallibs.h"
#include "vector.h"

double Vect::getLength() {
    return hypot(x, y);
}

void Vect::add (Vect *V) {
    x += V->x;
    y += V->y;
}

void Vect::sub (Vect *V) {
    x -= V->x;
    y -= V->y;
}

double Vect::mult (Vect *V) {
    return this->x * V->x + this->y * V->y;
}

void Vect::setX(const double x) {
    this->x = x;
}

void Vect::setY(const double y) {
    this->y = y;
}

double Vect::getX() {
    return this->x;
}

double Vect::getY() {
    return this->y;
}

void Vect::operator +(Vect V) {
    this->add(&V);
}

void Vect::operator -(Vect V) {
    this->sub(&V);
}

double Vect::operator *(Vect V) {
    return this->mult(&V);
}
