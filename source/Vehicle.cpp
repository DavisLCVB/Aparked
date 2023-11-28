#include <Vehicle.hpp>

Vehicle::Vehicle(std::string plate, Color color, VehicleType type) {
    this->plate = plate;
    this->color = color;
    this->type = type;
}

void Vehicle::set_plate(std::string plate) {
    this->plate = plate;
}

void Vehicle::set_color(Color color) {
    this->color = color;
}

void Vehicle::set_type(VehicleType type) {
    this->type = type;
}

std::string Vehicle::get_plate() {
    return this->plate;
}

Color Vehicle::get_color() {
    return this->color;
}

VehicleType Vehicle::get_type() {
    return this->type;
}

std::string Vehicle::to_string() {
    std::string buffer = "";
    buffer += this->plate + "\n";
    int _color = static_cast<int>(this->color);
    buffer += std::to_string(_color) + "\n";
    int _type = static_cast<int>(this->type);
    buffer += std::to_string(_type) + "\n";
    return buffer;
}