/*
 * File: 
 * Author:
 * Created:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include "include/server.h"

// Extract username from "Hello, I am <name>."
void extract_username(const char* msg, char* username) {
    // 1. Find prefix in msg
    // 2. Move pointer after prefix
    // 3. Find '.' after username
    // 4. Copy to 'username' and remove newline if any
}

// Reset all fields of MsgInfo
void init_msgInfo(MsgInfo *msg) {
    // Set command_type=0, clear user_name, file_name, data
}

// Prepare all client slots for use
void init_client() {
    // For each slot: set fd=-1, ip/port=0, state=CLIENT_IDLE
    // Clear username, allocate msg_info, call init_msgInfo
}

// Add a client in a free slot
int add_client(int index, const char* username, int client_fd, struct sockaddr_in addr) {
    // Validate index & slot empty, assign fd/ip/port/state/username
    // Increment client_counter, print total clients
    return 0; // Return 1 on success
}

// Remove a client from given slot
int remove_client(int index) {
    // Validate index & active client
    // Print disconnect, reset fields, decrement counter
    return 0; // Return 1 on success
}

// List other connected clients
int get_current_clients(char* list, int current) {
    // Append all usernames except current's, separated by '\n'
    return 0; // Return 1 if any found
}

// Parse user input into MsgInfo
void input_parser(const char *input, MsgInfo *msg_info) {
    // Copy input to buffer, init msg_info
    // If not starting with '/', set BROADCAST and copy message
    // Else parse commands: /msg, /file, /list, /quit
}

