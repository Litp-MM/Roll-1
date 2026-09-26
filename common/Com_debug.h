#ifndef __COM_DEBUG_H__
#define __COM_DEBUG_H__

#include "usart.h"
#include "stdio.h"
#include "stdarg.h"
#include "string.h"

//日志输出打印在CPU运行上非常占用资源=》通过比特率计算
//打印10字节左右大概需要1ms，非常影响飞机的飞行
//所以在后续飞机需要正常飞行的时候，需要关闭日志输出
//设置一个日志输出打印开关
#define DEBUG_LOG_ENABLE 1  
// 1 = 开启日志打印，0 = 关闭日志打印 

#ifdef DEBUG_LOG_ENABLE

//使用宏定义的方式，只打印文件名称，不打印路径名称
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define __FILE_NAME (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

//使用宏定义的方式能实现打印日志之前先添加并且输出文件名和行号，方便调试
#define debug_printf(format,...) printf("[%s:%d]  "format, __FILE_NAME, __LINE__, ##__VA_ARGS__)

#else
//如果没有开启日志输出打印开关，那么debug_printf就不做任何事情
#define debug_printf(format,...)
#endif

#endif //
