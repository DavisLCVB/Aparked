#include <ControlConsole.hpp>
#include <windows.h>

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

void ControlConsole::change_color(int background, int foreground) {
    HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_handle, background * 16 + foreground);
}