#include "LogInner.h"
#include <time.h>
#include <chrono>
#include <mutex>

using namespace std::chrono;

std::mutex mtx; // 多线程场景下打印使用，不是多线程的话关掉可以节约点性能

void LogInner::output(const FILE* f, const char& level, const char* tag, const char* format, va_list list) const {
	FILE* fp = const_cast<FILE*>(f);
	auto now = system_clock::now();
	time_t tt = system_clock::to_time_t(now);
	struct tm* timeinfo = localtime(&tt);
	mtx.lock();
	fprintf(fp, "[%02d-%02d %02d:%02d:%02d.%03d %c/%s] ",
		timeinfo->tm_mon + 1,
		timeinfo->tm_mday,
		timeinfo->tm_hour,
		timeinfo->tm_min,
		timeinfo->tm_sec,
		(int)(duration_cast<milliseconds>(now.time_since_epoch()).count() % 1000),
		level, tag);
	vfprintf(fp, format, list);
	fprintf(fp, "\n");
	mtx.unlock();
}

void LogInner::v(const char* tag, const char* format, va_list list) const  {
	if (mLevel > LOG_LEVEL_VERBOSE) {
		return;
	}
	output(stdout, 'V', tag, format, list);
}

void LogInner::d(const char* tag, const char* format, va_list list) const  {
	if (mLevel > LOG_LEVEL_DEBUG) {
		return;
	}
	output(stdout, 'D', tag, format, list);
}

void LogInner::i(const char* tag, const char* format, va_list list) const  {
	if (mLevel > LOG_LEVEL_INFO) {
		return;
	}
	output(stdout, 'I', tag, format, list);
}

void LogInner::w(const char* tag, const char* format, va_list list) const  {
	if (mLevel > LOG_LEVEL_WARN) {
		return;
	}
	output(stdout, 'W', tag, format, list);
}

void LogInner::e(const char* tag, const char* format, va_list list) const  {
	if (mLevel > LOG_LEVEL_ERR) {
		return;
	}
	output(stderr, 'E', tag, format, list);
}

LogInner& LogInner::getInstance() {
	static LogInner instance;
	return instance;
}

LogInner::LogInner() : mLevel(LOG_LEVEL_VERBOSE) {
}

LogInner::~LogInner() {
}

void LogInner::setLogLevel(log_level_t level) {
	mLevel = level;
}
