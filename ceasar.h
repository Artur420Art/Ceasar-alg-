#include <iostream>
#include <map>



class Ceasar 
{
public:
    Ceasar(std::string&, std::string&, int);
    ~Ceasar();
    void init();
    void fetch(std::string str);
    std::string m_decode(std::string& str, const size_t pos);
    std::string m_encode(std::string& str, const size_t pos);
private:
    using ptr = std::string(Ceasar::*) (std::string& , const size_t );
private:

    enum commands {DECODE, ENCODE};
    enum range {A = 65, Z = 90, a = 97, z = 122,};
    std::map<std::string, commands> m_comm_f;
    std::map <commands, ptr> m_func;
};
