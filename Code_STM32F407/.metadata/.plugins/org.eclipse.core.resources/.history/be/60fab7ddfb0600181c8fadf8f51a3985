#include "../../inc/UART/Parser.h"

#include "stm32f4xx.h"

static MessageParserState g_messageParserState = WAIT_START_CHARACTER;
static unsigned char g_messageContentIndex;

unsigned char g_messageLength;
unsigned char g_messageId;
char g_messageContent[255];


char parseMessage(char p_byteToParse)
{

    switch(g_messageParserState){

        case WAIT_START_CHARACTER:

            resetMessageParserStateMachine();
            if(p_byteToParse == '#'){
            	GPIOD->ODR ^= 0x4000;
            	g_messageParserState = WAIT_COMMAND_CHARACTER;
            }

            break;

        case WAIT_COMMAND_CHARACTER:

            if(p_byteToParse == 0){ //there is a mistake, message id 0 doesn't exist.
               g_messageParserState = WAIT_START_CHARACTER;
            }
            else{
                g_messageId = p_byteToParse;
                g_messageParserState = WAIT_DATA_SIZE_CHARACTER;
            }
            break;

        case WAIT_DATA_SIZE_CHARACTER:

            g_messageLength = p_byteToParse;
            g_messageParserState = WAIT_DATA_CONTENT;
            break;

        case WAIT_DATA_CONTENT:

            g_messageContent[g_messageContentIndex] = p_byteToParse;
            g_messageContentIndex++;
            if(g_messageContentIndex == g_messageLength){
                g_messageParserState = WAIT_CHECKSUM;
            }
            break;

        case WAIT_CHECKSUM:

            g_messageParserState = WAIT_START_CHARACTER;

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

void resetMessageParserStateMachine()
{
    g_messageParserState = WAIT_START_CHARACTER;

    /* Not necesary, more for visualisation*/
    g_messageId = 0;
    g_messageLength = 0;
    for(int i = 0; i<255;i++) g_messageContent[i]=0;
    g_messageContentIndex = 0;
}
