





#include <map>
#include <vector>
#include <string>

class StreamReader;
class FigureConfig
{
public:
    static std::map<int, FigureConfig*> dic;
    static std::vector<FigureConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    FigureConfig(
    int

 id_,

    float

 length_,

    float

 width_,

    float

 height_,

    std::string

 modelUrl_,

    int




 * avatarIDArr_,

    std::string




 * avatarNameArr_
);
    ~FigureConfig();

    
    int

 id;
    
    float

 length;
    
    float

 width;
    
    float

 height;
    
    std::string

 modelUrl;
    
    int




 * avatarIDArr;
    
    std::string




 * avatarNameArr;
};
