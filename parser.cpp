#include "parser.h"
#include <tgbot/tgbot.h>
#include <iostream>

namespace Parser {
    void handleProductRequest(const std::string& productName) {
        TgBot::Bot bot("7562667143:AAGdRiTD73H7fYvhA28zvTMDwpK-kHS3fCs");

        bot.getEvents().onCommand("start", [&bot](TgBot::Message::Ptr message) {
            bot.getApi().sendMessage(message->chat->id, "Привет! Отправь мне название товара, и я расскажу о нем.");
        });

        bot.getEvents().onAnyMessage([&bot](TgBot::Message::Ptr message) {
            if (message->text.find("/start") == 0) {
                return;
            }

            std::string productName = message->text;

            bot.getApi().sendMessage(message->chat->id, "Товар для того-то: " + productName);
            bot.getApi().sendMessage(message->chat->id, "В основном такие комментарии: ...");
            bot.getApi().sendMessage(message->chat->id, "Такая динамика цены: ...");
        });

        try {
            std::cout << "Bot username: " << bot.getApi().getMe()->username << "\n";
            TgBot::TgLongPoll longPoll(bot);
            while (true) {
                longPoll.start();
            }
        } catch (TgBot::TgException& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }

    void startBot() {
        handleProductRequest("");
    }
}