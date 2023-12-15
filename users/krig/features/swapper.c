#include "swapper.h"

void update_swapper(
    bool *active,
    uint16_t cmdish,
    uint16_t tabish,
    uint16_t tabish_alt,
    uint16_t trigger,
    uint16_t trigger_alt,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            if (!*active) {
                *active = true;
                register_code(cmdish);
            }
            register_code(tabish);
        } else {
            unregister_code(tabish);
            // Don't unregister cmdish until some other key is hit or released.
        }
    } else if (keycode == trigger_alt) {
        if (record->event.pressed) {
            if (!*active) {
                *active = true;
                register_code(cmdish);
            }
            register_code(tabish_alt);
        } else {
            unregister_code(tabish_alt);
        }
    } else if (*active) {
            unregister_code(cmdish);
            *active = false;
    }
}

#include "krig.h"

static bool cmd_tab_active = false;

void process_record_swapper(uint16_t keycode, keyrecord_t* record) {
    update_swapper(&cmd_tab_active, KC_LGUI, KC_TAB, KC_GRV, CMD_TAB, CMD_GRV, keycode, record);
}
