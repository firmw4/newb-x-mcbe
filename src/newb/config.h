#ifndef NL_CONFIG_H
#define NL_CONFIG_H

/*
  NEWB SHADER MAIN CONFIG
  This part contains base configuration options for the shader.

  TOGGLES
  - If [toggle] is mentioned, then
    options can be commented to disable (by adding '//')
  - eg: #define PLANTS_WAVE    -> this is ON
        //#define PLANTS_WAVE  -> this is OFF

  COLOR VALUES
  - Color format: vec3(red,green,blue)
  - 1.0 means 100%, 0.0 means 0%
  - eg: vec3(1.0,1.0,0.0) = yellow

  VALUES
  - Values must be decimal
  - eg. 32 is wrong, 32.0 is correct

  TYPES
  - Should be integer. options to choose will be mentioned there
  - eg: #define NL_FOG_TYPE 2

  Remember to rebuild the shader after making changes.
*/

/* Color correction */
#define NL_TONEMAP_TYPE  3
#define NL_CONTRAST      1.350
#define NL_EXPOSURE      1.250
#define NL_SATURATION    1.200
//#define NL_TINT         vec3(1.0,0.75,0.5)

/* Terrain lighting */
#define NL_SUN_INTENSITY 2.05   // 0.5 weak ~ 5.0 bright
#define NL_TORCH_INTENSITY 0.85  // 0.5 weak ~ 3.0 bright
#define NL_NIGHT_BRIGHTNESS 0.25 // 0.0 dark ~ 2.0 bright
#define NL_CAVE_BRIGHTNESS 0.80  // 0.0 dark ~ 2.0 bright
#define NL_SHADOW_INTENSITY 0.86 // 0.0 no shadow ~ 1.0 strong shadow
#define NL_BLINKING_TORCH     // [toggle] flickering light
//#define NL_CLOUD_SHADOW       // [toggle] cloud shadow (simple clouds only)

/* Sun/moon light color on terrain */
#define NL_MORNING_SUN_COL vec3(1.0,0.42,0.24)
#define NL_NOON_SUN_COL    vec3(1.0,0.75,0.42)
#define NL_NIGHT_SUN_COL   vec3(0.62,0.4,1.00)

/* Ambient light on terrain (light that is added everywhere) */
#define NL_NETHER_AMBIENT vec3(1.0,0.68,0.89)
#define NL_END_AMBIENT    vec3(0.88,0.45,1.3)

/* Torch colors */
#define NL_OVERWORLD_TORCH_COL  vec3(1.0,0.63,0.2)
#define NL_UNDERWATER_TORCH_COL vec3(0.4,0.82,0.9)
#define NL_NETHER_TORCH_COL     vec3(1.2,0.42,0.2)
#define NL_END_TORCH_COL        vec3(0.8,0.42,1.0)

/* Fog */
#define NL_FOG_TYPE 2             // 0:no fog, 1:vanilla, 2:smoother vanilla
#define NL_MIST_DENSITY 1.25      // 0.0 no mist ~ 1.0 misty
#define NL_RAIN_MIST_OPACITY 0.12 // [toggle] 0.04 very subtle ~ 0.5 thick rain mist blow
//#define NL_CLOUDY_FOG 0.1         // [toggle] 0.0 subtle - 0.8 dense fog clouds

/* Sky colors */
#define NL_DAY_ZENITH_COL    vec3(0.280, 0.520, 1.000)
#define NL_DAY_HORIZON_COL   vec3(0.550, 0.680, 1.000)

#define NL_NIGHT_ZENITH_COL  vec3(0.000, 0.002, 0.006)
#define NL_NIGHT_HORIZON_COL vec3(0.002, 0.082, 0.255)

#define NL_DAWN_ZENITH_COL   vec3(0.200, 0.270, 0.600)
#define NL_DAWN_HORIZON_COL  vec3(1.000, 0.605, 0.120)
#define NL_DAWN_EDGE_COL     vec3(1.400, 0.305, 0.200)

#define NL_RAIN_ZENITH_COL   vec3(0.520, 0.520, 0.700)
#define NL_RAIN_HORIZON_COL  vec3(0.480, 0.500, 0.680)

#define NLC_END_SKY 3
#define NL_END_ZENITH_COL    vec3(0.020, 0.000, 0.043)
#define NL_END_HORIZON_COL   vec3(0.280, 0.060, 0.820)

