/*
 * L293D.cpp - Library for using a L293D motor controller chip
 * Created by Tyler Sweat, May 25 2015
 * Released under the MIT License
 */

#include "Arduino.h"
#include "L293D.h"

L293D::L293D(int _pin_E, int _pin_A, int _pin_B)
{
    pinMode(_pin_E, OUTPUT);
    pinMode(_pin_A, OUTPUT);
    pinMode(_pin_B, OUTPUT);
    pin_E = _pin_E;
    pin_A = _pin_A;
    pin_B = _pin_B;
    // Set initially to 0
    set(0);
}

void L293D::set(double value)
{
    if(value <= 1 && value >= -1)
    {
        set((int)(value * 255));
    }
}

void L293D::set(int value)
{
    if(value == 0)
    {
        digitalWrite(pin_E, LOW);
        val = value;
    }
    else if(value > 0 && value <= 255)
    {
        // disable before possibly switching directions
        digitalWrite(pin_E, LOW);
        // drive pin A HIGH and pin B LOW
        digitalWrite(pin_A, HIGH);
        digitalWrite(pin_B, LOW);
        // enable
        analogWrite(pin_E, value);
        // Save value it's been set to
        val = value;
    }
    else if(value < 0 && value >= -255)
    {
        // disable before possibly switching directions
        digitalWrite(pin_E, LOW);
        // drive pin A LOW and pin B HIGH
        digitalWrite(pin_A, LOW);
        digitalWrite(pin_B, HIGH);
        // enable
        analogWrite(pin_E, -1*value); // Multiply by -1 to make sure the value is positive.
        // Save value it's been set to
        val = value;
    }
}

int L293D::get()
{
    return val;
}
