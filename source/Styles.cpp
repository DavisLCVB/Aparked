#include <Styles.hpp>

std::string styleToString(Styles style) {
    std::string style_string = "";
    switch (style) {
    case Styles::Solid:
        style_string.append("123456789ab");
        break;
    case Styles::Simple:
        style_string.push_back((char)180); // ┤0
        style_string.push_back((char)179); // │1
        style_string.push_back((char)191); // ┐2
        style_string.push_back((char)192); // └3
        style_string.push_back((char)193); // ┴4
        style_string.push_back((char)194); // ┬5
        style_string.push_back((char)195); // ├6
        style_string.push_back((char)196); // ─7
        style_string.push_back((char)197); // ┼8
        style_string.push_back((char)217); // ┘9
        style_string.push_back((char)218); // ┌10
        break;
    case Styles::Double:
        style_string.push_back((char)185); // ╣0
        style_string.push_back((char)186); // ║1
        style_string.push_back((char)187); // ╗2
        style_string.push_back((char)200); // ╚3
        style_string.push_back((char)202); // ╩4
        style_string.push_back((char)203); // ╦5
        style_string.push_back((char)204); // ╠6
        style_string.push_back((char)205); // ═7
        style_string.push_back((char)206); // ╬8
        style_string.push_back((char)188); // ╝9
        style_string.push_back((char)201); // ╔10
        break;
    default:
        style_string = "123456789ab";
        break;
    }
    return style_string;
}