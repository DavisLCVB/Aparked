/**
 * @file Color.hpp
 * @brief Define la enumeración Color.
 */

#pragma once
#ifndef _COLOR_HPP_
#define _COLOR_HPP_

/**
 * @enum Color
 * @brief Representa diferentes colores.
 */
enum class Color {
    BLACK = 0, /**< Color negro */
    BLUE = 1, /**< Color azul */
    GREEN = 2, /**< Color verde */
    CYAN = 3, /**< Color cian */
    RED = 4, /**< Color rojo */
    MAGENTA = 5, /**< Color magenta */
    BROWN = 6, /**< Color marrón */
    LIGHT_GRAY = 7, /**< Color gris claro */
    DARK_GRAY = 8, /**< Color gris oscuro */
    LIGHT_BLUE = 9, /**< Color azul claro */
    LIGHT_GREEN = 10, /**< Color verde claro */
    LIGHT_CYAN = 11, /**< Color cian claro */
    LIGHT_RED = 12, /**< Color rojo claro */
    LIGHT_MAGENTA = 13, /**< Color magenta claro */
    YELLOW = 14, /**< Color amarillo */
    WHITE = 15 /**< Color blanco */
};

/**
 * @brief Convierte un código entero a un valor de Color.
 * @param cod El código entero que representa un color.
 * @return El valor de Color correspondiente.
 */
Color int_to_Color(int cod);

#endif // _COLOR_HPP_