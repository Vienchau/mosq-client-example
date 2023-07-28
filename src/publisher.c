#include "main.h"
#include <stdio.h>
#include <mosquitto.h>
#include <string.h>
#include <unistd.h>
#include <jansson.h>

void printHello()
{
    printf("hello\n");
}

int publicMessage(char *message)
{
    int status;
    mosquitto_lib_init();
    struct mosquitto *mosq = mosquitto_new(CLIENT_ID, true, NULL);
    if (mosq)
    {
        status = mosquitto_connect(mosq, BROKER, MQTT_PORT, 60);
        if (status == MOSQ_ERR_SUCCESS)
        {
            printf("We are connected to the broker! \n");
            status = mosquitto_publish(mosq, NULL, TOPIC, strlen(message), message, 0, false);
        }
    }

    mosquitto_disconnect(mosq);
    mosquitto_destroy(mosq);
    mosquitto_lib_cleanup();

    return status;
}

json_t *formatMessage(char *action, char *payload)
{
    json_t *root = json_object();
    json_object_set_new(root, ACTION, json_string(action));
    json_object_set_new(root, PAYLOAD, json_string(payload));
    return root;
}