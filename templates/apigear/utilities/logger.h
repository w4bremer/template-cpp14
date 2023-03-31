/*
* MIT License
*
* Copyright (c) 2021 ApiGear
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
#pragma once

#include <functional>
#include <string>

#if defined _WIN32 || defined __CYGWIN__
#ifdef __GNUC__
#define API_GEAR_LOGGER __attribute__ ((dllexport))
#else
#define API_GEAR_LOGGER __declspec(dllexport)
#endif
#else
#if __GNUC__ >= 4
#define API_GEAR_LOGGER __attribute__ ((visibility ("default")))
#else
#define API_GEAR_LOGGER
#endif
#endif


namespace ApiGear { namespace Utilities {

/**
* Logging levels for logs across the application.
*/
enum API_GEAR_LOGGER LogLevel {
    Info,
    Debug,
    Warning,
    Error
};

/** A type of function to log*/
using WriteLogFunc = std::function<void(LogLevel level, const std::string& msg)>;

/* 
* Set any log function which implements the WriteLogFunc signature
* 
* Can be used to disable logging or to write to a file or database.
*
* @param func a functions which implements the WriteLogFunc signature
*/
void API_GEAR_LOGGER setLog(WriteLogFunc func);

/* 
* Get the default console log function
*
* @return func returns the default console log function
*/
WriteLogFunc API_GEAR_LOGGER getConsoleLogFunc();

/*
* Use to log on LogLevel::Info
*/
void API_GEAR_LOGGER logInfo(const std::string& msg);

/*
* Use to log on LogLevel::Debug
*/
void API_GEAR_LOGGER logDebug(const std::string& msg);

/*
* Use to log on LogLevel::Warning
*/
void API_GEAR_LOGGER logWarning(const std::string& msg);

/*
* Use to log on LogLevel::Error
*/
void API_GEAR_LOGGER logError(const std::string& msg);

} } // ApiGear::Utilities
