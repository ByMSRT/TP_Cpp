#ifndef PRIEST.HPP
#define PRIEST.HPP
#include "./Character.hpp"
#include <string>
#include "./Exceptions.hpp"

using namespace std;


class Priest : public Character {
    private:
    int mp;
    int magicalAttack;
    bool healOther(int mp);

    public:
    Priest(string name) : Character(name,Job::PriestJob,20,250,20,1000), mp(100){}
    void fireball(Character& other);
};

#endif