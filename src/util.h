#ifndef PARTICLES_UTIL_H
#define PARTICLES_UTIL_H

#include <stdbool.h>

// Struct to hold data for a FixedLoop for
// updating logic at a consistent timestep
typedef struct FixedLoop {
    long int start;
    long int end;
    double delta;
    double rate;
} FixedLoop;

// Creates FixedLoop at a certain framerate
FixedLoop CreateFixedLoop(double rate);

// Update FixedLoop. Should be called as often as possible
void OuterUpdateFixedLoop(FixedLoop* loop);

// Update FixedLoop after each iteration of loop
void InnerUpdateFixedLoop(FixedLoop* loop);

// Get value 0.0-1.0 which represents blend between time between last iteration
// to the next iteration
double GetFixedLoopAlpha(const FixedLoop* loop);

// Check if FixedLoop is ready to iterate
bool IsFixedLoopReady(const FixedLoop* loop);

// Get current time in microseconds
long GetMicroTime();

#endif //PARTICLES_UTIL_H
