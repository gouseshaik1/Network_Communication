/*
 * TcpUtils.cpp
 *
 *  Created on: 29-Apr-2025
 *      Author: Lenovo
 */

#include "TcpServer.h"
#include <iostream>

void initialize_sockets() {
#ifdef _WIN32
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        std::cerr << "WSAStartup failed: " << result << std::endl;
        exit(1);
    }
#endif
}

void cleanup_sockets() {
#ifdef _WIN32
    WSACleanup();
#endif
}



