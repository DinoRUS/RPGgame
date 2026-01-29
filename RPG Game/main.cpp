#include <iostream>
#include "windows.h"
#include "mainClass.h"
#include "gameClasses.h"
#include "Evil.h"

using namespace std;

/*class Product
{
public: Product() = default;
};

class Bread : public Product
{
public: Bread() = default;
};

class Chips : public Product
{
public: Chips() = default;
};

class Creator
{
public:
    Creator() = default;
    virtual Product FactoryMethod() { return Product(); }
};

class BreadCreator : Creator
{
public:
    BreadCreator() = default;
    Product FactoryMethod() override { return Bread(); }
};
class ChipsCreator : Creator
{
public:
    ChipsCreator() = default;
    Product FactoryMethod() override { return Chips(); }
};*/ //пример написания

enum class ValueQuality
{
    мусор, обычное, редкое, легендарное, мифическое //эквивалент перечисления чисел
};

enum class WaponClass
{
    топор, взрывчатка, катана, волшебный_лук, огненный_арбалет
};
enum class SpalloClass
{
    токсичный_дождь, метеор, вспышка, огненный_всплеск, крик_банши
};

enum class CharacterType
{
    UNKNOWN = 0,
    NEMESIS,
    OMEGA, 
    JUGGERNAUT 
};

struct Wapon
{
    string name{ "Оружие" };
    WaponClass wclass = WaponClass::алебарда;
    unsigned int price{ 0 };
    string valueSite[5]{ "Топор","Взрывчатка","Катана","Волшебный_лук","Огненный_арбалет" };
    string site{ NULL };
    unsigned short damage{ 1 };
    Wapon(WaponClass wclass)
    {
        switch (wclass)
        {
        case WaponClass::алебарда:
            cout << "Топор\n";
            break;
        case WaponClass::клеймор:
            cout << "Взрывчатка\n";
            break;
        case WaponClass::катана:
            cout << "Катана\n";
            break;
        case WaponClass::лук:
            cout << "Волшебный_лук\n";
            break;
        case WaponClass::арбалет:
            cout << "Огненный_арбалет\n";
            break;
        default:
            break;
        }
    };
};
struct Spallo
{
    string name{ "Магия" };
    SpalloClass sclass = SpalloClass::токсичный_дождь;
    unsigned int price{ 0 };
    Spallo(SpalloClass sclass)
    {
        switch (sclass)
        {
        case SpalloClass::токсичный_дождь:
            cout << "\n";
            break;
        case SpalloClass::метеор:
            cout << "\n";
            break;
        case SpalloClass::вспышка:
            cout << "\n";
            break;
        case SpalloClass::огненный_всплеск:
            cout << "\n";
            break;
        case SpalloClass::крик_банши:
            cout << "\n";
            break;
        default:
            break;
        }
    };
};
//отличие struct от class
/**/
struct Treasure //по умолчанию все внутри public
{
    string name{ "Ресурс" };
    ValueQuality quality = ValueQuality::мусор;
    unsigned int price{ 0 };
    Treasure(ValueQuality quality)
    {
        switch (quality)
        {
        case ValueQuality::мусор:
            cout << "Обломки\n";
            break;
        case ValueQuality::обычное:
            cout << "Комплект новичков\n";
            break;
        case ValueQuality::редкое:
            cout << "Антиматерия\n";
            break;
        case ValueQuality::легендарное:
            cout << "Мудрая Книга\n";
            break;
        case ValueQuality::мифическое:
            cout << "Яблоко Адема\n";
            break;
        default:
            break;
        }
    }
};
struct Cloth : Treasure //наследование по умолчанию public
{
    Cloth(ValueQuality quaity) : Treasure(quality) {};
    string valueSite[5]{ "Броня для ног","Броня для рук","Броня для головы","Броня для торса","Комплексная: специальная защита" };
    string site{ NULL };
    unsigned short armor{ 1 };
};

/*
class Treasure //все по умолчанию внутри private
{
public:
    string name{ "добыча" };
    string quality[5]{ "мусор","обычное","редкое","легендарное","мифическое" };
    unsigned int price{ 0 };
};
class Cloth : Treasure //наследование по умолчанию private
{
    string valueSite[5]{ "обувь","перчатки","шлем","нагрудник","пояс" };
    string site{ NULL };
    unsigned short armor{ 1 };
};*/

/*unique_ptr<Npc>CreateWapon(WaponClass wclass)
{
    switch (wclass)
    {
    case WaponClass::алебарда:
        //return make_unique<топор>()
        break;
    case WaponClass::взрывчатка:
        break;
    case WaponClass::катана:
        break;
    case WaponClass::волшебный_лук:
        break;
    case WaponClass::огненный_арбалет:
        break;
    default:
        invalid_argument("Неизвестный тип оружия");
        break;
    }
}*/

