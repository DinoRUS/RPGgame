#pragma once
#include "mainClass.h"
#include "string"

class Nemesis : public virtual Npc
{
protected:  
    unsigned short strenght{ 430 };
    string weapons[4] = { "Алый Меч", "Арбалет", "Кровавая Булава", "Кинжал" };
public:
    bool Save() override;
    bool Load() override;
    Nemesis();
    Nemesis(string name, unsigned int health, float damage);

    void GetWeapons();
    void GetInfo();
    void Create() override;

    bool operator == (const Nemesis& nemesis) const;
    Nemesis& operator = (const Npc& npc);

    ~Nemesis();
};

class Omega : public virtual Npc
{

    class Art
    {
    protected:
        string name{ "Ореол" };
        unsigned short damage{ 0 };
        unsigned short price{ 0 };
        bool isCurse{ false };
        int timeCast{ 0 };

    public:
        Art(string name = "Ореол", unsigned short damage = 0,
            unsigned short price = 0, bool isCurse = false, int timeCast = 0);

        string GetName() const { return name; }
        unsigned short GetDamage() const { return damage; }
        unsigned short GetPrice() const { return price; }
        bool IsCurse() const { return isCurse; }
        int GetTimeCast() const { return timeCast; }

        unsigned short CastArt();
    };
protected:
    unsigned short intellect = 380;
    Art arts[5] = {
        Art("Коллапс сверхновой", 340,100,false,30),
        Art("Дыхание пустоты", 0,45,false,100),
        Art("Энтропийный распад", 15,50,true,10),
        Art("Сфера сингулярности", 0,200,false,5),
        Art("Квантовая нить судьбы", 0,100,false,15),
    };
public:
    Omega();
    Omega(string name, unsigned int health, float damage);
    void GetArts();
    void GetInfo();
    void GetArtInfo();
    void Create() override;
    bool operator == (const Omega& omega) const;
    void operator = (Npc npc);
    bool Save() override;
    bool Load() override;
    ~Omega(); //деструктор всегда без аргументов
};

class Stormtrooper : public Nemesis, public Omega
{
public:
    Juggernaut();
    void GetInfo();
    void Create() override;
    bool operator == (const Juggernaut& juggernaut) const;
    Juggernaut& operator = (const Npc& npc);
    bool Save() override;
    bool Load() override;
};
