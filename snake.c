#include <stdio.h> //to use the printf() function
#include <unistd.h> //to use the sleep() function
#include <conio.h> //to use Kbhit() and gectch() functions
#include <stdlib.h> //to use rand() and srand() functions
#include <time.h> //to use the time() function
//variables declaration
int	width = 20;
int	height = 20;
int	i;
int	j;
int	x;
int	y;
int	foodx;
int	foody;
int	game_over;
int	pos;
int	score;
int	highest_score;

//this function starts the game 
void	gamestart()
{
	printf("press 'x' to start the game!");
	if (kbhit)
	{
		if (getch() == 'x')
		{
			game_over = 0;
		}
	}
}
//the following function is responsible for spawning the food within the boundary of the game. 
void	setup()
{
	//using the srand() function to generate truly random numbers
	//using the time() function to get the number of seconds on system time and randomly seed
	//the rand() function
	srand(time(0));
	//game_over = 0;
	x = height / 2;
	y = width / 2;
     label1:
	foodx = rand() % 20; //using rand()%20 so the food will spawn within the border.
	if (foodx == 0)
		goto label1;
     label2:
	foody = rand() % 20;
	if (foody == 0)
		goto label2;
	score = 0; //the score is 0 at the beginning of the game.
}
//the following function is responsible for the boundary where the game will be played.
void	border()
{
	i = 0;
	//to clear the screen
	system("cls");
	while (i < height)
	{
		while (j < width)
		{
			if (i == 0 || i == width - 1 || j == 0 || j == height - 1)
				printf("#");
			else if (i == x && j == y)
				printf("O"); //the snake
			else if (i == foodx && j == foody)
				printf("*"); //the food
			else
				printf(" ");
			j++;
		}
		j = 0;
		printf("\n");
		i++;
	}
	//prints the score
	printf("the score is %d", score);
	printf("\n");
	printf("press 'x' to exit the game.");
}

//the following function is taking the input from the keys (W, A, S, D, X)
void	input()
{
	if (kbhit())
	{
		switch (getch())
		{
			case 'a':
				pos = 1;
				break;
			case 's':
				pos = 2;
				break;
			case 'd':
				pos = 3;
				break;
			case 'w':
				pos = 4;
				break;
			case 'x':
				game_over = 1;
				break;
		}
	}
}
 //the logic of the game
void	game()
{
	//the function in C delays the program execution
	//this function slows down the movement of the snake so the game can be playable
	sleep(0.2);
	//player movements
	switch (pos)
	{
		case 1:
			y--;
			break;
		case 2:
			x++;
			break;
		case 3:
			y++;
			break;
		case 4:
			x--;
			break;
		default:
			break;
	}
	//when the player touches the border
	if (x < 0 || x > height || y < 0 || y > width)
		game_over = 1;
	//when the player touches the food
	//it spawns another one
	if ( x == foodx && y == foody)
	{
		srand(time(0));
label3:
		foodx = rand() % 20;
		if (foodx == 0)
			goto label3;
label4:
		foody = rand() % 20;
		if (foody == 0)
			goto label4;
		score += 5;
	}
}
void	main()
{
	setup();
	gamestart();
	//until the game is over
	//if game_over = 1 the game is over
	while (!game_over)
	{
		border();
		input();
		game();
	}
}
