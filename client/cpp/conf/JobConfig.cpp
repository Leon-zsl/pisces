









#include "StreamReader.h"
#include "JobConfig.h"

using namespace std;

std::map<int, JobConfig*> JobConfig::dic;
std::vector<JobConfig*> JobConfig::list;

JobConfig::JobConfig(
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



* initItemIDsInBag_)
{
    id = id_;
    name = name_;
    propID = propID_;
    maleFigureID = maleFigureID_;
    femaleFigureID = femaleFigureID_;
    figureType = figureType_;
    maxLevel = maxLevel_;
    talentIDArr = talentIDArr_;
    infoTxtID = infoTxtID_;
    initEquipIDArr = initEquipIDArr_;
    initBagItemIDs = initBagItemIDs_;
    initItemIDsInBag = initItemIDsInBag_;
}

JobConfig::~JobConfig()
{
    delete[] talentIDArr;
    delete[] initEquipIDArr;
    delete[] initBagItemIDs;
    delete[] initItemIDsInBag;
}
    
void JobConfig::build()
{
    //std::string path = "./data/";
    //path += "JobConfig.bytes";
    std::string path = "JobConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "JobConfig")
    {
        printf("invalid file flag %s", flag.c_str());
        delete rs;
        return;
    }
        
    int col_cnt = rs->read_short();
    if(col_cnt != 12)
    {
        printf("col cnt invalid %d : %d", col_cnt, 12);
        delete rs;
        return;
    }
            
    int row_cnt = rs->read_int();
    for(int i = 0; i < row_cnt; i++)
        add_item(rs);

    delete rs;
}

void JobConfig::add_item(StreamReader* rs)
{
    int arr_item_len_JobConfig;

    
    int
     id_ =     
    rs->read_int();

    
    std::string
     name_ =     
    rs->read_string();

    
    int
     propID_ =     
    rs->read_int();

    
    int
     maleFigureID_ =     
    rs->read_int();

    
    int
     femaleFigureID_ =     
    rs->read_int();

    
    int
     figureType_ =     
    rs->read_int();

    
    int
     maxLevel_ =     
    rs->read_int();

    arr_item_len_JobConfig = rs->read_short();
    
    int



*     talentIDArr_ =     new 
    int



     [arr_item_len_JobConfig];

    for(int i = 0; i < arr_item_len_JobConfig; ++i)
        talentIDArr_[i] =         
    rs->read_int();

    
    int
     infoTxtID_ =     
    rs->read_int();

    arr_item_len_JobConfig = rs->read_short();
    
    int



*     initEquipIDArr_ =     new 
    int



     [arr_item_len_JobConfig];

    for(int i = 0; i < arr_item_len_JobConfig; ++i)
        initEquipIDArr_[i] =         
    rs->read_int();

    arr_item_len_JobConfig = rs->read_short();
    
    int



*     initBagItemIDs_ =     new 
    int



     [arr_item_len_JobConfig];

    for(int i = 0; i < arr_item_len_JobConfig; ++i)
        initBagItemIDs_[i] =         
    rs->read_int();

    arr_item_len_JobConfig = rs->read_short();
    
    std::string



*     initItemIDsInBag_ =     new 
    std::string



     [arr_item_len_JobConfig];

    for(int i = 0; i < arr_item_len_JobConfig; ++i)
        initItemIDsInBag_[i] =         
    rs->read_string();

        
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

    JobConfig* new_obj_JobConfig = new JobConfig(id_, name_, propID_, maleFigureID_, femaleFigureID_, figureType_, maxLevel_, talentIDArr_, infoTxtID_, initEquipIDArr_, initBagItemIDs_, initItemIDsInBag_);

    dic[id_] = new_obj_JobConfig;
    list.push_back(new_obj_JobConfig);
}

void JobConfig::destroy()
{
    for(std::vector<JobConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
