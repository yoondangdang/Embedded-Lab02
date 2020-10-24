#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/wait.h>

#include "kbhandle.h"

struct game_info
{
	long int player1;
	long int player2;
};

#define SHM_KEY 0x12345

int main()
{
	key_t key = SHM_KEY;
	struct game_info* gi;
	int i = 0;

	/*
	  Code Blocks for shared memeory: Variable Allocation
	*/

	/*
	  Retrive struct game_info object
	*/

	gi->player1 = 0;
	gi->player2 = 79;

	changemode(1);
	printf("%s\n", "Nonblock Single Threaded");
	printf("%s\n", "q: quit");
	while(1)
	{
		if(kbhit())
		{
			switch(getchar())
			{
				/*
				   case statement for process termination
				*/

				/*
				   case statements for player 1
				*/

			}
	
		}

		/*
			Code block for screen update
		*/
		
		/* Update Frequency: 1 second*/
		sleep(1);
	}	

END:
	printf("Program Terminated\n");
	changemode(0);
	return 0;
}
