#include <iostream>
#include <memory>
#include "Napoj.h"
#include "Dodatki.h"

void printMessage(std::string opis, int cena) 
{
    std::cout << "Napoj: " << opis << std::endl << " Cena: " << cena << " zl" << std::endl;
}

int main() 
{
    std::unique_ptr<Napoj> napoj1 = std::make_unique<Esspresso>();
    napoj1 = std::make_unique<Mleko>(std::move(napoj1));
    napoj1 = std::make_unique<BitaSmietana>(std::move(napoj1));
    printMessage(napoj1->getOpis(), napoj1->getCena());

    std::unique_ptr<Napoj> napoj2 = std::make_unique<Herbata>();
    napoj2 = std::make_unique<SyropKarmelowy>(std::move(napoj2));
    napoj2 = std::make_unique<Mleko>(std::move(napoj2));
    napoj2 = std::make_unique<BitaSmietana>(std::move(napoj2));
    printMessage(napoj2->getOpis(), napoj2->getCena());

    std::unique_ptr<Napoj> napoj3 = std::make_unique<Herbata>();
    napoj3 = std::make_unique<Mleko>(std::move(napoj3));
    napoj3 = std::make_unique<BitaSmietana>(std::move(napoj3));
    napoj3 = std::make_unique<SyropKarmelowy>(std::move(napoj3));
    printMessage(napoj3->getOpis(), napoj3->getCena());
}