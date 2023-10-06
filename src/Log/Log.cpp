#include "Log.h"

void Log::info(std::string message)
{
    std::cout << "[INFO]: " << message << std::endl;
}

void Log::warn(std::string message)
{
    std::cout << "[WARN]: " << message << std::endl;
}

void Log::error(std::string message)
{
    std::cout << "[ERROR]: " << message << std::endl;
}

void Log::fatal(std::string message)
{
    std::cout << "[FATAL]: " << message << std::endl;
    exit(EXIT_FAILURE);
}

void Log::stopRaylibLogging()
{
    SetTraceLogLevel(LOG_NONE);
}
