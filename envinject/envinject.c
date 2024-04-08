#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>
#include <string.h>

char *getenv( const char *name ) {
	char *(*lgetenv)( const char *name ) = dlsym(RTLD_NEXT, "getenv");
	char *override_url = "http://localhost:8080/";

	if (strcmp(name, "ACTIONS_CACHE_URL") == 0) {
		printf("ACTIONS_CACHE_URL Requested...\n Overriding URL with %s\n", override_url);
		return(override_url);
	}
	return lgetenv(name);
}
