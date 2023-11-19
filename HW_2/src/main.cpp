#include "vehicle/car.h"
#include "vehicle/bike.h"
#include <iostream>

using namespace transport;

int main() {
    Car car("Tesla Bulletproof Cybertruck");
    Bike bike("BMX");

    std::cout << car.description() << std::endl;
    std::cout << bike.description() << std::endl;

    return 0;
}
