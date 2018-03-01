#include "receivestatemachine.h"


ReceiveStateMachine::ReceiveStateMachine()
{
    this->resetMessageParserStateMachine();
}

bool ReceiveStateMachine::parseMessage(char p_byteToParse)
{

    switch(m_state){

        case WAIT_START_CHARACTER:

            resetMessageParserStateMachine();
            if(p_byteToParse == '#'){
                m_state = WAIT_COMMAND_CHARACTER;
            }

            break;

        case WAIT_COMMAND_CHARACTER:

            if(p_byteToParse == 0){ //there is a mistake, message id 0 doesn't exist.
               m_state = WAIT_START_CHARACTER;
            }
            else{
                m_messageId = p_byteToParse;
                m_state = WAIT_DATA_SIZE_CHARACTER;
            }
            break;

        case WAIT_DATA_SIZE_CHARACTER:

            m_messageLength = p_byteToParse;
            if(m_messageLength == 0x00) m_state = WAIT_CHECKSUM;
            else m_state = WAIT_DATA_CONTENT;
            break;

        case WAIT_DATA_CONTENT:

            m_messageContent.append(p_byteToParse);
            m_messageContentIndex++;
            if(m_messageContentIndex == m_messageLength){
                m_state = WAIT_CHECKSUM;
            }
            break;

        case WAIT_CHECKSUM:

            m_state = WAIT_START_CHARACTER;

            if(p_byteToParse == '.'){
                return 1;
            }
//            {
//                unsigned char sum = 0;
//
//                for(int i = 0; i < m_messageContent.count(); i++){
//                   sum += (unsigned char) m_messageContent.at(i);
//                }
//
//                sum += p_byteToParse;
//
//                if(sum == 0){
//                    return 1;
//                }
//                else{
//                  return 1; //TODO: for now it returns message received in every case. modify that to be more robust.
//                }
//            }
            break;


        default:
            //not supposed to get there
            break;
     }

    return 0; //message not complete
}

unsigned char ReceiveStateMachine::getMessageId()
{
    return m_messageId;
}

QByteArray ReceiveStateMachine::getMessageContent()
{
    return m_messageContent;
}

void ReceiveStateMachine::resetMessageParserStateMachine()
{
    m_state = WAIT_START_CHARACTER;

    /* Not necesary, more for visualisation*/
    m_messageId = 0;
    m_messageLength = 0;
    m_messageContentIndex = 0;
    m_messageContent.clear();
}

float ReceiveStateMachine::readFloatUnion(QByteArray::iterator& p_it)
{
    floatUnion_t v_floatUnion;

    v_floatUnion.bytes[0] = *p_it; p_it++;
    v_floatUnion.bytes[1] = *p_it; p_it++;
    v_floatUnion.bytes[2] = *p_it; p_it++;
    v_floatUnion.bytes[3] = *p_it; p_it++;

    return v_floatUnion.floating;
}

int ReceiveStateMachine::readIntUnion(QByteArray::iterator& p_it)
{
    intUnion_t v_intUnion;

    v_intUnion.bytes[0] = *p_it; p_it++;
    v_intUnion.bytes[1] = *p_it; p_it++;
    v_intUnion.bytes[2] = *p_it; p_it++;
    v_intUnion.bytes[3] = *p_it; p_it++;

    return v_intUnion.integer;
}


