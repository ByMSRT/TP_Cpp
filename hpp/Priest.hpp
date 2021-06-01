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
    Priest(string name);
    void healOther(Character& other);
    void launchSpecialAction(Character& c) override;
    string getSpecialActionName() override;
};

#endif