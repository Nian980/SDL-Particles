//
//  Swarm.h
//  ParticleExplosion
//
//  Created by Nian Xu Wang on 6/26/18.
//  Copyright © 2018 Nian Xu Wang. All rights reserved.
//

#ifndef Swarm_h
#define Swarm_h

#include "Particle.h"

namespace nian {
    
class Swarm {
public:
    const static int NPARTICLES = 5000;
    
private:
    Particle* mParticles;
    int prevElapsed;
    
public:
    Swarm();
    virtual ~Swarm();
    
    const Particle* const getParticles() { return mParticles; } //inline cuz small function
    void update(int elapsedTicks);
};
    
}

#endif /* Swarm_h */
