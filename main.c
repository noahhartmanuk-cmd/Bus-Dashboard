#define SDL_MAIN_HANDLED    
#define V_RES 640
#define H_RES 960

#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include "lv_conf.h"
#include "lvgl/lvgl.h"
#include "buses.h"

static lv_indev_t * mouse;
static lv_indev_t * mousewheel;
static lv_indev_t * keyboard;

typedef struct Stop {
    char *full_name;
    char *abrv;
    int is_fave;
} stop;

stop* get_fave_stops(void);

int main() {

    lv_init();

    lv_display_t * display1 = lv_sdl_window_create(H_RES, V_RES);
    if (display1 == NULL) {
        printf("Display initialisation failed!");
        goto error;
    }
    lv_sdl_window_set_resizeable(display1, false);

    mouse = lv_sdl_mouse_create();
    mousewheel = lv_sdl_mousewheel_create();
    keyboard = lv_sdl_keyboard_create();

    lv_obj_t * my_screen = lv_obj_create(NULL);
    lv_screen_load(my_screen);

    lv_obj_t * timetable = lv_table_create(my_screen);
    lv_obj_set_align(timetable, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_set_size(timetable, 760, 540);
    /*
    lv_table_set_row_cnt(timetable, 3);
    lv_table_set_col_cnt(timetable, 3);
    lv_table_set_cell_value(timetable, 0, 0, "Yo!");
    */
    lv_obj_t * fave_buses = lv_table_create(my_screen);
    lv_obj_set_align(fave_buses, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_set_size(fave_buses, 200, 640);

    lv_obj_t * current_stop = lv_label_create(my_screen);
    lv_obj_set_y(current_stop, 50);
    lv_obj_set_x(current_stop, 200);
    lv_obj_set_size(current_stop, 760, 60);
    lv_obj_set_style_text_font(current_stop, LV_FONT_DEFAULT_MONTSERRAT_38, 0);

    lv_obj_t * search_bar = lv_textarea_create(my_screen);
    lv_obj_set_align(search_bar, LV_ALIGN_TOP_RIGHT);
    lv_obj_set_size(search_bar, 760, 40);
  
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

/*
stop* get_fave_stops(void) {
    struct stat info;
    char dir[100];
    snprintf(dir, sizeof(dir), "%s/.buses", getenv("HOME"));

    while (stat(dir, &info) == -1) {
        if (errno == ENOENT) {
            mkdir(dir, 0777);
        }
        printf("There was an error with stat!");
        return NULL;
    }

    if (!S_ISDIR(info.st_mode)) {
        printf("~/.buses is not a directory: fix");
        return NULL;
    }

    char path[100];
    snprintf(path, sizeof(dir), "%s/fave.busses", dir);


    if (stat(dir, &info) == -1) {
        printf("There was an error with stat!");
        return NULL;
    }

    if (!S_ISREG(info.st_mode)) {
        printf("~/.buses/fave.busses is not a file: fix");
        return NULL;
    }

    FILE * fptr = fopen(dir, "r");
    if (fptr == NULL) {
        printf("Error opening %s", dir);
        return NULL;
    }   
}
*/