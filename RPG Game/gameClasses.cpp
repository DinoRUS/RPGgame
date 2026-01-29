
#include "gameClasses.h"

bool Nemesis::Save()
{
    ofstream saveSystem("save.bin", ios::binary);
    if (saveSystem.is_open())
    {
        if (Npc::Save())
        {
            cout << "Сохранение не удалось" << endl;
            return false;
        }
        saveSystem.write(reinterpret_cast<const char*>(&strenght), sizeof(strenght));
        saveSystem.close();
        return true;
    }
    else
    {
        cout << "Сохранение не удалось" << endl;
        return false;
    }

};
bool Nemesis::Load()
{
    ifstream loadSystem("save.bin", ios::binary);

    if (loadSystem.is_open())
    {
        if (!Npc::Load())
        {
            cout << "Биометрические данные не совпадают.\nЛичность не подтверждена" << endl;
            return false;
        }
        loadSystem.read(reinterpret_cast<char*>(&strenght), sizeof(strenght));

    }
    else
    {
        cout << "Биометрические данные не совпадают.\nЛичность не подтверждена" << endl;
        return false;
    }
    loadSystem.close();
    return true;


};
Nemesis::Nemesis() //конструктор по умолчанию, когда нет аргументов
{
    name = "Немезис";
    health = 1600;
    damage = 250;
}

Nemesis::Nemesis(string name, unsigned int health, float damage)
{
    cout << "конструктор Немезиса" << endl;
    this->name = name;
    this->health = health;
    this->damage = damage;
}

void Nemesis::GetWeapons()
{
    cout << name << " взял в руки " << weapons[lvl - 1];
}
void Nemesis::GetInfo()   //полиморфизм (перегрузка для метода)
{
    Npc::GetInfo();
    cout << "Сила - " << strenght << endl;
    cout << "Доступное оружие - ";
    for (int i = 0; i < lvl; i++)
    {
        cout << weapons[i] << endl;
    }
}
void Nemesis::Create()
{
    cout << "Вы создали немезиса" << endl;
    cout << "Введите имя персонажа\t";
    cin >> name;
    GetInfo();
    GetWeapons();
}
bool Nemesis::operator == (const Nemesis& nemesis) const
{
    return (nemesis.damage == this->damage) &&
        (nemesis.health == this->health) &&
        (nemesis.strenght == this->strenght);
}
Nemesis& Nemesis::operator = (const Npc& npc)
{
    if (this != &npc)
    {
        this->name = npc.GetName();
        this->health = npc.GetHealth();
        this->damage = npc.GetDamage();
        this->lvl = npc.GetLvl();
        return *this;
    }

}

Nemesis::~Nemesis()
{
    cout << name << "\nПоглощен Катастрофой" << endl;
}

TheCaster::Art::Art(string name, unsigned short damage,
    unsigned short price, bool isCurse, int timeCast)
    : name(name), damage(damage), price(price),
    isCurse(isCurse), timeCast(timeCast)
{
}

unsigned short Omega::Art::CastArt()
{
    return 0;
}

bool Omega::Save()
{
    ofstream saveSystem("save.bin", ios::binary);
    if (saveSystem.is_open())
    {
        if (!Npc::Save())
        {
            cout << "Сохранение не удалось" << endl;
            return false;
        }
        saveSystem.write(reinterpret_cast<const char*>(&intellect), sizeof(intellect));
        saveSystem.close();
        return true;
    }
    else
    {
        cout << "Сохранение не удалось" << endl;
        return false;
    }
}
bool Omega::Load()
{
    ifstream loadSystem("save.bin", ios::binary);
    if (loadSystem.is_open())
    {
        if (!Npc::Load())
        {
            cout << "Биометрические данные не совпадают.\nЛичность не подтверждена" << endl;
            return false;
        }
        loadSystem.read(reinterpret_cast<char*>(&intellect), sizeof(intellect));
        loadSystem.close();
        return true;
    }
    else
    {
        cout << "Биометрические данные не совпадают.\nЛичность не подтверждена" << endl;
        return false;
    }
}
Omega::Omega()
{
    name = "Омега";
    health = 1100;
    damage = 300;
}
Omega::Omega(string name, unsigned int health, float damage)
{
    cout << "конструктор омеги" << endl;
    this->name = name;
    this->health = health;
    this->damage = damage;
}
void Omega::GetArts()
{
    cout << name << " взял в руки ";
}
void Omega::GetInfo() //полиморфизм (перегрузка для метода)
{
    Npc::GetInfo();
    cout << "Интеллект - " << intellect << endl;
    cout << "Доступные Ореолы - ";
   

}
void Omega::GetArtInfo()
{
    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << " Искусство: " << arts[i].GetName()
            << ", Урон: " << arts[i].GetDamage()
            << ", Цена: " << arts[i].GetPrice() << endl;
    }

}

