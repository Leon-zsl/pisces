









#include "StreamReader.h"
#include "TextConfig.h"

using namespace std;

std::map<int, TextConfig*> TextConfig::dic;
std::vector<TextConfig*> TextConfig::list;

TextConfig::TextConfig(
    int
 id_, 
    std::string
 text_)
{
    id = id_;
    text = text_;
}

TextConfig::~TextConfig()
{
}
    
void TextConfig::build()
{
    //std::string path = "./data/";
    //path += "TextConfig.bytes";
    std::string path = "TextConfig.bytes";
    StreamReader* rs = new StreamReader(path);
    /*int filelen = */rs->read_int();
    string flag = rs->read_string();
    if(flag != "TextConfig")
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

void TextConfig::add_item(StreamReader* rs)
{

    
    int
     id_ =     
    rs->read_int();

    
    std::string
     text_ =     
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

    TextConfig* new_obj_TextConfig = new TextConfig(id_, text_);

    dic[id_] = new_obj_TextConfig;
    list.push_back(new_obj_TextConfig);
}

void TextConfig::destroy()
{
    for(std::vector<TextConfig*>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        delete *itr;
    }

    list.clear();
    dic.clear();
}
