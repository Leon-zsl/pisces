





#include <map>
#include <vector>
#include <string>

class StreamReader;
class SceneConfig
{
public:
    static std::map<int, SceneConfig*> dic;
    static std::vector<SceneConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    SceneConfig(
    int

 id_,

    std::string

 sceneName_,

    int

 sceneType_,

    std::string

 resName_,

    int

 landID_,

    int

 level_,

    float

 length_,

    float

 width_,

    std::string




 * fixedBlockArr_,

    std::string

 bornPos_,

    std::string




 * portalArr_,

    std::string




 * npcArr_,

    std::string




 * boxMinePosArr_,

    std::string




 * monsterPosArr_,

    std::string

 bossPos_,

    std::string

 exBoxPos_
);
    ~SceneConfig();

    
    int

 id;
    
    std::string

 sceneName;
    
    int

 sceneType;
    
    std::string

 resName;
    
    int

 landID;
    
    int

 level;
    
    float

 length;
    
    float

 width;
    
    std::string




 * fixedBlockArr;
    
    std::string

 bornPos;
    
    std::string




 * portalArr;
    
    std::string




 * npcArr;
    
    std::string




 * boxMinePosArr;
    
    std::string




 * monsterPosArr;
    
    std::string

 bossPos;
    
    std::string

 exBoxPos;
};
