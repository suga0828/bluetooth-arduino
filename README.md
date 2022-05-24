# Bluetooth Arduino

Arduino program to activate/deactivate pins by bluetooth connection.
There will be 3 outputs pines (2, 4 and 7) operated as follow:

| DATA RECEIVED | PIN | ACTION |
| ------------- | --- | ------ |
| '1'           | 2   | TOGGLE |
| '2'           | 4   | TOGGLE |
| '3'           | 7   | TOGGLE |
| '4'           | ALL | OFF    |
