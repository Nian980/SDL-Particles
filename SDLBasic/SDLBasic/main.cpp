//
//  main.cpp
//  SDLBasic
//
//  Created by Nian Xu Wang on 6/14/18.
//  Copyright © 2018 Nian Xu Wang. All rights reserved.
//
#include <SDL2/SDL.h>
#include <iostream>
#include <stdio.h> //for printf

int main(int argc, const char * argv[]) {
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL Init failed" << std::endl;
        return 1;
    }
    std::cout << "SDL Init success" << std::endl;
    
    SDL_Window* window = SDL_CreateWindow("Particle Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) { //if failed to create window
        SDL_Quit();
        printf("Could not create window: %s \n", SDL_GetError());
        return 1;
    }
    
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) { //careful, capital SDL_QUIT
                SDL_Log("User just clicked close on the window!");
                quit = true;
            }
        }
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
