#ifndef STARS_H
#define STARS_H

#include "noise.h"

// Draw star
vec3 drawStar(vec3 color, vec3 viewDir, float time, float rainFactor, vec3 fogColor) {
  float t = 8.0;
  float e = 100.0;
  float n = randStar(viewDir);

  float s = pow(clamp(randStar(viewDir * 200.0), 0.0, 1.0), t) * e;
  s *= mix(0.4, 1.4, randStar(viewDir * 100.0 + vec3(time, time, time)));

  float sizeFactor = smoothstep(1.0 - NLC_STAR_SIZE, 1.0, n);
  float mask = (1.0 - 1.0 * rainFactor) * max(1.0 - 3.0 * max(fogColor.b, fogColor.g), 0.0);

  color = NLC_STAR_COLOR * s * fogColor.rgb * (1.0 - rainFactor);

  return color + vec3(s * NLC_STAR_BRIGHTNESS) * mask;
}
#endif