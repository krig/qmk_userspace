 /*
  * Copyright 2023 Kristoffer Gronlund
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

#pragma once

#undef TAPPING_TOGGLE
#define TAPPING_TOGGLE 2
#undef TAPPING_TERM
#define TAPPING_TERM 200
#define HOLD_ON_OTHER_KEY_PRESS
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#undef DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

#ifdef AUDIO_ENABLE
#undef STARTUP_SONG
    #define STARTUP_SONG SONG(MINOR_SOUND)
#endif

#define FLOW_COUNT 15
#define FLOW_LAYERS_COUNT 1

/*
#define KRIG_CUSTOM_SHIFT
#define KRIG_CUSTOM_SEQUENCES
#define KRIG_CAPS_WORD
#define KRIG_MOUSE_LAYER
#define KRIG_MONOBLOCK
*/

#ifdef KRIG_MOUSE_LAYER
// settings copied from the ferris default keymap

// Set the mouse settings to a comfortable speed/accuracy trade-off,
// assuming a screen refresh rate of 60 Htz or higher
// The default is 50. This makes the mouse ~3 times faster and more accurate
#define MOUSEKEY_INTERVAL 16
// The default is 20. Since we made the mouse about 3 times faster with the previous setting,
// give it more time to accelerate to max speed to retain precise control over short distances.
#define MOUSEKEY_TIME_TO_MAX 40
// The default is 300. Let's try and make this as low as possible while keeping the cursor responsive
#define MOUSEKEY_DELAY 100
// It makes sense to use the same delay for the mouseweel
#define MOUSEKEY_WHEEL_DELAY 100
// The default is 100
#define MOUSEKEY_WHEEL_INTERVAL 50
// The default is 40
#define MOUSEKEY_WHEEL_TIME_TO_MAX 100
#endif
