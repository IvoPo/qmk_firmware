/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2020 Ben Roesner (keycapsss.com)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_ANIMATIONS
#    define RGBLIGHT_HUE_STEP 6 // number of steps to cycle through the hue by
#    define RGBLIGHT_SAT_STEP 6 // number of steps to increment the saturation by
#    define RGBLIGHT_VAL_STEP 6 // number of steps to increment the brightness by
#    define RGBLIGHT_SLEEP //  the RGB lighting will be switched off when the host goes to sleep
#endif

//Encoder config for EC11 by Alps
#define ENCODER_RESOLUTION 2

#define XXX KC_NO

#define LAYOUT_miryoku(\
        K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09,\
        K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19,\
        K20, K21, K22, K23, K24,                K25, K26, K27, K28, K29,\
        N30, N31, K32, K33, K34,                K35, K36, K37, N38, N39 \
)\
LAYOUT(\
XXX, XXX, XXX, XXX, XXX, XXX,                XXX, XXX, XXX, XXX, XXX, XXX,\
XXX, K00, K01, K02, K03, K04,                K05, K06, K07, K08, K09, XXX,\
XXX, K10, K11, K12, K13, K14,                K15, K16, K17, K18, K19, XXX,\
XXX, K20, K21, K22, K23, K24, XXX,      XXX, K25, K26, K27, K28, K29, XXX,\
                XXX, K32, K33, K34,    K35, K36, K37, XXX \
)
