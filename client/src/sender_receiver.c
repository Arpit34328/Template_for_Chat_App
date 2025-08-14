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
#include <sys/socket.h>

#include "include/client.h"

extern char buffer[BUFFER_SIZE];
pthread_mutex_t print_mutex = PTHREAD_MUTEX_INITIALIZER;
int should_exit = 0;

void* handle_recv(void *arg) {
    int sock_fd = *((int*)arg);
    char local_buffer[BUFFER_SIZE];

    while (!should_exit) {
        // Write you code Here
    }
    return NULL;
}

void* handle_send(void *arg) {
    int sock_fd = *((int*)arg);
    char send_buffer[BUFFER_SIZE];

    while (!should_exit) {
        // Write your code Here
    }

    return NULL;
}

