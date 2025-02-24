#ifndef CACHE_MANAGER_H
#define CACHE_MANAGER_H

char* get_cached_value(int key);
void store_cached_value(int key, const char* value);
void free_cache();

#endif
