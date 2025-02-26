/*
 * Copyright (c) 2006-2025, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-02-25     CYFS         first version
 */

#include <rtthread.h>
#include <rtdevice.h>


#include "p3t1755.h"

#define DBG_TAG "P3T1755"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>

#define P3T1755_ADDR                 0x90

enum
{
	P3T1755_REG_TEMP = 0x00,
	P3T1755_REG_CONFIG = 0x01,
	P3T1755_REG_TL = 0x02,
	P3T1755_REG_TH = 0x03
};
static struct rt_i2c_bus_device *p3t1755_i2c_bus = RT_NULL;     


int p3t1755_init(void)
{
	p3t1755_i2c_bus = (struct rt_i2c_bus_device *)rt_device_find(P3T1755_I2C_BUS_NAME);
	if (p3t1755_i2c_bus == RT_NULL)
	{
		LOG_E("can't find %s device!\n", P3T1755_I2C_BUS_NAME);
		return -RT_ERROR;
	}
	LOG_I("p3t1755 init success\n");
	return RT_EOK;
}



int p3t1755_read(uint8_t *data, uint8_t len)
{
	rt_uint8_t cmd[1] ={P3T1755_REG_TEMP};
	struct rt_i2c_msg msgs[2];
	msgs[0].addr = P3T1755_ADDR;
	msgs[0].buf = cmd;
	msgs[0].flags = RT_I2C_WR;
	msgs[0].len = 1;
	msgs[1].addr = P3T1755_ADDR;
	msgs[1].buf = data;
	msgs[1].flags = RT_I2C_RD;
	msgs[1].len = len;
	if (rt_i2c_transfer(p3t1755_i2c_bus, msgs, 2) == 2)
	{
		return RT_EOK;
	}
	return -RT_ERROR;
}


int p3t1755_read_temp(float * temp)
{
	uint8_t data[2];
	if(p3t1755_read(data, 2) == RT_EOK)
	{
		*temp = (float)((data[0] << 8) | data[1]) / 256.0;
		return RT_EOK;
	}
	return -RT_ERROR;
}
