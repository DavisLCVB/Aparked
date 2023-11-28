#include <Color.hpp>
Color int_to_Color(int cod){
    switch (cod){
        case 0:
            return Color::BLACK;
        case 1:
            return Color::BLUE;
        case 2:
            return Color::GREEN;
        case 3:
            return Color::CYAN;
        case 4:
            return Color::RED;
        case 5:
            return Color::MAGENTA;
        case 6:
            return Color::BROWN;
        case 7:
            return Color::LIGHT_GRAY;
        case 8:
            return Color::DARK_GRAY;
        case 9:
            return Color::LIGHT_BLUE;
        case 10:
            return Color::LIGHT_GREEN;
        case 11:
            return Color::LIGHT_CYAN;
        case 12:
            return Color::LIGHT_RED;
        case 13:
            return Color::LIGHT_MAGENTA;
        case 14:
            return Color::YELLOW;
        case 15:
            return Color::WHITE;
        default:
            return Color::BLACK;
    }
}