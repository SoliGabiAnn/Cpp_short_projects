#ifndef NAPOJ_H
#define NAPOJ_H

#include <iostream>
#include <string>
#include <memory>

class Napoj 
{
public:
    virtual ~Napoj() = default;
    virtual std::string getOpis() = 0;
    virtual int getCena() = 0;
};

class Esspresso : public Napoj
{
    private:
        std::string nazwa = "Esspresso";
        int cena = 8;
    public:
        std::string getOpis() override
        {
            return  nazwa;
        }
        int getCena() override
        {
            return cena;
        }
};


class Americano : public Napoj
{
    private:
        std::string nazwa = "Americano";
        int cena = 6;
    public:
        std::string getOpis() override
        {
            return nazwa;
        }
        int getCena() override
        {
            return cena;
        }
};

class Herbata : public Napoj
{
    private:
        std::string nazwa = "Herbata";
        int cena = 7;
    public:
        std::string getOpis() override
        {
            return  nazwa;
        }
        int getCena() override
        {
            return cena;
        }
};

#endif