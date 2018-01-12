#include <stdio.h>
#include <assert.h>

#include "data_circular_buffer.h"
#include "circular_buffer.h"

#define BUFFER_SPACE 5

void test1() 
{
    struct DataCircularBuffer buffer[BUFFER_SPACE];

    struct circBuf_t circularBuffer = { buffer, 0, 0, BUFFER_SPACE, 0};

    struct DataCircularBuffer d1 = { "MAC1", 1 };
   
    circBufPush(&circularBuffer, d1);

    assert(numElementsInBuffer(&circularBuffer) == 1);

    struct DataCircularBuffer d3 = { "MAC3", 3};
    circBufPush(&circularBuffer, d3);

    assert(numElementsInBuffer(&circularBuffer) == 2);

    struct DataCircularBuffer d4;
    struct DataCircularBuffer d5;

    circBufPop(&circularBuffer, &d4);
    circBufPop(&circularBuffer, &d5);

    printf("--> %s\n", d4.mac_address);
    printf("--> %d\n", d4.light_power);

    printf("--> %s\n", d5.mac_address);
    printf("--> %d\n", d5.light_power);

    assert(numElementsInBuffer(&circularBuffer) == 0);

}

void test2() 
{
    int ret;

    struct DataCircularBuffer buffer[BUFFER_SPACE];

    struct circBuf_t circularBuffer = { buffer, 0, 0, BUFFER_SPACE, 0};

    struct DataCircularBuffer d1 = { "MAC1", 1 };

    struct DataCircularBuffer d2 = { "MAC2", 2 };

    struct DataCircularBuffer d3 = { "MAC3", 3 };

    struct DataCircularBuffer d4 = { "MAC4", 4 };

    struct DataCircularBuffer d5 = { "MAC5", 5 };

    ret = circBufPush(&circularBuffer, d1);
    ret = circBufPush(&circularBuffer, d2);
    ret = circBufPush(&circularBuffer, d3);
    ret = circBufPush(&circularBuffer, d4);
    assert(ret == 0);
    assert(numElementsInBuffer(&circularBuffer) == 4);
    
    ret = circBufPush(&circularBuffer, d5);

    assert(ret == 0);

    assert(numElementsInBuffer(&circularBuffer) == 5);

    struct DataCircularBuffer d1A;
    struct DataCircularBuffer d2A;

    ret = circBufPop(&circularBuffer, &d1A);
    assert(ret == 0);

    ret = circBufPop(&circularBuffer, &d2A);
    assert(ret == 0);

    assert(d1.light_power == d1A.light_power);
    assert(d2.light_power == d2A.light_power);

    assert(numElementsInBuffer(&circularBuffer) == 3);

    struct DataCircularBuffer d6 = { "MAC6", 6 };
    struct DataCircularBuffer d7 = { "MAC7", 7 };

    ret = circBufPush(&circularBuffer, d6);
    assert(ret == 0);

    ret = circBufPush(&circularBuffer, d7);
    assert(ret == 0);

    assert(numElementsInBuffer(&circularBuffer) == 5);

    struct DataCircularBuffer d8 = { "MAC8", 8 };
    ret = circBufPush(&circularBuffer, d8);
    assert(ret == -1);
}


int main() 
{
    test1();
    test2();

    return 0;
}
