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
}