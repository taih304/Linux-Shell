Steps for perform Firmware update on OS application layer

* Step 1: Create a firmware update service on customize OS. When there is a comming request for firmware update, we first do some validation check and then stop all current running services and jobs to release the RAM memory, just keep some crucial one needed for the change of rootfs operation in the later steps.
* Step 2: Load the minimal rootfs onto RAM memory and switch root, here we're completely seperated from the targeted memory device that we load the image onto.
* Step 3: Board receives the image data from external interfaces (ethernet, serial, i2c, ...), mount the driver for the memory card and perform write operation to it. Once done, signal reboot action for the board to boot into new updated firmware
