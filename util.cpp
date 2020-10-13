#include "util.h"
#include <QHostInfo>
#include <QNetworkInterface>

util::util()
{
    util::getWifiIP();{

        QString ipAddress;
        QNetworkInterface wifi;
        // Get WiFi interface
         QList<QNetworkInterface> interfceList = QNetworkInterface::allInterfaces();
         for (int i = 0; i < interfceList.size(); ++i)
         {

             if (interfceList.at(i).name().contains("wireless") && interfceList.at(0).isValid() && interfceList.at(i).IsUp)
             {
                 //qDebug() << "Interfaces:" << i << interfceList.at(i).name() << " / " << interfceList.at(i).humanReadableName();
                 wifi = interfceList.at(i);
                break;
             }

         }

        QList<QHostAddress> ipAddressesList = wifi.allAddresses();
        // use the first non-localhost IPv4 address
        for (int i = 0; i < ipAddressesList.size(); ++i) {
            if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
                ipAddressesList.at(i).toIPv4Address() ) {
                ipAddress = ipAddressesList.at(i).toString();
                //qDebug() << "Using following IP Address:" << ipAddress;
                break;
            }
        }
        //qDebug() << "getBroadWiFiAddress" << ipAddress;
        return ipAddress;
    }
}