/**
 * Copyright (c) 2015 - present LibDriver All rights reserved
 * 
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. 
 *
 * @file      driver_hcsr04_interface.h
 * @brief     driver hcsr04 interface header file
 * @version   2.0.0
 * @author    Shifeng Li
 * @date      2021-04-15
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2021/04/15  <td>2.0      <td>Shifeng Li  <td>format the code
 * <tr><td>2020/12/21  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */

#ifndef DRIVER_HCSR04_INTERFACE_H
#define DRIVER_HCSR04_INTERFACE_H

#include "driver_hcsr04.h"

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @defgroup hcsr04_interface_driver hcsr04 interface driver function
 * @brief    hcsr04 interface driver modules
 * @ingroup  hcsr04_driver
 * @{
 */

/**
 * @brief  interface trig init
 * @return status code
 *         - 0 success
 *         - 1 trig init failed
 * @note   none
 */
uint8_t hcsr04_interface_trig_init(void);

/**
 * @brief  interface trig deinit
 * @return status code
 *         - 0 success
 *         - 1 trig deinit failed
 * @note   none
 */
uint8_t hcsr04_interface_trig_deinit(void);

/**
 * @brief     interface trig write
 * @param[in] value written value
 * @return    status code
 *            - 0 success
 *            - 1 trig write failed
 * @note      none
 */
uint8_t hcsr04_interface_trig_write(uint8_t value);

/**
 * @brief  interface echo init
 * @return status code
 *         - 0 success
 *         - 1 echo init failed
 * @note   none
 */
uint8_t hcsr04_interface_echo_init(void);

/**
 * @brief  interface echo deinit
 * @return status code
 *         - 0 success
 *         - 1 trig echo failed
 * @note   none
 */
uint8_t hcsr04_interface_echo_deinit(void);

/**
 * @brief      interface echo read
 * @param[out] *value pointer to a value buffer
 * @return     status code
 *             - 0 success
 *             - 1 echo read failed
 * @note       none
 */
uint8_t hcsr04_interface_echo_read(uint8_t *value);

/**
 * @brief      interface timestamp read
 * @param[out] *t pointer to a time structure
 * @return     status code
 *             - 0 success
 *             - 1 timestamp read failed
 * @note       none
 */
uint8_t hcsr04_interface_timestamp_read(hcsr04_time_t *t);

/**
 * @brief     interface delay us
 * @param[in] us time
 * @note      none
 */
void hcsr04_interface_delay_us(uint32_t us);

/**
 * @brief     interface delay ms
 * @param[in] ms time
 * @note      none
 */
void hcsr04_interface_delay_ms(uint32_t ms);

/**
 * @brief     interface print format data
 * @param[in] fmt format data
 * @note      none
 */
void hcsr04_interface_debug_print(const char *const fmt, ...);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
