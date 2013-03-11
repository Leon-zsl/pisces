



#include <map>
#include <vector>
#include <string>

class StreamReader;
class GuildRankConfig
{
public:
    static std::map<int, GuildRankConfig*> dic;
    static std::vector<GuildRankConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    GuildRankConfig(
    int
 id_, 
    std::string
 name_, 
    int



* rights_);
    ~GuildRankConfig();

    
    int
     id;
    
    std::string
     name;
    
    int



*     rights;
};
