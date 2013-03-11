









#include "StreamReader.h"
#include "ItemConfig.h"

using namespace std;

std::map<int, ItemConfig*> ItemConfig::dic;
std::vector<ItemConfig*> ItemConfig::list;

ItemConfig::ItemConfig(
    int
 id_, 
    std::string
 name_, 
    std::string
 description_, 
    std::string
 iconUrl_, 
    std::string
 resName_, 
    int
 type_, 
    int
 npcPrice_, 
    int
 grade_, 
    int
 level_, 
    int
 levelRequired_, 
    int
 binding_, 
    int
 maxCount_, 
    int
 linkID_, 
    int
 skillID_, 
    bool
 useDestruction_, 
    bool
 offlineDestruction_)
{
    id = id_;
    name = name_;
    description = description_;
    iconUrl = iconUrl_;
    resName = resName_;
    type = type_;
    npcPrice = npcPrice_;
    grade = grade_;
    level = level_;
    levelRequired = levelRequired_;
    binding = binding_;
    maxCount = maxCount_;
    linkID = linkID_;
    skillID = skillID_;
    useDestruction = useDestruction_;
    offlineDestruction = offlineDestruction_;
}

ItemConfig::~ItemConfig()
{
}
    
void ItemConfig::build()
{
    std::string path = "./data/";
    path += "ItemConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "ItemConfig")
    {
        printf("invalid file flag %s", flag.c_str());
        delete rs;
        return;
    }
        
    int col_cnt = rs->read_short();
    if(col_cnt != 16)
    {
        printf("col cnt invalid %d : %d", col_cnt, 16);
        delete rs;
        return;
    }
            
    int row_cnt = rs->read_int();
    for(int i = 0; i < row_cnt; i++)
        add_item(rs);

    delete rs;
}

void ItemConfig::add_item(StreamReader* rs)
{

    
    int
     id_ =     
    rs->read_int();

    
    std::string
     name_ =     
    rs->read_string();

    
    std::string
     description_ =     
    rs->read_string();

    
    std::string
     iconUrl_ =     
    rs->read_string();

    
    std::string
     resName_ =     
    rs->read_string();

    
    int
     type_ =     
    rs->read_int();

    
    int
     npcPrice_ =     
    rs->read_int();

    
    int
     grade_ =     
    rs->read_int();

    
    int
     level_ =     
    rs->read_int();

    
    int
     levelRequired_ =     
    rs->read_int();

    
    int
     binding_ =     
    rs->read_int();

    
    int
     maxCount_ =     
    rs->read_int();

    
    int
     linkID_ =     
    rs->read_int();

    
    int
     skillID_ =     
    rs->read_int();

    
    bool
     useDestruction_ =     
    rs->read_bool();

    
    bool
     offlineDestruction_ =     
    rs->read_bool();

        
    if(id_ == 0)
    {
        printf("invalid key: %d", id_);
        return;
    }
    if(dic.find(id_) != dic.end())
    {
        printf("duplicate key: %d", id_);
        return;
    }

    ItemConfig* new_obj_ItemConfig = new ItemConfig(id_, name_, description_, iconUrl_, resName_, type_, npcPrice_, grade_, level_, levelRequired_, binding_, maxCount_, linkID_, skillID_, useDestruction_, offlineDestruction_);

    dic[id_] = new_obj_ItemConfig;
    list.push_back(new_obj_ItemConfig);
}

void ItemConfig::destroy()
{
    for(std::vector<ItemConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
