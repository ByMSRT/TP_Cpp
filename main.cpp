#include <cstdlib>
#include <ctime>
#include <iostream>
#include "hpp/Character.hpp"
#include "hpp/Barbarian.hpp"
#include "hpp/Mage.hpp"
#include "hpp/Potion.hpp"
#include "hpp/Exceptions.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    try {
        srand(time(NULL));
        Mage gandalf("Gandalf");
        Barbarian conan("Conan");
        conan.enterFury();
        conan.attack(gandalf);

        conan.attack(gandalf);
        cout << "Gandalf a " << gandalf.getCurrentHp() << " PV" << endl;
        conan.enterFury();

        Potion small(3,100);
    
        gandalf += small;
        gandalf += small;
        gandalf += small;
        gandalf += small;
        cout << "All potions were drunk !" << endl;
    }
    catch(IllegalFury& illegalF){
        cout << "An illegal barbarian fury operation occured : " << illegalF.what() << endl;
    }
    catch(EmptyPotion& ep){
        cout << "An illegal barbarian fury operation occured : " << ep.what() << endl;
    }
    catch(exception& e){
        cout << "An exception occured : " << e.what() << endl;
    }

    cout << "Fight finished" << endl;

    return 0;
}