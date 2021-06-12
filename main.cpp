#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <functional>
#include "hpp/Character.hpp"
#include "hpp/Barbarian.hpp"
#include "hpp/Mage.hpp"
#include "hpp/Potion.hpp"
#include "hpp/Exceptions.hpp"
#include "hpp/Priest.hpp"
#include "hpp/Monster.hpp"



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
    try {
        
        string nameMC(""); // -> string nameMC = "";
        int index;
        string classMC(""); 
        vector<Character*> characters;
        vector<string> classes;
        
        cout << "De un nom au reuf : ";
        cin >> nameMC ;
        cout << endl << " choisi ta classe ( classe dispo ffffffff) : ";
        cin >> classMC ;

        for ( int i = 0 ; i<classes.size(); i++){
            if (classes[i] == classMC){
                index = i;
            }
        }
        switch (index)
        {
        case 0:
        {
            Barbarian barbarian(nameMC);
            characters.push_back(new Barbarian(barbarian));
            break;
        }
        case 1: 
        {
            Mage mage(nameMC);
            characters.push_back(new Mage(mage));
            break;
        }
        case 2:
        {
            Priest priest(nameMC);
            characters.push_back(new Priest(priest));
            break;
        }
        } 
        for (int i = 0; i < characters.size(); i++){
            cout << characters[i]->getSpecialActionName() << endl;
        }

    }

    catch(exception& e){
        cout << "An exception occured : " << e.what() << endl;
    }
    



    cout << "Fight finished" << endl;

    return 0;
}

