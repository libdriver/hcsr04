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
 * @file      driver_hcsr04_read_test.c
 * @brief     driver hcsr04 read test source file
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

#include "driver_hcsr04_read_test.h"

static hcsr04_handle_t gs_handle;        /**< hcsr04 handle */

/**
 * @brief     read test
 * @param[in] times is the read times
 * @return    status code
 *            - 0 success
 *            - 1 test failed
 * @note      none
 */
uint8_t hcsr04_read_test(uint32_t times)
{
    uint8_t res;
    uint32_t i;
    hcsr04_info_t info;
    
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
    
    /* get info */
    res = hcsr04_info(&info);
    if (res != 0)
    {
        hcsr04_interface_debug_print("hcsr04: get info failed.\n");
       
        return 1;
    }
    else
    {
        /* print chip information */
        hcsr04_interface_debug_print("hcsr04: chip is %s.\n", info.chip_name);
        hcsr04_interface_debug_print("hcsr04: manufacturer is %s.\n", info.manufacturer_name);
        hcsr04_interface_debug_print("hcsr04: interface is %s.\n", info.interface);
        hcsr04_interface_debug_print("hcsr04: driver version is %d.%d.\n", info.driver_version / 1000, (info.driver_version % 1000) / 100);
        hcsr04_interface_debug_print("hcsr04: min supply voltage is %0.1fV.\n", info.supply_voltage_min_v);
        hcsr04_interface_debug_print("hcsr04: max supply voltage is %0.1fV.\n", info.supply_voltage_max_v);
        hcsr04_interface_debug_print("hcsr04: max current is %0.2fmA.\n", info.max_current_ma);
        hcsr04_interface_debug_print("hcsr04: max temperature is %0.1fC.\n", info.temperature_max);
        hcsr04_interface_debug_print("hcsr04: min temperature is %0.1fC.\n", info.temperature_min);
    }
    
    /* hscr04 init */
    res = hcsr04_init(&gs_handle);
    if (res != 0)
    {
        hcsr04_interface_debug_print("hcsr04: init failed.\n");
       
        return 1;
    }
    
    /* start read test */
    hcsr04_interface_debug_print("hcsr04: start read test.\n");
    for (i = 0; i < times; i++)
    {
        uint32_t time_us;
        float m;
        
        /* read distance */
        res = hcsr04_read(&gs_handle, (uint32_t *)&time_us, (float *)&m);
        if (res != 0)
        {
            hcsr04_interface_debug_print("hcsr04: read failed.\n");
            (void)hcsr04_deinit(&gs_handle);
            
            return 1;
        }
        m *= 100.0f;
        hcsr04_interface_debug_print("hcsr04: distance is %fcm.\n", m);
        hcsr04_interface_delay_ms(2000);
    }
    
    /* finish read test */
    hcsr04_interface_debug_print("hcsr04: finish read test.\n");
    (void)hcsr04_deinit(&gs_handle);
    
    return 0;
}
