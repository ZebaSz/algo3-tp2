#include <cstdarg>
#include <cstdio>
#include "Utils.h"

namespace Utils {
    void log(logLevel level, const char* format, ...) {
        if(CUR_LOG_LEVEL <= level) {
            va_list args;
            va_start(args, format);
            vprintf(format, args);
            std::cout << std::endl;
            va_end(args);
        }
    }
}