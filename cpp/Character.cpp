#include "../hpp/Character.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> jobs {
    "Freelancer",
    "Mage",
    "Warrior",
    "Barbarian",
    "Druid",
    "Priest",
    "Paladin",
    "Monster",
};

Character::Character(string name, Job job, int pAtt, int mAtt, int def, int maxHp){
    this->name = name;
    this->job = job;
    this->physicalAttack = pAtt;
    this->magicAttack = mAtt;
    this->defense = def;
    this->maxHp = maxHp;
    this->hp = maxHp;
    this->quickness = rand() % 41 + 80;
}


void Character::heal(unsigned int healingValue) {
    if( hp + healingValue > maxHp){
        hp = maxHp;
    }
    else {
        hp += healingValue;
    }
}

void Character::shield(unsigned int shieldValue){
    this->defense += shieldValue;
}

void Character::drink(Potion& p){
    this->heal(p.getHealedHp());
}

Character& Character::operator+=(Potion& p){
    this->drink(p);
    return *this;
}

void Character::attack(Character& defender) {
    int damage = this->physicalAttack - defender.defense;
    defender.receiveDamage(damage);
    cout << this->toString() << " attacks " << defender.toString() << endl;
}

void Character::receiveDamage(int damage){
    if(damage < 0) {
        damage = 0;
    }
    if(this->hp - damage < 0){
        this->hp = 0;
    }
    else {
        this->hp -= damage;
    }
}

void Character::launchSpecialAction() {}
void Character::launchSpecialAction(Character& c) {}
void Character::playRound(vector<Character*>& characters, int nbrAllies) {}
void Character::playRound(vector<Character*>& characters, int nbrAllies, string actionName) {}


int Character::getCurrentHp(){
    return this->hp;
}
int Character::getMaxHp(){
    return this->maxHp;
}
Job Character::getJob() {
    return this->job;
}
string Character::getSpecialActionName() {
    return "Special action";
}

string Character::toString() {
    return this->name + " the " + jobs[this->job]; //+ " (Quickness=" + to_string(this->quickness) + ")";
}