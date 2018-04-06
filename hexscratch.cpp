
#include <iostream>
#include <boost/algorithm/hex.hpp>
#include <string>

int main()
{
    std::string hexed("4142434445464748");

    // print it
    boost::algorithm::unhex(hexed, std::ostream_iterator<char>(std::cout));
    std::cout << std::endl;
    // or save it
    std::string unhexed;
    boost::algorithm::unhex(hexed, std::back_inserter(unhexed));
    std::cout << unhexed << std::endl;
    return 0;
}
