#ifndef STARS_H
#define STARS_H

#include "detection.h"
#include "noise.h"

// draw star function to be called
vec3 drawStar(vec3 color, vec3 viewDir, float time, vec3 fogColor, float rainFactor) {
  float mask = (1.0-rainFactor)*max(1.0-3.0*max(fogColor.b, fogColor.g), 0.0);
  float s = pow(clamp(randStar(viewDir*200.0), 0.0, 1.0), 8.0)*100.0;
  s *= mix(0.4, 1.4, randStar(viewDir*100.0 + vec3(time)));

  return color + vec3(s*NLC_TWINKLING_STAR, s*NLC_TWINKLING_STAR, s*NLC_TWINKLING_STAR)*mask;
}

// draw star function for the end
vec3 drawTheEndStar(vec3 color, vec3 viewDir, float time) {
  vec3 starDir = normalize(viewDir);
  float s = pow(clamp(randStar(viewDir*200.0), 0.0, 1.0), 8.0)*100.0;
  float f = 0.5 + 0.5 * sin(randStar(starDir*150.0 + vec3(time))*6.28 + time*0.5); 
  s *= mix(0.4, 1.4, randStar(starDir*100.0+vec3(time)))*f;

  return color + vec3(s*NLC_END_TWINKLING_STAR, s*NLC_END_TWINKLING_STAR, s*NLC_END_TWINKLING_STAR);
}

#endif