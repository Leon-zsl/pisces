



#include <map>
#include <vector>
#include <string>

class StreamReader;
class PropertyConfig
{
public:
    static std::map<int, PropertyConfig*> dic;
    static std::vector<PropertyConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    PropertyConfig(
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
 cCRE_);
    ~PropertyConfig();

    
    int
     id;
    
    std::string
     desc;
    
    int
     baseHP;
    
    int
     baseMP;
    
    int
     baseEP;
    
    int
     baseAP;
    
    float
     aReMP;
    
    float
     bReMP;
    
    float
     aSTR;
    
    float
     bSTR;
    
    float
     cSTR;
    
    float
     aAGI;
    
    float
     bAGI;
    
    float
     cAGI;
    
    float
     aINT;
    
    float
     bINT;
    
    float
     cINT;
    
    float
     aCON;
    
    float
     bCON;
    
    float
     cCON;
    
    float
     aMND;
    
    float
     bMND;
    
    float
     cMND;
    
    float
     aCRE;
    
    float
     bCRE;
    
    float
     cCRE;
};
