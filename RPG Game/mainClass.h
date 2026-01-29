#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Npc
{
protected: 
    string name{ "Персонаж" };
    unsigned int health{ 10 };
    float damage{ 5 };
    unsigned short lvl{ 1 };

public:   
    string GetName() const;
    unsigned int GetHealth() const;
    float GetDamage() const;
    unsigned int GetLvl() const;
    virtual void GetInfo() const;

    virtual void Create() {};
    virtual bool Save();
    virtual bool Load();
    virtual ~Npc() = default;
};
class Wayfarer
{
private:
    unique_ptr<Npc> currentCharacter;
public:
    void Create(unique_ptr<Npc> wayfarer);
    void Create();
    bool Save();
    bool Load(unique_ptr<Npc> wayfarer);
    Npc* GetCharacter();
};
