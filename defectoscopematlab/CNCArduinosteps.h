// CNCArduinosteps.h

#ifndef _CNCARDUINOSTEPS_h
#define _CNCARDUINOSTEPS_h
#include <elapsedMillis.h>
//#include <TimerOne.h>
//#include <TimerThree.h>
#include <TimerOne\TimerOne.h>
#include <TimerThree\TimerThree.h>

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
// ������� ��� ������� �� ������ �����������. ���������� ���� � ����, �� ������� ��������� �� ����� �����������, ����� ��������� ������� ������� �� ������������ ����� �����������
class CNCArduinostepsClass
{
public:
	struct currencoord
	{
		long currentXs;
		long currentYs;
	};
	struct currencoordunits
	{
		double currentXunits;
		double currentYunits;
	};
	void init();
	void setpins(byte dirx, byte diry, byte xsteppin, byte ysteppin, byte enablepin);
	void setdxdy(double dxXunits, double dxYunits);
	void setcalibration(double calibX, double calibY);
	void serialhandler(String command, long amount,String amountstri);
	
	currencoord getcurrencoord();
	currencoordunits getcurrentcoordunits();
	
	static  void Yinterpt(bool yplus); //���������� ���������� ����� �� ���������� ��������, � ������������� ���� ������������� �����������
	static  void Xinterpt(bool xplus);
private:

 protected:
	 long dxX, dxY; //DX of each axies in steps -  � �����
	 double dxXun, dxYun; //DX of each axies in units -  � ��
	 long totalXsteps,totalYsteps; //totalsteps
	 double calibrationX, calibrationY; //calibration to the system units (������� �� � ����� ����)
	 long currentX, currentY; //� �����
	 double currentXun, currentYun; // � ��
	 long testingstepsX, testingfreqX;
	 bool testingenableX;
	 byte testingdirX;
	 byte testingdirY;
	 byte DirX, DirY;
	 long maxX, maxY;
	 long xsize, ysize;
	 bool timer1s, timer3s;
	 bool coordintXe, coordintYe;
	 bool Xarrivd, Yarrivd;
	 void serialcalibratedx(String calibrcommand);
	 void calibrate(long maxcalibr);
	
	static  volatile long timer1steps, timer3steps,timer1stepsinter,timer3stepsinter;
	static  volatile long timer1stepsfull, timer3stepsfull;
	 static volatile long timer1freq, timer3freq;
	 void SetDirX(byte dirx);
		 void SetDirY(byte diry);
	 static volatile long timer1freqspeedup, timer3freqspeedup;
	 static volatile long timer1freqspeedupcoef, timer3freqspeedupcoef;
	 static volatile bool Xinterptconc, Yinterptconc,Xarrived,Yarrived,Xinterptconc2,Yinterptconc2;
	 static void ArrivedX();
	 static void ArrivedY();
	 
	// static void Yintert();
	// static void Xintert();
	 long desirX, desirdY; // where is next stop
	 byte Xpin, Ypin;
	 bool pinsset,calibset,dxdyset,zeroset;
	 byte DirpinX, DirpinY, Enablepin;
	 long StepsX(long stepsXf,long speedXf, byte directx); //steps engine in calibration factor. speed means delay in microseconds, wich mean the frequency
	 long StepsY(long stepsYf, long speedYf, byte directy);
	 void calculatecurcorunits(currencoord inputcurcor, currencoordunits &outputcurcorunits);
	 void GotoCoord(double Xmm, double Ymm);
	// void FreqStepsX(long stepsXf, long speedXf);
	// void FreqStepsY(long stepsYf, long speedYf);
	 void GotoZero();
	 static void StepXintr();
	 static void StepYintr();
	 void StepX(long speedX);
	 void StepY(long speedY);
	 void Arrivedtostop();
	 currencoord newcurcord;
	 currencoordunits newcurcordunits;




 

};

extern CNCArduinostepsClass CNCArduinosteps;

#endif

