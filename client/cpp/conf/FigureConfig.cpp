









#include "StreamReader.h"
#include "FigureConfig.h"

using namespace std;

std::map<int, FigureConfig*> FigureConfig::dic;
std::vector<FigureConfig*> FigureConfig::list;

FigureConfig::FigureConfig(
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



* avatarNameArr_)
{
    id = id_;
    length = length_;
    width = width_;
    height = height_;
    modelUrl = modelUrl_;
    avatarIDArr = avatarIDArr_;
    avatarNameArr = avatarNameArr_;
}

FigureConfig::~FigureConfig()
{
    delete[] avatarIDArr;
    delete[] avatarNameArr;
}
    
void FigureConfig::build()
{
    //std::string path = "./data/";
    //path += "FigureConfig.bytes";
    std::string path = "FigureConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "FigureConfig")
    {
        printf("invalid file flag %s", flag.c_str());
        delete rs;
        return;
    }
        
    int col_cnt = rs->read_short();
    if(col_cnt != 7)
    {
        printf("col cnt invalid %d : %d", col_cnt, 7);
        delete rs;
        return;
    }
            
    int row_cnt = rs->read_int();
    for(int i = 0; i < row_cnt; i++)
        add_item(rs);

    delete rs;
}

void FigureConfig::add_item(StreamReader* rs)
{
    int arr_item_len_FigureConfig;

    
    int
     id_ =     
    rs->read_int();

    
    float
     length_ =     
    rs->read_float();

    
    float
     width_ =     
    rs->read_float();

    
    float
     height_ =     
    rs->read_float();

    
    std::string
     modelUrl_ =     
    rs->read_string();

    arr_item_len_FigureConfig = rs->read_short();
    
    int



*     avatarIDArr_ =     new 
    int



     [arr_item_len_FigureConfig];

    for(int i = 0; i < arr_item_len_FigureConfig; ++i)
        avatarIDArr_[i] =         
    rs->read_int();

    arr_item_len_FigureConfig = rs->read_short();
    
    std::string



*     avatarNameArr_ =     new 
    std::string



     [arr_item_len_FigureConfig];

    for(int i = 0; i < arr_item_len_FigureConfig; ++i)
        avatarNameArr_[i] =         
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

    FigureConfig* new_obj_FigureConfig = new FigureConfig(id_, length_, width_, height_, modelUrl_, avatarIDArr_, avatarNameArr_);

    dic[id_] = new_obj_FigureConfig;
    list.push_back(new_obj_FigureConfig);
}

void FigureConfig::destroy()
{
    for(std::vector<FigureConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
