

/*********************************************************************

Copyright (C) 2015 Jeffrey O. Pfaffmann

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

*********************************************************************/

#include "dbhivetable.h"

// Default constructor.
dbhivetable::dbhivetable() {

}

// Constructor for identying the dbtool and table name.
dbhivetable::dbhivetable(Tool     *db,
                     std::string name   ) :
    DBTable (db, name)
{

    // Load SQL specific to child class.
    store_add_row_sql();
    store_create_sql();

    // must build table sepparately so new
    // sql can be properly registered
    build_table();
}

dbhivetable::~dbhivetable() {

}

void dbhivetable::store_add_row_sql() {

    sql_template =  "SELECT name ";
    sql_template += "FROM   sqlite_master ";
    sql_template += "WHERE";
    sql_template += "    type = \"table\"";
    sql_template += ";";

}


void dbhivetable::store_create_sql() {

    //std::cerr << "calling store_create_sql from DBTableEx\n";

    sql_create =  "CREATE TABLE ";
    sql_create += table_name;
    sql_create += " ( ";
    sql_create += " id INT PRIMARY KEY NOT NULL, ";
    sql_create += "  f_name TEXT NOT NULL, ";
    sql_create += "  l_name TEXT NOT NULL, ";
    sql_create += "  game TEXT NOT NULL,";
    sql_create += "  score TEXT  NOT NULL ";
    sql_create += " );";

}

bool dbhivetable::add_row_p(int id, std::string f_name,std::string l_name,
                             std::string game, std::string   score) {
    int   retCode = 0;
    char *zErrMsg = 0;

    char tempval[128];

    sql_add_row  = "INSERT INTO ";
    sql_add_row += table_name;
    sql_add_row += " ( id, f_name, l_name, game, score) ";
    sql_add_row += "VALUES (";

    sprintf(tempval, "%d", id);
    sql_add_row += tempval;
    sql_add_row += ", ";

    sql_add_row += "\"";
    sql_add_row += std::string(f_name);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(l_name);
    sql_add_row += "\", ";

    sql_add_row += "\"";
    sql_add_row += std::string(game);
    sql_add_row += "\", ";

    sql_add_row += std::string(score);
    sql_add_row += " ";

    sql_add_row += " );";

    std::cout << sql_add_row << std::endl;

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_add_row.c_str(),
                           cb_add_row,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}

bool dbhivetable::update_row_p(int id, std::string game, std::string   score){
        int   retCode = 0;
        char *zErrMsg = 0;

        char tempval[128];
        sql_update_row  = "UPDATE ";
        sql_update_row += table_name;
        sql_update_row += " SET game = ";

        sql_update_row += "\"";
        sql_update_row += std::string(game);
        sql_update_row += "\" ";

        sql_update_row += "WHERE id = ";


        sprintf(tempval, "%d", id);
        sql_update_row += tempval;

        std::cout << sql_update_row << std::endl;

        retCode = sqlite3_exec(curr_db->db_ref(),
                               sql_update_row.c_str(),
                               cb_update_row,
                               this,
                               &zErrMsg          );

        if( retCode != SQLITE_OK ){

            std::cerr << table_name
                      << " template ::"
                      << std::endl
                      << "SQL error: "
                      << zErrMsg;

            sqlite3_free(zErrMsg);
        }
        sql_update_row  = "UPDATE ";
        sql_update_row += table_name;
        sql_update_row += " SET score = ";

        sql_update_row += std::string(score);

        sql_update_row += " WHERE id = ";


        sprintf(tempval, "%d", id);
        sql_update_row += tempval;

        std::cout << sql_update_row << std::endl;

        retCode = sqlite3_exec(curr_db->db_ref(),
                               sql_update_row.c_str(),
                               cb_update_row,
                               this,
                               &zErrMsg          );

        if( retCode != SQLITE_OK ){

            std::cerr << table_name
                      << " template ::"
                      << std::endl
                      << "SQL error: "
                      << zErrMsg;

            sqlite3_free(zErrMsg);
        }
        return retCode;
}

char** dbhivetable::select_row_p(){
        int   retCode = 0;
        char *zErrMsg = 0;

        char **tempval= 0;
        sql_select  = "SELECT * FROM ";
        sql_select += table_name;
        sql_select += ";";
        std::cout << sql_select << std::endl;
        if(size()<1)
            return nullptr;
        retCode = sqlite3_get_table(curr_db->db_ref(),sql_select.c_str(),
                                    &tempval,&row_cnt,&column,&zErrMsg);
        if( retCode != SQLITE_OK ){

            std::cerr << table_name
                      << " template ::"
                      << std::endl
                      << "SQL error: "
                      << zErrMsg;

            sqlite3_free_table(tempval);
        }

        return tempval;
}

bool dbhivetable::select_all() {

    int   retCode = 0;
    char *zErrMsg = 0;

    sql_select_all  = "SELECT * FROM ";
    sql_select_all += table_name;
    sql_select_all += ";";

    retCode = sqlite3_exec(curr_db->db_ref(),
                           sql_select_all.c_str(),
                           cb_select_all,
                           this,
                           &zErrMsg          );

    if( retCode != SQLITE_OK ){

        std::cerr << table_name
                  << " template ::"
                  << std::endl
                  << "SQL error: "
                  << zErrMsg;

        sqlite3_free(zErrMsg);
    }

    return retCode;
}


int cb_add_row(void  *data,
               int    argc,
               char **argv,
               char **azColName)
{



    std::cerr << "cb_add_row being called\n";

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    int i;

    dbhivetable *obj = (dbhivetable *) data;

    std::cout << "------------------------------\n";
    std::cout << obj->get_name()
              << std::endl;

    for(i = 0; i < argc; i++){
        std::cout << azColName[i]
                  << " = "
                  <<  (argv[i] ? argv[i] : "NULL")
                  << std::endl;
    }

    return 0;
}

int cb_update_row(void  *data,
               int    argc,
               char **argv,
               char **azColName)
{



    std::cerr << "cb_update_row being called\n";

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    int i;

    dbhivetable *obj = (dbhivetable *) data;

    std::cout << "------------------------------\n";
    std::cout << obj->get_name()
              << std::endl;

    for(i = 0; i < argc; i++){
        std::cout << azColName[i]
                  << " = "
                  <<  (argv[i] ? argv[i] : "NULL")
                  << std::endl;
    }

    return 0;
}

int cb_select_all(void  *data,
                  int    argc,
                  char **argv,
                  char **azColName)
{



    std::cerr << "cb_select_all being called\n";

    if(argc < 1) {
        std::cerr << "No data presented to callback "
                  << "argc = " << argc
                  << std::endl;
    }

    int i;

    dbhivetable *obj = (dbhivetable *) data;

    std::cout << "------------------------------\n";
    std::cout << obj->get_name()
              << std::endl;

    for(i = 0; i < argc; i++){
        std::cout << azColName[i]
                  << " = "
                  <<  (argv[i] ? std::string(argv[i]) : "NULL")
                  << std::endl;
    }

    return 0;
}