unique_ptr<Npc> CreateCharacter(CharacterType type)
{
    switch (type)
    {
    case CharacterType::UNKNOWN:
        return make_unique<Npc>();
        break;
    case CharacterType::NEMESIS:
        return make_unique<Nemesis>();
        break;
    case CharacterType::OMEGA:
        return make_unique<Omega>();
        break;
    case CharacterType::JUGGERNAUT:
        return make_unique<Juggernaut>();
        break;
    default:
        invalid_argument("Неизвестная роль");
        break;
    }
}

unsigned short TestChoise(unsigned short maxChoise, string text)
{
    unsigned short choise = 1;
    cin >> choise;
    while (choise > maxChoise || choise < 1)
    {
        cout << text << endl;
        cin >> choise;
    }
    return choise;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    /*Treasure treasure;
    treasure.name = "доисторическая лопата";
    treasure.price = 30;
    treasure.quality = treasure.valuequality[3];
    cout << treasure.name << '\n' << treasure.price << '\n' << treasure.quality << '\n';*/

    /*Cloth cloth(ValueQuality::мифическое);
    cloth.armor = 10;
    cloth.site = cloth.valueSite[2];
    cloth.name = "Шлем Арчи III";
    cloth.price = 50;
    cout << cloth.name << '\n' << cloth.site << '\n' << cloth.armor << '\n' << cloth.price << '\n';

    Wapon wapon(WaponClass::катана);
    wapon.damage = 10;
    wapon.site = wapon.valueSite[2];
    wapon.name = "Тихий ужас";
    wapon.price = 50;
    cout << wapon.name << '\n' << wapon.site << '\n' << wapon.damage << '\n' << wapon.price << '\n';*/

    Wayfarer* wayfarer = new Wayfarer();

    cout << "Добро пожаловать в Адем, присаживайтесь и подпишите здесь...\n";
    cout << "Записать кодовое имя...\n(1 - Новое досье, 2 - Загрузить досье)\n";
    if (TestChoise(2, "Ничего не найдено в наших архивах\nПопытка повторного нахождения документов"))
    {
        cout << "Выберите новый класс из нашего реестра героев:\n\t1 - Немезис\n\t2 - Омега\n\t3 - Джаггернаут\n";
        unique_ptr<Npc> character;
        switch (TestChoise(3, "Хм... Пусто. Ничего нету. Даже листочка не нашлось.\nВы уверены, что работали на нас?\n"))
        {
        case 1:
            character = CreateCharacter(CharacterType::NEMESIS);
            break;
        case 2:
            character = CreateCharacter(CharacterType::OMEGA);
            break;
        case 3:
            character = CreateCharacter(CharacterType::JUGGERNAUT);
            break;
        }
        wayfarer->Create(move(character));
    }
    else
    {
        ifstream loadSystem("save.bin", ios::binary);
        if (!loadSystem.is_open())
        {
            {
                size_t nameLenght;
                loadSystem.read(reinterpret_cast<char*>(&nameLenght), sizeof(nameLenght));
                char* buffer = new char[nameLenght + 1];
                loadSystem.read(buffer, nameLenght);
                buffer[nameLenght] = '\0';

                return loadSystem.good();
            }
        }
    }
    /*unsigned short choise = 1;
    cin >> choise;
    while (choise > 2 || choise < 1)
    {
        cout << "Наверное ты ошибся, повтори снова\n";
        cin >> choise;
    }
    if (choise == 1)
    {
        cout << "Расскажи о своих навыках\n\t1 - Воин\n\t2 - Волшебник\n\t3 - Паладин\n";
        cin >> choise;
        while (choise > 3 || choise < 1)
        {
            cout << "Такого еще не было в наших краях\nНе мог бы ты повторить\n";
            cin >> choise;
        }

        switch (choise)
        {
        case 1: {
            player->Create(warrior);
            delete wizard;
            wizard = nullptr;
            delete paladin;
            paladin = nullptr;
            break;
        }
        case 2: {
            player->Create(wizard);
            delete warrior;
            warrior = nullptr;
            delete paladin;
            paladin = nullptr;
            break;
        }
        case 3: {
            player->Create(paladin);
            delete warrior;
            warrior = nullptr;
            delete wizard;
            wizard = nullptr;
            break;
        }
        }

    }

    else
    {
        player->Load(warrior);
    }

    cout << "Cделаем остановку тут?\n\t1 - Cохранить досье\n\t2 - продолжим путь\n";
    cin >> choise;
    if (choise == 1)
    {
        if (warrior != nullptr) player->Save(warrior);
        if (wizard != nullptr) player->Save(wizard);
        if (paladin != nullptr) player->Save(paladin);
    }*/
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
