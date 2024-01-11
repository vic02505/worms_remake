#pragma once

#include <exception>
#include <string>

class UnExpectedException : public std::exception {
 private:
    std::string m_Msg;
 public:
    explicit UnExpectedException(const std::string& msg) : m_Msg(msg) {}
    const char* what() const noexcept override {
        return m_Msg.c_str();
    }
};
