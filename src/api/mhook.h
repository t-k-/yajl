#pragma once
#include <stdint.h>
#include <malloc.h>
#include <string.h>

int64_t mhook_unfree(void);
int64_t mhook_tot_allocs(void);

void mhook_print_unfree(void);

void *__wrap_malloc(size_t);
void *__wrap_calloc(size_t, size_t);
void *__wrap_strdup(const char*);
void __wrap_free(void*);
