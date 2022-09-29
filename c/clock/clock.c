#include "clock.h"

clock_t clock_create(int hour, int minute)
{
    int extra_hours = minute / 60;
    hour = hour + extra_hours; 
    minute = minute % 60;

    while (hour >= 24)
        hour = hour - 24;

    while (hour <= 0)
        hour = 24 + hour;
    
    while (minute < 0)
    {
        minute = 60 + minute;
        hour--;
    }
    if(hour == 24)
        hour = 0;

    clock_t clock;
    clock.text[0] = hour / 10 + '0';
    clock.text[1] = hour % 10 + '0';
    clock.text[2] = ':';
    clock.text[3] = minute / 10 + '0';
    clock.text[4] = minute % 10 + '0';
    clock.text[5] = '\0';
    return clock;
}

int ret_hour(clock_t clock)
{
    return atoi(clock.text);
}

int ret_min(clock_t clock)
{
    char aux[2];
    aux[0] = clock.text[3];
    aux[1] = clock.text[4];
    return atoi(aux);
}

clock_t clock_add(clock_t clock, int minute_add)
{
    clock = clock_create(ret_hour(clock), ret_min(clock) + minute_add);
    return clock;
}
clock_t clock_subtract(clock_t clock, int minute_subtract)
{
    clock = clock_create(ret_hour(clock), ret_min(clock) - minute_subtract );
    return clock;
}

bool clock_is_equal(clock_t a, clock_t b)
{
    return (ret_hour(a) == ret_hour(b) && ret_min(a) == ret_min(b));
}
/*
int main ()
{
    clock_t myclock;
    myclock = clock_create(0,-1);
   // myclock = clock_subtract(myclock, 4);
    printf("%s\n", myclock.text);
}*/
