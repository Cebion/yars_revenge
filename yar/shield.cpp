/***************************************************************************
                          shield.cpp  -  shield class
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
//									Reset shield to either static or scroller
//
//	**************************************************************************************************************************

void Shield::Reset(int Scroll)
{
    int i,j;
    for (i = 0;i < 16;i++) Cell[i] = 0;         // Erase the shield
    SetColour();FillRect();
    ScrollType = Scroll;
    SetScale(P_SHIELDSIZE,P_SHIELDSIZE);        // Draw the shield bit off the main surface
    SetOrigin(0,P_SHIELDSIZE*16);
    for (i = 127;i > 0;i--)
    {
        SetColour(255-i*5/3,0,0);
        FrameRect(128-i,128-i,128+i,128+i);
    }
    SetScale();SetOrigin(0,0);
    for (i = 0;i < 16;i++)                      // Work through the cells
        for (j = 0;j < 8;j++)
    {
        int c = 1;                              // Solid
        if (IsScroller() == 0)                  // If not scroller give it the right shape
        {
            if (i >= 6 && i <= 9 && j > 4) c = 0;
            if (i < 4 && j < 4-i) c = 0;
            if (i >= 11 && j < i-11) c = 0;
        }
        SetShield(j,i,c);
    }
    NextScroll = SGWGameClock();                // Next scrolling time
}

//	**************************************************************************************************************************
//
//									Paint on the screen in curent state
//
//	**************************************************************************************************************************

void Shield::SetShield(int x,int y,int On)
{
    int Mask = 128 >> x;                        // Calculate stuff
    if (x < 0 || y < 0 || x >= 8 || y >= 16) return;
    int x1 = x * P_SHIELDSIZE;
    int y1 = y * P_SHIELDSIZE;
    if (((Cell[y] & Mask) != 0)                 // Has not changed
                    == (On != 0)) return;
    Cell[y] ^= Mask;                            // Changed !
    if (Cell[y] & Mask)                         // Draw either cell or space
    {
        SGWRect r(0,16*P_SHIELDSIZE,P_SHIELDSIZE-1,17*P_SHIELDSIZE-1);
        Copy(*this,r,x1,y1);
    }
    else
    {
        SetColour();
        FillRect(x1,y1,x1+P_SHIELDSIZE-1,y1+P_SHIELDSIZE-1);
    }   
}

//	**************************************************************************************************************************
//
//									Paint on the screen in curent state
//
//	**************************************************************************************************************************

int Shield::GetShield(int x,int y)
{
    if (x < 0 || y < 0 || x >= 8 || y >= 16) return 0;
    return (Cell[y] & (128 >> x)) != 0;
}

//	**************************************************************************************************************************
//
//									Paint on the screen in curent state
//
//	**************************************************************************************************************************

void Shield::Paint(Quotile &q)
{
    SGWRect r(0,0,8*P_SHIELDSIZE-1,16*P_SHIELDSIZE-1);
    if (IsScroller() &&                         // Do we scroll & is it time ?
                SGWGameClock() > NextScroll)
    {
        NextScroll = SGWGameClock()+60;
        int Curr[16];
        for (int i = 0;i < 16;i++)              // Roll the whole shield
                        Curr[i] = Cell[i];
        for (int i = 0;i < 16;i++)
        {
            for (int j = 0;j < 7;j++)
                SetShield(j+1,i,Curr[i] & (128 >> j));
            SetShield(0,i,Curr[(i-1)&15] & 1);  // Could be long winded... easier on a 2600 :)
        }
    }
    Copy(r,                                     // Write to display.
         LTOP(XEXT)-Width()-1,
         LTOP(q.GetQY())-P_SHIELDSIZE*8);
}

//	**************************************************************************************************************************
//
//									Does the given point collide with a shield cell ?
//
//	**************************************************************************************************************************

int Shield::ShieldCollide(int x,int y,int &xShield,int &yShield,Quotile &q)
{
    x = LTOP(x);y = LTOP(y);                    // Convert back to physical
    x = x - (LTOP(XEXT)-Width()-1);             // Offset from shield position
    y = y - (LTOP(q.GetQY())-P_SHIELDSIZE*8);
    if (x < 0 || y < 0) return 0;               // Off left,top
    xShield = x / P_SHIELDSIZE;                 // Convert to cell #
    yShield = y / P_SHIELDSIZE;
    if (xShield >= 8 || yShield >= 16) return 0;// out of range, return 0
    return GetShield(xShield,yShield);          // return 1 if cell there.
}

