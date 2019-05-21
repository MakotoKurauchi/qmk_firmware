/* Copyright 2017 MakotoKurauchi <http://yushakobo.jp/>
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

#ifndef _PCA9956_H_
#define _PCA9956_H_


uint8_t PCA9956_begin(uint8_t i2cAddr);
uint8_t PCA9956_sleep(uint8_t i2cAddr);
uint8_t PCA9956_wakeup(uint8_t i2cAddr);
uint8_t PCA9956_reset(uint8_t i2cAddr);
uint8_t PCA9956_iref_all(uint8_t i2cAddr, uint8_t val);
uint8_t PCA9956_pwm_all(uint8_t i2cAddr, uint8_t val);
uint8_t PCA9956_pwm1(uint8_t i2cAddr, uint8_t id, uint8_t val);
uint8_t PCA9956_pwm3(uint8_t i2cAddr, uint8_t id, uint8_t *val);
uint8_t PCA9956_pwm(uint8_t i2cAddr, uint8_t id, uint8_t *val, uint8_t len);



#define PCA9956_MODE1 0x00
#define PCA9956_MODE2 0x01
#define PCA9956_LEDOUT0 0x02
#define PCA9956_LEDOUT1 0x03
#define PCA9956_LEDOUT2 0x04
#define PCA9956_LEDOUT3 0x05
#define PCA9956_LEDOUT4 0x06
#define PCA9956_LEDOUT5 0x07
#define PCA9956_GRPPWM 0x08
#define PCA9956_GRPFREQ 0x09
#define PCA9956_PWM0 0x0A
#define PCA9956_PWM1 0x0B
#define PCA9956_PWM2 0x0C
#define PCA9956_PWM3 0x0D
#define PCA9956_PWM4 0x0E
#define PCA9956_PWM5 0x0F
#define PCA9956_PWM6 0x10
#define PCA9956_PWM7 0x11
#define PCA9956_PWM8 0x12
#define PCA9956_PWM9 0x13
#define PCA9956_PWM10 0x14
#define PCA9956_PWM11 0x15
#define PCA9956_PWM12 0x16
#define PCA9956_PWM13 0x17
#define PCA9956_PWM14 0x18
#define PCA9956_PWM15 0x19
#define PCA9956_PWM16 0x1A
#define PCA9956_PWM17 0x1B
#define PCA9956_PWM18 0x1C
#define PCA9956_PWM19 0x1D
#define PCA9956_PWM20 0x1E
#define PCA9956_PWM21 0x1F
#define PCA9956_PWM22 0x20
#define PCA9956_PWM23 0x21
#define PCA9956_IREF0 0x22
#define PCA9956_IREF1 0x23
#define PCA9956_IREF2 0x24
#define PCA9956_IREF3 0x25
#define PCA9956_IREF4 0x26
#define PCA9956_IREF5 0x27
#define PCA9956_IREF6 0x28
#define PCA9956_IREF7 0x29
#define PCA9956_IREF8 0x2A
#define PCA9956_IREF9 0x2B
#define PCA9956_IREF10 0x2C
#define PCA9956_IREF11 0x2D
#define PCA9956_IREF12 0x2E
#define PCA9956_IREF13 0x2F
#define PCA9956_IREF14 0x30
#define PCA9956_IREF15 0x31
#define PCA9956_IREF16 0x32
#define PCA9956_IREF17 0x33
#define PCA9956_IREF18 0x34
#define PCA9956_IREF19 0x35
#define PCA9956_IREF20 0x36
#define PCA9956_IREF21 0x37
#define PCA9956_IREF22 0x38
#define PCA9956_IREF23 0x39
#define PCA9956_OFFSET 0x3A
#define PCA9956_SUBADR1 0x3B
#define PCA9956_SUBADR2 0x3C
#define PCA9956_SUBADR3 0x3D
#define PCA9956_ALLCALLADR 0x3E
#define PCA9956_PWMALL 0x3F
#define PCA9956_IREFALL 0x40
#define PCA9956_EFLAG0 0x41
#define PCA9956_EFLAG1 0x42
#define PCA9956_EFLAG2 0x43
#define PCA9956_EFLAG3 0x44
#define PCA9956_EFLAG4 0x45
#define PCA9956_EFLAG5 0x46

#endif
