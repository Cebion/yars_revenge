/***************************************************************************
                          game.cpp  -  game class
                             -------------------
    begin                : Sun Oct 12 2003
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


//	**************************************************************************************************************************
//
//							                Create all objects, set up etc.
//
//	**************************************************************************************************************************

Game::Game()
{    
    sprites = new SpriteSurface;
    zone = new ZoneSurface;
    shield = new Shield;
    yar = new Yar(*sprites,*this);
    emissile = new EnergyMissile(*sprites,*this);
    quotile = new Quotile(*sprites,*this);
    destroyer = new DestroyerMissile(*sprites,*this);
    zorlon = new ZorlonCannon(*sprites,*this);
    for (int i = 0;i < 8;i++) SFX[i] = NULL;
    SFX[0] = new SGWAudioBeep(1200,80);
    SFX[1] = new SGWAudioBeep(500,80);
    SFX[2] = new SGWAudioBeep(200,130);
    SFX[3] = new SGWAudioNoise(500);
    SFX[4] = new SwirlNoise(800);
    SFX[5] = new LowNoise(1000);
    ResetAll();
}

//	**************************************************************************************************************************
//
//							                    Delete all objects
//
//	**************************************************************************************************************************

Game::~Game()
{
    delete sprites;
    delete zone;
    delete shield;
    delete yar;
    delete emissile;
    delete quotile;
    delete destroyer;
    delete zorlon;
    for (int i = 0;i < 8;i++)
        if (SFX[i] != NULL) delete(SFX[i]);
}

//	**************************************************************************************************************************
//
//							                 Reset the game for a new level
//
//	**************************************************************************************************************************

void Game::Reset(int ResetShield)
{
    if (ResetShield) shield->Reset((Level & 1) == 0);
    yar->Reset();
    emissile->Reset();
    quotile->Reset();
    destroyer->Reset();
    zorlon->Reset();
}

//	**************************************************************************************************************************
//
//							                 Repaint the whole display
//
//	**************************************************************************************************************************

void Game::Paint(void)
{
    SGWDisplaySurface Disp;
    char sScore[8];
    Disp.SetColour(0,0,0);Disp.FillRect();
//  sprites->Copy(512,0);
    yar->Paint();
    shield->Paint(*quotile);
    emissile->Paint();
    destroyer->Paint();
    zone->Paint();
    quotile->Paint();
    zorlon->Paint();
    sprintf(sScore,"%07d",Score);
    for (int i = 0;i < 7;i++)
    {
        int n = (sScore[i] - '0')*P_SPRITESIZE;
        SGWRect r(4*P_SPRITESIZE,n,5*P_SPRITESIZE-1,n+P_SPRITESIZE-1);
        sprites->Copy(r,10+i*P_SPRITESIZE,10);
    }
    for (int i = 0;i < Lives-1;i++)
    {
        SGWRect r(0,0,P_SPRITESIZE-1,P_SPRITESIZE-1);
        sprites->Copy(r,1020-(i+1)*(P_SPRITESIZE*9/8),10);
    }        
    Disp.Flip();
}

//	**************************************************************************************************************************
//
//							                    Process all objects
//
//	**************************************************************************************************************************

void Game::Process(void)
{
    yar->Process();
    emissile->Process();
    quotile->Process();
    destroyer->Process();
    zorlon->Process();
}

//	**************************************************************************************************************************
//
//							                    Creates the swirly noise
//
//	**************************************************************************************************************************

void SwirlNoise::CreateSwirlNoise(void)
{
    int Steps = 32;
    for (int i = 0;i < Steps;i++)
    {
        int Start = i*Size()/Steps;
        for (int n = 0;n < Size()/Steps;n++)
        {
            if (n/(i+3)%2) Write(Start+n,-32000);else Write(Start+n,32000);
        }        
    }
}

//	**************************************************************************************************************************
//
//							                    Underlying low hum
//
//	**************************************************************************************************************************

void LowNoise::CreateNoise(void)
{
    for (int i = 0;i < Size();i++)
    {
        int v = (i & 256) ? 4000 : -4000;
        Write(i,v);
    }
}

//	**************************************************************************************************************************
//
//							                      Run a complete game
//
//	**************************************************************************************************************************

void Game::Run(void)
{
    ResetAll();
    while (SGWExitKey() == 0 && Lives > 0)
    {
        Reset(0);
        int Result = RunLevel();
        if (Result)
        {
            Level++;
            Reset(1);
        }
        else
            Lives--;
    }
}

//	**************************************************************************************************************************
//
//							                    Main game execution loop
//
//	**************************************************************************************************************************

int Game::RunLevel(void)
{
    StartLevel();
    PlayLoop(5);
    int Next = SGWGameClock();
    while (SGWExitKey() == 0 && yar->IsDead() == 0 && quotile->IsDestroyed() == 0)
    {
        while (SGWGameClock() > Next)
        {
            Next += 20;
        }
        Process();
        Paint();
    }
    for (int i = 0;i < 8;i++)
        if (SFX[i] != NULL) SFX[i]->Stop();
    if (quotile->IsDestroyed()) EndLevel();
    return quotile->IsDestroyed();
}

//	**************************************************************************************************************************
//
//							                      Start of Level stuff
//
//	**************************************************************************************************************************

void Game::StartLevel(void)
{
    SGWDisplaySurface Disp;
    char Lvl[9];
    Disp.SetColour(0,0,0);Disp.FillRect();
    SGWRect r(256,284,768,484);
    Disp.SetColour(255,255,0);
    Disp.String(r,"Level   ");
    sprintf(Lvl,"      %02d",Level % 100);
    Disp.SetColour(0,255,255);
    Disp.String(r,Lvl);
    Disp.Flip();
    SGWTimer e(2000);
    e.WaitTimer();
}

//	**************************************************************************************************************************
//
//							            End of Level (Quotile Destroyed) stuff
//
//	**************************************************************************************************************************

void Game::EndLevel(void)
{
    SGWDisplaySurface Disp;
    for (int i = 0;i < 38*3;i++)
    {
        SGWTimer e(30);
        int l = i % 38*10;
        Disp.SetColour(rand()&255,rand()&255,rand()&255);
        Disp.FillRect(0,384-l-10,1023,384-l);
        Disp.FillRect(0,384+l,1023,384+l+10);
        Disp.Flip();
        e.WaitTimer();
    }        
}

