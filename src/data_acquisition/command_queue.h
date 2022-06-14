//
// Created by x on 2022/6/10.
//

#ifndef DATA_ACQUISITION_COMMAND_QUEUE_H
#define DATA_ACQUISITION_COMMAND_QUEUE_H

#include <vector>
#include "command.h"

class CommandQueue {
private:
    std::vector<Command*> queue_;
    size_t curr_ptr_ = 0;
public:
    void pushBack(Command* cmd) {
        queue_.push_back(cmd);
    }

    /**
     *
     * @return 指令执行完毕时，返回空指针
     */
    Command* getCommand() {
        if (curr_ptr_ == queue_.size()) {
            return nullptr;
        } else {
            return queue_.at(curr_ptr_++);
        }
    }

    Command* peekCommand() {
        if (curr_ptr_ == queue_.size()) {
            return nullptr;
        } else {
            return queue_.at(curr_ptr_);
        }
    }


    size_t getSize() {
        return queue_.size();
    }

    ~CommandQueue() {
        for (auto cmd : queue_) {
            delete cmd;
        }
    }
};

#endif//DATA_ACQUISITION_COMMAND_QUEUE_H
