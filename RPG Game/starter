#pragma once
#include "gameClasses.h"
#include <string>

class Warrior : public virtual Npc //íàñëåäîâàíèå ñ ìîäèôèêàòîðîì äîñòóïà public
{
protected:  //ìîäèôèêàòîð 0 (ïðèâàòíûé - çàùèùåííûé, äîñòóï ê ïîëÿì, òîëüêî âíóòðè êëàññà)
	unsigned short strenght{ 31 };
	std::string weapons[4] = { "êàñòåò", "äóáèíêà", "êëèíîê", "ìå÷" };
public:
	Warrior();
	Warrior(std::string name, unsigned int health, float damage);
	void GetWeapons();
	void GetInfo() override;
	void Create() override;
	bool operator == (const Warrior& warrior) const;
	Warrior& operator = (const Npc& npc);
	bool Save() override;
	bool Load() override;
	~Warrior();
};

class Wizard : public virtual Npc
{
public:
	class Spell
	{
		protected: 
			string name{ "çàêëèíàíèå" };
			unsigned short damage{ 0 };
			unsigned short price{ 0 };
			bool isCurse{ false };
			int timeCast{ 0 };
		public:
			Spell(string name = "çàêëèíàíèå", unsigned short damage = 0, unsigned short price = 0, bool isCurse = false, int timeCast = 0);
			string operator[](unsigned index) const;
			unsigned short CastSpell();
	};
protected:
	unsigned short intellect = 27;
	Spell spells[5] = {
    Spell("",52,15,false,60),
		Spell("",1000,70,false,100),
		Spell("",100,25,false,5),
		Spell("",54,30,false,0),
	};
public:
	Wizard();
	Wizard(string name, unsigned int health, float damage);
	void GetInfo() override;
	void Create() override;
	Wizard operator + (const Wizard& wizard) const;
	bool Save() override;
	void GetSpellsInfo();
	~Wizard();
};

class Paladin : public Warrior, public Wizard
{
public:
	Paladin();
	void GetInfo() override;
	void Create() override;
	bool Save() override;

};
