#include <Controller.hpp>

Controller::Controller() {
    this->console = nullptr;
    this->printer = nullptr;
    this->frames = nullptr;
}

Controller::Controller(ControlConsole *console, ConsolePrinter<std::string> *printer, ConsoleFrames *frames) {
    this->console = console;
    this->printer = printer;
    this->frames = frames;

    this->frames->init_screen();
    _getch();
    this->frames->paint_loading_screen();
    this->init_loading_bar();
    this->frames->paint_main_menu();
    _getch();
}

void Controller::init_loading_bar() {
    for (int i = 0; i < 80; i++) {
        this->printer->print(20 + i, 15, "o", Color::BLACK, Color::BLACK);
        Sleep(1 * 100 / 80);
    }
}

void Controller::set_console(ControlConsole *console) {
    this->console = console;
}

void Controller::set_printer(ConsolePrinter<std::string> *printer) {
    this->printer = printer;
}

void Controller::set_frames(ConsoleFrames *frames) {
    this->frames = frames;
}

ControlConsole *Controller::get_console() {
    return this->console;
}

ConsolePrinter<std::string> *Controller::get_printer() {
    return this->printer;
}

ConsoleFrames *Controller::get_frames() {
    return this->frames;
}