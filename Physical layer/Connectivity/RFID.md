The R20XD-USB is a plug-n-play RFID reader for 125 kHz RFID tag. Ubuntu has a built-in driver for it. Whenever it is plugged inside the Ubuntu PC, its driver will be automatically detected:

```sh
tranphucvinh@tranphucvinh:~$ ll /dev/input/by-id
lrwxrwxrwx 1 root root  10 May 11 14:16 usb-Sycreader_USB_Reader_08FF20150112-event-kbd -> ../event18
```

It mainly supports 2 types of 125 kHz RFID tags:
* TK4100: A read-only RFID tags which has 5 bytes UUID. TK4100 tag always has its UUID printed in the back of it
* EM4100: A read-only RFID tags which has 8 bytes UUID. 

Simply swipe the 125 kHz RFID tag and R20XD-USB will immediately print this card's UUID to your current mouse pointer. E.g: Your current mouse pointer is pointing at your terminal, then the card UUID will be printed on your terminal. Your current mouse pointer is pointing at an opened file, then the card UUID will be printed on that file. 

As being a plug-n-play device, R20XD-USB **doesn't support reading the card UUID on its device file**, i.e ``/dev/input/event18``.