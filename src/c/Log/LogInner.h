#ifndef LOG_INNER_HPP_
#define LOG_INNER_HPP_

#include <stdarg.h>
#include <stdio.h>

/// @brief 日志级别
/// 级别排序 ERROR > WARNING > INFO > DEBUG > VERBOSE
typedef enum {
	LOG_LEVEL_VERBOSE,        ///< 打印所有级别日志
	LOG_LEVEL_DEBUG,          ///< 打印高于DEBUG(包含)级别日志
	LOG_LEVEL_INFO,           ///< 打印高于INFO(包含)级别日志
	LOG_LEVEL_WARN,           ///< 打印高于WARNING(包含)级别日志
	LOG_LEVEL_ERR,            ///< 打印高于ERROR(包含)级别日志
	LOG_LEVEL_CLOSE           ///< 关闭
} log_level_t;

class LogInner {

public:
	// @brief 获取LogInner单例对象
	static LogInner& getInstance();

	/// @brief 设置log级别
	/// @param [in] level 级别
	void setLogLevel(log_level_t level);

	/// @brief 自定义tag的log
	/// @param [in] tag 自定义的tag
	/// @param [in] format 字符串格式
	/// @param [in] list 待输出的可变参数
	void v(const char* tag, const char* format, va_list list) const;

	/// @brief 自定义tag的log
	/// @param [in] tag 自定义的tag
	/// @param [in] format 字符串格式
	/// @param [in] list 待输出的可变参数
	void d(const char* tag, const char* format, va_list list) const;

	/// @brief 自定义tag的log
	/// @param [in] tag 自定义的tag
	/// @param [in] format 字符串格式
	/// @param [in] list 待输出的可变参数
	void i(const char* tag, const char* format, va_list list) const;

	/// @brief 自定义tag的log
	/// @param [in] tag 自定义的tag
	/// @param [in] format 字符串格式
	/// @param [in] list 待输出的可变参数
	void w(const char* tag, const char* format, va_list list) const;

	/// @brief 自定义tag的log
	/// @param [in] tag 自定义的tag
	/// @param [in] format 字符串格式
	/// @param [in] list 待输出的可变参数
	void e(const char* tag, const char* format, va_list list) const;

private:
	LogInner();
	~LogInner();
	LogInner(const LogInner& rhs);
	const LogInner& operator= (const LogInner& rhs);
	void output(const FILE* f, const char& l, const char* tag, const char* format, va_list list) const;

	log_level_t mLevel;
};

#endif //LOG_INNER_HPP_
