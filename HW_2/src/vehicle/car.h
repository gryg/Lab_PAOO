#pragma once

#include "vehicle.h"

namespace transport {

class Car : public Vehicle {
private:
    std::string model;

public:
    Car(std::string model);

    Car(const Car& other);
    Car(Car&& other) noexcept;
    Car& operator=(const Car& other);
    Car& operator=(Car&& other) noexcept;

    std::string description() const override;
};

}
