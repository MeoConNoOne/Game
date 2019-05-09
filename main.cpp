#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
#include <cstdio>
#include <iomanip>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <windows.h>
#include "equation.h"
#include "drawer.h"


using namespace std;

SDL_Window* gWindow;
SDL_Renderer* gRenderer;
drawer gameDraw(gWindow, gRenderer);

void printIntro(){
    gameDraw.initWindow();

    /*for (int i = 0; i < 8; i++)
    {
        gameDraw.getImage("introScene1.png");
        SDL_Delay(100);
        gameDraw.getImage("introScene2.png");
        SDL_Delay(100);
    }
    gameDraw.getImage("introScene3.png");
    SDL_Delay(500);
    gameDraw.getImage("introScene4.png");
    SDL_Delay(500);
    gameDraw.getImage("introScene5.png");
    SDL_Delay(500);
    gameDraw.getImage("defusing.png");
    SDL_Delay(800);*/
    SDL_RenderClear(gRenderer);

}

string getStringEquationSum(equation eqSum)
{
    string finalString;
    stringstream ss;
    ss << eqSum.num1;
    finalString = ss.str();
    stringstream ss2;
    ss2 << eqSum.num2;
    finalString = finalString + " + " + ss2.str();
    stringstream ss3;
    ss3 << eqSum.num3;
    finalString = finalString + " = " + ss3.str();
    return finalString;
}
string getStringEquationSub(equation eqSub)
{
    string finalString;
    stringstream ss;
    ss << eqSub.num1;
    finalString = ss.str();
    stringstream ss2;
    ss2 << eqSub.num2;
    finalString = finalString + " - " + ss2.str();
    stringstream ss3;
    ss3 << eqSub.num3;
    finalString = finalString + " = " + ss3.str();
    return finalString;
}
string getStringEquationMul(equation eqMul)
{
    string finalString;
    stringstream ss;
    ss << eqMul.num1;
    finalString = ss.str();
    stringstream ss2;
    ss2 << eqMul.num2;
    finalString = finalString + " x " + ss2.str();
    stringstream ss3;
    ss3 << eqMul.num3;
    finalString = finalString + " = " + ss3.str();
    return finalString;
}
string getStringEquationDiv(equation eqDiv)
{
    string finalString;
    stringstream ss;
    ss << eqDiv.num1;
    finalString = ss.str();
    stringstream ss2;
    ss2 << eqDiv.num2;
    finalString = finalString + " : " + ss2.str();
    stringstream ss3;
    if((int)(eqDiv.num1) % (int)(eqDiv.num2) == 0) ss3 << fixed << setprecision(0) << eqDiv.num3;
    else ss3 << fixed << setprecision(2) << eqDiv.num3;
    finalString = finalString + " = " + ss3.str();
    return finalString;
}
string getLivesString(int live)
{
    string finalString;
    stringstream ss;
    ss << live;
    finalString = ss.str();
    return finalString;
}
string getPointString(int point)
{
    string finalString;
    stringstream ss;
    ss << point;
    finalString = ss.str();
    return finalString;
}
void printEq(equation eq ,int  calculate ,int live ,int point){

    gameDraw.getImage("defusing.png");
    gameDraw.printLive(getLivesString(live));
    gameDraw.printScoreMap(getPointString(point));
    SDL_Delay(300);
    if(calculate == 0) gameDraw.printEquation(getStringEquationSum(eq));
    else if(calculate == 1) gameDraw.printEquation(getStringEquationSub(eq)) ;
    else if(calculate == 2) gameDraw.printEquation(getStringEquationMul(eq)) ;
    else if(calculate == 3) gameDraw.printEquation(getStringEquationDiv(eq)) ;

    gameDraw.getButton("wrong.png", 30, 400, 165, 145);
    gameDraw.getButton("right.png", 210, 400, 165, 145);
    gameDraw.clearRender();
}


