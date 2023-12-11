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
    this->is_running = true;

    this->parking_controller = std::make_unique<ParkingController>(printer);

    this->init_controller();
}

void Controller::init_controller() {
    this->load_files();
    this->frames->init_screen();
    _getch();
    this->frames->paint_loading_screen();
    this->init_loading_bar();
    this->frames->paint_main_menu();
    std::string input = this->receive_data();
    if (input == "exit") {
        this->console->change_color(Color::BLACK, Color::WHITE);
        this->console->clear_screen();
        return;
    }
    while(this->is_running) {
        this->init_program();
    }
}

void Controller::init_loading_bar() {
    for (int i = 0; i < 80; i++) {
        this->printer->print(20 + i, 15, "o", Color::BLACK, Color::BLACK);
        Sleep(1 * 100 / 80);
    }
}

std::string Controller::receive_data() {
    this->console->move_cursor(86, 11);
    std::string input = this->reader->read(30, Color::WHITE, Color::BLACK);
    this->console->clear_screen();
    return input;
}

void Controller::paint_parking() {
    this->parking_controller->fill_parking();
}

void Controller::load_files() {
    CustomerManager::load_customers();
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

void Controller::set_reader(ConsoleReader *reader) {
    this->reader = reader;
}

ConsoleReader *Controller::get_reader() {
    return this->reader;
}

void Controller::init_program() {
    std::string option = this->frames->paint_options_main_menu();
    std::vector<std::string> options;
    std::string temp;
    temp = "Estacionar veh";
    temp.push_back(char(161));
    temp += "culo";
    options.push_back(temp);
    temp = "Retirar veh";
    temp.push_back(char(161));
    temp += "culo";
    options.push_back(temp);
    temp = "Ver estacionamiento";
    options.push_back(temp);
    temp = "Salir";
    options.push_back(temp);
    if(option == options.at(0)) {
        this->park_vehicle();
    } else if(option == options.at(1)) {
        this->remove_vehicle();
    } else if(option == options.at(2)) {
        this->show_parking();
    } else if(option == options.at(3)) {
        this->is_running = false;
        this->console->change_color(Color::BLACK, Color::WHITE);
        this->console->clear_screen();
        return;
    }
}

void Controller::park_vehicle() {
    //TODO
}

void Controller::remove_vehicle() {
    //TODO
}

void Controller::show_parking() {
    this->console->change_color(Color::WHITE, Color::BLACK, true);
    this->console->clear_screen();
    this->paint_parking();
    _getch();
    this->console->change_color(Color::WHITE, Color::BLACK);
    this->console->clear_screen();
}

void Controller::get_info() {
    //TODO
}