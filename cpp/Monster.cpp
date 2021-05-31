#include "../hpp/Monster.hpp"

void Monster::simpleAtt(){
    Character& randomEnemy = enemies[rand() % enemies.size()];
    this->attack(randomEnemy);
}

void Monster::groupAtt(){
    int tampon = this->physicalAttack;
    this->physicalAttack = this->physicalAttack / enemies.size();
    for(Character& enemy : enemies){
        this->attack(enemy);
    }
    this->physicalAttack = tampon;
}

void Monster::upDef(){
    Character& randomAlly = allies[rand() % allies.size()];
    randomAlly.shield(20);
}

void Monster::action(vector<Character&> enemies, vector<Character&> allies){
    this->enemies = enemies;
    this->allies = allies;

    selectAction = rand() % 3;

    if(selectAction == 0){
        simpleAtt();
    } else if (selectAction == 1){
        groupAtt();
    } else {
        upDef();
    }
    
}