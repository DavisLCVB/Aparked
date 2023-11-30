#include <ConsolePrinter.hpp>

template <typename Element>
ConsolePrinter<Element>::ConsolePrinter(ControlConsole *console_controller) {
    this->console = console_controller;
}

template <typename Element>
void ConsolePrinter<Element>::print(int x, int y, Element element, bool vertical) {
    this->console->move_cursor(x, y);
    if (!vertical) {
        std::cout << element;
    } else {
        for (auto c : element) {
            this->console->move_cursor(x, y);
            std::cout << c;
            y++;
        }
    }
}

template <typename Element>
void ConsolePrinter<Element>::print(int x, int y, Element element, Color background, Color foreground, bool vertical) {
    this->console->change_color(background, foreground);
    this->print(x, y, element, vertical);
}

template <typename Element>
void ConsolePrinter<Element>::print(int x, int y, char element) {
    this->console->move_cursor(x, y);
    std::cout << element;
}

template <typename Element>
void ConsolePrinter<Element>::print(int x, int y, char element, Color background, Color foreground) {
    this->console->change_color(background, foreground);
    this->print(x, y, element);
}

template <typename Element>
void ConsolePrinter<Element>::print_horizontal_line(int x, int y, int length, Element element) {
    for (int i = 0; i < length; i++) {
        this->print(x + i, y, element);
    }
}

template <typename Element>
void ConsolePrinter<Element>::print_horizontal_line(int x, int y, int length, Styles style) {
    std::string style_string = styleToString(style);
    for (int i = 0; i < length; i++) {
        this->print(x + i, y, style_string.at(7));
    }
}

template <typename Element>
void ConsolePrinter<Element>::print_horizontal_line(int x, int y, int length, Styles style, Color background, Color foreground) {
    this->console->change_color(background, foreground);
    this->print_horizontal_line(x, y, length, style);
}

template <typename Element>
void ConsolePrinter<Element>::print_horizontal_line(int x, int y, int length, Element element, Color background, Color foreground) {
    this->console->change_color(background, foreground);
    this->print_horizontal_line(x, y, length, element);
}

template <typename Element>
void ConsolePrinter<Element>::print_vertical_line(int x, int y, int length, Element element) {
    for (int i = 0; i < length; i++) {
        this->print(x, y + i, element);
    }
}

template <typename Element>
void ConsolePrinter<Element>::print_vertical_line(int x, int y, int length, Element element, Color background, Color foreground) {
    this->console->change_color(background, foreground);
    this->print_vertical_line(x, y, length, element);
}

template <typename Element>
void ConsolePrinter<Element>::print_vertical_line(int x, int y, int length, Styles style) {
    std::string style_string = styleToString(style);
    for (int i = 0; i < length; i++) {
        this->print(x, y + i, style_string.at(1));
    }
}

template <typename Element>
void ConsolePrinter<Element>::print_vertical_line(int x, int y, int length, Styles style, Color background, Color foreground) {
    this->console->change_color(background, foreground);
    this->print_vertical_line(x, y, length, style);
}

template <typename Element>
void ConsolePrinter<Element>::print_rectangle(int x, int y, int width, int height, Element element, bool fill) {
    if (fill) {
        for (int i = 0; i < height; i++) {
            this->print_horizontal_line(x, y + i, width, element);
        }
    } else {
        this->print_horizontal_line(x, y, width, element);
        this->print_horizontal_line(x, y + height - 1, width, element);
        this->print_vertical_line(x, y, height, element);
        this->print_vertical_line(x + width - 1, y, height, element);
    }
}

template <typename Element>
void ConsolePrinter<Element>::print_rectangle(int x, int y, int width, int height, Element element, Color background, Color foreground, bool fill) {
    this->console->change_color(background, foreground);
    this->print_rectangle(x, y, width, height, element, fill);
}

template<typename Element>
void ConsolePrinter<Element>::print_rectangle(int x, int y, int width, int height, Styles style, bool fill) {
    std::string style_string = styleToString(style);
    if (fill) {
        for (int i = 0; i < height; i++) {
            this->print_horizontal_line(x, y + i, width, style, Color::BLACK, Color::BLACK);
        }
    } else {
        this->print_horizontal_line(x, y, width, style);
        this->print_horizontal_line(x, y + height - 1, width, style);
        this->print_vertical_line(x, y, height, style);
        this->print_vertical_line(x + width - 1, y, height, style);
        this->print(x, y, style_string.at(10));
        this->print(x + width - 1, y, style_string.at(2));
        this->print(x, y + height - 1, style_string.at(3));
        this->print(x + width - 1, y + height - 1, style_string.at(9));
    }
}

template<typename Element>
void ConsolePrinter<Element>::print_rectangle(int x, int y, int width, int height, Styles style, Color background, Color foreground, bool fill) {
    this->console->change_color(background, foreground);
    this->print_rectangle(x, y, width, height, style, fill);
}

template <typename Element>
void ConsolePrinter<Element>::print_matrix(int x, int y, std::vector<std::vector<Element>> matrix, Color background, Color foreground1, Color foreground2, Color foreground3) {
    this->console->change_color(background, foreground1);
    for (int i = 0; i < (int)matrix.size(); i++) {
        for (int j = 0; j < (int)matrix.at(i).size(); j++) {
            if (matrix.at(i).at(j) == "0") {
                this->print(x + j, y + i, matrix.at(i).at(j), foreground1, foreground1);
            } else if (matrix.at(i).at(j) == "1") {
                this->print(x + j, y + i, matrix.at(i).at(j), foreground2, foreground2);
            } else if (matrix.at(i).at(j) == "2") {
                this->print(x + j, y + i, matrix.at(i).at(j), foreground3, foreground3);
            } else {
                this->print(x + j, y + i, matrix.at(i).at(j), background, foreground1);
            };
        }
    }
}

template <typename Element>
void ConsolePrinter<Element>::print_diagonal_line(int x, int y, int width, int step, Element element, bool left_to_right) {
    step = std::abs(step);
    for (int i = 0; i < width; i += step) {
        this->print((left_to_right ? x + i : x - i), y, element);
        y += step;
        if (x >= MAX_WIDTH || y >= MAX_HEIGHT)
            break;
    }
}

template <typename Element>
void ConsolePrinter<Element>::print_diagonal_line(int x, int y, int width, int step, Element element, Color background, Color foreground, bool left_to_right) {
    this->console->change_color(background, foreground);
    this->print_diagonal_line(x, y, width, step, element, left_to_right);
}

template <typename Element>
void ConsolePrinter<Element>::print_fill_diagonal(int x, int y, int width, int step, Element element, bool left_to_right) {
    step = std::abs(step);
    for (int i = width; i > 0; i -= step) {
        if (x >= MAX_WIDTH || y >= MAX_HEIGHT)
            break;
        this->print_horizontal_line(x, y, i, element);
        left_to_right ? x++ : false;
        y++;
    }
}

template <typename Element>
void ConsolePrinter<Element>::print_fill_diagonal(int x, int y, int width, int step, Element element, Color background, Color foreground, bool left_to_right) {
    this->console->change_color(background, foreground);
    this->print_fill_diagonal(x, y, width, step, element, left_to_right);
}