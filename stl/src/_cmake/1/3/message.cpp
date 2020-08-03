#include "message.h"

ostream &message::print_msg(ostream &os)
{
    os << "this is my message ";
    os << _msg;
    return os;
}
