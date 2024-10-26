//_____________________________________________________Header Files______________________________________________________________________________

#include<graphics.h>// to run graphics

#include<conio.h>//      to use getch() function

#include<string.h>//   to work with strings
//___________________________________________________Define Directives___________________________________________________________________________

#define left 65//                left of brick

#define top 35//                 top of brick

#define right 125//              right of brick

#define bottom 60//              bottom of brick

#define game_zone_start 55//     game zone left side

#define game_zone_end 935//      game zone right side

#define game_zone_up 25//        game zone upside

#define game_zone_down 645//     game zone downside

//___________________________________________________Global Variables____________________________________________________________________________

int col = 10;//                           total number of columns

int row = 5;//                            total rows of bricks

int ballX = 510, ballY = 606;//           initial position of ball

int ballRadius = 13;//                    radius of ball

int paddleX = 445, paddleY = 620;//       left and bottom of paddle

int paddleWidth=575, paddleHeight=645;//  right and height of paddle

int bricks[12][10];//                     array to make bricks

int bricksRemaining = 0;//                total number of bricks on the screen

int directionX = 2;//                     initial direction horizontally

int directionY = -2;//                    initial direction vertically

int score = 0;//                          initial score
//____________________________________________________Function Prototypes________________________________________________________________________

void open();//                   start the game

void starting();//               animation on starting

void mainmenu();//               Main menu of game

void key();//                    Key checker for in main menu

void play();//                   Function to start the game

void loading();//                animation on game play starting

void initialize();//             initialize the array for bricks

void draw();//                   Draw the elements of game

void mover();//                  Animate ball and paddle on action

void ballPaddleCollision();//    Ball and Paddle collision

void ballBrickCollision();//     Ball and Brick Collision

void scoredisplayer();//           Display score on the window

void gameStatus();//             Game Status

void restart();//                restart the game

void gameOver();//               Game over

void gameWin();//                Game Win

void pauseGame();//              Game Pause

void soundfunc();//              changing sound

void exitfunc();//               Exit window function



//_____________________________________________________Main Function_____________________________________________________________________________

int main()
{
    PlaySound("music files//losangeles.wav", NULL, SND_ASYNC | SND_LOOP);

    initwindow(1280, 720, "Brick Breaker");

    open();

    getch();

    closegraph();

    return 0;
}

//_________________________________________________open Function________________________________________________________________________________

void open()
{
    starting();

    mainmenu();
}

//__________________________________________________starting function__________________________________________________________________________


void starting()
{
    while(1)
    {
        setcolor(YELLOW);

        settextstyle(BOLD_FONT, HORIZ_DIR, 8);

        outtextxy(250, 250, "BRICK BREAKER GAME");

        setlinestyle(SOLID_LINE, SOLID_FILL, 7);

        rectangle(25, 25, 1255, 680);//                   full window border

        setfillstyle(SOLID_FILL, YELLOW);

        rectangle(450, 330, 940, 380);//                  loading bar border

        bar(460, 340, 590, 370);//                        loading bar 1

        delay(500);

        bar(460, 340, 750, 370);//                        loading bar 2

        delay(500);

        bar(460, 340, 930, 370);//                        loading bar 3

        delay(500);

        break;
    }
}

//________________________________________________________Main Menu___________________________________________________________________________

void mainmenu()
{
    cleardevice();

    settextstyle(BOLD_FONT, HORIZ_DIR, 9);

    rectangle(25, 25, 1255, 680);//                  border of game screen

    outtextxy(400, 60, "MAIN MENU");

    rectangle(400, 180, 900, 330);//                 rectangle around play

    rectangle(400, 330, 900, 480);//                 rectangle around sound

    rectangle(400, 480, 900, 630);//                 rectangle around exit

    outtextxy(535, 210, "PLAY");

    outtextxy(515, 355, "SOUND");

    outtextxy(540, 500, "EXIT");

    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 2);

    outtextxy(350, 650, "Enter F1 to play, F2 to change music and F3 to Exit");

    while(1)
    {
       key();
    }
}

//__________________________________________________________Key__________________________________________________________________________________

