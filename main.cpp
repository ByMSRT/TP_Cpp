#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include "hpp/Character.hpp"
#include "hpp/Barbarian.hpp"
#include "hpp/Mage.hpp"
#include "hpp/Priest.hpp"
#include "hpp/Monster.hpp"
#include "hpp/Potion.hpp"
#include "hpp/Exceptions.hpp"

using namespace std;

vector<string> classes = {"Barbarian", "Mage", "Priest", "Monster"};
vector<string> allyNames {"Elouan", "Nico", "Nathy", "Nathan", "Julien", "Cédric", "Sebiche", "Thib"};
vector<string> monsterNames {"Wolf", "Vampire", "Zombie", "Dragon", "Dino", "Ghoul"};
// vector<string> randomNames; // https://www.fantasynamegenerators.com/ with libcurl lib

// Fonction de création d'un nouveau personnage
void createCharacter(vector<Character*>& characters, string name, string job) {
    int index = -1;
    
    for (int i = 0; i < classes.size(); i++) {
        if (classes[i] == job) {
            index = i;
        }
    }
    switch(index) {
        case 0:
        {
            characters.push_back(new Barbarian(name));
            break;
        }
        case 1:
        {
            characters.push_back(new Mage(name));
            break;
        }
        case 2:
        {
            characters.push_back(new Priest(name));
            break;
        }
        case 3:
        {
            characters.push_back(new Monster(name));
            break;
        }
        default:
            throw UnknownJob();
            break;
    }
}

// Fonction de création des personnages d'une même équipe (alliés ou monstres pour l'instant)
void createTeam(vector<Character*>& characters, int nbrMembers, string teamName) {
    vector<string> teamMemberNames = {};
    vector<string> teamClasses = classes;
    string msg("");
    if (teamName == "allies") {
        teamMemberNames = allyNames;
        teamClasses.pop_back();
        msg = nbrMembers == 1 ? "ally" : "allies";
    } else if (teamName == "monsters") {
        teamMemberNames = monsterNames;
        teamClasses = {"Monster"};
        msg = nbrMembers == 1 ? "monster" : "monsters";
    }

    for (int i = 0; i < nbrMembers; i++) {
        createCharacter(characters, teamMemberNames[rand() % teamMemberNames.size()], teamClasses[rand() % teamClasses.size()]);
    }
    cout << to_string(nbrMembers) << " new " << msg << " just enter the fight !" << endl;
}

// Fonction d'affichage de tous les personnages
void displayCharacters(vector<Character*>& characters) {
    for (int i = 0; i < characters.size(); i++) {
        cout << characters[i]->toString() << " [ " << to_string(characters[i]->getCurrentHp()) << "/" << characters[i]->getMaxHp() << "HP ] | ";
    }
    cout << endl;
}

// Fonction déternimant l'état actuel du combat (fini -> true, pas fini -> false)
bool isFightFinished(vector<Character*>& characters, int nbrAllies) {
    vector<Character*> allies(characters.begin(), characters.begin() + nbrAllies + 1);
    vector<Character*> monsters(characters.begin() + nbrAllies + 1, characters.end());
    int hpsAllies = 0;
    int hpsMonsters = 0;
    for(int i = 0; i < allies.size(); i++) {
        hpsAllies += allies[i]->getCurrentHp();
    }
    for(int i = 0; i < monsters.size(); i++) {
        hpsMonsters += monsters[i]->getCurrentHp();
    }
    return hpsAllies == 0 || hpsMonsters == 0;
}

int main(int argc, char const *argv[])
{
    // catch(IllegalFury& illegalF){
    //     cout << "An illegal barbarian fury operation occured : " << illegalF.what() << endl;
    // }
    // catch(EmptyPotion& ep){
    //     cout << "An illegal barbarian fury operation occured : " << ep.what() << endl;
    // }
    // catch(exception& e){
    //     cout << "An exception occured : " << e.what() << endl;
    // }
    Potion small(3,100);

    try {
        srand(time(NULL));

        vector<Character*> characters;
        int nbrAllies = 0;
        int rounds = 1;

        cout << "--- Welcome to Sos10RPG ! ---" << endl << endl;

        // Création du personnage principal
        cout << "Main character's creation, please fill fields downside" << endl;
        cout << "   Name                            : ";
        string nameMC = ""; cin >> nameMC;
        cout << "   Class (Barbarian, Mage, Priest) : ";
        string classMC = ""; cin >> classMC;
        cout << endl;
        createCharacter(characters, nameMC, classMC);

        // Création des alliés
        cout << "Hi " << characters[0]->toString() << " ! Do you want some allies ?" << endl;
        string alliesAnswer(""); cin >> alliesAnswer; transform(alliesAnswer.begin(), alliesAnswer.end(), alliesAnswer.begin(), ::tolower);
        if (alliesAnswer == "yes" || alliesAnswer == "y" || alliesAnswer == "oui") {
            cout << "How many allies do you want to fight with ?" << endl;
            cin >> nbrAllies;
            createTeam(characters, nbrAllies, "allies"); // Création des alliés
        } else {
            cout << "Let's have a 1v1 fight !" << endl;
        }

        // Création des monstres
        nbrAllies++;
        createTeam(characters, nbrAllies, "monsters");
        nbrAllies--;
        cout << endl;

        sort(characters.begin(), characters.end(), Character::sortByQuickness); // Tri des personnages en fonction de leur vitesse

        // Lancement du combat
        while(!isFightFinished(characters, nbrAllies)) {
            string actionName("");

            cout << endl << "> ROUND " << rounds << " <" << endl;

            for(int i = 0; i < characters.size(); i++) {
                
                if (characters[i]->getJob() == MonsterJob) {
                    characters[i]->playRound(characters, nbrAllies);
                } else {

                    cout << characters[i]->toString() << "'s round : Action (Attack, Special, Potion) : ";
                    cin >> actionName;
                    if (actionName == "Potion") {
                        characters[i]->heal(small.getHealedHp());
                    } else {
                        characters[i]->playRound(characters, nbrAllies, actionName);
                    }
                    
                }
            }

            cout << endl << "Characters : " << endl;
            displayCharacters(characters);

            rounds++;
        }

        cout << "--- Fight finished ---" << endl;

    } catch(exception& e) {
        cout << "ERROR : " << e.what() << endl;
    }

    return 0;
}