#ifndef COMMAND_H
#define COMMAND_H
#include "controller.h"
#include "snap7.h"
#include <QtEndian>

class Command
{
public:
    virtual bool execute() = 0;
protected:
    byte buffer;
    Controller* controller;
};

class startCommand : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 1;
        return controller->writeVal(0x84, 1, 1, 1, 0x01, &buffer);
    }
};

class stopCommand : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 1;
        return controller->writeVal(0x84, 1, 1, 1, 0x01, &buffer);
    }
};

class stopCommandR : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 0;
        return controller->writeVal(0x84, 1, 1, 1, 0x01, &buffer);
    }
};

class restartCommand : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 1;
        return controller->writeVal(0x84, 1, 1, 1, 0x01, &buffer);
    }
};

class stopXCommand : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 1;
        return controller->writeVal(0x84, 1, 0, 1, 0x01, &buffer);
    }
};

class initXCommand : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 1;
        return controller->writeVal(0x84, 1, 40, 1, 0x01, &buffer);
    }
};

class initYCommand : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 1;
        return controller->writeVal(0x84, 1, 41, 1, 0x01, &buffer);
    }
};

class initZCommand : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 1;
        return controller->writeVal(0x84, 1, 42, 1, 0x01, &buffer);
    }
};

class startXAutoCommand : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 1;
        return controller->writeVal(0x84, 1, 24, 1, 0x01, &buffer);
    }
};

class startYAutoCommand : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 1;
        return controller->writeVal(0x84, 1, 25, 1, 0x01, &buffer);
    }
};

class startZAutoCommand : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 1;
        return controller->writeVal(0x84, 1, 26, 1, 0x01, &buffer);
    }
};

class startXAutoCommandR : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 0;
        return controller->writeVal(0x84, 1, 24, 1, 0x01, &buffer);
    }
};

class startYAutoCommandR : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 0;
        return controller->writeVal(0x84, 1, 25, 1, 0x01, &buffer);
    }
};

class startZAutoCommandR : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 0;
        return controller->writeVal(0x84, 1, 26, 1, 0x01, &buffer);
    }
};

// JOG置1
class startXJogPlus : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 1;
        return controller->writeVal(0x84, 1, 16, 1, 0x01, &buffer);
    }
};

class startYJogPlus : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 1;
        return controller->writeVal(0x84, 1, 18, 1, 0x01, &buffer);
    }
};

class startZJogPlus : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 1;
        return controller->writeVal(0x84, 1, 20, 1, 0x01, &buffer);
    }
};

class startXJogMinus : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 1;
        return controller->writeVal(0x84, 1, 17, 1, 0x01, &buffer);
    }
};

class startYJogMinus : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 1;
        return controller->writeVal(0x84, 1, 19, 1, 0x01, &buffer);
    }
};

class startZJogMinus : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 1;
        return controller->writeVal(0x84, 1, 21, 1, 0x01, &buffer);
    }
};

// JOG置0
class startXJogPlusR : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 0;
        return controller->writeVal(0x84, 1, 16, 1, 0x01, &buffer);
    }
};

class startYJogPlusR : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 0;
        return controller->writeVal(0x84, 1, 18, 1, 0x01, &buffer);
    }
};

class startZJogPlusR : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 0;
        return controller->writeVal(0x84, 1, 20, 1, 0x01, &buffer);
    }
};

class startXJogMinusR : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 0;
        return controller->writeVal(0x84, 1, 17, 1, 0x01, &buffer);
    }
};

class startYJogMinusR : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 0;
        return controller->writeVal(0x84, 1, 19, 1, 0x01, &buffer);
    }
};

class startZJogMinusR : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 0;
        return controller->writeVal(0x84, 1, 21, 1, 0x01, &buffer);
    }
};

class manualCmd : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 0;
        return controller->writeVal(0x84, 1, 0, 1, 0x01, &buffer);
    }
};

class AutoCmd : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 1;
        return controller->writeVal(0x84, 1, 0, 1, 0x01, &buffer);
    }
};

// 给定xyz位置速度，启动运动
class startXYZCombo
{
public:
    startXYZCombo(QString xPosition, QString yPosition, QString zPosition, QString xSpeed, QString ySpeed, QString zSpeed) {
        this->xPosition = processReal(xPosition);
        this->yPosition = processReal(yPosition);
        this->zPosition = processReal(zPosition);

        this->xSpeed = processReal(xSpeed);
        this->ySpeed = processReal(ySpeed);
        this->zSpeed = processReal(zSpeed);
    }

    bool execute() {
        Controller *controller = Controller::controller();

        controller->writeVal(0x84, 1, 30, 1, 0x08, &xSpeed); //x轴速度
        controller->writeVal(0x84, 1, 34, 1, 0x08, &ySpeed); //y轴速度
        controller->writeVal(0x84, 1, 38, 1, 0x08, &zSpeed); //z轴速度

        controller->writeVal(0x84, 1, 6, 1, 0x08, &xPosition); //x轴位置
        controller->writeVal(0x84, 1, 10, 1, 0x08, &yPosition); //y轴位置
        controller->writeVal(0x84, 1, 14, 1, 0x08, &zPosition); //z轴位置

        Command *cmdSAXR = new startXAutoCommandR();
        Command *cmdSAYR = new startYAutoCommandR();
        Command *cmdSAZR = new startZAutoCommandR();
        cmdSAXR->execute();
        cmdSAYR->execute();
        cmdSAZR->execute();

        Command *cmdSAX = new startXAutoCommand();
        Command *cmdSAY = new startYAutoCommand();
        Command *cmdSAZ = new startZAutoCommand();
        cmdSAX->execute();
        cmdSAY->execute();
        cmdSAZ->execute();


        Command *cmdIX = new initXCommand();
        Command *cmdIY = new initYCommand();
        Command *cmdIZ = new initZCommand();
        cmdIX->execute();
        cmdIY->execute();
        cmdIZ->execute();
        return 0;
    }

private:
    longword xPosition, yPosition, zPosition;
    longword xSpeed, ySpeed, zSpeed;

    longword processReal(QString lineEdit) {
        float targetXPosSF = lineEdit.toFloat();
        longword buffer = *((long *)&targetXPosSF);
        buffer = qToBigEndian(buffer);
        return buffer;
    };
};

class resetXYZ : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 1;
        return controller->writeVal(0x84, 1, 2, 1, 0x01, &buffer);
    }
};

class resetXYZR : public Command
{
public:
    bool execute() {
        Controller *controller = Controller::controller();
        buffer = 0;
        return controller->writeVal(0x84, 1, 2, 1, 0x01, &buffer);
    }
};

#endif // COMMAND_H
