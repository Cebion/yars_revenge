/***************************************************************************
                    yar.hxx  -  header files, Yar's Revenge
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

#include "sgw.hxx"

#define LTOP(c) ((c) >> 8)                      // Conversion between logical and physical
#define PTOL(c) ((c) << 8)                      // values in logical unless stated otherwise

#define  XEXT       PTOL(DEFAULT_SCX)           // Screen size
#define  YEXT       PTOL(DEFAULT_SCY)
#define  ZONEWIDTH  PTOL(160)                   // Zone width
#define  ZONEPOS    PTOL(208)                   // Zone position
#define  QUOTILESWING PTOL(400)                 // Swing of quotile

#define  P_SPRITESIZE (48)                      // Size of sprite graphics - physical pixels
#define  P_SHIELDSIZE (20)                      // Size of shield brick - physical pixels

class SpriteSurface : public SGWTransparentSurface
{
    public:
        SpriteSurface() : SGWTransparentSurface(P_SPRITESIZE*5,P_SPRITESIZE*12) { Redraw(); }
    protected:
        void Redraw(void);
        void DrawYar(int Rot,int y);
        void DrawSwirl(int Spin);
        void DrawQuotile(int r,int g,int b);
        void DrawCannon(int r,int g,int b);       
        void RLine(int x,int y1,int y2,int r,int g,int b,int p);
        void ShadowEllipse(int x,int y,int w,int r,int g,int b);
    private:
        int  Rotate;
};

class ZoneSurface : public SGWTransparentSurface
{
    public:
        ZoneSurface() : SGWTransparentSurface(LTOP(ZONEWIDTH)) { Redraw(); }
        void Paint(void);
    protected:
        void Redraw(void);
};

class Yar;
class EnergyMissile;
class Quotile;
class DestroyerMissile;
class Shield;
class ZorlonCannon;

class Game
{
    public:
        Game();
        ~Game();
        int Skill(void) { return (Level-1)*8+100; }
        void Run(void);
        int RunLevel(void);
        void Paint(void);
        void Process(void);
        void AddScore(int n) { Score = Score + n; }
        void Reset(int ResetShield);
        void ResetAll(void) { Score = 0;Lives =4;Level = 1;Reset(1); }
        void Play(int Sound) { SFX[Sound]->Play(); }
        void PlayLoop(int Sound) { SFX[Sound]->PlayLoop(); }
        void Stop(int Sound) { SFX[Sound]->Stop(); }
        void StartLevel(void);
        void EndLevel(void);
        SpriteSurface *sprites;
        ZoneSurface *zone;
        Yar *yar;
        EnergyMissile *emissile;
        Quotile *quotile;
        DestroyerMissile *destroyer;
        Shield *shield;
        ZorlonCannon *zorlon;
        int Score;
        int Lives;
        int Level;
        SGWAudioObject *SFX[8];
};

class Sprite
{
    public:
        Sprite(SpriteSurface &s,Game &g) : SpriteGraphics(s),GameData(g) { Reset(); }
        void Reset(void) { MoveTo(XEXT/2,YEXT/2);Show();SetState(0); };
        void Paint(void);
        void MoveTo(int x,int y) { xPos = x;yPos = y; }
        int  GetX(void) { return xPos; }
        int  GetY(void) { return yPos; }
        void SetDirection(int dx,int dy) { DirX = dx; DirY = dy; }
        int  GetDX(void) { return DirX; }
        int  GetDY(void) { return DirY; }
        void Show(void) { Visible = 1; }
        void Hide(void) { Visible = 0; }
        void SetState(int New) { State = New;StateTime = SGWGameClock(); }
        int  GetState(void) { return State; }
        int  GetStateTime(void) { return SGWGameClock()-StateTime; }
        void Process(void) { };
        int  IsVisible(void) { return Visible; }
        void GetRect(SGWRect &r);
        int  Collide(Sprite &s);
    protected:
        virtual void GetGraphic(int &x,int &y) { x = y = 0; }
        virtual int Width(void)  { return 256; }
        virtual int Height(void) { return 256; }       
        SpriteSurface &SpriteGraphics;
        Game &GameData;
    private:
        int State,StateTime;
        int xPos,yPos;
        int Visible;
        int DirX,DirY;
};        

class EnergyMissile : public Sprite
{
    public:
        EnergyMissile(SpriteSurface &s,Game &g) : Sprite(s,g) { Reset(); }
        void Process(void);
        void Reset(void) { Sprite::Reset();Hide(); }
    protected:
        virtual int Width(void)  { return 64; }
        virtual int Height(void) { return 64; }
        virtual void GetGraphic(int &x,int &y) { x = 4;y = 10; }
};

class Yar : public Sprite
{
    public:
        Yar(SpriteSurface &s,Game &g) : Sprite(s,g) { SetDirection(1,0); }
        void Reset(void) { Sprite::Reset();SetDirection(1,0);Trons = 0; }
        void Process(void);
        void Explode(void);
        int  IsDead(void);
        int  InZone(void) { return (GetX() > ZONEPOS && GetX() < ZONEPOS+ZONEWIDTH); }
    protected:
        virtual void GetGraphic(int &x,int &y);
    private:
        int Trons;
};

class Quotile : public Sprite
{
    public:
        Quotile(SpriteSurface &s,Game &g) : Sprite(s,g) { Reset(); }
        void Reset(void) { Sprite::Reset();MoveTo(XEXT-PTOL(P_SPRITESIZE)/2,YEXT/2);SetAttackTime();Pos = 0; }
        void Process(void);
        int  GetQY(void);
        int  IsDestroyed(void);
        void Destroy(void);
    protected:
        virtual void GetGraphic(int &x,int &y);
        void SetAttackTime(void);
    public:
        int FireTime;
        int Pos;
        int StartX,StartY,TargetX,TargetY;
};

class DestroyerMissile : public Sprite
{
    public:
        DestroyerMissile(SpriteSurface &s,Game &g) : Sprite (s,g) { Reset(); }
        void Reset(void) { Sprite::Reset();MoveTo(XEXT*3/4,YEXT/2); }
        void Process(void);
    protected:
        virtual int Width(void)  { return 192; }
        virtual int Height(void) { return 64; }
        virtual void GetGraphic(int &x,int &y) { x = 3;y = 7; }
};

class Shield : public SGWTransparentSurface
{
    public:
        Shield() : SGWTransparentSurface(P_SHIELDSIZE*8,P_SHIELDSIZE*17) { Reset(0); }
        void Reset(int Scroll);
        void SetShield(int x,int y,int On);
        int  GetShield(int x,int y);
        int  ShieldCollide(int x,int y,int &xShield,int &yShield,Quotile &q);
        void Paint(Quotile &q);
        int  IsScroller(void) { return ScrollType; }
    private:
        int  ScrollType;
        int  NextScroll;
        int  Cell[16];
};

class ZorlonCannon : public Sprite
{
    public:
        ZorlonCannon(SpriteSurface &s,Game &g) : Sprite(s,g) { Reset(); }
        void Reset(void) { Sprite::Reset();MoveTo(PTOL(P_SPRITESIZE)/2,YEXT/2);Hide(); }
        void Process(void);
        void Launch(void);
        void Reload(void);
    protected:
        virtual int Width(void)  { return 192; }
        virtual int Height(void) { return 64; }
        virtual void GetGraphic(int &x,int &y);
};

class SwirlNoise : public SGWAudioBeep
{
    public:
        SwirlNoise(int Len) : SGWAudioBeep(100,Len) { CreateSwirlNoise(); }
    private:
        void CreateSwirlNoise(void);
};


class LowNoise : public SGWAudioBeep
{
    public:
        LowNoise(int Len) : SGWAudioBeep(100,Len) { CreateNoise(); }
    private:
        void CreateNoise(void);
};
