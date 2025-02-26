/*
 * Copyright (c) 2006-2025, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-02-25     CYFS         first version
 */

#ifndef __P3T1755_H__
#define __P3T1755_H__



int p3t1755_init(void);
int p3t1755_read(uint8_t *data, uint8_t len);
int p3t1755_read_temp(float * temp);

#endif /* __P3T1755_H__ */
