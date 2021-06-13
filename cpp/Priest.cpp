#include "../hpp/Priest.hpp"
#include "../hpp/Character.hpp"

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
    cout << this->toString() << " heals " << other.toString() << endl;
    
}

void Priest::playRound(vector<Character*>& characters, int nbrAllies, string actionName) {
    vector<Character*> allies(characters.begin(), characters.begin() + nbrAllies + 1);
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
        cout << "Heal : ";
        for (int i = 1; i <= allies.size(); i++) {
            string msg = (i == allies.size()) ? " ? " : ", ";
            cout << to_string(i) << ") " << allies[i - 1]->toString() << msg;
        }
        cin >> userChoice;
        this->healOther(*allies[stoi(userChoice) - 1]);

    } else {
        cout << "Action haven't been recognized, select one between Attack, Special, Potion : ";
        cin >> actionName;
        this->playRound(characters, nbrAllies, actionName);
    }
}

void Priest::launchSpecialAction(Character& c) {
    this->healOther(c);
}

string Priest::getSpecialActionName() {
    return "Heal ally";
}