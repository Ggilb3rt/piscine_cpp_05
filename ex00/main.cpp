#include <iostream>
#include "Bureaucrat.hpp"

int main () {

    Bureaucrat  hermes("Hermes", 0);
    Bureaucrat  hermes2(hermes);

    hermes2.promotion();
    hermes.retrograde();
    std::cout << hermes2 << "  |  " << hermes << std::endl;
    return 0;
}