/* Rainbow */
//#define NL_RAINBOW         // [toggle] enable rainbow in sky
#define NL_RAINBOW_CLEAR 0.0 // 0.3 subtle ~ 1.7 bright during clear
#define NL_RAINBOW_RAIN 1.0  // 0.5 subtle ~ 2.0 bright during rain

/* Ore glow intensity */
#define NL_GLOW_TEX 4.0    // 0.4 weak ~ 8.0 bright
//#define NL_GLOW_SHIMMER    // [toggle] shimmer effect
#define NL_GLOW_LEAK 0.6   // [toggle] 0.08 subtle ~ 1.0 100% brightness of NL_GLOW_TEX

/* Waving */
#define NL_PLANTS_WAVE 0.05    // [toggle] 0.02 gentle ~ 0.4 violent
#define NL_LANTERN_WAVE 0.16   // [toggle] 0.05 subtle ~ 0.4 large swing
#define NL_WAVE_SPEED 2.2      // 0.5 slow wave ~ 5.0 very fast wave
//#define NL_EXTRA_PLANTS_WAVE // [toggle] !dont use! wave using texture coords (1.21.0 vanilla 2048x1024)

/* Water */
#define NL_WATER_TRANSPARENCY 0.6 // 0.0 transparent ~ 1.0 normal
#define NL_WATER_BUMP 0.07        // 0.001 plain ~ 0.2 bumpy water
#define NL_WATER_TEX_OPACITY 0.225  // 0.0 plain water ~ 1.0 vanilla water texture
#define NL_WATER_WAVE             // [toggle] wave effect
#define NL_WATER_FOG_FADE         // [toggle] fog fade for water
#define NL_WATER_CLOUD_REFLECTION // [toggle] simple clouds/aurora reflection
//#define NL_WATER_REFL_MASK      // [toggle] fake water reflection mask
#define NL_WATER_TINT vec3(0.52,0.92,0.85)

/* Underwater */
#define NL_UNDERWATER_BRIGHTNESS 2.6         // 0.0 dark ~ 3.0 bright
#define NL_CAUSTIC_INTENSITY 2.2             // 0.5 weak ~ 5.0 bright
//#define NL_UNDERWATER_WAVE 0.1               // [toggle] 0.02 subtle ~ 0.6 trippy
#define NL_UNDERWATER_STREAKS 1.8            // [toggle] 0.8 subtle - 2.0 bright streaks from top
#define NL_UNDERWATER_TINT vec3(0.6,1.0,0.9) // fog tint color when underwater

/* Cloud type */
#define NL_CLOUD_TYPE 2 // 0:vanilla, 1:soft, 2:rounded

/* Vanilla cloud settings - make sure to remove clouds.png when using this */
#define NL_CLOUD0_THICKNESS 2.4      // 0.5 slim ~ 8.0 fat
#define NL_CLOUD0_RAIN_THICKNESS 4.0 // 0.5 slim ~ 8.0 fat
#define NL_CLOUD0_OPACITY 1.0        // 0.0 invisible ~ 1.0 opaque
#define NL_CLOUD0_MULTILAYER         // [toggle] extra cloud layer

/* Soft cloud settings */
#define NL_CLOUD1_SCALE vec2(0.026, 0.102) // 0.003 large ~ 0.2 tiny
#define NL_CLOUD1_DEPTH 2.6                // 0.0 no bump ~ 10.0 large bumps
#define NL_CLOUD1_SPEED 0.04               // 0.0 static ~ 0.4 fast moving
#define NL_CLOUD1_DENSITY 0.62             // 0.1 less clouds ~ 0.8 more clouds
#define NL_CLOUD1_OPACITY 0.9              // 0.0 invisible ~ 1.0 opaque

/* Rounded cloud Settings */
#define NL_CLOUD2_THICKNESS 2.2      // 0.5 slim ~ 5.0 fat
#define NL_CLOUD2_RAIN_THICKNESS 2.4 // 0.5 slim ~ 5.0 fat
#define NL_CLOUD2_STEPS 5            // 3 low quality ~ 16 high quality
#define NL_CLOUD2_SCALE 0.03         // 0.003 large ~ 0.3 tiny
#define NL_CLOUD2_SHAPE 0.5          // 0.0 round ~ 1.0 box
#define NL_CLOUD2_DENSITY 100.0       // 1.0 blurry ~ 100.0 sharp
#define NL_CLOUD2_VELOCITY 0.8       // 0.0 static ~ 4.0 very fast
//#define NL_CLOUD2_MULTILAYER       // [toggle] extra cloud layer

