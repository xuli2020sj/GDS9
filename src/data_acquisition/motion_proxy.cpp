//
// Created by x on 2022/6/9.
//

#include "motion_proxy.h"
#include <unistd.h>
#include "spdlog/spdlog.h"
#include "util.h"

MotionProxy::MotionProxy() {

}

MotionProxy::~MotionProxy() = default;

const char *MotionProxy::getIp() const {
    return ip_;
}

void MotionProxy::setIp(const char *ip) {
    MotionProxy::ip_ = ip;
}

/**
 *
 * @return 0 表示连接成功，其它表示连接失败
 */
int MotionProxy::Connect() {
    return TS7Client::ConnectTo(ip_, 0, 1);
}

void MotionProxy::executeCmdQueue(CommandQueue *cmd_queue) {
    size_t cmd_num = cmd_queue->getSize();
    if (cmd_num == 0) return ;
    for (int i = 0; i < cmd_num; i++) {
        cmd_queue->getCommand()->executeMotion();
        cmd_queue->getCommand()->executeDetection();
    }
}

/**
 * 需要使用单独线程启动，读取PLC数据，并解析数据到类Axis中
 */
void MotionProxy::synAxisState() {
    while(true) {
        std::vector<std::string> RBString(68);
        if (this->Connected())
        {
            this->ReadArea(0x84, 1, 0, 68, 0x02, &read_buffer_);
            for (int index = 0; index < 68 ; index++) {
                //controller->readVal(0x84, 1, index, 1, 0x02, &RBuffer[index]);
//                RBString[index] = QString("%1").arg(QString::number(RBuffer[index],10).toUInt(), 8, 2, QLatin1Char('0'));
                RBString[index] = convertToBase2(read_buffer_[index]);
                //                char *res = nullptr;
//                itoa(read_buffer_[index], res, 2);
//                RBString[index] = res;
                spdlog::trace("index: {} string: {}", index, RBString[index]);
            }
        }
        else {
            this->Connect();
        }
        dataProcess(RBString);
        sleep(5);
    }
}

/**
 * 解析读取到的PLC数据块
 * @param db_data
 */
