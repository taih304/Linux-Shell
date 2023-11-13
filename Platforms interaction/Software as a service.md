# Telegram
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

To perform those operations inside a forever loop:

```sh
while true;
do
   # curl commands above
   sleep 1
done
```

## openssl

**/getUpdates**

```sh
https_request="GET /bot1284804357:AAHRiRkFpUL6rRsQVO10iRQ485uwqrHLFaE/getUpdates HTTP/1.1\r\n"
https_request+="Host:api.telegram.org\r\n"
https_request+="Connection: close\r\n\r\n"

while true
do
   echo -e $https_request | openssl s_client -quiet -connect api.telegram.org:443
   sleep 1
done
```

**Send message with query string**

```sh
https_request="GET /bot1284804357:AAHRiRkFpUL6rRsQVO10iRQ485uwqrHLFaE/sendMessage"
https_request+="?chat_id=998576382&text=Message from query string "
https_request+="HTTP/1.1\r\n"
https_request+="Host:api.telegram.org\r\n"
https_request+="Connection: close\r\n\r\n"

while true
do
   echo -e $https_request | openssl s_client -quiet -connect api.telegram.org:443
done
```
**Send message with JSON data**

```sh
message="{\"chat_id\":998576382,\"text\": \"Send JSON message\"}"
https_request="GET /bot1284804357:AAHRiRkFpUL6rRsQVO10iRQ485uwqrHLFaE/sendMessage HTTP/1.1\r\n"
https_request+="Host:api.telegram.org\r\n"
https_request+="Content-Type: application/json\r\n"
https_request+="Content-Length: "
https_request+=${#message}
https_request+="\r\n\r\n"
https_request+=$message
https_request+="\r\n"

while true;
do
   echo $https_request
   echo -e $https_request | openssl s_client -quiet -connect api.telegram.org:443
   sleep 1
done
```

**Notice**: If declare the JSON with ``''``:

```json
message="{'chat_id':998576382,'text': 'open ssl test'}"
```

There will be error: 

```js
{"ok":false,"error_code":400,"description":"Bad Request: message text is empty"}read:errno=0
```
# Google drive
**Connect Ubuntu PC to Google drive**

**Step 1**: Open ``Online Accounts`` application. Choose **Google**

**Step 2**: Enter username and password. When implementing in 20th March 2022, there is error [Sign in with Google temporarily disabled for this app](https://askubuntu.com/questions/1164372/sign-in-with-google-temporarily-disabled-for-this-app#). This error is global and can't be fixed even when Turn on less secure apps in Google account settings.
# AsciiDoc
AsciiDoc document can be generated to any chosen format like HTML, PDF,... by CLI or by AsciiDoc extension on VS code.

### CLI

```sh
asciidoctor -o test test.adoc
```

Generate file ``test`` from ``test.adoc``. ``test`` will then have HTML type.

To generate PDF file, use ``asciidoctor-pdf``

Install 

```sh
sudo gem install rouge #Install rouge first
```

```sh
sudo apt install ruby-asciidoctor-pdf
```

**Note**: If ``rouge`` is not installed, when running ``asciidoctor-pdf`` command, there will be error:

```
asciidoctor: WARNING: optional gem 'rouge' is not available. Functionality disabled.
asciidoctor: FAILED: required gem 'rouge' is not available. Processing aborted.
  Use --trace for backtrace
```

To generate the PDF file:

```sh
asciidoctor-pdf test.adoc
```

File ``test.pdf`` will be generate and will have a format like a PDF book.

### AsciiDoc extension

The AsciiDoc extension on VScode allows user to preview the adoc file and generate it to the chosen format.

To generate a adoc file to a chonse format, like PDF, in that ``adoc`` file, press ``Ctr+Shift+P`` or ``F1``, then choose **Export document as PDF**.
