#include "Evil.h"

using namespace std;

ThePriestess::ThePriestess(const std::string& name) {
    this->name = name;
    health = 10;
    damage = 5.0f;  
}

ThePriestess::ThePriestess(const std::string& name, unsigned int health) : ThePriestess(name) {
    this->health = health;
}

ThePriestess::ThePriestess(const std::string& name, unsigned int health, float damage) : ThePriestess(name, health) {
    this->damage = damage;  
}

void ThePriestess::GetInfo() {
    cout << endl;
    cout << "на вас напал " << name << endl;
    if (health >= 0 && damage < 0) {
        cout << "Здоровье - " << health << endl;
    }
    if (health < 0 && damage >= 0) {
        cout << "урон - " << damage << endl;
    }
    if (health >= 0 && damage >= 0) {
        cout << "Здоровье - " << health << endl;
        cout << "урон - " << damage << endl;
    }
}
