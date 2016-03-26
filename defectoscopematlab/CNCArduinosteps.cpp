// 
// 
// 

#include "CNCArduinosteps.h"
#include <TimerOne.h>
#include <TimerThree.h>
CNCArduinostepsClass CNCArduinosteps;
volatile long CNCArduinostepsClass::timer1steps;
volatile long CNCArduinostepsClass::timer1stepsfull;
volatile long CNCArduinostepsClass::timer1freq;
volatile long CNCArduinostepsClass::timer1freqspeedup;
volatile long CNCArduinostepsClass::timer1freqspeedupcoef;
volatile bool CNCArduinostepsClass::Yinterptconc;
volatile long CNCArduinostepsClass::timer3steps;
volatile long CNCArduinostepsClass::timer3stepsinter;
volatile long CNCArduinostepsClass::timer1stepsinter;
volatile long CNCArduinostepsClass::timer3stepsfull;
volatile long CNCArduinostepsClass::timer3freq;
volatile long CNCArduinostepsClass::timer3freqspeedup;
volatile long CNCArduinostepsClass::timer3freqspeedupcoef;
volatile bool CNCArduinostepsClass::Xinterptconc;
volatile bool CNCArduinostepsClass::Xinterptconc2;
volatile bool CNCArduinostepsClass::Yinterptconc2;
volatile bool CNCArduinostepsClass::Xarrived;
volatile bool CNCArduinostepsClass::Yarrived;
//void CNCArduinostepsClass::ArrivedX();
void CNCArduinostepsClass::init()
{
	pinsset = false;
	calibset = false;
	//Timer1.initialize(0);
	Yinterptconc = false;
	Xinterptconc = false;
	dxdyset = false;
	Enablepin = 52;
	DirpinX = 46;
	DirpinY = 44;
	maxscanset = false;
	xsize = 631;
	ysize = 886;
	
	

}

//void CNCArduinostepsClass::Yinterpt()
//{
	//Yinterptconc = true;
//	Serial.println("Yconv");
//}
void CNCArduinostepsClass::StepX(long speedX)
{
	
	//elapsedMicros tolrx = 0;
	//digitalWrite(led, digitalRead(led) ^ 1);
	//digitalWrite(Xpin, LOW);
	PORTB = B00000000;
	//long itrk = tolr;
	//Serial.println(speedX);
	//delay(speedX);

	delayMicroseconds(speedX);

	//long itrek = tolr;
	//while (tolrx < speedX)
	//{
		//long itrk = tolrx;
		//	Serial.println(itrk);
//	}
	//long itrek = tolrx;
	//Serial.println(itrek);
	//if (tolr > speedX)
	//{
	//	long itrk = tolr;
	//	Serial.println(itrk);
	//	return 1;
	//}
	//digitalWrite(Xpin,HIGH);
	PORTB = B01000000;

}
void CNCArduinostepsClass::StepY(long speedY)
{
	//elapsedMicros tolry = 0;
	//digitalWrite(2, LOW);
	//digitalWrite(12, digitalRead(12) ^ 1);
	//long itrk = tolr;
	//Serial.println(speedX);
	//delay(speedX);
	PORTB = B00000000;
	delayMicroseconds(speedY);

	//long itrek = tolr;
	//while (tolry < speedY)
	//{

	//}
	//long itrek = tolry;
	//Serial.println(itrek);
	//if (tolr > speedX)
	//{
	//	long itrk = tolr;
	//	Serial.println(itrk);
	//	return 1;
	//}
	//digitalWrite(2, HIGH);
	PORTB = B10000000; //PORTB & B11111110;
}

void CNCArduinostepsClass::Arrivedtostop()
{
	//int gkk = 4445;
	//long kjfri = 4985495;
	//long oiuiuoi = 4877848;
	//String info = String(gkk) + '&' + String(kjfri) + '&' + String(oiuiuoi);
	//Serial.println(info);
}

void CNCArduinostepsClass::serialcalibratedx(String calibrcommand) // установка dxX и dxY с парсингом команды по последовательному порту
{
	//String calibrationtemp = calibrcommand.substring(0, calibrcommand.indexOf('&'));
	String dxtemp = calibrcommand;
	//Serial.println(calibrationtemp);
	//Serial.println(dxtemp);
	//double calibrationXtemp = calibrationtemp.substring(0, calibrationtemp.indexOf('$')).toFloat();
	//Serial.println(calibrationXtemp);
	//double calibrationYtemp = calibrationtemp.substring(calibrationtemp.indexOf('$') + 1, calibrationtemp.length()).toFloat();
	//Serial.println(calibrationYtemp);
	double dxXtemp = dxtemp.substring(0, dxtemp.indexOf('$')).toFloat();
	Serial.println(dxXtemp);
	double dxYtemp = dxtemp.substring(dxtemp.indexOf('$') + 1, dxtemp.length()).toFloat();
	Serial.println(dxYtemp);
	//double calibrationXtemp = amountstri.substring(0, amountstri.indexOf('$')).toFloat();
	///Serial.println(amountstri.substring(0, amountstri.indexOf('$')));
	//double calibrationYtemp = amountstri.substring(amountstri.indexOf('$')+1, amountstri.indexOf('&')).toFloat();
	//Serial.println(amountstri.substring(amountstri.indexOf('$')+1, amountstri.indexOf('&')));
	//double dxXtemp = amountstri.substring(amountstri.indexOf('&')+1, amountstri.indexOf('$')).toFloat();
	//Serial.println(amountstri.substring(amountstri.indexOf('&')+1, amountstri.indexOf('$')));
	//double dxYtemp = amountstri.substring(amountstri.indexOf('$')+1, amountstri.indexOf('#')).toFloat();
	//Serial.println(amountstri.substring(amountstri.indexOf('$')+1, amountstri.indexOf('#')));
	//Serial.println(calibrationXtemp);
	//Serial.println(calibrationYtemp);
	//Serial.println(dxXtemp);
	//Serial.println(dxYtemp);
	//setcalibration(calibrationXtemp, calibrationYtemp);
	setdxdy(dxXtemp, dxYtemp);

}

