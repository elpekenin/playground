#include QMK_KEYBOARD_H

#include "uart.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    LAYOUT_ortho_1x1(KC_A)
};

void keyboard_post_init_user(void) {
    debug_enable = true;
}

void housekeeping_task_user(void) {
    static uint32_t print_timer = 0;
    if (timer_elapsed32(print_timer) < 500) {
        return;
    }

    print_timer = timer_read32();
    printf("Alive\n");

    // dump UART to console
    uart_init(115200);
    while (uart_available()) {
        printf("%c", uart_read());
    }
}
