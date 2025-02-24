#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cache_manager.h"

#define MAXIMUM_CACHED_CENTS 150000

char* cache[MAXIMUM_CACHED_CENTS] = {0};

char* get_cached_value(int key) {
    if (key < MAXIMUM_CACHED_CENTS && cache[key] != NULL) {
        return cache[key];
    }
    return NULL;
}

void store_cached_value(int key, const char* value) {
    if (key < MAXIMUM_CACHED_CENTS) {
        cache[key] = strdup(value);
    }
}

void free_cache() {
    for (int i = 0; i < MAXIMUM_CACHED_CENTS; i++) {
        if (cache[i] != NULL) {
            free(cache[i]);
            cache[i] = NULL;
        }
    }
}
