#pragma once
#include"DxLib.h"

//’Ç‰Á
class Ease
{
public:
	static double In(double start, double end, double time, double max_time);

	static double Out(double start, double end, double time, double max_time);

	static double InOut(double start, double end, double time, double max_time);

	static double In_Back(double start, double end, double time, double max_time);

	static double Out_Back(double start, double end, double time, double max_time);

	static double InOut_Back(double start, double end, double time, double max_time);

	static double Out_Bounce(double start, double end, double time, double max_time);

	static double In_Bounce(double start, double end, double time, double max_time);

	static double InOut_Bounce(double start, double end, double time, double max_time);

	//‰´‚Ì‚â‚Â
	static double easeInOutCubic(double x);
	static double easeInOutQuart(double x);
	static double easeInBack(double x);

	static double easeInCirc(double x);

	static double easeOutCubic(double x);
	static double easeInCubic(double x);
	static double easeOutQuad(double x);

	static double Lerp(double start, double end, double t);
};

