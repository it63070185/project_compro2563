#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

void delay(int number_of_seconds);
void display(int num);

int main()
{
	char txt[3];
	int r;
	int bucket[5];
	int ans[5];
	system("clear");
	int i = 0;
	int check = 1;
	char end[1] = "n";

	// display "kmitl"

	printf("==============================\n");
	printf("|                            |\n");
	printf("| *  *  ** **  * ***** *     |\n");
	printf("| * *   * * *  *   *   *     |\n");
	printf("| ***   *   *  *   *   *     |\n");
	printf("| *  *  *   *  *   *   ****  |\n");
	printf("|                            |\n");
	printf("==============================\n");
	delay(2);
	system("clear");

	// display example input

	printf("=========================================\n");
	printf("|Example input answer                   |\n");
	display(10);
	printf("|Input 2 answer: 0 4                    |\n");
	printf("|Warning!!! Do not input while hinting. |\n");
	printf("========================================\n");

	// scanf for start mini game

	printf("Input some keys to start >>");
	scanf("%s", txt);
	delay(0.5);
	system("clear");

	// main loop Game

	while(1 == 1){ // 1==1 --> True
		if(end[0] == 'y'){ // เช็คว่าจะเล่นอีกรอบหรือไม่
			break;
		}
		i = 0;

		// รอบในการเล่น

		while(i < 5){
			// random เลข
			if(check == 1){
				srand(time(NULL));
				r = rand() % 9;
				bucket[i] = r;
			}

			// จัดเก็บเลขที่ random และ แสดง display ตามที่กำหนด

			for (int j = 0; j <= i; ++j)
			{
				printf("round:%d\n", i+1);
				display(bucket[j]);
				delay(1.6);
				system("clear");
				printf("round:%d\n", i+1);
				display(9);
				delay(1.7);
				system("clear");
			}
			printf("round:%d\n", i+1);

			// รับ input เพือ เทียบกับเลขที่ random

			display(10);
			for (int j = 0; j <= i; ++j)
			{
				if (j == 0)
				{
					printf("Input %d answer: ", i+1);
				}
				scanf("%d", &ans[j]);
			}

			// check ว่าถูกหรือผิด

			for (int j = 0; j <= i; ++j)
			{
				// printf("%d %d\n", bucket[j], ans[j]);
				if(bucket[j] != ans[j]){
					delay(0.5);
					system("clear");
					printf("================\n");
					printf("| incorrect!!! |\n");
					printf("================\n");
					delay(1);
					system("clear");
					check = 0;
					break;
				}
				if(bucket[j] == ans[j]){
					check = 1;
				}
			}
			if(check == 1){
				i++;
				delay(0.5);
				system("clear");
				printf("==============\n");
				printf("| correct!!! |\n");
				printf("==============\n");
				delay(1);
				system("clear");
			}
		}

		// printf ว่าชนะและถามว่าจะเล่นอีกรอบไหม

		printf("==============\n");
		printf("| You win!!! |\n");
		printf("==============\n");
		printf("close game(y/n) >>");
		scanf("%s", end);
		tolower(end[0]);
		system("clear");
		delay(1);
	}
    return 0;
}

// ฟังชั่น delay

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}
// printf [0] [1] [2]
// Ans: T --> i+1  check = 1 F -->  check = 0

// Display รูปแบบต่างๆ


void display(int num)
{
	switch(num)
	{
		case 0:
		printf("[X] [ ] [ ]\n");
		printf("[ ] [ ] [ ]\n");
		printf("[ ] [ ] [ ]\n");
		break;
		case 1:
		printf("[ ] [X] [ ]\n");
		printf("[ ] [ ] [ ]\n");
		printf("[ ] [ ] [ ]\n");
		break;
		case 2:
		printf("[ ] [ ] [X]\n");
		printf("[ ] [ ] [ ]\n");
		printf("[ ] [ ] [ ]\n");
		break;
		case 3:
		printf("[ ] [ ] [ ]\n");
		printf("[X] [ ] [ ]\n");
		printf("[ ] [ ] [ ]\n");
		break;
		case 4:
		printf("[ ] [ ] [ ]\n");
		printf("[ ] [X] [ ]\n");
		printf("[ ] [ ] [ ]\n");
		break;
		case 5:
		printf("[ ] [ ] [ ]\n");
		printf("[ ] [ ] [X]\n");
		printf("[ ] [ ] [ ]\n");
		break;
		case 6:
		printf("[ ] [ ] [ ]\n");
		printf("[ ] [ ] [ ]\n");
		printf("[X] [ ] [ ]\n");
		break;
		case 7:
		printf("[ ] [ ] [ ]\n");
		printf("[ ] [ ] [ ]\n");
		printf("[ ] [X] [ ]\n");
		break;
		case 8:
		printf("[ ] [ ] [ ]\n");
		printf("[ ] [ ] [ ]\n");
		printf("[ ] [ ] [X]\n");
		break;
		case 9:
		printf("[ ] [ ] [ ]\n");
		printf("[ ] [ ] [ ]\n");
		printf("[ ] [ ] [ ]\n");
		break;
		case 10:
		printf("[0] [1] [2]\n");
		printf("[3] [4] [5]\n");
		printf("[6] [7] [8]\n");
		break;
	}
}
