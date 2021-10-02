// CVE - 2020 - 35499
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BT_CONNECTED 1
#define BT_VOICE 11
#define BT_SNDMTU 12
#define BT_RCVMTU 13
#define BT_PHY 14

struct sock
{
    int sk_state;
};

struct socket
{
    struct sock *sk;
};

static int sco_sock_getsockopt(struct socket *sock, int optname)
{

    struct sock *sk = sock->sk;
    int err;

    // Null Pointer dereference if the
    if (optname == BT_VOICE)
    {
        printf("BT_VOICE\n");
    }
    if (optname == BT_PHY)
    {
        printf("BT_PHY\n");
    }
    if (optname == BT_RCVMTU)
    {
        printf("BT_RCVMTU\n");
    }
    if (optname == BT_SNDMTU)
    {
        printf("BT_SNDMTU\n");
    }
    return 1;
}

int main()
{
    struct sock sk = {3};
    struct socket sock0 = {&sk};
    struct socket *sock;
    sock = &sock0;
    printf("Struct socket initialized\n");

    // Initialize the name of the feature
    int optname = 13;
    int rv = sco_sock_getsockopt(sock, optname);
    printf("Return value: %d\n", rv);
    return 0;
}