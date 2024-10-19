#ifndef STARS_H
#define STARS_H

#include "detection.h"
#include "noise.h"

// Draw star
vec3 drawStar(vec3 color, vec3 viewDir, float time, vec3 fogColor, nl_environment env) {
  float t = 8.0;
  float e = 100.0;
  float n = randStar(viewDir);

  float mask = (1.0-1.0*env.rainFactor)*max(1.0-3.0*max(fogColor.b, fogColor.g), 0.0);

  float s = pow(clamp(randStar(viewDir*200.0), 0.0, 1.0), t) * e;
  s *= mix(0.4, 1.4, randStar(viewDir*100.0 + vec3(time, time, time)));

  return color + vec3(s*2.0) * mask;
}

#endif