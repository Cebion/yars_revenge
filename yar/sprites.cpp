/***************************************************************************
            sprites.cpp  -  sprite objects of various types
                             -------------------
    begin                : Fri Oct 10 2003
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
//							                Painting method for the base class
//
//	**************************************************************************************************************************

void Sprite::Paint(void)
{
    if (Visible)                                // If it is being drawn.
    {
        int x = LTOP(xPos) - P_SPRITESIZE/2;    // Where to paint it
        int y = LTOP(yPos) - P_SPRITESIZE/2;
        int x1,y1;        
        GetGraphic(x1,y1);                      // Get the graphic ccordinates
        SGWRect r(x1*P_SPRITESIZE,              // Convert to a physical rectangle
                  y1*P_SPRITESIZE,
                  (x1+1)*P_SPRITESIZE-1,
                  (y1+1)*P_SPRITESIZE-1);
        SpriteGraphics.Copy(r,x,y);             // Copy to screen

        if (0)                                  // Debugs sprite rectangles if '1'
        {
            SGWRect r;
            SGWDisplaySurface d;
            GetRect(r);
            d.SetColour(255,255,255);           
            d.FrameRect(LTOP(r.Left),LTOP(r.Top),LTOP(r.Right),LTOP(r.Bottom));
        }
    }
}

//	**************************************************************************************************************************
//
//							                Get bounding rectangle for sprite
//
//	**************************************************************************************************************************

void Sprite::GetRect(SGWRect &r)
{
    int w = PTOL(P_SPRITESIZE*Width()/256);
    int h = PTOL(P_SPRITESIZE*Height()/256);
    r.Left = GetX()-w/2;r.Right = GetX()+w/2;
    r.Top = GetY()-h/2;r.Bottom = GetY()+h/2;
}

//	**************************************************************************************************************************
//
//							           Collision between sprites (Rectangle based)
//
//	**************************************************************************************************************************

int Sprite::Collide(Sprite &s)
{
    SGWRect r1,r2;
    GetRect(r1);s.GetRect(r2);                  // Get the two rectangles
    if (abs((r1.Left+r1.Right)/2-(r2.Left+r2.Right)/2) > abs(r1.Left-r1.Right)/2+abs(r2.Left-r2.Right)/2)
        return 0;
    if (abs((r1.Top+r1.Bottom)/2-(r2.Top+r2.Bottom)/2) > abs(r1.Top-r1.Bottom)/2+abs(r2.Top-r2.Bottom)/2)
        return 0;
    return 1;
}
