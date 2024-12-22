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

#define NUM_COLORS (sizeof(colors) / sizeof(colors[0]))
static uint8_t current_color_index = 0;

// This is a side lights only configuration where the color is set to a static gradient.
static bool HOLOGRAPHICS_UNDERGLOW(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
    }

     for (uint8_t i = 67; i <= 76; i++) {
        rgb_matrix_set_color(i,
                            colors[(current_color_index + (i - 67)) % NUM_COLORS].r,
                            colors[(current_color_index + (i - 67)) % NUM_COLORS].g,
                            colors[(current_color_index + (i - 67)) % NUM_COLORS].b);
    }

    for (uint8_t i = 77; i <= 86; i++) {
        rgb_matrix_set_color(i,
                            colors[(current_color_index + (i - 77)) % NUM_COLORS].r,
                            colors[(current_color_index + (i - 77)) % NUM_COLORS].g,
                            colors[(current_color_index + (i - 77)) % NUM_COLORS].b);
    }

    return rgb_matrix_check_finished_leds(led_max);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
