#include <Controller.hpp>

Controller::Controller() {
    this->console = nullptr;
    this->printer = nullptr;
    this->frames = nullptr;
}

Controller::Controller(ControlConsole *console, ConsolePrinter<std::string> *printer, ConsoleFrames *frames, ConsoleReader *reader) {
    this->console = console;
    this->printer = printer;
    this->frames = frames;
    this->reader = reader;

    this->frames->init_screen();
    _getch();
    this->frames->paint_loading_screen();
    this->init_loading_bar();
    this->frames->paint_main_menu();
    this->receive_data();
    _getch();
}

void Controller::init_loading_bar() {
    for (int i = 0; i < 80; i++) {
        this->printer->print(20 + i, 15, "o", Color::BLACK, Color::BLACK);
        Sleep(1 * 100 / 80);
    }
}

void Controller::receive_data(){
    this->console->move_cursor(86, 11);
    std::string input = this->reader->read(30, Color::WHITE, Color::BLACK);
    this->console->clear_screen();
    this->console->move_cursor(0, 0);
    this->printer->print(0, 0, input);
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