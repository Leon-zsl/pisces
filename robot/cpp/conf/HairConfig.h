





#include <map>
#include <vector>
#include <string>

class StreamReader;
class HairConfig
{
public:
    static std::map<int, HairConfig*> dic;
    static std::vector<HairConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    HairConfig(
    int

 id_,

    std::string

 hairMaleURL_,

    std::string

 hairFemaleURL_
);
    ~HairConfig();

    
    int

 id;
    
    std::string

 hairMaleURL;
    
    std::string

 hairFemaleURL;
};
