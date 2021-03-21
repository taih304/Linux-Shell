### Read UID

On terminal

```
$ scriptor
```

Then use APDU command ``FF CA 00 00 00`` to read UID

**Read UID by scriptor script**

Read UID and store in ``text.csv``

``./test.scriptor``

```
#! /usr/bin/env scriptor
FF CA 00 00 00
```

```
./test.scriptor | grep "<" >> test.csv
```

**Result**

```
< 0B B0 B3 11 90 00 : Normal processing.
```

Then use regular expression to get the UID (along with ``awk``):

```sh
$ awk -F'[<:]' '{print $2}' test.csv
```

**Read value from NFC then stores in result.csv**

```sh
./test.scriptor | grep "<" >> rawValue.csv
awk -F'[<:]' '{print $2}' rawValue.csv >> result.csv #print $2 to output file result.csv
```

### Read UID with ACR122U and send its value to MQTT broker

* Broker: Thingsboard

**test.scriptor**

```
#! /usr/bin/env scriptor
FF CA 00 00 00
```

**main.sh**

```shell
./test.scriptor | grep "<" > rawValue.csv
awk -F'[<:]' '{print $2}' rawValue.csv > readUID.csv

while read textLine; do
    mosquitto_pub -d -h "demo.thingsboard.io" -t "v1/devices/me/telemetry" -u "O0kt6xUl6cTGv9RM7M9P" -m "{'uid':'$textLine'}"    
done < readUID.csv
```