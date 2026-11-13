#define V_RES 300
#define H_RES 300

#include <unistd.h>
#include <stdio.h>
#include "lv_conf.h"
#include "lvgl/lvgl.h"

int main() {

    lv_init();

    lv_display_t * display1 = lv_x11_window_create("X11", H_RES, V_RES);
    if (display1 == NULL) {
        printf("Display initialisation failed!");
        return 1;
    }   

    lv_obj_t * my_screen = lv_obj_create(NULL);
    lv_screen_load(my_screen);

    

    while (1) {      
        uint32_t wait_ms = lv_timer_handler();

        if (wait_ms < 1) {
            wait_ms = 1;
        }

        usleep(wait_ms * 1000);
        printf("All Good!");
    }
} 