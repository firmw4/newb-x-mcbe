#ifndef STARS_H
#define STARS_H

#include "noise.h"

vec3 drawStars(vec3 skyColor, vec3 viewDir, float time, float rainFactor, vec4 fogColor) {
    float noise = randStar(viewDir * 200.0);

    if (noise > NLC_STAR_DENSITY) return skyColor;

    float brightness = pow(clamp(noise, 0.0, 1.0), 8.0) * NLC_STAR_BRIGHTNESS;
    brightness *= mix(0.4, 1.4, randStar(viewDir * 100.0 + vec3(time, time, time)));
    vec3 starColor = NLC_STAR_COL * brightness * fogColor.rgb * (1.0 - rainFactor);
    float starFactor = smoothstep(1.0 - NLC_STAR_SIZE, 1.0, noise);

    return skyColor + starColor * starFactor;
}

#endif
    