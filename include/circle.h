// Copyright 2024 Dmitry Vanushkin
#pragma once

#include <cmath>

class Circle {
 private:
    static const double PI;

    double radius;

    explicit Circle(double radius);

 public:
    static Circle CreateByRadius(double radius);
    static Circle CreateBySquare(double square);
    static Circle CreateByFerence(double ference);

 public:
    double GetRadius() const;
    double GetSquare() const;
    double GetFerence() const;

    void SetRadius(double radius);
    void SetFerence(double ference);
    void SetSquare(double square);

 private:
    static double ValidatePositiveOrError(double value);
};
