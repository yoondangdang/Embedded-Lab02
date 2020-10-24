# LAB02 IPC 및 쓰레드 연습
본 실습은 쓰레드와 프로세스 간 통신을 연습하기 위한 문제입니다. 첫번 째 실습에서는 싱글 쓰레드 상에서의 간단한 콘솔 기반 게임을 개발합니다. 그 이후 IPC중 Shared Memory를 사용하여 2인용 게임으로 콘솔 기반 게임을 확장합니다. 이후 멀티 쓰레드를 사용하도록 콘솔 기반 게임을 확장하여 싱글 쓰레드의 콘솔 기반 게임보다 좋은 사용자 경험을 주는 소프트웨어를 개발합니다. 

## 실습01 싱글 쓰레드 상에서의 콘솔 기반 게임
 싱글 쓰레드 상에서의 콘솔 기반 게임에 대해서는 hiclass의 강의를 참고하여 작성하기 바랍니다. 
 싱글 쓰레드 상에서 발생하는 이벤트 처리는 하나의 while문에서 모든 것을 처리하기 때문에 상대적으로 지연이 발생합니다. 이후 실습에서 이를 해결합니다. 

### Code
```C
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

```
### 실행화면
 [![실행화면](https://raw.githubusercontent.com/cbchoi/Embedded-Lab02/master/media/lab02_01.webm)]

## 실습02 Shared Memory를 사용한 Multi-Player Console Game
 Shared Memory를 사용한 Multi-Player Console Game은 서로 다른 두 개의 프로세스를 실행시켜 각 프로세스의 정보를 교환하여 게임을 진행합니다. 이 때 Shared Memory를 사용하여 정보를 공유하며 while문을 실행할 때마다 Shared Memory 상의 데이터를 확인하여 게임 화면을 갱신합니다. 

### Code for player1
```C
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
	/*
	  Remove the shared memory
	*/
	changemode(0);
	return 0;
}

```

### Code for player2
```C
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
	/*
	  Remove the shared memory
	*/
	changemode(0);
	return 0;
}

```
### 실행화면
 [![실행화면](https://raw.githubusercontent.com/cbchoi/Embedded-Lab02/master/media/lab02_02.webm)]

## 실습03 Multi-Thread를 사용한 콘솔 기반 게임
 Shared Memory를 사용한 Multi-Player Console Game은 서로 다른 두 개의 프로세스를 실행시켜 각 프로세스의 정보를 교환하여 게임을 진행합니다. 이 때 Shared Memory를 사용하여 정보를 공유하며 while문을 실행할 때마다 Shared Memory 상의 데이터를 확인하여 게임 화면을 갱신합니다. 

### Code for player1
```C
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

```
### 실행화면
 [![실행화면](mhttps://raw.githubusercontent.com/cbchoi/Embedded-Lab02/master/media/lab02_03.webm)]

# 수행해야 할 것
 1. st_player.c 구현: 동영상 강의를 참고하여 해당 코드 구현
 2. sm_player1.c, sm_player2.c 구현: shared memory를 사용하여 코드 구현
 3. mt_player.c 구현: multi-thread로 구현 (1차 힌트 없이 구현/2차 힌트를 받고 구현)
 4. (추가점수) mt_player1.c, mt_player2.c 구현: CMakeLists.txt를 수정하여 multi-thread를 사용한 콘솔 기반 게임 개발 (CMakeLists.txt 수정에 대해서는 웹 검색을 사용할 것)
 5. (추가점수) named pipe를 사용하여 np_player1.c, np_player2.c 구현: CMakeList.txt를 수정하여 multi-thread를 사용한 콘솔 기반 게임 개발 (CMakeLists.txt 수정에 대해서는 웹 검색을 사용할 것)
 6. (추가점수) Message Queue를 사용하여 mq_player1.c, mq_player2.c 구현: CMakeList.txt를 수정하여 multi-thread를 사용한 콘솔 기반 게임 개발 (CMakeLists.txt 수정에 대해서는 웹 검색을 사용할 것)

# 평가(3점 + 2점)
 - 1번 구현 시 0.25
 - 2번 구현 시 1.00
 - 3번 구현 시 1.75 ~ 2.25 (1차 시도시 2.25, 2차 시도시 1.75)
 - 4번 구현 시 0.5
 - 5번 구현 시 0.5
 - 6번 구현 시 0.5
 - (주의) 컴파일 에러가 날 시에는 0점 처리함 
 - (주의) 런타임 에러가 날 시에는 20% 페널티 처리함
 - (주의) 의미론적으로 문제가 있을 시에는 10% 페널티 처리함