#include <ParkingSpace.hpp>

ParkingSpace::ParkingSpace(int x, int y) {
    this->x = x;
    this->y = y;
}

void ParkingSpace::set_x(int x) {
    this->x = x;
}

void ParkingSpace::set_y(int y) {
    this->y = y;
}

int ParkingSpace::get_x() {
    return this->x;
}

int ParkingSpace::get_y() {
    return this->y;
}

std::string ParkingSpace::to_string(){
    std::string buffer = "";
    buffer += std::to_string(this->x) + "\n";
    buffer += std::to_string(this->y) + "\n";
    return buffer;
}