bool aKeyPressed(equation eq, int point) //check đúng sai sự kiện chuột
{
    SDL_Event playerAns;
    char ansChar = ' ';
    Uint32 startTime = SDL_GetTicks();
    int lastWidth = 0;
    int countTick = 0;
    int keys;
    unsigned int timeLimit;
    int step = 60;
    if (point < 5)
    {
        timeLimit = 2000;
        keys = 30;
    }
    else{
        timeLimit = 1000;
        keys = 10;
    }
    while(SDL_GetTicks() - startTime <= timeLimit){
        gameDraw.drawTimeLeft(lastWidth);
        if (SDL_PollEvent(&playerAns) != 0 && playerAns.type == SDL_KEYDOWN){
            if (playerAns.key.keysym.sym == SDLK_LEFT){
                ansChar = 'N';
                break;
            }
            if (playerAns.key.keysym.sym == SDLK_RIGHT){
                ansChar = 'Y';
                break;
            }
        }
        if (countTick > keys)
        {
            lastWidth += step;
            keys += countTick;
            countTick++;
        }
        countTick++;
    }
    if (ansChar == eq.key) return true;
    return false;

}



void gameOver(int point);


void startARound(int point , int live)
{
        srand(time(NULL));
        int calculate = rand() % 4;
        if (point == 0){
            printIntro();
        }
        else{
            gameDraw.resetAfterARound();
        }
        int lv;
        if (point > 5){
            if (point > 10){
                lv = 3;
            }
            else lv = 2;
        }
        else lv = 1;
        while ( live != 0){
        equation eq;
        if(calculate == 0) eq.getRandomEquationSum(lv);
        else if(calculate == 1) eq.getRandomEquationSub(lv);
        else if(calculate == 2) eq.getRandomEquationMul(lv);
        else if(calculate == 3) eq.getRandomEquationDiv(lv);

        printEq(eq ,calculate,live,point);
        if (aKeyPressed(eq, point)){
            point++;
            startARound(point,live);
        }
        else
        {
            live -- ;
            gameDraw.resetAfterARound();
        }
    }
    gameOver(point);

}

void printMenu()// Vẽ màn hình menu
{

    const int statButtonX = 40;
    const int startButtonY = 300;
    const int startButtonW = 145;
    const int startButtonH = 63;
    const int quitButtonX = 210;
    const int quitButtonY = 300;
    const int quitButtonW = 145;
    const int quitButtonH = 62;

    gameDraw.getImage("menu.png");
    gameDraw.getButton("startButton.png", statButtonX, startButtonY, startButtonW, startButtonH);
    gameDraw.getButton("quitButton.png", quitButtonX, quitButtonY, quitButtonW, quitButtonH);

    bool quit = false;
    SDL_Event e;
    while (!quit){

        if (SDL_PollEvent(&e) != 0 && e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT){
            int mouseX = e.button.x;
            int mouseY = e.button.y;
            if ((mouseX > statButtonX) && (mouseX < statButtonX + startButtonW) &&
                (mouseY > startButtonY) && (mouseY < startButtonY + startButtonH)){

                SDL_RenderClear(gRenderer);
                SDL_DestroyRenderer(gRenderer);
                SDL_DestroyWindow(gWindow);
                SDL_Quit();
                startARound(0 , 3);
                quit = true;

            }
            if ((mouseX > quitButtonX) && (mouseX < quitButtonX + quitButtonW) &&
                (mouseY > quitButtonY) && (mouseY < quitButtonY + quitButtonH))
                quit = true;
        }
    }

    SDL_RenderClear(gRenderer);
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
}

int main(int argc, char* argv[])
{

    gameDraw.initWindow();
    printMenu();
    return 0;
}

void gameOver(int point)
{
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
    gameDraw.initWindow();


    gameDraw.getImage("endGame1.png");
    SDL_Delay(200);
    gameDraw.getImage("endGame2.png");
    SDL_Delay(200);
    gameDraw.getImage("endGame3.png");
    SDL_Delay(200);
    gameDraw.getImage("endGame4.png");
    gameDraw.printScore(getPointString(point));
    bool quit = false;
    SDL_Event e;
    while (!quit){
        if (SDL_PollEvent(&e) != 0 && e.type == SDL_KEYDOWN){
            if (e.key.keysym.sym == SDLK_ESCAPE){
                quit = true;
            }
            else
            {
                SDL_RenderClear(gRenderer);
                SDL_DestroyRenderer(gRenderer);
                SDL_DestroyWindow(gWindow);
                SDL_Quit();
                startARound(0 ,3);
                quit = true;

            }
        }
    }
    SDL_RenderClear(gRenderer);
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);
    SDL_Quit();
}
