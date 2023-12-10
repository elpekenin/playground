#include QMK_KEYBOARD_H

#include "rtc/rtc.h"

#include "logging.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_1x1(KC_A)
};

void keyboard_post_init_keymap(void) {
    rtc_init();
    set_logging_fmt("[%T] %LL -- %M\n");
}


static char log_time_str[30] = {0};
const char *log_time(void) {
    rtc_time_t time = rtc_read_time_struct();
    snprintf(
        log_time_str, sizeof(log_time_str),
        "%02d/%02d/%02d·%02d:%02d:%02d",
        time.date, time.month, time.year % 1000,
        time.hour, time.minute, time.second
    );
    return log_time_str;
}

void housekeeping_task_keymap(void) {
    static uint32_t timer = 0;

    if (timer_elapsed32(timer) < 5000) {
        return;
    }
    timer = timer_read32();

    rtc_task();

    logging(UNKNOWN, LOG_INFO, "Testing");
}

