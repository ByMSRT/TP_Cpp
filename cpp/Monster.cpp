#include "../hpp/Monster.hpp"

void Monster::simpleAtt(){
    Character* randomAlly = allies[rand() % allies.size()];
    this->attack(*randomAlly);
}

void Monster::groupAtt(){
    cout << "Zone attack : ";
    int tampon = this->physicalAttack;
    this->physicalAttack = this->physicalAttack / allies.size();
    for(Character* ally : allies){
        this->attack(*ally);
    }
    this->physicalAttack = tampon;
}

void Monster::upDef(){
    Character* randomMonster = monsters[rand() % monsters.size()];
    randomMonster->shield(20);
    cout << this->toString() << " enhance " << randomMonster->toString() << "'s defense." << endl;
}

void Monster::action(vector<Character*> allies, vector<Character*> monsters){
    this->allies = allies;
    this->monsters = monsters;

    selectAction = rand() % 3;

    if(selectAction == 0){
        simpleAtt();
    } else if (selectAction == 1){
        groupAtt();
    } else {
        upDef();
    }
    
}

void Monster::playRound(vector<Character*>& characters, int nbrAllies) {
    vector<Character*> allies(characters.begin(), characters.begin() + nbrAllies + 1);
    vector<Character*> monsters(characters.begin() + nbrAllies + 1, characters.end());
    // cout << "allies : ";
    // for (Character* character : allies) {
    //     cout << character->name << endl;
    // }
    // cout << "monsters : ";
    // for (Character* character : monsters) {
    //     cout << character->name << endl;
    // }
    this->action(allies, monsters);
}

string Monster::getSpecialActionName() {
    return "Monster attack or enhance other monster defense";
}