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
    size_t curr_ptr_;
public:
    void pushBack(){

    }

    /**
     *
     * @return 指令执行完毕时，返回空指针
     */
    Command* getCommand() {
        ++curr_ptr_;
        if (curr_ptr_ == queue_.size()) {
            return nullptr;
        } else {
            return queue_.at(curr_ptr_);
        }
    }

    size_t getSize() {
        return queue_.size();
    }
};

#endif//DATA_ACQUISITION_COMMAND_QUEUE_H
