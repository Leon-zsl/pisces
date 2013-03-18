





#include <map>
#include <vector>
#include <string>

class StreamReader;
class GuildConfig
{
public:
    static std::map<int, GuildConfig*> dic;
    static std::vector<GuildConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    GuildConfig(
    int

 id_,

    int

 memberCapicity_
);
    ~GuildConfig();

    
    int

 id;
    
    int

 memberCapicity;
};
