/******************************************************************************
PlayATrack.ino
Cytron EasyMP3 Shield Library example sketch
Created by Ng Beng Chet @ Cytron Technologies Sdn Bhd 
Original Creation Date: Mar 10, 2016
https://github.com/CytronTechnologies/CytronWiFiShield

Modified from DFPlayer_Mini_Mp3 Library examples
Credit to lisper <lisper.li@dfrobot.com> @ DFRobot
Original Creation Date: May 30, 2014
https://github.com/DFRobot/DFPlayer-Mini-mp3

!!! Description Here !!!

Development environment specifics:
	IDE: Arduino 1.6.7
	Hardware Platform: Arduino Uno or any other compatible boards
	Cytron EasyMP3 Shield Version: 1.0

Distributed as-is; no warranty is given.
******************************************************************************/
#include <CytronEZMP3.h>

CytronEZMP3 mp3;

void setup () {
	Serial.begin(9600);
  if(!mp3.begin(2, 3))
  {
    Serial.println("Init failed");
    while(1);
  }
  mp3.setVolume(25);
  Serial.print("Device: ");
  Serial.println(mp3.getCurrentDevice()==1?"U-Disk":"microSD");

  Serial.print("Total files: ");
  Serial.println(mp3.getTotalFiles());
}

void loop () {        
	mp3.playTrack(1);
  Serial.println("Now playing track " + (String)mp3.getTrackNo());
	delay (6000);
	mp3.next();
  Serial.println("Now playing track " + (String)mp3.getTrackNo());
	delay (6000);
	mp3.prev();
  Serial.println("Now playing track " + (String)mp3.getTrackNo());
	delay (6000);
	mp3.playTrack(2);
  Serial.println("Now playing track " + (String)mp3.getTrackNo());
	delay (6000);
}
