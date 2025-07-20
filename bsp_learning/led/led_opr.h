//This is a common header for different embedded boards
#ifndef LED_OPR_H
#define LED_OPR_H

struct board_led_operations
{
    void (*led_init)(int which); //which led on the board to init
    void (*led_cntl)(int which, int status); //status=1 means on, status=0 means off
};

struct board_led_operations* get_board_led_operations_struct(void);

#endif
