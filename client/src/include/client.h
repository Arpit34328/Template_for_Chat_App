
/*
 * File Name:
 * Author Name: 
 * Created:
 */

#ifndef CLIENT_H
#define CLIENT_H


#include <pthread.h>
#include <stdio.h>


#define PORT 8080
#define IP_SIZE 16
#define BUFFER_SIZE 1024
#define USERNAME_SIZE 16


#define GOODBYE "Good Bye"
#define GET_FILE "/file"
#define END_FILE "/endfile"
#define QUIT "/quit"

int start_client();

void* handle_recv(void *arg);
void* handle_send(void *arg);

char* get_filename(const char* message);
FILE* open_unique_file(const char* base_name);


extern pthread_mutex_t print_mutex;
extern int should_exit;

#endif // CLIENT_H
