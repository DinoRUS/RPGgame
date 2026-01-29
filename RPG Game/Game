#include <iostream>
#include "windows.h"

using namespace std;

//модификаторы доступа:
// private - приватный, запрещает доступ к свойствам и классам за пределами самого класса
// protected - защищенный, можно передавать свойства и методы в классы наследники, но не использовать в основном потоке программы
// public - публичный, общедоступный, можно использовать везде

//базовый класс - абстрактный (класс у которого все методы виртуальные)
class Npc
{
protected: //модификатор 0 защищенный (дает доступ внутри класса родителя и наследника), но все еще не дает доступ в основном потоке программы
    string name{ "персонаж" };
    unsigned int health{ 10 };
    float damage{ 5 };
    unsigned short lvl{ 1 };
public: //публичный модификатор доступ (использовать метод можно в любом месте)
    virtual void GetInfo() //метод класса
    {
        cout << "Имя - " << name << endl;
        cout << "Здоровье - " << health << endl;
        cout << "Урон - " << damage << endl;
    }
    virtual void Create() {};
};

//наследование - использование доступных свойств и методов класса родителям (parent), классом наследником(child)
class Warrior : public virtual Npc //наследование с модификатором доступа public
{
protected: //модификатор 0 (приватный - защищенный, доступ к полям, только внутри класса)
    unsigned short strenght{ 31 };
    string weapons[4] = { "кастет", "дубинка", "клинок", "меч" };
public:
    //конструктор - метод, который вызывается в момент создания экземпляра класса (вручную вызвать в основном потоке программы не можем)

    Warrior() //конструктор по умолчанию, когда нет аргументов
    {
        name = "воин";
        health = 50;
        damage = 20;
    }
    //кастомный конструктор
    Warrior(string name, unsigned int health, float damage)
    {
        cout << "конструктор война" << endl;
        this->name = name;
        this->health = health;
        this->damage = damage;
    }

    void GetWeapons()
    {
        cout << name << " взял в руки " << weapons[lvl - 1];
    }
    void GetInfo() override //полиморфизм (перегрузка для метода)
    {
        Npc::GetInfo();
        cout << "Сила - " << strenght << endl;
        cout << "Доступное оружие - ";
        for (int i = 0; i < lvl; i++)
        {
            cout << weapons[i] << endl;
        }
    }
    void Create() override
    {
        cout << "Вы создали война" << endl;
        cout << "Введите имя персонажа\t";
        cin >> name;
        GetInfo();
        GetWeapons();
    }
    //перегрузка операторов
    //перегрузка оператора сравнения (==)
    bool operator == (const Warrior& warrior) const
    {
        return ((warrior.damage == this->damage) && (warrior.health == this->health)
            && (warrior.strenght == this->strenght));
    }
    //деструктор - метод, который вызывается автоматически при высвобождении памяти
    //при окончании работы с экземпляром класса (нельзя вызвать вручную)

    ~Warrior() //деструктор всегда без аргументов
    {
        cout << endl;
        cout << name << " пал смертью храбрых" << endl;
    }
};

//virtual - создает виртуализацию методов, классов при этом сам класс повторно не создается

class Wizard : public virtual Npc
{
protected:
    unsigned short intellect = 27;
    string spell[4] = { "ослепление", "огненная стрела", "огненный шар", "токсичныый дождь" };
public:
    Wizard()
    {
        name = "волшебник";
        health = 30;
        damage = 25;
    }
    Wizard(string name, unsigned int health, float damage)
    {
        cout << "конструктор волшебника" << endl;
        this->name = name;
        this->health = health;
        this->damage = damage;
    }
    void GetInfo() override //полиморфизм (перегрузка для метода)
    {
        Npc::GetInfo();
        cout << "Интеллект - " << intellect << endl;
        cout << "Доступные заклинания в книге заклинаний - ";
        for (int i = 0; i < lvl; i++)
        {
            cout << spell[i] << endl;
        }
    }
    void CastSpell()
    {
        cout << name << " применяет " << spell[lvl - 1] << endl;
    }
    void Create() override
    {
        cout << "Вы создали волшебника" << endl;
        cout << "Введите имя персонажа\t";
        cin >> name;
        GetInfo();
        CastSpell();
    }
    Wizard operator + (const Wizard& wizard) const
    {
        return Wizard(this->name, (this->health + wizard.health), (this->damage + wizard.damage));
    }
    ~Wizard() //деструктор всегда без аргументов
    {
        cout << endl;
        cout << name << " испустил дух" << endl;
    }
};

//множественное наследование
class Paladin : public Warrior, public Wizard
//следующий родительственный класс добавляется через запятую
{
public:
    Paladin()
    {
        name = "паладин";
        health = 75;
        damage = 10;
        strenght = 30;
    }
    void GetInfo() override
    {
        Warrior::GetInfo();
        cout << "Интеллект - " << intellect << endl;
        cout << "Доступные заклинания - ";
        for (int i = 0; i < lvl; i++)
        {
            cout << spell[i] << endl;
        }
    }
    void Create() override
    {
        cout << "Вы создали паладина" << endl;
        cout << "Введите имя персонажа\t";
        cin >> name;
        GetInfo();
        CastSpell();
        GetWeapons();
    }
};

class Player
{
public:
    void Create(Npc* player)
    {
        player->Create();
    }
};

unsigned short GetChoice(unsigned short first, unsigned short last);

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Warrior* warrior = new Warrior();
    Warrior* warrior2 = new Warrior();
    
    cout << (*warrior == *warrior2) << endl;

    Wizard* wizard = new Wizard();
    Wizard* wizard2 = new Wizard();
    Wizard* megaWizard = new Wizard();
   
    *megaWizard = *wizard + *wizard2;
    megaWizard->GetInfo();

    Paladin* paladin = new Paladin();
    Player* player = new Player();

    cout << "Привет, странник\nПрисядь у костра и расскажи о себе\n";
    cout << "Ты впервые тут? (1 - новый персонаж, 2 - загрузить)\n";

    unsigned short choice = GetChoice(1, 2); 

    if (choice == 1)
    {
        cout << "Расскажи о своих навыках\n1 - Воин\n2 - Волшебник\n3 - Паладин\n";
        choice = GetChoice(1, 3); 
        switch (choice)
        {
        case 1:
            player->Create(warrior);
            delete wizard;
            delete paladin;
            break;
        case 2:
            player->Create(wizard);
            delete warrior;
            delete paladin;
            break;
        case 3:
            player->Create(paladin);
            delete warrior;
            delete wizard;
            break;
        }
    }
    if (choice == 2)
    {
       
        cout << "Загрузка персонажа..." << endl;
        delete warrior;
        delete warrior2;
        delete wizard;
        delete wizard2;
        delete megaWizard;
        delete paladin;
    }


   
    return 0;
}

unsigned short GetChoice(unsigned short first, unsigned short last) 
{
    unsigned short choice;
    cin >> choice;
    while (choice < first || choice > last) {
        cout << "Неверный ввод! Введите число от " << first << " до " << last;
        cout << endl;
        cin >> choice;
    }
    return choice;

}
