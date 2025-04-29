/*
 * TcpServer.h
 *
 *  Created on: 29-Apr-2025
 *      Author: Lenovo
 */

#ifndef TCPSERVER_H_
#define TCPSERVER_H_

#ifdef _WIN32
  #include <winsock2.h>
  //#pragma comment(lib, "ws2_32.lib")
#else
  #include <sys/socket.h>
  #include <arpa/inet.h>
  #include <unistd.h>
  #define SOCKET int
  #define INVALID_SOCKET (-1)
  #define SOCKET_ERROR   (-1)
#endif

void initialize_sockets();
void cleanup_sockets();



#endif /* TCPSERVER_H_ */
