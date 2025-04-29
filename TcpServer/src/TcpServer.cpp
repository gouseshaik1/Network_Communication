/*
 * TcpServer.cpp
 *
 *  Created on: 29-Apr-2025
 *      Author: Lenovo
 */

#include "TcpServer.h"
#include <iostream>
#include <cstring>

int main() {
    initialize_sockets();

    SOCKET server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == INVALID_SOCKET) {
        std::cerr << "Socket creation failed!" << std::endl;
        return 1;
    }

    sockaddr_in server_addr{};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(server_socket, (sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        std::cerr << "Bind failed!" << std::endl;
        return 1;
    }

    listen(server_socket, 1);
    std::cout << "Server listening on port 8080..." << std::endl;

    SOCKET client_socket = accept(server_socket, nullptr, nullptr);
    if (client_socket == INVALID_SOCKET) {
        std::cerr << "Accept failed!" << std::endl;
        return 1;
    }

    char buffer[1024] = {};
    recv(client_socket, buffer, sizeof(buffer), 0);
    std::cout << "Client says: " << buffer << std::endl;

    const char* reply = "Hello from Server!";
    send(client_socket, reply, strlen(reply), 0);

#ifdef _WIN32
    closesocket(server_socket);
    closesocket(client_socket);
#else
    close(server_socket);
    close(client_socket);
#endif

    cleanup_sockets();
    return 0;
}



