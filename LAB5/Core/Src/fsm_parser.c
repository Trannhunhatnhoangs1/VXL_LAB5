
#include "fsm_parser.h"


int parser_status = INIT;
int message_status = INIT;

void command_parser_fsm() {
    int index;
    if (index_buffer == 0) index = MAX_BUFFER_SIZE - 1;
    else index = index_buffer - 1;

    switch(parser_status) {
    case INIT:
        if (buffer[index] == '!') parser_status = _;
        break;
    case _:
        if (buffer[index] == 'R') parser_status = _R;
        else parser_status = INIT;
        break;
    case _R:
        if (buffer[index] == 'S') parser_status = _RS;
        else parser_status = INIT;
        break;
    case _RS:
        if (buffer[index] == 'T') parser_status = _RST;
        else parser_status = INIT;
        break;
    case _RST:
        if (buffer[index] == '#') {
            parser_status = _RST_;
            message_status = SEND;
        }
        else parser_status = INIT;
        break;
    case _RST_:
        if (buffer[index] == '!') parser_status = END;
        break;

    case END:
        if (buffer[index] == 'O') parser_status = O;
        else parser_status = _RST_;
        break;
    case O:
        if (buffer[index] == 'K') parser_status = OK;
        else parser_status = _RST_;
        break;
    case OK:
        if (buffer[index] == '#') {
            message_status = INIT;
            parser_status = INIT;
        }
        else parser_status = _RST_;
        break;
    default:
        break;
    }
}