void MotionProxy::dataProcess(std::vector<std::string> db_data) {
    std::string dbs2 = db_data[43];
    std::string dbX0 = db_data[0];
    std::string dbX1 = db_data[1];
    std::string dbX3 = db_data[3];
    std::string dbX4 = db_data[4];
    std::string dbX5 = db_data[5];

    std::string currentXPos = db_data[44] + db_data[45] + db_data[46] +db_data[47];
    this->x_axis_.setCurrentPosition(binToFloat(currentXPos));
    auto currentYPos = db_data[48] + db_data[49] + db_data[50] +db_data[51];
    this->y_axis_.setCurrentPosition(binToFloat(currentYPos));
    auto currentZPos = db_data[52] + db_data[53] + db_data[54] +db_data[55];
    this->z_axis_.setCurrentPosition(binToFloat(currentZPos));

    auto currentXSpeed = db_data[56] + db_data[57] + db_data[58] + db_data[59];
    this->x_axis_.setCurrentSpeed(binToFloat(currentXSpeed));
    auto currentYSpeed = db_data[60] + db_data[61] + db_data[62] + db_data[63];
    this->y_axis_.setCurrentSpeed(binToFloat(currentYSpeed));
    auto currentZSpeed = db_data[64] + db_data[65] + db_data[66] + db_data[67];
    this->z_axis_.setCurrentSpeed(binToFloat(currentZSpeed));

    auto targetXAbsolutePos = db_data[6] + db_data[7] + db_data[8] + db_data[9];
    this->x_axis_.setTargetAbsoltePosition(binToFloat(targetXAbsolutePos));
    auto targetYAbsolutePos = db_data[10] + db_data[11] + db_data[12] + db_data[13];
    this->y_axis_.setTargetAbsoltePosition(binToFloat(targetYAbsolutePos));
    auto targetZAbsolutePos = db_data[14] + db_data[15] + db_data[16] + db_data[17];
    this->z_axis_.setTargetAbsoltePosition(binToFloat(targetZAbsolutePos));

    auto targetXRelativePos = db_data[18] + db_data[19] + db_data[20] + db_data[21];
    this->x_axis_.setTargetRelativePosition(binToFloat(targetXRelativePos));
    auto targetYRelativePos = db_data[22] + db_data[23] + db_data[24] + db_data[25];
    this->y_axis_.setTargetRelativePosition(binToFloat(targetYRelativePos));
    auto targetZRelativePos = db_data[26] + db_data[27] + db_data[28] + db_data[29];
    this->z_axis_.setTargetRelativePosition(binToFloat(targetZRelativePos));

    auto targetXSpeed = db_data[30] + db_data[31] + db_data[32] + db_data[33];
    this->x_axis_.setTargetSpeed(binToFloat(targetXSpeed));
    auto targetYSpeed = db_data[30] + db_data[31] + db_data[32] + db_data[33];
    this->y_axis_.setTargetSpeed(binToFloat(targetYSpeed));
    auto targetZSpeed = db_data[30] + db_data[31] + db_data[32] + db_data[33];
    this->z_axis_.setTargetSpeed(binToFloat(targetZSpeed));

    this->x_axis_.setIsReady(stoi(db_data[42].substr(3, 1)));
    this->y_axis_.setIsReady(stoi(db_data[42].substr(2,1)));
    this->z_axis_.setIsReady(stoi(db_data[42].substr(1, 1)));

    this->x_axis_.setIsAlert(stoi(db_data[42].substr(6, 1)));
    this->y_axis_.setIsAlert(stoi(db_data[42].substr(5, 1)));
    this->z_axis_.setIsAlert(stoi(db_data[42].substr(4, 1)));

    this->x_axis_.setIsZero(stoi(dbs2.substr(7, 1)));
    this->y_axis_.setIsZero(stoi(dbs2.substr(6, 1)));
    this->z_axis_.setIsZero(stoi(dbs2.substr(5, 1)));

    this->x_axis_.setIsCompleted(stoi(dbs2.substr(4,1)));
    this->y_axis_.setIsCompleted(stoi(dbs2.substr(3,1)));
    this->z_axis_.setIsCompleted(stoi(dbs2.substr(2,1)));

    this->x_axis_.setStop(stoi(dbX0.substr(4,1)));
    this->y_axis_.setStop(stoi(dbX0.substr(3,1)));
    this->z_axis_.setStop(stoi(dbX0.substr(2,1)));

    this->x_axis_.setIsAbsoluteMoationManual(stoi(dbX1.substr(7,1)));
    this->y_axis_.setIsAbsoluteMoationManual(stoi(dbX1.substr(6,1)));
    this->z_axis_.setIsAbsoluteMoationManual(stoi(dbX1.substr(5,1)));
    this->x_axis_.setIsRelativeMoationManual(stoi(dbX1.substr(4,1)));
    this->y_axis_.setIsRelativeMoationManual(stoi(dbX1.substr(3,1)));
    this->z_axis_.setIsRelativeMoationManual(stoi(dbX1.substr(2,1)));

    this->x_axis_.setIsJogPlus(stoi(db_data[2].substr(7,1)));
    this->y_axis_.setIsJogPlus(stoi(db_data[2].substr(5,1)));
    this->z_axis_.setIsJogPlus(stoi(db_data[2].substr(3,1)));
    this->x_axis_.setIsJogNegative(stoi(db_data[2].substr(6,1)));
    this->y_axis_.setIsJogNegative(stoi(db_data[2].substr(4,1)));
    this->z_axis_.setIsJogNegative(stoi(db_data[2].substr(2,1)));

    this->x_axis_.setIsAbsoluteMoationAuto(stoi(dbX3.substr(7,1)));
    this->y_axis_.setIsAbsoluteMoationAuto(stoi(dbX3.substr(6,1)));
    this->z_axis_.setIsAbsoluteMoationAuto(stoi(dbX3.substr(5,1)));
    this->x_axis_.setIsRelativeMoationAuto(stoi(dbX3.substr(4,1)));
    this->y_axis_.setIsRelativeMoationAuto(stoi(dbX3.substr(3,1)));
    this->z_axis_.setIsRelativeMoationAuto(stoi(dbX3.substr(2,1)));

    this->x_axis_.setUpLimit(stoi(dbX4.substr(7,1)));
    this->y_axis_.setUpLimit(stoi(dbX4.substr(6,1)));
    this->z_axis_.setUpLimit(stoi(dbX4.substr(5,1)));
    this->x_axis_.setDownLimit(stoi(dbX4.substr(4,1)));
    this->y_axis_.setDownLimit(stoi(dbX4.substr(3,1)));
    this->z_axis_.setDownLimit(stoi(dbX4.substr(2,1)));

    this->x_axis_.setInit(stoi(dbX5.substr(7,1)));
    this->y_axis_.setInit(stoi(dbX5.substr(6,1)));
    this->z_axis_.setInit(stoi(dbX5.substr(5,1)));

    this->x_axis_.setLocalOrRemote(stoi(dbX0.substr(7,1)));
    this->x_axis_.setStopAllAxis(stoi(dbX0.substr(6,1)));
    this->x_axis_.setResetAllAxis(stoi(dbX0.substr(5,1)));
    this->x_axis_.setLocalOrRemoteState(stoi(db_data[42].substr(7,1)));
}

/**
 *
 * @param num
 * @return 八位二进制数字符串,高位补零
 */
std::string MotionProxy::convertToBase2(uint8_t num) {
    if (num == 0) return "00000000";
    std::string res;
    while (num > 0) {
        res.push_back(num % 2 + '0');
        num /= 2;
    }
    while (res.size() < 8) {
        res.push_back('0');
    }
    std::reverse(res.begin(), res.end());
    return res;
}



/**
 * 32位二进制转换为IEEE单精度浮点数数据
 * @param str
 * @return
 */
float MotionProxy::binToFloat(const std::string& str) {
    if (str.size() != 32) return 0.0;
    util::float_data d;
    d.c_data[3] = stoi(str.substr(0, 8), nullptr, 2);
    d.c_data[2] = stoi(str.substr(8, 8), nullptr, 2);
    d.c_data[1] = stoi(str.substr(16, 8), nullptr, 2);
    d.c_data[0] = stoi(str.substr(24, 8), nullptr, 2);
    return d.f_data;
}
