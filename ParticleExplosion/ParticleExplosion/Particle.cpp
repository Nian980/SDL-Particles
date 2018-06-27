//
//  Particle.cpp
//  ParticleExplosion
//
//  Created by Nian Xu Wang on 6/26/18.
//  Copyright © 2018 Nian Xu Wang. All rights reserved.
//

#include "Particle.h"
#include <cmath>

namespace nian {
    
    Particle::Particle() : mX(0), mY(0) {
        /* old stuff
        //create particles in a 1 by 1 space, then mapping to the screen
        //rand() gives number between 0 and RAND_MAX, so /RAND_MAX gives 0 to 1, *2.0 gives 0 to 2.0, -1 gives -1 to 1
        mX = (2.0 * rand())/RAND_MAX - 1;
        mY = (2.0 * rand())/RAND_MAX - 1;
        xSpeed = 0.001 * ((2.0 * rand())/RAND_MAX - 1); //get a double value -1 to 1
        ySpeed = 0.001 * ((2.0 * rand())/RAND_MAX - 1);
        */
        
        mDirection = (double)rand()/RAND_MAX;
    }

    Particle::~Particle() {
        
    }
    
    void Particle::update() {
        /* Old stuff.
        mX += xSpeed;
        mY += ySpeed;
        if (mX < -1.0 || mX > 1.0) {
            xSpeed *= -1; //flip speed if going outside of space
        }
        if (mY < -1.0 || mY > 1.0) {
            ySpeed *= -1; //flip speed if going outside of space
        }
         */
    }
}
