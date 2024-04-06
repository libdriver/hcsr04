/**
 * Copyright (C) LibDriver 2015-2021 All rights reserved
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
 * @file      stm32f407_driver_hcsr04_interface.c
 * @brief     stm32f407 driver hcsr04 interface source file
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

#include "driver_hcsr04_interface.h"
#include "delay.h"
#include "uart.h"
#include "wire.h"
#include "tim.h"
#include <stdarg.h>

/**
 * @brief timer var definition
 */
static uint64_t gs_ms = 0;        /**< ms */

/**
 * @brief     timer callback
 * @param[in] us is the timer cnt
 * @note      none
 */
static void gs_tim_irq(uint32_t us)
{
    gs_ms += us / 1000;
}

/**
 * @brief  interface timer init
 * @return status code
 *         - 0 success
 *         - 1 init failed
 * @note   none
 */
uint8_t hcsr04_interface_timer_init(void)
{
    /* timer init */
    if (tim_init(1000, gs_tim_irq) != 0)
    {
        return 1;
    }
    
    /* timer start */
    if (tim_start() != 0)
    {
        return 1;
    }
    
    return 0;
}

/**
 * @brief  interface trig init
 * @return status code
 *         - 0 success
 *         - 1 trig init failed
 * @note   none
 */
uint8_t hcsr04_interface_trig_init(void)
{
    return wire_clock_init();
}

/**
 * @brief  interface trig deinit
 * @return status code
 *         - 0 success
 *         - 1 trig deinit failed
 * @note   none
 */
uint8_t hcsr04_interface_trig_deinit(void)
{
    return wire_clock_deinit();
}

/**
 * @brief     interface trig write
 * @param[in] value is the written value
 * @return    status code
 *            - 0 success
 *            - 1 trig write failed
 * @note      none
 */
uint8_t hcsr04_interface_trig_write(uint8_t value)
{
    return wire_clock_write(value);
}

/**
 * @brief  interface echo init
 * @return status code
 *         - 0 success
 *         - 1 echo init failed
 * @note   none
 */
uint8_t hcsr04_interface_echo_init(void)
{
    return wire_init();
}

/**
 * @brief  interface echo deinit
 * @return status code
 *         - 0 success
 *         - 1 trig echo failed
 * @note   none
 */
uint8_t hcsr04_interface_echo_deinit(void)
{
    return wire_deinit();
}

/**
 * @brief      interface echo read
 * @param[out] *value points to a value buffer
 * @return     status code
 *             - 0 success
 *             - 1 echo read failed
 * @note       none
 */
uint8_t hcsr04_interface_echo_read(uint8_t *value)
{
    return wire_read(value);
}

/**
 * @brief      interface timestamp read
 * @param[out] *t points to a time structure
 * @return     status code
 *             - 0 success
 *             - 1 timestamp read failed
 * @note       none
 */
uint8_t hcsr04_interface_timestamp_read(hcsr04_time_t *t)
{
    t->millisecond = gs_ms;
    t->microsecond = tim_get_handle()->Instance->CNT;
    
    return 0;
}

/**
 * @brief     interface delay us
 * @param[in] us
 * @note      none
 */
void hcsr04_interface_delay_us(uint32_t us)
{
    delay_us(us);
}

/**
 * @brief     interface delay ms
 * @param[in] ms
 * @note      none
 */
void hcsr04_interface_delay_ms(uint32_t ms)
{
    delay_ms(ms);
}

/**
 * @brief     interface print format data
 * @param[in] fmt is the format data
 * @note      none
 */
void hcsr04_interface_debug_print(const char *const fmt, ...)
{
    char str[256];
    uint16_t len;
    va_list args;
    
    memset((char *)str, 0, sizeof(char) * 256); 
    va_start(args, fmt);
    vsnprintf((char *)str, 255, (char const *)fmt, args);
    va_end(args);
    
    len = strlen((char *)str);
    (void)uart_write((uint8_t *)str, len);
}
