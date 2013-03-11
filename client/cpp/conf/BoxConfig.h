



#include <map>
#include <vector>
#include <string>

class StreamReader;
class BoxConfig
{
public:
    static std::map<int, BoxConfig*> dic;
    static std::vector<BoxConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    BoxConfig(
    int
 id_, 
    std::string
 name_, 
    std::string
 resUrl_, 
    bool
 isInteractive_, 
    int
 refreshSecond_, 
    int
 health_, 
    float
 length_, 
    float
 width_, 
    float
 height_, 
    int
 damageSkillID_, 
    std::string



* dropObjectsData_);
    ~BoxConfig();

    
    int
     id;
    
    std::string
     name;
    
    std::string
     resUrl;
    
    bool
     isInteractive;
    
    int
     refreshSecond;
    
    int
     health;
    
    float
     length;
    
    float
     width;
    
    float
     height;
    
    int
     damageSkillID;
    
    std::string



*     dropObjectsData;
};
