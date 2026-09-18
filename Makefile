sheep2:
	g++ -g sheep2.cpp $$(pkg-config --libs --cflags raylib) -o sheep2

sheep1:
	g++ -g sheep1.cpp $$(pkg-config --libs --cflags raylib) -o sheep1

clean:
	rm -f sheep2
