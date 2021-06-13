# Cpp TP Projet RPG en C++

![img](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)

## Groupe : Nathan, Nicolas, Nathy, Elouan

# 🔵 Principe du projet 

Le but de ce TP est de faire de notre base de RPG un petit jeu qui permette de dérouler un combat de n personnages contre n monstres, nous devons rajouter une classe prètre et une classe monstre puis ajouter une notion de vitesse de jeu pour déterminer l'ordre des tours. Enfin, on doit créer une interface en ligne de commande pour choisir les actions des personnages et consulter leur statut.

## 🟠 Fonctionnement

Nous utilisons le `makefile` qui est un fichier regroupant un ensemble de commandes permettant d'exécuter un ensemble d'actions, comme la compilation d'un projet.

Le makefile se compose de : 

- D'une cible,
- D'une ou plusieurs dépendances,
- D'une ou plusieurs commandes.


## 🟠 Exemple de commande dans le fichier

Voici un exemple de commande située dans le `makefile` : 


`rpg : main.o Character.o Mage.o Barbarian.o Exceptions.o Potion.o
	g++ main.o Character.o Mage.o Barbarian.o Exceptions.o Potion.o -o rpg --std=c++11`

### 💻 Lancement de la compilation

Pour lancer la compilation, on utilisera la commande suivante : `make`.

### 🕹 Lancement du programme

Pour lancer le programme, on utilisera la commande suivante : `./rpg`.

## 🟠 Axes d'améliorations

- Pas prendre en compte le tableau trié en fonction de la vitesse lors d'un combat avec plsusieurs membres dans une seule équipe.

- Ne pas prendre en compte les personnages qui n'ont plus d'HP


