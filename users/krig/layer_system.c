#include "krig.h"
#include "layer_system.h"

bool krig_process_default_layers(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case DF_QWER:
            if (record->event.pressed) {
                if (layer_state_cmp(default_layer_state, _QWERTY)) {
                    set_single_persistent_default_layer(_ALTERN);
                } else if (layer_state_cmp(default_layer_state, _ALTERN)) {
                    set_single_persistent_default_layer(_GAME);
                } else {
                    set_single_persistent_default_layer(_QWERTY);
                }
            }
            return false;
    };
    return true;
}
