/***************************************************************************
                    graphics.cpp  -  sprite graphic objects
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
//								        Redraw all the sprites on the surface
//
//	**************************************************************************************************************************

void SpriteSurface::Redraw(void)
{
    SetColour();FillRect();                     // Fill with transparency
    SetScale(P_SPRITESIZE,P_SPRITESIZE);        // Means we always use 0-255,0-255 irrespective
    for (int i = 0;i < 4;i++)                   // 4 rotations of Yar
    {
        for (int y = 0;y < 3;y++)               // In 3 flying positions
        {
            SetOrigin(P_SPRITESIZE*i,           // Drawing positions
                                y*P_SPRITESIZE);
            DrawYar(i,y);
        }
        SetOrigin(P_SPRITESIZE*i,               // We draw the swirl next
                        P_SPRITESIZE*3);
        DrawSwirl(i);                           // This will be rotated 0,22.5,45 and 67.5 degrees
    }
    for (int i = 0;i < 8;i++)                   // Now draw 8 Quotiles (the base on the right)
    {
        SetOrigin(i % 4 * P_SPRITESIZE,(i / 4 + 4) * P_SPRITESIZE);
        if (i == 0)
            DrawQuotile(255,128,0);
        else
            DrawQuotile((i & 1) ? 255:0,(i & 2) ? 255 : 0,(i & 4) ? 255 : 0);
        SetOrigin(i % 4 * P_SPRITESIZE,(i / 4 + 6) * P_SPRITESIZE);
        if (i == 0)
            DrawCannon(255,128,0);
        else
            DrawCannon((i & 1) ? 255:0,(i & 2) ? 255 : 0,(i & 4) ? 255 : 0);
    }
    for (int i = 0;i < 16;i++)                  // Draw 16 explosions with increasing amounts of blobs
    {
        SetOrigin(i % 4 * P_SPRITESIZE,(i/4+8) * P_SPRITESIZE);
        for (int n = 0;n < i*3/2+4;n++)
        {
            int w = 16+i/2;
            int x = rand()%(255-w*2)+w;
            int y = rand()%(255-w*2)+w;
            int r = (n%4 == 0) ? 0 : 255;
            ShadowEllipse(x,y,w,r,255,255-r);
        }
    }
    SetOrigin(4 * P_SPRITESIZE,10*P_SPRITESIZE);// Bullet or whatever it is.
    ShadowEllipse(128,128,32,255,255,255);
    for (int i = 0;i < 10;i++)
    {
        SetOrigin(4 * P_SPRITESIZE,i * P_SPRITESIZE);
        SetScale(P_SPRITESIZE,P_SPRITESIZE);
        SetColour(0,255,255);
        Char(0,0,255,255,i+'0');
    }
}

//	**************************************************************************************************************************
//
//								                Draw a shadowed ellipse
//
//	**************************************************************************************************************************

void SpriteSurface::ShadowEllipse(int x,int y,int w,int r,int g,int b)
{
    for (int i = w;i >= 0;i--)
    {
        int p = 100-i*70/w;
        SetColour(r*p/100,g*p/100,b*p/100);
        FillEllipse(x-i,y-i,x+i,y+i);
    }
}

//	**************************************************************************************************************************
//
//						    Draw Yar (your character) given rotation and wing position
//
//	**************************************************************************************************************************

void SpriteSurface::DrawYar(int Rot,int y)
{
    Rotate = Rot;
    for (int i = 0;i <= 128;i++)                // Work from left to right
    {
        int ya = 32+(128-i)/2+y*32*(128-i)/128; // Work out wing start height
        int yb = 255;
        int p = 100-abs(i-64);                  // and the lighting effect
        int r = 60+y*20;
        if (i > r) yb = 255-(i-r)*2;            // inside of the wing
        if (i < 40) yb = 255-(40-i);            // outside corner
        if (yb > 255) yb = 255;
        RLine(i,ya,yb,255,255,0,p);             // Draw it, both halves
        RLine(255-i,ya,yb,255,255,0,p);
    }
    for (int i = 0;i < 32;i++)                  // Now draw the head
    {
        int ya = 0;                             // top and bottom
        int yb = 96-i*2;
        int p = (31-i)+68;
        if (i > 8) ya = (i-8);                  // clip corners
        RLine(128-i,ya,yb,0,255,255,p);         // draw both sides
        RLine(128+i,ya,yb,0,255,255,p);
    }
}

//	**************************************************************************************************************************
//
//							                Draw a rotated line
//
//	**************************************************************************************************************************

void SpriteSurface::RLine(int x,int y1,int y2,int r,int g,int b,int p)
{
    SetColour(r*p/100,g*p/100,b*p/100);         // The draw colour
    if (Rotate & 1)
    {
        if (Rotate == 1)
            y1 = 255-y1,y2 = 255-y2;
        Line(y1,x,y2,x);
    }
    else                                        // drawing vertical line
    {
        if (Rotate == 2)
            y1 = 255-y1,y2 = 255-y2;
        Line(x,y1,x,y2);
    }
}

//	**************************************************************************************************************************
//
//										        Draw a swirl
//
//	**************************************************************************************************************************

void SpriteSurface::DrawSwirl(int Angle)
{
    for (int Arm = 0;Arm < 4;Arm++)             // Each swirl has four arms
    {
        int StartAngle = Arm*90+Angle * 90 / 4; // Start Angle - there are 4 rotations 0 - 90 divided equally
        for (int i = 0;i < 128;i++)
        {
            double r = ((double)StartAngle-     // The rotation at this distance out
                            pow(i,1.14)) * 2.0 * 3.141 / 360.0;
            int x = (int)(cos(r)*i+128);        // The position
            int y = (int)(sin(r)*i+128);
            int w = (128-i)/12+1;               // Width of arm
            int p = 100-i/3;                    // Colour depth
            SetColour(255*p/100,128*p/100,0);
            FillRect(x-w,y-w,x+w,y+w);          // Draw a rectangle (it works !)
        }
    }
}

//	**************************************************************************************************************************
//
//										        Draw a quotile
//
//	**************************************************************************************************************************

void SpriteSurface::DrawQuotile(int r,int g,int b)
{
    for (int y = 0;y < 128;y++)                 // Top to bottom
    {
        int x1 = (y < 32) ? 0 : y+16;           // Left and right pos
        int x2 = (y < 8) ? 255 : 224;
        int p = 100-y/2;
        SetColour(r*p/100,g*p/100,b*p/100);     // Draw it shaded
        Line(x1,128-y,x2,128-y);
        Line(x1,128+y,x2,128+y);
        if (y > 16 && y < 96)                   // Hollowed out ?
        {
            x1 = x1 + 32;                       // Work out hollowing
            if (x1 < 48+32) x1 = 48+32;
            x2 = 224 - 32;
            SetColour();                        // And clear it.
            Line(x1,128-y,x2,128-y);
            Line(x1,128+y,x2,128+y);
        }
    }
}

//	**************************************************************************************************************************
//
//										        Draw a cannon
//
//	**************************************************************************************************************************

void SpriteSurface::DrawCannon(int r,int g,int b)
{
    for (int y = 0;y < 32;y++)                  // Top to bottom
    {
        int x1 = 32+y;                          // Left and right pos
        int x2 = 224-y;
        int p = 100-y*2;
        SetColour(r*p/100,g*p/100,b*p/100);     // Draw it shaded
        Line(x1,128-y,x2,128-y);
        Line(x1,128+y,x2,128+y);
    }
}

//	**************************************************************************************************************************
//
//										  Redraw the safety zone surface
//
//	**************************************************************************************************************************

void ZoneSurface::Redraw(void)
{
    for (int x = 0;x < 8;x++)                   // An array of blocks, 1/8 of with by 4 pixels high
        for (int y = 0;y < DEFAULT_SCY/4;y++)
            if (rand()%3 == 0)
            {
                int r = rand()%2?255:0;
                int g = rand()%2?255:0;
                int b = rand()%2?255:0;
                SetColour(r/2,g/2,b/2);
                FillRect(x*LTOP(ZONEWIDTH)/8,y*4,(x+1)*LTOP(ZONEWIDTH)/8-2,y*4+3);
                SetColour(r,g,b);
                FillRect(x*LTOP(ZONEWIDTH)/8+2,y*4+1,(x+1)*LTOP(ZONEWIDTH)/8-4,y*4+2);
            }
}

//	**************************************************************************************************************************
//
//									Paint on the screen in curent state
//
//	**************************************************************************************************************************

void ZoneSurface::Paint(void)
{
    int w = DEFAULT_SCY/16;                     // Do it in chunks this big, copying from original.
    int y = 0;
    srand(SGWSystemClock()/30*33);              // Is time dependent - changes at 50Hz -  not speed dependent
    while (y < DEFAULT_SCY)                     // Do till reached bottom
    {
        int h = w;                              // Size of chunk
        if (y + h > DEFAULT_SCY) h = DEFAULT_SCY-y;
        int p = rand()%(DEFAULT_SCY-h);         // Copy from here
        SGWRect r(0,p,LTOP(ZONEWIDTH)-1,p+h-1);
        Copy(r,LTOP(ZONEPOS),y);                // Do the copy
        y = y + h;
    }
}

