#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "kbhandle.h"

struct game_info
{
	/* Player1's location */
	long int player1; 
	/* Player2's location */
	long int player2;
};

int main()
{
	struct game_info gi;
	int i = 0;

	gi.player1 = 0;
	gi.player2 = 79;

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

				/*
				   case statements for player 2
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