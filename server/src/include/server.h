/*
 * File Name: 
 * Author Name:
 * Created: 
 */

#ifndef SERVER_H
#define SERVER_H

#include <netinet/in.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024
#define USERNAME_SIZE 16
#define FILENAME_SIZE 256
#define DATA_SIZE 512

// Command types using enum for better type safety
typedef enum {
        BROADCAST = 1,
        MSG = 2,
        FILE_SEND = 3,
        LIST = 4,
        QUIT = 5
} CommandType;

// Client state enum for file transfer management
typedef enum {
        CLIENT_IDLE = 0,
        CLIENT_SENDING_FILE = 1
} ClientState;

typedef struct {
        CommandType command_type;
        char user_name[USERNAME_SIZE];
        char file_name[FILENAME_SIZE];
        char data[DATA_SIZE];
} MsgInfo;

typedef struct {
        int fd;
        uint32_t ip;
        uint16_t port;
        char username[USERNAME_SIZE];
        MsgInfo *msg_info;
        ClientState state;
} ClientInfo;

// Function declarations
int start_server();
void extract_username(const char* msg, char* username);
void init_client();
void init_msgInfo(MsgInfo *msg);
int add_client(int index, const char* username, int client_fd, struct sockaddr_in client_addr);
int remove_client(int index);
int get_current_clients(char* client_list, int current_client);
void input_parser(const char *input, MsgInfo *msg_info);
void broadcast(int index);
void send_msg(int index);
void transfer_file(int index);
void handle_file_data_transfer(int sender_index);
void list_clients(int index);
void quit_client(int index);

// Global variables
extern ClientInfo *client_set;
extern int client_counter;

#endif // SERVER_H
