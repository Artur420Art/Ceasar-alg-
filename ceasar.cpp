#include <iostream>
#include <vector>
#include "ceasar.h"

std::string Ceasar::m_decode(std::string& str, const size_t pos = 1)
{
    int size = str.length();
    for (int i = 0; i < size; ++i)
    {
        char letter = str[i]; 
        if(letter >= range::a && letter <= range::z) {
            letter -= pos;
            if (letter < range::a) {
                letter = letter - range::a + range::z + 1;
            }
        }
        else if(letter >= range::A && letter < range::Z) {
            letter -= pos;
            if (letter > range::a) {
                letter = letter - range::A + range::Z + 1;
            }
        }         
        str[i] = letter;
    }

    std::cout << str;
    return str;
}
std::string Ceasar::m_encode(std::string& str, const size_t pos = 1)
{
    int size = str.length();
    for (int i = 0; i < size; ++i)
    {
        char letter = str[i];
        if(letter >= range::a && letter <= range::z) {
            letter += pos;
            if (letter > range::z) {
                letter = letter + range::a - range::z + 1;
            }
        }
        else if(letter >= range::A && letter <= range::Z) {
            letter += pos;
            if (letter < range::Z) {
                letter = letter + range::A - range::Z + 1;
            }
        }         
        str[i] = letter;
    }
    std::cout << str;

    return str;
}

void Ceasar::init() {

    m_comm_f["decode"] = commands::DECODE;
    m_comm_f["encode"] = commands::ENCODE;

    m_func[commands::DECODE] = &Ceasar::m_decode;
    m_func[commands::ENCODE] = &Ceasar::m_encode;


}

Ceasar::Ceasar(std::string& str, std::string& let, int step = 1) {
    this->init();
    if (m_comm_f.find(str) == m_comm_f.end()) {throw std::invalid_argument("command not valid");}

    (this->*m_func[m_comm_f[str]])(let, step);
}

