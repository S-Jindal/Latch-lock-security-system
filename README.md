# Latch-lock-security-system
Arduino code for a latch lock that works on commands from an android device and lock/unlock when the correct password is given.

The hardware of this lock consists of an Arduino UNO microcontroller, a bluetooth module compatible with arduino, a servo motor compatible with arduino and a latch. The setup will be fixed to the door. The rotation of servpo governs the motion of lock. The servo rotates when arduino successfully connects to an android device via bluetooth and recieves a specific password from the device. To connect to the BT module and send password, an app is already available on Google Play Store. Furthermore, I'll post the code for a better version of the android app here after some time. 

To know more about the mechanical part and how the hardware is set up, please refer to this video link :
https://www.youtube.com/watch?v=2BHuGtoXZiI


This system will be very effective if implemented economically. Most of its use will be in the dormitories/hostels where this would prevent a lot of thefts.  The reason for its effectiveness lies in the fact that the thief couldn't know whether someone is inside the room or not as the lock is present on the inner side of the door and nothing is present on the outer side. Hence this even reduces the chance of breaking the lock using cutting tools. 

Moreover, there is room for further modifications like integrate this with a GSM module. The piezo sensor is already implemented in the code (for detecting mechanical shocks), so the task left is to read the sensor reading and command the GSM to send required SMS/call to the user.
