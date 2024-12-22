 /* Copyright 2024 Eugenio Pastoral
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

RGB_MATRIX_EFFECT(SOLID_UNDERGLOW)
RGB_MATRIX_EFFECT(HOLOGRAPHICS_UNDERGLOW)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

// This is a side lights only configuration where the solid color is following the current HSV setting.
static bool SOLID_UNDERGLOW(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    RGB rgb = rgb_matrix_hsv_to_rgb(rgb_matrix_config.hsv);
    for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], 0x02)) { // 0x02 == LED_FLAG_UNDERGLOW
            rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
        } else {
            rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}

const rgb_t colors[] = {
    {0xff, 0x00, 0xee},
    {0xcc, 0x00, 0xff},
    {0x9e, 0x00, 0xff},
    {0x70, 0x00, 0xff},
    {0x52, 0x00, 0xff},
    {0x33, 0x00, 0xff},
    {0x00, 0x38, 0xff},
    {0x00, 0x57, 0xff},
    {0x00, 0x85, 0xff},
    {0x00, 0xb2, 0xff}
};

// This is a side lights only configuration where the color is set to a static gradient.
static bool HOLOGRAPHICS_UNDERGLOW(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        if (HAS_FLAGS(g_led_config.flags[i], 0x02)) { // 0x02 == LED_FLAG_UNDERGLOW
            // RIGHT-HAND SIDE LEDS || LEFT-HAND SIDE LEDS
            if (i == 67 || i == 77) {
                rgb_matrix_set_color(i, colors[0].r, colors[0].g, colors[0].b);
            } else if (i == 68 || i == 78) {
                rgb_matrix_set_color(i, colors[1].r, colors[1].g, colors[1].b);
            } else if (i == 69 || i == 79) {
                rgb_matrix_set_color(i, colors[2].r, colors[2].g, colors[2].b);
            } else if (i == 70 || i == 80) {
                rgb_matrix_set_color(i, colors[3].r, colors[3].g, colors[3].b);
            } else if (i == 71 || i == 81) {
                rgb_matrix_set_color(i, colors[4].r, colors[4].g, colors[4].b);
            } else if (i == 72 || i == 82) {
                rgb_matrix_set_color(i, colors[5].r, colors[5].g, colors[5].b);
            } else if (i == 73 || i == 83) {
                rgb_matrix_set_color(i, colors[6].r, colors[6].g, colors[6].b);
            } else if (i == 74 || i == 84) {
                rgb_matrix_set_color(i, colors[7].r, colors[7].g, colors[7].b);
            } else if (i == 75 || i == 85) {
                rgb_matrix_set_color(i, colors[8].r, colors[8].g, colors[8].b);
            } else if (i == 76 || i == 86) {
                rgb_matrix_set_color(i, colors[9].r, colors[9].g, colors[9].b);
            }
        }
        else {
            rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
