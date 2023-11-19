#include <ControlConsole.hpp>

void ControlConsole::set_visible_cursor(bool visible) {
    this->visible_cursor = visible;
    HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor_info;
    GetConsoleCursorInfo(console_handle, &cursor_info);
    cursor_info.bVisible = visible;
    SetConsoleCursorInfo(console_handle, &cursor_info);
}

void ControlConsole::move_cursor(short x, short y) {
    HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position = {x, y};
    SetConsoleCursorPosition(console_handle, position);
}

void ControlConsole::change_color(Color background, Color foreground) {
    HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_handle, static_cast<int>(background) * 16 + static_cast<int>(foreground));
}