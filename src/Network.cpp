#include "Network.hpp"

#include <stdexcept>

using namespace service::network;

Network::Network()
{
    curl_global_init(CURL_GLOBAL_ALL);
    mHandler = curl_easy_init();

    if (not mHandler)
    {
        throw std::runtime_error("Failed to initialize curl");
    }
}

Network::~Network()
{
    curl_easy_cleanup(mHandler);
    curl_global_cleanup();
}

std::string Network::getResponse(const std::string& url) const
{
    std::string result;

    curl_easy_setopt(mHandler, CURLOPT_URL, url.c_str());
    curl_easy_setopt(mHandler, CURLOPT_WRITEFUNCTION, callback);
    curl_easy_setopt(mHandler, CURLOPT_WRITEDATA, &result);

    CURLcode response = curl_easy_perform(mHandler);

    if (response not_eq CURLE_OK)
    {
        throw std::runtime_error("Failed to perform curl request");
    }
    return result;    
}
