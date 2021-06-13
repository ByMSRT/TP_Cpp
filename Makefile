rpg : main.o Character.o Mage.o Priest.o Monster.o Barbarian.o Exceptions.o Potion.o
	g++ main.o Character.o Mage.o Priest.o Monster.o Barbarian.o Exceptions.o Potion.o -o rpg --std=c++11

main.o : main.cpp
	g++ -c main.cpp -o main.o --std=c++11

Character.o : cpp/Character.cpp hpp/Character.hpp
	g++ -c cpp/Character.cpp -o Character.o --std=c++11

Mage.o : cpp/Mage.cpp hpp/Mage.hpp
	g++ -c cpp/Mage.cpp -o Mage.o --std=c++11

Priest.o : cpp/Priest.cpp hpp/Priest.hpp
	g++ -c cpp/Priest.cpp -o Priest.o --std=c++11

Monster.o : cpp/Monster.cpp hpp/Monster.hpp
	g++ -c cpp/Monster.cpp -o Monster.o --std=c++11

Barbarian.o : cpp/Barbarian.cpp hpp/Barbarian.hpp
	g++ -c cpp/Barbarian.cpp -o Barbarian.o --std=c++11

Exceptions.o : cpp/Exceptions.cpp hpp/Exceptions.hpp
	g++ -c cpp/Exceptions.cpp -o Exceptions.o --std=c++11

Potion.o : cpp/Potion.cpp hpp/Potion.hpp
	g++ -c cpp/Potion.cpp -o Potion.o --std=c++11

clean : 
	rm *.o
