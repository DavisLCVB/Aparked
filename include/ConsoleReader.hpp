#pragma once
#ifndef CONSOLE_READER_HPP
#define CONSOLE_READER_HPP

#include <ControlConsole.hpp>
#include <ConsolePrinter.hpp>
#include <conio.h>
#include <string>
#include <Keys.hpp>

class ConsoleReader {
private:
    ControlConsole *console;
    ConsolePrinter<std::string> *printer;
public:
    ConsoleReader(ControlConsole *console, ConsolePrinter<std::string> *printer);
    void set_console(ControlConsole *console);
    ControlConsole *get_console();
    void set_printer(ConsolePrinter<std::string> *printer);
    ConsolePrinter<std::string> *get_printer();
    std::string read();
    std::string read(Color foreground, Color background);
    std::string read(int width);
    std::string read(int width, Color foreground, Color background);
};
#endif // CONSOLE_READER_HPP