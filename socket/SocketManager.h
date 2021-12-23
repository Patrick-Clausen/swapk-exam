//
// Created by Patrick Clausen on 19/12/2021.
//

#ifndef SWAPK_EXAM_SOCKETMANAGER_H
#define SWAPK_EXAM_SOCKETMANAGER_H

#include <queue>
#include <vector>
#include <boost/asio.hpp>
#include <boost/signals2.hpp>
#include "SocketListener.h"
#include "SocketConnection.h"

class SocketManager {
public:
    SocketManager(boost::asio::ip::tcp::endpoint endpoint, std::function<std::string(std::string)> callHandler);
    ~SocketManager();
private:
    std::function<std::string(std::string)> _callHandler;
    void newConnection(boost::asio::ip::tcp::socket*);

    void connectionCompleted(SocketConnection*);

    bool transferConnection();
    bool cleanupConnection();

    SocketListener* _listener;

    std::vector<SocketConnection*> _connections;
    std::mutex _connectionsMutex;

    void threadFunction();
    std::thread* _thread;
    bool _keepGoing = true;

    std::queue<boost::asio::ip::tcp::socket*> _incomingConnections;
    std::mutex _incomingConnectionsMutex;

    std::queue<SocketConnection*> _completedConnections;
    std::mutex _completedConnectionsMutex;
};


#endif //SWAPK_EXAM_SOCKETMANAGER_H
