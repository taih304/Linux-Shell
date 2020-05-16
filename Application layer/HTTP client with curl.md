### GET request

```sh
curl -v -X GET youtube.com
```

Get data form Python HTTP server

HTTP server: ``Python/Application layer/HTTP/HTTP server.md``

Python HTTP server return ``Hello, World`` on Web browser.

Shell script: ``curl -v -X GET localhost:8000``

Output result to a file: ``curl -v -X GET localhost:8000 > temp.md``

File ``temp.md`` will have ``Hello, World``.

### Send data to a HTTP server

HTTP server: ThingsBoard

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

### ThingsBoard HTTP server: Control devices 

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

### Working with Telegram API

``/getMe``

```sh
curl -v -X GET https://api.telegram.org/bot1203028769:AAHsOT1BSv16Ds7WvZBGWy_-5oITZFlFcfA/getMe
```

Send message with query string

```sh
curl -X GET https://api.telegram.org/bot1203028769:AAHeZRPPItDZpSD-wTZIHZxEfBitWIA3YSw/sendMessage -d chat_id=998576382 -d text="Hello World"
```

Send message with JSON data 

```sh
curl -X GET https://api.telegram.org/bot1203028769:AAHeZRPPItDZpSD-wTZIHZxEfBitWIA3YSw/sendMessage -d "{\"chat_id\": 998576382, \"text\": \"curl message\"}" --header "Content-Type:application/json"
```

``message.json`` 

```json
{
    "chat_id": 998576382,
    "text": "curl message"
}
```

```sh
curl -X GET https://api.telegram.org/bot1203028769:AAHeZRPPItDZpSD-wTZIHZxEfBitWIA3YSw/sendMessage -d @message.json --header "Content-Type:application/json"
```