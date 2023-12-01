#include <Color.hpp>
#include <Controller.hpp>
#include <conio.h>
#include <ControlConsole>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <windows.h>

int main() {
    std::unique_ptr<ControlConsole> console = std::make_unique<ControlConsole>();
    std::unique_ptr<ConsolePrinter<std::string>> printer;
    printer = std::make_unique<ConsolePrinter<std::string>>(console.get());
    std::unique_ptr<ConsoleFrames> frames;
    frames = std::make_unique<ConsoleFrames>(console.get(), printer.get());
    std::unique_ptr<ConsoleReader> reader;
    reader = std::make_unique<ConsoleReader>(console.get(), printer.get());
    std::unique_ptr<Controller> controller;
    controller = std::make_unique<Controller>(console.get(), printer.get(), frames.get(), reader.get());
    return 0;
}