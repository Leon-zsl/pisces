





#include <map>
#include <vector>
#include <string>

class StreamReader;
class CargoConfig
{
public:
    static std::map<int, CargoConfig*> dic;
    static std::vector<CargoConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    CargoConfig(
    int

 id_,

    std::string

 name_,

    int




 * itemIDArr_,

    int




 * itemLimitArr_,

    std::string




 * prestigeLevelArr_,

    std::string




 * priceArr_
);
    ~CargoConfig();

    
    int

 id;
    
    std::string

 name;
    
    int




 * itemIDArr;
    
    int




 * itemLimitArr;
    
    std::string




 * prestigeLevelArr;
    
    std::string




 * priceArr;
};
