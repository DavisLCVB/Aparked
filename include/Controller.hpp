#pragma once
#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include<ControlConsole.hpp>
#include<ConsolePrinter.hpp>
#include<ConsoleFrames.hpp>
#include<Conio.h>

class Controller {
private:
    ControlConsole *console;
    ConsolePrinter<std::string> *printer;
    ConsoleFrames *frames;
public:
    Controller();
    Controller(ControlConsole *console, ConsolePrinter<std::string> *printer, ConsoleFrames *frames);
    void set_console(ControlConsole *console);
    void set_printer(ConsolePrinter<std::string> *printer);
    void set_frames(ConsoleFrames *frames);
    ControlConsole *get_console();
    ConsolePrinter<std::string> *get_printer();
    ConsoleFrames *get_frames();
    void init_loading_bar();
};

#endif // CONTROLLER_HPP