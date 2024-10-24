/***************************************************************************
                          main.cpp  -  main program
                              -------------------
    begin                : Fri Oct 10 18:55:05 BST 2003
    copyright            : (C) 2003 by Paul Robson
    email                : autismuk@autismuk.freeserve.co.uk
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include "yar.hxx"

int Skill(void) { return 100; }

int PlayGame(void)
{
    int a;
    SGWDisplaySurface Disp;
    Disp.SetColour(0,0,0);Disp.FillRect();
    Disp.SetColour(255,255,0);
    Disp.String(64,64,960,320,"Yar's Revenge");
    a = 420;
    Disp.SetColour(0,255,255);
    Disp.String(512-a,328,512+a,358,"Written by Paul Robson 2003");
    a = 320;
    Disp.SetColour(0,255,0);
    Disp.String(512-a,396,512+a,426,"Based on the Atari 2600 Game");
    a = 360;
    Disp.String(512-a,434,512+a,464,"created by Howard Scott Warshaw");
    Disp.SetColour(255,255,255);
    Disp.String(512-a,720,512+a,750,"Press Fire to start, Escape to exit");
    Disp.Flip();
    while (SGWExitKey() != 0 || SGWReadStick(a,a,a,a) != 0) {}

    while (SGWExitKey() == 0 && SGWReadStick(a,a,a,a) == 0) {}
    return (SGWExitKey() == 0);
}

int SGWMain(int argc, char *argv[])
{
    Game game;
    while (PlayGame()) game.Run();
    argc = argc;argv = argv;
    return 0;
}

char *SGWName(char *Name)
{
    Name = Name;
    return (char *)"Yar's Revenge";
}

