#include <ConsoleReader.hpp>

ConsoleReader::ConsoleReader(ControlConsole *console, ConsolePrinter<std::string> *printer) {
    this->console = console;
    this->printer = printer;
}

void ConsoleReader::set_console(ControlConsole *console) {
    this->console = console;
}

ControlConsole *ConsoleReader::get_console() {
    return this->console;
}

void ConsoleReader::set_printer(ConsolePrinter<std::string> *printer) {
    this->printer = printer;
}

ConsolePrinter<std::string> *ConsoleReader::get_printer() {
    return this->printer;
}

std::string ConsoleReader::read() {
    POINT cursor_position = this->console->get_cursor_position();
    long x = cursor_position.x;
    long y = cursor_position.y;
    std::string input = "";
    while (true) {
        int key = _getch();
        std::string old = input;
        if (key != static_cast<int>(Keys::BACKSPACE) && key != static_cast<int>(Keys::ENTER)) {
            input.push_back(static_cast<char>(key));
            this->console->move_cursor(x, y);
            this->printer->print(x, y, input);
        } else if (key == static_cast<int>(Keys::BACKSPACE) && input.length() > 0) {
            input.pop_back();
            this->console->move_cursor(x, y);
            this->printer->print(x, y, old, Color::WHITE, Color::WHITE);
            this->printer->print(x, y, input, Color::WHITE, Color::BLACK);
        } else if (key == static_cast<int>(Keys::ENTER) && input.length() > 0) {
            break;
        }
    }
    return input;
}

std::string ConsoleReader::read(Color background, Color foreground) {
    this->console->change_color(background, foreground);
    std::string input = this->read();
    return input;
}

std::string ConsoleReader::read(int width) {
    this->console->set_visible_cursor(true);
    POINT cursor_position = this->console->get_cursor_position();
    long x = cursor_position.x;
    long y = cursor_position.y;
    std::string input = "";
    while (true) {
        int key = _getch();
        bool size = static_cast<int>(input.length()) < width;
        std::string old = input;
        if (key != static_cast<int>(Keys::BACKSPACE) && key != static_cast<int>(Keys::ENTER) && size) {
            input.push_back(static_cast<char>(key));
            this->console->move_cursor(x, y);
            this->printer->print(x, y, input);
        } else if (key == static_cast<int>(Keys::BACKSPACE) && static_cast<int>(input.length()) > 0) {
            input.pop_back();
            this->console->move_cursor(x, y);
            this->printer->print(x, y, old, Color::WHITE, Color::WHITE);
            this->printer->print(x, y, input, Color::WHITE, Color::BLACK);
        } else if (key == static_cast<int>(Keys::ENTER) && static_cast<int>(input.length()) > 0) {
            break;
        }
    }
    this->console->set_visible_cursor(false);
    return input;
}

std::string ConsoleReader::read(int width, Color background, Color foreground) {
    this->console->change_color(background, foreground);
    std::string input = this->read(width);
    return input;
}