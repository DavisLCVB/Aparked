#pragma once
#ifndef CONSOLE_READER_HPP
#define CONSOLE_READER_HPP

#include <ControlConsole.hpp>
#include <ConsolePrinter.hpp>
#include <conio.h>
#include <string>
#include <Keys.hpp>

/**
 * @class ConsoleReader
 * @brief Una clase que proporciona métodos para leer la entrada desde la consola.
 */
class ConsoleReader {
private:
    ControlConsole *console; /**< Puntero al objeto ControlConsole. */
    ConsolePrinter<std::string> *printer; /**< Puntero al objeto ConsolePrinter. */
public:
    /**
     * @brief Constructor de la clase ConsoleReader.
     * @param console Puntero al objeto ControlConsole.
     * @param printer Puntero al objeto ConsolePrinter.
     */
    ConsoleReader(ControlConsole *console, ConsolePrinter<std::string> *printer);

    /**
     * @brief Establece el objeto ControlConsole.
     * @param console Puntero al objeto ControlConsole.
     */
    void set_console(ControlConsole *console);

    /**
     * @brief Obtiene el objeto ControlConsole.
     * @return Puntero al objeto ControlConsole.
     */
    ControlConsole *get_console();

    /**
     * @brief Establece el objeto ConsolePrinter.
     * @param printer Puntero al objeto ConsolePrinter.
     */
    void set_printer(ConsolePrinter<std::string> *printer);

    /**
     * @brief Obtiene el objeto ConsolePrinter.
     * @return Puntero al objeto ConsolePrinter.
     */
    ConsolePrinter<std::string> *get_printer();

    /**
     * @brief Lee una cadena desde la consola.
     * @return La cadena leída desde la consola.
     */
    std::string read();

    /**
     * @brief Lee una cadena desde la consola con colores de primer plano y fondo especificados.
     * @param foreground El color de primer plano de la consola.
     * @param background El color de fondo de la consola.
     * @return La cadena leída desde la consola.
     */
    std::string read(Color foreground, Color background);

    /**
     * @brief Lee una cadena desde la consola con un ancho especificado.
     * @param width El ancho de la entrada.
     * @return La cadena leída desde la consola.
     */
    std::string read(int width);

    /**
     * @brief Lee una cadena desde la consola con un ancho, colores de primer plano y fondo especificados.
     * @param width El ancho de la entrada.
     * @param foreground El color de primer plano de la consola.
     * @param background El color de fondo de la consola.
     * @return La cadena leída desde la consola.
     */
    std::string read(int width, Color foreground, Color background);
};
#endif // CONSOLE_READER_HPP