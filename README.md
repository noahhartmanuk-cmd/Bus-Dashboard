# TFL Bus app native for Linux!

This is very much not complete however I have got LVGL set up and the basic layout set up!

## How to run:

### Option 1: Compile from source

#### Ensure that you have the necessary packages: cmake and sdl2

* Step 1: run git clone on `https://github.com/noahhartmanuk-cmd/Bus-Dashboard` with `git clone https://github.com/noahhartmanuk-cmd/Bus-Dashboard`

* Step 2: move into that directory with `cd Bus_Dashboard/`

* Step 3: build with cmake with `cmake -S . -B build` then `cmake --build build`

* Step 4: ensure the binary is executable with `chmod +x build/bus-dashboard`

* Finally: run the binary with `build/bus-dashboard`

