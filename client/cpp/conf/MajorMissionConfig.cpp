











#include "StreamReader.h"
#include "MajorMissionConfig.h"

using namespace std;

MajorMissionConfig::MajorMissionConfig(
    int
 id_)
{
    id = id_;
}

MajorMissionConfig::~MajorMissionConfig()
{
}
    
void MajorMissionConfig::build()
{
    std::string path = "./data/";
    path += "MajorMissionConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    int filelen = rs->read_int();
    string flag = rs->read_string();
    if(flag != "MajorMissionConfig")
    {
        printf("invalid file flag %s", flag.c_str());
        delete rs;
        return;
    }
        
    int col_cnt = rs->read_short();
    if(col_cnt != 1)
    {
        printf("col cnt invalid %d : %d", col_cnt, 1);
        delete rs;
        return;
    }
            
    int row_cnt = rs->read_int();
    for(int i = 0; i < row_cnt; i++)
        add_item(rs);

    delete rs;
}

void MajorMissionConfig::add_item(StreamReader* rs)
{

    
    int
     id_ =     
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

    MajorMissionConfig* new_obj_MajorMissionConfig = new MajorMissionConfig(id_);

    dic[(id_] = new_obj_MajorMissionConfig;
    list.push_back(new_obj_MajorMissionConfig);
}

void MajorMissionConfig::destroy()
{
    for(std::vector<MajorMissionConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
