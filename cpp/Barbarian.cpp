#include "../hpp/Barbarian.hpp"
#include "../hpp/Character.hpp"

Barbarian::Barbarian(string name) : Character(name,Job::BarbarianJob,200,0,15,900) {
    this->baseAttack = this->physicalAttack;
    this->baseDefense = this->defense;
    this->inFury = false;
    this->quickness = rand() % 41 + 60;
}

void Barbarian::enterFury(){
    cout << this->toString() << " enter fury mode !" << endl;
    baseAttack = this->physicalAttack;
    baseDefense = this->defense;
    furyCharges = 3;
    inFury = true;
    physicalAttack *= 1.5f;
    defense = 0;
    this->receiveDamage(maxHp*0.15f);
}

void Barbarian::leaveFury(){
    cout << this->toString() << " leave fury mode." << endl;
    physicalAttack = baseAttack;
    defense = baseDefense;
    inFury = false;
}

void Barbarian::playRound(vector<Character*>& characters, int nbrAllies, string actionName) {
    vector<Character*> monsters(characters.begin() + nbrAllies + 1, characters.end());
    string userChoice("");

    if (furyCharges > 0) {
        furyCharges--;
    } else {
        if (inFury) {
            this->leaveFury();
        }
    }

    if (actionName == "Attack") {
        cout << "Attack : ";
        for (int i = 1; i <= monsters.size(); i++) {
            string msg = (i == monsters.size()) ? " ? " : ", ";
            cout << to_string(i) << ") " << monsters[i - 1]->toString() << msg;
        }
        cin >> userChoice;
        this->attack(*monsters[stoi(userChoice) - 1]);
        
    } else if (actionName == "Special") {
        if(!inFury) {
            this->enterFury();
        } else {
            cout << this->toString() << " is already in fury." << endl;
            cout << "Do you want to leave the fury ? " << this->furyCharges << " fury tours remaining. (yes/no)" << endl;
            cin >> userChoice;
            if (userChoice == "yes") {
                this->leaveFury();
            }
        }

    } else {
        cout << "Action haven't been recognized, select one between Attack, Special, Potion : ";
        cin >> actionName;
        this->playRound(characters, nbrAllies, actionName);
    }
}

void Barbarian::launchSpecialAction() {
    if( inFury ){
        this->leaveFury();
    } else {
        this->enterFury();
    }
}

void Barbarian::decrementFuryCharges() {
    this->furyCharges--;
}

string Barbarian::getSpecialActionName() {
    return "Fury";
}