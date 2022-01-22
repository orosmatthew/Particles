#include "util.h"

#include <sys/time.h>

FixedLoop CreateFixedLoop(double rate)
{
    FixedLoop loop = {
            .start = GetMicroTime(),
            .end = GetMicroTime(),
            .delta = 0,
            .rate = 1000000.0 / rate,
    };
    return loop;
}

void OuterUpdateFixedLoop(FixedLoop* loop)
{
    loop->start = GetMicroTime();
    loop->delta += (double)(loop->start - loop->end);
    loop->end = loop->start;
}

void InnerUpdateFixedLoop(FixedLoop* loop)
{
    loop->delta -= loop->rate;
}

double GetFixedLoopAlpha(const FixedLoop* loop)
{
    return loop->delta / loop->rate;
}

bool IsFixedLoopReady(const FixedLoop* loop)
{
    return loop->delta >= loop->rate;
}

long GetMicroTime()
{
    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}