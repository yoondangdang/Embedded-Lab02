#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <pthread.h>

#include "kbhandle.h"

struct game_info
{
	long int player1;
	long int player2;
};

struct game_info* gi;

#define SHM_KEY 0x12345

pthread_mutex_t mid;
int termination_flag = 0;

void* game_print(void * arg)
{
	int i;
	while(!termination_flag)
	{
		











		sleep(1);
	}

	return 0;
}

void* game_input(void * arg)
{
	printf("%s\n", "Nonblock Single Threaded");
	printf("%s\n", "q: quit");
	while(!termination_flag)
	{
		
		sleep(0.01);
	}
	return 0;
}

int main()
{
	int shmid;
	key_t key = SHM_KEY;
	void* shmem = (void*) 0;
	

	printf("Program Terminated\n");
	changemode(0);
	return 0;
}
