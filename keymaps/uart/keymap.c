#include QMK_KEYBOARD_H

#include "uart.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_ortho_1x1(KC_A)
};

void keyboard_post_init_user(void) {
    debug_enable = true;
    uart_init(115200);
}

void housekeeping_task_user(void) {
    // dump UART to console
    while (uart_available()) {
        printf("%c", uart_read());
    }
}
