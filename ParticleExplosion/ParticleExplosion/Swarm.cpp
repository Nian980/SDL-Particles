//
//  Swarm.cpp
//  ParticleExplosion
//
//  Created by Nian Xu Wang on 6/26/18.
//  Copyright © 2018 Nian Xu Wang. All rights reserved.
//

#include "Swarm.h"

namespace nian {
    Swarm::Swarm() {
        mParticles = new Particle[NPARTICLES];
    }
    
    Swarm::~Swarm() {
        delete [] mParticles;
    }
    
    void Swarm::update() {
        for (int i = 0; i < Swarm::NPARTICLES; i++) {
            mParticles[i].update();
        }
    }
}
