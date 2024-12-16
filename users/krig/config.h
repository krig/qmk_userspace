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

#define FLOW_COUNT 30

/*
#define KRIG_CUSTOM_SHIFT
#define KRIG_CUSTOM_SEQUENCES
#define KRIG_CAPS_WORD
#define KRIG_MOUSE_LAYER
#define KRIG_MONOBLOCK
*/

#ifdef KRIG_MOUSE_LAYER

#define MK_COMBINED
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_TIME_TO_MAX 50
#endif
