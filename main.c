#define SDL_MAIN_HANDLED    
#define V_RES 640
#define H_RES 960

#include <unistd.h>
#include <stdio.h>
#include "lv_conf.h"
#include "lvgl/lvgl.h"

int main() {

    lv_init();

    lv_display_t * display1 = lv_sdl_window_create(H_RES, V_RES);
    if (display1 == NULL) {
        printf("Display initialisation failed!");
        goto error;
    }   
    lv_sdl_window_set_resizeable(display1, true);

    lv_obj_t * my_screen = lv_obj_create(NULL);
    lv_screen_load(my_screen);

    lv_obj_t * table = lv_table_create(my_screen);
    lv_obj_set_align(table, LV_ALIGN_BOTTOM_RIGHT);

    lv_table_set_row_cnt(table, 3);
    lv_table_set_col_cnt(table, 3);
    lv_table_set_cell_value(table, 0, 0, "Yo!");

    while (1) {      
        uint32_t wait_ms = lv_timer_handler();

        if (wait_ms < 1) {
            wait_ms = 1;
        }

        usleep(wait_ms * 1000);
        //printf("All Good!\n");
    }

    error:
        return 1;
} 