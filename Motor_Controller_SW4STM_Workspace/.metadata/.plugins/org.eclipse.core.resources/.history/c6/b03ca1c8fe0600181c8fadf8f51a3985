#ifndef PARSER_H
#define PARSER_H

typedef enum {
      WAIT_START_CHARACTER,
      WAIT_COMMAND_CHARACTER,
      WAIT_DATA_SIZE_CHARACTER,
      WAIT_DATA_CONTENT,
      WAIT_CHECKSUM
    }MessageParserState;



extern unsigned char g_messageLength;
extern unsigned char g_messageId;
extern char g_messageContent[255];

char parseMessage(char p_byteToParse);
void resetMessageParserStateMachine();

#endif //PARSER_H
