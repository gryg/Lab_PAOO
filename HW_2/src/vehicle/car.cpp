#include "car.h"

namespace transport {

Car::Car(std::string mdl) : model(std::move(mdl)) {}

Car::Car(const Car& other) : model(other.model) {}

Car::Car(Car&& other) noexcept : model(std::move(other.model)) {}

Car& Car::operator=(const Car& other) {
    if (this != &other) {
        model = other.model;
    }
    return *this;
}

Car& Car::operator=(Car&& other) noexcept {
    if (this != &other) {
        model = std::move(other.model);
    }
    return *this;
}

std::string Car::description() const {
    return "Car: " + model;
}

}
