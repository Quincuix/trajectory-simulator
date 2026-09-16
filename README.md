# 2D Projectile Trajectory Simulator

A C++ simulator that models a projectile's flight under gravity and air resistance, with a live animated view of the trajectory.

## Overview

I built this to teach myself C++ and get some hands-on numerical simulation experience ahead of studying aerospace engineering. It models a 2D projectile subject to gravity and drag, using RK4 integration, and renders the motion live with SFML.

## Physics

- Gravity is constant (-9.8 m/s²)
- Drag uses the actual drag equation (0.5 * air density * v² * drag coefficient * area), so it scales with speed squared rather than being a flat percentage each step
- Motion is integrated using RK4 instead of basic Euler stepping, since RK4 samples the rate of change at four points per step instead of one, which reduces error, especially when forces change quickly within a step

At the timestep and speeds I'm using here, Euler and RK4 end up looking almost identical. This is because RK4's advantage really shows up with bigger models or faster-changing forces, so this was more about implementing it properly than seeing a dramatic visual difference.

## What's here

- `window_test.cpp`: the live animated simulation (SFML)
- `demo.cpp`: earlier CLI version that exports trajectory data to CSV
- `plot.py`: plots the CSV output with matplotlib

## Running it

You'll need g++ and SFML installed:
sudo apt install libsfml-dev
g++ window_test.cpp -o window_test -lsfml-graphics -lsfml-window 
-lsfml-system
./window_test

## Limitations

This is a simplified 2D model; which does not include altitude-dependent air density, wind, rotation or multi-stage effects. 
