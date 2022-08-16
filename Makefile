SDL_INCLUDE = /Library/Frameworks/SDL2.framework/headers
FRAMEWORK = /Library/Frameworks/
FRAMEWORK_NAME = SDL2
OUT_DIR = ./bin/out
INCLUDE = ./include
SRC = ./src/*.cpp

all:
	g++ $(SRC) -I $(INCLUDE) -I $(SDL_INCLUDE) -F$(FRAMEWORK) -framework $(FRAMEWORK_NAME)  -o $(OUT_DIR)