#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>
#include <map>
#include <string>
#include <iostream>

namespace asio = boost::asio;
using ip = asio::ip;
using tcp = ip::tcp;

class ChatSession : public std::enable_shared_from_this<ChatSession> {
public:
    ChatSession(tcp::socket socket) : socket_(std::move(socket)) {}

    void start() {
        read();
    }

private:
    void read() {
        auto self = shared_from_this();
        socket_.async_read_some(asio::buffer(read_msg_),
            [this, self](std::error_code ec, std::size_t length) {
                if (!ec) {
                    std::string message(read_msg_.data(), length);
                    chat_room_.deliver(message, shared_from_this());
                    read();
                } else {
                    chat_room_.leave(shared_from_this());
                }
            });
    }

    void write(const std::string& message) {
        auto self = shared_from_this();
        asio::async_write(socket_,
            asio::buffer(message),
            [this, self](std::error_code ec, std::size_t /*length*/) {
                if (ec) {
                    chat_room_.leave(shared_from_this());
                }
            });
    }

    void on_write(const std::error_code& /*ec*/, size_t /*length*/) {}

    tcp::socket socket_;
    std::string read_msg_;
    ChatRoom& chat_room_;
};

class ChatRoom {
public:
    void join(ChatSession::pointer new_session) {
        sessions_[new_session->id_] = new_session;
        new_session->chat_room_ = *this;
    }

    void deliver(const std::string& message, ChatSession::pointer except) {
        for (auto& session : sessions_) {
            if (session.second != except) {
                session.second->write(message);
            }
        }
    }

    void leave(ChatSession::pointer session) {
        sessions_.erase(session->id_);
    }

    int id_generator = 0;
    std::map<int, ChatSession::pointer> sessions_;
};

class ChatServer {
public:
    ChatServer(asio::io_context& io_context, unsigned short port)
        : acceptor_(io_context, tcp::endpoint(tcp::v4(), port)),
          io_context_(io_context),
          chat_room_(ChatRoom()) {}

    void start() {
        do_accept();
        io_context_.run();
    }

private:
    void do_accept() {
        acceptor_.async_accept(
            [this](std::error_code ec, tcp::socket socket) {
                if (!ec) {
                    auto session = std::make_shared<ChatSession>(std::move(socket));
                    session->id_ = chat_room_.id_generator++;
                    chat_room_.join(session);
                    session->start();
                }
                do_accept();
            });
    }

    tcp::acceptor acceptor_;
    asio::io_context& io_context_;
    ChatRoom chat_room_;
};

int main() {
    try {
        asio::io_context io_context;
        ChatServer server(io_context, 12345);
        server.start();
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}-