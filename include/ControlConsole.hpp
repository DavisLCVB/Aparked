#pragma once
#ifndef CONTROL_CONSOLE_HPP
#define CONTROL_CONSOLE_HPP

/**
 * @brief La clase ControlConsole representa una clase de control para administrar la ventana de la consola.
 */
class ControlConsole {
private:
    bool visible_cursor;

public:
    /**
     * @brief Construye un nuevo objeto ControlConsole.
     */
    ControlConsole() = default;

    /**
     * @brief Establece la visibilidad del cursor en la ventana de la consola.
     * @param visible Un valor booleano que indica si el cursor debe ser visible o no.
     */
    void set_visible_cursor(bool visible);

    /**
     * @brief Mueve el cursor a la posición especificada en la ventana de la consola.
     * @param x La coordenada x de la nueva posición del cursor.
     * @param y La coordenada y de la nueva posición del cursor.
     */
    void move_cursor(short x, short y);

    /**
     * @brief Cambia los colores de fondo y primer plano de la ventana de la consola.
     * @param background El código que representa el color de fondo deseado.
     * @param foreground El código que representa el color de primer plano deseado.
     */
    void change_color(int background, int foreground);
};

#endif // CONTROL_CONSOLE_HPP