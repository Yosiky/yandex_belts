#include <sstream>
#include <string>
using namespace std;

class Logger {
public:
  explicit Logger(ostream& output_stream) : os(output_stream) {
  }

  void SetLogLine(bool value) { log_line = value; }
  void SetLogFile(bool value) { log_file= value; }

	bool GetLogLine(void) const { return (log_line); }
	bool GetLogFile(void) const { return (log_file); }

  void Log(const string& message) {
		os << message;
  }

private:
  ostream& os;
  bool log_line = false;
  bool log_file = false;
};

#define LOG_GET_LINE(line) #line
#define LOG_GET_LINE_STR(line) LOG_GET_LINE(line)

#define LOG(logger, message) 																				\
		do {																														\
		bool line = logger.GetLogLine();																\
		bool file = logger.GetLogFile();																\
		if (file)																												\
			logger.Log(__FILE__);																					\
		if (file && line)																								\
			logger.Log(":" LOG_GET_LINE_STR(__LINE__));										\
		else if (!file && line)																					\
			logger.Log("Line " LOG_GET_LINE_STR(__LINE__));								\
		if (file || line)																								\
			logger.Log(" ");																							\
		logger.Log(message);																						\
		logger.Log("\n");																								\
	} while (false);

// void TestLog() {
// /* Для написания юнит-тестов в этой задаче нам нужно фиксировать конкретные
//  * номера строк в ожидаемом значении (см. переменную expected ниже). Если
//  * мы добавляем какой-то код выше функции TestLog, то эти номера строк меняются,
//  * и наш тест начинает падать. Это неудобно.
//  *
//  * Чтобы этого избежать, мы используем специальный макрос #line
//  * (http://en.cppreference.com/w/cpp/preprocessor/line), который позволяет
//  * переопределить номер строки, а также имя файла. Благодаря ему, номера
//  * строк внутри функции TestLog будут фиксированы независимо от того, какой
//  * код мы добавляем перед ней*/
// #line 1 "logger.cpp"

//   ostringstream logs;
//   Logger l(logs);
//   LOG(l, "hello");

//   l.SetLogFile(true);
//   LOG(l, "hello");

//   l.SetLogLine(true);
//   LOG(l, "hello");

//   l.SetLogFile(false);
//   LOG(l, "hello");

//   string expected = "hello\n";
//   expected += "logger.cpp hello\n";
//   expected += "logger.cpp:10 hello\n";
//   expected += "Line 13 hello\n";
//   ASSERT_EQUAL(logs.str(), expected);
// }

// int main() {
//   TestRunner tr;
//   RUN_TEST(tr, TestLog);
// }
