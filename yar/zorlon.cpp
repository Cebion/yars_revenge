/***************************************************************************
                          zorlon.cpp  -  description
                             -------------------
    begin                : Mon Oct 13 2003
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

#define sHidden     (0)
#define sFollowing  (1)
#define sCrossing   (2)
#define sBouncing   (3)

//	**************************************************************************************************************************
//
//							                      Select Current Graphic
//
//	**************************************************************************************************************************

void ZorlonCannon::GetGraphic(int &x,int &y)
{
    x = (SGWSystemClock()/100%8);
    y = 6+x/4;
    x = x % 4;
}

//	**************************************************************************************************************************
//
//							                 Process Zorlon Cannon's movements
//
//	**************************************************************************************************************************

void ZorlonCannon::Process(void)
{
    int x,xs,ys;
    switch(GetState())
    {
        case sHidden:
            Hide();
            break;
        case sFollowing:
            Show();
            MoveTo(PTOL(P_SPRITESIZE)/2,GameData.yar->GetY());
            break;
        case sCrossing:
            x = YEXT/64*GameData.Skill()/100;
            MoveTo(GetX()+x,GetY());
            if (GetX() > XEXT) SetState(sHidden);
            if (GameData.shield->ShieldCollide(GetX(),GetY(),xs,ys,*(GameData.quotile)))
                SetState(sBouncing);
            if (Collide(*(GameData.yar)))
            {
                GameData.yar->Explode();
                SetState(sHidden);
            }
            if (Collide(*(GameData.quotile))) GameData.quotile->Destroy();
            break;
        case sBouncing:
            x = YEXT/64*GameData.Skill()/100;
            MoveTo(GetX()-x,GetY());
            if (GetX() < 0) SetState(sHidden);
            if (Collide(*(GameData.yar)))
            {
                GameData.yar->Explode();
                SetState(sHidden);
            }
            break;
    }
}

//	**************************************************************************************************************************
//
//							                 State setters for Zorlon Cannon
//
//	**************************************************************************************************************************

void ZorlonCannon::Launch(void)
{
    if (GetState() == sFollowing) SetState(sCrossing);
}

void ZorlonCannon::Reload(void)
{
    if (GetState() == sHidden) SetState(sFollowing);
}
