#include <iostream>
#include "libssh/libssh.h"
#include "Payload.h"


int main()
{
    Payload payload;
    payload.connect();

    return 0;
}