#include "../hpp/Barbarian.hpp"

Barbarian::Barbarian(string name) : Character(name,Job::BarbarianJob,200,0,15,900) {
    this->baseAttack = this->physicalAttack;
    this->baseDefense = this->defense;
    this->inFury = false;
    this->quickness = rand() % 41 + 60;
}

void Barbarian::enterFury(){
    baseAttack = this->physicalAttack;
    baseDefense = this->defense;
    inFury = true;
    physicalAttack *= 1.5f;
    defense = 0;
    this->receiveDamage(maxHp*0.15f);
}

void Barbarian::leaveFury(){
    physicalAttack = baseAttack;
    defense = baseDefense;
    inFury = false;
}

void Barbarian::launchSpecialAction() {
    if( inFury ){
        this->leaveFury();
    } else {
        this->enterFury();
    }
}

string Barbarian::getSpecialActionName() {
    return "Furie";
}