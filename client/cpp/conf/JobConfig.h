





#include <map>
#include <vector>
#include <string>

class StreamReader;
class JobConfig
{
public:
    static std::map<int, JobConfig*> dic;
    static std::vector<JobConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    JobConfig(
    int

 id_,

    std::string

 name_,

    int

 propID_,

    int

 maleFigureID_,

    int

 femaleFigureID_,

    int

 figureType_,

    int

 maxLevel_,

    int




 * talentIDArr_,

    int

 infoTxtID_,

    int




 * initEquipIDArr_,

    int




 * initBagItemIDs_,

    std::string




 * initItemIDsInBag_
);
    ~JobConfig();

    
    int

 id;
    
    std::string

 name;
    
    int

 propID;
    
    int

 maleFigureID;
    
    int

 femaleFigureID;
    
    int

 figureType;
    
    int

 maxLevel;
    
    int




 * talentIDArr;
    
    int

 infoTxtID;
    
    int




 * initEquipIDArr;
    
    int




 * initBagItemIDs;
    
    std::string




 * initItemIDsInBag;
};
