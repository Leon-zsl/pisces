





#include <map>
#include <vector>
#include <string>

class StreamReader;
class DeputySkillConfig
{
public:
    static std::map<int, DeputySkillConfig*> dic;
    static std::vector<DeputySkillConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    DeputySkillConfig(
    int

 id_,

    std::string

 name_,

    std::string

 texUrl_,

    int

 deputyID_,

    int




 * itemIDs_,

    int




 * itemCounts_,

    bool

 isSltItemRqr_,

    int




 * addiItemIDs_,

    int




 * addItemCounts_,

    std::string




 * randomItems_,

    int

 targetItemID_,

    int

 targetItemCount_,

    int

 requiredItemID_,

    int

 deputyLevel_,

    std::string

 description_,

    int

 orangeLevel_,

    int

 yellowLevel_,

    int

 greenLevel_,

    int

 money_,

    int

 subDeputyID_,

    int




 * stgPart_,

    int

 costTime_,

    int




 * stgPropIDs_,

    int




 * stgPropValues_,

    int

 stgSkillID_
);
    ~DeputySkillConfig();

    
    int

 id;
    
    std::string

 name;
    
    std::string

 texUrl;
    
    int

 deputyID;
    
    int




 * itemIDs;
    
    int




 * itemCounts;
    
    bool

 isSltItemRqr;
    
    int




 * addiItemIDs;
    
    int




 * addItemCounts;
    
    std::string




 * randomItems;
    
    int

 targetItemID;
    
    int

 targetItemCount;
    
    int

 requiredItemID;
    
    int

 deputyLevel;
    
    std::string

 description;
    
    int

 orangeLevel;
    
    int

 yellowLevel;
    
    int

 greenLevel;
    
    int

 money;
    
    int

 subDeputyID;
    
    int




 * stgPart;
    
    int

 costTime;
    
    int




 * stgPropIDs;
    
    int




 * stgPropValues;
    
    int

 stgSkillID;
};
