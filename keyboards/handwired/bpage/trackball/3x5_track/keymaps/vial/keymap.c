#include QMK_KEYBOARD_H
#include "3x5_track.h"

#define _COLEMAK 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_3x5(
        _______  ,  _______, _______  , _______  , _______  ,                     _______  , _______  , _______  , _______  , _______,
        _______  ,  _______, _______  , _______  , _______  ,                     _______  , _______  , _______  , _______  , _______,
        _______  ,  _______, _______  , _______  , _______  ,                     _______  , _______  , _______  , _______  , _______,
                                      _______,                       _______,
                                      _______, _______,             _______,
                                      _______, _______,     _______, _______
        ),

    [_LOWER] = LAYOUT_3x5(
        _______,_______,_______,_______,KC_LBRC,                     KC_RBRC, KC_P7 , KC_P8 , KC_P9 ,KC_PLUS,
        KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,                     KC_RPRN, KC_P4 , KC_P5 , KC_P6 ,KC_MINS,
        _______,_______,_______,_______,_______,                     _______, KC_P1 , KC_P2 , KC_P3 ,KC_EQL,
                                        _______,                     _______,
                                        KC_BTN3,KC_BTN1,             _______,
                                        SNIPING,DRGSCRL,     _______,QK_BOOT

        ),

    [_RAISE] = LAYOUT_3x5(
        KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5,                       KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,
        _______,_______,_______,_______,KC_LBRC,                     KC_RBRC,_______,KC_NLCK,KC_INS ,KC_SLCK,
        KC_LEFT,KC_UP  ,KC_DOWN,KC_RGHT,KC_LPRN,                     KC_RPRN,KC_MPRV,KC_MPLY,KC_MNXT,KC_VOLD,
                                        _______,                     _______,
                                        _______,_______,             _______,
                                        QK_BOOT,_______,     _______,_______
        )
};

void keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
    debug_enable=true;
    debug_matrix=true;
    debug_keyboard=true;
    debug_mouse=true;
#else
    debug_enable=false;
    debug_matrix=false;
    debug_keyboard=false;
    debug_mouse=false;
#endif
}

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)  },
    [1] =   { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [2] =   { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    //                  Encoder 1                                     Encoder 2
};
#endif

void pointing_device_init_user(void) {
    set_auto_mouse_layer(2);
    set_auto_mouse_enable(true);
}
