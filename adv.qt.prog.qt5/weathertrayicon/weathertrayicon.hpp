#ifndef WEATHERTRAYICON_HPP
#define WEATHERTRAYICON_HPP
/*
    Copyright (c) 2009-10 Qtrac Ltd. All rights reserved.

    This program or module is free software: you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation, either version 3 of
    the License, or (at your option) any later version. It is provided
    for educational purposes and is distributed in the hope that it will
    be useful, but WITHOUT ANY WARRANTY; without even the implied
    warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See
    the GNU General Public License for more details.
*/

#include <QCache>
#include <QIcon>
#include <QMenu>
#include <QString>
#include <QSystemTrayIcon>
#include <QUrl>


class QDomDocument;
class QNetworkAccessManager;
class QNetworkReply;


class WeatherTrayIcon : public QSystemTrayIcon
{
    Q_OBJECT

public:
    explicit WeatherTrayIcon();

private slots:
    void requestXml();
    void readXml(QNetworkReply *reply);
    void readIcon(QNetworkReply *reply);
    void setAirport(QAction *action);

private:
    void createContextMenu();
    void populateToolTip(QDomDocument *document);
    QString toolTipField(const QString &name,
            const QString &htmlColor, const QString &value,
            bool appendBr=true);
    QString textForTag(const QString &tag, QDomDocument *document);

    QMenu menu;
    QNetworkAccessManager *networkXmlAccess;
    QNetworkAccessManager *networkIconAccess;
    QString airport;
    QCache<QUrl, QIcon> iconCache;
    int retryDelaySec;
};

#endif // WEATHERTRAYICON_HPP
