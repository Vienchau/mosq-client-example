#ifndef __MAIN_H__
#define __MAIN_H__
#include <jansson.h>
#include <mosquitto.h>
/* MQTR Configure */
#define CLIENT_ID "Pi_publisher"
#define BROKER "broker.emqx.io"
#define MQTT_PORT 1883
#define TOPIC "t1/test01"
#define MESSAGE_TEST "hello subscriber!"

/* Application Configure */
#define ERROR_CODE -1
#define SUCCESS_CODE 0

/* JSON configure */
#define ACTION "action"
#define PAYLOAD "payload"

void print_hello();
int public_message(char *message, struct mosquitto *mosq, char *topic);
json_t *format_message(char *action, char *payload);

#endif