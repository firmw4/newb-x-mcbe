#ifndef NOISE_H
#define NOISE_H

#include "constants.h"

// hash function for noise (for highp only)
highp float rand(highp vec2 n) {
  return fract(sin(dot(n, vec2(12.9898, 4.1414))) * 43758.5453);
}

// rand with transition
float randt(vec2 n, vec2 t) {
  return smoothstep(t.x, t.y, rand(n));
}

// 1D noise - used in plants,lantern wave
highp float noise1D(highp float x) {
  float x0 = floor(x);
  float t0 = x-x0;
  t0 *= t0*(3.0-2.0*t0);
  return mix(fract(sin(x0)*84.85), fract(sin(x0+1.0)*84.85), t0);
}

// simpler rand for disp, puddles
float fastRand(vec2 n){
  return fract(37.45*sin(dot(n, vec2(4.36, 8.28))));
}

// water displacement map (also used by caustic)
float disp(vec3 pos, highp float t) {
  float val = 0.5 + 0.5*sin(t*1.7 + (pos.x+pos.y)*NL_CONST_PI_HALF);
  return mix(fastRand(pos.xz), fastRand(pos.xz+vec2_splat(1.0)), val);
}

float noise2D(vec2 u) {
  vec2 u0 = floor(u);
  vec2 v = u-u0;
  v = 3.0*v*v - 2.0*v*v*v;

  float c0 = rand(u0);
  float c1 = rand(u0+vec2(1.0, 0.0));
  float c2 = rand(u0+vec2(1.0, 1.0));
  float c3 = rand(u0+vec2(0.0, 1.0));

  float n = mix(mix(c0, c3, v.y),mix(c1, c2, v.y), v.x);
  return n;
}

// apply bevel with radius r at at corner (1.0)
float bevel(float x, float r) {
	 //return smoothstep(0.5,1.5,x);
  float y = max(x-r,0.0);
  return r+sqrt(1.0-2.0*r+r*r-y*y);
}

// hash function for star
vec3 hashStar(vec3 p) {
    p = vec3(dot(p, vec3(127.1, 311.7, 74.7)),
             dot(p, vec3(269.5, 183.3, 246.1)),
             dot(p, vec3(113.5, 271.9, 124.6)));

    return -1.0 + 2.0 * fract(sin(p) * 43758.5453123);
}

// generate random star
float randStar(in vec3 p) {
  vec3 i = floor(p);
  vec3 f = fract(p);
  vec3 u = f * f * (3.0 - 2.0 * f);

  return mix(mix(mix(dot(hashStar(i + vec3(0.0, 0.0, 0.0)), f - vec3(0.0, 0.0, 0.0)),
                     dot(hashStar(i + vec3(1.0, 0.0, 0.0)), f - vec3(1.0, 0.0, 0.0)), u.x),
                 mix(dot(hashStar(i + vec3(0.0, 1.0, 0.0)), f - vec3(0.0, 1.0, 0.0)),
                     dot(hashStar(i + vec3(1.0, 1.0, 0.0)), f - vec3(1.0, 1.0, 0.0)), u.x), u.y),
             mix(mix(dot(hashStar(i + vec3(0.0, 0.0, 1.0)), f - vec3(0.0, 0.0, 1.0)),
                     dot(hashStar(i + vec3(1.0, 0.0, 1.0)), f - vec3(1.0, 0.0, 1.0)), u.x),
                 mix(dot(hashStar(i + vec3(0.0, 1.0, 1.0)), f - vec3(0.0, 1.0, 1.0)),
                     dot(hashStar(i + vec3(1.0, 1.0, 1.0)), f - vec3(1.0, 1.0, 1.0)), u.x), u.y), u.z);
}

#endif