void CNCArduinostepsClass::calibrate(long maxcalibr,bool simulcalibr)
{
	xsize = 631;
	ysize = 886;
	//Serial.println(xsize);
	//Serial.println(ysize);
	GotoZero();
	delay(1000);
	long clbtr = 0;
	currencoord calibg;
	//long maxcalib = maxcalibr;
	if (maxcalibr < 2)
	{
		maxcalibr = 2;
	}
	
	Serial.println(xsize);
	Serial.println(ysize);
	if (!simulcalibr) {
		long totalstepsclbx = 0;
		maxX = 0;
		for (clbtr = 0;clbtr < maxcalibr;clbtr++)
		{
			if (DirX == 1)
			{
				DirX = 0;
			}
			else if (DirX == 0)
			{
				DirX = 1;
			}
			Serial.println(DirX);
			digitalWrite(DirpinX, DirX);

			maxX = 0;
			long totalxsteps = StepsX(100000, 1000, DirX);
			totalstepsclbx = totalxsteps + totalstepsclbx;
			Serial.println(totalstepsclbx);
			Serial.println(maxX);
			delay(1000);
		}
		GotoZero();
		delay(1000);
		clbtr = 0;
		Serial.print("X-");
		Serial.println(totalstepsclbx);
		long totalstepsclby = 0;
		maxY = 0;
		for (clbtr = 0;clbtr < maxcalibr;clbtr++)
		{
			if (DirY == 1)
			{
				DirY = 0;
			}
			else if (DirY == 0)
			{
				DirY = 1;
			}
			Serial.println(DirY);
			digitalWrite(DirpinY, DirY);

			maxY = 0;
			long totalysteps = StepsY(100000, 1000, DirY);
			totalstepsclby = totalysteps + totalstepsclby;
			Serial.println(totalstepsclby);
			Serial.println(maxY);
			delay(1000);
		}

		Serial.print("Y-");
		Serial.println(totalstepsclby);
		Serial.println(maxX);
		totalstepsclbx = totalstepsclbx / clbtr;
		maxX = totalstepsclbx;
		totalstepsclby = totalstepsclby / clbtr;
		maxY = totalstepsclby;
		calibg.currentXs = totalstepsclbx;
		calibg.currentYs = totalstepsclby;
	}
	else
	{
		long totalstepsclbx = 0;
		long totalstepsclby = 0;

		maxX = 0;
		maxY = 0;
		for (clbtr = 0;clbtr < maxcalibr;clbtr++)
		{
			if (DirX == 1)
			{
				DirX = 0;
			}
			else if (DirX == 0)
			{
				DirX = 1;
			}
			if (DirY == 1)
			{
				DirY = 0;
			}
			else if (DirY == 0)
			{
				DirY = 1;
			}
			//Serial.println(DirX);
			digitalWrite(DirpinX, DirX);
			digitalWrite(DirpinY, DirY);

			maxX = 0;
			maxY = 0;
			//long totalxsteps = StepsX(100000, 1000, DirX);
			calibg = simultengoxy(100000, 100000,1000,1000);
			calibg.currentXs = calibg.currentXs + calibg.currentXs;
			calibg.currentYs = calibg.currentYs + calibg.currentYs;
			//totalstepsclbx = totalxsteps + totalstepsclbx;
			//Serial.println(totalstepsclbx);
			//Serial.println(maxX);
			delay(1000);
		}
		calibg.currentXs = calibg.currentXs/clbtr;
		calibg.currentYs = calibg.currentYs/clbtr;
		GotoZero();
	}
	Serial.println(calibg.currentXs);
	Serial.println("ss");
	Serial.println(calibg.currentYs);

	double tempclx = (double)xsize / (double)calibg.currentXs;
	double tempcly = (double)ysize / (double)calibg.currentYs;
	//calibrationX = 
	//calibrationY = (double)ysize / (double)totalstepsclby;
	calibset = true;
	setcalibration(tempclx, tempcly);

	Serial.println(tempclx,6);
	Serial.println(tempcly, 6);
	zeroset = false;
	GotoZero();
	//setdxdy(100, 100);
}

void CNCArduinostepsClass::ArrivedX()
{
	Serial.println(timer1stepsinter);
	Xarrived = true;
	Serial.println("arivdX");
}

void CNCArduinostepsClass::ArrivedY()
{
	Serial.println(timer3stepsinter);
	Yarrived = true;
	Serial.println("arivdY");
}

//void CNCArduinostepsClass::Yintert()
//{
	
//	Serial.println("Yconv");
//}

//void CNCArduinostepsClass::Xintert()
//{
//}

