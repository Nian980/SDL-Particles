//
//  Swarm.cpp
//  ParticleExplosion
//
//  Created by Nian Xu Wang on 6/26/18.
//  Copyright © 2018 Nian Xu Wang. All rights reserved.
//

#include "Swarm.h"

namespace nian {
    Swarm::Swarm() : prevElapsed(0) {
        mParticles = new Particle[NPARTICLES];
    }
    
    Swarm::~Swarm() {
        delete [] mParticles;
    }
    
    void Swarm::update(int elapsedTicks) {
        int deltaTime = elapsedTicks - prevElapsed;
        
        for (int i = 0; i < Swarm::NPARTICLES; i++) {
            mParticles[i].update(deltaTime);
        }
        
        prevElapsed = elapsedTicks;
    }
}
