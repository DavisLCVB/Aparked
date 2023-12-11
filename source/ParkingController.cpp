#include <ParkingController.hpp>

ParkingController::ParkingController(ConsolePrinter<std::string> *printer) {
    this->printer = printer;
}

void ParkingController::fill_parking() {
    this->init_parking();
    this->print_parking();
    for (int i = 0; i < CustomerManager::get_customer_count(); i++) {
        Customer *customer = CustomerManager::get_customer(i);
        int x = customer->get_parking_space()->get_x();
        int y = customer->get_parking_space()->get_y();
        Color color = customer->get_vehicle()->get_color();
        this->printer->print(X_COORD + x, Y_COORD + y, "####", Color::WHITE, color);
        std::string temp = "#";
        this->parking.at(Y_COORD + y).at(X_COORD + x) = temp;
        this->parking.at(Y_COORD + y).at(X_COORD + x + 1) = temp;
        this->parking.at(Y_COORD + y).at(X_COORD + x + 2) = temp;
        this->parking.at(Y_COORD + y).at(X_COORD + x + 3) = temp;
    }
}

void ParkingController::select_parking_space() {
    this->printer->get_console()->move_cursor(X_COORD + X_INCREMENT, Y_COORD + Y_INCREMENT);
    bool is_correct_selected = false;
    int key = 0;
    do {
        this->fill_parking();
        if (this->parking.at(Y_INCREMENT).at(X_INCREMENT) == "#") {
            this->printer->print(X_COORD + X_INCREMENT, Y_COORD + Y_INCREMENT, "####", Color::CYAN, Color::WHITE);
        } else {
            this->printer->print(X_COORD + X_INCREMENT, Y_COORD + Y_INCREMENT, "####", Color::CYAN, Color::CYAN);
        }
        key = _getch();
        this->delete_advertisement();
        switch (key) {
        case static_cast<int>(Keys::UP):
            this->up_parking_space();
            break;
        case static_cast<int>(Keys::DOWN):
            this->down_parking_space();
            break;
        case static_cast<int>(Keys::LEFT):
            this->left_parking_space();
            break;
        case static_cast<int>(Keys::RIGHT):
            this->right_parking_space();
            break;
        case static_cast<int>(Keys::ENTER):
            is_correct_selected = this->select_parking_space(Y_INCREMENT, X_INCREMENT);
            if (!is_correct_selected) {
                this->send_advertisement();
            }
            break;
        default:
            break;
        }
    } while (is_correct_selected || key != static_cast<int>(Keys::ESC));
}

bool ParkingController::select_parking_space(int x, int y) {
    if (this->parking.at(y).at(x) == "#") {
        return false;
    }
    std::string temp = "#";
    this->parking.at(Y_COORD + y).at(X_COORD + x) = temp;
    this->parking.at(Y_COORD + y).at(X_COORD + x + 1) = temp;
    this->parking.at(Y_COORD + y).at(X_COORD + x + 2) = temp;
    this->parking.at(Y_COORD + y).at(X_COORD + x + 3) = temp;
    this->X_SELECTED = x;
    this->Y_SELECTED = y;
    return true;
}

void ParkingController::up_parking_space() {
    if (Y_INCREMENT != 2) {
        Y_INCREMENT -= 2;
    }
    if (Y_INCREMENT == 2) {
        Y_INCREMENT = 10;
    }
}

void ParkingController::down_parking_space() {
    if (Y_INCREMENT != 12) {
        Y_INCREMENT += 2;
    }
    if (Y_INCREMENT == 12) {
        Y_INCREMENT = 4;
    }
}

void ParkingController::left_parking_space() {
    if (Y_INCREMENT == 12 || Y_INCREMENT == 26) {
        Y_INCREMENT -= 6;
    } else if (Y_INCREMENT == 20) {
        Y_INCREMENT -= 8;
    } else if (Y_INCREMENT == 6) {
        Y_INCREMENT = 26;
    }
}

void ParkingController::right_parking_space() {
    if (Y_INCREMENT == 6 || Y_INCREMENT == 20) {
        Y_INCREMENT += 6;
    } else if (Y_INCREMENT == 12) {
        Y_INCREMENT += 8;
    } else if (Y_INCREMENT == 26) {
        Y_INCREMENT = 6;
    }
}