void key()
{
    if(GetAsyncKeyState(VK_F1))
    {
        play();
    }
    if(GetAsyncKeyState(VK_F2))
    {
        soundfunc();
    }
    if(GetAsyncKeyState(VK_F3))
    {
        exitfunc();
    }
}

//________________________________________________Game Play function____________________________________________________________________________

void play()
{
    int page=0;

    loading();

    initialize();

    while(1)
    {
        setactivepage(page);

        setvisualpage(1-page);

        draw();

        mover();

        gameStatus();

        scoredisplayer();

        page=1-page;
    }
}

//_____________________________________________________loading____________________________________________________________________________________

void loading()
{
    while(1)
    {
        cleardevice();

        setcolor(YELLOW);

        settextstyle(BOLD_FONT, HORIZ_DIR, 10);

        outtextxy(390, 220, "LOADING");

        setlinestyle(SOLID_LINE, SOLID_FILL, 7);

        rectangle(25, 25, 1255, 680);//                   full window border

        setfillstyle(SOLID_FILL, YELLOW);

        rectangle(405, 330, 910, 380);//                  loading bars border

        bar(415, 340, 590, 370);//                        loading bar 1

        delay(500);

        bar(415, 340, 750, 370);//                        loading bar 2

        delay(500);

        bar(415, 340, 900, 370);//                        loading bar 3

        delay(500);

        break;
    }
}

//_______________________________________________________________Initialize____________________________________________________________________

void initialize()
{
    for (int i = 0; i <= row; i++)
    {
        for (int j = 0; j <= col; j++)
        {
            bricks[i][j] = rand() % 2;

            if (bricks[i][j] == 1)
            {
                bricksRemaining++;//                   count the bricks initialized
            }
        }
    }
}

//__________________________________________________________Draw_______________________________________________________________________________

void draw()
{

    cleardevice();

    rectangle(50, 25, 940, 650);//                Game Zone

    rectangle(950, 25, 1230, 350);//              Score box

    rectangle(950, 370, 1230, 650);//             Name area

    outtextxy(1020, 460, "BRICK");

    outtextxy(1000, 510, "BREAKER");

    for (int i = 0; i <= row; i++)
    {
        for (int j = 0; j <=col; j++)
        {
            if (bricks[i][j] == 1)
            {
                setlinestyle(SOLID_LINE, SOLID_FILL, 3);
                rectangle(left + j * 80, top + i * 40, right + j * 80, bottom + i * 40);//   Draw the bricks
                if(i==0){
                    setfillstyle(SOLID_FILL,BLACK);
                    floodfill(left +6 + j * 80, top + 6 + i * 40,YELLOW);
                }
               else if(i==1){
                    setfillstyle(SOLID_FILL,RED);
                    floodfill(left +6 + j * 80, top + 6 + i * 40,YELLOW);
                }
                else if(i==2){
                    setfillstyle(SOLID_FILL,BLUE);
                    floodfill(left +6 + j * 80, top + 6 + i * 40, YELLOW);
                }
                else if(i==3){
                    setfillstyle(SOLID_FILL,GREEN);
                    floodfill(left +6 + j * 80, top + 6 + i * 40,YELLOW);
                }
                else if(i==4){
                    setfillstyle(SOLID_FILL,MAGENTA);
                    floodfill(left +6 + j * 80, top + 6 + i * 40, YELLOW);
                }
                else{
                    setfillstyle(SOLID_FILL,CYAN);
                    floodfill(left +6 + j * 80, top + 6 + i * 40,YELLOW);
                }
            }
        }
    }

    rectangle(paddleX, paddleY, paddleWidth, paddleHeight);//         Draw the paddle

    setfillstyle(SOLID_FILL, YELLOW);

    circle(ballX + directionX, ballY + directionY, 13);//              Draw the ball
}

//___________________________________________________________Mover________________________________________________________________________________

