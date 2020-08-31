### Send data

Send data to Live Demo server:

```sh
curl -v -X POST -d "{\"temperature\": 25}" https://demo.thingsboard.io/api/v1/O0kt6xUl6cTGv9RM7M9P/telemetry --header "Content-Type:application/json"
```

Send data to local server:

```sh
curl -v -X POST -d "{\"temperature\": 25}" 192.168.1.22:8000 --header "Content-Type:application/json"
```

``message.json``

```json
{
    "temperature": 25
}
```

```sh
curl -v -X POST -d @message.json 192.168.1.22:8000 --header "Content-Type:application/json"
```

Send data in while loop

```sh
while [ true ]
do
	curl -v -X POST -d "{\"temperature\": 25}" https://demo.thingsboard.io/api/v1/O0kt6xUl6cTGv9RM7M9P/telemetry --header "Content-Type:application/json"	
	sleep 1
done	
```

### Control devices with RPC

Get return value from control widget of ThingsBoard dashboard

```sh
while [ true ]
do
	curl -v -X GET https://demo.thingsboard.io/api/v1/O0kt6xUl6cTGv9RM7M9P/rpc
	sleep 1
done >> temp.md
```
**Result**

```
{"id":122,"method":"setValue","params":true}{"id":123,"method":"setValue","params":false}{"id":125,"method":"setValue","params":true}{"id":127,"method":"setValue","params":false}
```

Parse the return to get the button status

```sh
while [ true ]
do
	curl -s -v -X GET https://demo.thingsboard.io/api/v1/O0kt6xUl6cTGv9RM7M9P/rpc > temp.json
	params=$(cat temp.json|jq '.params')
	echo $params
	sleep 1
done
```