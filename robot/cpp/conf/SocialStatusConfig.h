





#include <map>
#include <vector>
#include <string>

class StreamReader;
class SocialStatusConfig
{
public:
    static std::map<int, SocialStatusConfig*> dic;
    static std::vector<SocialStatusConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    SocialStatusConfig(
    int

 id_,

    int

 statusId_,

    std::string

 desc_
);
    ~SocialStatusConfig();

    
    int

 id;
    
    int

 statusId;
    
    std::string

 desc;
};
