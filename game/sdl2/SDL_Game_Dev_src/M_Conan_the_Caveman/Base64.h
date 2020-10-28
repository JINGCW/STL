#pragma once
#ifndef STANDARD_TEMPLATE_LIBRARIES_BASE64_H
#define STANDARD_TEMPLATE_LIBRARIES_BASE64_H

#include "MCC_config.h"
#include <string>
#include <vector>

MCC_begin
    std::string base64_encode(unsigned char const *, unsigned int len);

    std::string base64_decode(std::string const &s);
MCC_end

#endif //STANDARD_TEMPLATE_LIBRARIES_BASE64_H
