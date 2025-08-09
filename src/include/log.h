#ifndef ENIGMA_LOG_H
#define ENIGMA_LOG_H

#include<stdio.h>
#include<time.h>

void log_info(const char* message) {

#ifdef ENIGMA_LOG_INFO
	time_t t = time(NULL);
	struct tm *tm = localtime(&t);
	char formatted_time[64];

	size_t ret = strftime(formatted_time, sizeof(formatted_time), "%c", tm);

	printf("[%s] [INFO] - %s\n", formatted_time, message);
#endif

}

#endif
