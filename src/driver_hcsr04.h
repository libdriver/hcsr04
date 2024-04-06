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
 * @file      driver_hcsr04.h
 * @brief     driver hcsr04 header file
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

#ifndef DRIVER_HCSR04_H
#define DRIVER_HCSR04_H

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C"{
#endif

/**
 * @defgroup hcsr04_driver hcsr04 driver function
 * @brief    hcsr04 driver modules
 * @{
 */

/**
 * @addtogroup hcsr04_base_driver
 * @{
 */

/**
 * @brief hcsr04 read retry times definition
 */
#ifndef HCSR04_READ_RETRY_TIMES
    #define HCSR04_READ_RETRY_TIMES 3        /**< retry 3 times */
#endif

/**
 * @brief hcsr04 time structure definition
 */
typedef struct hcsr04_time_s
{
    uint64_t microsecond;        /**< microsecond */
    uint32_t millisecond;        /**< millisecond */
} hcsr04_time_t;

/**
 * @brief hcsr04 handle structure definition
 */
typedef struct hcsr04_handle_s
{
    uint8_t (*trig_init)(void);                            /**< point to a trig_init function address */
    uint8_t (*trig_deinit)(void);                          /**< point to a trig_deinit function address */
    uint8_t (*trig_write)(uint8_t value);                  /**< point to a trig_write function address */
    uint8_t (*echo_init)(void);                            /**< point to an echo_init function address */
    uint8_t (*echo_deinit)(void);                          /**< point to an echo_deinit function address */
    uint8_t (*echo_read)(uint8_t *value);                  /**< point to an echo_read function address */
    uint8_t (*timestamp_read)(hcsr04_time_t *time);        /**< point to a timestamp_read function address */
    void (*delay_us)(uint32_t ms);                         /**< point to a delay_us function address */
    void (*delay_ms)(uint32_t ms);                         /**< point to a delay_ms function address */
    void (*debug_print)(const char *const fmt, ...);       /**< point to a debug_print function address */
    uint8_t inited;                                        /**< inited flag */
} hcsr04_handle_t;

/**
 * @brief hcsr04 information structure definition
 */
typedef struct hcsr04_info_s
{
    char chip_name[32];                /**< chip name */
    char manufacturer_name[32];        /**< manufacturer name */
    char interface[8];                 /**< chip interface name */
    float supply_voltage_min_v;        /**< chip min supply voltage */
    float supply_voltage_max_v;        /**< chip max supply voltage */
    float max_current_ma;              /**< chip max current */
    float temperature_min;             /**< chip min operating temperature */
    float temperature_max;             /**< chip max operating temperature */
    uint32_t driver_version;           /**< driver version */
} hcsr04_info_t;

/**
 * @}
 */

/**
 * @defgroup hcsr04_link_driver hcsr04 link driver function
 * @brief    hcsr04 link driver modules
 * @ingroup  hcsr04_driver
 * @{
 */

/**
 * @brief     initialize hcsr04_handle_t structure
 * @param[in] HANDLE points to an hcsr04 handle structure
 * @param[in] STRUCTURE is hcsr04_handle_t
 * @note      none
 */
#define DRIVER_HCSR04_LINK_INIT(HANDLE, STRUCTURE)      memset(HANDLE, 0, sizeof(STRUCTURE))

/**
 * @brief     link trig_init function
 * @param[in] HANDLE points to an hcsr04 handle structure
 * @param[in] FUC points to a trig_init function address
 * @note      none
 */
#define DRIVER_HCSR04_LINK_TRIG_INIT(HANDLE, FUC)      (HANDLE)->trig_init = FUC

/**
 * @brief     link trig_deinit function
 * @param[in] HANDLE points to an hcsr04 handle structure
 * @param[in] FUC points to a trig_deinit function address
 * @note      none
 */
#define DRIVER_HCSR04_LINK_TRIG_DEINIT(HANDLE, FUC)    (HANDLE)->trig_deinit = FUC

/**
 * @brief     link trig_write function
 * @param[in] HANDLE points to an hcsr04 handle structure
 * @param[in] FUC points to a trig_write function address
 * @note      none
 */
