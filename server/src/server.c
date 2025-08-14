/*
 * File Name:
 * Author Name:
 * Created:
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/poll.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <arpa/inet.h>

#include "include/server.h"

ClientInfo* client_set;
int client_counter = 0;

int start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    char buffer[BUFFER_SIZE];
    struct pollfd fds[MAX_CLIENTS + 1];

    // TODO: Allocate memory for client_set
    // TODO: Initialize client list

    // TODO: Create socket
    // TODO: Set socket options
    // TODO: Bind socket to address
    // TODO: Start listening

    // --- Basic poll initialization ---
    // fd[0] is reserved for the server listening socket
    fds[0].fd = server_fd;     // TODO: assign after creating socket
    fds[0].events = POLLIN;    // monitor for incoming connections

    // Initialize all other slots to -1 (no client connected yet)
    for (int i = 1; i <= MAX_CLIENTS; i++) {
        fds[i].fd = -1;
        fds[i].events = POLLIN;
    }
    // ----------------------------------

    while (1) {
        // TODO: Wait for events with poll()

        // TODO: Handle new incoming connections

        // TODO: Handle client data
        //  - Read data from client
        //  - Parse input
        //  - Execute command based on type (BROADCAST, MSG, FILE_SEND, LIST, QUIT)
        //  - Handle file transfer if needed
        //  - Handle unexpected disconnect
    }

    // TODO: Close server socket
    // TODO: Free all allocated memory

    return 0;
}

