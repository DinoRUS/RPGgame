#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Npc
{
protected: //модификатор 0 защищенный (дает доступ внутри класса родителя и наследника)
    //но все еще не дает доступ в основном потоке программы

    string name{ "персонаж" };
    unsigned int health{ 10 };
    float damage{ 5 };
    unsigned short lvl{ 1 };

public:    //публичный модификатор доступ (использовать метод можно в любом месте)
    string GetName() const {};
    unsigned int GetHealth();
    float GetDamage();
    unsigned int GetLvl();
    virtual void GetInfo();
    virtual void Create() {};
    virtual bool Save() ;

    Npc Load();




};
class Player
{
private:
    unique_ptr<Npc> currentCharacter{ nullptr };
public:
    void Create(unique_ptr<Npc> player)
    {
        currentCharacter = move(player);
        currentCharacter->Create();
    }
    void Create()
    {
        if (currentCharacter != nullptr)
            currentCharacter->Create();
    }
    bool Save()
    {
        return currentCharacter ? currentCharacter->Save() : false;
    }
    bool Load(unique_ptr<Npc> player)
    {
        if (player->Load()) {
            currentCharacter = move(player);
            return true;
        }
        return false;
    }
    Npc* GetCharacter()
    {
        return currentCharacter.get();
    }
};

virtual bool Load()
{
    ifstream loadSystem("save.bin", ios::binary);
    if (loadSsytem.is open())
    {
        size_t nameLength;
        loadSystem.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
        char* buffer = new char[nameLength + 1];
        loadSystem.read(buffer, nameLength);
        buffer[nameLength] = '\0';
        name = string(buffer);
        delete[] buffer;

        loadSystem.read(reinterpret_cast<char*>(&health), sizeof(health));
        loadSystem.read(reinterpret_cast<char*>(&damage), sizeof(damage));
        loadSystem.read(reinterpret_cast<char*>(&lvl), sizeof(lvl));
        return loadSystem.good();
    }
    else
    {
        cout << "Связь с небесами нарушена\nПамять о ваших прошлых путешествиях\n";
        return false;
    }
    loadSystem.close();

    virtual ~Npc() = default;
};
