#ifndef STARS_H
#define STARS_H

#include "noise.h"

// Star drawing function
vec3 drawStars(vec3 color, vec3 viewDir, float time) {
  float t = 8.0; // threshold
  float e = 100.0; // exposure

  float s = pow(clamp(randStars(viewDir * 200.0), 0.0, 1.0), t) * e;
  s *= mix(0.4, 1.4, randStars(viewDir * 100.0 + vec3(time, time, time)));

  // Apply star intensity to the color
  return color + vec3(s * 2.0);
}

#endif
    