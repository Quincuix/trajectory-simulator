# 2D Projectile Trajectory Simulator

A C++ physics simulator that models projectile motion under gravity and air resistance, with live animated visualization.

## What it does

- Simulates a projectile launched with an initial velocity, affected by gravity and quadratic air drag
- Uses RK4 (4th-order Runge-Kutta) integration for numerically accurate motion, rather than simple Euler integration
- Renders the motion live in an animated window using SFML
- Exports trajectory data to CSV, with a Python (matplotlib) script for plotting the arc separately

## Physics model

- **Gravity:** constant downward acceleration (-9.8 m/s²)
- **Drag:** calculated using the real drag equation, `F = 0.5 * air_density * v^2 * drag_coefficient * area`, opposing the direction of motion. This scales with velocity squared, unlike a simplified linear approximation.
- **Integration:** RK4 samples the rate of change four times per time step (start, two midpoints, end) and combines them with a weighted average, which is significantly more accurate than Euler integration for the same time step size — especially when forces change rapidly.

## What I learned

This was my first real C++ project. Along the way I learned:
- Core C++ (variables, loops, functions, structs)
- Why numerical integration method choice matters, and when RK4's accuracy advantage actually shows up (mainly at larger time steps or rapidly-changing forces — at this simulation's scale, RK4 and Euler look visually similar, which is itself a useful finding)
- Working with a real graphics library (SFML) and the basics of a render loop
- Git/GitHub workflow for version control

## Limitations / possible extensions

- 2D only — a real trajectory/orbital mechanics simulator would need 3D
- Assumes constant air density (real air density decreases with altitude)
- Single rigid body — no rotation, wind, or multi-stage effects
- Fixed drag coefficient and area — could be extended to accept different projectile shapes

## Running it

Requires g++ and SFML:sudo apt install libsfml-dev
g++ window_test.cpp -o window_test -lsfml-graphics -lsfml-window -lsfml-system
./window_test
