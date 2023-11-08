# Grove-Collision-Sensor

mangOH code for Grove Collision sensor

### Setup

Insert Grove Collision sensor to pin D5 of Grove IoT Expansion card.

### How To Run

1. Go to mangOH workspace: ``leaf shell``
2. Go to ``$CURDIR/apps/collisionSensor``: ``mkapp -t wp77xx collisionSensor.adef``
3. Install app: ``app install collisionSensor.wp77xx.update 192.168.2.2``

### How it works

1. ssh to mangOH ``ssh root@192.168.2.2``
2. ``logread -f |grep collisionSensor`` to view log of app ``collisionSensor``
3. If a collision is detected: ``collision detected`` and the app freeze for 2 second ; or else ``collision undetected``