void mover()
{
    if (GetAsyncKeyState(VK_RIGHT) && paddleWidth < game_zone_end)
    {
        paddleX += 10;
        paddleWidth = paddleX+130;

        rectangle(paddleX, paddleY, paddleWidth, paddleY+25);
    }

    if (GetAsyncKeyState(VK_LEFT) && paddleX > game_zone_start)
    {
        paddleX -= 10;
        paddleWidth= paddleX+130;

        rectangle(paddleX, paddleY, paddleWidth, paddleY+25);
    }

    ballX = ballX + directionX;

    ballY = ballY + directionY;

    if (game_zone_start + ballRadius == ballX)
    {
        directionX = -directionX;
    }
    if (game_zone_end - ballRadius == ballX)
    {
        directionX = -directionX;
    }
    if (game_zone_up + ballRadius == ballY)
    {
        directionY = -directionY;
    }
    delay(1/75);

    ballPaddleCollision();

    ballBrickCollision();

    gameStatus();
}

//__________________________________________________________Ball Paddle Collision_________________________________________________________________

void ballPaddleCollision()
{
    if (ballX + ballRadius >= paddleX && ballX - ballRadius <= paddleWidth && ballY + ballRadius >= paddleY)
    {
        directionY = -directionY;
    }
}


//_______________________________________________________Ball Brick Collision_______________________________________________________________________

void ballBrickCollision()
{
    for (int i = 0; i <= row; i++)
    {
        for (int j = 0; j <= col; j++)
        {
            if (bricks[i][j] == 1)
            {
                if (ballX >= (left - ballRadius) + j * 80 && ballX <= (right + ballRadius) + j * 80 && ballY >= (top - ballRadius) + i * 40 && ballY <= (bottom + ballRadius) + i * 40)
                {

                    bricks[i][j]=0;


                    directionY = -directionY;

                    score++;

                    bricksRemaining--;
                }
            }
        }
    }
}
//___________________________________________________________Score Displayer_______________________________________________________

void scoredisplayer()
{
    char displayer[10];

    settextstyle(8, HORIZ_DIR, 5);

    outtextxy(1000, 100, "SCORE : ");

    sprintf(displayer, "%d", score);

    settextstyle(8, HORIZ_DIR, 5);

    outtextxy(1060, 200, displayer);
}
//__________________________________________________Game status_____________________________________________________________________________

void gameStatus()
{
    if(ballY >= game_zone_down)
    {
        gameOver();
    }
    if(bricksRemaining==4)
    {
        gameWin();
    }
    if(GetAsyncKeyState(VK_ESCAPE))
    {
       pauseGame();
    }
}

//____________________________________________________Game Over__________________________________________________________________________________

void gameOver()
{
        cleardevice();

        rectangle(25, 25, 1255, 680);//            Rectangle for border

        rectangle(400, 270, 900, 365);//           Rectangle for text display

        ballY=700;

        settextstyle(BOLD_FONT, HORIZ_DIR, 6);

        outtextxy(520, 245, "Game Over!");

        settextstyle(BOLD_FONT, HORIZ_DIR, 5);

        outtextxy(435, 300, "Press Spacebar to");

        settextstyle(BOLD_FONT, HORIZ_DIR, 6);

        outtextxy(560, 340, "RESTART");

        if(GetAsyncKeyState(VK_SPACE))
        {
            restart();
        }
}
//_____________________________________________________GameWin_________________________________________________________________________________

void gameWin()
{
        cleardevice();

        rectangle(25, 25, 1255, 680);//            Rectangle for border

        rectangle(400, 270, 900, 365);//           Rectangle for text display

        ballY=700;

        settextstyle(BOLD_FONT, HORIZ_DIR, 6);

        outtextxy(520, 245, "Game Win!");

        settextstyle(BOLD_FONT, HORIZ_DIR, 5);

        outtextxy(435, 300, "Press Spacebar to");

        settextstyle(BOLD_FONT, HORIZ_DIR, 6);

        outtextxy(540, 340, "RESTART");

        if(GetAsyncKeyState(VK_SPACE))
        {
            restart();
        }
}

//_____________________________________________________Restart___________________________________________________________________________________