void CNCArduinostepsClass::Scan(bool firststepgo)
{
	Serial.println(pinsset);
	Serial.println(dxdyset);
	Serial.println(maxscanset);
	Serial.println(calibset);
	returncoordtomatlab();
	bool going = false;
	
	if (pinsset && dxdyset &&maxscanset && calibset)
	{
		Serial.print("gort");
		Serial.println(newcurcordunits.currentXunits + dxXun);
		Serial.println(scanxbackwards);
		Serial.println(newcurcordunits.currentXunits);
		Serial.println(newcurcordunits.currentYunits);
		Serial.print("fgfg - ");
		Serial.println(newcurcordunits.currentXunits - dxXun);
		if (firststepgo) {
			Serial.println(firstscanX);
			Serial.println(firstscanY);
			GotoCoord(firstscanX, firstscanY);
			
			Serial.println(newcurcordunits.currentXunits);
			Serial.println(newcurcordunits.currentYunits);
			//Serial.print("fgfg - ");
			//Serial.println(newcurcordunits.currentXunits - dxX);
			//Serial.print("SCor"); // scancoordinates for mathlab
			returncoordtomatlab();
			//Serial.print(newcurcordunits.currentXunits+'$'+ newcurcordunits.currentYunits + '\n');
			scanxbackwards = false;
			//Serial.print(newcurcordunits.currentYunits+'\n');
		}
		else
		{
			if (newcurcord.currentXs+dxX <= maxXscansize && !scanxbackwards &&!going)
			{
				
				GotoCoord(newcurcordunits.currentXunits + dxXun, newcurcordunits.currentYunits);
				returncoordtomatlab();
				going = true;
			}
			else if (newcurcord.currentXs + dxX > maxXscansize && newcurcord.currentYs + dxY <= maxYscansize && !scanxbackwards &&!going)
			{
				GotoCoord(newcurcordunits.currentXunits, newcurcordunits.currentYunits+dxYun);
				returncoordtomatlab();
				scanxbackwards = true;
				going = true;
			}
			else if (newcurcord.currentXs-dxX>=firstscanXsteps && scanxbackwards&&!going)
			{
				GotoCoord(newcurcordunits.currentXunits-dxXun, newcurcordunits.currentYunits);
				returncoordtomatlab();
				going = true;
				
			}
			else if (newcurcord.currentXs - dxX < firstscanXsteps && scanxbackwards && newcurcord.currentYs + dxY <= maxYscansize&&!going)
			{
				GotoCoord(newcurcordunits.currentXunits, newcurcordunits.currentYunits + dxYun);
				returncoordtomatlab();
				going = true;
				scanxbackwards = false;
				
			}
		}


	}
	else
	{
		Serial.println("Missing settings");
	}
}

