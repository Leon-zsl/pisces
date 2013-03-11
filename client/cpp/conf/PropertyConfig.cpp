









#include "StreamReader.h"
#include "PropertyConfig.h"

using namespace std;

std::map<int, PropertyConfig*> PropertyConfig::dic;
std::vector<PropertyConfig*> PropertyConfig::list;

PropertyConfig::PropertyConfig(
    int
 id_, 
    std::string
 desc_, 
    int
 baseHP_, 
    int
 baseMP_, 
    int
 baseEP_, 
    int
 baseAP_, 
    float
 aReMP_, 
    float
 bReMP_, 
    float
 aSTR_, 
    float
 bSTR_, 
    float
 cSTR_, 
    float
 aAGI_, 
    float
 bAGI_, 
    float
 cAGI_, 
    float
 aINT_, 
    float
 bINT_, 
    float
 cINT_, 
    float
 aCON_, 
    float
 bCON_, 
    float
 cCON_, 
    float
 aMND_, 
    float
 bMND_, 
    float
 cMND_, 
    float
 aCRE_, 
    float
 bCRE_, 
    float
 cCRE_)
{
    id = id_;
    desc = desc_;
    baseHP = baseHP_;
    baseMP = baseMP_;
    baseEP = baseEP_;
    baseAP = baseAP_;
    aReMP = aReMP_;
    bReMP = bReMP_;
    aSTR = aSTR_;
    bSTR = bSTR_;
    cSTR = cSTR_;
    aAGI = aAGI_;
    bAGI = bAGI_;
    cAGI = cAGI_;
    aINT = aINT_;
    bINT = bINT_;
    cINT = cINT_;
    aCON = aCON_;
    bCON = bCON_;
    cCON = cCON_;
    aMND = aMND_;
    bMND = bMND_;
    cMND = cMND_;
    aCRE = aCRE_;
    bCRE = bCRE_;
    cCRE = cCRE_;
}

PropertyConfig::~PropertyConfig()
{
}
    
void PropertyConfig::build()
{
    std::string path = "./data/";
    path += "PropertyConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "PropertyConfig")
    {
        printf("invalid file flag %s", flag.c_str());
        delete rs;
        return;
    }
        
    int col_cnt = rs->read_short();
    if(col_cnt != 26)
    {
        printf("col cnt invalid %d : %d", col_cnt, 26);
        delete rs;
        return;
    }
            
    int row_cnt = rs->read_int();
    for(int i = 0; i < row_cnt; i++)
        add_item(rs);

    delete rs;
}

void PropertyConfig::add_item(StreamReader* rs)
{

    
    int
     id_ =     
    rs->read_int();

    
    std::string
     desc_ =     
    rs->read_string();

    
    int
     baseHP_ =     
    rs->read_int();

    
    int
     baseMP_ =     
    rs->read_int();

    
    int
     baseEP_ =     
    rs->read_int();

    
    int
     baseAP_ =     
    rs->read_int();

    
    float
     aReMP_ =     
    rs->read_float();

    
    float
     bReMP_ =     
    rs->read_float();

    
    float
     aSTR_ =     
    rs->read_float();

    
    float
     bSTR_ =     
    rs->read_float();

    
    float
     cSTR_ =     
    rs->read_float();

    
    float
     aAGI_ =     
    rs->read_float();

    
    float
     bAGI_ =     
    rs->read_float();

    
    float
     cAGI_ =     
    rs->read_float();

    
    float
     aINT_ =     
    rs->read_float();

    
    float
     bINT_ =     
    rs->read_float();

    
    float
     cINT_ =     
    rs->read_float();

    
    float
     aCON_ =     
    rs->read_float();

    
    float
     bCON_ =     
    rs->read_float();

    
    float
     cCON_ =     
    rs->read_float();

    
    float
     aMND_ =     
    rs->read_float();

    
    float
     bMND_ =     
    rs->read_float();

    
    float
     cMND_ =     
    rs->read_float();

    
    float
     aCRE_ =     
    rs->read_float();

    
    float
     bCRE_ =     
    rs->read_float();

    
    float
     cCRE_ =     
    rs->read_float();

        
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

    PropertyConfig* new_obj_PropertyConfig = new PropertyConfig(id_, desc_, baseHP_, baseMP_, baseEP_, baseAP_, aReMP_, bReMP_, aSTR_, bSTR_, cSTR_, aAGI_, bAGI_, cAGI_, aINT_, bINT_, cINT_, aCON_, bCON_, cCON_, aMND_, bMND_, cMND_, aCRE_, bCRE_, cCRE_);

    dic[id_] = new_obj_PropertyConfig;
    list.push_back(new_obj_PropertyConfig);
}

void PropertyConfig::destroy()
{
    for(std::vector<PropertyConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
