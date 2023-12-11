#pragma once
#ifndef PARKINGCONTROLLER_HPP
#define PARKINGCONTROLLER_HPP

#include <ControlConsole>
#include <CustomerManager.hpp>
#include <string>
#include <vector>

class ParkingController {
private:
    const int X_COORD = 41;
    const int Y_COORD = 2;
    const int PARKING_WIDTH = 36;
    const int PARKING_HEIGHT = 15;
    int X_INCREMENT = 6;
    int Y_INCREMENT = 4;
    int X_SELECTED = -1;
    int Y_SELECTED = -1;
    std::vector<std::vector<std::string>> parking;
    ConsolePrinter<std::string> *printer;

public:
    ParkingController() = default;
    ParkingController(ConsolePrinter<std::string> *printer);
    void init_parking();
    void fill_parking();
    void print_parking();
    void select_parking_space();
    void up_parking_space();
    void down_parking_space();
    void left_parking_space();
    void right_parking_space();
    bool select_parking_space(int x, int y);
    void reset_data();
    void send_advertisement();
    void delete_advertisement();
    int get_x_coord();
    int get_y_coord();
    int get_parking_width();
    int get_parking_height();
    int get_x_increment();
    int get_y_increment();
    int get_x_selected();
    int get_y_selected();
    std::vector<std::vector<std::string>> get_parking();
};

#endif // PARKINGCONTROLLER_HPP