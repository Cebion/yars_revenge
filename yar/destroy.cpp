/***************************************************************************
                   destroy.cpp  -  Destroyer/Energy Missile Classes
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

//	**************************************************************************************************************************
//
//									        Process method for destroyer missile
//
//	**************************************************************************************************************************

void DestroyerMissile::Process(void)
{
    int d = XEXT/44/32*100/GameData.Skill();
    int x = GetX(),y = GetY();
    x = x +  ((x < GameData.yar->GetX()) ? d : -d);
    y = y +  ((y < GameData.yar->GetY()) ? d : -d);
    MoveTo(x,y);
    if (Collide(*(GameData.yar)) && GameData.yar->InZone() == 0)
    {
        GameData.yar->Explode();
        Hide();
    }
}

//	**************************************************************************************************************************
//
//									 Process Energy Missile (done at 50Hz normally)
//
//	**************************************************************************************************************************

void EnergyMissile::Process(void)
{
    Shield &s = *(GameData.shield);
    if (IsVisible())                            // Only if visible
    {
        int xs,ys;
        MoveTo(GetX()+GetDX()*XEXT/50,          // Move to new position
               GetY()+GetDY()*YEXT/50);
        if (GetX() < 0 || GetX() > XEXT) Hide();// If off edge then terminate
        if (GetY() < 0 || GetY() > YEXT) Hide();
        if (s.ShieldCollide(GetX(),GetY(),      // Check for collision
                               xs,ys,*(GameData.quotile)))
        {
            GameData.AddScore(69);
            GameData.Play(2);
            if (s.IsScroller() || 1)            // Scroller, one brick at once
            {
                s.SetShield(xs,ys,0);
            }
            else
            {
                xs = xs + GetDX();              // Advance forward one - that + shape comes out.
                ys = ys + GetDY();
                s.SetShield(xs,ys,0);
                s.SetShield(xs-1,ys,0);
                s.SetShield(xs+1,ys,0);
                s.SetShield(xs,ys-1,0);
                s.SetShield(xs,ys+1,0);
            }
            Hide();
        }
    }
}
