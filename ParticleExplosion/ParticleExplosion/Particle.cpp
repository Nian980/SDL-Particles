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
        init();
    }

    Particle::~Particle() {
        
    }
    
    void Particle::init() {
        mDirection = (2 * M_PI * rand())/RAND_MAX; //double division
        mSpeed = (0.05 * rand())/RAND_MAX;
        
        mSpeed *= mSpeed; //square the speed
    }
    
    void Particle::update(int deltaTime) {
        mDirection += deltaTime * 0.0005; //slowly curve the direction
        
        double xSpeed = mSpeed * cos(mDirection);
        double ySpeed = mSpeed * sin(mDirection);
        
        mX += xSpeed * deltaTime;
        mY += ySpeed * deltaTime;
        
        //stop particle going outside of the -1 to 1 space, instead reinitialises to center of screen
        if (mX < -1 || mX > 1 || mY < -1 || mY > 1) {
            init();
        }
        
//        //add more randomness, 1/100 chance. Looks bad actually
//        if (rand() < RAND_MAX/100) {
//            init();
//        }
        
    }
    
}