void ParkingController::print_parking() {
    for (int i = 0; i < PARKING_HEIGHT; i++) {
        for (int j = 0; j < PARKING_WIDTH; j++) {
            if (this->parking.at(i).at(j) == "0") {
                this->printer->print(X_COORD + j, Y_COORD + i, '#', Color::BLACK, Color::BLACK);
            } else {
                if (this->parking.at(i).at(j) == "1") {
                    this->printer->print(X_COORD + j, Y_COORD + i, '#', Color::WHITE, Color::WHITE);
                } else if (this->parking.at(i).at(j) == "2") {
                    this->printer->print(X_COORD + j, Y_COORD + i, char(178), Color::WHITE, Color::BLACK);
                }
            }
        }
    }
}

void ParkingController::init_parking() {
    this->parking = {{"0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0"},
                     {"0", "0", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "0", "0"},
                     {"0", "0", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "0", "0"},
                     {"0", "0", "1", "1", "1", "1", "2", "2", "2", "2", "0", "0", "2", "2", "2", "2", "1", "1", "1", "1", "2", "2", "2", "2", "0", "0", "2", "2", "2", "2", "1", "1", "1", "1", "0", "0"},
                     {"0", "0", "1", "1", "1", "1", "1", "1", "1", "1", "0", "0", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "0", "0", "1", "1", "1", "1", "1", "1", "1", "1", "0", "0"},
                     {"0", "0", "1", "1", "1", "1", "2", "2", "2", "2", "0", "0", "2", "2", "2", "2", "1", "1", "1", "1", "2", "2", "2", "2", "0", "0", "2", "2", "2", "2", "1", "1", "1", "1", "0", "0"},
                     {"0", "0", "1", "1", "1", "1", "1", "1", "1", "1", "0", "0", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "0", "0", "1", "1", "1", "1", "1", "1", "1", "1", "0", "0"},
                     {"0", "0", "1", "1", "1", "1", "2", "2", "2", "2", "0", "0", "2", "2", "2", "2", "1", "1", "1", "1", "2", "2", "2", "2", "0", "0", "2", "2", "2", "2", "1", "1", "1", "1", "0", "0"},
                     {"0", "0", "1", "1", "1", "1", "1", "1", "1", "1", "0", "0", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "0", "0", "1", "1", "1", "1", "1", "1", "1", "1", "0", "0"},
                     {"0", "0", "1", "1", "1", "1", "2", "2", "2", "2", "0", "0", "2", "2", "2", "2", "1", "1", "1", "1", "2", "2", "2", "2", "0", "0", "2", "2", "2", "2", "1", "1", "1", "1", "0", "0"},
                     {"0", "0", "1", "1", "1", "1", "1", "1", "1", "1", "0", "0", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "0", "0", "1", "1", "1", "1", "1", "1", "1", "1", "0", "0"},
                     {"0", "0", "1", "1", "1", "1", "2", "2", "2", "2", "0", "0", "2", "2", "2", "2", "1", "1", "1", "1", "2", "2", "2", "2", "0", "0", "2", "2", "2", "2", "1", "1", "1", "1", "0", "0"},
                     {"0", "0", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "0", "0"},
                     {"0", "0", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "1", "0", "0"},
                     {"0", "0", "0", "0", "1", "1", "1", "1", "1", "1", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "0", "1", "1", "1", "1", "1", "1", "0", "0", "0", "0"}};
}

void ParkingController::reset_data() {
    this->X_SELECTED = -1;
    this->Y_SELECTED = -1;
    this->X_INCREMENT = 6;
    this->Y_INCREMENT = 4;
}

int ParkingController::get_x_coord() {
    return this->X_COORD;
}

int ParkingController::get_y_coord() {
    return this->Y_COORD;
}

int ParkingController::get_parking_width() {
    return this->PARKING_WIDTH;
}

int ParkingController::get_parking_height() {
    return this->PARKING_HEIGHT;
}

int ParkingController::get_x_increment() {
    return this->X_INCREMENT;
}

int ParkingController::get_y_increment() {
    return this->Y_INCREMENT;
}

int ParkingController::get_x_selected() {
    return this->X_SELECTED;
}

int ParkingController::get_y_selected() {
    return this->Y_SELECTED;
}

std::vector<std::vector<std::string>> ParkingController::get_parking() {
    return this->parking;
}

void ParkingController::send_advertisement() {
    std::string message = "Espacio de estacionamiento lleno";
    int coord_x = this->printer->center_text(message);
    this->printer->print(coord_x, Y_COORD + PARKING_WIDTH + 3, message, Color::WHITE, Color::RED);
}

void ParkingController::delete_advertisement() {
    std::string message = "Espacio de estacionamiento lleno";
    int coord_x = this->printer->center_text(message);
    this->printer->print(coord_x, Y_COORD + PARKING_WIDTH + 3, message, Color::WHITE, Color::WHITE);
}