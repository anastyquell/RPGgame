#pragma once
#include "Magic.h"

class Character {
protected:
    int lvl;
    double hp;
    double maxHp;
    double atk;
    double crit;
    double critRate;

    int opit;
    int point;
public:
    Character()
    {
        
    }
    Character(int lvl, double hp, double atk, double crit, double critRate)
    {
        this->lvl = lvl;
        this->maxHp = hp;
        this->hp = hp;
        this->atk = atk;
        this->crit = crit;
        this->critRate = critRate;
        this->opit = 0;
        this->point = 100;
    }

    virtual int getHp() {
        return this->hp;
    }
    virtual int getMaxHp() {
        return this->maxHp;
    }
    void appLvl(int opit) {
        if (opit >= (1000 * this->lvl)) {
            this->opit = opit - (1000*this->lvl);
            lvl++;
            this->atk*= 2 * lvl;
            this->crit += 0.1 * (lvl / 100);
            this->hp *= 2 * lvl;
            point += 1000;
            cout << "\nВiтаємо, Ваш рiвень пiдвищео до " << this->lvl << endl;
            system("pause");
        }
    }
    int getPoint() {
        return this->point;
    }
    int getOpit() {
        return this->opit;
    }
    double getCrit() {
        return this->crit;
    }
    double getAtk() {
        return this->atk;
    }
    double getCritRate() {
        return this->critRate;
    }
    virtual int getLvl(int lvlMag = 0) { return this->lvl; }

    void setHp(int hp) {
        this->hp = hp;
    }

    void setATK(int atk) {
        this->atk = atk;
    }
    void setCrit(double crit) {
        this->crit = crit;
    }
    void setCritRate(double critRate) {
        this->critRate = critRate;
    }
    void dropPoint(int p) {
        this->point -= p;
    }
    void addOpit(int o) {
        this->opit += o;
    }
    void addPoint(int p) {
        this->opit += p;
    }
   virtual int getStartHp() {
        return this->hp;
    }
    virtual int dropHp(int ataka, int moobType = -1) = 0;

    virtual Magic* UseIceMagic() const = 0;
    virtual Magic* UseFireMagic() const = 0;
    virtual Magic* UseDendroMagic() const = 0;
    virtual Magic* UseElectroMagic() const = 0;
    virtual Magic* UseHeelMagic() const = 0;
    virtual Magic* UseMobMagic() const = 0;

    virtual Magic* UseIceMagic(double lvlScills) const = 0;
    virtual Magic* UseFireMagic(double lvlScills) const = 0;
    virtual Magic* UseDendroMagic(double lvlScills) const = 0;
    virtual Magic* UseElectroMagic(double lvlScills) const = 0;
    virtual Magic* UseHeelMagic(double lvlScills) const = 0;
    virtual Magic* UseMobMagic(double lvlScills) const = 0;
};


class Enemy : public Character {
public:

};


class ClassCharacter : public Character {
public:
    ClassCharacter() :Character()
    {}
    ClassCharacter(double lvl, double hp, double atk, double crit, double critRate) : Character(lvl, hp, atk, crit, critRate)
    {}
    Magic* UseIceMagic() const override {
        return new Ice();
    }
    Magic* UseFireMagic() const override {
        return new Fire();
    }
    Magic* UseDendroMagic() const override {
        return new Dendro();
    }
    Magic* UseElectroMagic() const override {
        return new Electro();
    }
    Magic* UseHeelMagic() const override {
        return new Heel();
    }
    Magic* UseMobMagic() const override {
        return new MoobsAttack();
    }

    Magic* UseIceMagic(double lvlScills) const override {
        return new Ice(lvlScills);
    }
    Magic* UseFireMagic(double lvlScills) const override {
        return new Fire(lvlScills);
    }
    Magic* UseDendroMagic(double lvlScills) const override {
        return new Dendro(lvlScills);
    }
    Magic* UseElectroMagic(double lvlScills) const override {
        return new Electro(lvlScills);
    }
    Magic* UseHeelMagic(double lvlScills) const override {
        return new Heel(lvlScills);
    }
    Magic* UseMobMagic(double lvlScills) const override {
        return new MoobsAttack(lvlScills);
    }
};

class Magician : public ClassCharacter
{
public:
    Magician() :ClassCharacter()
    {}
    Magician(double lvl, double hp, double atk, double crit, double critRate) : ClassCharacter(lvl, hp, atk, crit, critRate)
    {
       
    }

    void setLvl(int lvl) {
        this->lvl = lvl;
    }

    int dropHp(int ataka, int moobType = -1) override{
        this->hp -= ataka;
        return this->hp;
    }
    void startParams() {
        this->setHp(500); this->setLvl(1); this->setATK(2000); this->setCrit(1); this->setCritRate(0.3);
    }
};

class Mob : public ClassCharacter {
    double resist;
    double setMoobResist(int moobType) {
        switch (moobType)
        {
        case 1:
            resist = 0.1;
            break;
        case 2:
            resist = 0.3;
            break;
        case 3:
            resist = 0.5;
            break;
        case 4:
            resist = 0.05;
        default:
            break;
        }
        return resist;
    }
public:
    Mob() :ClassCharacter()
    {
        this->lvl = 1;
        this->hp = 100;
        this->atk = 1000;
        this->crit = 1;
        this->critRate = 0.1;
    }
    Mob(double lvl, double hp, double atk, double crit, double critRate) : ClassCharacter(lvl, hp, atk, crit, critRate)
    {}
    int getLvl(int lvlMag) {
        int max = lvlMag + 2;
        int min;
        if (lvlMag > 2) min = lvlMag - 2;
        else min = lvlMag;
        this->lvl = min + rand() % (max - min + 1);
        return this->lvl;
    }
    int getATK() {
        this->atk *= 2 * lvl;
        return this->atk;
    }
    int dropHp(int ataka, int moobType = -1) override{
        resist = setMoobResist(moobType);
        this->hp -= ataka * resist;
        return this->hp;
    }
    int getStartHp() override{
        if (this->hp <= 0) {
            this->hp = 100;
        }
        this->hp *= 2 * lvl;
        return this->hp;
    }
};


std::ostream& operator << (std::ostream& out, Magician* mag)
{
    out << "Mag:" << std::endl << std::endl;
    out << "lvl: " << mag->getLvl() << std::endl;
    out << "hp: " << mag->getHp() << std::endl;
    out << "atk: " << mag->getAtk() << std::endl;
    out << "crit: " << mag->getCrit() << std::endl;
    out << "critRate: " << mag->getCritRate() << std::endl;
    return out;
}

