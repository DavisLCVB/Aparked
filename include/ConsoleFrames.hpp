#pragma once
#ifndef CONSOLE_FRAMES_HPP
#define CONSOLE_FRAMES_HPP

#include <Color.hpp>
#include <ConsolePrinter.hpp>
#include <ControlConsole.hpp>
#include <OptionController.hpp>
#include <Resources.hpp>
#include <memory>

/**
 * @brief Clase que representa los marcos de la consola.
 *
 * Esta clase se encarga de pintar diferentes marcos en la consola, como el menú principal,
 * la pantalla de carga y las opciones.
 */
class ConsoleFrames {
private:
    ControlConsole *console;
    ConsolePrinter<std::string> *printer;

public:
    /**
     * @brief Constructor de la clase ConsoleFrames.
     *
     * @param console Puntero a la consola de control.
     * @param printer Puntero al objeto ConsolePrinter utilizado para imprimir en la consola.
     */
    ConsoleFrames(ControlConsole *console, ConsolePrinter<std::string> *printer);

    /**
     * @brief Método para pintar el menú principal en la consola.
     */
    void paint_main_menu();

    /**
     * @brief Método para pintar la pantalla de carga en la consola.
     */
    void paint_loading_screen();

    /**
     * @brief Método para pintar las opciones en la consola.
     */
    std::string paint_options_main_menu();

    /**
     * @brief Método para preparar la consola.
     */
    void init_screen();

    /**
     * @brief Método para resetear la consola a su estado original.
     */
    void reset_screen();

    std::string init_main_selection(std::vector<std::string> options, int y_init);

    void paint_customer_data();

    /**
     * @brief Destructor de la clase ConsoleFrames.
     */
    ~ConsoleFrames();
};

#endif // CONSOLE_FRAMES_HPP