#include "ceasar.h"
#include <iostream>
#include <fstream>

int main() {
    std::string commande_text;
    std::string text;
    int step;

    do {
        std::cout << "please Enter command(decode/encode)" << std::endl;
        std::cin >> commande_text;
        std::cout << "please Enter text" << std::endl;
        std::cin >> text;
        std::cout << "please Enter step" << std::endl;
        std::cin >> step;
        if((!commande_text.empty()) && (!text.empty())) {break;}
    }while (true);
    Ceasar obj(commande_text, text, step);

       
}