#include <stdio.h>
#include "api/mhook.h"

static int64_t unfree = 0;
static int64_t tot_allocs = 0;

int64_t mhook_unfree(void)
{
	return unfree;
}

int64_t mhook_tot_allocs(void)
{
	return unfree;
}

void mhook_print_unfree(void)
{
	printf("Total memory allocs: %ld.\n", tot_allocs);
	printf("Unfree memory allocs: %ld.\n", unfree);
}

/* malloc() hook */
void *__real_malloc(size_t);

void *__wrap_malloc(size_t c)
{
	void *p = __real_malloc(c);

	if (p) {
		unfree++;
		tot_allocs++;
	}

	return p;
}

/* calloc() hook */
void *__real_calloc(size_t, size_t);

void *__wrap_calloc(size_t nmemb, size_t size)
{
	void *p = __real_calloc(nmemb, size);

	if (p) {
		unfree++;
		tot_allocs++;
	}

	return p;
}

/* strdup() hook */
void *__real_strdup(const char *);

void *__wrap_strdup(const char *s)
{
	void *p = __real_strdup(s);

	if (p) {
		unfree++;
		tot_allocs++;
	}

	return p;
}

/* free() hook */
void __real_free(void*);

void __wrap_free(void *p)
{
	if (p)
		unfree--;

	__real_free(p);
}
