# VEX Robotics Team 1516A

C++ robot software for Team 1516A's VEX V5 Push Back project, built with **PROS** and **LemLib**. This repository contains drivetrain configuration, driver controls, and inertial-sensor initialization.

## Current implementation

- Six-motor drivetrain with explicit port assignments and motor directions.
- Arcade driver control through LemLib, with separate exponential throttle and steering curves.
- IMU calibration, chassis calibration, and an initial pose of `(0, 0, 0)`.
- Live IMU heading display on the V5 Brain LCD.
- Lateral and angular PID settings configured for future motion routines.

**Status:** driver control and sensor setup are implemented. The `autonomous()` callback is currently empty; this snapshot does not include an autonomous competition routine.

## Code organization

| File | Purpose |
| --- | --- |
| [`pushback1516A/src/main.cpp`](pushback1516A/src/main.cpp) | Startup calibration, competition callbacks, arcade driving, and heading display |
| [`pushback1516A/src/globals.cpp`](pushback1516A/src/globals.cpp) | Motor ports, drivetrain geometry, IMU, PID settings, drive curves, and chassis |
| [`pushback1516A/include/globals.h`](pushback1516A/include/globals.h) | Shared robot configuration declarations |
| [`pushback1516A/project.pros`](pushback1516A/project.pros) | Project metadata and dependencies |

## Hardware configuration

| Component | Configuration in `globals.cpp` |
| --- | --- |
| Left motors, back/middle/front | Ports `10`, `-9`, `8` |
| Right motors, back/middle/front | Ports `-18`, `19`, `-20` |
| Motor cartridges | Blue |
| Inertial sensor | Smart Port `1` |
| Drivetrain model | 3.25-inch omni wheels, 450 RPM, 25-inch track width |
| Tracking wheels | No dedicated tracking wheels configured |

Negative ports indicate reversed motors. Check these values against the physical robot before uploading.

## Build and run

Install the [PROS toolchain](https://pros.cs.purdue.edu/v5/getting-started/index.html), then open the nested `pushback1516A` project. The manifest records PROS kernel **4.2.1**, LemLib **0.5.6**, and liblvgl **9.2.0**.

```sh
cd pushback1516A
pros make
pros upload
```

Keep the robot stationary during IMU calibration. Driver control reads the controller and updates the heading display with a 10 ms loop delay.

## Testing and results

The heading readout supports observing sensor behavior on the robot. Recorded measurements, competition results, and a demonstration video have not yet been added.

## Project code and credits

Robot-specific application code is in `main.cpp`, `globals.cpp`, and `globals.h`. The project uses the [PROS](https://pros.cs.purdue.edu/) runtime and [LemLib](https://lemlib.readthedocs.io/) chassis, motion-control, and drive-curve APIs. These libraries and bundled LVGL and fmt dependencies are external projects; their included notices and licenses apply.
