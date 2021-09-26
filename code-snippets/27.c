// CVE - 2020 - 36158
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define IEEE80211_MAX_SSID_LEN 65536

// Struct for bpf ring buffer
struct cfg80211_ssid
{
    unsigned long ssid_len;
};

int mwifiex_cmd_802_11_ad_hoc_start(struct cfg80211_ssid *req_ssid)
{
    // A high value of SSID can be provided to corrupt the buffer
    if (req_ssid->ssid_len > IEEE80211_MAX_SSID_LEN)
    {
        printf("SSID too high\n");
        req_ssid->ssid_len = IEEE80211_MAX_SSID_LEN;
    }
    else
        printf("SSID within bounds\n");
    return 1;
}

int main()
{
    struct cfg80211_ssid req_ssid0 = {96104};
    struct cfg80211_ssid *req_ssid;
    req_ssid = &req_ssid0;
    printf("Initialized req ssid struct\n");
    mwifiex_cmd_802_11_ad_hoc_start(req_ssid);
    return 0;
}