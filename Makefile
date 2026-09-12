opponents:
	g++ -g opponents.cpp $$(pkg-config --libs --cflags raylib) -o opponents

sheep:
	g++ -g sheeps.cpp $$(pkg-config --libs --cflags raylib) -o sheeps

clean:
	rm -f opponents
