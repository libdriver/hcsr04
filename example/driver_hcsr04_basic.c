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
 * @file      driver_hcsr04_basic.c
 * @brief     driver hcsr04 basic source file
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

#include "driver_hcsr04_basic.h"

static hcsr04_handle_t gs_handle;        /**< hcsr04 handle */

/**
 * @brief  basic example init
 * @return status code
 *         - 0 success
 *         - 1 init failed
 * @note   none
 */
uint8_t hcsr04_basic_init(void)
{
    uint8_t res;
    
    /* link interface function */
    DRIVER_HCSR04_LINK_INIT(&gs_handle, hcsr04_handle_t);
    DRIVER_HCSR04_LINK_TRIG_INIT(&gs_handle, hcsr04_interface_trig_init);
    DRIVER_HCSR04_LINK_TRIG_DEINIT(&gs_handle, hcsr04_interface_trig_deinit);
    DRIVER_HCSR04_LINK_TRIG_WRITE(&gs_handle, hcsr04_interface_trig_write);
    DRIVER_HCSR04_LINK_ECHO_INIT(&gs_handle, hcsr04_interface_echo_init);
    DRIVER_HCSR04_LINK_ECHO_DEINIT(&gs_handle, hcsr04_interface_echo_deinit);
    DRIVER_HCSR04_LINK_ECHO_WRITE(&gs_handle, hcsr04_interface_echo_read);
    DRIVER_HCSR04_LINK_TIMESTAMP_READ(&gs_handle, hcsr04_interface_timestamp_read);
    DRIVER_HCSR04_LINK_DELAY_MS(&gs_handle, hcsr04_interface_delay_ms);
    DRIVER_HCSR04_LINK_DELAY_US(&gs_handle, hcsr04_interface_delay_us);
    DRIVER_HCSR04_LINK_DEBUG_PRINT(&gs_handle, hcsr04_interface_debug_print);
    
    /* hcsr04 init */
    res = hcsr04_init(&gs_handle);
    if (res != 0)
    {
        hcsr04_interface_debug_print("hcsr04: init failed.\n");
       
        return 1;
    }

    return 0;
}

/**
 * @brief      basic example read
 * @param[out] *m points to a distance buffer
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 * @note       none
 */
uint8_t hcsr04_basic_read(float *m)
{
    uint32_t time_us;
    
    /* read distance */
    if (hcsr04_read(&gs_handle, (uint32_t *)&time_us, m) != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * @brief  basic example deinit
 * @return status code
 *         - 0 success
 *         - 1 deinit failed
 * @note   none
 */
uint8_t hcsr04_basic_deinit(void)
{
    /* close hcsr04 */
    if (hcsr04_deinit(&gs_handle) != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
