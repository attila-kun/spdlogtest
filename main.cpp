#include <thread>
#include <iostream>
#include <spdlog/spdlog.h>
#include <spdlog/async.h>
#include <spdlog/sinks/stdout_sinks.h>
#include <spdlog/sinks/daily_file_sink.h>

static std::shared_ptr<spdlog::sinks::stdout_sink_st> stdoutSink = std::make_shared<spdlog::sinks::stdout_sink_st>();
static std::shared_ptr<spdlog::sinks::daily_file_sink_st> fileSink = std::make_shared<spdlog::sinks::daily_file_sink_st>("logfile", 23, 59);

class Log {
    public:
        Log() {
            std::cout << "Log created" << std::endl;

            std::vector<spdlog::sink_ptr> sinks;    
            sinks.push_back(stdoutSink);
            sinks.push_back(fileSink);
            auto combined_logger = std::make_shared<spdlog::async_logger>("name", begin(sinks), end(sinks), spdlog::thread_pool());
            std::cout << "A" << std::endl;
            (*combined_logger).info("hello");
            std::cout << "B" << std::endl;
        }
};

thread_local Log logger;

using namespace std;
int main() 
{    
    spdlog::init_thread_pool(10000, 1);
    Log log;
    return 0;
}