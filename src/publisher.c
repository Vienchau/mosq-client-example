#include "main.h"
#include <stdio.h>
#include <mosquitto.h>
#include <string.h>
#include <unistd.h>
#include <jansson.h>

void print_hello()
{
    printf("hello\n");
}

int public_message(char *message, struct mosquitto *mosq, char *topic)
{
    int status = mosquitto_publish(mosq, NULL, topic, strlen(message), message, 0, false);
    return status;
}

json_t *format_message(char *action, char *payload)
{
    json_t *root = json_object();
    json_object_set_new(root, ACTION, json_string(action));
    json_object_set_new(root, PAYLOAD, json_string(payload));
    return root;
}