#define DRIVER_HCSR04_LINK_TRIG_WRITE(HANDLE, FUC)     (HANDLE)->trig_write = FUC

/**
 * @brief     link echo_init function
 * @param[in] HANDLE points to an hcsr04 handle structure
 * @param[in] FUC points to an echo_init function address
 * @note      none
 */
#define DRIVER_HCSR04_LINK_ECHO_INIT(HANDLE, FUC)      (HANDLE)->echo_init = FUC

/**
 * @brief     link echo_deinit function
 * @param[in] HANDLE points to an hcsr04 handle structure
 * @param[in] FUC points to an echo_deinit function address
 * @note      none
 */
#define DRIVER_HCSR04_LINK_ECHO_DEINIT(HANDLE, FUC)    (HANDLE)->echo_deinit = FUC

/**
 * @brief     link echo_read function
 * @param[in] HANDLE points to an hcsr04 handle structure
 * @param[in] FUC points to an echo_read function address
 * @note      none
 */
#define DRIVER_HCSR04_LINK_ECHO_WRITE(HANDLE, FUC)     (HANDLE)->echo_read = FUC

/**
 * @brief     link timestamp_read function
 * @param[in] HANDLE points to an hcsr04 handle structure
 * @param[in] FUC points to a timestamp_read function address
 * @note      none
 */
#define DRIVER_HCSR04_LINK_TIMESTAMP_READ(HANDLE, FUC) (HANDLE)->timestamp_read = FUC

/**
 * @brief     link delay_ms function
 * @param[in] HANDLE points to an hcsr04 handle structure
 * @param[in] FUC points to a delay_ms function address
 * @note      none
 */
#define DRIVER_HCSR04_LINK_DELAY_MS(HANDLE, FUC)       (HANDLE)->delay_ms = FUC

/**
 * @brief     link delay_us function
 * @param[in] HANDLE points to an hcsr04 handle structure
 * @param[in] FUC points to a delay_us function address
 * @note      none
 */
#define DRIVER_HCSR04_LINK_DELAY_US(HANDLE, FUC)       (HANDLE)->delay_us = FUC

/**
 * @brief     link debug_print function
 * @param[in] HANDLE points to an hcsr04 handle structure
 * @param[in] FUC points to a debug_print function address
 * @note      none
 */
#define DRIVER_HCSR04_LINK_DEBUG_PRINT(HANDLE, FUC)    (HANDLE)->debug_print = FUC

/**
 * @}
 */

/**
 * @defgroup hcsr04_base_driver hcsr04 base driver function
 * @brief    hcsr04 base driver modules
 * @ingroup  hcsr04_driver
 * @{
 */

/**
 * @brief      get chip's information
 * @param[out] *info points to an hcsr04 info structure
 * @return     status code
 *             - 0 success
 *             - 2 handle is NULL
 * @note       none
 */
uint8_t hcsr04_info(hcsr04_info_t *info);

/**
 * @brief     initialize the chip
 * @param[in] *handle points to an hcsr04 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 trig or echo init failed
 *            - 2 handle is NULL
 *            - 3 linked functions is NULL
 * @note      none
 */
uint8_t hcsr04_init(hcsr04_handle_t *handle);

/**
 * @brief     close the chip
 * @param[in] *handle points to an hcsr04 handle structure
 * @return    status code
 *            - 0 success
 *            - 1 trig or echo deinit failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 * @note      none
 */
uint8_t hcsr04_deinit(hcsr04_handle_t *handle);

/**
 * @brief      read the distance
 * @param[in]  *handle points to an hcsr04 handle structure
 * @param[out] *time_us points to a us buffer
 * @param[out] *m points to a distance buffer
 * @return     status code
 *             - 0 success
 *             - 1 read failed
 *             - 2 handle is NULL
 *             - 3 handle is not initialized
 * @note       none
 */
uint8_t hcsr04_read(hcsr04_handle_t *handle, uint32_t *time_us, float *m);

/**
 * @}
 */

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
