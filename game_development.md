# Game Development in C++
### Introduction

Game Development is an exciting field to explore in programming. It is a growing industry and employs a huge number of developers. This article will focus on the basics of game development for beginners to get started. The concepts are fundamental for game development in any language.

The following functions are fundamental for the development of any game:

* Setup() 
* Draw()
* Input()
* Logic()

**setup() -** 
This function initializes the game components. For eg. position, score, etc.

```cpp
void Setup()
{
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score = 0;
}
```
**draw() -** 
This function creates the visual components of the game. For eg. game characters

```cpp
void Draw()
{
	system("cls"); 
	for (int i = 0; i < width+2; i++)
		cout << "-";
	cout << endl;

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (j == 0)
				cout << "|";
			if (i == y && j == x)
				cout << "O";
			else if (i == fruitY && j == fruitX)
				cout << "*";
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						cout << "O";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}
				

			if (j == width - 1)
				cout << "|";
		}
		cout << endl;
	}
	for (int i = 0; i < width+2; i++)
		cout << "-";
	cout << endl;	
    cout << "Score:" << score << endl;
}
```

**input() -** 
This function manages inputs from the user in order to play/access the game. 
For eg. Control Keys

```cpp
void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}
```
**logic() -** 
This function manages the flow of the game. This is the most important component of the game that has logic. 

```cpp
void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	default:
		break;
	}
	//if (x > width || x < 0 || y > height || y < 0)
	//	gameOver = true;
	if (x >= width) x = 0; else if (x < 0) x = width - 1;
	if (y >= height) y = 0; else if (y < 0) y = height - 1;

	for (int i = 0; i < nTail; i++)
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;

	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitY = rand() % height;
		nTail++;
	}
}
```

---

So hope this helps you in getting started. Happy Coding.
