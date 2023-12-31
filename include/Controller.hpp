#pragma once
#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <Conio.h>
#include <ConsoleFrames.hpp>
#include <ConsolePrinter.hpp>
#include <ConsoleReader.hpp>
#include <ControlConsole.hpp>
#include <CustomerManager.hpp>
#include <ParkingController.hpp>

class Controller {
private:
    ControlConsole *console;
    ConsolePrinter<std::string> *printer;
    ConsoleFrames *frames;
    ConsoleReader *reader;
    std::unique_ptr<ParkingController> parking_controller;
    bool is_running = true;

public:
    Controller();
    Controller(ControlConsole *console, ConsolePrinter<std::string> *printer, ConsoleFrames *frames, ConsoleReader *reader);
    void set_console(ControlConsole *console);
    void set_printer(ConsolePrinter<std::string> *printer);
    void set_frames(ConsoleFrames *frames);
    void set_reader(ConsoleReader *reader);
    ControlConsole *get_console();
    ConsolePrinter<std::string> *get_printer();
    ConsoleFrames *get_frames();
    ConsoleReader *get_reader();
    void init_loading_bar();
    std::string receive_data();
    void paint_parking();
    void load_files();
    void init_controller();
    void init_program();
    void show_parking();
    void park_vehicle();
    void remove_vehicle();
    void get_info();
    void verify_info();
};

#endif // CONTROLLER_HPP