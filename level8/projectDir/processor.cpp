#include "processor.h"
#include <cstdio>
#include <string>

// BKDR Hash Function
unsigned long processor::BKDRHash(const char *str) 
{
    unsigned long seed = 131313; // 31 131 1313 13131 131313 etc..
    unsigned long hash = 0;
    
    while (*str)
    {
        hash = hash * seed + (*str++);
    }
  
    return hash % HASHSIZE;
}

void processor::calculation_Directory()
{
    dir = std::to_string(BKDRHash(this->id.c_str()));
}

bool login::signin()
{

}



bool login::signup()
{

}

std::vector<std::string> sqlor::sql_exec(std::string sql)
{
    sqlite3_get_table(this->db, sql.c_str(), char ***pazResult, int *pnRow, int *pnColumn, char **pzErrmsg)



}