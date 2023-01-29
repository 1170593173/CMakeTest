#ifndef LOG_OUTER_H_
#define LOG_OUTER_H_

#include "LogInner.h"

#ifdef __cplusplus
extern "C" {
#endif

/// @brief 打开log开关，默认LOG_LEVEL_VERBOSE
void set_log_level(log_level_t level);

/// @brief 带tag的verbose级别log
/// @param [in] tag log标识
/// @param [in] format 输出消息格式化字符串
/// @param [in] ...(可变参数)
void logv_tag(const char* tag, const char* format, ...);

/// @brief 带tag的debug级别log
/// @param [in] tag log标识
/// @param [in] format 输出消息格式化字符串
/// @param [in] ...(可变参数)
void logd_tag(const char* tag, const char* format, ...);

/// @brief 带tag的info级别log
/// @param [in] tag log标识
/// @param [in] format 输出消息格式化字符串
/// @param [in] ...(可变参数)
void logi_tag(const char* tag, const char* format, ...);

/// @brief 带tag的warning级别log
/// @param [in] tag log标识
/// @param [in] format 输出消息格式化字符串
/// @param [in] ...(可变参数)
void logw_tag(const char* tag, const char* format, ...);

/// @brief 带tag的error级别log
/// @param [in] tag log标识
/// @param [in] format 输出消息格式化字符串
/// @param [in] ...(可变参数)
void loge_tag(const char* tag, const char* format, ...);

#ifdef __cplusplus
}
#endif

#endif //LOG_OUTER_H_
