#include "../hpp/Priest.hpp"

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
