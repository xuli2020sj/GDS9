//
// Created by x on 2022/6/12.
//

#ifndef GDS9_COMMAND_H
#define GDS9_COMMAND_H


#include "snap7.h"
#include "util.h"
#include "motion_proxy.h"
#include "detection_proxy.h"

/**
 * @brief
 */
class Command {
public:
    virtual bool doMotion(MotionProxy *mp) {return true;};
    virtual bool doDetection(DetectionProxy *mp) {return true;};
};

class StartCommand : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 1;
        return mp->WriteArea(0x84, 1, 0, 1, 0x01, &buffer);
    }
};

class stopCommand : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 1;
        return mp->WriteArea(0x84, 1, 1, 1, 0x01, &buffer);
    }
};

class stopCommandR : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 0;
        return mp->WriteArea(0x84, 1, 1, 1, 0x01, &buffer);
    }
};

class restartCommand : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 1;
        return mp->WriteArea(0x84, 1, 1, 1, 0x01, &buffer);
    }
};

class stopXCommand : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 1;
        return mp->WriteArea(0x84, 1, 0, 1, 0x01, &buffer);
    }
};

class initXCommand : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 1;
        return mp->WriteArea(0x84, 1, 40, 1, 0x01, &buffer);
    }
};

class initYCommand : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 1;
        return mp->WriteArea(0x84, 1, 41, 1, 0x01, &buffer);
    }
};

class initZCommand : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 1;
        return mp->WriteArea(0x84, 1, 42, 1, 0x01, &buffer);
    }
};

class startXAutoCommand : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 1;
        return mp->WriteArea(0x84, 1, 24, 1, 0x01, &buffer);
    }
};

class startYAutoCommand : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 1;
        return mp->WriteArea(0x84, 1, 25, 1, 0x01, &buffer);
    }
};

class startZAutoCommand : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 1;
        return mp->WriteArea(0x84, 1, 26, 1, 0x01, &buffer);
    }
};

class startXAutoCommandR : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 0;
        return mp->WriteArea(0x84, 1, 24, 1, 0x01, &buffer);
    }
};

class startYAutoCommandR : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 0;
        return mp->WriteArea(0x84, 1, 25, 1, 0x01, &buffer);
    }
};

class startZAutoCommandR : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 0;
        return mp->WriteArea(0x84, 1, 26, 1, 0x01, &buffer);
    }
};

// JOG置1
class startXJogPlus : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 1;
        return mp->WriteArea(0x84, 1, 16, 1, 0x01, &buffer);
    }
};

class startYJogPlus : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 1;
        return mp->WriteArea(0x84, 1, 18, 1, 0x01, &buffer);
    }
};

class startZJogPlus : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 1;
        return mp->WriteArea(0x84, 1, 20, 1, 0x01, &buffer);
    }
};

class startXJogMinus : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 1;
        return mp->WriteArea(0x84, 1, 17, 1, 0x01, &buffer);
    }
};

class startYJogMinus : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 1;
        return mp->WriteArea(0x84, 1, 19, 1, 0x01, &buffer);
    }
};

class startZJogMinus : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 1;
        return mp->WriteArea(0x84, 1, 21, 1, 0x01, &buffer);
    }
};

// JOG置0
class startXJogPlusR : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 0;
        return mp->WriteArea(0x84, 1, 16, 1, 0x01, &buffer);
    }
};

class startYJogPlusR : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 0;
        return mp->WriteArea(0x84, 1, 18, 1, 0x01, &buffer);
    }
};

class startZJogPlusR : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 0;
        return mp->WriteArea(0x84, 1, 20, 1, 0x01, &buffer);
    }
};

class startXJogMinusR : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 0;
        return mp->WriteArea(0x84, 1, 17, 1, 0x01, &buffer);
    }
};

class startYJogMinusR : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 0;
        return mp->WriteArea(0x84, 1, 19, 1, 0x01, &buffer);
    }
};

class startZJogMinusR : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 0;
        return mp->WriteArea(0x84, 1, 21, 1, 0x01, &buffer);
    }
};

class manualCmd : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 0;
        return mp->WriteArea(0x84, 1, 0, 1, 0x01, &buffer);
    }
};

class AutoCmd : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 1;
        return mp->WriteArea(0x84, 1, 0, 1, 0x01, &buffer);
    }
};

// 给定xyz位置速度，启动运动
class StartXYZCombo : public Command {
public:
    StartXYZCombo(std::string xPosition, std::string yPosition, std::string zPosition, std::string xSpeed,
                  std::string ySpeed, std::string zSpeed) {
        this->xPosition = util::converFloatToBin(xPosition);
        this->yPosition = util::converFloatToBin(yPosition);
        this->zPosition = util::converFloatToBin(zPosition);

        this->xSpeed = util::converFloatToBin(xSpeed);
        this->ySpeed = util::converFloatToBin(ySpeed);
        this->zSpeed = util::converFloatToBin(zSpeed);
    }

    bool doMotion(MotionProxy *mp) override {

        mp->WriteArea(0x84, 1, 30, 1, 0x08, &xSpeed); //x轴速度
        mp->WriteArea(0x84, 1, 34, 1, 0x08, &ySpeed); //y轴速度
        mp->WriteArea(0x84, 1, 38, 1, 0x08, &zSpeed); //z轴速度

        mp->WriteArea(0x84, 1, 6, 1, 0x08, &xPosition); //x轴位置
        mp->WriteArea(0x84, 1, 10, 1, 0x08, &yPosition); //y轴位置
        mp->WriteArea(0x84, 1, 14, 1, 0x08, &zPosition); //z轴位置

        Command *cmdSAXR = new startXAutoCommandR();
        Command *cmdSAYR = new startYAutoCommandR();
        Command *cmdSAZR = new startZAutoCommandR();
        cmdSAXR->doMotion(mp);
        cmdSAYR->doMotion(mp);
        cmdSAZR->doMotion(mp);

        Command *cmdSAX = new startXAutoCommand();
        Command *cmdSAY = new startYAutoCommand();
        Command *cmdSAZ = new startZAutoCommand();
        cmdSAX->doMotion(mp);
        cmdSAY->doMotion(mp);
        cmdSAZ->doMotion(mp);

        Command *cmdIX = new initXCommand();
        Command *cmdIY = new initYCommand();
        Command *cmdIZ = new initZCommand();
        cmdIX->doMotion(mp);
        cmdIY->doMotion(mp);
        cmdIZ->doMotion(mp);
        return 0;
    }
private:
    longword xPosition, yPosition, zPosition;
    longword xSpeed, ySpeed, zSpeed;
};

class resetXYZ : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 1;
        return mp->WriteArea(0x84, 1, 2, 1, 0x01, &buffer);
    }
};

class resetXYZR : public Command {
public:
    bool doMotion(MotionProxy *mp) override {
        byte buffer = 0;
        return mp->WriteArea(0x84, 1, 2, 1, 0x01, &buffer);
    }
};


#endif//GDS9_COMMAND_H
