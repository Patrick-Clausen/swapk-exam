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

namespace restbuilder::socket {
    
    class SocketManager {
    public:
        SocketManager(boost::asio::ip::tcp::endpoint endpoint, std::function<std::string(std::string)> &callHandler);

        ~SocketManager();

    private:
        std::function<std::string(std::string)> _callHandler;

        void newConnection(std::shared_ptr<boost::asio::ip::tcp::socket>);

        void connectionCompleted(std::shared_ptr<SocketConnection>);

        bool transferConnection();

        bool cleanupConnection();

        SocketListener _listener;

        std::vector<std::shared_ptr<SocketConnection> > _connections;
        std::mutex _connectionsMutex;

        void threadFunction();

        std::thread _thread;
        bool _keepGoing = true;

        std::queue<std::shared_ptr<boost::asio::ip::tcp::socket> > _incomingConnections;
        std::mutex _incomingConnectionsMutex;

        std::queue<std::shared_ptr<SocketConnection> > _completedConnections;
        std::mutex _completedConnectionsMutex;
    };

}

#endif //SWAPK_EXAM_SOCKETMANAGER_H
