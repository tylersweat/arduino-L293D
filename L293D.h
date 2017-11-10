/* 
 * L293D.h - Library for using a L293D motor controller chip
 * Created by Tyler Sweat, May 25 2015
 * Released under the MIT License
 */

#ifndef L293D_H
#define L293D_H

#include "Arduino.h"

class L293D
{
  public:
  	L293D(int, int, int);
  	void set(double);
  	void set(int);
  	int get();
  private:
  	int pin_E;
  	int pin_A;
  	int pin_B;
  	int val;
};

#endif
