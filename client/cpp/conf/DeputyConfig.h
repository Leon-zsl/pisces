



#include <map>
#include <vector>
#include <string>

class StreamReader;
class DeputyConfig
{
public:
    static std::map<int, DeputyConfig*> dic;
    static std::vector<DeputyConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    DeputyConfig(
    int
 id_, 
    std::string
 name_, 
    std::string
 texUrl_, 
    int



* deputyPointsLimits_,
    int



* jobLevels_,
    std::string



* levelName_,
    int



* moneys_,
    int
 subDeputyCount_, 
    std::string



* subDeputyNames_,
    int



* initDeputySkillIDs_,
    std::string
 description_);
    ~DeputyConfig();

    
    int
     id;
    
    std::string
     name;
    
    std::string
     texUrl;
    
    int



*     deputyPointsLimits;
    
    int



*     jobLevels;
    
    std::string



*     levelName;
    
    int



*     moneys;
    
    int
     subDeputyCount;
    
    std::string



*     subDeputyNames;
    
    int



*     initDeputySkillIDs;
    
    std::string
     description;
};
