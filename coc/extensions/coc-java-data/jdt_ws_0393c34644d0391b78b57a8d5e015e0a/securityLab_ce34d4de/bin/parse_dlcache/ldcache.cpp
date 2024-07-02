#include "ldcache.h"
#include <fstream>
#include <cstdio>
#include <cstring>

using namespace std;

static std::string g_ldcachePath = "/etc/ld.so.cache";
static std::vector<ldcacheEntry> g_parseCache;
static std::fstream fs;

#define CACHE_MAGIC_NEW "glibc-ld.so.cache1.1"
#define FLAG_ELF 0x01

struct header_new
{
	char magic[sizeof(CACHE_MAGIC_NEW) - 1];
	uint32_t lib_count;
	uint32_t strs_len;
	uint32_t unused[5];
};

struct entry_new
{
	int32_t flags;
	uint32_t key;
	uint32_t value;
	uint32_t os_ver;
	uint64_t hwcap;
};

PreloadCache::PreloadCache() {

}

PreloadCache::PreloadCache(const std::string& path) {
    this->preloadCachePath = path;
}

PreloadCache::~PreloadCache() {
    cout << "Execute ~PreloadCache." << endl;
    if (fs) {
        cout << "Execute close preload cache file." << endl;
        fs.close();
    }
}

std::vector<ldcacheEntry> PreloadCache::parsePreloadCache() {
    std::cout << "start parsePreloadCache()." << std::endl;
    return parsePreloadCache(g_ldcachePath);
}

std::vector<ldcacheEntry> PreloadCache::parsePreloadCache(const std::string &path) {
    printf("--------> [%s] \n", path.c_str());
    fs.open(path, ios::in | ios::binary);
    if (!fs.is_open())
    {
        cout << "Error opening file." << endl;
        return g_parseCache;
    }

    fs.seekg( 0, ios::end );
    int size = fs.tellg();
    fs.seekg(0, ios::beg);
    cout << "size: " << size << endl;

    FILE* f = std::fopen(path.c_str(), "rb");
    if (f == nullptr) {
        return g_parseCache;
    }
    struct header_new hdrNew;
    std::fread(&hdrNew, sizeof(struct header_new), 1, f);
    
    cout << "magic = " << hdrNew.magic << endl;
    cout << "lib_count = " << hdrNew.lib_count << endl;

    if (!fs) {
        fs.close();
    }

    return g_parseCache;
}