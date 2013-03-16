





#include <map>
#include <vector>
#include <string>

class StreamReader;
class GuildRankRightsConfig
{
public:
    static std::map<int, GuildRankRightsConfig*> dic;
    static std::vector<GuildRankRightsConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    GuildRankRightsConfig(
    int

 id_,

    int

 right_,

    std::string

 desc_,

    std::string




 * npcArr_
);
    ~GuildRankRightsConfig();

    
    int

 id;
    
    int

 right;
    
    std::string

 desc;
    
    std::string




 * npcArr;
};
