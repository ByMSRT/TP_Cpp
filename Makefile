rpg : main.o Character.o Mage.o Barbarian.o Exceptions.o Potion.o
	g++ main.o Character.o Mage.o Barbarian.o Exceptions.o Potion.o -o rpg

main.o : main.cpp
	g++ -c main.cpp -o main.o

Character.o : cpp/Character.cpp hpp/Character.hpp
	g++ -c cpp/Character.cpp -o Character.o

Mage.o : cpp/Mage.cpp hpp/Mage.hpp
	g++ -c cpp/Mage.cpp -o Mage.o

Barbarian.o : cpp/Barbarian.cpp hpp/Barbarian.hpp
	g++ -c cpp/Barbarian.cpp -o Barbarian.o

Exceptions.o : cpp/Exceptions.cpp hpp/Exceptions.hpp
	g++ -c cpp/Exceptions.cpp -o Exceptions.o

Potion.o : cpp/Potion.cpp hpp/Potion.hpp
	g++ -c cpp/Potion.cpp -o Potion.o

clean : 
	rm *.o