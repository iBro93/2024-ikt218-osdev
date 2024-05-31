#pragma once

#include "../include/libc/stdint.h"
#include "../include/libc/stddef.h"
#include "../include/libc/stdbool.h"
#include "../include/libc/limits.h"
#include "../include/libc/stdio.h"

#include "../include/libc/string.h"

#define EOF (-1)

// Custom Functions
void panic(const char *reason);
char *hex32_to_str(char buffer[], unsigned int val);
char *int32_to_str(char buffer[], int val);
