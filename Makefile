

all:
	g++ -I ./include ./src/*.cpp -I /Library/Frameworks/SDL2.framework/headers -F/Library/Frameworks/ -framework SDL2 -o ./bin/out