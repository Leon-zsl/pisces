









#include "StreamReader.h"
#include "PropertyCoeConfig.h"

using namespace std;

std::map<int, PropertyCoeConfig*> PropertyCoeConfig::dic;
std::vector<PropertyCoeConfig*> PropertyCoeConfig::list;

PropertyCoeConfig::PropertyCoeConfig(
    int
 id_, 
    float
 value_, 
    std::string
 desc_)
{
    id = id_;
    value = value_;
    desc = desc_;
}

PropertyCoeConfig::~PropertyCoeConfig()
{
}
    
void PropertyCoeConfig::build()
{
    std::string path = "./data/";
    path += "PropertyCoeConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "PropertyCoeConfig")
    {
        printf("invalid file flag %s", flag.c_str());
        delete rs;
        return;
    }
        
    int col_cnt = rs->read_short();
    if(col_cnt != 3)
    {
        printf("col cnt invalid %d : %d", col_cnt, 3);
        delete rs;
        return;
    }
            
    int row_cnt = rs->read_int();
    for(int i = 0; i < row_cnt; i++)
        add_item(rs);

    delete rs;
}

void PropertyCoeConfig::add_item(StreamReader* rs)
{

    
    int
     id_ =     
    rs->read_int();

    
    float
     value_ =     
    rs->read_float();

    
    std::string
     desc_ =     
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

    PropertyCoeConfig* new_obj_PropertyCoeConfig = new PropertyCoeConfig(id_, value_, desc_);

    dic[id_] = new_obj_PropertyCoeConfig;
    list.push_back(new_obj_PropertyCoeConfig);
}

void PropertyCoeConfig::destroy()
{
    for(std::vector<PropertyCoeConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
