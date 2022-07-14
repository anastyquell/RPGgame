#pragma once
#include "lib.h"


class Magic {
protected:
    double lvlScills;
    double dmgScills;
    double manaDrop;
    double hilling;
    bool statusIce;
    bool statusFire;
    bool statusDendro;
    bool statusElectro;
public:
    Magic()
    {
        this->lvlScills = 1;
        this->dmgScills = 0;
        this->manaDrop = 5;
        this->hilling = 10;
        this->statusIce = this->statusFire = this->statusDendro = this->statusElectro = false;
    }
    Magic(double lvlScills) : Magic()
    {
        this->lvlScills = lvlScills;
    }
    double getLvlScills() {
        return this->lvlScills;
    }
    double getDmgScills() {
        return this->dmgScills;
    }
    double getManaDrop() {
        return this->manaDrop;
    }

    void setLvlScills(double lvlScills) {
        this->lvlScills = lvlScills;
    }
    void setDmgScills(double dmgScills) {
        this->dmgScills = dmgScills;
    }
    void setManaDrop(double manaDrop) {
        this->manaDrop = manaDrop;
    }
    void appLvlScills() {
        this->lvlScills++;
        manaDrop += 5;
    }
    void setStatusIce() { this->statusIce = true; }
    void dropStatusIce() { this->statusIce = false; }
    void setStatusFire() { this->statusFire = true; }
    void dropStatusFire() { this->statusFire = false; }
    void setStatusDendro() { this->statusDendro = true; }
    void dropStatusDendro() { this->statusDendro = false; }
    void setStatusElectro() { this->statusElectro = true; }
    void dropStatusElectro() { this->statusElectro = false; }

    void clearStatus()
    {
        dropStatusIce();
        dropStatusFire();
        dropStatusDendro();
        dropStatusElectro();
    }

    virtual double Use(double value, double dopValue = 0) = 0;
    virtual ~Magic() {};
};


class Fire : public Magic {
public:
    Fire() : Magic()
    {}
    Fire(double lvlScills) : Magic(lvlScills)
    {}
    double Use(double value, double dopValue) override
    {
        if (statusIce) {
            this->dmgScills = lvlScills * value * 0.5;
            this->clearStatus();
        }
        else {
            this->dmgScills = lvlScills * value;
        }
        return this->dmgScills;
    }
    ~Fire() = default;
};

class Ice : public Magic {
public:
    Ice() : Magic()
    {}
    Ice(double lvlScills) : Magic(lvlScills)
    {}
    double Use(double value, double dopValue) override {
        if (statusFire) {
            this->dmgScills = lvlScills * value * 0.5;
            this->dropStatusFire();
        }
        else {
            this->dmgScills = lvlScills * value;
        }
        return this->dmgScills;
    }
};
class Electro : public Magic {
public:
    Electro() : Magic()
    {}
    Electro(double lvlScills) : Magic(lvlScills)
    {}
    double Use(double value, double dopValue) override {
        if (statusDendro) {
            this->dmgScills = lvlScills * value * 0.5;
            this->dropStatusDendro();
        }
        else {
            this->dmgScills = lvlScills * value;
        }
        return this->dmgScills;
    }
};

class Dendro : public Magic {
public:
    Dendro() : Magic()
    {}
    Dendro(double lvlScills) : Magic(lvlScills)
    {}
    double Use(double value, double dopValue = 0) override {
        if (statusElectro) {
            this->dmgScills = lvlScills * value * 0.5;
            this->dropStatusElectro();
        }
        else {
            this->dmgScills = lvlScills * value;
        }
        return this->dmgScills;
    }
};

class Heel : public Magic {
public:
    Heel() : Magic()
    {}
    Heel(double lvlScills) : Magic(lvlScills)
    {}
    double Use(double value, double dopValue = 0) override {
        value += (this->hilling * this->lvlScills);
        if (value < dopValue) {
            return value;
        }
        else {
            return dopValue;
        }
    }
};

class MoobsAttack : public Magic {
public:
    MoobsAttack() : Magic()
    {}
    MoobsAttack(double lvlScills) : Magic(lvlScills)
    {}
    double Use(double value, double dopValue = 0) override {
        this->dmgScills = lvlScills;
        return this->dmgScills;
    }
};