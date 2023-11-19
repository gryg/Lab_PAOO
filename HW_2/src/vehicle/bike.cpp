#include "bike.h"

namespace transport {

Bike::Bike(std::string tp) : type(std::move(tp)) {}

std::string Bike::description() const {
    return "Bike: " + type;
}

}
