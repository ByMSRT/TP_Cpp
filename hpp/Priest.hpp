#ifndef PRIEST.HPP
#define PRIEST.HPP
#include "./Character.hpp"
#include <string>
#include "./Exceptions.hpp"

using namespace std;


class Priest : public Character {
    private:
    int mp;
    int maxMp;
    bool tryUsingMp(int mp);

    public:
    Priest(string name) : Character(name,Job::PriestJob,20,250,20,1000), mp(100), maxMp(100){}
    void healOther(Character& other);
};

#endif