#include <OptionController.hpp>

OptionController::OptionController(ConsolePrinter<std::string> *printer, std::vector<std::string> options) {
    this->printer = printer;
    for (auto p : options) {
        this->options.push_back(std::make_pair(false, p));
    }
}

void OptionController::set_printer(ConsolePrinter<std::string> *printer) {
    this->printer = printer;
}

void OptionController::set_options(std::vector<std::pair<bool, std::string>> options) {
    this->options = options;
}

void OptionController::set_options(std::vector<std::string> options) {
    for (auto p : options) {
        this->options.push_back(std::make_pair(false, p));
    }
}

ConsolePrinter<std::string> *OptionController::get_printer() {
    return this->printer;
}

std::vector<std::pair<bool, std::string>> OptionController::get_options() {
    return this->options;
}

void OptionController::set_background(Color background) {
    this->background = background;
}

void OptionController::set_foreground(Color foreground) {
    this->foreground = foreground;
}

void OptionController::set_selected_background(Color selected_background) {
    this->selected_background = selected_background;
}

void OptionController::set_selected_foreground(Color selected_foreground) {
    this->selected_foreground = selected_foreground;
}

Color OptionController::get_background() {
    return this->background;
}

Color OptionController::get_foreground() {
    return this->foreground;
}

Color OptionController::get_selected_background() {
    return this->selected_background;
}

Color OptionController::get_selected_foreground() {
    return this->selected_foreground;
}

void OptionController::set_init_y(int init_y) {
    if (init_y >= 0)
        this->init_y = init_y;
    else
        this->init_y = 0;
}

void OptionController::set_separator(int separator) {
    if (separator >= 0)
        this->separator = separator;
    else
        this->separator = 1;
}

int OptionController::get_init_y() {
    return this->init_y;
}

int OptionController::get_separator() {
    return this->separator;
}

void OptionController::paint_options() {
    for (int i = 0; i < (int)this->options.size(); i++) {
        int x_word = 0;
        if (this->options.at(i).first) {
            x_word = printer->center_text(options.at(i).second);
            this->printer->print_horizontal_line(0, this->init_y + i * separator, 120, "o", this->selected_background, this->selected_background);
            this->printer->print(x_word, init_y + i * separator, this->options.at(i).second, this->selected_background, this->selected_foreground);
            this->printer->print(x_word - 6, init_y + i * separator, ">>", this->selected_background, this->selected_foreground);
            this->printer->print(x_word + options.at(i).second.size() + 3, init_y + i * separator, "<<", this->selected_background, this->selected_foreground);
        } else {
            x_word = printer->center_text(options.at(i).second);
            this->printer->print_horizontal_line(0, this->init_y + i * separator, 120, "o", this->background, this->background);
            this->printer->print(printer->center_text(options.at(i).second), init_y + i * separator, this->options.at(i).second, this->background, this->foreground);
        }
    }
}

int OptionController::init_options() {
    this->options.at(0).first = true;
    this->paint_options();
    int key;
    do {
        key = _getch();
        switch (key) {
        case static_cast<int>(Keys::UP):
        case static_cast<int>(Keys::LEFT):
        case static_cast<int>(Keys::W):
        case static_cast<int>(Keys::A):
            for (int i = 0; i < (int)this->options.size(); i++) {
                if (this->options.at(i).first) {
                    this->options.at(i).first = false;
                    if (i == 0) {
                        this->options.at(this->options.size() - 1).first = true;
                    } else {
                        this->options.at(i - 1).first = true;
                    }
                    break;
                }
            }
            this->paint_options();
            break;
        case static_cast<int>(Keys::DOWN):
        case static_cast<int>(Keys::RIGHT):
        case static_cast<int>(Keys::S):
        case static_cast<int>(Keys::D):
            for (int i = 0; i < (int)this->options.size(); i++) {
                if (this->options.at(i).first) {
                    this->options.at(i).first = false;
                    if (i == (int)this->options.size() - 1) {
                        this->options.at(0).first = true;
                    } else {
                        this->options.at(i + 1).first = true;
                    }
                    break;
                }
            }
            this->paint_options();
            break;
        }
    } while (key != static_cast<int>(Keys::ENTER));
    return std::distance(this->options.begin(), std::find_if(this->options.begin(), this->options.end(), [](std::pair<bool, std::string> p) { return p.first; }));
}