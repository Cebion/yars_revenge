/***************************************************************************
                    sgw.hpp  -  Header file for SDL Wrapper classes
                             -------------------
    begin                : Wed Oct  1 14:06:28 BST 2003
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

/* Note : this is the first C++ thing I've ever written, so I know the class
          design isn't very good, I'm not using it properly, etc. Gotta start
          somewhere - the next thing I write will be much better. But it works -
          though the sound thing isn't brilliant..... */
          
using namespace std;

#include <iostream>
#include <string>
#include <cstdlib>   // for free, malloc, rand, srand

#define DEFAULT_SCX		(1024)					// Default Screen Size and Depth
#define DEFAULT_SCY		(768)
#define DEFAULT_SCBPP	(0)
#define MAXSOUND        (16)                    // Maximum number of sounds

#define SGWASSERT(x)	if (!(x)) SGWERROR()	// ASSERT and ERROR macros
#define SGWERROR()	SGWFatalError(__LINE__,__FILE__)

int SGWMain(int argc,char *argv[]);				// Main program must be defined.
char *SGWName(char *Name);		    			// Return Window Caption Name must be defined
void SGWSetSpeed(int n);
void SGWFatalError(int Line,string File);		// Prototyping

int SGWGameClock(void);				            // No point in wrapping this, it just goes to SDL_GetTicks()
int SGWSystemClock(void);                       // This one is unaffected by the game speed.

int SGWReadStick(int &A,int &B,int &dx,int &dy);// Read a joystick
int SGWMouseClick(int &x,int &y);				// Read a mouse select - and - click
int SGWExitKey(void);

class SGWRect
{
	public:
		SGWRect() {}							// Constructors
		SGWRect(int x1,int y1,int x2,int y2) { Left = x1;Top = y1;Right = x2;Bottom = y2; }
		int Left,Top,Right,Bottom;				// The rectangle
};

class SGWSurface								// A basic Surface 
{
	public:
		SGWSurface(int x = 0,int y = 0,int Trans = 0,int UseDisplay = 0,char *File = NULL);		
		~SGWSurface();							

		void SetColour(int r,int g,int b);	
		void SetColour() { SetColour(-1,-1,-1); }
        void SetColour(int Col) { Colour = Col; }
		unsigned int GetColour(void) { return Colour; }
		int  Width(void)  { return xSize; }
		int  Height(void) { return ySize; }
		void SetOrigin(int x = 0,int y = 0) { xOrigin = x; yOrigin = y; }
		void SetScale(int x = 256,int y = 256) { xScale = x; yScale = y; }

		void Plot(int x1,int y1);
		void FillRect(int x1=0,int y1=0,int x2=0,int y2=0);
		void FillRect(SGWRect &r) { FillRect(r.Left,r.Top,r.Right,r.Bottom); }
		void FrameRect(int x1=0,int y1=0,int x2=0,int y2=0);
		void FrameRect(SGWRect &r) { FrameRect(r.Left,r.Top,r.Right,r.Bottom); }
		void FillEllipse(int x1=0,int y1=0,int x2=0,int y2=0);
		void FillEllipse(SGWRect &r) { FillEllipse(r.Left,r.Top,r.Right,r.Bottom); }
		void FrameEllipse(int x1=0,int y1=0,int x2=0,int y2=0);
		void FrameEllipse(SGWRect &r) { FrameEllipse(r.Left,r.Top,r.Right,r.Bottom); }
		void Line(int x1=0,int y1=0,int x2=0,int y2=0);

		void Copy(SGWSurface &Target,SGWRect &SrcRect,int x = 0,int y = 0);
		void Copy(SGWRect &SrcRect,int x = 0,int y = 0);
		void Copy(SGWSurface &Target,int x = 0,int y = 0);
		void Copy(int x = 0,int y = 0);

		void HorizontalMirror(int x1 = 0,int y1 = 0,int x2 = 0,int y2 = 0);
		void VerticalMirror(int x1 = 0,int y1 = 0,int x2 = 0,int y2 = 0);

		void Char(int x1=0,int y1=0,int x2=0,int y2=0,char c = ' ');
		void Char(SGWRect &r,char c) { Char(r.Left,r.Top,r.Right,r.Bottom,c); }
		void String(int x1=0,int y1=0,int x2=0,int y2=0,char *s = "");
		void String(SGWRect &r,char *s) { String(r.Left,r.Top,r.Right,r.Bottom,s); }

		void Flip(void);


	protected:
		void SortAndValidate(int &x1,int &y1,int &x2,int &y2);
		void PointProcess(int &x1,int &y1);

	private:
		void *sSurface;							// Surface = actually SDL_Surface but I don't wanna include SDL
		int xSize,ySize;						// Surface size (physical)
		unsigned int Colour;					// Drawing colour
		int IsTransparent;						// Set if transparent
		unsigned int TransColour;				// Transparency drawing colour
		int IsDisplay;							// Set if is the physical display object
		int xOrigin,yOrigin;					// Mobile origin and scaling
		int xScale,yScale;
} ;

class SGWTransparentSurface : public SGWSurface	// A surface but with transparency
{
	public:
		SGWTransparentSurface(int x = 0,int y = 0) : SGWSurface(x,y,1,0,NULL) { }
};

class SGWBitmapSurface : public SGWSurface		// A surface with a bitmap on it, one solid, one transparent
{
	public:
        SGWBitmapSurface(char *File) : SGWSurface(0,0,0,0,File) {}
};

class SGWTransparentBitmapSurface : public SGWSurface	
{
	public:
		SGWTransparentBitmapSurface(char *File) : SGWSurface(0,0,1,0,File) {}
};

class SGWDisplaySurface : public SGWSurface		// The actual physical display
{
	public:
		SGWDisplaySurface(int x = 0,int y = 0) : SGWSurface(0,0,0,1,NULL) { }
};

class SGWTimer                                  // A simple timer
{
	public:
		SGWTimer(int TimeOut = 0);
		void ResetTimer(int t = 0);
		unsigned int Elapsed(void);
		int TimedOut(void);
		void WaitTimer(void);	

	private:
		int StartClock;
		int EndClock;
		int EventTime;
};

class SGWAudioObject                            // An audio object
{
    public:
        SGWAudioObject()   { Data = NULL; Position = Length = 0;Attach(); SoundOn = 0;LoopSound = 0; }
        ~SGWAudioObject()  { Detach();if (Data != NULL) free(Data); }
        void CopyStream(void *Stream,int Reqd);
        void Play(void) { Position = 0;SoundOn = 1; }
        void PlayLoop(void) { Position = 0;SoundOn = 1;LoopSound = 1; }
        void Stop(void) { SoundOn = 0; LoopSound = 0; }
        int  Size(void) { return Length/2; }
        void Write(int Pos,int Dat);
    protected:
        void Attach(void);
        void Detach(void);
        void *Data;
        int Position;
        int Length;
        int SoundOn;
        int LoopSound;
};

class SGWAudioWave : public SGWAudioObject
{
    public:
        SGWAudioWave(char *File) : SGWAudioObject() { Load(File); }
    protected:
        void Load(char *File);
};

class SGWAudioBeep : public SGWAudioObject
{
    public:
        SGWAudioBeep(int p,int l) : SGWAudioObject() { CreateBeep(p,l); }
    protected:
        void CreateWave(void *Data,int Size,int sPitch);
        void CreateBeep(int sPitch,int sLength);
};

class SGWAudioNoise : public SGWAudioBeep 
{
    public:
        SGWAudioNoise(int l) : SGWAudioBeep(0,l) { }
};

