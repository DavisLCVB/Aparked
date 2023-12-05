#pragma once
#ifndef OPTION_CONTROLLER_HPP
#define OPTION_CONTROLLER_HPP

#include <Algorithm>
#include <Color.hpp>
#include <Conio.h>
#include <ConsolePrinter.hpp>
#include <Keys.hpp>

class OptionController {
private:
    ConsolePrinter<std::string> *printer;
    std::vector<std::pair<bool, std::string>> options;
    Color background = Color::WHITE;
    Color foreground = Color::BLACK;
    Color selected_background = Color::CYAN;
    Color selected_foreground = Color::BLACK;
    int init_y = 0;
    int separator = 1;

public:
    OptionController() = default;
    OptionController(ConsolePrinter<std::string> *printer, std::vector<std::string> options);
    void set_printer(ConsolePrinter<std::string> *printer);
    void set_options(std::vector<std::pair<bool, std::string>> options);
    void set_background(Color background);
    void set_foreground(Color foreground);
    void set_selected_background(Color selected_background);
    void set_selected_foreground(Color selected_foreground);
    void set_init_y(int init_y);
    void set_separator(int separator);
    void set_options(std::vector<std::string> options);
    ConsolePrinter<std::string> *get_printer();
    std::vector<std::pair<bool, std::string>> get_options();
    Color get_background();
    Color get_foreground();
    Color get_selected_background();
    Color get_selected_foreground();
    int get_init_y();
    int get_separator();
    void paint_options();
    int init_options();
};

#endif // OPTION_CONTROLLER_HPP