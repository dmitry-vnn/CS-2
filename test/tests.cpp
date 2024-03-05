// Copyright 2024 Dmitry Vanushkin

#include <gtest/gtest.h>
#include <cstdint>

#include "circle.h"
#include "tasks.h"

double PI = 4 * std::atan(1);
double EPS = 1e-5;

TEST(circle, create_by_5_radius_and_assert_radius) {
    auto circle = Circle::CreateByRadius(5);
    ASSERT_EQ(circle.GetRadius(), 5);
}

TEST(circle, create_by_10_radius_assert_square_and_ference) {
    auto radius = 10;
    auto circle = Circle::CreateByRadius(radius);

    ASSERT_NEAR(circle.GetSquare(), radius * radius * PI, EPS);
    ASSERT_NEAR(circle.GetFerence(), 2 * radius * PI, EPS);
}

TEST(circle, create_by_100_square_and_assert_square) {
    auto square = 100;
    auto circle = Circle::CreateBySquare(square);

    ASSERT_NEAR(circle.GetSquare(), square, EPS);
}

TEST(circle, create_by_100_square_and_assert_radius_and_ference) {
    auto square = 100;
    auto circle = Circle::CreateBySquare(square);

    auto actualRadius = sqrt(square / PI);

    ASSERT_NEAR(circle.GetRadius(), actualRadius, EPS);
    ASSERT_NEAR(circle.GetFerence(), 2 * actualRadius * PI, EPS);
}

TEST(circle, create_by_30_ference_and_assert_it) {
    auto ference = 30;
    auto circle = Circle::CreateByFerence(ference);

    ASSERT_NEAR(circle.GetFerence(), ference, EPS);
}

TEST(circle, create_by_30_ference_and_assert_radius_and_square) {
    auto ference = 30;

    auto circle = Circle::CreateByFerence(ference);

    auto actualRadius = ference / (2 * PI);

    ASSERT_NEAR(circle.GetRadius(), actualRadius, EPS);
    ASSERT_NEAR(circle.GetSquare(), PI * actualRadius * actualRadius, EPS);
}

TEST(circle, create_by_radius_reset_it_and_assert) {
    auto radius = 31.5234;
    auto newRadius = 100.25;

    auto circle = Circle::CreateByRadius(radius);

    circle.SetRadius(newRadius);

    ASSERT_NEAR(circle.GetRadius(), newRadius, EPS);
}

TEST(circle, create_by_square_reset_it_and_assert) {
    auto square = 130.345352;
    auto newSquare = 70.9557358;

    auto circle = Circle::CreateBySquare(square);

    circle.SetSquare(newSquare);

    ASSERT_NEAR(circle.GetSquare(), newSquare, EPS);
}

TEST(circle, create_by_ference_reset_it_and_assert) {
    auto ference = 10.528525285205259;
    auto newFerence = 28.53251525;

    auto circle = Circle::CreateByFerence(ference);

    circle.SetFerence(newFerence);

    ASSERT_NEAR(circle.GetFerence(), newFerence, EPS);
}

TEST(circle, create_by_radius_reset_it_and_assert_square_and_ference) {
    auto radius = 40;
    auto newRadius = 200;

    auto circle = Circle::CreateByRadius(radius);

    circle.SetRadius(newRadius);

    ASSERT_NEAR(circle.GetSquare(), newRadius * newRadius * PI, EPS);
    ASSERT_NEAR(circle.GetFerence(), 2 * newRadius * PI, EPS);
}

TEST(circle, create_by_square_reset_it_and_assert_radius_and_ference) {
    auto square = 40;
    auto newSquare = 925.4;

    auto circle = Circle::CreateBySquare(square);

    circle.SetSquare(newSquare);

    auto actualRadius = sqrt(newSquare / PI);

    ASSERT_NEAR(circle.GetRadius(), actualRadius, EPS);
    ASSERT_NEAR(circle.GetFerence(), 2 * actualRadius * PI, EPS);
}

