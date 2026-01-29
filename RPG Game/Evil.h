#pragma once
#include "MainClass.h"
#include <iostream>

class ThePriestess : public Npc {
public:
    ThePriestess(const std::string& name);
    ThePriestess(const std::string& name, unsigned int health);
    ThePriestess(const std::string& name, unsigned int health, float damage);
    void GetInfo();
};
