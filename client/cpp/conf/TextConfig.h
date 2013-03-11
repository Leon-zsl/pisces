



#include <map>
#include <vector>
#include <string>

class StreamReader;
class TextConfig
{
public:
    static std::map<int, TextConfig*> dic;
    static std::vector<TextConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    TextConfig(
    int
 id_, 
    std::string
 text_);
    ~TextConfig();

    
    int
     id;
    
    std::string
     text;
};
