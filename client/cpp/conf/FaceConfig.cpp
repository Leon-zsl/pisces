









#include "StreamReader.h"
#include "FaceConfig.h"

using namespace std;

std::map<int, FaceConfig*> FaceConfig::dic;
std::vector<FaceConfig*> FaceConfig::list;

FaceConfig::FaceConfig(
    int
 id_, 
    std::string
 faceURL_)
{
    id = id_;
    faceURL = faceURL_;
}

FaceConfig::~FaceConfig()
{
}
    
void FaceConfig::build()
{
    std::string path = "./data/";
    path += "FaceConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "FaceConfig")
    {
        printf("invalid file flag %s", flag.c_str());
        delete rs;
        return;
    }
        
    int col_cnt = rs->read_short();
    if(col_cnt != 2)
    {
        printf("col cnt invalid %d : %d", col_cnt, 2);
        delete rs;
        return;
    }
            
    int row_cnt = rs->read_int();
    for(int i = 0; i < row_cnt; i++)
        add_item(rs);

    delete rs;
}

void FaceConfig::add_item(StreamReader* rs)
{

    
    int
     id_ =     
    rs->read_int();

    
    std::string
     faceURL_ =     
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

    FaceConfig* new_obj_FaceConfig = new FaceConfig(id_, faceURL_);

    dic[id_] = new_obj_FaceConfig;
    list.push_back(new_obj_FaceConfig);
}

void FaceConfig::destroy()
{
    for(std::vector<FaceConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
