//
// Created by romain on 01/06/18.
//

#ifndef CPP_INDIE_STUDIO_GAMECONTROLLER_H
#define CPP_INDIE_STUDIO_GAMECONTROLLER_H


#include "ANetworkController.h"
#include "RequestLobbyMessage.h"
#include "RequestStartGameMessage.h"
#include "InputMessage.h"

class GameServer;
class GameClient;

class GameServerController: public ANetworkController {
public:

    explicit GameServerController(GameServer *server) : ANetworkController(), _server(server) {}

    void defineMessageHandlers(handlers_t &handlers) override;
    void onConnect(GameClient *client);
    void onDisconnect(GameClient *client);

    void onStartRequested(GameClient *client, RequestStartGameMessage *msg);
    void onJoinAsked(GameClient *client, RequestLobbyMessage *msg);
    void onInputReceived(GameClient *client, InputMessage *msg);

private:
    GameServer *_server;
};


#endif //CPP_INDIE_STUDIO_GAMECONTROLLER_H