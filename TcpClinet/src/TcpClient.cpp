/*
 * TcpClient.cpp
 *
 *  Created on: 29-Apr-2025
 *      Author: Lenovo
 */


#include "TcpClient.h"
#include <iostream>
#include <cstring>

int main() {
    initialize_sockets();

    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == INVALID_SOCKET) {
        std::cerr << "Socket creation failed!" << std::endl;
        return 1;
    }

    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        std::cerr << "Connection failed!" << std::endl;
        return 1;
    }

    const char* message = "Hello from Client!";
    send(sock, message, strlen(message), 0);

    char buffer[1024] = {};
    recv(sock, buffer, sizeof(buffer), 0);
    std::cout << "Server replied: " << buffer << std::endl;

#ifdef _WIN32
    closesocket(sock);
#else
    close(sock);
#endif

    cleanup_sockets();
    return 0;
}




