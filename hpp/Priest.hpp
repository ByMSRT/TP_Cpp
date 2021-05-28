#ifndef PRIEST.HPP
#define PRIEST.HPP
#include "./Character.hpp"
#include <string>
#include "./Exceptions.hpp"

using namespace std;


class Priest : public Character {
    private:
    

    public:
    Priest(string name) : Character(name,Job::PriestJob,15,200,30,1000){}
    void healOther(Character& other);
};

#endif