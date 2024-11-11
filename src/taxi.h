#pragma once
#include "car.h"
#include "route.h"

class Taxi{
    private:
        Car car;
        Route route;

    public:
        Taxi(Car, Route);
};