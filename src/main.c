#include "main.h"
#include <stdio.h>
#include "main.h"
#include <unistd.h>
#include <jansson.h>

int main()
{
    int code, counter = 0;
    char *payload, *action = "TEST";

    while (1)
    {
        payload = (char *)malloc(sizeof(char) * 50);
        sprintf(payload, "Hello subscriber! My ordinal number is: %d", counter++);
        json_t *message_json = formatMessage(action, payload);
        char *message_str = json_dumps(message_json, JSON_INDENT(1));

        code = publicMessage(message_str);
        if (code != SUCCESS_CODE)
        {
            printf("Message sent fail! Error code: %d \n", code);
        }
        else
        {
            printf("Message sent successfully\n");
        }
        sleep(0.1);

        json_decref(message_json);
        free(message_str);
        free(payload);
    }
}