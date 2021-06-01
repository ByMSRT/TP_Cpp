#include "../hpp/Priest.hpp"

Priest::Priest(string name) : Character(name,Job::PriestJob,20,250,20,1000), mp(100), maxMp(100){
    this->quickness = rand() % 41 + 70;
}

bool Priest::tryUsingMp(int mp){
    if(this->mp < mp){
        return false;
    }
    this->mp -= mp;
    return true;
}

void Priest::healOther(Character& other){
    if(!tryUsingMp(this->maxMp*0.10f)){
        return;
    }

    int randomHeal = rand() % (magicAttack + 1) + magicAttack;

    if(randomHeal + other.getCurrentHp() <= other.getMaxHp()){
        other.heal(randomHeal);
    }
    
}

void Priest::launchSpecialAction(Character& c) {
    this->healOther(c);
}

string getSpecialActionName() {
    return "Soin d'allié";
}