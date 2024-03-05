// Copyright 2024 Dmitry Vanushkin
#include "tasks.h"
#include "circle.h"

double EarthAndRopeSolve(double earthRadius, double growth) {
    auto earth = Circle::CreateByRadius(earthRadius);
    auto increasedRope = Circle::CreateByRadius(earthRadius + growth);

    return increasedRope.GetSquare() - earth.GetSquare();
}

double SwimmingPoolSolve(double poolRadiusMeter,
                         double areaWidthMeter,
                         double areaPricePerSquareMeter,
                         double fencePricePerMeter) {
    auto pool = Circle::CreateByRadius(poolRadiusMeter);
    auto areaAndPool = Circle::CreateByRadius(poolRadiusMeter + areaWidthMeter);

    auto areaSquare = areaAndPool.GetSquare() - pool.GetSquare();
    auto areaPrice = areaSquare * areaPricePerSquareMeter;

    auto fencePrice = areaAndPool.GetFerence() * fencePricePerMeter;

    return areaPrice + fencePrice;
}
