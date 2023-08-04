#include <iostream>
#include <map>
#include <string.h>
using namespace std;

int main(int argc, char *argv[])
{
    map<string, string> map_id_name;
    map_id_name.insert({"中国", "china"});
    map_id_name.insert({"美国", "America"});
    map_id_name.insert({"英国", "England"});
    map_id_name.insert({"德国", "Germany"});
    map_id_name.insert({"日本", "Japan"});
    map_id_name.insert({"法国", "France"});
    map_id_name.insert({"俄罗斯", "Russia"});
    map_id_name.insert({"印度", "India"});
    map_id_name.insert({"巴西", "Brazil"});
    map_id_name.insert({"意大利", "Italy"});
    map_id_name.insert({"加拿大", "Canada"});
    map_id_name.insert({"澳大利亚", "Australia"});
    map_id_name.insert({"南非", "South Africa"});
    map_id_name.insert({"墨西哥", "Mexico"});
    char buf[16] = {0};
    while(1)
    {
        cin >> buf;
        if(strcmp("exit", buf) == 0) 
        {
            break;
        }
        auto itr = map_id_name.find(buf);
        if( itr == map_id_name.end())
        {
            cout << "没有这个国家" << endl;
        }else{
            cout << itr->second << endl;
        }

    }

    return 0;
}