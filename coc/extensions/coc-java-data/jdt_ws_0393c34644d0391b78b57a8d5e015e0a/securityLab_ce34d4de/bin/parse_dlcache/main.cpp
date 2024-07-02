#include "ldcache.h"

#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "start main." << std::endl;
    PreloadCache preloadCache("/etc/ld.so.cache");
    std::vector<ldcacheEntry> ret = preloadCache.parsePreloadCache();
    for (size_t i = 0; i < ret.size(); i++)
    {
        std::cout << ret[i].name << std::endl;
    }
    return 0;
}