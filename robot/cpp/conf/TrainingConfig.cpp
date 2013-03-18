









#include "StreamReader.h"
#include "TrainingConfig.h"

using namespace std;

std::map<int, TrainingConfig*> TrainingConfig::dic;
std::vector<TrainingConfig*> TrainingConfig::list;

TrainingConfig::TrainingConfig(
    int
 id_, 
    int
 preID_, 
    std::string
 bgResName_, 
    float
 bgOffsetX_, 
    float
 bgOffsetY_, 
    std::string



* texResName_,
    float
 texOffsetX_, 
    float
 texOffsetY_, 
    int
 exp_)
{
    id = id_;
    preID = preID_;
    bgResName = bgResName_;
    bgOffsetX = bgOffsetX_;
    bgOffsetY = bgOffsetY_;
    texResName = texResName_;
    texOffsetX = texOffsetX_;
    texOffsetY = texOffsetY_;
    exp = exp_;
}

TrainingConfig::~TrainingConfig()
{
    delete[] texResName;
}
    
void TrainingConfig::build()
{
    //std::string path = "./data/";
    //path += "TrainingConfig.bytes";
    std::string path = "TrainingConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "TrainingConfig")
    {
        printf("invalid file flag %s", flag.c_str());
        delete rs;
        return;
    }
        
    int col_cnt = rs->read_short();
    if(col_cnt != 9)
    {
        printf("col cnt invalid %d : %d", col_cnt, 9);
        delete rs;
        return;
    }
            
    int row_cnt = rs->read_int();
    for(int i = 0; i < row_cnt; i++)
        add_item(rs);

    delete rs;
}

void TrainingConfig::add_item(StreamReader* rs)
{
    int arr_item_len_TrainingConfig;

    
    int
     id_ =     
    rs->read_int();

    
    int
     preID_ =     
    rs->read_int();

    
    std::string
     bgResName_ =     
    rs->read_string();

    
    float
     bgOffsetX_ =     
    rs->read_float();

    
    float
     bgOffsetY_ =     
    rs->read_float();

    arr_item_len_TrainingConfig = rs->read_short();
    
    std::string



*     texResName_ =     new 
    std::string



     [arr_item_len_TrainingConfig];

    for(int i = 0; i < arr_item_len_TrainingConfig; ++i)
        texResName_[i] =         
    rs->read_string();

    
    float
     texOffsetX_ =     
    rs->read_float();

    
    float
     texOffsetY_ =     
    rs->read_float();

    
    int
     exp_ =     
    rs->read_int();

        
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

    TrainingConfig* new_obj_TrainingConfig = new TrainingConfig(id_, preID_, bgResName_, bgOffsetX_, bgOffsetY_, texResName_, texOffsetX_, texOffsetY_, exp_);

    dic[id_] = new_obj_TrainingConfig;
    list.push_back(new_obj_TrainingConfig);
}

void TrainingConfig::destroy()
{
    for(std::vector<TrainingConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
