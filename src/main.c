#include "main.h"
#include <stdio.h>
#include "main.h"
#include <unistd.h>
#include <jansson.h>
#include <mosquitto.h>
#include <string.h>
int main()
{
    int code, counter = 0;
    char payload[100], *action = "TEST";
    mosquitto_lib_init();
    struct mosquitto *mosq = mosquitto_new(CLIENT_ID, true, NULL);
    if (mosq)
    {
        code = mosquitto_connect(mosq, BROKER, MQTT_PORT, 60);
        if (code == MOSQ_ERR_SUCCESS)
        {
            while (counter < 10)
            {
                sprintf(payload, "Hello subscriber! My ordinal number is: %d", counter++);
                json_t *message_json = format_message(action, payload);
                char *message_str = json_dumps(message_json, JSON_INDENT(1));

                code = public_message(message_str, mosq, TOPIC);
                if (code != SUCCESS_CODE)
                {
                    printf("Message sent fail! Error code: %d \n", code);
                }
                else
                {
                    printf("Message sent successfully: %s\n", message_str);
                }
                sleep(1);

                json_decref(message_json);
                free(message_str);
                memset(payload, '\0', 100);
            }
            mosquitto_disconnect(mosq);
            mosquitto_destroy(mosq);
            mosquitto_lib_cleanup();
        }
    }
}