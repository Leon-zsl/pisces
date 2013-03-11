



#include <map>
#include <vector>
#include <string>

class StreamReader;
class CollectionConfig
{
public:
    static std::map<int, CollectionConfig*> dic;
    static std::vector<CollectionConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    CollectionConfig(
    int
 id_, 
    std::string
 name_, 
    float
 length_, 
    float
 width_, 
    int
 type_, 
    std::string
 description_, 
    std::string



* resUrl_,
    int
 refreshSecond_, 
    int



* prodItemIDs_,
    int



* rdItemIDs_,
    std::string



* rdItemCounts_,
    int



* prodItemCountLimit_,
    int
 requiredSkillID_, 
    int
 skillLevel_, 
    int
 costItemID_, 
    int
 costItemCount_, 
    int



* periods_,
    std::string



* products_,
    int
 text_);
    ~CollectionConfig();

    
    int
     id;
    
    std::string
     name;
    
    float
     length;
    
    float
     width;
    
    int
     type;
    
    std::string
     description;
    
    std::string



*     resUrl;
    
    int
     refreshSecond;
    
    int



*     prodItemIDs;
    
    int



*     rdItemIDs;
    
    std::string



*     rdItemCounts;
    
    int



*     prodItemCountLimit;
    
    int
     requiredSkillID;
    
    int
     skillLevel;
    
    int
     costItemID;
    
    int
     costItemCount;
    
    int



*     periods;
    
    std::string



*     products;
    
    int
     text;
};
