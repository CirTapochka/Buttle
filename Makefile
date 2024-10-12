all: buttle_shipp

buttle_shipp: main.o segment.o ship.o manager.o gameboard.o
	g++ main.o segment.o ship.o manager.o gameboard.o -o buttle_shipp

main.o: main.cpp manager.h gameboard.h
	g++ -c main.cpp

segment.o: segment.cpp segment.h
	g++ -c segment.cpp

ship.o: ship.cpp ship.h segment.h
	g++ -c ship.cpp

manager.o: manager.cpp manager.h ship.h
	g++ -c manager.cpp

gameboard.o: gameboard.cpp gameboard.h 
	g++ -c gameboard.cpp


clean: 
	rm *.o buttle_shipp