TEST(circle, create_by_ference_reset_it_and_assert_radius_and_square) {
    auto ference = 41230;
    auto newFerence = 0.00001;

    auto circle = Circle::CreateByFerence(ference);

    circle.SetFerence(newFerence);

    auto actualRadius = newFerence / (2 * PI);

    ASSERT_NEAR(circle.GetRadius(), actualRadius, EPS);
    ASSERT_NEAR(circle.GetSquare(), actualRadius * actualRadius * PI, EPS);
}

TEST(circle, create_by_radius_reset_square_and_assert_radius_and_ference) {
    auto radius = 30.5552;
    auto newSquare = 29.9994;

    auto circle = Circle::CreateByRadius(radius);

    circle.SetSquare(newSquare);

    auto actualRadius = sqrt(newSquare / PI);

    ASSERT_NEAR(circle.GetRadius(), actualRadius, EPS);
    ASSERT_NEAR(circle.GetFerence(), 2 * actualRadius * PI, EPS);
}

TEST(circle, create_by_radius_reset_ference_and_assert_square_and_ference) {
    auto radius = 95.28;
    auto newFerence = 2.71;

    auto circle = Circle::CreateByRadius(radius);

    circle.SetFerence(newFerence);

    auto actualRadius = newFerence / (2 * PI);

    ASSERT_NEAR(circle.GetRadius(), actualRadius, EPS);
    ASSERT_NEAR(circle.GetSquare(), actualRadius * actualRadius * PI, EPS);
}

TEST(circle, create_by_zero_radius) {
    ASSERT_ANY_THROW(Circle::CreateByRadius(0));
}

TEST(circle, create_by_negative_radius) {
    ASSERT_ANY_THROW(Circle::CreateByRadius(-9.525));
}

TEST(circle, create_by_zero_square) {
    ASSERT_ANY_THROW(Circle::CreateBySquare(0));
}

TEST(circle, create_by_negative_square) {
    ASSERT_ANY_THROW(Circle::CreateBySquare(-94524.4));
}

TEST(circle, create_by_zero_ference) {
    ASSERT_ANY_THROW(Circle::CreateByFerence(0));
}

TEST(circle, create_by_negative_ference) {
    ASSERT_ANY_THROW(Circle::CreateByFerence(-525.4));
}

TEST(circle, create_and_set_negative_radius) {
    auto circle = Circle::CreateByFerence(95);
    ASSERT_ANY_THROW(circle.SetRadius(-5));
}

TEST(circle, create_and_set_negative_square) {
    auto circle = Circle::CreateByRadius(14);
    ASSERT_ANY_THROW(circle.SetSquare(-0.52));
}

TEST(circle, create_and_set_negative_ference) {
    auto circle = Circle::CreateBySquare(9.515);
    ASSERT_ANY_THROW(circle.SetFerence(0));
}

// Получается зазор ~~ 40 км2
TEST(tasks, earth_and_rope) {
    auto earthRadiusMeters = 6378.1 * 1e3;
    auto actualResultMeters = PI * (2 * earthRadiusMeters + 1);

    ASSERT_NEAR(
            EarthAndRopeSolve(earthRadiusMeters, 1),
            actualResultMeters,
            1e-1);
}

TEST(tasks, swimming_pool) {
    auto poolRadius = 3;
    auto areaWidth = 1;

    auto meterFencePrice = 2000;
    auto squareMeterAreaPrice = 1000;

    auto fencePrice = 2 * PI * (poolRadius + areaWidth) * meterFencePrice;
    auto areaPrice = PI * areaWidth * (areaWidth + 2 * poolRadius)
            * squareMeterAreaPrice;

    ASSERT_NEAR(
        SwimmingPoolSolve(poolRadius, areaWidth,
                          squareMeterAreaPrice, meterFencePrice),
        fencePrice + areaPrice,
        1e-1);
}

