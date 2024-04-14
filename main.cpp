#include <iostream>
#include <windows.h>
#include "plans.h"

int main() {
    SetConsoleOutputCP( 65001 );

    int e = Plans::parsefile("data.in");

    switch (e) {
        case 0:
            std::cout << "Figūra veiksmīgi izveidota";
            break;
        case 1:
            std::cout << "Jābūt vismaz 3 punkti";
            break;
        case 2:
            std::cout << "Linija nevar sākties un beigties tajā pašā punktā";
            break;
        case 3:
            std::cout << "Līnijas krustojas";
            break;
        case 4:
            std::cout << "kļūda ar ievaddatu failu";
            break;
        case 5:
            std::cout << "Līnijas parklājas";
            break;
        default:
            std::cout << "Neparedzēta kļūda";
            break;
    }
    return 0;
}
