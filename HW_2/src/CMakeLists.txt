add_subdirectory(vehicle)

add_executable(HW2Applicaiton main.cpp)

target_link_libraries(HW2Applicaiton PRIVATE VehicleLibrary)
