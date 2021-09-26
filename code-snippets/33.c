// CVE - 2020 - 25643
// Memory corruption and read overflow
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>

#define LCP_OPTION_ACCM 9

// Define an 8 bit integer as u8
typedef uint8_t u8;
int err;

static void ppp_cp_parse_cr(unsigned int req_len, const u8 *data)
{
    static u8 const valid_accm[6] = {LCP_OPTION_ACCM, 6, 0, 0, 0, 0};
    const u8 *opt;
    unsigned int len = req_len;

    for (opt = data; len; len -= opt[1], opt += opt[1])
    {
        if (len < 2 || opt[1] < 2 || len < opt[1])
            err = ENOTCONN;
    }
}

int main()
{
    const u8 *data;
    const u8 data0 = 9;
    data = &data0;
    ppp_cp_parse_cr(4, data);
    return 0;
}
