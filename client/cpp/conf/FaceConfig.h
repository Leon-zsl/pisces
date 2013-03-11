



#include <map>
#include <vector>
#include <string>

class StreamReader;
class FaceConfig
{
public:
    static std::map<int, FaceConfig*> dic;
    static std::vector<FaceConfig*> list;

    static void build();
    static void destroy();
    static void add_item(StreamReader* rs);
    
public:
    FaceConfig(
    int
 id_, 
    std::string
 faceURL_);
    ~FaceConfig();

    
    int
     id;
    
    std::string
     faceURL;
};
