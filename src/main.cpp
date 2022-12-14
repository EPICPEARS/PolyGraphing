#include <main.hpp>

void setup_axis(SDL_Renderer *rend){
    SDL_SetRenderDrawColor(rend, 255, 255, 255, 100);
    SDL_RenderDrawLine(rend, 300, 0, 300, 480);
    SDL_RenderDrawLine(rend, 0, 200, 640, 200);
    SDL_SetRenderDrawColor(rend, 0, 0, 0, 100);
    SDL_RenderPresent(rend);
}

void event_handling(SDL_Event e, SDL_bool *quit){

    while (SDL_PollEvent(&e) != 0){
            if (e.type == SDL_QUIT)
            {
            *quit = SDL_TRUE;
            }
            switch (e.type)
            {
                case SDL_KEYDOWN:
                    *quit = SDL_TRUE;
                    break;
                
                default:
                    break;
            }
        }

}

int main(int argc, char *argv[]){

    if (argc <= 2){
        return 1;
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    PolyNomialSolver psolve(argc, argv);
    SDL_bool quit = SDL_FALSE;


    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_Log("failed to init: %s", SDL_GetError());
        return -1;
    }

    window = SDL_CreateWindow("Hello", 0, 0, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);


    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    if (renderer == NULL){
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        return -1;
    }

    while (!quit){
        SDL_Event e;

        SDL_RenderClear(renderer);
        psolve.GetPoints(renderer);
        setup_axis(renderer);

        event_handling(e, &quit);
 
    }

    SDL_Quit();
    return 1;

}