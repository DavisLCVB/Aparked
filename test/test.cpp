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
    printer->print(0, 0, "Hello, world!", 0, 15);
    _getch();
    console->set_visible_cursor(true);
    system("cls");
    return 0;
}