/***************************************************************************
                          quotile.cpp  -  Quotile class
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

#define sQuotile        (0)                     // Quotile in normal position
#define sAttackStart    (1)                     // Spinning in normal position, ready to attack
#define sAttack         (2)                     // Attacking
#define sDestroyed      (3)                     // Quotile destroyed.

//	**************************************************************************************************************************
//
//                      Get the graphic to be used - either the quotile or the spinner
//
//	**************************************************************************************************************************

void Quotile::GetGraphic(int &x,int &y)
{
    switch(GetState())
    {
        case sQuotile:                          // Quotile (waiting....)
        case sDestroyed:
            x = (SGWSystemClock()/100%8);
            y = 4+x/4;
            x = x % 4;
            break;
        case sAttackStart:                      // The swirling attack star spirally thing
        case sAttack:
            x = SGWSystemClock()/30%4;
            y = 3;
            break;
    }
}

//	**************************************************************************************************************************
//
//                      Set the time at which the quotile will go into its pre-attack spin
//
//	**************************************************************************************************************************

void Quotile::SetAttackTime(void)
{
    FireTime = SGWGameClock()+500+6000*100*100/GameData.Skill()/GameData.Skill();
}

//	**************************************************************************************************************************
//
//                  The current vertical quotile position - this is independent of the attack position
//
//	**************************************************************************************************************************

int  Quotile::GetQY(void)
{
    int y,n = (Pos*GameData.Skill()/100)%1000;  // Position in cycle
    if (n < 250) y = n;                         // Work out real position -250..250
    if (n >= 250 && n < 750) y = 500-n;
    if (n >= 750) y = n-1000;
    y = y * QUOTILESWING / 250 / 2;             // Convert to swing degree
    return YEXT/2+y;
}
    
//	**************************************************************************************************************************
//
//                                          Run the process for the quotile
//
//	**************************************************************************************************************************

void Quotile::Process(void)
{
    if (GetState() == sQuotile ||               // Normal movement pattern.
        GetState() == sAttackStart)             // Not when in attack mode.
    {
        Pos++;
        MoveTo(XEXT-PTOL(P_SPRITESIZE)/2,GetQY());
    }
    switch(GetState())
    {
        case sQuotile:                          // Normal mode, go to attack spin when time up
            if (SGWGameClock() > FireTime)
            {
                SetState(sAttackStart);
                GameData.PlayLoop(4);
            }
            else
                GameData.Stop(4);
            break;
        case sAttackStart:                      // Spinning before attack, go to attack
            if (GetStateTime() > 2000*100/GameData.Skill())
            {
                SetState(sAttack);
                StartX = GetX();StartY = GetY();// Target
                TargetX = GameData.yar->GetX();
                TargetY = GameData.yar->GetY();
                if (TargetX == StartX) StartX--;// We divide by this - avoid /0 error.
            }
            break;
        case sAttack:                           // Charging after the player
            int p = GetStateTime()/10*XEXT/(abs(TargetX-StartX)+abs(TargetY-StartY));
            p = p * GameData.Skill()/100;
            int x = (int)((double)StartX+(TargetX-StartX)*p/100.0);
            int y = (int)((double)StartY+(TargetY-StartY)*p/100.0);
            MoveTo(x,y);
            if (x < 0 || y < 0 || y > YEXT)     // Reached left edge, top edge, bottom edge, reset
            {
                SetState(sQuotile);
                SetAttackTime();
            }
            break;        
    }
    if (Collide(*GameData.yar)                  // Check for collision
                    && GetState()!=sQuotile)  
    {
        if (GetState() != sDestroyed) GameData.yar->Explode();
        Hide();
        GameData.Stop(4);
    }
}

//	**************************************************************************************************************************
//
//                                                  Quotile Destroyed ?
//
//	**************************************************************************************************************************

int Quotile::IsDestroyed(void)
{
    return (GetState() == sDestroyed);
}

//	**************************************************************************************************************************
//
//                                              Destroy Quotile if appropriate
//
//	**************************************************************************************************************************

void Quotile::Destroy(void)
{
    int n = GetState();
    if (n != sDestroyed)
    {
        GameData.Stop(4);
        SetState(sDestroyed);
        if (n == sAttack) GameData.AddScore(6000);
        if (n == sAttackStart) GameData.AddScore(2000);
        if (n == sQuotile) GameData.AddScore(1000);
        Hide();
    }
}
