#pragma once
#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <string>
#include <Color.hpp>
#include <VehicleTypes.hpp>

class Vehicle {
private:
    std::string plate;
    Color color;
    VehicleType type;
public:
    Vehicle() = default;
    Vehicle(std::string plate, Color color, VehicleType type);
    void set_plate(std::string plate);
    void set_color(Color color);
    void set_type(VehicleType type);
    std::string get_plate();
    Color get_color();
    VehicleType get_type();
    std::string to_string();
};

#endif // VEHICLE_HPP