//
//  Screen.cpp
//  ParticleExplosion
//
//  Created by Nian Xu Wang on 6/15/18.
//  Copyright © 2018 Nian Xu Wang. All rights reserved.
//

#include "Screen.h"

namespace nian {
    
    Screen::Screen() : mWindow(NULL), mRenderer(NULL), mTexture(NULL), mBuffer1(NULL), mBuffer2(NULL)
    {
    }
    
    bool Screen::init() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            return false;
        }
        
        mWindow = SDL_CreateWindow("Particle Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (mWindow == NULL) { //if failed to create window
            SDL_Quit();
            return false;
        }
        
        mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_PRESENTVSYNC);
        if (mRenderer == NULL) {
            SDL_DestroyWindow(mWindow);
            SDL_Quit();
            return false;
        }
        mTexture = SDL_CreateTexture(mRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT); //SDL_PIXELFORMAT_RGBA8888 means 1 byte per Red, Green, Blue, Alpha, so 0 to 255 for each
        if (mTexture == NULL) {
            SDL_DestroyRenderer(mRenderer);
            SDL_DestroyWindow(mWindow);
            SDL_Quit();
            return false;
        }
        

        mBuffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]; //for different systems, c++ int may not be 32 bits
        //each RGBA is 1 byte (8 bits) each, so each Uint32 (32 bits) pixel stores one set of RGBA info. We need 800*600 of these buffers as thats how many pixels in the screen. This buffer is essentially a really long array storing row after row of pixel data together.
        mBuffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
        
        //Set the memory located at buffer ptr to black 0 to clear buffer, for all the width*height*4 (entire screen).
        //max possible is 255 (or 0xFF), as it's allocated as Uint32), which is white.
        memset(mBuffer1, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
        memset(mBuffer2, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
        
        return true;
    }
    
    void Screen::update() {
        SDL_UpdateTexture(mTexture, NULL, mBuffer1, SCREEN_WIDTH * sizeof(Uint32)); //pitch (last argument) is size of 1 row of pixels
        SDL_RenderClear(mRenderer);
        SDL_RenderCopy(mRenderer, mTexture, NULL, NULL);
        SDL_RenderPresent(mRenderer);
    }
    
    /** Set pixel at (x, y) on the screen to a color */
    void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
        if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
            return; //only plot pixel if within the screen
        }
        
        Uint32 color = 0; //4 * 8 bits, in format of RRGGBBAA in hex
        
        color += red;
        color <<= 8; //bitshift left 8 bits
        color += green;
        color <<= 8;
        color += blue;
        color <<= 8;
        color += 0xFF; //FF is opaque for Alpha
        
        mBuffer1[(y * SCREEN_WIDTH) + x] = color;
        //each row is SCREEN_WIDTH pixels long, times y to go down the right number of rows, + x to move the right number of columns
    }
    
    bool Screen::processEvents() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) { //if user clicks red close button
                return false;
            }
        }
        return true;
    }
    
    void Screen::boxBlur() {
        //Swap buffers. Pixel info is in b2, draw b1
        Uint32* temp = mBuffer1;
        mBuffer1 = mBuffer2;
        mBuffer2 = temp;
        
        for (int y = 0; y < SCREEN_HEIGHT; y++) { //for each pixel, do the blurring by sampling the pixels around it
            for (int x = 0; x < SCREEN_WIDTH; x++) {
                /* get pixels around P and average
                 0 0 0
                 0 P 0
                 0 0 0
                 */
                int totalRed = 0;
                int totalGreen = 0;
                int totalBlue = 0;
                
                for (int row = -1; row <= 1; row++) {
                    for (int col = -1; col <= 1; col++) {
                        int currX = x + col; //start from top left corner for x and y
                        int currY = y + row;
                        
                        if (currX >= 0 && currX < SCREEN_WIDTH && currY >= 0 && currY < SCREEN_HEIGHT) {
                            //if statement so don't go over the edge of the screen
                            Uint32 color = mBuffer2[currY * SCREEN_WIDTH + currX]; //get to the correct index in this buffer array
                            Uint8 red = color >> 24; //extract the RGB values using bitshift from that pixel
                            Uint8 green = color >> 16;
                            Uint8 blue = color >> 8;
                            
                            totalRed += red; //add each red to the totalRed for pixel P
                            totalGreen += green;
                            totalBlue += blue;
                        }
                    }
                }
                
                Uint8 red = totalRed/9; //average the red out for the pixel P
                Uint8 green = totalGreen/9;
                Uint8 blue = totalBlue/9;
                
                setPixel(x, y, red, green, blue);
            }
        }
    }
    
    void Screen::close() {
        delete [] mBuffer1;
        delete [] mBuffer2;
        SDL_DestroyTexture(mTexture);
        SDL_DestroyRenderer(mRenderer);
        SDL_DestroyWindow(mWindow);
        SDL_Quit();
    }
}
