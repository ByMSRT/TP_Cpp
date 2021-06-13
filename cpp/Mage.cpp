#include "../hpp/Mage.hpp"
#include "../hpp/Character.hpp"

Mage::Mage(string name) : Character(name,Job::MageJob,65,200,30,1000), maxMp(100), mp(100){
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

void Mage::playRound(vector<Character*>& characters, int nbrAllies, string actionName) {
    vector<Character*> monsters(characters.begin() + nbrAllies + 1, characters.end());
    string userChoice("");
    
    if (actionName == "Attack") {
        cout << "Attack : ";
        for (int i = 1; i <= monsters.size(); i++) {
            string msg = (i == monsters.size()) ? " ? " : ", ";
            cout << to_string(i) << ") " << monsters[i - 1]->toString() << msg;
        }
        cin >> userChoice;
        this->attack(*monsters[stoi(userChoice) - 1]);
        
    } else if (actionName == "Special") {
        cout << "Throw fireball to : ";
        for (int i = 1; i <= monsters.size(); i++) {
            string msg = (i == monsters.size()) ? " ? " : ", ";
            cout << to_string(i) << ") " << monsters[i - 1]->toString() << msg;
        }
        cin >> userChoice;
        this->fireball(*monsters[stoi(userChoice) - 1]);

    } else {
        cout << "Action haven't been recognized, select one between Attack, Special, Potion : ";
        cin >> actionName;
        this->playRound(characters, nbrAllies, actionName);
    }
}

string Mage::getSpecialActionName() {
    return "Fireball";
}
