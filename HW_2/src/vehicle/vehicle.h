#pragma once

#include <string>

namespace transport {

class Vehicle {
public:
    Vehicle() = default;
    virtual ~Vehicle() = default;

    virtual std::string description() const = 0;
};

}
