#ifndef ROBOTRECEIVESTATEMACHINE_H
#define ROBOTRECEIVESTATEMACHINE_H

#include <QByteArray>


typedef union{
    float floating;
    char  bytes[sizeof(float)];
}floatUnion_t;

typedef union{
    int integer;
    char bytes[sizeof(int)];
}intUnion_t;


class RobotReceiveStateMachine
{
    typedef enum {
          WAIT_START_CHARACTER,
          WAIT_COMMAND_CHARACTER,
          WAIT_DATA_SIZE_CHARACTER,
          WAIT_DATA_CONTENT,
          WAIT_CHECKSUM
        }State;

public:
    RobotReceiveStateMachine();
    bool parseMessage(char p_byteToParse);
    unsigned char getMessageId();
    QByteArray getMessageContent();




    static float readFloatUnion(QByteArray::iterator& p_it);
    static int   readIntUnion(QByteArray::iterator& p_it);

private:
    void resetMessageParserStateMachine();

    State m_state;
    unsigned char m_messageContentIndex;
    unsigned char m_messageLength;
    unsigned char m_messageId;
    QByteArray    m_messageContent;
};
#endif // ROBOTRECEIVESTATEMACHINE_H
