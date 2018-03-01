#ifndef SERIALRECEIVESTATEMACHINE_H
#define SERIALRECEIVESTATEMACHINE_H

#include <QByteArray>

class SerialReceiveStateMachine
{
    typedef enum {
          WAIT_START_CHARACTER,
          WAIT_COMMAND_CHARACTER,
          WAIT_DATA_SIZE_CHARACTER,
          WAIT_DATA_CONTENT,
          WAIT_CHECKSUM
        }State;

public:
    SerialReceiveStateMachine();
    bool parseMessage(char p_byteToParse);
    unsigned char getMessageId();
    QByteArray getMessageContent();

private:
    void resetMessageParserStateMachine();

    State m_state;
    unsigned char m_messageContentIndex;
    unsigned char m_messageLength;
    unsigned char m_messageId;
    QByteArray    m_messageContent;
};

#endif // SERIALRECEIVESTATEMACHINE_H




