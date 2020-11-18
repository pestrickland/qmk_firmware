#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Layer 0
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   :  | ESC |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | GUI  |   A  |   R  |   S  |   T  |   G  |   K  |   N  |   E  |   I  |   O  |  '   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   Z  |   X  |   C  |   D  |   V  |   M  |   H  |   ,  |   .  |   /  |Shift/Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl |  Del | CAPS |  ALT |Layer1| Bksp |Space |Layer2| Left | Down |  Up  |Right |
     * `-----------------------------------------------------------------------------------'
     */
    [0] = LAYOUT_ortho_4x12(KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_B, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_ESC, KC_LGUI, KC_A, KC_R, KC_S, KC_T, KC_G, KC_K, KC_N, KC_E, KC_I, KC_O, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_D, KC_V, KC_M, KC_H, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_ENT), KC_LCTL, KC_DEL, KC_CAPS, KC_LALT, MO(1), KC_BSPC, KC_SPC, MO(2), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),

    /* Layer 1
     * ,-----------------------------------------------------------------------------------.
     * |   `  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      | Vol- | Vol+ | Mute |      |      |      |  F11 |  F12 |      |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Reset|      |      |      |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [1] = LAYOUT_ortho_4x12(KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______, _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, KC_F11, KC_F12, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    /* Layer 2 (r_ Indicates RGB Controls)
     * ,-----------------------------------------------------------------------------------.
     * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |r_TOG |r_Mode|r_Hue+|r_Hue-|      |      |   -  |   =  |   [  |   ]  | ISO #|
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |ISO \ |BL_STEP|     |      |      |      |   +  |      |      |   }  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [2] = LAYOUT_ortho_4x12(_______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______, _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, _______, _______, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_NUHS, _______, KC_NUBS, BL_STEP, _______, _______, _______, _______, KC_PLUS, _______, _______, KC_RCBR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)};

void matrix_init_user(void) {}

void matrix_scan_user(void) {}

bool process_record_user(uint16_t keycode, keyrecord_t *record) { return true; }

void led_set_user(uint8_t usb_led) {
    if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
    } else {
    }

    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    } else {
    }

    if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
    } else {
    }

    if (IS_LED_ON(usb_led, USB_LED_COMPOSE)) {
    } else {
    }

    if (IS_LED_ON(usb_led, USB_LED_KANA)) {
    } else {
    }
}
