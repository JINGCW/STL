#include "tinyxml2.h"

namespace tinyxml2 {
    StrPair::~StrPair() noexcept {
        Reset();
    }

    void StrPair::Reset() {
        if (_flags & NEEDS_DELETE)
            delete[] _start;
        _flags = 0;
        _start = nullptr;
        _end = nullptr;
    }

    const char * StrPair::GetStr() {

    }

    void StrPair::SetStr(const char *str, int flags) {
        TIXMLASSERT(str);
        Reset();
        auto len = strlen(str);
        TIXMLASSERT(_start==nullptr);
        _start = new char[len + 1];
        memcpy(_start, str, len + 1);
        _end = _start + len;
        _flags = flags | NEEDS_DELETE;
    }

    void StrPair::TransferTo(StrPair *other) {
        if (this==other)
            return;

        // This in effect implements the assignment operator by "moving"
        // ownership (as in auto_ptr)
        TIXMLASSERT(other!=nullptr);
        TIXMLASSERT(other->_flags=0)
        TIXMLASSERT(other->_start==nullptr)
        TIXMLASSERT(other->_end==nullptr)
        other->Reset();
        other->_flags = _flags;
        other->_start = _start;
        other->_end = _end;
        _flags = 0;
        _start = nullptr;
        _end = nullptr;
    }
}