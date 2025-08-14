/*
 * File:
 * Author:
 * Created:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include "include/client.h"

char buffer[BUFFER_SIZE];

int start_client() {
    int sock_fd = 0;
    struct sockaddr_in serv_addr;
    char server_ip[IP_SIZE] = {0};
    char username[USERNAME_SIZE] = {0};

    // TODO: Create socket here

    // TODO: Set server family & port

    printf("Enter the IP address Where you want to connect: ");
    // TODO: Read IP from user

    // Remove newline at end of server_ip

    // TODO: Convert IP string to binary form

    // TODO: Connect to the server

    printf("Connected to server at %s:%d\n", server_ip, PORT);

    // TODO: Prepare and send username to server
    printf("Enter Your Name [GID_FirstName] (Don't use space, use '_'): ");
    // TODO: Read username
    // Send the user name to server

    pthread_t recv_thread, send_thread;

    // TODO: Create receive thread

    usleep(100000); // Let receive thread start

    // TODO: Create send thread

    // TODO: Wait for threads to finish

    // TODO: Close socket and cleanup
  
    return 0;
}

