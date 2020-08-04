#ifndef STANDARD_TEMPLATE_LIBRARIES_MESSAGE_H
#define STANDARD_TEMPLATE_LIBRARIES_MESSAGE_H

#pragma once

#include <string>
#include <iostream>

#define DLL_EXPORTS
#include "c++config.h"

using namespace std;


class EXPORT_API message
{
public:
    friend ostream &operator<<(ostream &os, message &msg)
    {
        return msg.print_msg(os);
    }

    message(const string &s) :
            _msg(s)
    {}

private:
    string _msg;

    ostream &print_msg(ostream &os);
};

#endif //STANDARD_TEMPLATE_LIBRARIES_MESSAGE_H
