#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <iostream>
#include <memory>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QUrl>
#include <QObject>
#include <QString>
#include <QDebug>
#include <QLoggingCategory>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

enum HttpRequestMethod {
    POST,
    GET,
    DELETE
};

class HttpClient : public QObject
{
    Q_OBJECT
public:
    HttpClient(QObject* parent = 0);
    Q_INVOKABLE void login_to_server(QString _name, QString _pass);
    Q_INVOKABLE void change_password(QString _user, QString _old, QString _new);
    Q_INVOKABLE void send_request_open(QString _name, QString _mac);
    Q_INVOKABLE void get_all_device_cloud();

    virtual ~HttpClient();
public:
    void initialize(const QString& host, int port);
    void setRequestMethod(HttpRequestMethod requestMethod);
    void addPostItem(const QString &key, const QString &value);
    void sendRequest(const QString& api, QByteArray m_postData);
    void sendRequestAddevice(const QString& api, QByteArray m_postData);

    QNetworkReply* replyData();
private:
    QByteArray _m_postData;
    QNetworkReply *_repData;
    QNetworkAccessManager mgr;
    QNetworkRequest *_request;
    HttpRequestMethod _method;
    QString _host;
    int _port;
    QByteArray m_data;
    QByteArray tokenlogin;
    QString current_api;
signals:
    void create_group_from_cloud(QString _group);
    void creat_device_from_cloud(QString _name, QString _group, QString _address,int _id, int _type);
    void update_device_id_from_cloud(QString _group, QString _name,int _id);
    void login_status(int _status);
    void access_status(int _status);
    void changePass_status(int _status);
    void get_msg_open(QString _msg);
private slots:
    void read_data_request(QNetworkReply *reply);
    void process_json(QString _data);
};

#endif // HTTPCLIENT_H
