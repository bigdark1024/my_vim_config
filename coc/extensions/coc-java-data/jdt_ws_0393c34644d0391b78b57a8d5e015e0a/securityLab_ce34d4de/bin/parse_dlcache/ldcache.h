#ifndef LD_CACHE_FILE_H
#define LD_CACHE_FILE_H

#include <iostream>
#include <vector>
#include <string>

struct ldcacheEntry {
    std::string name;
    std::string path;
};

class PreloadCache {
public:
    PreloadCache();
    PreloadCache(const std::string& path);
    ~PreloadCache();
    std::vector<ldcacheEntry> parsePreloadCache();
    std::vector<ldcacheEntry> parsePreloadCache(const std::string &path);
private:
    std::vector<ldcacheEntry> preloadVector;
    std::string preloadCachePath;
};

#endif