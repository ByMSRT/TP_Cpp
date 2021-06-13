#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "./Character.hpp"
#include <string>
#include "./Exceptions.hpp"

using namespace std;

class Barbarian : public Character {
    private:
    int baseAttack;
    int baseDefense;
    bool inFury;
    int furyCharges;

    public:
    Barbarian(string name);
    void enterFury();
    void leaveFury();
    void decrementFuryCharges();

    void playRound(vector<Character*>& characters, int nbrAllies, string actionName) override;
    void launchSpecialAction() override;
    string getSpecialActionName() override;
};


#endif