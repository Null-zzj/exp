#include <iostream>
#include <sqlite3.h>
#include <string>
#include <vector>

#define HASHSIZE 100000000000
class login
{
    bool signin();
    bool signup();
};

class sqlor
{
    std::string DB = "user.db";
    sqlite3 *db;

    sqlor()
    {

        try
        {
            int ret = sqlite3_open(DB.c_str(), &db);
            if (ret != SQLITE_OK)
            {
                throw sqlite3_errmsg(db);
            }
        }
        catch (const char *msg)
        {
            std::cerr << "Error opening database: " << msg << std::endl;
            exit(-1);
        }
    }

public:
    std::vector<std::string> sql_exec(std::string sql);
  


};

class processor
{
    std::string id;
    std::string name;
    std::string passwd;
    std::string dir;
    login log;
    unsigned long BKDRHash(const char *str);
    void calculation_Directory();

  public:
};
