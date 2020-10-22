#pragma once
#ifndef STANDARD_TEMPLATE_LIBRARIES_LAYER_H
#define STANDARD_TEMPLATE_LIBRARIES_LAYER_H

#include "MCC_config.h"

MCC_begin
    class Layer
    {
    public:
        virtual void render() = 0;

        virtual void update() = 0;

    protected:
        virtual ~Layer()
        {}
    };
MCC_end
#endif //STANDARD_TEMPLATE_LIBRARIES_LAYER_H
