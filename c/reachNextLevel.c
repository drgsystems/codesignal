#include <stdio.h>
#include <stdbool.h>

/*
You are playing an RPG game. Currently your experience 
points (XP) total is equal to experience. To reach the 
next level your XP should be at least at threshold. If 
you kill the monster in front of you, you will gain more 
experience points in the amount of the reward.

Given values experience, threshold and reward, check 
if you reach the next level after killing the monster.

Example

    For experience = 10, threshold = 15, and reward = 5, the output should be
    solution(experience, threshold, reward) = true;
    For experience = 10, threshold = 15, and reward = 4, the output should be
    solution(experience, threshold, reward) = false.

Input/Output

    [execution time limit] 0.5 seconds (c)
    [input] integer experience
    Guaranteed constraints:
    3 ≤ experience ≤ 250.
    [input] integer threshold
    Guaranteed constraints:
    5 ≤ threshold ≤ 300.
    [input] integer reward
    Guaranteed constraints:
    2 ≤ reward ≤ 65.
    [output] boolean
    true if you reach the next level, false otherwise.

[C] Syntax Tips
// Prints help message to the console
// Returns a string
char * helloWorld(char * name) {
    char * answer = malloc(strlen(name) + 8);
    printf("This prints to the console when you Run Tests");
    strcpy(answer, "Hello, ");
    strcat(answer, name);
    return answer;
}

*/

bool solution(int experience, int threshold, int reward) {
	if(experience +reward >= threshold) return true;
	else return false;
}

void main()
{

	printf("experience=%d,threshold=%d,reward=%d,result=%d\n",10,15,5, solution(10,15,5));
	printf("experience=%d,threshold=%d,reward=%d,result=%d\n",10,15,4, solution(10,15,4));
	printf("experience=%d,threshold=%d,reward=%d,result=%d\n",3,5,2, solution(3,5,2));
	printf("experience=%d,threshold=%d,reward=%d,result=%d\n",250,300,65, solution(250,300,65));
	printf("experience=%d,threshold=%d,reward=%d,result=%d\n",250,5,2, solution(250,5,2));
	
}