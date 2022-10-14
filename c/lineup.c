#include <stdio.h>

/*
To prepare his students for an upcoming game, the sports coach 
decides to try some new training drills. To begin with, he lines 
them up and starts with the following warm-up exercise: when the 
coach says 'L', he instructs the students to turn to the left. 
Alternatively, when he says 'R', they should turn to the right. 
Finally, when the coach says 'A', the students should turn around.

Unfortunately some students (not all of them, but at least one) 
can't tell left from right, meaning they always turn right when 
they hear 'L' and left when they hear 'R'. The coach wants to 
know how many times the students end up facing the same direction.

Given the list of commands the coach has given, count the number 
of such commands after which the students will be facing the same 
direction.

Example

For commands = "LLARL", the output should be
solution(commands) = 3.

Let's say that there are 4 students, and the second one can't tell 
left from right. In this case, only after the second, third and fifth 
commands will the students face the same direction.

Input/Output

    [execution time limit] 0.5 seconds (c)

    [input] string commands

    String consisting of characters 'L', 'R' and 'A' only.

    Guaranteed constraints:
    0 ≤ commands.length ≤ 35.

    [output] integer

    The number of commands after which students face the same direction.
*/

int solution(char * commands) {
	int direction=0,cnt=0;
	for(int i=0; commands[i]!='\0'; i++){		
		if(commands[i]=='L') direction-=1;
		else if(commands[i]=='R') direction+=1;
		else if(commands[i]=='A') direction+=0;
		if(direction%2==0){
			cnt++;
			printf("direction=%d, cnt=%d\n",direction,cnt);
		}
	}
	return cnt;
}

int main()
{
	char test1[16][35]={"LLARL","3","RLR","1","","0","L","0","A","1","AAAAAAAAAAAAAAA","15",
	"RRRRRRRRRRLLLLLLLLLRRRRLLLLLLLLLL","16","AALAAALARAR","5"};
	
	for(int i=0; i<8; i++)
		printf("test1[%d]=%s should be %s and is %d\n",i, test1[i*2], test1[i*2+1], solution(test1[i*2]));

}
