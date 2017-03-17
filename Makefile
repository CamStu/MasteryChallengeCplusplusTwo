cardgames: deck.o CardGames.o Go_fish.o main.o Poker.o
	g++ deck.o CardGames.o Go_fish.o main.o Poker.o -o games
deck.o: deck.cpp
	g++ deck.cpp -c
CardGames.o: CardGames.cpp
	g++ CardGames.cpp -c
Go_fish.o: Go_fish.cpp
	g++ Go_fish.cpp -c
main.o: main.cpp
	g++ main.cpp -c
Poker.o: Poker.cpp
	g++ Poker.cpp -c
clean:
	rm -f *.out *.o cardgames
