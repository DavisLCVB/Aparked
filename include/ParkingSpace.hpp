#pragma once
#ifndef PARKING_SPACE_HPP
#define PARKING_SPACE_HPP

#include <string>

class ParkingSpace {
private:
    int x;
    int y;
public:
    ParkingSpace() = default;
    ParkingSpace(int x, int y);
    void set_x(int x);
    void set_y(int y);
    int get_x();
    int get_y();
    std::string to_string();
};

#endif // PARKING_SPACE_HPP