#ifndef DODATKI_H
#define DODATKI_H

#include <iostream>
#include <string>
#include <memory>
#include "Napoj.h"

class DekoratorDodatku : public Napoj
{
    protected:
        std::unique_ptr<Napoj> napoj;
    public:
        DekoratorDodatku(std::unique_ptr<Napoj> n) : napoj(std::move(n)) {
        }

        std::string getOpis() override {
            return napoj->getOpis();
        }
        int getCena() override {
            return napoj->getCena();
        }
};

class Mleko : public DekoratorDodatku
{
    private:
        std::string nazwa = "Mleko";
        int cena = 3;
    public:
        Mleko(std::unique_ptr<Napoj> n) : DekoratorDodatku(std::move(n)) {}
        
        std::string getOpis() override
        {
            return napoj->getOpis() + ", " + nazwa;
        }
        int getCena() override
        {
            return napoj->getCena() + cena;
        }
};

class BitaSmietana : public DekoratorDodatku
{
    private:
        std::string nazwa = "Bita smietana";
        int cena = 4;
    public:
        BitaSmietana(std::unique_ptr<Napoj> n) : DekoratorDodatku(std::move(n)) {}
        std::string getOpis() override
        {
            return napoj->getOpis() + ", " + nazwa;
        }
        int getCena() override
        {
            return napoj->getCena() + cena;
        }
};

class SyropKarmelowy : public DekoratorDodatku
{
    private:
        std::string nazwa = "Syrop Karmelowy";
        int cena = 5;
    public:
        SyropKarmelowy(std::unique_ptr<Napoj> n) : DekoratorDodatku(std::move(n)) {}
        std::string getOpis() override
        {
            return napoj->getOpis() + ", " + nazwa;
        }
        int getCena() override
        {
            return napoj->getCena() + cena;
        }
};

class PodwojnaKawa : public DekoratorDodatku
{
    private:
        std::string nazwa = "Podwojna kawa";
    public:
        PodwojnaKawa(std::unique_ptr<Napoj> n) : DekoratorDodatku(std::move(n)) {}
        std::string getOpis() override
        {
            return napoj->getOpis() + ", " + nazwa;
        }
        int getCena() override
        {
            return napoj->getCena()*2;
        }
};
#endif