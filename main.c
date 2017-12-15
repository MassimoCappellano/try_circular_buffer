#include <stdio.h>

#include "data_circular_buffer.h"
#include "circular_buffer.h"

#define BUFFER_SPACE 100

int main() 
{
    struct DataCircularBuffer d1 = { "MAC1", 123 };
    struct DataCircularBuffer d2;
    
    d2 = d1;

    printf("%s\n", d2.mac_address);
    printf("%d\n", d2.light_power);

    struct DataCircularBuffer buffer[BUFFER_SPACE];

    struct circBuf_t circularBuffer = { buffer, 0, 0, BUFFER_SPACE};
   
    circBufPush(&circularBuffer, d1);

    struct DataCircularBuffer d3 = { "MAC3", 3};
    circBufPush(&circularBuffer, d3);

    struct DataCircularBuffer d4;
    struct DataCircularBuffer d5;

    circBufPop(&circularBuffer, &d4);
    circBufPop(&circularBuffer, &d5);

    printf("--> %s\n", d4.mac_address);
    printf("--> %d\n", d4.light_power);

    printf("--> %s\n", d5.mac_address);
    printf("--> %d\n", d5.light_power);

    return 0;
}
