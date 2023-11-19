#pragma once

#include "vehicle.h"

namespace transport {

class Bike : public Vehicle {
private:
    std::string type;

public:
    Bike(std::string type);

    std::string description() const override;
};

}
