#include "Log.h"

#include <filesystem>
#include <fstream>
#include <thread>
#include <unordered_map>
#include <vector>



namespace rle
{
    namespace log
    {
        namespace detail
        {

// this directive frees some memory from defines and
// static allocations
#ifdef RLE_LOGGING

            static const std::unordered_map<std::uint8_t, std::string> severity_tags
            {
                { INFO, "[INFO]" },
                { WARN, "[WARN]" },
                { ERR, "[ERR]" }
            };

            static std::ofstream ofs;



            bool init(const std::string& path)
            {
                if (ofs.is_open())
                    ofs.close();

                // make sure the log directory is created
                std::filesystem::create_directories("./logs");

                ofs.open(path, std::ios_base::app);
                return ofs.is_open();
            }

            void out(const std::uint8_t severity, const std::string& msg)
            {
                if (!ofs.is_open())
                    return;

                if (severity_tags.find(severity) == severity_tags.end())
                    ofs << "[UNKNOWN] ";
                else
                    ofs << severity_tags.at(severity) << ' ';

                // get local time
                std::time_t t = time(NULL);
                struct tm buf;
                char str[26] = { 0 };
                localtime_s(&buf, &t);
                strftime(str, sizeof(str), "[%x-%X]", &buf);
                ofs << str << ' ' << msg << std::endl;
                ofs.flush();
            }

#endif // RLE_LOGGING

        }
    }
}
