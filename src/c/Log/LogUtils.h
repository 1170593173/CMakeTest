#ifndef _LOG_UTILS_H_
#define _LOG_UTILS_H_

#include "LogOuter.h"
#include <string.h>
#include <chrono>

// Windows文件路径分隔符是\\，Linux文件路径分隔符是/
#ifdef _MSC_VER
#define __FILENAME__ (strrchr(__FILE__, '\\') + 1)
#else
#define __FILENAME__ (strrchr(__FILE__, '/') + 1)
#endif

// 可自定义标签，在cpp中自己定义这个宏就行，如若没有则使用默认标签
#ifndef LOG_TAG
#define LOG_TAG "default_tag"
#endif

#define LOG_TRACE(func, format, ...) \
    func(LOG_TAG, "[%s][%s][%d]: " format, __FILENAME__, __FUNCTION__, __LINE__, ##__VA_ARGS__)

#define LOGV(format, ...) LOG_TRACE(logv_tag, format, ##__VA_ARGS__)
#define LOGD(format, ...) LOG_TRACE(logd_tag, format, ##__VA_ARGS__)
#define LOGI(format, ...) LOG_TRACE(logi_tag, format, ##__VA_ARGS__)
#define LOGW(format, ...) LOG_TRACE(logw_tag, format, ##__VA_ARGS__)
#define LOGE(format, ...) LOG_TRACE(loge_tag, format, ##__VA_ARGS__)

#define __TIC__(V) auto time_##V##_start = std::chrono::high_resolution_clock::now()
#define __TOC__(V) auto time_##V##_end = std::chrono::high_resolution_clock::now(); \
                   auto time_##V##_span = std::chrono::duration_cast<std::chrono::duration<double>> \
                       (time_##V##_end - time_##V##_start); \
                   LOGD("%s elapse time: %.3f ms", #V, time_##V##_span.count() * 1000)

#endif // _LOG_UTILS_H_
