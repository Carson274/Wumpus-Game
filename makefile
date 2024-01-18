CC=g++ -std=c++11 -lncurses -g
exe_file = run

all: $(exe_file)

$(exe_file): bats.o cave.o event.o game.o gold.o main.o room.o stalactites.o wumpus.o adventurer.o armor.o ladder.o passage.o
	$(CC) bats.o cave.o event.o game.o gold.o main.o room.o stalactites.o wumpus.o adventurer.o armor.o ladder.o passage.o -o $(exe_file)

bats.o: bats.cpp bats.h
	$(CC) -c bats.cpp

cave.o: cave.cpp cave.h
	$(CC) -c cave.cpp

event.o: event.cpp event.h
	$(CC) -c event.cpp

game.o: game.cpp game.h
	$(CC) -c game.cpp

gold.o: gold.cpp gold.h
	$(CC) -c gold.cpp

room.o: room.cpp room.h
	$(CC) -c room.cpp

stalactites.o: stalactites.cpp stalactites.h
	$(CC) -c stalactites.cpp

wumpus.o: wumpus.cpp wumpus.h
	$(CC) -c wumpus.cpp

adventurer.o: adventurer.cpp adventurer.h
	$(CC) -c adventurer.cpp

armor.o: armor.cpp armor.h
	$(CC) -c armor.cpp

ladder.o: ladder.cpp ladder.h
	$(CC) -c ladder.cpp

passage.o: passage.cpp passage.h
	$(CC) -c passage.cpp

clean:
	rm -f *.o $(exe_file)