void restart()
{
    col = 10;//                           total number of columns

    row = 5;//                            total rows of bricks

    ballX = 510, ballY = 606;//           initial position of ball

    ballRadius = 13;//                    radius of ball

    paddleX = 445, paddleY = 620;//       left and bottom of paddle

    paddleWidth=575, paddleHeight=645;//  right and height of paddle

    bricks[12][10];//                     array to make bricks

    bricksRemaining = 0;//                total number of bricks on the screen

    directionX = 2;//                     initial direction horizontally

    directionY = -2;//                    initial direction vertically

    score = 0;//                          initial score

    play();
}

//________________________________________________Game Pause_______________________________________________________________________

void pauseGame()
{
    while(1)
    {
        cleardevice();

        rectangle(25, 25, 1255, 645);//             BORDER

        rectangle(400, 270, 900, 365);//            Borders around the text

        settextstyle(BOLD_FONT, HORIZ_DIR, 6);

        outtextxy(480, 245, "GAME PAUSED");

        settextstyle(BOLD_FONT, HORIZ_DIR, 5);

        outtextxy(430, 300, "Press any key to");

        settextstyle(BOLD_FONT, HORIZ_DIR, 6);

        outtextxy(520, 340, "CONTINUE");

        getch();

        break;
    }
}
//_____________________________________________Sound Function_________________________________________________________________

void soundfunc()
{
   int key;

   cleardevice();

   rectangle(400, 140, 900, 540);

   settextstyle(BOLD_FONT, HORIZ_DIR, 8);

   outtextxy(540, 100, "MUSIC");

   settextstyle(EUROPEAN_FONT, HORIZ_DIR, 4);

   outtextxy(620, 190, "PRESS :");

   outtextxy(480, 240, "F1 -- CYBERPUNK");

   outtextxy(480, 290, "F2 -- DO IT NOW");

   outtextxy(480, 340, "F3 -- FUNKY");

   outtextxy(480, 390, "F4 -- GROOVE");

   outtextxy(480, 440, "F5 -- LOS ANGELES");

   outtextxy(480, 490, "F6 -- MUTE");

   outtextxy(320, 580, "Press Backspace to Back to Main Menu");

   while(1)
   {
       if(GetAsyncKeyState(VK_F1))
       {
          PlaySound(0, 0, 0);

          PlaySound("music files//cyberpunk.wav", NULL, SND_LOOP | SND_ASYNC);
        }
        if(GetAsyncKeyState(VK_F2))
        {
          PlaySound(0, 0, 0);

          PlaySound("music files//doitnow.wav", NULL, SND_LOOP | SND_ASYNC);
        }
        if(GetAsyncKeyState(VK_F3))
        {
          PlaySound(0, 0, 0);

          PlaySound("music files//funky.wav", NULL, SND_LOOP | SND_ASYNC);
        }
        if(GetAsyncKeyState(VK_F4))
        {
          PlaySound(0, 0, 0);

          PlaySound("music files//groove.wav", NULL, SND_LOOP | SND_ASYNC);
        }
        if(GetAsyncKeyState(VK_F5))
        {
          PlaySound(0, 0, 0);

          PlaySound("music files//losangeles.wav", NULL, SND_LOOP | SND_ASYNC);
        }
        if(GetAsyncKeyState(VK_F6))
        {
          PlaySound(0, 0, SND_LOOP | SND_ASYNC);
        }
        if(GetAsyncKeyState(VK_BACK))
        {
            mainmenu();
        }
   }
}
//_____________________________________Exit Function_________________________________________________________________________

void exitfunc()
{
    cleardevice();

    rectangle(400, 200, 900, 401);

    settextstyle(BOLD_FONT, HORIZ_DIR, 5);

    outtextxy(420, 210 , "Press Enter Key to ");

    outtextxy(590, 250, "EXIT");

    outtextxy(410, 290, "Press Any other key");

    outtextxy(520, 330, "to back to");

    outtextxy(540, 380, "MAIN MENU");

    while(1)
    {
       if(GetAsyncKeyState(VK_RETURN))
       {
          exit(0);
       }
       else if(GetAsyncKeyState(VK_BACK))
       {
          mainmenu();
       }
    }
}
