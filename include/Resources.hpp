#pragma once
#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include <vector>
#include <string>

/**
 * @brief La clase Resources representa una colección de recursos estáticos.
 * 
 * Esta clase proporciona acceso a varios recursos estáticos, como logotipos.
 */
class Resources {
    public:
        static std::vector<std::vector<std::string>> logo_estacionamiento; /**< El logotipo para el estacionamiento. */
        static std::vector<std::vector<std::string>> logo_grupo; /**< El logotipo para el grupo. */
};

#endif  // RESOURCES_HPP