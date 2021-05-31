#ifndef MONSTER_HPP
#define MONSTER_HPP
#include "./Character.hpp"
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

class Monster : public Character {
    private:
    vector<Character&> enemies;
    vector<Character&> allies;
    int selectAction;
    void simpleAtt();
    void groupAtt();
    void upDef();

    public:
    Monster(string name) : Character(name,Job::MonsterJob,200,100,50,1000){}
    void action(vector<Character&> enemies, vector<Character&> allies);
};


#endif