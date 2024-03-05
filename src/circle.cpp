// Copyright 2024 Dmitry Vanushkin

#include <cstdint>
#include <stdexcept>
#include "circle.h"

const double Circle::PI = std::atan(1.0) * 4;

Circle::Circle(double radius): radius(radius) {}

double Circle::ValidatePositiveOrError(double value) {
    if (value <= 0) {
        throw std::logic_error("value must be positive");
    }
    return value;
}

Circle Circle::CreateByRadius(double radius) {
    return Circle(ValidatePositiveOrError(radius));
}

Circle Circle::CreateBySquare(double square) {
    return Circle(sqrt(ValidatePositiveOrError(square) / PI));
}

Circle Circle::CreateByFerence(double ference) {
    return Circle(ValidatePositiveOrError(ference) / (2 * PI));
}

double Circle::GetRadius() const {
    return radius;
}

double Circle::GetSquare() const {
    return PI * radius * radius;
}

double Circle::GetFerence() const {
    return 2 * PI * radius;
}

void Circle::SetRadius(double radius) {
    Circle::radius = ValidatePositiveOrError(radius);
}

void Circle::SetFerence(double ference) {
    SetRadius(ValidatePositiveOrError(ference) / (2 * PI));
}

void Circle::SetSquare(double square) {
    SetRadius(sqrt(ValidatePositiveOrError(square) / PI));
}
