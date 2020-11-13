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
				case 'q':
				{	
					goto END;
				}
				break;
				case 'a':
				{	
					
					gi.player <= 0 ? gi.player1 =0:gi.player1--;
					
				}
				break;
				case 'd':
				{	
					if(gi.player1 >= 79)
					{
						gi.player1 = 79;
					}
					else 
					{
						gi.player1++;
					}
				}
				break;
					
				case'\033':
				{
				getchar ();
				switch(getchar)())
				{
					case'D':
					{
						gi.player2 <= 0 ? gi.player2 =0:gi.player2--;
					}
					break;
					case'C':
					{
						if(gi.player2 >= 79)
					{
						gi.player2 = 79;
					}
					else 
					{
						gi.player2++;
					}
					}
					break;
				
				}
				
				
				}
					
				
			}
	
		}

		for(i = 0; i<80; i++){
		if(gi.player1 == i)
		{
			printf("*");
		}
		else if(gi.player2 == i){
			printf("o");
		}
		else
		{
			printf(" ");
		}
		
		}printf("\n");
		
		/* Update Frequency: 1 second*/
		sleep(1);
	}	

END:
	printf("Program Terminated\n");
	changemode(0);
	return 0;
}
