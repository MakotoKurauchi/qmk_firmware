/* Copyright 2019 Takuya Urakawa (dm9records.com)
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

// place overrides here
#define LED1_LED2_INIT  DDRC  |= (1<<4), DDRC |= (1<<5)
#define LED1ON          PORTC |= (1<<4)
#define LED1OFF         PORTC &= ~(1<<4)
#define LED2ON          PORTC |= (1<<5)
#define LED2OFF         PORTC &= ~(1<<5)
