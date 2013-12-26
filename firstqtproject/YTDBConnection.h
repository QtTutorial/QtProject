#ifndef YTDBCONNECTION_H
#define YTDBCONNECTION_H
#include <QtSql/QtSql>
#include <QTableView>

class YTDBConnection
{
public:
    YTDBConnection();   //constructor
public:
    bool OpenDB();  //Connect to my database "Taiwan"
    void CloseDB(); //Close database
    bool getData(QStringList &d_list); //get a list of the Taiwan city names from database
    bool getData(QTableView *srcTable,QString currentText);
private:
    QSqlDatabase db;
};

#endif // YTDBCONNECTION_H
