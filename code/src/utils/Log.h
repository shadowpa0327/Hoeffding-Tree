/*
 * Copyright (C) 2015 Holmes Team at HUAWEI Noah's Ark Lab.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef Log_H_
#define Log_H_

#include <iostream>
#include <string>
#include <cstdarg>
#include <vector>

// Function for handling formatted strings
inline std::string format_string(const char* format, ...) {
    va_list args;
    va_start(args, format);
    std::vector<char> buffer(1024);
    vsnprintf(buffer.data(), buffer.size(), format, args);
    va_end(args);
    return std::string(buffer.data());
}

// Overload for handling a single string argument
inline std::string format_string(const std::string& message) {
    return message;
}

// Logging macro
#define LOG_INFO(...) std::cout << "INFO: " << format_string(__VA_ARGS__) << std::endl
#define LOG_DEBUG(...)  std::cout << "DEBUG: " << format_string(__VA_ARGS__) << std::endl
#define LOG_WARN(...)  std::cout << "WARNING: " << format_string(__VA_ARGS__) << std::endl
#define LOG_ERROR(...) std::cerr << "ERROR: " << format_string(__VA_ARGS__) << std::endl

#endif /* Log_H_ */
