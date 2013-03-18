





#include <map>
#include <vector>
#include <string>

class StreamReader;
class FactionConfig
{
public:
    static std::map<int, FactionConfig*> dic;
    static std::vector<FactionConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    FactionConfig(
    int

 id_,

    std::string

 name_,

    int




 * prestigeLevelArr_,

    int




 * prestigeArr_,

    std::string




 * prestigeNameArr_
);
    ~FactionConfig();

    
    int

 id;
    
    std::string

 name;
    
    int




 * prestigeLevelArr;
    
    int




 * prestigeArr;
    
    std::string




 * prestigeNameArr;
};