long CNCArduinostepsClass::StepsX(long stepsXf, long speedXf,byte directx)
{
	if (DirX == 0 ) {
		Xinterptconc = false;
	}
	else if (DirX == 1) {
		Xinterptconc2 = false;

	}
	long tempspeedX = speedXf * 10;
	Serial.println("Dir");
	Serial.println(DirX);
	long ix = 0;
	for (ix;ix < stepsXf; ix++)
	{
		if ((!Xinterptconc && (DirX == 1)) || (!Xinterptconc2 && (DirX == 0)))
		//if(!Xinterptconc&&!Xinterptconc2)

		
		{
			//if (pulseXelapsed > 100000) {
			//Serial.print("x");
			//Serial.println(i);
			
			StepX(tempspeedX);
			if (tempspeedX >= speedXf)
			{
				tempspeedX - 50;
			}
			//delayMicroseconds(1000);
			//pulseXelapsed = 0;
			//}
		}
		else break;
	}
	Serial.println(ix);
	return ix;
	maxX = ix;
}
long CNCArduinostepsClass::StepsY(long stepsYf, long speedYf,byte directy)
{
	Serial.print("ffggtr - ");
	Serial.println(stepsYf);
	elapsedMillis timer =0;
	//Serial.println(dirY);
	if (DirY == 0 ) {
		Yinterptconc = false;
	}
	else if (DirY == 1 ) {
		Yinterptconc2 = false;
	}
	//Xinterptconc = false;
	long tempspeedYf = speedYf*1000;
	long testingyempspeed = 1666;
	long tempspeedY = 1666; //600 гц нужно
	long experimentr = 2000;
	long koef = 3;
	int ogol = 0;
	//на каждые n/10 увеличение скорости в два раза
	long speedcoef = stepsYf / 10;
	Serial.println(speedcoef);
	Serial.println((stepsYf - speedcoef) % 2);
	Serial.println(((stepsYf-1) - speedcoef) % 2);
	Serial.println(((stepsYf -2) - speedcoef) % 2);
	Serial.println(stepsYf % 10);
	Serial.println((stepsYf - 1)% 10);
	Serial.println((stepsYf - 2)%10);
	testingyempspeed = testingyempspeed / 1.5;
	Serial.println(testingyempspeed);
	Serial.println((stepsYf - speedcoef) % 4);
	testingyempspeed = testingyempspeed / 1.5;
	Serial.println(testingyempspeed);
	Serial.println((stepsYf - speedcoef) % 8);
	testingyempspeed = testingyempspeed / 1.5;
	Serial.println(testingyempspeed);
	long fofo = 0;
	double maxspeed = 0;
	Serial.println((stepsYf - speedcoef) % 16);
	Serial.println(((stepsYf - speedcoef) % 16)&1);
	testingyempspeed = testingyempspeed / 1.5;
	Serial.println(testingyempspeed);
	double testingcoef = 0;
	long sboost;
	if (stepsYf > 100)
	{
		sboost = stepsYf / 8;
	}
	else
	{
		sboost = 4;
	}
	long iy = 0;
	//long j = 0;
	for (iy;iy < stepsYf; iy++)
	{
		if ((!Yinterptconc && DirY ==0)|| (!Yinterptconc2 && DirY == 1)) {
			//if (pulseXelapsed > 100000) {
		//Serial.print("y");
			//Serial.println(i);
		//	if(iy<stepsYf/4)
		//	{
			//	tempspeedYf = (speedYf * 1000) - iy;
			//	StepY(tempspeedYf);
			//	}
			//else {
			//if (timer == 100)
			//{
			//if (experimentr>=350)
			//{
			//	experimentr = experimentr/2;
		//	}
			
			//if (ogol == 10 && experimentr>=600)
			//{
				//experimentr = experimentr -30;
				//ogol = 0;
			//}
			
			
				testingcoef = testingcoef + 0.02;
			
			
			//if (iy == (stepsYf / 2))
			//{
			//	testingcoef = 0;
			//}
			//if (iy < sboost && experimentr>600)
			//{
			//	experimentr = 1666 - (koef*iy);
			//	maxspeed = experimentr;
				//Serial.println(experimentr);
			//}

			//1600*x^2+0.01x+334
			
			//if (iy > (stepsYf - sboost))
			//{
				//Serial.println(stepsYf - sboost);
				//Serial.println(experimentr);
			//	fofo = stepsYf - iy;
				//experimentr = koef*(stepsYf-iy)+333;
				//experimentr = 333 + (koef*fofo);
				//experimentr = 600 + 1 * (fofo);
			//	experimentr = maxspeed + (0.2*iy);
				//Serial.println(experimentr);
		//	}
			//Serial.println(experimentr);
			//maxspeed = (1600 * (pow(testingcoef,2))) + (0.01*testingcoef) + 334;
				maxspeed = sin(testingcoef)*1660;
			StepY((long)maxspeed);
				//ogol++;
				//Serial.println(experimentr);
				//delayMicroseconds(experimentr);


			//	Serial.println(tempspeedY);
			//	if (tempspeedY >= speedYf)
				//{
				//	tempspeedY - 1000;
				//}
		//	}
			
			//	if(!Xinterptconc)
				//{
					//if (pulseXelapsed > 100000) {
					//Serial.print("x");
					//Serial.println(i);
				//StepX(speedYf);
					//delayMicroseconds(1000);
					//pulseXelapsed = 0;
					//}
				//}
				
			//delayMicroseconds(1000);
			//pulseXelapsed = 0;
			//}
			//	experimentr = 0;
		}
		else break;
	}
	Serial.println("speed");
	Serial.println(experimentr);
	Serial.println(iy);
	timer = 0;
	maxY = iy;
	//Serial.println(j);
	return iy;
}
void CNCArduinostepsClass::calculatecurcorunits(currencoord inputcurcor, currencoordunits &outputcurcorunits)
{
	if (calibset)
	{
		outputcurcorunits.currentXunits = inputcurcor.currentXs*calibrationX;
		outputcurcorunits.currentYunits = inputcurcor.currentYs*calibrationY;
	}
	else { calibrate(2,false); }
}
void CNCArduinostepsClass::returncoordtomatlab()
{
	Serial.print("SCor"); // scancoordinates for mathlab
	Serial.print(newcurcordunits.currentXunits);
	Serial.print('$');
	Serial.println(newcurcordunits.currentYunits);


}
CNCArduinostepsClass::currencoord CNCArduinostepsClass::simultengoxy(long Xstepssim, long Ystepssim, long SpeedX, long SpeedY)
{
	long maxsteps = 0;
	long minsteps = 0;
	long donestepsx = 0;
	long donestepsy = 0;
	bool maxy = false;
	bool maxx = false;
	bool donex = false;
	bool doney = false;
	if (SpeedX <= 0)
	{
		SpeedX = 1000;
	}
	if (SpeedY <=0)
	{
		SpeedY = 1000;
	}
	currencoord outputtemp;
	Serial.println(Xstepssim);
	Serial.println(Ystepssim);
	if (DirX == 0) {
		Xinterptconc = false;
	}
	else if (DirX == 1) {
		Xinterptconc2 = false;

	}
	if (DirY == 0) {
		Yinterptconc = false;
	}
	else if (DirY == 1) {
		Yinterptconc2 = false;
	}
	if (Xstepssim > Ystepssim)
	{
		maxsteps = Xstepssim;
		minsteps = Ystepssim;
		maxx = true;

	}

	else if (Ystepssim > Xstepssim)
	{
		maxsteps = Ystepssim;
		minsteps = Xstepssim;
		maxy = true;
	}
	else if (Ystepssim == Xstepssim)
	{
		maxx = true;
		maxy = true;
		maxsteps = Ystepssim;
		minsteps = Ystepssim;
	}
	Serial.println(maxsteps);
	Serial.println(minsteps);
	Serial.println(maxx);
	Serial.println(maxy);
	Serial.println(digitalRead(19));
	Serial.println(digitalRead(18));
	Serial.println(DirX);
	Serial.println(DirY);
	for (long i = 0;i < maxsteps;i++) {
		//for (long j = 0; j < minsteps; j++)
		//{
		//	if(j)
		//}
		if (((!Xinterptconc && (DirX == 1)) || (!Xinterptconc2 && (DirX == 0))) && ((!Yinterptconc && DirY == 0) || (!Yinterptconc2 && DirY == 1)))
		{
			if (i <= maxsteps && maxx && ((digitalRead(19) == HIGH && DirX == 0) || (digitalRead(18) == HIGH && DirX == 1)))
			{
				//StepsX(1, 1, 0);
				StepX(SpeedX);
				donestepsx++;
			}
			else {
				delayMicroseconds(SpeedX);
			}

			if (i <= maxsteps && maxy && ((digitalRead(20) == HIGH && DirY == 1) || (digitalRead(21) == HIGH && DirY == 0)))
			{
				//StepsY(1, 1, 0);
				StepY(SpeedY);
				donestepsy++;
			}
			else {
				delayMicroseconds(SpeedY);
			}

			if (i <= minsteps && maxy && ((digitalRead(19) == HIGH && DirX == 0) || (digitalRead(18) == HIGH && DirX == 1)))
			{
				//StepsX(1, 1, 0);
				StepX(SpeedX);
				donestepsx++;
			}
			else {
				delayMicroseconds(SpeedX);
			}

			if (i <= minsteps && maxx && ((digitalRead(20) == HIGH && DirY == 1) || (digitalRead(21) == HIGH && DirY == 0)))
			{
				//StepsY(1, 1, 0);
				StepY(SpeedY);
				donestepsy++;
			}
			else {
				delayMicroseconds(SpeedY);
			}

		}
		else break;
		
		
	}
	Serial.print("donestepsx - ");
	Serial.println(donestepsx);
	Serial.print("donestepsy - ");
	Serial.println(donestepsy);
	maxX = donestepsx;
	maxY = donestepsy;
	outputtemp.currentXs = donestepsx;
	outputtemp.currentYs = donestepsy;
	return outputtemp;
}
void CNCArduinostepsClass::SetDirX(byte dirx)
{
	digitalWrite(DirpinX, dirx);
	DirX = dirx;
}
void CNCArduinostepsClass::SetDirY(byte diry)
{
	digitalWrite(DirpinY, diry);
	DirY = diry;
}
void CNCArduinostepsClass::GotoCoord(double Xmm, double Ymm)
{
	if (calibset && pinsset)
	//if(pinsset)
	{
		if (!zeroset)
		{
			GotoZero();
		}
		if ((Xmm >= 0) && (Ymm >= 0)) {
			//calibrationX = 0.012;
			//calibrationY = 0.024;
			//xsize = 631;
		//	ysize = 886;
			long coordXsteps = abs(Xmm / calibrationX);
			long coordYsteps = abs(Ymm / calibrationY);
			long neededstepsX1 = 0;
			long neededstepsY1 = 0;
			long neededstepsX2 = 0;
			long neededstepsY2 = 0;
			Serial.print("Xmm2 - ");
			Serial.println(Xmm);
			Serial.print("Ymm2 - ");
			Serial.println(Ymm);
			Serial.print("CurrentXsteps - ");
			Serial.println(newcurcord.currentXs);
			Serial.print("CurrentYsteps - ");
			Serial.println(newcurcord.currentYs);
			Serial.print("Xsteps2 - ");
			Serial.println(coordXsteps);
			Serial.print("Ysteps2 - ");
			Serial.println(coordYsteps);
			Serial.println("ffre");
			Serial.println(maxX);
			Serial.println(maxY);
			Serial.println("Fff");
			Serial.println(coordXsteps - newcurcord.currentXs);
			Serial.println(coordYsteps - newcurcord.currentYs);
			if (Xmm <= xsize && Ymm <= ysize)
			{
				if (coordXsteps < newcurcord.currentXs)
				{
					Serial.println("neededcoordsx < curcordsx");
					neededstepsX1 = newcurcord.currentXs-coordXsteps;
					SetDirX(1);
					delay(200);
					long donestepsx = StepsX(neededstepsX1, 1000, 1);
					newcurcord.currentXs = newcurcord.currentXs - donestepsx;
				}
				if (coordXsteps > newcurcord.currentXs)
				{
					Serial.println("neededcoordsx > curcordsx");
					neededstepsX2 = coordXsteps - newcurcord.currentXs;
					SetDirX(0);
					delay(200);
					long donestepsx = StepsX(neededstepsX2, 1000, 0);
					newcurcord.currentXs = newcurcord.currentXs + donestepsx;
				}
				if (coordYsteps < newcurcord.currentYs)
				{
					Serial.println("neededcoordsy < curcordsy");
					neededstepsY1 = abs(newcurcord.currentYs - coordYsteps);
					Serial.print("neededstpes - ");
					Serial.println(neededstepsY1);
					SetDirY(0);
					//digitalWrite(DirpinY, LOW);
					delay(200);
					Serial.print("rrr - ");
					Serial.println(neededstepsY1);
					long donestepsy = StepsY(neededstepsY1, 1000, 0);

					newcurcord.currentYs = newcurcord.currentYs - donestepsy;
				}
				if (coordYsteps > newcurcord.currentYs)
				{
					Serial.println("neededcoordsy > curcordsy");
					neededstepsY2 = coordYsteps - newcurcord.currentYs;
					Serial.println(neededstepsY2);
					SetDirY(1);
					//digitalWrite(DirpinY, HIGH);
					delay(200);
					Serial.print("difii ");
					Serial.println(neededstepsY2);
					long donestepsy = StepsY(neededstepsY2, 1000, 1);
					newcurcord.currentYs = newcurcord.currentYs + donestepsy;
				}
				//if ((coordXsteps < newcurcord.currentXs) && (coordYsteps < newcurcord.currentYs))
				//{
				//	Serial.println("newcoord < currcords");
				//	SetDirX(0);
					// 20      40                 
				//	newcurcord.currentXs = newcurcord.currentXs + StepsX(coordXsteps - newcurcord.currentXs, 1000, 0);
				//	Serial.println(newcurcord.currentXs);
				//	Serial.println(" steps X");
				//	calculatecurcorunits(newcurcord, newcurcordunits);
				//	Serial.print(newcurcordunits.currentXunits);
				//	Serial.println(" mm X");
				//	delay(1000);
				//	SetDirY(1);
					// 20      40                 
				//	newcurcord.currentYs = newcurcord.currentYs + StepsY(coordYsteps - newcurcord.currentYs, 1000, 1);
				//	Serial.println(newcurcord.currentYs);
				//	Serial.println(" steps");
				//	calculatecurcorunits(newcurcord, newcurcordunits);
				//	Serial.print(newcurcordunits.currentYunits);
				//	Serial.println(" mm Y");

				//}
				//else if ((coordXsteps > newcurcord.currentXs) && (coordYsteps > newcurcord.currentYs))
			//	{
			//		Serial.println("newcoord < currcords");
			//		SetDirX(1);
					// 40      20                 
				//	newcurcord.currentXs = newcurcord.currentXs - StepsX(newcurcord.currentXs - coordXsteps, 1000, 0);
				//	Serial.println(newcurcord.currentXs);
				//	Serial.println(" steps X");
				//	calculatecurcorunits(newcurcord, newcurcordunits);
				//	Serial.print(newcurcordunits.currentXunits);
				//	Serial.println(" mm X");
				//	delay(1000);
				//	SetDirY(0);
					// 20      40                 
				//	newcurcord.currentYs = newcurcord.currentYs + StepsY(coordYsteps - newcurcord.currentYs, 1000, 0);
				//	Serial.println(newcurcord.currentYs);
				//	Serial.println(" steps Y");
				//	calculatecurcorunits(newcurcord, newcurcordunits);
				//	Serial.print(newcurcordunits.currentYunits);
				//	Serial.println(" mm Y");
				//}
				if (newcurcord.currentXs == coordXsteps || newcurcord.currentYs == coordYsteps)
				{
					Serial.println("already on coordinate or on zero X");
				}



				//if (newcurcord.currentYs < coordYsteps)
				//{

				//	SetDirY(1);
			///		// 20      40                 
				//	newcurcord.currentYs = newcurcord.currentYs + StepsY(coordYsteps - newcurcord.currentYs, 1000, 1);
				//	Serial.println(newcurcord.currentYs);
				//	Serial.println(" steps");
				//	calculatecurcorunits(newcurcord, newcurcordunits);
				//	Serial.print(newcurcordunits.currentYunits);
				//	Serial.println(" mm Y");
				//}
				//else if (newcurcord.currentYs > coordYsteps)
				//{
					//SetDirY(0);
					// 20      40                 
					//newcurcord.currentYs = newcurcord.currentYs + StepsY(coordYsteps - newcurcord.currentYs, 1000, 0);
					//Serial.println(newcurcord.currentYs);
					//Serial.println(" steps Y");
					//calculatecurcorunits(newcurcord, newcurcordunits);
					//Serial.print(newcurcordunits.currentYunits);
					//Serial.println(" mm Y");
				//}
				
				Serial.print("CurrentXsteps2 - ");
				Serial.println(newcurcord.currentXs);
				Serial.print("CurrentYsteps2 - ");
				Serial.println(newcurcord.currentYs);
				calculatecurcorunits(newcurcord, newcurcordunits);
			}
			else 
			{
				Serial.println("maxpoint");
			}
		}

	}
	else if (!calibset)
	{
		calibrate(2,false);
	}

}
//void CNCArduinostepsClass::FreqStepsX(long stepsXf, long speedXf)
//{
//	timer1freqspeedup = speedXf * 10;
//	timer1freq = speedXf;
//	timer1stepsfull = stepsXf;
//	Timer1.initialize(speedXf);
//	Xarrived = false;
//	timer1freqspeedupcoef = speedXf / 100;
//	Serial.println(stepsXf);
//	Serial.println(speedXf);
//	timer1stepsinter = 0;
//	digitalWrite(13, LOW);
//	Timer1.attachInterrupt(StepXintr);
//	Yinterptconc = false;
	//Timer1.setPeriod(speedXf);
