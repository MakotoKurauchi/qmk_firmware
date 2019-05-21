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

#include "i2cmaster.h"
#include "pca9956.h"

uint8_t PCA9956_begin(uint8_t i2cAddr){
  return 0;
}
uint8_t PCA9956_sleep(uint8_t i2cAddr){
  return 0;
}
uint8_t PCA9956_wakeup(uint8_t i2cAddr){
  return 0;
}

uint8_t PCA9956_reset(uint8_t i2cAddr){
  uint8_t err = i2c_start(i2cAddr<<1);  if (err) goto i2c_error;
  err = i2c_write(0);                   if (err) goto i2c_error;
  err = i2c_write(0x06);                if (err) goto i2c_error;
  i2c_stop();
  return 0;

i2c_error:
  i2c_stop();
  return err;
}

uint8_t PCA9956_iref_all(uint8_t i2cAddr, uint8_t val){
  uint8_t err = i2c_start(i2cAddr<<1);  if (err) goto i2c_error;
  err = i2c_write(PCA9956_IREFALL);     if (err) goto i2c_error;
  err = i2c_write(val);                 if (err) goto i2c_error;
  i2c_stop();
  return 0;

i2c_error:
  i2c_stop();
  return err;
}

uint8_t PCA9956_pwm_all(uint8_t i2cAddr, uint8_t val){
  uint8_t err = i2c_start(i2cAddr<<1);  if (err) goto i2c_error;
  err = i2c_write(PCA9956_PWMALL);      if (err) goto i2c_error;
  err = i2c_write(val);                 if (err) goto i2c_error;
  i2c_stop();
  return 0;
i2c_error:
  i2c_stop();
  return err;
}

uint8_t PCA9956_pwm1(uint8_t i2cAddr, uint8_t id, uint8_t val){
  uint8_t err = i2c_start(i2cAddr<<1);  if (err) goto i2c_error;
  err = i2c_write(PCA9956_PWM0 + id);   if (err) goto i2c_error;
  err = i2c_write(val);                 if (err) goto i2c_error;
  i2c_stop();
  return 0;

i2c_error:
  i2c_stop();
  return err;
}

uint8_t PCA9956_pwm(uint8_t i2cAddr, uint8_t id, uint8_t *val, uint8_t len){
  uint8_t err = i2c_start(i2cAddr<<1);        if (err) goto i2c_error;
  err = i2c_write((PCA9956_PWM0 + id)|0x80);  if (err) goto i2c_error;
  for(uint8_t i=0; i<len; i++){
  	err = i2c_write(val[i]);                  if (err) goto i2c_error;
  }
  i2c_stop();
  return 0;

i2c_error:
  i2c_stop();
  return err;
}

uint8_t PCA9956_pwm3(uint8_t i2cAddr, uint8_t id, uint8_t *val){
  return PCA9956_pwm(i2cAddr, id, val, 3);
}
