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
        mDirection = (2 * M_PI * rand())/RAND_MAX; //double division
        mSpeed = (0.05 * rand())/RAND_MAX;
        
        mSpeed *= mSpeed; //square the speed
    }

    Particle::~Particle() {
        
    }
    
    void Particle::update(int deltaTime) {
        mDirection += deltaTime * 0.001;
        
        double xSpeed = mSpeed * cos(mDirection);
        double ySpeed = mSpeed * sin(mDirection);
        
        mX += xSpeed * deltaTime;
        mY += ySpeed * deltaTime;
    }
    
}
