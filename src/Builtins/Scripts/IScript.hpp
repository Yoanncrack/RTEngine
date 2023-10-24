#pragma once

namespace RTEngine
{
    class IScript
    {
        public:

        virtual void start() = 0;

        virtual void update() = 0;
    };
}
