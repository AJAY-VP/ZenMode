#pragma once
#include <bits/stdc++.h>
#include <uuid/uuid.h>
using namespace std;

string generate_uuid() {
    uuid_t uuid;
    char str[37];
    uuid_generate(uuid);
    uuid_unparse(uuid, str);
    return string(str);
}

time_t get_expiry_time(){
    time_t now = time(nullptr);
    struct tm* timeinfo = localtime(&now);
    timeinfo->tm_hour = 23;
    timeinfo->tm_min = 59;
    timeinfo->tm_sec = 59;
    timeinfo->tm_mday += 30;
    return mktime(timeinfo);
}

string format_expiry_time(time_t expiry) {
    char buffer[20];
    struct tm* timeinfo = localtime(&expiry);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timeinfo);
    return string(buffer);
}