//
// Created by romain on 01/06/18.
//

#include <iostream>
#include "HelloConnectMessage.h"
#include "GameServerController.h"
#include "GameServer.h"

void GameServerController::defineMessageHandlers(handlers_t &handlers) {
    handlers[MapDataMessage::PROTOCOL_ID] = handler(*this, &GameServerController::onMapDataMessage);
}

void GameServerController::onConnect(GameClient *client) {
    client->send(HelloConnectMessage());
}

void GameServerController::onDisconnect(GameClient *client) {

}

void GameServerController::onMapDataMessage(GameClient *client, MapDataMessage *msg) {
    client->kick();
}