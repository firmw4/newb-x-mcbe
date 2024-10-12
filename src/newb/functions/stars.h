#ifndef STARS_H
#define STARS_H

#include "noise.h"

// draw stars
vec3 drawStars(vec3 color, vec3 viewDir, float time, float rainFactor, vec3 fogColor) {
  float t = 8.0;
  float e = 100.0;

  // Calculate mask based on fog and rain
  float mask = (1.0 - 1.0 * rainFactor) * max(1.0 - 3.0 * max(fogColor.b, fogColor.g), 0.0);

  // Calculate star intensity using the new randStars function
  float s = pow(clamp(randStars(viewDir * 200.0), 0.0, 1.0), t) * e;
  s *= mix(0.4, 1.4, randStars(viewDir * 100.0 + vec3(time, time, time)));

  // Apply star intensity to the color with mask
  return color + vec3(s * 2.0) * mask;
}

#endif
    