#include <utils.h>
#include <iostream>
#include <sstream>

std::string Utils::intToString (int a) {
    std::ostringstream temp;
    temp<<a;
    return temp.str();
}

const char * Utils::intToConstCharPointer (int a) {
    std::string temp_string = intToString(a);
    return temp_string.c_str();
}

std::string Utils::floatToString (float a) {
    std::ostringstream temp;
    temp<<a;
    return temp.str();
}

const char * Utils::floatToConstCharPointer (float a) {
    std::string temp_string = floatToString(a);
    return temp_string.c_str();
}