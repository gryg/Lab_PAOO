add_library(VehicleLibrary car.cpp bike.cpp)

target_include_directories(VehicleLibrary INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
