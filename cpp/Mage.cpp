#include "../hpp/Mage.hpp"

Mage::Mage(string name) : Character(name,Job::MageJob,15,200,30,1000), maxMp(100), mp(100){
    this->quickness = rand() % 41 + 100;
}

bool Mage::tryUsingMp(int mp){
    if(this->mp < mp){
        return false;
    }
    this->mp -= mp;
    return true;
}

void Mage::fireball(Character& other){
    if(!tryUsingMp(this->maxMp*0.10f)){
        return;
    }
    int randomNumber = rand() % 10;
    if(randomNumber == 0){
        return;
    }
    other.receiveDamage(this->magicAttack);
}

void Mage::launchSpecialAction(Character& c) {
    this->fireball(c);
}

string Mage::getSpecialActionName() {
    return "Boule de feu";
}