//	Timer1.start();

//}
//void CNCArduinostepsClass::FreqStepsY(long stepsYf, long speedYf)
//{
//	Yarrived = false;
//	timer3freqspeedup = speedYf * 10;
//	timer3freq = speedYf;
//	digitalWrite(5, LOW);
//	timer3stepsfull = stepsYf;
//	Timer3.initialize(speedYf);
//	timer3freqspeedupcoef = speedYf / 100;
//	Serial.println(stepsYf);
//	Serial.println(speedYf);
//	timer3stepsinter = 0;
//	Timer3.attachInterrupt(StepYintr);
//	Yinterptconc = false;
//	//Timer1.setPeriod(speedXf);
//	Timer3.start();
//}
void CNCArduinostepsClass::GotoZero()
{
	if (pinsset) {
		zeroset = false;
		Xarrived = false;
		Yarrived = false;
		Serial.println("GoingtoZero");
		DirX =1; //1 правильно

		DirY = 0; //0 правильно
		digitalWrite(DirpinX, DirX);
		digitalWrite(DirpinY, DirY);
		//FreqStepsY(5000, 1000);
		
		//while (!Yarrived)
		//{

        //}
		//FreqStepsY(10000000, 1000);
		Serial.println(digitalRead(18));
		if (digitalRead(18) == HIGH)
		{
		long totalxsteps = StepsX(1000000, 1000,1);
		}
		if (digitalRead(21) == HIGH)
		{
		long totalysteps = StepsY(1000000, 1000,0);
		}
		newcurcord.currentXs = 0;
		newcurcord.currentYs = 0;
		zeroset=true;
		Serial.println("inzero");
	}
}
void CNCArduinostepsClass::StepXintr()
{
//	if (timer1steps > timer1stepsfull || Xinterptconc)
//	{
//		Timer1.stop();
//		timer1stepsinter = timer1steps;
//		timer1steps = 1;
//		ArrivedX();

//		Xinterptconc = false;
		
//	}
	//if (timer1freqspeedup > timer1freq)
	//{
	//	timer1freqspeedup = timer1freqspeedup - timer1freqspeedupcoef;
	//	Timer1.initialize(timer1freqspeedup);
	//}
	//if (timer1steps > 200)
	//{
	//	Timer1.setPeriod(4000);
	//}
	
	//Serial.println(timer1steps);
	//digitalWrite(13, digitalRead(13) ^ 1);
	//timer1steps++;
}
void CNCArduinostepsClass::StepYintr()
{
//	Serial.println(timer3stepsfull);
	//if (timer3steps > timer3stepsfull || Yinterptconc)
	//{
	///	Timer3.stop();
	//	timer3stepsinter = timer3steps;
	//	timer3steps = 1;
	//	ArrivedY();
	//	Yinterptconc = false;

//	}
	//if (timer1freqspeedup > timer1freq)
	//{
	//	timer1freqspeedup = timer1freqspeedup - timer1freqspeedupcoef;
	//	Timer1.initialize(timer1freqspeedup);
	//}
	//if (timer1steps > 200)
	//{
	//	Timer1.setPeriod(4000);
	//}

	//Serial.println(timer3steps);
//	digitalWrite(2, digitalRead(2) ^ 1);
//	timer3steps++;
}
void CNCArduinostepsClass::setpins(byte dirx, byte diry, byte xsteppin, byte ysteppin, byte enablepin)
{
	Xpin = xsteppin;
	Ypin = ysteppin;
	Enablepin = enablepin;
	
	DirpinX = dirx;
	DirpinY = diry;

	pinsset = true;
}

