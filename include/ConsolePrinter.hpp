#ifndef CONSOLE_PRINTER_HPP
#define CONSOLE_PRINTER_HPP
#include <ControlConsole.hpp>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Clase que imprime elementos en la consola.
 *
 * Esta clase se utiliza para imprimir elementos en la consola, como caracteres, líneas y matrices.
 * Se puede especificar la posición, el color de fondo y el color de primer plano de los elementos a imprimir.
 */
template <class Element>
class ConsolePrinter {
private:
    ControlConsole *console;

public:
    /**
     * @brief Constructor de la clase ConsolePrinter.
     *
     * @param console_controller Puntero al controlador de la consola.
     */
    ConsolePrinter(ControlConsole *console_controller);

    /**
     * @brief Imprime un elemento en la posición (x, y) de la consola.
     *
     * @param x Posición horizontal.
     * @param y Posición vertical.
     * @param element Elemento a imprimir.
     */
    void print(int x, int y, Element element);

    /**
     * @brief Imprime un elemento en la posición (x, y) de la consola con colores personalizados.
     *
     * @param x Posición horizontal.
     * @param y Posición vertical.
     * @param element Elemento a imprimir.
     * @param background Color de fondo.
     * @param foreground Color de primer plano.
     */
    void print(int x, int y, Element element, int background, int foreground);

    /**
     * @brief Imprime un rectángulo en la consola.
     *
     * @param x Posición horizontal del rectángulo.
     * @param y Posición vertical del rectángulo.
     * @param width Ancho del rectángulo.
     * @param height Altura del rectángulo.
     * @param element Elemento a imprimir.
     * @param fill Indica si se debe rellenar el rectángulo o no (valor predeterminado: false).
     */
    void print_rectangle(int x, int y, int width, int height, Element element, bool fill = false);

    /**
     * @brief Imprime una matriz en la consola.
     *
     * @param x Posición horizontal de la matriz.
     * @param y Posición vertical de la matriz.
     * @param matrix Matriz a imprimir.
     */
    void print_matrix(int x, int y, std::vector<std::vector<Element>> matrix);

    /**
     * @brief Imprime una línea horizontal en la consola.
     *
     * @param x Posición horizontal de la línea.
     * @param y Posición vertical de la línea.
     * @param length Longitud de la línea.
     * @param element Elemento a imprimir.
     */
    void print_horizontal_line(int x, int y, int length, Element element);

    /**
     * @brief Imprime una línea vertical en la consola.
     *
     * @param x Posición horizontal de la línea.
     * @param y Posición vertical de la línea.
     * @param length Longitud de la línea.
     * @param element Elemento a imprimir.
     */
    void print_vertical_line(int x, int y, int length, Element element);
};

/**
 * Implementación de la clase ConsolePrinter.
 */

template <typename Element>
ConsolePrinter<Element>::ConsolePrinter(ControlConsole *console_controller) {
    this->console = console_controller;
}

template <typename Element>
void ConsolePrinter<Element>::print(int x, int y, Element element) {
    this->console->move_cursor(x, y);
    std::cout << element;
}

template <typename Element>
void ConsolePrinter<Element>::print(int x, int y, Element element, int background, int foreground) {
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
void ConsolePrinter<Element>::print_vertical_line(int x, int y, int length, Element element) {
    for (int i = 0; i < length; i++) {
        this->print(x, y + i, element);
    }
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
void ConsolePrinter<Element>::print_matrix(int x, int y, std::vector<std::vector<Element>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.at(i).size(); j++) {
            this->print(x + j, y + i, matrix.at(i).at(j));
        }
    }
}

#endif // CONSOLE_PRINTER_HPP