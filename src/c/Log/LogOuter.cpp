#include "LogOuter.h"

void set_log_level(log_level_t level) {
	LogInner::getInstance().setLogLevel(level);
}

void logv_tag(const char* tag, const char* format, ...) {
	va_list list;
	va_start(list, format);
	LogInner::getInstance().v(tag, format, list);
	va_end(list);
}

void logd_tag(const char* tag, const char* format, ...) {
	va_list list;
	va_start(list, format);
	LogInner::getInstance().d(tag, format, list);
	va_end(list);
}

void logi_tag(const char* tag, const char* format, ...) {
	va_list list;
	va_start(list, format);
	LogInner::getInstance().i(tag, format, list);
	va_end(list);
}

void logw_tag(const char* tag, const char* format, ...) {
	va_list list;
	va_start(list, format);
	LogInner::getInstance().w(tag, format, list);
	va_end(list);
}

void loge_tag(const char* tag, const char* format, ...) {
	va_list list;
	va_start(list, format);
	LogInner::getInstance().e(tag, format, list);
	va_end(list);
}
