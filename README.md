# Cpp TP Projet RPG en C++

![img](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)

## Groupe : Nathan, Nicolas, Nathy, Elouan

---

# 🔵 Fonctionnement

Nous utilisons le `makefile` qui est un fichier regroupant un ensemble de commandes permettant d'exécuter un ensemble d'actions, comme la compilation d'un projet.

Le makefile se compose de : 

- D'une cible
- D'une ou plusieurs dépendances
- D'une ou plusieurs commandes.


## 🟠 Exemple de commande dans le fichier

Voici un exemple de commande situé dans le `makefile` : 
`rpg : main.o Character.o Mage.o Barbarian.o Exceptions.o Potion.o
	g++ main.o Character.o Mage.o Barbarian.o Exceptions.o Potion.o -o rpg --std=c++11`

### 💻 Lancement de la compilation

Pour lancer la compilation, on utilisera la commande suivante : `make`.

### 🕹 Lancement du programme

Pour lancer le programme, on utilisera la commande suivante : `./rpg`.
