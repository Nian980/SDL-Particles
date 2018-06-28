//
//  Screen.h
//  ParticleExplosion
//
//  Created by Nian Xu Wang on 6/15/18.
//  Copyright © 2018 Nian Xu Wang. All rights reserved.
//

#ifndef SCREEH_H
#define SCREEH_H

#include <iostream>
#include <stdio.h> //for printf
#include <SDL2/SDL.h>

namespace nian {

class Screen {
public:
    static const int SCREEN_WIDTH = 800; //public cuz we might need it outside of class
    static const int SCREEN_HEIGHT = 600; //static cuz same for all screen objects
    
private:
    //Convention: use m to indicate they are instance/member variables not local variables
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    SDL_Texture* mTexture;
    Uint32* mBuffer1;
    Uint32* mBuffer2;
    
public:
    Screen(); //default constructor
    bool init(); //success or fail initialization
    void update();
    void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue); //unsigned 8bit int is basically a char
    bool processEvents();
    void boxBlur();
    void close(); //close down stuff we openend
};

}

#endif /* Screen_h */