void CNCArduinostepsClass::setdxdy(double dxXunits, double dxYunits)
{
	dxXun = dxXunits;
	dxYun = dxYunits;
	
	
	if (calibset)
	{
		dxX = abs((double)dxXun / calibrationX);
		dxY = abs((double)dxYun / calibrationY);
		Serial.println(dxX);
		Serial.println(dxY);
		Serial.println(dxXun);
		Serial.println(dxYun);
		dxdyset = true;


	}
}

void CNCArduinostepsClass::setcalibration(double calibX, double calibY)
{
	calibrationX = calibX;
	calibrationY = calibY;
	Serial.println(calibrationX);
	Serial.println(calibrationY);
	calibset = true;
}

void CNCArduinostepsClass::serialhandler(String command,long amount, String amountstri)
{
	Serial.println(command);
	Serial.println(amount);
	if (command.equals("DXX"))
	{
		dxX = amount;
	}
	else if (command.equals("DXY"))
	{
		dxY = amount;
	}
	else if (command.equals("TAS"))
	{
		Arrivedtostop();
	}
	else if (command.equals("XSS"))
	{
		testingstepsX = amount;

	}
	else if (command.equals("CLB"))
	{
		long calibrcounts = amountstri.substring(0, amountstri.indexOf('$')).toInt();
		String simulcalibr = amountstri.substring(amountstri.indexOf('$') + 1, amountstri.length());
		if (simulcalibr == "true")
		{
			calibrate(amount, true);
		}
		if (simulcalibr == "false")
		{
			calibrate(amount, false);
		}
		//calibrate(amount,simulcalibr);

	}
	else if (command.equals("MTC"))
	{
		serialcalibratedx(amountstri); //установка dxXun dxYun
	}
	else if (command.equals("ENB"))
	{
		if (amount == 0)
		{
			digitalWrite(Enablepin, HIGH);
			Serial.println(digitalRead(52));

		}
		if (amount == 1)
		{
			digitalWrite(Enablepin, LOW);
			Serial.println(digitalRead(52));
		}
	}
	else if (command.equals("TSR"))
	{
		SetDirY(1);
		for (int i = 0;i < 20; i++)
		{
			StepsY(1000000, 1666, 1);
			delay(500);
			if (DirY == 0)
			{
				SetDirY(1);
			}
			else if (DirY == 1)
			{
				SetDirY(0);
			}
		}
	}
	else if (command.equals("XSD"))
	{
		testingdirX = amount;
		if (testingdirX == 1)
		{
			digitalWrite(DirpinX, HIGH);
			DirX = 1;
		}
		else if (testingdirX == 0)
		{
			digitalWrite(DirpinX, LOW);
			DirX = 0;
		}

	}
	else if (command.equals("GTZ"))
	{
		GotoZero();

	}
	else if (command.equals("YSD"))
	{
		testingdirY = amount;
		if (testingdirY == 1)
		{
			digitalWrite(DirpinY, HIGH);
			DirY = 1;
		}
		else if (testingdirY == 0)
		{
			digitalWrite(DirpinY, LOW);
			DirY = 0;
		}

	}
	else if (command.equals("XSF"))
	{
		testingfreqX = amount;

	}
	else if (command.equals("SFS")) //первая точка для сканирование
	{
		Scan(true);

	}
	else if (command.equals("SNS")) // продолжение сканирования
	{
		Scan(false);

	}
	else if (command.equals("XSE"))
	{
		testingenableX = amount;
		if (testingenableX)
		{
		long totalxsteps = StepsX(testingstepsX, testingfreqX,DirX);
			digitalWrite(4, HIGH);
			digitalWrite(10, HIGH);
		}
	}
	else if (command.equals("XTF"))
	{
		timer1freq = amount;
	}
	else if (command.equals("XTS"))
	{
		timer1stepsfull = amount;
	}
	else if (command.equals("XTE"))
	{
		//Xinterptconc = false;

		//FreqStepsX(timer1stepsfull, timer1freq);
		if (timer1freq > 0 && timer1stepsfull > 0)
		{
			long totalxsteps = StepsX(timer1stepsfull, timer1freq, DirX);
		}
		else { Serial.println("X settings not set"); }
	}
	else if (command.equals("GTC"))
	{
		double gotoXmm = amountstri.substring(0, amountstri.indexOf('$')).toFloat();
		double gotoYmm = amountstri.substring(amountstri.indexOf('$') + 1, amountstri.length()).toFloat();
		Serial.println("gotoXmm");
		Serial.println(gotoXmm);
		Serial.println("gotoYmm");
		Serial.println(gotoYmm);
		GotoCoord(gotoXmm, gotoYmm);
		
	}
	else if (command.equals("SMT")) // езда одновременно
	{
		double gotoXmmsim = amountstri.substring(0, amountstri.indexOf('$')).toFloat();
		double gotoYmmsim = amountstri.substring(amountstri.indexOf('$') + 1, amountstri.length()).toFloat();
		Serial.println("gotoXmmsim");
		Serial.println(gotoXmmsim);
		Serial.println("gotoYmmsim");
		Serial.println(gotoYmmsim);
		simultengoxy(gotoXmmsim, gotoYmmsim,timer1freq,timer3freq);

	}
	else if (command.equals("MSS"))
	{
		//double maxscansizeXmm = amountstri.substring(0, amountstri.indexOf('$')).toFloat();
		//double maxscansizeYmm = amountstri.substring(amountstri.indexOf('$') + 1, amountstri.length()).toFloat();
		//Serial.println("maxscansizeXmm");
		//Serial.println(maxscansizeXmm);
		//Serial.println("maxscansizeYmm");
		//Serial.println(maxscansizeYmm);
		setsizeofscan(amountstri);

	}
	else if (command.equals("YTF"))
	{
		timer3freq = amount;
	}
	else if (command.equals("YTS"))
	{
		timer3stepsfull = amount;
	}
	else if (command.equals("YTE"))
	{
		//Yinterptconc = false;
		//FreqStepsY(timer3stepsfull, timer3freq);
		if (timer3freq > 0 && timer3stepsfull > 0)
		{
	long totalysteps = StepsY(timer3stepsfull, timer3freq,DirY);
		}
		else { Serial.println("Y settings not set"); }
	}
	else
	{
		Serial.println("Wrong command");
	}
}

