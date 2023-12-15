/* Copyright 2021 Dane Evans
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

// #define USE_MATRIX_I2C

/* Select hand configuration */

/// https://thomasbaart.nl/2018/12/01/reducing-firmware-size-in-qmk/

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS
#define SPLIT_USB_DETECT
#define SELECT_SOFT_SERIAL_SPEED 2

#define CUSTOM_FONT

#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

#define ENCODER_DIRECTION_FLIP

#define KRIG_CUSTOM_SHIFT
#define KRIG_CUSTOM_SEQUENCES
#define KRIG_CAPS_WORD
