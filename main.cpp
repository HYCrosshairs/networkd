#include "Network.hpp"

#include <iostream>

using namespace service::network;

int main(int argc, char const *argv[])
{
    Network network;

    std::cout << network.getResponse("https://fr.wikipedia.org/wiki/BMW_S%C3%A9rie_3") << std::endl;
    return 0;
}