CNCArduinostepsClass::currencoord CNCArduinostepsClass::getcurrencoord()
{
	currencoord tempcurcords;
	tempcurcords.currentXs = newcurcord.currentXs;
	tempcurcords.currentYs = newcurcord.currentYs;
	return tempcurcords;
}

CNCArduinostepsClass::currencoordunits CNCArduinostepsClass::getcurrentcoordunits()
{
	currencoordunits tempcurcords;
	tempcurcords.currentXunits = newcurcordunits.currentXunits;
	tempcurcords.currentYunits = newcurcordunits.currentYunits;

	return currencoordunits();
}

void CNCArduinostepsClass::setsizeofscan(String sizecommand)
{
	if (pinsset)
	{
		if (calibset)
		{
			String firstcordtemp = sizecommand.substring(0, sizecommand.indexOf('&'));
			String maxcoordtemp = sizecommand.substring(sizecommand.indexOf('&') + 1, sizecommand.indexOf('#'));
			//Serial.println(calibrationtemp);
			//Serial.println(dxtemp);
			double Xmmsize =firstcordtemp.substring(0, firstcordtemp.indexOf('$')).toFloat();
			//Serial.println(calibrationXtemp);
			double Ymmsize = firstcordtemp.substring(firstcordtemp.indexOf('$') + 1, firstcordtemp.length()).toFloat();
			//Serial.println(calibrationYtemp);
			double Xmmsizem = maxcoordtemp.substring(0, maxcoordtemp.indexOf('$')).toFloat();
			//Serial.println(dxXtemp);
			double Ymmsizem = maxcoordtemp.substring(maxcoordtemp.indexOf('$') + 1, maxcoordtemp.length()).toFloat();
			if (Xmmsizem < xsize && Ymmsizem < ysize && Xmmsizem < xsize && Ymmsizem < ysize) {
				maxXscansize = abs(Xmmsizem / calibrationX);
				maxYscansize = abs(Ymmsizem / calibrationY);
				firstscanX = Xmmsize;
				firstscanY = Ymmsize;
				firstscanXsteps = abs(Xmmsize / calibrationX);
				firstscanYsteps = abs(Ymmsize / calibrationY);
				Serial.println(firstscanX);
				Serial.println(firstscanY);
				Serial.println(maxXscansize);
				Serial.println(maxYscansize);
				maxscanset = true;

				GotoZero();
				//GotoCoord(Xmmsize, Ymmsize);
			}
		}
		else
		{
			calibrate(2,false);
		}
	}
}

void CNCArduinostepsClass::Yinterpt(bool yplus)
{
//	Yintert();
	Serial.println("Yconvf");
	if (!yplus) {
		Yinterptconc = true;
		Yinterptconc2 = false;
	}
	else if (yplus)
	{
		Yinterptconc2 = true;
		Yinterptconc = false;
	}
	Yarrived = true;
}
void CNCArduinostepsClass::Xinterpt(bool xplus)
{
	
	//	Yintert();
	Serial.println("Xconvf");
	if (!xplus) {
		Xinterptconc = true;
		Xinterptconc2 = false;
	}
	else if (xplus)
	{
		Xinterptconc2 = true;
		Xinterptconc = false;
	}
	Serial.println(Xinterptconc);
	Serial.println(Xinterptconc2);

	Xarrived = true;
}

