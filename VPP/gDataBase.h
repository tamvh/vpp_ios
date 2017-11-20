#ifndef GDATABASE_H
#define GDATABASE_H

#include <QFileInfo>
#include <QSqlDatabase>
//#include <QSql>
#include <QStringList>
#define DB_STORE_PATH  "profiles/userVpp.sqlite"
//#define DB_SETTINGS    "settings/settings_db.sqlite"

class gDataBase
{
public:
    gDataBase();
    void database_init();
    void open_database();   // create connection with database file
    bool params_table_init(QString _table_name);
    void drop_table(QString _table_name);  // delete table from database
    void save_one_parameter(int param_id,  QString param_name, QString param_pass);
    QString get_name_parameter(int id);
    QString get_pass_parameter(int id);

    void get_profile_list();
/*
    void setting_table_init();
    void save_one_setting(int id, QString setting_name, QString setting_value);
    void get_one_setting(QString setting_name, QString setting_value);
*/
    QList<QString> m_profile_list;

private:
    QString replace_space_in_profile_name(QString _profile_name); // check and replace any space with _
private:
    QSqlDatabase m_profile_database;
    QString m_profile_table_name;


};

#endif // GDATABASE_H
