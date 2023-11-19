#include <ConsoleFrames.hpp>

ConsoleFrames::ConsoleFrames(ControlConsole *console, ConsolePrinter<std::string> *printer) {
    this->console = console;
    this->printer = printer;
}

void ConsoleFrames::paint_main_menu() {
    printer->get_console()->change_color(Color::WHITE, Color::BLACK, true);
    printer->get_console()->clear_screen();
    printer->print_fill_diagonal(0, 0, 86, 1, "o", Color::CYAN, Color::CYAN, false);
    printer->print_fill_diagonal(0, 0, 40, 1, "o", Color::LIGHT_CYAN, Color::LIGHT_CYAN, false);
    printer->print_diagonal_line(87, 0, 30, 1, "o", Color::CYAN, Color::CYAN, false);
    printer->print_diagonal_line(41, 0, 30, 1, "o", Color::LIGHT_CYAN, Color::LIGHT_CYAN, false);
    std::string element = "";
    element.push_back(char(178));
    printer->print_diagonal_line(84, 0, 30, 2, element, Color::CYAN, Color::WHITE, false);
    printer->print_diagonal_line(38, 0, 30, 2, element, Color::LIGHT_CYAN, Color::CYAN, false);
    printer->print_diagonal_line(82, 0, 30, 3, element, Color::CYAN, Color::WHITE, false);
    printer->print_diagonal_line(36, 0, 30, 3, element, Color::LIGHT_CYAN, Color::CYAN, false);
}

void ConsoleFrames::paint_loading_screen() {
    printer->get_console()->change_color(Color::WHITE, Color::BLACK, true);
    printer->get_console()->clear_screen();
    printer->print(53, 10, "C a r g a n d o . . .", Color::WHITE, Color::BLACK);
    printer->print_horizontal_line(20, 15, 80, "o", Color::DARK_GRAY, Color::DARK_GRAY);
}

void ConsoleFrames::init_screen() {
    console->set_visible_cursor(false);
    console->change_color(Color::WHITE, Color::BLACK);
    console->clear_screen();
}

void ConsoleFrames::reset_screen() {
    console->set_visible_cursor(true);
    console->change_color(Color::BLACK, Color::WHITE);
    console->clear_screen();
}

ConsoleFrames::~ConsoleFrames() {
    this->reset_screen();
}