/* Custom rounded cloud settings */
#define NLC_CLOUD2_OPACITY 0.8
#define NLC_CLOUD2_TRANSITION1 0.1001
#define NLC_CLOUD2_TRANSITION2 0.1

#define NLC_DAY_CLOUD2_COL   vec3(0.72, 0.72, 0.75)
#define NLC_NIGHT_CLOUD2_COL vec3(0.10, 0.121, 0.3)
#define NLC_DAWN_CLOUD2_COL  vec3(0.63, 0.417, 0.3)
#define NLC_RAIN_CLOUD2_COL  vec3(0.03, 0.08, 0.08)

/* Aurora settings */
#define NL_AURORA_VELOCITY 0.03 // 0.0 static ~ 0.3 very fast
#define NL_AURORA_SCALE 0.04    // 0.002 large ~ 0.4 tiny
#define NL_AURORA_WIDTH 0.18    // 0.04 thin line ~ 0.4 thick lines
#define NL_AURORA_COL1 vec3(0.1, 0.9, 1.0)
#define NL_AURORA_COL2 vec3(0.8, 0.4, 1.0)

/* Shooting star */
#define NL_SHOOTING_STAR 1.0        // [toggle] 0.2 dim ~ 1.0 bright
#define NL_SHOOTING_STAR_PERIOD 8.0 // 0.4 fast ~ 12.0 slow (12 secs)
#define NL_SHOOTING_STAR_DELAY 8.0 // 0.0 no delay ~ 100.0 long time (100 secs)

/* Chunk loading slide in animation */
//#define NL_CHUNK_LOAD_ANIM 100.0 // [toggle] -600.0 fall from top ~ 600.0 rise from bottom

/* Sun/Moon */
//#define NL_SUNMOON_ANGLE 45.0 // [toggle] 0.0 no tilt ~ 90.0 tilt of 90 degrees
#define NL_SUNMOON_SIZE 1.1     // 0.3 tiny ~ 4.0 massive

/* Fake godrays during sunrise/sunset */
#define NL_GODRAY 1.2 // [toggle] 0.1 subtle ~ 0.8 strong

/* Sky reflection */
//#define NL_GROUND_REFL 0.4       // [toggle] 0.2 slightly reflective ~ 1.0 fully reflect sky 
#define NL_GROUND_RAIN_WETNESS 1.0 // 0.0 no wetness ~ 1.0 fully wet blocks when raining
#define NL_GROUND_RAIN_PUDDLES 0.7 // 0.0 no puddles ~ 1.0 puddles
//#define NL_GROUND_AURORA_REFL    // [toggle] aurora reflection on ground


/*
  NEWB SHADER SUBPACK CONFIG
  This part contains custom configuration options for each subpack.

  If a value is already defined,
  then you must undefine it before modifying:
  eg: #undef OPTION_NAME

  Subpack names and flags are inside `pack_config.toml`.
  Build tool will enable corresponding flags when compiling. 
*/

#ifdef NO_WAVE_NO_FOG
  #define NO_WAVE
  #define NO_FOG
#endif

#ifdef NO_FOG
  #undef NL_FOG_TYPE
  #define NL_FOG_TYPE 0
#endif

#ifdef NO_WAVE
  #undef NL_PLANTS_WAVE
  #undef NL_LANTERN_WAVE
  #undef NL_UNDERWATER_WAVE
  #undef NL_WATER_WAVE
  #undef NL_RAIN_MIST_OPACITY
#endif

#ifdef SOFT_CLOUDS
  #undef NL_CLOUD_TYPE
  #define NL_CLOUD_TYPE 1
#endif

#ifdef BOX_CLOUDS
  #undef NL_CLOUD_TYPE
  #define NL_CLOUD_TYPE 0
#endif

/*
#ifdef ALWAYS_REFLECTION
  #define NL_GROUND_REFL 0.6
#endif
*/

#endif
