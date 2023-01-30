#include <stdio.h>

//#include "math/add.h"
#ifdef __cplusplus
extern "C" {
#endif

int add_int(int x, int y);

int reduce_int(int x, int y);

#ifdef __cplusplus
}
#endif

#include "math/minus.h"
#include "myfile.h"
#include "cJSON.h"


#include "Log/LogOuter.h"
#include <string.h>
#include <chrono>
#include <thread>

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

/*用途：打印不同类型的日志*/
#define LOGV(format, ...) LOG_TRACE(logv_tag, format, ##__VA_ARGS__)
#define LOGD(format, ...) LOG_TRACE(logd_tag, format, ##__VA_ARGS__)
#define LOGI(format, ...) LOG_TRACE(logi_tag, format, ##__VA_ARGS__)
#define LOGW(format, ...) LOG_TRACE(logw_tag, format, ##__VA_ARGS__)
#define LOGE(format, ...) LOG_TRACE(loge_tag, format, ##__VA_ARGS__)

/*用途:计算一段程序的运行时间
__TIC__(V)表示的起始点计时
__TOC__(V)表示的结束点的时间*/
#define __TIC__(V) auto time_##V##_start = std::chrono::high_resolution_clock::now()
#define __TOC__(V) auto time_##V##_end = std::chrono::high_resolution_clock::now(); \
                   auto time_##V##_span = std::chrono::duration_cast<std::chrono::duration<double>> \
                       (time_##V##_end - time_##V##_start); \
                   LOGD("%s elapse time: %.3f ms", #V, time_##V##_span.count() * 1000)

void foo() {
    for (int i = 0; i < 5; i++) { LOGD("i: %d", i); }
}

void bar() {
    for (char c = 'a'; c < 'f'; c++) { LOGD("c: %c", c); }
}

int main(void) {

#ifdef REAL_COOL_ENGINEER
  std::cout<<"in ifdef"<<std::endl;
#else
  std::cout<<"not in ifdef"<<std::endl;
#endif
#ifdef TESTQQQ
  std::cout<<"in ifdef"<<std::endl;
#else
  std::cout<<"not in ifdef"<<std::endl;
#endif

  printf("Hello CMake!\n");

  int res = add_int(10, 24);
  printf("10 + 24 = %d\n", res);

  res = reduce_int(24, 10);
  printf("24 - 10 = %d\n", res);

  res = minus_int(40, 96);
  printf("40 - 96 = %d\n", res);

  student m_stu;
  cout<<m_stu.getname()<<endl;
  cout<<m_stu.getage()<<endl;

  //读
  cJSON *json;//封装后的json对象
	json=cJSON_Parse("{\"duration\":4,\"name\":\"file_integrity_detection_linux_ex.lua\",\"req_id\":\"0:63bfbdf323de2f00011fe189\",\"ret_code\":0,\"ret_msg\":\"[{\"count\":3,\"taskid\":\"63bfb25c8f8ba13a95ea8dc1\",\"timestamp\":1673510402,\"msg\":\"\",\"code\":0}]\",\"script_id\":\"agent.java.common.f3be53ecf5af4ec15694\"}");
	if (!json) {
		printf("Error before: [%s]\n",cJSON_GetErrorPtr());
	}
	char *out=cJSON_Print(json);
  if (out)
  {
    string aaa = out;
    cout<<aaa<<endl;
  }

  set_log_level(LOG_LEVEL_DEBUG);
  LOGV("test log v"); // won't print， because debug level > verbose level
  __TIC__(task);
  int res1 = 0;
  for (size_t i = 0; i < 1000; i++)
  {
    res1 += i;
    
  }
  std::cout<<res1<<std::endl;
  
  std::thread t1(foo);
  std::thread t2(bar);
  t1.join();
  t2.join();
  __TOC__(task); // print time elapse

  return 0;
}
