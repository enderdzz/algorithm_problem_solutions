#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define N 100

int i = 0, t = 1, cur;

struct Timer
{
	int left_time;
}myTimer[N];

void setTimer(int time, int no)
{
	struct Timer a;
	a.left_time = time;
	myTimer[no] = a;
	cur++;
}

void timeout()
{
	printf("Time: %d\n",t++);
	int j;
	for (j = 0; j < cur; j++) {
		if(myTimer[j].left_time != 1) {
			myTimer[j].left_time--;
		}
		else {
			printf("myTimer[%d] end\n", j);
		}
	}
}

int main()
{
	int i;
	for(i = 0; i < 5; i++){
		printf("send #%d\n", i);
		setTimer(5, i);

		//等信号(异步)
		if(signal(SIGALRM, timeout) == SIG_ERR){
			printf("error\n");
		}
		//停一秒
		sleep(1);
		//发信号
		kill(getpid(), SIGALRM);

	}
	while(1) {
		sleep(1);
		kill(getpid(), SIGALRM);

	}
	if(signal(SIGALRM, timeout) == SIG_ERR){
		puts("wrong");
	}

	exit(0);
}
