/***************************************************************************
               yar.cpp  -  Yar and EnergyMissile Sprite Object
                             -------------------
    begin                : Sat Oct 11 2003
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

#define sMoving     (0)                         // Default state, Yar moving normally.
#define sSpinning   (1)                         // Spinning around (first phase of explosion)
#define sExploding  (2)                         // Exploding (second phase of explosion)
#define sDead       (3)                         // Dead.

//	**************************************************************************************************************************
//
//									Select graphic dependent upon State of Yar.
//
//	**************************************************************************************************************************

void Yar::GetGraphic(int &x,int &y)
{
    switch(GetState())
    {
        case sMoving:                           // Moving normally
            switch(GetDX())                     // What graphic do I use ?
            {
                case -1:    x = 3;break;
                case 0:     x = (GetDY() < 0) ? 0 : 2;break;
                case 1:     x = 1;break;
            }
            y = SGWGameClock()/130 % 4;         // Animate it
            if (y == 3) y = 1;
            break;

        case sSpinning:                         // When spinning, spin clockwise
            x = GetStateTime()/110%4;
            y = 0;
            break;
            
        case sExploding:
            int i = 15-GetStateTime()/100;
            if (i < 0) i = 0;
            x = i % 4;y = i / 4+8;
            break;

    }
}

//	**************************************************************************************************************************
//
//					Methods requiring access to state constants which are local to this file
//
//	**************************************************************************************************************************

void Yar::Explode(void)
{
    if (GetState() == sMoving)
    {
        SetState(sSpinning);
        GameData.PlayLoop(3);
    }
}

int  Yar::IsDead(void)  { return (GetState() == sDead); }

//	**************************************************************************************************************************
//
//									    Process Yar (done at 50Hz normally)
//
//	**************************************************************************************************************************

void Yar::Process(void)
{
    int i,x,y,xs,ys,w,dx,dy,Fire;
    switch(GetState())
    {
        case sMoving:                           // Moving around normally
            w = PTOL(P_SPRITESIZE);             // Sprite size
            SGWReadStick(Fire,i,dx,dy);         // Read stick, update direction if appropriate
            if (dx != 0 || dy != 0)             // Moving ?
            {
                int xOld,yOld;
                SetDirection(dx,dy);            // Set direction
                x = GetX()+dx*XEXT/40/3;        // New position
                y = GetY()+dy*XEXT/40/3;
                if (x < w/2) x = w;             // Limit horizontally, wrap vertically
                if (x > XEXT-w/2) x = XEXT-w;
                if (y < 0 || y > YEXT) y = YEXT-y;
                xOld = GetX();yOld = GetY();
                MoveTo(x,y);                    // Move it.

                x = GetX()+dx*w/2;              // Look to see if we are eating the shield
                y = GetY()+dy*w/2;
                                                // If so, bounce off it.
                if (GameData.shield->ShieldCollide(x,y,xs,ys,*(GameData.quotile)))
                {                               // Remove the brick and bounce back
                    GameData.shield->SetShield(xs,ys,0);       
                    MoveTo(GetX()-dx*w/2,GetY()-dy*w/2);
                    Trons++;
                    GameData.AddScore(169);
                    GameData.Play(0);
                }
                if (Collide(*(GameData.quotile))) Trons=4;
                if (Trons >= 4)
                {
                    GameData.zorlon->Reload();
                    Trons = 0;
                }

            }
            x = GetX();y = GetY();              // Collision with shield ? Move back till clear.
            while (GameData.shield->ShieldCollide(x+w/2,y+w/2,xs,ys,*(GameData.quotile)) ||
                   GameData.shield->ShieldCollide(x+w/2,y-w/2,xs,ys,*(GameData.quotile)) ||
                   GameData.shield->ShieldCollide(x-w/2,y+w/2,xs,ys,*(GameData.quotile)) ||
                   GameData.shield->ShieldCollide(x-w/2,y-w/2,xs,ys,*(GameData.quotile)))
            {
                x = x - abs(GetDX())*w/3;
                y = y - GetDY()*w/3;
                MoveTo(x,y);
            }
            if (GameData.emissile->IsVisible() == 0 &&     // Time to fire ?
                                    Fire != 0 && InZone() == 0)
            {
                GameData.emissile->MoveTo(GetX(),GetY());
                GameData.emissile->SetDirection(GetDX(),GetDY());
                GameData.emissile->Show();
                GameData.Play(1);
            }
            if (Fire != 0)                      // Launch Zorlon Cannon
                GameData.zorlon->Launch();          
            break;

        case sSpinning:                         // Spinning prior to exploding
            if (GetStateTime() > 2000) SetState(sExploding);
            break;

        case sExploding:                        // Exploding
            if (GetStateTime() > 1600) SetState(sDead);
            break;

        case sDead:                             // Actually dead
            GameData.Stop(3);
            break;
    }
}

