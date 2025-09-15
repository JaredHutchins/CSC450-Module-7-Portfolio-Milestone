# CSC450 Week 7 – Portfolio Milestone: Halo Countdown Protocol

## What This Is

This repo contains my Week 7 CSC450 Portfolio Milestone assignment. It's a C++ console program that demonstrates basic concurrency using two threads in a Halo-themed simulation.

## What's Inside

- HaloCountdown.cpp – The C++ program  
- README.md

## Key Features

- Simulates the arming and detonation of a HAVOK tactical nuke using two threads  
- Thread 1 (Master Chief) counts from 1 to 20 to simulate the arming process  
- Thread 2 (Cortana) waits for arming to complete, then counts down from 20 to 0  
- Uses std::thread and std::atomic to coordinate execution  
- Console output is thematically styled and clearly structured

## How to Run

Compile:
```
clang++ -std=c++17 -o HaloCountdown HaloCountdown.cpp
```

Run:
```
./HaloCountdown
```

## Created By

Jared Hutchins