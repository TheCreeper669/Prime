#ifndef SCP_EXCEPTION_HPP
#define SCP_EXCEPTION_HPP

// C++ libs
#include <exception>
#include <string>

namespace scp {

class Exception: public std::exception {
    public:
        Exception(const std::string& type = "", const std::string& who = "", const std::string& what = "") noexcept;
        virtual ~Exception() noexcept;
        virtual const char* what() const noexcept;
    private:
        std::string m_type;
        std::string m_who;
        std::string m_what;
};

Exception::Exception(const std::string& type, const std::string& who, const std::string& what) noexcept:
    m_type(type),
    m_who(who),
    m_what(what)
{
    //
}

Exception::~Exception() noexcept {
    //
}

const char* Exception::what() const noexcept {
    std::string exception = "Error: ['" + m_who + "'] throw exception ['" + m_type + "'], details: ['" + m_what + "'].";
    return exception.c_str();
}

} // closing namespace scp

#endif /* SCP_EXCEPTION_HPP */
