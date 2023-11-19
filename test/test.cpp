#include <Color.hpp>
#include <ConsolePrinter.hpp>
#include <ControlConsole.hpp>
#include <conio.h>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <windows.h>

int main() {
    system("cls");
    std::unique_ptr<ControlConsole> console = std::make_unique<ControlConsole>();
    console->set_visible_cursor(false);
    std::unique_ptr<ConsolePrinter<std::string>> printer;
    printer = std::make_unique<ConsolePrinter<std::string>>(console.get());
    printer->print(0, 0, "Hello, world!", Color::BLACK, Color::WHITE);
    printer->print_horizontal_line(0, 1, 15, "-", Color::BLUE, Color::YELLOW);
    printer->print_diagonal_line(0, 2, 10, 1, "o", Color::RED, Color::GREEN);
    _getch();
    console->set_visible_cursor(true);
    console->change_color(Color::BLACK, Color::WHITE);
    system("cls");
    return 0;
}