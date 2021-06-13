#ifndef MONSTER_HPP
#define MONSTER_HPP
#include "./Character.hpp"
#include <string>
#include <cstdlib>
#include <vector>

using namespace std;

class Monster : public Character {
    private:
    vector<Character*> allies;
    vector<Character*> monsters;
    int selectAction;
    void simpleAtt();
    void groupAtt();
    void upDef();

    public:
    Monster(string name) : Character(name,Job::MonsterJob,200,100,40,1000){}

    void playRound(vector<Character*>& characters, int nbrAllies) override;

    string getSpecialActionName() override;
    void action(vector<Character*> monsters, vector<Character*> allies);
};


#endif