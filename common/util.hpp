/*************************************************************************
 * This file is part of input-overlay
 * github.con/univrsal/input-overlay
 * Copyright 2020 univrsal <universailp@web.de>.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *************************************************************************/

#pragma once
#include <stdint.h>
#include <string>

/* clang-format off */
#define UTIL_MAX(a, b)                  (((a) > (b)) ? (a) : (b))
#define UTIL_MIN(a, b)                  (((a) < (b)) ? (a) : (b))
#define UTIL_CLAMP(lower, x, upper)     (UTIL_MIN(upper, UTIL_MAX(x, lower)))
#define UTIL_SWAP_BE16(i)               ((i >> 8) | (i << 8))

#define DEAD_ZONE(x, dz)                ((x < dz) && (x > -dz))
/* clang-format on */

namespace common {

/* Get default key names from a libuiohook keycode */
const char *key_to_text(int key_code);

void util_enable_mask(uint16_t &masks, uint16_t mask);

void util_disable_mask(uint16_t &masks, uint16_t mask);

void util_set_mask(uint16_t &masks, uint16_t mask, bool state);

uint16_t util_mouse_to_vc(int m);

inline bool ends_with(std::string const &value, std::string const &ending)
{
	if (ending.size() > value.size())
		return false;
	return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

}
