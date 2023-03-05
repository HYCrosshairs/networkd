#pragma once

#include <curl/curl.h>

#include <string>

namespace service::network
{
class Network
{
public:
    Network();
    ~Network();

    std::string getResponse(const std::string& url) const;

private:
    CURL* mHandler;

    static size_t callback(char* resBuffer, size_t size, size_t blockNbr, void* storeBuffer)
    {
        std::string& data = *reinterpret_cast<std::string*>(storeBuffer);
        data.append(resBuffer, size * blockNbr);
        return size * blockNbr;
    }
};    
} // namespace service::network
