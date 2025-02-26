/*
 * Copyright (c) 2006-2025, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-02-25     CYFS         first version
 */

#include "nxp_p3t1755_sensor_v2.h"

#define DBG_ENABLE
#define DBG_LEVEL DBG_LOG
#define DBG_SECTION_NAME  "sensor.nxp.p3t1755"
#define DBG_COLOR
#include <rtdbg.h>

#include "P3T1755.h"

 

static RT_SIZE_TYPE _p3t1755_fetch_data(rt_sensor_t sensor, rt_sensor_data_t buf, rt_size_t len)
{
	struct rt_sensor_data *data = buf;
	float temp = 0;
	if (p3t1755_read_temp(&temp) == RT_EOK)
	{
		data->type = RT_SENSOR_TYPE_TEMP;
		data->data.temp = temp;
		data->timestamp = rt_sensor_get_ts();
		return 1;
	}
	return 0;
}

static rt_err_t _p3t1755_control(struct rt_sensor_device *sensor, int cmd, void *args)
{
	return -RT_ERROR;
}

static struct rt_sensor_ops p3t1755_ops =
{
	.fetch_data = _p3t1755_fetch_data,
	.control = _p3t1755_control,

};



int rt_hw_p3t1755_init(const char *name, struct rt_sensor_config *cfg)
{
	rt_sensor_t sensor_temp = RT_NULL;

	sensor_temp = rt_calloc(1, sizeof(struct rt_sensor_device));
	if (sensor_temp == RT_NULL)
	{
		LOG_E("Can't allocate memory for p3t1755 sensor device on '%s' ", name);
		return -RT_ENOMEM;
	}

	sensor_temp->info.type       = RT_SENSOR_TYPE_TEMP;
	sensor_temp->info.vendor     = RT_SENSOR_VENDOR_UNKNOWN;
	sensor_temp->info.unit       = RT_SENSOR_UNIT_CELSIUS;
	sensor_temp->info.intf_type  = RT_SENSOR_INTF_I2C;
	sensor_temp->info.name 	 = "p3t1755";

	sensor_temp->info.acquire_min = 100;
	sensor_temp->info.accuracy.resolution = 0.01;
    sensor_temp->info.accuracy.error = 0.3;
    sensor_temp->info.scale.range_min = -40.0;
    sensor_temp->info.scale.range_max = 85.0;

	

	rt_memcpy(&sensor_temp->config, cfg, sizeof(struct rt_sensor_config));
	sensor_temp->ops = &p3t1755_ops;

	p3t1755_init();

	if (rt_hw_sensor_register(sensor_temp, name, RT_DEVICE_FLAG_RDWR, RT_NULL) != RT_EOK)
	{
		LOG_E("p3t1755 sensor register failed");
		return -RT_ERROR;
	}

	LOG_I("p3t1755 sensor init success");
	return RT_EOK;

}

