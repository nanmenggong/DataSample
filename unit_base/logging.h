#ifndef LOGGING_H_
#define LOGGING_H_
#include <sstream>

const char* FilenameFromPath(const char* file);

class LogStream
{
public:
    LogStream() = default;

    LogStream(const char* file_name, const int line);

    LogStream(const char* file_name, const int line, const char* mark);

    ~LogStream();

    std::ostream&
    ostream()
    {
        return print_stream_;
    }

private:
    std::ostringstream print_stream_;
    const int line_;
    const char* file_name_;
    int thread_num_;
};

#define LOG \
  LogStream(__FILE__, __LINE__).ostream()

#define LOG_MING \
  LogStream(__FILE__, __LINE__, "Ming:").ostream()

#define EQUAL_DE(v1, v2) \
    if((v1) != (v2)) \
  (LOG<< "Check failed: " << v1 << " is not "<< (v2))

#define EQUAL_DE_INFO(v1, v2, v3) \
    if((v1) != (v2)) \
  (LOG<< "Check failed: " << v1 << " is not "<< (v2) << ", "<<(v3))

#endif
