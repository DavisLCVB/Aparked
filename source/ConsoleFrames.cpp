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
    printer->print(3, 2, "UNMSM", Color::BLACK, Color::LIGHT_CYAN, true);
    printer->print(4, 2, "niversidad", Color::LIGHT_CYAN, Color::BLACK);
    printer->print(4, 3, "acional", Color::LIGHT_CYAN, Color::BLACK);
    printer->print(4, 4, "ayor de", Color::LIGHT_CYAN, Color::BLACK);
    printer->print(4, 5, "an", Color::LIGHT_CYAN, Color::BLACK);
    printer->print(4, 6, "arcos", Color::LIGHT_CYAN, Color::BLACK);
    printer->print_matrix(40, 10, Resources::logo_estacionamiento, Color::CYAN, Color::CYAN, Color::WHITE);
    printer->print(41, 17, "A P A R K E D", Color::CYAN, Color::WHITE);
    printer->print_rectangle(85, 10, 32, 3, Styles::Double, Color::WHITE, Color::BLACK);
    printer->print(85, 9, "Ingrese su Usuario", Color::WHITE, Color::DARK_GRAY);
    printer->print_matrix(98, 20, Resources::logo_grupo, Color::WHITE, Color::WHITE, Color::DARK_GRAY);
    printer->print(99, 26, "Grupo", Color::WHITE, Color::DARK_GRAY);
}

std::string ConsoleFrames::paint_options_main_menu() {
    int y_init = 7;
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
    std::string op = init_main_selection(options, y_init);
    this->console->change_color(Color::WHITE, Color::BLACK);
    return op;
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

std::string ConsoleFrames::init_main_selection(std::vector<std::string> options, int y_init) {
    std::unique_ptr<OptionController> option_controller = std::make_unique<OptionController>(printer, options);
    option_controller->set_init_y(y_init);
    option_controller->set_separator(2);
    option_controller->set_background(Color::WHITE);
    option_controller->set_foreground(Color::BLACK);
    option_controller->set_selected_background(Color::CYAN);
    option_controller->set_selected_foreground(Color::WHITE);
    int ind = option_controller->init_options();
    return options.at(ind);
}

void ConsoleFrames::paint_customer_data(){
    this->printer->get_console()->change_color(Color::WHITE, Color::BLACK, true);
    this->printer->get_console()->clear_screen();
    this->printer->print_rectangle(7, 10, 45, 3, Styles::Double, Color::WHITE, Color::BLACK);
    this->printer->print_rectangle(7, 19, 45, 3, Styles::Double, Color::WHITE, Color::BLACK);
    this->printer->print_rectangle(69, 10, 45, 3, Styles::Double, Color::WHITE, Color::BLACK);
    this->printer->print_rectangle(69, 19, 45, 3, Styles::Double, Color::WHITE, Color::BLACK);
    this->printer->print(7, 9, "Ingrese su nombre:", Color::BLACK, Color::WHITE);
    this->printer->print(7, 18, "Ingrese su edad:", Color::BLACK, Color::WHITE);
    this->printer->print(69, 9, "Ingrese su placa:", Color::BLACK, Color::WHITE);
    this->printer->print(69, 18, "Escriba \"Si\" si es miembro", Color::BLACK, Color::WHITE);
}

ConsoleFrames::~ConsoleFrames() {
    this->reset_screen();
}