#ifndef BASEBALLPLAYEROF_H
#define BASEBALLPLAYEROF_H
#include <iostream>
using namespace std;

class BaseballPlayer {
private:
    std::string m_name;
    std::string m_position;
    char        m_swingType;
public:
    BaseballPlayer(std::string name,
               std::string position,
               char swingType);
    BaseballPlayer();
    virtual ~BaseballPlayer();

    std::string GetName()      const { return m_name; }
    std::string GetPosition()  const { return m_position; }
    char GetSwingType()        const { return m_swingType; }
};



#endif // BASEBALLPLAYEROF_H
