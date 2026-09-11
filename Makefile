sheep:
	g++ -g sheeps.cpp $$(pkg-config --libs --cflags raylib) -o sheeps

clean:
	rm -f sheeps
