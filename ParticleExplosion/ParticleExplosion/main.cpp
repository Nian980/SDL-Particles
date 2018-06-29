//
//  main.cpp
//  ParticleExplosion
//
//  Created by Nian Xu Wang on 6/14/18.
//  Copyright © 2018 Nian Xu Wang. All rights reserved.
//

#include "Screen.h"
#include "Swarm.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace nian; //so don't have to use e.g. nian::Screen

int main(int argc, const char * argv[]) {
    
    srand(time(NULL));
    
    Screen screen;
    if (screen.init() == false) {
        std::cout << "Error initialising SDL" << std::endl;
    }
    
    Swarm swarm;
    
    while (true) {
        //Update and Draw particles
        int elapsedTicks = SDL_GetTicks(); //returns number of milliseconds since the program has started
        
        swarm.update(elapsedTicks);
        
        unsigned char red = (1 + cos(elapsedTicks * 0.001)) * 127.5;
        unsigned char green = (1 + sin(elapsedTicks * 0.002)) * 127.5; //turn double into unsigned char
        unsigned char blue = (1 + cos(elapsedTicks * 0.003)) * 127.5;
        // *0.001 cuz the sin value jumps a lot. 1+ turns it to 0 to 2. *127.5 so you get between 0 and 255 ish
        
        const Particle* const pParticles = swarm.getParticles();
        
        for (int i = 0; i < Swarm::NPARTICLES; i++) {
            Particle particle = pParticles[i]; //get individual particles one by one
            
            //map each particle from 1 by 1 grid to screen space.
            //+1 to make it 0 to 2. Then multiply by half screen width to map to the screen.
            int x = (particle.mX + 1) * Screen::SCREEN_WIDTH/2; //x position of this particle.
            int y = particle.mY * Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2; //centers y
            
            screen.setPixel(x, y, red, green, blue);
        }
        
        screen.boxBlur();
        
        //Draw the screen
        screen.update();
        
        //Check for messages/events (process events)
        if (!screen.processEvents()) {
            break;
        }
    }
    
    screen.close();
    
    return 0;
}
