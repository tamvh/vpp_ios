#include <QtGui/QGuiApplication>

#include "gDataBase.h"
#include <QDebug>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QStandardPaths>
#include <QDir>

gDataBase::gDataBase()
{
    m_profile_table_name = "default profile";
}

void gDataBase::database_init()
{
    QString  tmpString = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QFileInfo checkfile(QString("%1/%2").arg(tmpString).arg("userVpp.sqlite"));
    m_profile_database = QSqlDatabase::addDatabase("QSQLITE");
    m_profile_database.setDatabaseName(tmpString + "/userVpp.sqlite");
    qDebug()<< "checkfile" << checkfile.absoluteFilePath();
    qDebug()<< "database init";
    if(checkfile.exists()){
        qDebug()<< "[+] Database file is exist";
        if(m_profile_database.open()){
            qDebug() << "[+] Connected to Database file :)";
        } else {
            qDebug() << "[-] Database file doesn't exist!";
        }
    }
    else  {
        qDebug()<<"[-]  file doesn't exist!";
        if (!QDir().exists()) {
            QDir().mkdir(tmpString);;
        }
    }
}

void gDataBase::open_database()
{
    qDebug()<<"void open database";
    if(!m_profile_database.open()){
        qDebug("No Connection to db :(");
    }
    else{
        get_profile_list();
        qDebug() << "openfile ok :))";

    }
}

bool gDataBase::params_table_init(QString _table_name)
{
//    open_database();
    QSqlQuery m_query(m_profile_database);
    m_profile_table_name = replace_space_in_profile_name(_table_name); // replace " " by _ if the name has any " "
    if(m_query.exec("CREATE TABLE IF NOT EXISTS " +  m_profile_table_name +
                 " (id INTEGER PRIMARY KEY, param_name TEXT, param_pass TEXT)"))
        return true;
    else return false;
}

void gDataBase::drop_table(QString _table_name)
{
    QSqlQuery m_query(m_profile_database);
    m_profile_table_name = replace_space_in_profile_name(_table_name); // replace " " by _ if the name has any " "
    m_query.exec("DROP TABLE IF EXISTS " +  m_profile_table_name);

}

void gDataBase::save_one_parameter(int param_id, QString param_name, QString param_pass)
{
    QSqlQuery m_query(m_profile_database);
    // Insert values of a customer
    m_query.prepare("INSERT OR REPLACE INTO " + m_profile_table_name +
                    "(id, param_name, param_pass)"
                    " VALUES(?,?,?)");

    m_query.addBindValue(param_id); // add value
    m_query.addBindValue(param_name);
    m_query.addBindValue(param_pass);
    m_query.exec(); // run sql script

}

QString gDataBase::get_name_parameter(int id)
{
    QString result = "";
    QSqlQuery m_query(m_profile_database);
    m_query.prepare("SELECT param_name FROM " + m_profile_table_name + " WHERE id=?;");
//    m_query.addBindValue(param_class);
    m_query.addBindValue(id);

    if(m_query.exec()){
        while(m_query.next()){
            result =  m_query.value(m_query.record().indexOf("param_name")).toString();
        }
    }
    else result =  "";
    return result;
}

QString gDataBase::get_pass_parameter(int id)
{
    QString result = "";
    QSqlQuery m_query(m_profile_database);
    m_query.prepare("SELECT param_pass FROM " + m_profile_table_name + " WHERE id=?;");
//    m_query.addBindValue(param_class);
    m_query.addBindValue(id);

    if(m_query.exec()){
        while(m_query.next()){
            result =  m_query.value(m_query.record().indexOf("param_pass")).toString();
        }
    }
    else result =  "";
    return result;
}


void gDataBase::get_profile_list()
{
    int record_count = 0;
    QSqlQuery m_query(m_profile_database);
    m_profile_list.clear();
    if(m_query.exec("SELECT name, sql FROM sqlite_master WHERE type='table'")){
        while (m_query.next()){
            record_count++;
            m_profile_list.insert(record_count, m_query.value("name").toString() );
        }
    }
}


QString gDataBase::replace_space_in_profile_name(QString _profile_name)
{
   return _profile_name.replace(" ","_");
}