void Omega::Create()
{
    cout << "Вы создали омегу" << endl;
    cout << "Введите имя персонажа\t";
    cin >> name;
    GetInfo();

}
bool Omega::operator == (const Omega& omega) const
{
    return ((omega.damage == this->damage) && (omega.health == this->health)
        && (omega.intellect == this->intellect));
}
void Omega::operator = (Npc npc)
{
    this->name = npc.GetName();
    this->name = npc.GetHealth();
    this->name = npc.GetDamage();
    this->name = npc.GetLvl();
}

Omega::~Omega() //деструктор всегда без аргументов
{
    cout << name << "\nПоглощен Катастрофой" << endl;
}

Juggernaut::Juggernaut()
{
    name = "Джаггернаут";
    health = 2500;
    damage = 150;
    strenght = 650;
    intellect = 250;
}
void Juggernaut::GetInfo()
{
    cout << "Имя - " << name << endl;
    cout << "Здоровье - " << health << endl;
    cout << "Урон - " << damage << endl;
    cout << "Сила - " << strenght << endl;
    cout << "Интеллект - " << intellect << endl;
}

void Juggernaut::Create()
{
    cout << "Вы создали джаггернаута" << endl;
    cout << "Введите имя персонажа\t";
    cin >> name;
    GetInfo();
    GetWeapons();  
}

bool Juggernaut::operator == (const Juggernaut& juggernaut) const
{
    return (juggernaut.damage == this->damage) &&
        (juggernaut.health == this->health) &&
        (juggernaut.strenght == this->strenght) &&
        (juggernaut.intellect == this->intellect);
}

Juggernaut& Juggernaut::operator = (const Npc& npc)
{
    if (this != &npc)
    {
        this->name = npc.GetName();
        this->health = npc.GetHealth();
        this->damage = npc.GetDamage();
        this->lvl = npc.GetLvl();
        this->strenght = 410;  
        this->intellect = 350; 
    }
    return *this;
}
bool Juggernaut::Save()
{
    ofstream saveSystem("save.bin", ios::binary);
    if (saveSystem.is_open())
    {
        if (!Npc::Save())
        {
            cout << "Сохранение не удалось" << endl;
            return false;
        }
        saveSystem.write(reinterpret_cast<const char*>(&intellect), sizeof(intellect));
        saveSystem.write(reinterpret_cast<const char*>(&strenght), sizeof(strenght));
        saveSystem.close();
        return true;
    }
    else
    {
        cout << "Сохранение не удалось" << endl;
        return false;
    }
}

bool Juggernaut::Load()
{
    ifstream loadSystem("save.bin", ios::binary);
    if (loadSystem.is_open())
    {
        if (!Npc::Load())
        {
            cout << "Биометрические данные не совпадают.\nЛичность не подтверждена" << endl;
            return false;
        }
        loadSystem.read(reinterpret_cast<char*>(&intellect), sizeof(intellect));
        loadSystem.read(reinterpret_cast<char*>(&strenght), sizeof(strenght));
        loadSystem.close();
        return true;
    }
    else
    {
        cout << "Биометрические данные не совпадают.\nЛичность не подтверждена" << endl;
        return false;
    }
}
