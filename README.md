# P3T1755

## 简介

本软件包是为 NXP P3T1755 温度计提供的通用传感器驱动包。通过使用此软件包，开发者可以快速的利用 RT-Thread 将此传感器驱动起来。

本篇文档主要内容如下：

- 传感器介绍
- 支持情况
- 使用说明

## 传感器介绍

P3T1755 是 NXP公司的一款温度到数字转换器，尺寸小巧。

## 支持情况

| 包含设备     | 温度计 |
| ------------ | ------ |
| **通讯接口** |        |
| IIC          | √      |
| I2C3         | X      |
| **工作模式** |        |
| 轮询         | √      |
| 中断         |        |
| FIFO         |        |

## 使用说明

### 依赖

- RT-Thread 4.0.0+
- Sensor 组件
- IIC 驱动：P3T1755 设备使用 IIC 进行数据通讯，需要系统 IIC 驱动框架支持；

### 获取软件包

使用 P3T1755 软件包需要在 RT-Thread 的包管理中选中它，具体路径如下：

```
/* TODO:完善路径 */
(i2c0) The name of the I2C bus used by P3T1755
[ ] Enable sensor divce framework
    Version (latest)  --->
```

### 使用软件包

P3T1755 软件包初始化函数如下所示：

```
int p3t1755_init(void)
```

#### 初始化示例

```c
#include "p3t1755.h"

static void p3t1755_test(int argc, char *argv[])
{
    p3t1755_init();
    float temp = 0;
    if (p3t1755_read_temp(&temp) == RT_EOK)
    {
        rt_kprintf("temp:%.2f\n", temp);
    }

}

MSH_CMD_EXPORT(p3t1755_test, i2c aht10 sample);
```

## 注意事项

暂无

## 联系人信息

维护人:

- [CYFS](https://github.com/CYFS3) 
