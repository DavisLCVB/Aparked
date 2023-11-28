#pragma once
#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <Conio.h>
#include <ConsoleFrames.hpp>
#include <ConsolePrinter.hpp>
#include <ConsoleReader.hpp>
#include <ControlConsole.hpp>
#include <CustomerManager.hpp>

class Controller {
private:
    ControlConsole *console;
    ConsolePrinter<std::string> *printer;
    ConsoleFrames *frames;
    ConsoleReader *reader;

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
    void receive_data();
    void load_files();
};

#endif // CONTROLLER_HPP