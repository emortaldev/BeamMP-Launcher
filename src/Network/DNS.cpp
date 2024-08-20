// Copyright (c) 2019-present Anonymous275.
// BeamMP Launcher code is not in the public domain and is not free software.
// One must be granted explicit permission by the copyright holder in order to modify or distribute any part of the source or binaries.
// Anything else is prohibited. Modified works may not be published and have be upstreamed to the official repository.
///
/// Created by Anonymous275 on 9/25/2020
///

#include <string>
#include "IPRegex.h"

#if defined(_WIN32)
#include <winsock2.h>
#elif defined(__linux__)
#include "linuxfixes.h"
#include <arpa/inet.h>
#include <netdb.h>
#endif

#include "Logger.h"

std::string GetAddr(const std::string& IP) {
    if (!std::regex_match(IP, IP_REGEX)) {
        return IP;
    }
    hostent* host;
#ifdef _WIN32
    WSADATA wsaData;
    if (WSAStartup(514, &wsaData) != 0) {
        error("WSA Startup Failed!");
        WSACleanup();
        return "";
    }
#endif

    host = gethostbyname(IP.c_str());
    if (!host) {
        error("DNS lookup failed! on " + IP);
        WSACleanup();
        return "DNS";
    }
    std::string Ret = inet_ntoa(*((struct in_addr*)host->h_addr));
    WSACleanup();
    return Ret;
}
