#include "axiscontrol.h"


abstractAxisControl::abstractAxisControl()
{
    isAlert = false;
    isReady = false;
    isZero = false;
    isCompleted = false;
}

bool abstractAxisControl::getIsAlert() const
{
    return isAlert;
}

void abstractAxisControl::setIsAlert(bool newIsAlert)
{
    isAlert = newIsAlert;
}

bool abstractAxisControl::getIsReady() const
{
    return isReady;
}

bool abstractAxisControl::getIsZero() const
{
    return isZero;
}

bool abstractAxisControl::getIsCompleted() const
{
    return isCompleted;
}

bool abstractAxisControl::getInit() const
{
    return init;
}

void abstractAxisControl::setInit(bool newInit)
{
    init = newInit;
}

void abstractAxisControl::setStop(bool newStop)
{
    stop = newStop;
}

bool abstractAxisControl::getStartAbsoluteMoation() const
{
    return startAbsoluteMoation;
}

void abstractAxisControl::setStartAbsoluteMoation(bool newStartAbsoluteMoation)
{
    startAbsoluteMoation = newStartAbsoluteMoation;
}

bool abstractAxisControl::getStartRelativeMoation() const
{
    return startRelativeMoation;
}

void abstractAxisControl::setStartRelativeMoation(bool newStartRelativeMoation)
{
    startRelativeMoation = newStartRelativeMoation;
}

float abstractAxisControl::getCurrentSpeed() const
{
    return currentSpeed;
}

void abstractAxisControl::setCurrentSpeed(float newCurrentSpeed)
{
    currentSpeed = newCurrentSpeed;
}

float abstractAxisControl::getCurrentPosition() const
{
    return currentPosition;
}

void abstractAxisControl::setCurrentPosition(float newCurrentPosition)
{
    currentPosition = newCurrentPosition;
}

float abstractAxisControl::getTargetSpeed() const
{
    return targetSpeed;
}

void abstractAxisControl::setTargetSpeed(float newTargetSpeed)
{
    targetSpeed = newTargetSpeed;
}

float abstractAxisControl::getTargetAbsoltePosition() const
{
    return targetAbsoltePosition;
}

void abstractAxisControl::setTargetAbsoltePosition(float newTargetAbsoltePosition)
{
    targetAbsoltePosition = newTargetAbsoltePosition;
}

float abstractAxisControl::getTargetRelativePosition() const
{
    return targetRelativePosition;
}

void abstractAxisControl::setTargetRelativePosition(float newTargetRelativePosition)
{
    targetRelativePosition = newTargetRelativePosition;
}

void abstractAxisControl::setIsReady(bool newIsReady)
{
    isReady = newIsReady;
}

void abstractAxisControl::setIsZero(bool newIsZero)
{
    isZero = newIsZero;
}

void abstractAxisControl::setIsCompleted(bool newIsCompleted)
{
    isCompleted = newIsCompleted;
}

bool abstractAxisControl::getStop() const
{
    return stop;
}

bool abstractAxisControl::getUpLimit() const
{
    return upLimit;
}

void abstractAxisControl::setUpLimit(bool newUpLimit)
{
    upLimit = newUpLimit;
}

bool abstractAxisControl::getDownLimit() const
{
    return downLimit;
}

void abstractAxisControl::setDownLimit(bool newDownLimit)
{
    downLimit = newDownLimit;
}

bool abstractAxisControl::getIsAbsoluteMoationManual() const
{
    return isAbsoluteMoationManual;
}

void abstractAxisControl::setIsAbsoluteMoationManual(bool newIsAbsoluteMoationManual)
{
    isAbsoluteMoationManual = newIsAbsoluteMoationManual;
}

bool abstractAxisControl::getIsRelativeMoationManual() const
{
    return isRelativeMoationManual;
}

void abstractAxisControl::setIsRelativeMoationManual(bool newIsRelativeMoationManual)
{
    isRelativeMoationManual = newIsRelativeMoationManual;
}

bool abstractAxisControl::getIsAbsoluteMoationAuto() const
{
    return isAbsoluteMoationAuto;
}

void abstractAxisControl::setIsAbsoluteMoationAuto(bool newIsAbsoluteMoationAuto)
{
    isAbsoluteMoationAuto = newIsAbsoluteMoationAuto;
}

bool abstractAxisControl::getIsRelativeMoationAuto() const
{
    return isRelativeMoationAuto;
}

void abstractAxisControl::setIsRelativeMoationAuto(bool newIsRelativeMoationAuto)
{
    isRelativeMoationAuto = newIsRelativeMoationAuto;
}

bool abstractAxisControl::getIsJogPlus() const
{
    return isJogPlus;
}

void abstractAxisControl::setIsJogPlus(bool newIsJogPlus)
{
    isJogPlus = newIsJogPlus;
}

bool abstractAxisControl::getIsJogNegative() const
{
    return isJogNegative;
}

void abstractAxisControl::setIsJogNegative(bool newIsJogNegative)
{
    isJogNegative = newIsJogNegative;
}

xAxis::xAxis()
{
    abstractAxisControl();
}

bool xAxis::getStopAllAxis() const
{
    return stopAllAxis;
}

void xAxis::setStopAllAxis(bool newStopAllAxis)
{
    stopAllAxis = newStopAllAxis;
}

bool xAxis::getLocalOrRemote() const
{
    return localOrRemote;
}

void xAxis::setLocalOrRemote(bool newLocalOrRemote)
{
    localOrRemote = newLocalOrRemote;
}

bool xAxis::getLocalOrRemoteState() const
{
    return localOrRemoteState;
}

void xAxis::setLocalOrRemoteState(bool newLocalOrRemoteState)
{
    localOrRemoteState = newLocalOrRemoteState;
}

bool xAxis::getResetAllAxis() const
{
    return resetAllAxis;
}

void xAxis::setResetAllAxis(bool newResetAllAxis)
{
    resetAllAxis = newResetAllAxis;
}

yAxis::yAxis()
{
    abstractAxisControl();
}

zAxis::zAxis()
{
    abstractAxisControl();
}
