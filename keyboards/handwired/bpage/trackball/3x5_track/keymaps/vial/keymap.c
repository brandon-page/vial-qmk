#include QMK_KEYBOARD_H
#include "3x5_track.h"
#include "trackball.h"

#define _BASE 0
#define _LOWER 1
#define _RAISE 2

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

enum bpage_custom_vial_keycodes {
    DrgScrl = QK_KB,
    DrgTog,
    DpiUp,
    DpiDwn,
    AutoCorrect,
    bptest,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case DrgScrl:
            charybdis_set_pointer_dragscroll_enabled(record->event.pressed);
            break;
        case DrgTog:
            if (record->event.pressed) {
                charybdis_set_pointer_dragscroll_enabled(!charybdis_get_pointer_dragscroll_enabled());
            }
            break;
        case DpiUp:
            if (record->event.pressed) {
                charybdis_cycle_pointer_default_dpi(true);
             }
            break;
        case DpiDwn:
            if (record->event.pressed) {
                charybdis_cycle_pointer_default_dpi(false);
             }
            break;
        case AutoCorrect:
            process_record_kb(QK_AUTOCORRECT_TOGGLE, record);
            break;
        case bptest:
            SEND_STRING("Hello world!");
            break;
        default:
            return true;
	}

    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_3x5(
        _______  ,  _______, _______  , _______  , _______  ,                     _______  , _______  , _______  , _______  , _______,
        _______  ,  _______, _______  , _______  , _______  ,                     _______  , _______  , _______  , _______  , _______,
        _______  ,  _______, _______  , _______  , _______  ,                     _______  , _______  , _______  , _______  , _______,
                                      _______,                       _______,
                                      _______, _______,             _______,
                                      _______, _______,     _______, _______
        ),

    [_LOWER] = LAYOUT_3x5(
        _______  ,  _______, _______  , _______  , _______  ,                     _______  , _______  , _______  , _______  , _______,
        _______  ,  _______, _______  , _______  , _______  ,                     _______  , _______  , _______  , _______  , _______,
        _______  ,  _______, _______  , _______  , _______  ,                     _______  , _______  , _______  , _______  , _______,
                                      _______,                       _______,
                                      _______, _______,             _______,
                                      _______, _______,     _______, _______
        ),

    [_RAISE] = LAYOUT_3x5(
        _______  ,  _______, _______  , _______  , _______  ,                     _______  , _______  , _______  , _______  , _______,
        _______  ,  _______, _______  , _______  , _______  ,                     _______  , _______  , _______  , _______  , _______,
        _______  ,  _______, _______  , _______  , _______  ,                     _______  , _______  , _______  , _______  , _______,
                                      _______,                       _______,
                                      _______, _______,             _______,
                                      _______, _______,     _______, _______
        ),

    [3] = LAYOUT_3x5(
        _______  ,  _______, _______  , _______  , _______  ,                     _______  , _______  , _______  , _______  , _______,
        _______  ,  _______, _______  , _______  , _______  ,                     _______  , _______  , _______  , _______  , _______,
        _______  ,  _______, _______  , _______  , _______  ,                     _______  , _______  , _______  , _______  , _______,
                                      _______,                       _______,
                                      _______, _______,             _______,
                                      _______, _______,     _______, _______
        ),

    [4] = LAYOUT_3x5(
        _______  ,  _______, _______  , _______  , _______  ,                     _______  , _______  , _______  , _______  , _______,
        _______  ,  _______, _______  , _______  , _______  ,                     _______  , _______  , _______  , _______  , _______,
        _______  ,  _______, _______  , _______  , _______  ,                     _______  , _______  , _______  , _______  , _______,
                                      _______,                       _______,
                                      _______, _______,             _______,
                                      _______, _______,     _______, _______
        ),

    [5] = LAYOUT_3x5(
        _______  ,  _______, _______  , _______  , _______  ,                     _______  , _______  , _______  , _______  , _______,
        _______  ,  _______, _______  , _______  , _______  ,                     _______  , _______  , _______  , _______  , _______,
        _______  ,  _______, _______  , _______  , _______  ,                     _______  , _______  , _______  , _______  , _______,
                                      _______,                       _______,
                                      _______, _______,             _______,
                                      _______, _______,     _______, _______
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
    [3] =   { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [4] =   { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [5] =   { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    //                  Encoder 1                                     Encoder 2
};
#endif

#if defined(POINTING_DEVICE_AUTO_MOUSE_ENABLE)
void pointing_device_init_user(void) {
    set_auto_mouse_layer(2);
    set_auto_mouse_enable(true);
}
#endif
