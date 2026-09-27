#include "App_FreeRTOS_task.h"

//STM32F103C8T6 => RRAM=20KB=20480B=5120*4B=5120个32位数据 => 分配12k给FreeRTOS使用，剩余8k给用户使用

void task1(void *args);
void task2(void *args);

//最小推荐填写128=》128*4=512字节
#define TASK1_STACK_SIZE 128
#define TASK2_STACK_SIZE 128
//任务优先级，数值越大优先级越高 =》最大优先级为configMAX_PRIORITIES-1=4 
//  =>不推荐使用最小优先级0（有空闲任务）和最大优先级4（系统任务），推荐使用1~3
#define TASK1_PRIORITY 1
#define TASK2_PRIORITY 2
TaskHandle_t task1_handle;
TaskHandle_t task2_handle;

/*启用FreeRTOS操作系统*/
void App_FreeRTOS_start(void){
    //1.创建任务
    xTaskCreate(task1, "App_FreeRTOS_task_1", TASK1_STACK_SIZE, NULL, TASK1_PRIORITY, &task1_handle);
    xTaskCreate(task2, "App_FreeRTOS_task_2", TASK2_STACK_SIZE, NULL, TASK2_PRIORITY, &task2_handle);
    //2.启动调度器


}





void task1(void *args){
    //task1任务启动之后，不断执行的内容
    while(1){
        debug_printf("task1 is running\r\n");
        vTaskDelay(1000);//延时1秒,且不占用CPU资源
    }
}

void task2(void *args){
    //task2任务启动之后，不断执行的内容
    while(1){
        debug_printf("task2 is running\r\n");
        vTaskDelay(1000);//延时1秒,且不占用CPU资源
    }
}
