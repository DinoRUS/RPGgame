#pragma once
#include "mainClass.cpp"
#include <string>

//наследование - использование доступных свойств
// и методов класса родителям (parent), классом наследником(child)
class Warrior : public virtual Npc //наследование с модификатором доступа public
{
protected:  //модификатор 0 (приватный - защищенный, доступ к полям, только внутри класса)
    unsigned short strenght{ 31 };
    string weapons[4] = { "кастет", "дубинка", "клинок", "меч" };
public:
    //конструктор - метод, который вызывается в момент создания экземпляра
    //класса (вручную вызвать в основном потоке программы не можем)
    Warrior();//конструктор по умолчанию, когда нет аргументов
    //кастомный конструктор
    Warrior(string name, unsigned int health, float damage);

    void GetWeapons()
    {

    };
    void GetInfo() override
    {

    };  //полиморфизм (перегрузка для метода)
    void Create() override
    {

    };

    //перегрузка операторов
    //перегрузка оператора сравнения (==)

    bool operator == (const Warrior& warrior) const {
        return (wairror.damage == this->damage) &&
            (wairror.health == this->health) &&
            (wairror.strength == this->strength);
    }

    Warrior& operator = (const Npc& npc)
    {


        if (this != &npc)
        {
            this->name = npc.GetName();
            this->health = npc.GetHeatlh();
            this->damage = npc.GetDamage();
            this->lvl = npc.GetLvl();
            return *this;
        }
    }
    void operator = (Npc npc);
    bool Save() override
    {
        ofstream saveSystem("save.bin", ios::binary);
        if (saveSystem.is_open())
        {
            if (!Npc::Save())
            {
                cout << "Сохранение не удалось\nПопробуйте позже\n";
                return false;
            }

            saveSystem.write(reinterpret_cast<const char*>(&strenght), sizeof(strenght));
            saveSystem.close();
            return true;
        }
        else
        {
            cout << "Сохранение не удалось\nПопробуйте позже\n";
            return false;
        }
    }
    bool Load() override
    {
        ifstream loadSsystem("save.bin", ios::binary);
        if (loadSystem.is_open())
        {
            if (!Npc::Load())
            {
                cout << "Связь с небесами нарушена\nПамять о ваших прошлых путешествиях повреждена\n";
                return false;
            }
            loadSystem.read(reinterpret_cast<char*>(&strenght), sizeof(strenght))
        }
        else
        {
            cout << "Связь с небесами нарушена\nПамять о ваших прошлых путешествиях повреждена\n";
            return false;
        }
        loadSystem.close();
        return true;
    };

    ~Warrior()
    {

    }; //деструктор всегда без аргументов

};


//virtual - создает виртуализацию методов, классов
//при этом сам класс повторно не создается
class Wizard : public virtual Npc
{
    class Spell
    {
    protected:
        string name{ "заклинание" };
        unsigned short damage{ 0 };
        unsigned short price{ 0 };
        bool isCurse{ false };
        int timeCast{ 0 };
    public:

        Spell(string name = "заклинание", unsigned short damage = 0,
            unsigned short price = 0, bool isCurse = false, int timeCast = 0)
        {
            this->name = name;
            this->damage = damage;
            this->price = price;
            this->isCurse = isCurse;
            this->timeCast = timeCast;
        }

        string operator[](unsigned index) const
        {
            switch (index)
            {
            case 0: return "Название - " + name; break;
            case 1: return "Урон - " + to_string(damage); break;
            case 2: return  "Стоймость применения -" + to_string(price) + "маны"; break;
            case 3:
            {
                if (isCurse)
                {
                    return "периодичный урон";
                }
                else {
                    return "произносимое заклинание";
                }
                break;
            }
            case 4: return isCurse ? "Длительность негативного эффекта - " + to_string(timeCast) :
                "Длительность применения - " + to_string(timeCast);
                break;
            default: return "такого свойства заклинания не существует";
                break;
            }
        }

        unsigned short CastSpell()
        {
            cout << "Вы применили " << name << " на противнике" << endl;
            return damage;
        }
    };
protected:
    unsigned short intellect = 27;
    Spell spells[5] = {
        Spell("Лазер",20,50,false,3)
        Spell("Заморзка",10,30,false,1)
        Spell("Вулкан",10,20,false)
        Spell("Метеор",10,25,true,5)
        Spell("Вихрь",5,10,false,10)
    };
public:
    Wizard();
    Wizard(string name, unsigned int health, float damage);
    void GetInfo() override;  //полиморфизм (перегрузка для метода)
    void Create() override;
    Wizard operator + (const Wizard& wizard) const;
    bool Save() override;
    ~Wizard();
}
//множественное наследование
class Paladin : public Warrior, public Wizard
    //следующий родительственный класс добавляется через запятую
{
public:
    Paladin()
    {
        name = "паладин";
        health = 25;
        damage = 12;
        strenght = 27;
    }
    void GetInfo() override
    {
        Warrior::GetInfo();
        cout << "Интеллект - " << intellect << endl;
        cout << "Доступные заклинания в книге заклинаний - ";
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
    bool operator == (const Paladin& paladin) const
    {
        return ((paladin.damage == this->damage) && (paladin.health == this->health)
            && (paladin.intellect == this->intellect)) && (paladin.strenght == this->strenght);
    }
    void operator = (Npc npc)
    {
        this->name = npc.GetName();
        this->name = npc.GetHealth();
        this->name = npc.GetDamage();
        this->name = npc.GetLvl();
    }
    bool Save() override
    {


        if (Npc::Save())
        {
            ofstream saveSystem("save.bin", ios::binary);
            if (saveSystem.is_open())
            {

                saveSystem.write(reinterpret_cast<const char*>(&intellect), sizeof(intellect));
                for (int i = 0; i < 4; i++)
                {
                    saveSystem.write(reinterpret_cast<const char*>(&spell[i]), sizeof(spell[i]));
                }
                saveSystem.close();
                return true;
            }
            else
            {
                cout << "сохранение не удалось" << endl;
                return false;
            }
        }
    }
};
