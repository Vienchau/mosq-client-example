#ifndef __MAIN_H__
#define __MAIN_H__
#include <jansson.h>

/* MQTR Configure */
#define     CLIENT_ID       "Pi_publisher"
#define     BROKER          "broker.emqx.io"
#define     MQTT_PORT       1883
#define     TOPIC           "pif/test"
#define     MESSAGE_TEST    "hello subscriber!"

/* Application Configure */
#define     ERROR_CODE      -1
#define     SUCCESS_CODE    0

/* JSON configure */
#define     ACTION          "action"
#define     PAYLOAD         "payload"

void printHello();
int publicMessage(char *message);
json_t *formatMessage(char *action, char *payload);

#endif