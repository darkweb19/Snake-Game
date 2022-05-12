#include <iostream>
#include <conio.h>
using namespace std;
bool gameover;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirection dir;

void setup()
{
    gameover = false;
    dir = STOP;
    x = width / 2;
    y = width / 2;
//    fruitX = rand() % width;
//    fruitY = rand() % height; 
    score = 0;
}

void draw()
{
    system("cls");
    cout << "Use WASD to play." <<endl;
    cout << "NOOOOB : Hehe" << endl;
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
            {
                cout << "#";
            }

            if (i == y && j == x)
                cout << "O";

            else if (i == fruitY && j == fruitX)
                cout << "F";

            else
                cout << " ";

            if (j == width - 1)
            {
                cout << "#";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
    {
        cout << "#";
    }
    cout << endl;
    cout << "Press  X to terminate. " << endl;
    cout << "Score : " << score <<endl;
}

void input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            x--;
            break;
        case 'w':
            dir = UP;
            y--;
            break;
        case 's':
            dir = DOWN;
            y++;
            break;
        case 'd':
            dir = RIGHT;
            x++;
            break;

        case 'x':
            gameover = true;
            break;
        }
    }
}

void logic()
{
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
    if(x > width || x <  0 || y > height || y < 0)
    gameover = true; 
    if(x == fruitX && y == fruitY){
        score += 10 ;
//        fruitX = rand() % width;
//        fruitY = rand() % height;
    }
}

int main()
{
    setup();
    while (!gameover)
    {
        draw();
        input();
        logic();
    }
    // sleep(10);
    return 0;
}
