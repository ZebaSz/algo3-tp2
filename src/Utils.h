#ifndef ALGO3_TP2_UTILS_H
#define ALGO3_TP2_UTILS_H

typedef int logLevel;
enum LOG_LEVEL {TRACE, DEBUG, INFO, WARN, ERROR, OFF};

#define CUR_LOG_LEVEL OFF

namespace Utils {
    void log(logLevel level, const char* format, ...);
}


#endif //ALGO3_TP2_UTILS_H
