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

void ControlConsole::change_color(Color background, Color foreground, bool all_screen) {
    HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(console_handle, static_cast<int>(background) * 16 + static_cast<int>(foreground));
    if (all_screen) {
        CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
        GetConsoleScreenBufferInfo(console_handle, &screen_buffer_info);
        COORD position = {0, 0};
        DWORD written;
        FillConsoleOutputAttribute(console_handle, static_cast<int>(background) * 16 + static_cast<int>(foreground), screen_buffer_info.dwSize.X * screen_buffer_info.dwSize.Y, position, &written);
    }
}

POINT ControlConsole::get_cursor_position() {
    HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(console_handle, &screen_buffer_info);
    POINT cursor_position = {screen_buffer_info.dwCursorPosition.X, screen_buffer_info.dwCursorPosition.Y};
    return cursor_position;
}

void ControlConsole::clear_screen() {
    system("cls");
}