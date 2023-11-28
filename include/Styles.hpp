#pragma once
#ifndef STYLES_HPP
#define STYLES_HPP

#include <vector>
#include <string>

enum class Styles{
    Solid,
    Simple,
    Double,
};

std::string styleToString(Styles style);

#endif // STYLES_HPP