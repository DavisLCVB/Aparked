#ifndef CONSOLE_PRINTER_HPP
#define CONSOLE_PRINTER_HPP
#include <Color.hpp>
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
    void print(int x, int y, Element element, Color background, Color foreground);

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
     * @brief Imprime un rectángulo en la consola.
     *
     * @param x La coordenada x de la esquina superior izquierda del rectángulo.
     * @param y La coordenada y de la esquina superior izquierda del rectángulo.
     * @param width El ancho del rectángulo.
     * @param height La altura del rectángulo.
     * @param element El elemento a imprimir dentro del rectángulo.
     * @param fill Indica si se debe rellenar el rectángulo con el elemento o no (por defecto es false).
     * @param background El color de fondo del rectángulo.
     * @param foreground El color de primer plano del rectángulo.
     */
    void print_rectangle(int x, int y, int width, int height, Element element, Color background, Color foreground, bool fill = false);

    /**
     * @brief Imprime una matriz en la consola.
     *
     * @param x Posición horizontal de la matriz.
     * @param y Posición vertical de la matriz.
     * @param matrix Matriz a imprimir.
     */
    void print_matrix(int x, int y, std::vector<std::vector<Element>> matrix);

    /**
     * @brief Imprime una matriz en la consola con colores de fondo y primer plano personalizados.
     *
     * @param x La posición x de la matriz en la consola.
     * @param y La posición y de la matriz en la consola.
     * @param matrix La matriz a imprimir.
     * @param background El color de fondo de la matriz.
     * @param foreground El color del primer plano de la matriz.
     */
    void print_matrix(int x, int y, std::vector<std::vector<Element>> matrix, Color background, Color foreground);

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
     * Imprime una línea horizontal en la consola.
     *
     * @param x La coordenada x de inicio de la línea.
     * @param y La coordenada y de la línea.
     * @param length La longitud de la línea.
     * @param element El elemento a utilizar para la línea.
     * @param background El color de fondo de la línea.
     * @param foreground El color de primer plano de la línea.
     */
    void print_horizontal_line(int x, int y, int length, Element element, Color background, Color foreground);

    /**
     * @brief Imprime una línea vertical en la consola.
     *
     * @param x Posición horizontal de la línea.
     * @param y Posición vertical de la línea.
     * @param length Longitud de la línea.
     * @param element Elemento a imprimir.
     */
    void print_vertical_line(int x, int y, int length, Element element);

    /**
     * Imprime una línea vertical en la consola.
     *
     * @param x La coordenada x de la posición inicial de la línea.
     * @param y La coordenada y de la posición inicial de la línea.
     * @param length La longitud de la línea.
     * @param element El elemento a utilizar para imprimir la línea.
     * @param background El color de fondo de la línea.
     * @param foreground El color de primer plano de la línea.
     */
    void print_vertical_line(int x, int y, int length, Element element, Color background, Color foreground);

    /**
     * Imprime una línea diagonal en la consola.
     *
     * @param x La coordenada x de la posición inicial de la línea.
     * @param y La coordenada y de la posición inicial de la línea.
     * @param width El ancho de la línea.
     * @param step El tamaño del paso entre cada elemento de la línea.
     * @param element El elemento a imprimir.
     * @param left_to_right Determina la dirección de la línea (de izquierda a derecha o de derecha a izquierda).
     */
    void print_diagonal_line(int x, int y, int width, int step, Element element, bool left_to_right = true);

    /**
     * Imprime una línea diagonal en la consola.
     *
     * @param x La coordenada x de la posición inicial de la línea.
     * @param y La coordenada y de la posición inicial de la línea.
     * @param width El ancho de la línea.
     * @param step El tamaño del paso entre cada elemento de la línea.
     * @param element El elemento a imprimir.
     * @param background El color de fondo de la línea.
     * @param foreground El color de primer plano de la línea.
     * @param left_to_right Determina la dirección de la línea (de izquierda a derecha o de derecha a izquierda).
     */
    void print_diagonal_line(int x, int y, int width, int step, Element element, Color background, Color foreground, bool left_to_right = true);
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
void ConsolePrinter<Element>::print(int x, int y, Element element, Color background, Color foreground) {
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

template <typename Element>
void ConsolePrinter<Element>::print_matrix(int x, int y, std::vector<std::vector<Element>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.at(i).size(); j++) {
            this->print(x + j, y + i, matrix.at(i).at(j));
        }
    }
}

template <typename Element>
void ConsolePrinter<Element>::print_matrix(int x, int y, std::vector<std::vector<Element>> matrix, Color background, Color foreground) {
    this->console->change_color(background, foreground);
    this->print_matrix(x, y, matrix);
}

template <typename Element>
void ConsolePrinter<Element>::print_diagonal_line(int x, int y, int width, int step, Element element, bool left_to_right) {
    step = std::abs(step);
    left_to_right ? true : step = -step;
    for (int i = 0; i < width; i += step) {
        this->print(x + i, y, element);
        y++;
    }
}

template <typename Element>
void ConsolePrinter<Element>::print_diagonal_line(int x, int y, int width, int step, Element element, Color background, Color foreground, bool left_to_right) {
    this->console->change_color(background, foreground);
    this->print_diagonal_line(x, y, width, step, element, left_to_right);
}

#endif // CONSOLE_PRINTER_HPP