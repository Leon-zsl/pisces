





#include <map>
#include <vector>
#include <string>

class StreamReader;
class PropertyCoeConfig
{
public:
    static std::map<int, PropertyCoeConfig*> dic;
    static std::vector<PropertyCoeConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    PropertyCoeConfig(
    int

 id_,

    float

 value_,

    std::string

 desc_
);
    ~PropertyCoeConfig();

    
    int

 id;
    
    float

 value;
    
    std::string

 desc;
};
