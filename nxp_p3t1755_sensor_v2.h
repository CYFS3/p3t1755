/*
 * Copyright (c) 2006-2025, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author          Notes
 * 2025-02-25     CYFS            the first version.
 *
 */

#ifndef __NXP_P3T1755_SENSOR_V2_H__
#define __NXP_P3T1755_SENSOR_V2_H__

#include <rthw.h>
#include <rtthread.h>
#include <rtdevice.h>

#if RT_VER_NUM < 0x50000
#include <stdint.h>
#endif

#if defined(RT_VERSION_CHECK)
    #if (RTTHREAD_VERSION >= RT_VERSION_CHECK(5, 0, 2))
        #define RT_SIZE_TYPE rt_ssize_t
#else
        #define RT_SIZE_TYPE rt_size_t
#endif
#endif


int rt_hw_p3t1755_init(const char *name, struct rt_sensor_config *cfg);

#endif /* __NXP_P3T1755_SENSOR_V2_H__ */
