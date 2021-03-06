#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "./Potion.hpp"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

enum Job {
    FreelancerJob,
    MageJob,
    WarriorJob,
    BarbarianJob,
    DruidJob,
    PriestJob,
    PaladinJob,
    MonsterJob,
};

class Character
{

    public:
    string name;

    protected:
    int physicalAttack;
    int magicAttack;
    int defense;
    int maxHp;
    int hp;
    int quickness;

    private:
    Job job;

    public:
    Character() : Character("John Doe",FreelancerJob,100,100,50,1000){}

    Character(string name, Job job);

    Character(string name, Job job, int pAtt, int mAtt, int def, int maxHp);

    void heal(unsigned int healingValue);

    void shield(unsigned int shieldValue);

    void drink(Potion& p);

    Character& operator+=(Potion& p);

    void attack(Character& defender);

    void receiveDamage(int damage);

    virtual void launchSpecialAction();
    virtual void launchSpecialAction(Character& c);
    
    virtual void playRound(vector<Character*>& characters, int nbrAllies);
    virtual void playRound(vector<Character*>& characters, int nbrAllies, string actionName);

    static bool sortByQuickness(const Character* c1, const Character* c2) {
        return c1->quickness > c2->quickness;
    }

    int getCurrentHp();
    int getMaxHp();
    Job getJob();
    virtual string getSpecialActionName();

    string toString();
};

#endif