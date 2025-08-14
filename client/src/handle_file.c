/*
 * File:
 * Author:
 * Created:
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/client.h"

char* get_filename(const char* message) {
    static char filename[256];
    memset(filename, 0, sizeof(filename));

    // Write your code here

    return filename;
}

FILE* open_unique_file(const char* base_name) {
    static char filename[350];
    
    // Write your code here

    return NULL;
}

