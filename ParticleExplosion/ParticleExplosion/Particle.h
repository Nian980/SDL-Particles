//
//  Particle.h
//  ParticleExplosion
//
//  Created by Nian Xu Wang on 6/26/18.
//  Copyright © 2018 Nian Xu Wang. All rights reserved.
//

#ifndef Particle_h
#define Particle_h

#include <stdio.h>
#include <cstdlib>

namespace nian {
//convert from cartesian to polar coordinates. Need a random degree (0 to 360) and speed for each.
    
struct Particle {
    double mX;
    double mY;
    
    double xSpeed; //cartesian coordinate system no longer needed
    double ySpeed;
    
//    double mSpeed; //polar coordinates with magnitude and direction (angle)
//    double mDirection;
    
    Particle();
    ~Particle();
    
    void update(); //update position of particle (and color as well?)
};
    
}

#endif /* Particle_h */
