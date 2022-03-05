#include <iostream>
#include "Bureaucrat.hpp"

int main () {

    Bureaucrat*  dd = new Bureaucrat("dd", 1599);
    Bureaucrat  hermes("Hermes", 0);
    Bureaucrat  hermes2(hermes);

    std::cout << "copy "; hermes2.promotion();
    hermes.retrograde();
    std::cout << "copy " << hermes2 << "  |  " << hermes << std::endl << *dd << std::endl;
    
    std::cout << "------------------------" << std::endl;
    Bureaucrat  boss("Boss", 1);
    boss.promotion();
    std::cout << boss << std::endl;
    boss.retrograde();
    std::cout << boss << std::endl;
    boss.promotion();
    std::cout << boss << std::endl;

    hermes2 = boss;
    std::cout << hermes2 << std::endl;
    delete dd;
    return 0;
}