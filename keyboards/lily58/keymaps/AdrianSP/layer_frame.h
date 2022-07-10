// Copyright 2021 Nicolas Druoton (druotoni)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// layer name : must be 3 chars
#define LAYER_NAME_0 "ABC"
#define LAYER_NAME_1 "PLY"
#define LAYER_NAME_2 "GLO"
#define LAYER_NAME_3 "LOW"
#define LAYER_NAME_4 "RIZ"

enum layer_number { _COLEMAK = 0, _GAME, _G_LOW, _LOWER, _RAISE };

void render_gears(void);
void render_layer_frame(gui_state_t t);
void update_layer_frame(layer_state_t state);