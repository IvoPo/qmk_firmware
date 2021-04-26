/* Copyright 2020 Ben Roesner (keycapsss.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum custom_keycodes {
    DIS_heart = SAFE_RANGE,
    DIS_question,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case DIS_heart:
        if (record->event.pressed) {
            send_string(">heart>\n");
        } else {
        }
        break;

    case DIS_question:
        if (record->event.pressed) {
            send_string(">waitwhat>");
        } else {
            tap_code(KC_ENTER);
        }
        break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * ,-----------------------,
 * |  7  |  <3 |  ?? |MUTE |
 * |-----+-----+-----+-----|
 * |  4  |  5  |  6  |PGUP |
 * |-----+-----+-----+-----|
 * |  1  |  2  |  3  |PGDN |
 * |-----+-----+-----+-----|
 * |  <  |  v  |  ^  |  >  |
 * `-----------------------'
 */
    [0] = LAYOUT_ortho_4x4(
        KC_MPLY,        DIS_heart,  DIS_question,   RSFT(KC_F22),
        KC_PSCREEN,     KC_INSERT,  KC_HOME,        KC_PGUP,
        KC_COPY,        KC_DELETE,  KC_END,         KC_PGDOWN,
        KC_LEFT,        KC_DOWN,    KC_UP,          KC_RIGHT),
};

// Set LED1 state during powerup
void keyboard_post_init_user(void) {
    writePinHigh(LED_RED);
}

void encoder_update_user(uint8_t index, bool clockwise) {
/*
Rev2.1 isp
,-----------------------,
|  E1 |     |     |  E4 |
|-----+-----+-----+-----|
|     |     |     |     |
|-----+-----+-----+-----|
|     |     |     |     |
|-----+-----+-----+-----|
|     |     |     |     |
`-----------------------'
 */

    // Left Encoder (E1)
    if (index == 0) {
        if (clockwise) {
        tap_code(KC_WH_U);
        } else {
        tap_code(KC_WH_D);
        }
    // Right encoder (E4)
    } else if (index == 3) {

        if (clockwise) {
        tap_code(KC_F20);
        } else {
        tap_code(KC_F21);
        }
    }
}
