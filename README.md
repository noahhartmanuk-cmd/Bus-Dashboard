# TFL Bus app native for Linux!

This is very much not complete however I have got LVGL set up and the basic layout set up!

Do bear in mind that this only works on Linux systems as of yet I have not baked in Windows support, however it may work on mac and if you are cool enough to run a bsd system it may run on that but for both cases you need to compile from source and it has not been tested to work :)

## How to run:

### Option 1: Compile from source

#### Ensure that you have the necessary packages: cmake and sdl2

* Step 1: run git clone on `https://github.com/noahhartmanuk-cmd/Bus-Dashboard` with `git clone https://github.com/noahhartmanuk-cmd/Bus-Dashboard`

* Step 2: move into that directory with `cd Bus_Dashboard/`

* Step 3: build with cmake with `cmake -S . -B build` then `cmake --build build`

* Step 4: ensure the binary is executable with `chmod +x build/bus-dashboard`

* Finally: run the binary with `build/bus-dashboard`

### Option 2: Run Appimage

#### Ensure that you have sdl2 installed, some distros ship with it e.g. Manjaro and some don't e.g. Fedora

* Step 1: Download latest [Appimage](https://github.com/noahhartmanuk-cmd/Bus-Dashboard/releases/)
* Step 2: Make executable with `chmod +x /path/to/appimage`
