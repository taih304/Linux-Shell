## curl

**/getMe**

```sh
curl -v -X GET https://api.telegram.org/bot1203028769:AAHsOT1BSv16Ds7WvZBGWy_-5oITZFlFcfA/getMe
```

**Send message with query string**

```sh
curl -X GET https://api.telegram.org/bot1203028769:AAHeZRPPItDZpSD-wTZIHZxEfBitWIA3YSw/sendMessage -d chat_id=998576382 -d text="Hello World"
```

**Send message with JSON data**

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

## openssl

**/getMe**

```sh
https_request="GET /bot1284804357:AAHRiRkFpUL6rRsQVO10iRQ485uwqrHLFaE/getMe HTTP/1.1\r\n"
https_request+="Host:api.telegram.org\r\n\r\n"

echo -e $https_request | openssl s_client -quiet -connect api.telegram.org:443
```

**Send message with query string**

```sh
https_request="GET /bot1284804357:AAHRiRkFpUL6rRsQVO10iRQ485uwqrHLFaE/sendMessage"
https_request+="?chat_id=998576382&text=Hello World "
https_request+="HTTP/1.1\r\n"
https_request+="Host:api.telegram.org\r\n\r\n"

echo -e $https_request | openssl s_client -quiet -connect api.telegram.org:443
```
**Send message with JSON data**

```sh
message="{\"chat_id\":998576382,\"text\": \"Hello, World !\"}"
https_request="GET /bot1284804357:AAHRiRkFpUL6rRsQVO10iRQ485uwqrHLFaE/sendMessage HTTP/1.1\r\n"
https_request+="Host:api.telegram.org\r\n"
https_request+="Content-Type: application/json\r\n"
https_request+="Content-Length: "
https_request+=${#message}
https_request+="\r\n\r\n"
https_request+=$message
https_request+="\r\n"

echo $https_request
echo -e $https_request | openssl s_client -quiet -connect api.telegram.org:443
```

**Notice**: If declare the JSON with ``''``:

```json
message="{'chat_id':998576382,'text': 'open ssl test'}"
```

There will be error: 

```js
{"ok":false,"error_code":400,"description":"Bad Request: message text is empty"}read:errno=0
```