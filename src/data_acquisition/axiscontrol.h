#ifndef AXISCONTROL_H
#define AXISCONTROL_H

#include "snap7.h"

class abstractAxisControl
{
public:
    abstractAxisControl();
    bool startAxisAbsolute();
    bool startAxisRelative();

    bool getIsAlert() const;

    void setIsAlert(bool newIsAlert);
    bool getIsReady() const;
    bool getIsZero() const;


    bool getIsCompleted() const;

    bool getInit() const;
    void setInit(bool newInit);

    void setStop(bool newStop);

    bool getStartAbsoluteMoation() const;
    void setStartAbsoluteMoation(bool newStartAbsoluteMoation);

    bool getStartRelativeMoation() const;
    void setStartRelativeMoation(bool newStartRelativeMoation);

    float getCurrentSpeed() const;
    void setCurrentSpeed(float newCurrentSpeed);

    float getCurrentPosition() const;
    void setCurrentPosition(float newCurrentPosition);

    float getTargetSpeed() const;
    void setTargetSpeed(float newTargetSpeed);

    float getTargetAbsoltePosition() const;
    void setTargetAbsoltePosition(float newTargetAbsoltePosition);

    float getTargetRelativePosition() const;
    void setTargetRelativePosition(float newTargetRelativePosition);

    void setIsReady(bool newIsReady);

    void setIsZero(bool newIsZero);

    void setIsCompleted(bool newIsCompleted);

    bool getStop() const;

    bool getUpLimit() const;
    void setUpLimit(bool newUpLimit);

    bool getDownLimit() const;
    void setDownLimit(bool newDownLimit);

    bool getIsAbsoluteMoationManual() const;
    void setIsAbsoluteMoationManual(bool newIsAbsoluteMoationManual);

    bool getIsRelativeMoationManual() const;
    void setIsRelativeMoationManual(bool newIsRelativeMoationManual);

    bool getIsAbsoluteMoationAuto() const;
    void setIsAbsoluteMoationAuto(bool newIsAbsoluteMoationAuto);

    bool getIsRelativeMoationAuto() const;
    void setIsRelativeMoationAuto(bool newIsRelativeMoationAuto);

    bool getIsJogPlus() const;
    void setIsJogPlus(bool newIsJogPlus);

    bool getIsJogNegative() const;
    void setIsJogNegative(bool newIsJogNegative);

protected:
    bool isAlert;
    bool isReady;
    bool isZero;
    bool isCompleted;

    bool isAbsoluteMoationManual;
    bool isRelativeMoationManual;
    bool isAbsoluteMoationAuto;
    bool isRelativeMoationAuto;
    bool isJogPlus;
    bool isJogNegative;

    bool init;
    bool stop;
    bool upLimit;
    bool downLimit;
    bool startAbsoluteMoation;
    bool startRelativeMoation;
    float currentSpeed;
    float currentPosition;
    float targetSpeed;
    float targetAbsoltePosition;
    float targetRelativePosition;

};

class xAxis : public abstractAxisControl
{
public:
    xAxis();
    bool getStopAllAxis() const;
    void setStopAllAxis(bool newStopAllAxis);

    bool getLocalOrRemote() const;
    void setLocalOrRemote(bool newLocalOrRemote);

    bool getLocalOrRemoteState() const;
    void setLocalOrRemoteState(bool newLocalOrRemoteState);

    bool getResetAllAxis() const;
    void setResetAllAxis(bool newResetAllAxis);

private:
    bool stopAllAxis;
    bool localOrRemote;
    bool localOrRemoteState;
    bool resetAllAxis;
};

class yAxis : public abstractAxisControl
{
public:
    yAxis();
};

class zAxis : public abstractAxisControl
{
public:
    zAxis();
};

#endif // AXISCONTROL_H
