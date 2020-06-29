# Dash-4
This is a 4-button DASH remote where each button publishes an MQTT message.
Each button responds to a short press <1 sec, and a long press, giving a total of eight MQTT messages.

MQTT topic:  dash4/status<br>
Where status will be one of 1 - 8

| Button | Short | Long |
| ------ | ----- | ---- |
|    1   |   1   |  5   |
|    2   |   2   |  6   |
|    3   |   3   |  7   |
|    4   |   4   |  8   |

OTA port is dash4-3AE561
(3AE561 is the last three HEX numbers of the ESP MAC address).
