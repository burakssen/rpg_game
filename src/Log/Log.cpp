#include "Log.h"

void Log::info(std::string message)
{
    std::cout << "\033[1;32m[INFO]\033[0m: " << message << std::endl;
}

void Log::warn(std::string message)
{
    std::cout << "\033[1;33m[WARN]\033[0m: " << message << std::endl;
}

void Log::error(std::string message)
{
    std::cout << "\033[1;31m[ERROR]\033[0m: " << message << std::endl;
}

void Log::fatal(std::string message)
{
    std::cout << "\033[1;37m[FATAL]\033[0m: " << message << std::endl;
    exit(EXIT_FAILURE);
}

void Log::stopRaylibLogging()
{
    SetTraceLogLevel(LOG_NONE);
}
